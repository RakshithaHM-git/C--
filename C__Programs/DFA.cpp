#include<iostream> 
#include <map>
#include <set>
using namespace std;

int main() {
    int numStates, numSymbols;

    cout << "Enter number of states: ";
    cin >> numStates;

    cout << "Enter number of input symbols: ";
    cin >> numSymbols;

    char symbols[numSymbols];
    cout << "Enter input symbols:\n";
    for (int i = 0; i < numSymbols; i++) {
        cin >> symbols[i];
    }

    // Transition table: (state, symbol) -> next state
    map<pair<int, char>, int> transition;

    cout << "Enter transition table (current_state input_symbol next_state):\n";
    for (int i = 0; i < numStates * numSymbols; i++) {
        int state, nextState;
        char symbol;
        cin >> state >> symbol >> nextState;
        transition[{state, symbol}] = nextState;
    }

    int initialState;
    cout << "Enter initial state: ";
    cin >> initialState;

    int numFinalStates;
    cout << "Enter number of final states: ";
    cin >> numFinalStates;

    set<int> finalStates;
    cout << "Enter final states:\n";
    for (int i = 0; i < numFinalStates; i++) {
        int state;
        cin >> state;
        finalStates.insert(state);
    }

    string input;
    cout << "Enter input string: ";
    cin >> input;

    int currentState = initialState;

    // Process the input string
    for (char ch : input) {
        if (transition.find({currentState, ch}) == transition.end()) {
            cout << "Rejected (No transition defined)\n";
            return 0;
        }
        currentState = transition[{currentState, ch}];
    }

    // Check acceptance
    if (finalStates.find(currentState) != finalStates.end()) {
        cout << "Accepted\n";
    } else {
        cout << "Rejected\n";
    }

    return 0;
}