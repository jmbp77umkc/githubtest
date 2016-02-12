#include <iostream>
#include <string>
#include <list>
#include <stack>

using namespace std;

bool undo(list<string>& ls,stack<string>& r);
bool redo(list<string>& ls,stack<string>& r);

int main() {
    list<string> actions;
    stack<string> redostack;
    
    string input;
    bool quit = false;
    bool result;
    
    while(!quit) {
        cout << "A/U/R/L/C/Q: ";
//        cout << "I don't know what's happening aaaaaaaaaaaaaaaaaaaaaa: ";
        cin >> input;
        switch (input.at(0)) {
            case 'A':
            case 'a':
                cout << "Action: ";
                cin >> input;
                actions.push_back(input);
                while (!redostack.empty()) redostack.pop();
                break;
            case 'U':
            case 'u':
                result = undo(actions,redostack);
                if (!result) cout << "Nothing to undo." << endl;
                break;
            case 'R':
            case 'r':
                result = redo(actions,redostack);
                if (!result) cout << "Nothing to redo." << endl;
                break;
            case 'L':
            case 'l':
                if (actions.empty()) cout << "Nothing to print.";
                for (list<string>::iterator iter=actions.begin(); iter!=actions.end(); ++iter) {
                    if (iter != actions.begin()) cout << " >> ";
                    cout << *iter;
                }
                cout << endl;
                break;
            case 'C':
            case 'c':
                actions.clear();
                while(!redostack.empty()) redostack.pop();
                break;
            case 'Q':
            case 'q':
                quit = true;
                break;
            default:
                cout << "Invalid." << endl;
        }
    }
    
    return 0;
}

bool undo(list<string>& ls,stack<string>& r) {
    if (ls.empty()) return false;
    r.push(ls.back());
    ls.pop_back();
    return true;
}

bool redo(list<string>& ls,stack<string>& r) {
    if (r.empty()) return false;
    ls.push_back(r.top());
    r.pop();
    return true;
}