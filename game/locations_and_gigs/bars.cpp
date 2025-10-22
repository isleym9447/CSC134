#include <iostream>
#include <string>
using namespace std;


/*
=========================================================
 BARS.CPP — FUTURE EXPANSION IDEAS & SYSTEM INTEGRATIONS
=========================================================

[🔹 SYSTEM HOOK IDEAS]

• STREET CRED REQUIREMENTS:
    - Require streetcred >= 10 to enter Afterlife.
    - Totentanz might require streetcred >= 5 (or a Maelstrom encounter first).
    - Lizzie’s always open (neutral territory).

• CORPO INFLUENCE EFFECTS:
    - If (corpoinfluence == true):
        - Some bars (Totentanz) react with hostility.
        - Afterlife patrons distrust corpo types.
        - Rogue might have unique dialogue: “Didn’t think I’d see a suit down here.”
        - At Lizzie’s, Moxes might flirt but not trust you.

• DRINK EFFECTS:
    - Temporary stat modifiers (body, reflex, tech, cool) for next encounter.
    - Chance for mild hangover / blurred vision flavor next morning.
    - Possible dialogue changes if intoxicated.

• REPUTATION FLAGS:
    - Visiting each bar for the first time could increment unique counters.
      e.g.  visited_lizzies = true, visited_afterlife = true, visited_totentanz = true
    - Later used for dialogue or gig unlocks:
        “Heard you’ve been around Night City’s hotspots.”

• EVENT HOOKS:
    - LIZZIE’S:
        - Judy or a Mox could offer a quick gig.
        - Braindance could trigger a hidden lore flashback.
    - AFTERLIFE:
        - Talking to Rogue sets a flag → “metRogue = true”
          (unlocks fixer-style gig or special dialogue later).
        - Sitting at a booth could trigger overheard merc chatter → gig lead.
    - TOTENTANZ:
        - Maelstrom crowdwatch could trigger random combat event.
        - “Slip into backroom” may lead to illegal BD or side job offer.

• TIME-BASED VARIATION:
    - Different bar dialogue if it’s “night”, “late night”, or “early morning”.
    - Add cooldowns: can’t revisit same bar twice in a row.

• ROMANCE & SOCIAL REACTIONS:
    - High Cool stat: special bar dialogue options.
    - Corpo or Streetkid origin could alter bartenders’ responses.
    - Potential flirt scenes at Lizzie’s (Mox dancers, patrons, etc.).

• AUDIO / VISUAL FLAVOR:
    - ASCII ambient sound cues or HUD color changes per bar.
        Lizzie’s = pink/purple neon
        Afterlife = blue/silver cold tone
        Totentanz = red/strobe warning

• FUTURE SYSTEM INTEGRATIONS:
    - Drinking too much might lower stealth accuracy temporarily.
    - Setting rogueFlag = true could allow new fixer call options later.
    - Expanding bars() into a hub loop with sub-functions (lizzies(), afterlife(), totentanz()) for cleaner modularity.

=========================================================
*/













