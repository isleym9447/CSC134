#pragma once
#include <SFML/Graphics.hpp>
#include <string>

#include "scenemanager.h"     // ✅ instead of scene.hpp
#include "ui/ui_button.h"
#include "player.h"


class SceneMainMenu : public Scene {
public:
    SceneMainMenu();
    void handleEvent(const sf::Event&) override;
    void update(float dt) override;
    void draw(sf::RenderWindow&) override;

private:
    sf::Texture bgTexture;
    sf::Sprite bgSprite;

    sf::Font font;

    UIButton btnNewGame;
    UIButton btnSettings;
    UIButton btnCredits;
    UIButton btnQuit;
};

#endif
