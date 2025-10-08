#include <iostream>
#include <vector>
using namespace std;

int hackingminigame() {
    vector<string> buffer = {"BD", "55", "1C", "E9", "7A"};
    vector<string> target = {"55", "1C", "E9"}; // kept for reference
    vector<string> input;
    string choice;

    cout << "=== CODE SEQUENCE OVERRIDE ===\n";
    cout << "Buffer: ";
    for (auto &c : buffer) cout << c << " ";
    cout << "\nTarget Sequence: ?? ?? ?? (hidden)\n";
    cout << "Pick 3 codes from the buffer (type them exactly, e.g. 55):\n";

    for (int i = 0; i < (int)target.size(); i++) {
        cout << "Choice " << (i+1) << ": ";
        cin >> choice;
        input.push_back(choice);
    }

    // TEMPORARY: accept any input as correct.
    // TODO (later): replace this with a check that compares the player's input
    // to the target AND/OR factors in the player's tech stat (e.g. tech >= X)
    // to determine success or failure.
    bool isCorrect = true; // <-- placeholder: always win for now

    if (isCorrect) {
        cout << "\n🔓 ACCESS GRANTED – You breached the system!\n";
    } else {
        cout << "\n💀 ACCESS DENIED – Trace detected.\n";
        cout << "Correct sequence was: ";
        for (auto &c : target) cout << c << " ";
        cout << endl;
    }

    return 0;
}
