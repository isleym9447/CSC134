#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "scenemanager.h"     
#include "player.h"
#include "ui/ui_button.h"



class SceneCharCreate : public Scene {
public:
    explicit SceneCharCreate(player& outPlayerRef);

    void handleEvent(const sf::Event& event) override;
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    bool isFinished() const override { return finished; }

private:
    enum class Step {
        Alias,
        HairColor,
        HairStyle,
        EyeColor,
        Lifepath,
        Boot
    };

    struct Choice {
        int value;
        UIButton button;
    };

    void setStep(Step s);
    void buildChoicesForStep();
    void handleClick(float x, float y);
    void finalizePlayer();
    void fitSpriteToWindow(sf::Sprite& sprite, const sf::Texture& tex);

    // Mapping functions
    std::string mapHairColor(int id);
    std::string mapHairStyle(int id);
    std::string mapEyeColor(int id);
    std::string mapLifepath(int id);

private:
    Step step;
    bool finished = false;

    // Backgrounds
    sf::Texture texCharCreate;
    sf::Texture texLifepath;
    sf::Sprite bgSprite;

    // Fonts
    sf::Font uiFont;

    // Alias UI
    sf::Text aliasPromptText;
    sf::Text aliasInputText;

    // Choice Label (above boxes)
    sf::Text choiceLabelText;

    // Boot loading text
    sf::Text loadingText;
    std::string fullBootString;
    std::size_t bootCharIndex = 0;
    float bootTimer = 0.f;
    const float bootSpeed = 0.03f; // readable fast typing

    // Choice buttons
    std::vector<Choice> choices;

    // Stored values
    std::string alias;
    int haircolorchoice = -1;
    int hairstylechoice = -1;
    int eyecolorchoice = -1;
    int lifepathchoice = -1;

    int streetcred = 0;
    int eddies = 0;
    bool corpoinfluence = false;

    std::string vehicle;
    std::vector<std::string> inventory;

    player& outPlayer;
};
