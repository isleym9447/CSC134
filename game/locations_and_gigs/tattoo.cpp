#include <iostream>
#include <string>
#include <vector>
#include "charcreate.h"   // includes extern vector<string> inventory;
using namespace std;

void tattoo() {
    int artistchoice;
    int tattooselect;

    cout << "\nYou wander the neon-lit streets, looking for a new tattoo spot.\n";
    cout << "Holo-signs flash across the skyline: chrome skulls, synth roses, glowing scripts.\n";
    cout << "Where do you go?\n\n";
    cout << "1. **Kristal’s Chrome Canvas** (Watson) — precise, glowing cyberpunk realism.\n";
    cout << "2. **Razor & Ink** (Heywood) — grunge aesthetics, black ink only.\n";
    cout << "3. **Luna’s Occult Parlor** (Little China) — spiritual tattoos & runes.\n";
    cout << "4. **Reedline Studio** (Westbrook) — minimalist, geometric linework.\n";
    cout << "5. **Nevermind Tattoos** (Japantown) — full-body holographic art.\n";
    cout << "6. Leave — maybe another time.\n";
    cout << "\nEnter your choice: ";
    cin >> artistchoice;

    cout << endl;

    switch (artistchoice) {
        case 1: {
            cout << "You enter Kristal’s Chrome Canvas — it smells like antiseptic and ozone.\n";
            cout << "Kristal smiles, her cybernetic eyes scanning your skin tone for light calibration.\n";
            cout << "Kristal: “Let’s make you shine, choom.”\n\n";
            cout << "Tattoo options:\n";
            cout << "1. Neon snake curling up your spine\n";
            cout << "2. Holo-rose glowing faintly on your wrist\n";
            cout << "3. Circuit halo behind your ear\n";
            cout << "\nChoose your tattoo: ";
            cin >> tattooselect;

            if (tattooselect == 1)
                cout << "\nThe snake coils to life under Kristal’s needle, glowing with pulse-reactive ink.\n";
            else if (tattooselect == 2)
                cout << "\nA soft rose blooms under your skin — subtle until the light hits it just right.\n";
            else if (tattooselect == 3)
                cout << "\nYou hear the faint buzz as Kristal etches perfect circuitry — like a saint of chrome.\n";
            else
                cout << "You change your mind halfway through. Maybe next time.\n";
            break;
        }

        case 2: {
            cout << "The shop is dark — black walls, old music, smell of ink and smoke.\n";
            cout << "The large man at the counter speaks, “Nothing fancy. Just ink and pain. What’ll it be?”\n\n";
            cout << "1. Barbed wire around the wrist\n";
            cout << "2. Flaming skull on shoulder\n";
            cout << "3. Broken heart on the ribs\n";
            cout << "\nChoose your tattoo: ";
            cin >> tattooselect;

            if (tattooselect == 1)
                cout << "\nIt stings like hell. He grins — “Now you look like you’ve been through something.”\n";
            else if (tattooselect == 2)
                cout << "\nThe skull burns in bold black lines — a mark of rebellion.\n";
            else if (tattooselect == 3)
                cout << "\nHe shades the heart with slow care. “Everyone’s got one,” he mutters.\n";
            else
                cout << "You nod, but the buzzing needle makes you reconsider.\n";
            break;
        }

        case 3: {
            cout << "Luna’s Occult Parlor is thick with incense. Runes flicker in candlelight.\n";
            cout << "Luna: “Tattoos are spells, love. Choose carefully.”\n\n";
            cout << "1. Protective sigil over your sternum\n";
            cout << "2. Tiny crescent moon behind your ear\n";
            cout << "3. Tarot card design along your forearm\n";
            cout << "\nChoose your tattoo: ";
            cin >> tattooselect;

            if (tattooselect == 1)
                cout << "\nShe hums softly as the sigil forms, whispering blessings with every stroke.\n";
            else if (tattooselect == 2)
                cout << "\nYou feel a strange calm as the moon ink settles under your skin.\n";
            else if (tattooselect == 3)
                cout << "\nThe card seems to shimmer as the ink dries — fate drawn on flesh.\n";
            else
                cout << "You hesitate, then decide maybe magic and metal don’t mix tonight.\n";
            break;
        }

        case 4: {
            cout << "Fineline Studio is quiet, minimalist — sterile light and perfect symmetry.\n";
            cout << "Red: “We don’t make art. We reveal it.”\n\n";
            cout << "1. Triangular linework on forearm\n";
            cout << "2. Minimalist skyline on collarbone\n";
            cout << "3. Binary code band around wrist\n";
            cout << "\nChoose your tattoo: ";
            cin >> tattooselect;

            if (tattooselect == 1)
                cout << "\nThe design forms sharp and clean — abstract, cold, but oddly beautiful.\n";
            else if (tattooselect == 2)
                cout << "\nThe skyline sits just beneath your skin — a whisper of the city.\n";
            else if (tattooselect == 3)
                cout << "\nBinary digits wrap your wrist. Hidden among them is your birth date.\n";
            else
                cout << "Red raises an eyebrow. “Indecision is its own pattern.”\n";
            break;
        }

        case 5: {
            cout << "You step into Nevermind Tattoos — holographic projections drift above each booth.\n";
            cout << "Nova: “Full spectrum or nothing, baby. Pick your projection.”\n\n";
            cout << "1. Phoenix that flares when your heart rate spikes\n";
            cout << "2. Animated koi swimming around your arm\n";
            cout << "3. Galaxy spiral across your back\n";
            cout << "\nChoose your tattoo: ";
            cin >> tattooselect;

            if (tattooselect == 1)
                cout << "\nThe phoenix bursts to life, glowing brighter with each heartbeat.\n";
            else if (tattooselect == 2)
                cout << "\nKoi flicker beneath your skin, circling your wrist like living light.\n";
            else if (tattooselect == 3)
                cout << "\nA cosmos blooms across your back — you become your own night sky.\n";
            else
                cout << "Nova shrugs. “Another time then, choom.”\n";
            break;
        }

        case 6:
            cout << "You decide to skip it. Maybe another night.\n";
            break;

        default:
            cout << "Invalid choice. You step away from the neon haze.\n";
            break;
    }

    cout << "\nYou leave the shop, the scent of ink and ozone still clinging to your skin.\n";
}
