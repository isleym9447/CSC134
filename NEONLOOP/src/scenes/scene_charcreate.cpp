#include "scenes/scene_charcreate.h"
#include <iostream>

SceneCharCreate::SceneCharCreate(player& outPlayerRef)
    : outPlayer(outPlayerRef)
{
    step = Step::Alias;

    texCharCreate.loadFromFile("assets/backgrounds/charcreate.png");
    texLifepath.loadFromFile("assets/backgrounds/lifepath.png");

    bgSprite.setTexture(texCharCreate);

    uiFont.loadFromFile("assets/fonts/cyberpunk.ttf");

    // Alias prompt
    aliasPromptText.setFont(uiFont);
    aliasPromptText.setCharacterSize(36);
    aliasPromptText.setFillColor(sf::Color::White);
    aliasPromptText.setString("Who are you?\nEnter your alias.");
    aliasPromptText.setPosition(1280/2 - aliasPromptText.getLocalBounds().width/2, 200);

    aliasInputText.setFont(uiFont);
    aliasInputText.setCharacterSize(32);
    aliasInputText.setFillColor(sf::Color(0,255,180));
    aliasInputText.setPosition(1280/2 - 200, 350);

    // Choice label
    choiceLabelText.setFont(uiFont);
    choiceLabelText.setCharacterSize(32);
    choiceLabelText.setFillColor(sf::Color::White);

    // Boot loading text
    loadingText.setFont(uiFont);
    loadingText.setCharacterSize(30);
    loadingText.setFillColor(sf::Color::White);
}

void SceneCharCreate::fitSpriteToWindow(sf::Sprite& sprite, const sf::Texture& tex) {
    float sx = 1280.f / tex.getSize().x;
    float sy = 720.f / tex.getSize().y;
    sprite.setScale(sx, sy);
}

void SceneCharCreate::setStep(Step s) {
    step = s;
    choices.clear();

    if (s == Step::Alias) {
        bgSprite.setTexture(texCharCreate, true);
        fitSpriteToWindow(bgSprite, texCharCreate);
        return;
    }

    if (s == Step::HairColor) {
        choiceLabelText.setString("Choose your hair color.");
    }
    else if (s == Step::HairStyle) {
        choiceLabelText.setString("Choose your haircut.");
    }
    else if (s == Step::EyeColor) {
        choiceLabelText.setString("Choose your eye color.");
    }
    else if (s == Step::Lifepath) {
        bgSprite.setTexture(texLifepath, true);
        fitSpriteToWindow(bgSprite, texLifepath);
        choiceLabelText.setString("Choose your Lifepath.");
    }
    else if (s == Step::Boot) {
        bgSprite.setColor(sf::Color::Black); // BLACK SCREEN

        fullBootString =
            "Initializing player data\n"
            "Syncing neural profile\n"
            "Deploying consciousness to Night City\n"
            "Welcome, " + alias + "";

        loadingText.setString("");
        loadingText.setPosition(1280/2 - 300, 720/2 - 50);

        bootCharIndex = 0;
        bootTimer = 0.f;
        return;
    }

    // Center choice label
    sf::FloatRect lb = choiceLabelText.getLocalBounds();
    choiceLabelText.setOrigin(lb.width/2, lb.height/2);
    choiceLabelText.setPosition(1280/2, 120);

    buildChoicesForStep();
}

void SceneCharCreate::buildChoicesForStep() {
    float btnW = 300;
    float btnH = 55;
    float startX = 1280/2 - btnW/2;
    float startY = 260;

    auto addBtn = [&](int val, const std::string& txt) {
        Choice c;
        c.value = val;
        c.button.setFont(uiFont);
        c.button.setSize(btnW, btnH);
        c.button.setPosition(startX, startY + choices.size()*75);
        c.button.setText(txt);
        choices.push_back(c);
    };

    switch (step) {
        case Step::HairColor:
            addBtn(1,"Black");
            addBtn(2,"Blonde");
            addBtn(3,"Pink");
            addBtn(4,"Purple");
            break;

        case Step::HairStyle:
            addBtn(1,"Long");
            addBtn(2,"Short");
            addBtn(3,"Braided");
            break;

        case Step::EyeColor:
            addBtn(1,"Brown");
            addBtn(2,"Blue");
            addBtn(3,"Green");
            addBtn(4,"Cyber Pink");
            break;

        case Step::Lifepath:
            addBtn(1,"Nomad");
            addBtn(2,"Streetkid");
            addBtn(3,"Corpo");
            break;

        default: break;
    }
}

