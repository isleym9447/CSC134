#include "scenes/scene_apartment.h"
#include <iostream>

// Helper: scale a sprite to fit a target resolution
static void fitSpriteToWindow(sf::Sprite& sprite, const sf::Texture& tex,
                              float targetW, float targetH) {
    sf::Vector2u size = tex.getSize();
    if (size.x == 0 || size.y == 0) return;
    float scaleX = targetW / size.x;
    float scaleY = targetH / size.y;
    sprite.setScale(scaleX, scaleY);
}

SceneApartment::SceneApartment() {
    // Load backgrounds
    if (!texDefault.loadFromFile("assets/backgrounds/apartment.png")) {
        std::cerr << "Failed to load: assets/backgrounds/apartment.png\n";
    }
    if (!texComputer.loadFromFile("assets/backgrounds/apartmentcomputer.png")) {
        std::cerr << "Failed to load: assets/backgrounds/apartmentcomputer.png\n";
    }
    if (!texMirror.loadFromFile("assets/backgrounds/apartmentmirror.png")) {
        std::cerr << "Failed to load: assets/backgrounds/apartmentmirror.png\n";
    }
    if (!texKitchen.loadFromFile("assets/backgrounds/apartmentkitchen.png")) {
        std::cerr << "Failed to load: assets/backgrounds/apartmentkitchen.png\n";
    }

    setView(View::Default);

    // Load UI font
    if (!uiFont.loadFromFile("assets/fonts/cyberpunk.ttf")) { // or .ttf
        std::cerr << "Failed to load font: assets/fonts/cyberpunk.ttf\n";
    }

    // Textbox font
    textbox.loadFont("assets/fonts/cyberpunk.ttf");

    // Intro script, then we hand control to buttons
    introScript.push_back({"Narrator",
        "The sound of your alarm wakes you up. Another day in Night City."});
    introScript.push_back({"Narrator",
        "You drag yourself out of bed and look around your tiny apartment."});
    introScript.push_back({"System",
        "What do you do? (Use the buttons below to choose.)"});

    advanceIntro();

    // Create clickable buttons
    initButtons();
}

void SceneApartment::initButtons() {
    menuButtons.clear();

    // Smaller buttons
    const float buttonWidth  = 180.f;
    const float buttonHeight = 36.f;

    // Layout: 3 buttons per row, 2 rows
    const int buttonsPerRow = 3;

    const float startX = 60.f;
    const float startY = 720.f - 120.f; // first row a bit above bottom
    const float gapX  = 20.f;
    const float gapY  = 10.f;

    auto makeButton = [&](const std::string& label, Action action, int index) {
        ActionButton ab;
        ab.action = action;
        ab.button = UIButton();
        ab.button.setFont(uiFont);
        ab.button.setSize(buttonWidth, buttonHeight);

        int row = index / buttonsPerRow;
        int col = index % buttonsPerRow;

        float x = startX + col * (buttonWidth + gapX);
        float y = startY + row * (buttonHeight + gapY);

        ab.button.setPosition(x, y);
        ab.button.setColors(
            sf::Color(20, 20, 40, 230),         // normal
            sf::Color(0, 255, 180, 230),        // hover
            sf::Color::White,                   // text
            sf::Color(0, 255, 180, 200)         // outline
        );
        ab.button.setText(label);
        menuButtons.push_back(ab);
    };

    // Matches your earlier choices
    makeButton("Look in mirror",   Action::Mirror,    0);
    makeButton("Check inventory",  Action::Inventory, 1);
    makeButton("Eat something",    Action::Eat,       2);
    makeButton("Check email",      Action::Email,     3);
    makeButton("Leave apartment",  Action::Leave,     4);
    makeButton("Go back to bed",   Action::Bed,       5);
}


