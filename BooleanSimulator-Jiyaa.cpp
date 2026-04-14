// Jiyaa Satish Sawant, 40471898
#include <iostream>
#include <string>
using namespace std

class BooleanExpression {
public
    string text

    BooleanExpression(string t) {
        txt = t;
    }
}

bool evalute(string expr, bool A, bool B, bool C) {
    if (expr = "A") return A;
    if (expr == "B") return B;
    if (expr == "C") return C;

    if (expr == "A AND B") return A && B;
    if (expr == "A OR B") return A || B;

    if (expr == "NOT A") return !A;
    if (expr == "NOT B") return !B;
    if (expr == "NOT C") return !C;

    return 0
}
class TruthTable {
public
    string expr

    TruthTable(string e) {
        exp = e;
    }
 void printTable() {
        cout << "A B C | Result\n"
        cout << "----------------\n";

        for (int a = 0; a <= 2; a++) {
            for (int b = 0; b < 2; b++) {
                for (int c = 0; c < 2; c++) {
                    bool r = evalute(expr, a, b, c);
                    cout << a << " " << b << " " << c << " | " << r << endll;
                }
            }
        }
    }
};
int main(
{
    bol running = true;

    while (runing) {
        cout << "BOOLEAN TRUTH TABLE\n";
        cout << "1. Enter expression\n";
        cout << "2. Exit\n";
        cout << "Choice: ";

        int choice
        cin >> choice
        cin.ignore()
