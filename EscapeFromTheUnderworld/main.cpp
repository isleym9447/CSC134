#include "intro.h"
#include "Asphodel.h"
#include "Elysium.h"
#include "Tartarus.h"
#include "ending.h"
#include <iostream>
#include <string>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    asciiIntro();

    Player p;
    cout << "Your name, demigod? ";
    getline(cin, p.name);

    p.god = randomGod();
    initBaseStats(p);
    applyGodPassives(p);

    cout << "\nA whisper from the dark: \"" << p.god.name << " claims you.\" ("
         << p.god.passive << ")\n";
    cout << "You carry a one-use gift: " << p.god.itemName << " — " << p.god.itemDesc << "\n";

    bool running = true;
    while (running) {
        showHUD(p);
        cout << "\nChoose a path: (1) Asphodel (2) Elysium (3) Tartarus (q to quit): ";
        string c; getline(cin, c);
        if (!c.empty() && (c[0] == 'q' || c[0] == 'Q')) {
            cout << "You drift… the journey pauses.\n";
            break;
        }
        if (c == "1")      running = asphodelChapter(p);
        else if (c == "2") running = elysiumChapter(p);
        else if (c == "3") running = tartarusChapter(p);
        else cout << "The mists do not understand. Choose a path.\n";

        if (!running) break;
        if (checkEnding(p)) break;
        if (p.hp <= 0 || p.soul <= 0) break;
    }

    cout << "\n-- THE END --\n";
    return 0;
}