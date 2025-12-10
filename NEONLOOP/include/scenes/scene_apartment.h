#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "scenemanager.h"     
#include "player.h"
#include "ui/ui_button.h"
#include "ui/ui_textbox.h"


class SceneApartment : public Scene {
public:
    SceneApartment();

    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    bool isFinished() const override { return finished; }

private:
    enum class View {
        Default,
        Computer,
        Mirror,
        Kitchen
    };

    enum class Action {
        Mirror,
        Inventory,
        Eat,
        Email,
        Leave,
        Bed
    };

    struct ActionButton {
        Action action;
        UIButton button;
    };

    void initButtons();
    void handleClick(float x, float y);
    void performAction(Action action);

    void advanceIntro();
    void setView(View v);

    sf::Sprite  bgSprite;
    sf::Texture texDefault;
    sf::Texture texComputer;
    sf::Texture texMirror;
    sf::Texture texKitchen;

    UITextBox textbox;
    sf::Font uiFont;

    struct Line {
        std::string speaker;
        std::string text;
    };

    std::vector<Line> introScript;
    int currentIndex = 0;
    bool finished = false;

    View currentView = View::Default;

    std::vector<ActionButton> menuButtons;

    bool showButtons = false;   // 👈 NEW: only draw/handle buttons when true
};
