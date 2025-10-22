// beginning with the magic words
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

// ======================================
// Function: mistysEsoterica
// ======================================

void mistysEsoterica() {
    srand(time(0));

    vector<string> tarotCards = {
        "The Fool", "The Magician", "The High Priestess", "The Empress", "The Emperor",
        "The Hierophant", "The Lovers", "The Chariot", "Strength", "The Hermit",
        "Wheel of Fortune", "Justice", "The Hanged Man", "Death", "Temperance",
        "The Devil", "The Tower", "The Star", "The Moon", "The Sun",
        "Judgement", "The World"
    };

    vector<string> meanings = {
        "A new journey begins. Trust the leap, even if you can’t see the landing.",
        "Your will shapes the code of reality. Manifest what you believe.",
        "Knowledge unseen, whispers in the quiet. Listen, not speak.",
        "Growth, care, creation — what you nurture will take root.",
        "Power and control are tools, not truths. Use them wisely.",
        "Tradition binds or guides — you choose which it becomes.",
        "A bond tested, a choice made. Love or duty — both cost something.",
        "Push forward. Victory demands motion, not hesitation.",
        "Courage isn’t muscle — it’s mercy under fire.",
        "The quiet within the chaos. Seek it.",
        "Luck’s a wheel — sometimes you’re the one crushed under it.",
        "Balance the scales before the world tips them for you.",
        "Surrender brings clarity. Let go of what no longer fits.",
        "An ending, and in it — a new start. Change doesn’t ask permission.",
        "Patience, restraint. All things find harmony in time.",
        "Temptation wears your reflection. Choose what to feed.",
        "Collapse clears the path for rebirth. Don’t fear the fall.",
        "A flicker of hope — fragile, luminous, real.",
        "Dreams blur with lies. Not all that glows is truth.",
        "Light returns after darkness. Joy follows ruin.",
        "Reckoning comes. The call to rise — or atone.",
        "Completion. Full circle. You’ve become your own legend."
    };

    

    cout << "\nThe bell above the door chimes softly as you step inside.\n";
    cout << "Incense curls through the air — sage and chrome dust.\n";
    cout << "Shelves hum with flickering candles and old tech relics.\n\n";

    this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Misty looks up from her cards and smiles faintly.\n";
    cout << "\"Hey, choom. You look... heavier than last time.\"\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << "\"Sit. Let’s see what the cards have to say.\"\n\n";

    this_thread::sleep_for(chrono::milliseconds(1200));
    cout << "She fans a deck of tarot cards across the velvet table.\n";
    cout << "\"Focus on your question. Don’t say it out loud.\"\n";
    cout << "Her voice softens. \"Now... pick three.\"\n\n";
    this_thread::sleep_for(chrono::milliseconds(1500));

    for (int i = 0; i < 3; i++) {
        int draw = rand() % tarotCards.size();

        cout << "───────────────" << endl;
        cout << "Card " << i + 1 << ": " << tarotCards[draw] << endl;
        cout << "Meaning: " << meanings[draw] << endl;
        cout << "───────────────" << endl;
        cout << endl;

        this_thread::sleep_for(chrono::milliseconds(1300));
    }

    cout << "Misty exhales slowly, watching the smoke curl above the spread.\n";
    this_thread::sleep_for(chrono::milliseconds(1200));
    cout << "\"The city’s got its claws in you, but it hasn’t won yet.\"\n";
    cout << "\"Take what resonates... leave what doesn’t.\"\n";
    this_thread::sleep_for(chrono::milliseconds(900));
    cout << "She gathers the cards back into the deck, the sound like static.\n\n";

    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                [1] Thank Misty and Leave                   ║" << endl;
    cout << "║                [2] Ask about your future                   ║" << endl;
    cout << "║                [3] Stay silent and watch the smoke         ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;

    int choice;
    cout << "> ";
    cin >> choice;

    cout << endl;

    switch (choice) {
        case 1:
            cout << "You nod. \"Thanks, Misty.\"\n";
            cout << "She smiles gently. \"Anytime, kid. Night City’s loud, but sometimes the cards whisper louder.\"\n";
            break;
        case 2:
            cout << "She smirks. \"If I told you, you’d try to change it.\"\n";
            cout << "\"Better to live it — you might surprise even fate.\"\n";
            break;
        case 3:
            cout << "You both sit in silence, the scent of incense mixing with neon from the window.\n";
            cout << "For a moment, the city feels almost... still.\n";
            break;
        default:
            cout << "Misty tilts her head. \"Guess that’s all the guidance you needed.\"\n";
            break;
    }

    cout << "\nYou step back into the noise of the street, the sound of chimes fading behind you.\n";
    cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
}
