#include "scenes/scene_mainmenu.h"
#include "scenemanager.h"
#include "scenes/scene_charcreate.h"
#include <iostream>

SceneMainMenu::SceneMainMenu() {
    // Background
    if (!bgTexture.loadFromFile("assets/backgrounds/title.png"))
        std::cerr << "ERROR: title.png not found\n";

    bgSprite.setTexture(bgTexture);

    // Font
    font.loadFromFile("assets/fonts/cyberpunk.ttf");

    float centerX = 1280.f / 2.f;
    float y = 500.f;

    btnNewGame.setFont(font);
    btnNewGame.setText("NEW GAME");
    btnNewGame.setSize(260, 60);
    btnNewGame.setPosition(centerX - 400, y);

    btnSettings.setFont(font);
    btnSettings.setText("SETTINGS");
    btnSettings.setSize(260, 60);
    btnSettings.setPosition(centerX - 130, y);

    btnCredits.setFont(font);
    btnCredits.setText("CREDITS");
    btnCredits.setSize(260, 60);
    btnCredits.setPosition(centerX + 140, y);

    btnQuit.setFont(font);
    btnQuit.setText("QUIT");
    btnQuit.setSize(260, 60);
    btnQuit.setPosition(centerX + 410, y);
}

void SceneMainMenu::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        float x = event.mouseButton.x;
        float y = event.mouseButton.y;

        if (btnNewGame.contains(x,y)) {
            SceneManager::changeScene(std::make_unique<SceneCharCreate>());
        }
        else if (btnQuit.contains(x,y)) {
            exit(0);
        }
        // settings + credits not implemented yet
    }
}

void SceneMainMenu::update(float) {}

void SceneMainMenu::draw(sf::RenderWindow& window) {
    window.draw(bgSprite);
    btnNewGame.draw(window);
    btnSettings.draw(window);
    btnCredits.draw(window);
    btnQuit.draw(window);
}
