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


    return evaluate(second, left, false, C);
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

int spaces = 0;
for (char ch : expr) {
    if (ch == ' ') {
        spaces++;
    }
}

if (spaces == 2) {
    r = evaluate(expr, a, b, c);
}
else if (spaces == 4) {
    r = evaluateMulti(expr, a, b, c);
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