void SceneCharCreate::handleEvent(const sf::Event& event) {
    if (step == Step::Alias) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8 && !alias.empty()) {
                alias.pop_back();
            }
            else if (event.text.unicode == 13 && !alias.empty()) {
                setStep(Step::HairColor);
            }
            else if (event.text.unicode < 128 && alias.size() < 16) {
                alias += static_cast<char>(event.text.unicode);
            }
        }
        return;
    }

    if (step == Step::Boot) return;

    if (event.type == sf::Event::MouseButtonPressed) {
        float mx = event.mouseButton.x;
        float my = event.mouseButton.y;
        handleClick(mx, my);
    }
}

void SceneCharCreate::handleClick(float x, float y) {
    for (auto& c : choices) {
        if (c.button.contains(x,y)) {

            if (step == Step::HairColor) {
                haircolorchoice = c.value;
                setStep(Step::HairStyle);
            }
            else if (step == Step::HairStyle) {
                hairstylechoice = c.value;
                setStep(Step::EyeColor);
            }
            else if (step == Step::EyeColor) {
                eyecolorchoice = c.value;
                setStep(Step::Lifepath);
            }
            else if (step == Step::Lifepath) {
                lifepathchoice = c.value;
                setStep(Step::Boot);
            }
        }
    }
}

void SceneCharCreate::update(float dt) {

    if (step == Step::Alias) {
        aliasInputText.setString(alias);
        return;
    }

    // Typewriter loading screen
    if (step == Step::Boot) {
        bootTimer += dt;

        if (bootTimer >= bootSpeed && bootCharIndex < fullBootString.size()) {
            bootTimer = 0.f;
            loadingText.setString(fullBootString.substr(0, bootCharIndex++));
        }

        if (bootCharIndex >= fullBootString.size()) {
            finalizePlayer();
            finished = true;
        }
    }
}

void SceneCharCreate::draw(sf::RenderWindow& window) {

    if (step != Step::Boot)
        window.draw(bgSprite);
    else {
        // Boot is black screen
        sf::RectangleShape black(sf::Vector2f(1280,720));
        black.setFillColor(sf::Color::Black);
        window.draw(black);
    }

    // ALIAS ENTRY
    if (step == Step::Alias) {
        window.draw(aliasPromptText);
        window.draw(aliasInputText);
        return;
    }

    // BOOT LOADING SCREEN
    if (step == Step::Boot) {
        window.draw(loadingText);
        return;
    }

    // CHOICE SCREENS
    window.draw(choiceLabelText);
    for (auto& c : choices)
        c.button.draw(window);
}

void SceneCharCreate::finalizePlayer() {

    player newPlayer(alias, mapLifepath(lifepathchoice));
    newPlayer.sethaircolor(mapHairColor(haircolorchoice));
    newPlayer.sethairstyle(mapHairStyle(hairstylechoice));
    newPlayer.seteyecolor(mapEyeColor(eyecolorchoice));

    outPlayer = newPlayer;
}

std::string SceneCharCreate::mapHairColor(int id) {
    switch(id) {
        case 1: return "Black";
        case 2: return "Blonde";
        case 3: return "Pink";
        case 4: return "Purple";
    }
    return "Unknown";
}

std::string SceneCharCreate::mapHairStyle(int id) {
    switch(id) {
        case 1: return "Long";
        case 2: return "Short";
        case 3: return "Braided";
    }
    return "Unknown";
}

std::string SceneCharCreate::mapEyeColor(int id) {
    switch(id) {
        case 1: return "Brown";
        case 2: return "Blue";
        case 3: return "Green";
        case 4: return "Cyber Pink";
    }
    return "Unknown";
}

std::string SceneCharCreate::mapLifepath(int id) {
    switch(id) {
        case 1: return "Nomad";
        case 2: return "Streetkid";
        case 3: return "Corpo";
    }
    return "Unknown";
}
