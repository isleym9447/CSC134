#ifndef SCENE_APARTMENT_H
#define SCENE_APARTMENT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include <string>

#include "scene.hpp"
#include "ui/ui_button.h"
#include "ui/ui_textbox.h"

// Which background of the apartment we're showing
enum class AptBg {
    Default,
    Mirror,
    Kitchen,
    Computer
};

class SceneApartment : public Scene {
public:
    SceneApartment();

    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    bool isFinished() const override { return sceneFinished; }

private:
    UITextBox textbox;
    sf::Sprite bgSprite;
    sf::Font uiFont;   // font for buttons

    struct ApartmentButton {
        UIButton button;
        std::function<void()> onClick;
    };

    std::vector<ApartmentButton> apartmentButtons;
    bool choicesActive;
    bool buttonsCreated;
    float buttonAppearDelay;
    bool sceneFinished;
    AptBg currentBg;

    void updateButtonsAfterTextReveal(float dt);
    void drawButtons(sf::RenderWindow& window);

    // Logic for each option
    void mirrorDesc();
    void bagDesc();
    void eatDesc();
    void emailDesc();
    void goToStreet();
    void goBackToSleep();

    // Helper to set background + dialogue and reset button timing
    void setBgAndText(const std::string& speaker, const std::string& text);
};

#endif // SCENE_APARTMENT_H
