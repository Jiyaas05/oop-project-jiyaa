// Jiyaa Satish Sawant, 40471898
#include <iostream>
#include <string>
#include <vector> 
using namespace std;

// Stores the expression the user enters
class BooleanExpression { 
public:
    string text;

    BooleanExpression(string t) {
        text = t;
    }
};

vector<string> split(string s) {
    vector<string> parts;
    string temp = "";

    for (char c : s) {
        if (c == ' ') {
            if (!temp.empty()) {
                parts.push_back(temp);
                temp.clear();
            }
        } else {
            temp += c;
        }
    }

    if (!temp.empty()) {
        parts.push_back(temp);
    }

    return parts;
}

string toUpperCase(string s) {
    string result = "";
    for (char c : s) {
        result += toupper(c);
    }
    return result;
}
string removeBrackets(string s) {
    string out = "";
    for (char c : s) {
        if (c != '(' && c != ')') {
            out += c;
        }
    }
    return out;
}

bool evalToken(string t, bool A, bool B, bool C) {
    if (t == "A") return A;
    if (t == "B") return B;
    if (t == "C") return C;
    return false;
}

bool evaluateExpression(string expr, bool A, bool B, bool C) {
    vector<string> p = split(expr);

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == "NOT" && i + 1 < p.size()) {
            bool val = evalToken(p[i+1], A, B, C);
            p[i] = val ? "FALSE" : "TRUE";
            p.erase(p.begin() + i + 1);
        }
    }

    for (int i = 0; i < p.size(); i++) {
        if (p[i] == "TRUE") p[i] = "A";
        if (p[i] == "FALSE") p[i] = "B";
    }

    bool result = evalToken(p[0], A, B, C);

    for (int i = 1; i < p.size(); i += 2) {
        string op = p[i];
        bool right = evalToken(p[i+1], A, B, C);

        if (op == "AND") result = result && right;
        else if (op == "OR") result = result || right;
        else if (op == "XOR") result = result ^ right;
        else if (op == "NAND") result = !(result && right);
        else if (op == "NOR") result = !(result || right);
    }

    return result;
}


// Evaluates Boolean expressions 
bool evaluate(string expr, bool A, bool B, bool C) {

    //operators 
    if (expr == "A") return A;
    if (expr == "B") return B;
    if (expr == "C") return C;

    if (expr == "A AND B") return A && B;
    if (expr == "A OR B") return A || B;

    if (expr == "NOT A") return !A;
    if (expr == "NOT B") return !B;
    if (expr == "NOT C") return !C;
    if (expr == "A XOR B") return A ^ B;
    if (expr == "A NAND B") return !(A && B);
    if (expr == "A NOR B")  return !(A || B);
    if (expr == "A NOT B") return A && (!B);
    if (expr == "A NOT C") return A && (!C);
    if (expr == "B NOT A") return B && (!A);
    if (expr == "B NOT C") return B && (!C);
    if (expr == "C NOT A") return C && (!A);
    if (expr == "C NOT B") return C && (!B);
    
    if (expr == "TRUE NOT A") return !A;
    if (expr == "TRUE NOT B") return !B;
    if (expr == "TRUE NOT C") return !C;
    if (expr == "FALSE NOT A") return A;
    if (expr == "FALSE NOT B") return B;
    if (expr == "FALSE NOT C") return C;

    // If the expression is not recognized, return false
    return false;
}

bool evaluateMulti(string expr, bool A, bool B, bool C) {
    vector<string> p = split(expr);

    if (p.size() != 5) {
        return false;
    }

    string first = p[0] + " " + p[1] + " " + p[2];
    bool left = evaluate(first, A, B, C);

    string fakeVar;
    if (left) {
        fakeVar = "A";
    } else {
        fakeVar = "B";
    }

    string second = fakeVar + " " + p[3] + " " + p[4];

    return evaluate(second, left, false, C);
}

bool evaluateThree(string expr, bool A, bool B, bool C) {
    vector<string> p = split(expr);
   
     if (p.size() == 7) {
        string first = p[0] + " " + p[1] + " " + p[2];
        bool left = evaluate(first, A, B, C);

        string fakeVar1 = left ? "A" : "B";
        string second = fakeVar1 + " " + p[3] + " " + p[4];
        bool mid = evaluate(second, left, false, C);

        string fakeVar2 = mid ? "A" : "B";
        string third = fakeVar2 + " " + p[5] + " " + p[6];

        return evaluate(third, mid, false, C);
    }

    if (p.size() == 6 && p[4] == "NOT") {
        string first = p[0] + " " + p[1] + " " + p[2];
        bool left = evaluate(first, A, B, C);

        string fakeVar = left ? "A" : "B";
        string second = fakeVar + " " + p[3] + " NOT " + p[5];

        return evaluate(second, left, false, C);
    }

    return false;
}


bool evaluateComplex(string expr, bool A, bool B, bool C) {
    vector<string> p = split(expr);
    
    // Handle expressions like "A AND B NOT C"
    if (p.size() == 7 && p[5] == "NOT") {
        string first = p[0] + " " + p[1] + " " + p[2];
        bool left = evaluate(first, A, B, C);
        
        string fakeVar1 = left ? "A" : "B";
        string second = fakeVar1 + " " + p[3] + " " + p[4];
        bool mid = evaluate(second, left, false, C);
        
        string fakeVar2 = mid ? string("A") : string("B");
        string third = fakeVar2 + " NOT " + p[6];
        return evaluate(third, mid, false, C);
    }
    
    return false;
}


class TruthTable {
public:
    string expr;

    TruthTable(string e) {
        expr = e;
    }
    void printTable() {
        cout << "A B C | Result\n";
        cout << "----------------\n";

        for (int a = 0; a < 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    bool r;

                    string clean = removeBrackets(expr);

                    int spaces = 0;
                    for (char ch : clean) {
                        if (ch == ' ') {
                            spaces++;
                        }
                    }


                    if (spaces == 2) {
                        r = evaluate(clean, a, b, c);
                    }   
                    else if (spaces == 4) {
                        r = evaluateMulti(clean, a, b, c);
                    }
                    else if (spaces == 6) {
                        if (evaluateComplex(clean, a, b, c) != false || clean.find("NOT") != string::npos) {
                            r = evaluateComplex(clean, a, b, c);
                        } else {
                            r = evaluateThree(clean, a, b, c);
                        }
                    }
                    else {
                        r = false;
                    }

                    cout << a << " " << b << " " << c << " | " << r << endl;
                }
            }
        }
    }
};

int main()
{
    bool running = true;
    // Main loop 
    while (running) {
        cout << "BOOLEAN TRUTH TABLE\n";
        cout << "1. Enter expression\n";
        cout << "2. Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Enter expression (In capital letters): ";
            string expr;
            getline(cin, expr);
            // Convert to uppercase
            expr = toUpperCase(expr);
            // prints the tablr
            BooleanExpression bexpr(expr);
            TruthTable table(expr);
            table.printTable();
        }
        else if (choice == 2) {
            running = false;
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
