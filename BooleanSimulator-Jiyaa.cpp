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
    if (t == "1") return true;
    if (t == "0") return false;
    return false;
}

// Evaluates Boolean expressions 
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
        if (p[i] == "TRUE") p[i] = "1";
        if (p[i] == "FALSE") p[i] = "0";
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

                    r = evaluateExpression(clean, a, b, c);

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