void bars() {
    int barchoice;
    int actionchoice;
    int drinkchoice;

    cout << "\nNight City after dark. Neon bleeds through the rain and music spills into the streets.\n";
    cout << "You check your holo-map — three hotspots still alive tonight.\n\n";

    cout << "1. Lizzie’s Bar — Mox neon, dancers, and braindance haze.\n";
    cout << "2. Afterlife — the mercs’ sanctuary, where legends never die.\n";
    cout << "3. Totentanz — chaos, metal, Maelstrom territory.\n";
    cout << "4. Leave — maybe another night.\n";
    cout << "\nEnter your choice: ";
    cin >> barchoice;
    cout << endl;

    // ==================================================
    // LIZZIE’S BAR
    // ==================================================
    if (barchoice == 1) {
        cout << "You push through Lizzie’s violet glow. Moxes laugh over the thump of bass,\n";
        cout << "dancers spin under pink holograms, and braindance rigs hum from upstairs.\n";

        cout << "\nWhat do you do?\n";
        cout << "1. Get a drink\n";
        cout << "2. Dance\n";
        cout << "3. Watch a BD\n";
        cout << "4. Leave\n";
        cout << "\nChoose: ";
        cin >> actionchoice;
        cout << endl;

        if (actionchoice == 1) {
            cout << "You lean on the bar. The bartender eyes you with a smirk.\n";
            cout << "“What’ll it be, choom?”\n\n";
            cout << "1. Tequila Especial — smooth and fiery.\n";
            cout << "2. Chateau Delen 2012 — overpriced, imported, and barely real.\n";
            cout << "3. Broseph Ale — cheap, bitter, and familiar.\n";
            cout << "\nOrder: ";
            cin >> drinkchoice;
            cout << endl;

            if (drinkchoice == 1)
                cout << "The tequila burns clean — sweet aftertaste, like synthetic lime and regret.\n";
            else if (drinkchoice == 2)
                cout << "You sip the fake vintage wine. For a second, you almost believe the label.\n";
            else if (drinkchoice == 3)
                cout << "Broseph Ale — the Night City classic. Warm, flat, comforting in its own way.\n";
            else
                cout << "You wave the bartender off. Maybe later.\n";
        }
        else if (actionchoice == 2)
            cout << "You let the music take you — pulse synced to the bass, lights strobed across your chrome.\n";
        else if (actionchoice == 3)
            cout << "Upstairs, a BD chair hums softly. You slot in for a short run — someone else’s memories, someone else’s night.\n";
        else if (actionchoice == 4)
            cout << "You step away from the neon and back into the city’s pulse.\n";
        else
            cout << "You linger a moment, lost in the haze.\n";
    }

    // ==================================================
    // AFTERLIFE
    // ==================================================
    else if (barchoice == 2) {
        cout << "You step into the Afterlife — cold light, steel walls, and whispers of legends.\n";
        cout << "Mercs talk shop under holo-names of the fallen, and the air smells like old gun oil and money.\n";

        cout << "\nWhat do you do?\n";
        cout << "1. Get a drink\n";
        cout << "2. Talk to the Queen of the Afterlife (Rogue)\n";
        cout << "3. Sit at a booth\n";
        cout << "4. Leave\n";
        cout << "\nChoose: ";
        cin >> actionchoice;
        cout << endl;

        if (actionchoice == 1) {
            cout << "The bartender nods. “What’s your poison?”\n\n";
            cout << "1. The Johnny Silverhand - A tequila old fashioned with a splash of beer and a chili garnish. For the rockerboy who never gave up.\n";
            cout << "2. The Jackie Welles - A shot of vodka, lime juice, ginger beer and, most importantly… a splash of love.\n";
            cout << "3. The David Martinez - A shot of vodka on the rocks, topped with NiCola. Aim high and go out with a bang.\n";
            cout << "\nOrder: ";
            cin >> drinkchoice;
            cout << endl;

            if (drinkchoice == 1)
                cout << "The Johnny burns your throat and memories alike.\n";
            else if (drinkchoice == 2)
                cout << "The Jackie is smooth and warm. Just like the proud son of Heywood himself was.\n";
            else if (drinkchoice == 3)
                cout << "The David hits hard and fades fast — just like the man himself.\n";
            else
                cout << "You change your mind. Maybe just water.\n";
        }
        else if (actionchoice == 2)
            cout << "Rogue’s at her usual spot — sharp gaze, sharper words. She looks you up and down.\n"
                    "Rogue: “You got biz, or you’re just another tourist?”\n"
                    "You talk for a bit — small talk mixed with subtle threats. Classic Rogue.\n";
        else if (actionchoice == 3)
            cout << "You take a booth alone. Mercs talk shop nearby — contracts, chrome, death. Feels like history.\n";
        else if (actionchoice == 4)
            cout << "You finish your drink and nod to the bartender on your way out.\n";
        else
            cout << "You linger in the dim light, watching merc legends trade stories.\n";
    }

    // ==================================================
    // TOTENTANZ
    // ==================================================
    else if (barchoice == 3) {
        cout << "You descend into Totentanz — a fortress of noise and flashing red light.\n";
        cout << "The floor shakes from the bass, Maelstrom gangoons throwing themselves into each other like cybernetic storms.\n";

        cout << "\nWhat do you do?\n";
        cout << "1. Get a drink\n";
        cout << "2. Crowdwatch (Maelstrom’s always up to something)\n";
        cout << "3. Slip into the backroom\n";
        cout << "4. Leave\n";
        cout << "\nChoose: ";
        cin >> actionchoice;
        cout << endl;

        if (actionchoice == 1) {
            cout << "The bartender’s face is half steel, half tattoos. “Pick fast, choom.”\n\n";
            cout << "1. 21st Stout — black and bitter.\n";
            cout << "2. Calavera Feliz — neon sugar and synthetic lime.\n";
            cout << "3. Calavera Feliz — yeah, there’s two taps of it. Don’t ask.\n";
            cout << "\nOrder: ";
            cin >> drinkchoice;
            cout << endl;

            if (drinkchoice == 1)
                cout << "The stout is thick, metallic, and strong enough to knock a borg offline.\n";
            else if (drinkchoice == 2 || drinkchoice == 3)
                cout << "The Calavera Feliz tastes like chemical summer and regret — classic Totentanz.\n";
            else
                cout << "You change your mind and step away before the bartender changes *your* mind.\n";
        }
        else if (actionchoice == 2)
            cout << "You stay near the wall, watching Maelstrom run their chaos routine — new chrome on display, blood in the lights.\n";
        else if (actionchoice == 3)
            cout << "You slip into the backroom. A few edgerunners are arguing over shards and eddies — better not interrupt.\n";
        else if (actionchoice == 4)
            cout << "You decide you like your bones unbroken tonight and head for the exit.\n";
        else
            cout << "You blink through the strobe lights, unsure what’s real or just flashing steel.\n";
    }

    // ==================================================
    // LEAVE / DEFAULT
    // ==================================================
    else if (barchoice == 4)
        cout << "You decide to skip the nightlife. Night City still hums, waiting for your next bad idea.\n";
    else
        cout << "Invalid choice. You scroll through the listings again but end up just walking the streets.\n";

    cout << "\nThe night stretches on — another corner, another story waiting to happen.\n";
}