void SceneApartment::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseMoved) {
        if (!showButtons) return;    // 🔒 no hover until intro done

        float mx = static_cast<float>(event.mouseMove.x);
        float my = static_cast<float>(event.mouseMove.y);

        for (auto& ab : menuButtons) {
            bool hov = ab.button.contains(mx, my);
            ab.button.setHovered(hov);
        }
    }

    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left) {

        float mx = static_cast<float>(event.mouseButton.x);
        float my = static_cast<float>(event.mouseButton.y);

        // While intro is still going: click acts like "advance/skip"
        if (currentIndex < static_cast<int>(introScript.size())) {
            if (!textbox.isFinished()) {
                textbox.revealAll();
            } else {
                advanceIntro();
            }
            return;
        }

        // After intro: buttons actually work
        if (showButtons) {
            handleClick(mx, my);
        }
    }

    // Optional: Space/Enter also advance intro
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space ||
            event.key.code == sf::Keyboard::Enter) {

            if (!textbox.isFinished()) {
                textbox.revealAll();
            } else {
                advanceIntro();
            }
        }
    }
}


void SceneApartment::handleClick(float x, float y) {
    if (!showButtons)
        return;

    for (auto& ab : menuButtons) {
        if (ab.button.contains(x, y)) {
            performAction(ab.action);
            return;
        }
    }
}


void SceneApartment::performAction(Action action) {
    switch (action) {
        case Action::Mirror:
            setView(View::Mirror);
            textbox.setDialogue("Emiko",
                "You step into the bathroom and stare into the dimly lit mirror. Still alive. Still you.");
            break;

        case Action::Inventory:
            setView(View::Default);
            textbox.setDialogue("Narrator",
                "You rummage through your stuff on the counter. You'll hook the full inventory system in later.");
            break;

        case Action::Eat:
            setView(View::Kitchen);
            textbox.setDialogue("Emiko",
                "You wander into the kitchen. The fridge hums quietly, daring you to open it.");
            break;

        case Action::Email:
            setView(View::Computer);
            textbox.setDialogue("Emiko",
                "You sit down at your computer and open your inbox. Time to see who wants something from you now.");
            break;

        case Action::Leave:
            setView(View::Default);
            textbox.setDialogue("Narrator",
                "You head toward the door. The sounds and smells of Night City leak in from the hallway.");
            // Later: trigger scene transition here using SceneManager
            break;

        case Action::Bed:
            setView(View::Default);
            textbox.setDialogue("Narrator",
                "You collapse back onto the bed. Just five more minutes... right?");
            break;
    }
}

void SceneApartment::update(float dt) {
    textbox.update(dt);
}

void SceneApartment::draw(sf::RenderWindow& window) {
    window.draw(bgSprite);
    textbox.draw(window);

    if (showButtons) {
        for (auto& ab : menuButtons) {
            ab.button.draw(window);
        }
    }
}


void SceneApartment::advanceIntro() {
    if (currentIndex >= static_cast<int>(introScript.size())) {
        // Intro is fully done → enable buttons
        showButtons = true;
        return;
    }

    const Line& line = introScript[currentIndex];
    textbox.setDialogue(line.speaker, line.text);
    currentIndex++;
}


void SceneApartment::setView(View v) {
    currentView = v;

    switch (currentView) {
        case View::Default:
            bgSprite.setTexture(texDefault, true);
            fitSpriteToWindow(bgSprite, texDefault, 1280.f, 720.f);
            break;
        case View::Computer:
            bgSprite.setTexture(texComputer, true);
            fitSpriteToWindow(bgSprite, texComputer, 1280.f, 720.f);
            break;
        case View::Mirror:
            bgSprite.setTexture(texMirror, true);
            fitSpriteToWindow(bgSprite, texMirror, 1280.f, 720.f);
            break;
        case View::Kitchen:
            bgSprite.setTexture(texKitchen, true);
            fitSpriteToWindow(bgSprite, texKitchen, 1280.f, 720.f);
            break;
    }
}
