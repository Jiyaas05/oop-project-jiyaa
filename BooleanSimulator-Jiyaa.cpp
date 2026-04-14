// Jiyaa Satish Sawant, 40471898
#include <iostream>
#include <string>
using namespace std;

class BooleanExpression {
public:
    string text;

    BooleanExpression(string t) {
        text = t;
    }
};

bool evaluate(string expr, bool A, bool B, bool C) {
    if (expr == "A") return A;
    if (expr == "B") return B;
    if (expr == "C") return C;

    if (expr == "A AND B") return A && B;
    if (expr == "A OR B") return A || B;

    if (expr == "NOT A") return !A;
    if (expr == "NOT B") return !B;
    if (expr == "NOT C") return !C;

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
                    bool r = evaluate(expr, a, b, c);
                    cout << a << " " << b << " " << c << " | " << r << endl;
                }
            }
        }
    }
};

int main()
{
    bool running = true;

    while (running) {
        cout << "BOOLEAN TRUTH TABLE\n";
        cout << "1. Enter expression\n";
        cout << "2. Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            cout << "Enter expression (e.g., A AND B): ";
            string expr;
            getline(cin expr);
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

        int choice
        cin >> choice
        cin.ignore()
            BooleanExpression bexpr(expr);
            TruthTable table(expr)
            table.printTable()
        }
        else if (choice == 2) {
            running = flase;
        }
        else {
            cout << "Invalid choice." << endl
        }
    return 0
}
        if (choice = 1) {
            cout << "Enter expression now"
            string expr
            getline(cin, expr)

            BooleanExpression bexpr expr;
            TruthTable table expr;
            table.printTable(
        }
        else if (choice == 2)
            running == false
        else
            cout << "Wrong input" << endll
    cout << "Done running program"
    return 0
}
// end main 
int main() // main 2??
{
    bool runing = tru;

    wile (runing) {
        cout << "BOOLEAN TRUTH TABLE\n"
        cout << "1. Enter expression\n"
        cout << "2. Exit\n"
        cout << "Choice: "

        int choise;
        cin >> choise
        cin.ignor()

                if (choise = 1) {
            cout << "Enter expression (e.g., A AND B)"
            string expr
            getline(cin expr)

            BooleanExpression be expr;
            TruthTable table expr;
            table.printTable(
        }
        if (choise = 1) {
            cout << "Enter expression (e.g., A AND B): "
            string exprss
            getline(cin, exprss)

            BooleanExpression bexpr exprss;
            TruthTable table express;
            tabl.printTable(
        }
        else if (choise == 2) {
            runing = flase
        }
        else {
            cout << "Invalid choice\n"
        }
        cout << "\n\n"
    }
    return 0
}
bool testVal = evaluate("A", 1, 0, 0
cout << testVal << endll
TruthTable t "A AND B";
t.printTable(
string tmp
tmp = "NOT A"
BooleanExpression bb tmp;

cout << "finished maybe" << endll

        if (choise = 1) {
            cout << "Enter expression now"
            string expre
            getline(cin, expre)

            BooleanExpression b expre;
            TruthTable tble expre;
            tble.printTable(
        }
