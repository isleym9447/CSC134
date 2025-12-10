#include "scenes/scene_apartment.h"
#include <iostream>

// Simple helper to scale a sprite to fit the window
static void fitSpriteToWindow(sf::Sprite& sprite,
                              const sf::Texture& tex,
                              float targetW,
                              float targetH)
{
    sf::Vector2u size = tex.getSize();
    if (size.x == 0 || size.y == 0) {
        sprite.setScale(1.f, 1.f);
        return;
    }
    float scaleX = targetW / static_cast<float>(size.x);
    float scaleY = targetH / static_cast<float>(size.y);
    float scale  = std::max(scaleX, scaleY);
    sprite.setScale(scale, scale);
}

// Apartment backgrounds (loaded once per program)
static sf::Texture texApartment;
static sf::Texture texApartmentMirror;
static sf::Texture texApartmentKitchen;
static sf::Texture texApartmentComputer;
static bool apartmentTexturesLoaded = false;

static void ensureApartmentTextures()
{
    if (apartmentTexturesLoaded) return;

    auto loadTex = [](sf::Texture& t, const std::string& path) {
        if (!t.loadFromFile(path)) {
            std::cerr << "Failed to load apartment background: " << path << std::endl;
        }
    };

    loadTex(texApartment,         "assets/backgrounds/apartment.png");
    loadTex(texApartmentMirror,   "assets/backgrounds/apartmentmirror.png");
    loadTex(texApartmentKitchen,  "assets/backgrounds/apartmentkitchen.png");
    loadTex(texApartmentComputer, "assets/backgrounds/apartmentcomputer.png");

    apartmentTexturesLoaded = true;
}

// Apply background according to AptBg
static void applyBackground(AptBg bg, sf::Sprite& sprite)
{
    ensureApartmentTextures();

    const sf::Texture* tex = &texApartment;
    switch (bg) {
        case AptBg::Default:  tex = &texApartment;         break;
        case AptBg::Mirror:   tex = &texApartmentMirror;   break;
        case AptBg::Kitchen:  tex = &texApartmentKitchen;  break;
        case AptBg::Computer: tex = &texApartmentComputer; break;
    }

    sprite.setTexture(*tex, true);
    fitSpriteToWindow(sprite, *tex, 1280.f, 720.f);
}

// ------------------------------------------------------------
// SceneApartment implementation
// ------------------------------------------------------------

SceneApartment::SceneApartment()
    : choicesActive(false)
    , buttonsCreated(false)
    , buttonAppearDelay(3.0f)   // <- wait longer so intro text can be read
    , sceneFinished(false)
    , currentBg(AptBg::Default)
{
    ensureApartmentTextures();
    applyBackground(currentBg, bgSprite);

    // Load font for textbox and buttons
    if (!uiFont.loadFromFile("assets/fonts/cyberpunk.ttf")) {
        std::cerr << "Failed to load assets/fonts/cyberpunk.ttf in SceneApartment\n";
    }

    textbox.loadFont("assets/fonts/cyberpunk.ttf");

    // Intro text + menu
    setBgAndText(
        "System",
        ">>> Wake the fuck up, choom. You're still in Night City. <<<\n\n"
        "What do you do before stepping out of your safe apartment?\n"
        
    );
}

void SceneApartment::setBgAndText(const std::string& speaker,
                                  const std::string& text)
{
    applyBackground(currentBg, bgSprite);
    textbox.setDialogue(speaker, text);

    // For the very first intro, we want the delay.
    // For later choices, we still give a tiny delay so text can appear cleanly.
    choicesActive     = false;
    buttonAppearDelay = 0.8f;
}

// ------------------------------------------------------------
// Event handling
// ------------------------------------------------------------
void SceneApartment::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed &&
        event.key.code == sf::Keyboard::Escape)
    {
        // ESC closes scene (let the game decide what to do)
        sceneFinished = true;
        return;
    }

    if (!choicesActive) return;

    if (event.type == sf::Event::MouseButtonPressed &&
        event.mouseButton.button == sf::Mouse::Left)
    {
        float mx = static_cast<float>(event.mouseButton.x);
        float my = static_cast<float>(event.mouseButton.y);

        for (auto& ab : apartmentButtons) {
            if (ab.button.contains(mx, my)) {
                if (ab.onClick) {
                    ab.onClick();
                }
                break;
            }
        }
    }

    if (event.type == sf::Event::MouseMoved) {
        float mx = static_cast<float>(event.mouseMove.x);
        float my = static_cast<float>(event.mouseMove.y);

        for (auto& ab : apartmentButtons) {
            ab.button.setHovered(ab.button.contains(mx, my));
        }
    }
}

// ------------------------------------------------------------
// Update + draw
// ------------------------------------------------------------
void SceneApartment::update(float dt)
{
    textbox.update(dt);
    updateButtonsAfterTextReveal(dt);
}

void SceneApartment::draw(sf::RenderWindow& window)
{
    window.draw(bgSprite);
    textbox.draw(window);
    drawButtons(window);
}

// ------------------------------------------------------------
// Button layout & drawing
// ------------------------------------------------------------
void SceneApartment::updateButtonsAfterTextReveal(float dt)
{
    // We don't have isFullyRevealed, so just use a timer.
    buttonAppearDelay -= dt;
    if (buttonAppearDelay > 0.f) return;

    choicesActive = true;

    if (!buttonsCreated) {
        buttonsCreated = true;

        apartmentButtons.clear();
        apartmentButtons.resize(6);

        // ---- HORIZONTAL LAYOUT AT BOTTOM ----
        const float btnWidth   = 190.f;
        const float btnHeight  = 40.f;
        const float spacing    = 10.f;
        const float totalWidth = 6 * btnWidth + 5 * spacing;
        const float startX     = (1280.f - totalWidth) / 2.f;
        const float y          = 720.f - 70.f;  // near bottom of window

        auto makeButton = [&](int index,
                              const std::string& label,
                              std::function<void()> fn)
        {
            ApartmentButton& ab = apartmentButtons[index];
            ab.button.setFont(uiFont);
            ab.button.setSize(sf::Vector2f(btnWidth, btnHeight));

            float x = startX + index * (btnWidth + spacing);
            ab.button.setPosition(x, y);

            ab.button.setText(label);
            ab.button.setColors(
                sf::Color(10, 10, 25, 230),   // normal
                sf::Color(0, 255, 180, 230),  // hover
                sf::Color::White,             // text
                sf::Color(0, 255, 180, 200)   // outline
            );

            ab.onClick = std::move(fn);
        };

        makeButton(0, "Look in the mirror", [this]() { mirrorDesc();    });
        makeButton(1, "Check inventory",    [this]() { bagDesc();       });
        makeButton(2, "Eat something",      [this]() { eatDesc();       });
        makeButton(3, "Check email",        [this]() { emailDesc();     });
        makeButton(4, "Leave apartment",    [this]() { goToStreet();    });
        makeButton(5, "Go back to bed",     [this]() { goBackToSleep(); });
    }
}

void SceneApartment::drawButtons(sf::RenderWindow& window)
{
    if (!choicesActive) return;

    for (auto& ab : apartmentButtons) {
        ab.button.draw(window);
    }
}

// ------------------------------------------------------------
// Logic for each choice
// ------------------------------------------------------------
void SceneApartment::mirrorDesc()
{
    currentBg = AptBg::Mirror;
    setBgAndText(
        "Narrator",
        "You shuffle into the bathroom and face the dimly lit mirror.\n"
        "Your own tired eyes stare back at you, ringed with neon fatigue.\n"
        "The light above you flickers, buzzing like a cheap braindance rig.\n"
        "Another day in Night City. Same ghost in the glass."
    );
}

void SceneApartment::bagDesc()
{
    currentBg = AptBg::Kitchen;
    setBgAndText(
        "Narrator",
        "You drag your bag across the counter and flick it open.\n"
        "Gear, meds, half-crumpled receipts — the usual mess of a Night City merc.\n"
        "Everything's still where you left it.\n"
        "For now, at least, nothing's gone missing."
    );
}

void SceneApartment::eatDesc()
{
    currentBg = AptBg::Kitchen;
    setBgAndText(
        "Narrator",
        "You crack open the fridge. A wave of cold air — and questionable smells — hits you.\n"
        "Half a donut in a takeout box. An I-Fruit that probably violates three health codes.\n"
        "You grab something vaguely edible and call it breakfast.\n"
        "It won't kill you. Probably."
    );
}

void SceneApartment::emailDesc()
{
    currentBg = AptBg::Computer;
    setBgAndText(
        "Narrator",
        "You sit at the desk and wake the ancient terminal.\n"
        "New messages blink at you in angry neon:\n\n"
        "- A fixer reminding you about \"opportunities\" you keep dodging.\n"
        "- A debt notice from some corpo you don't remember owing.\n"
        "- And one soft ping from an old contact, just asking if you're still alive.\n\n"
        "You stare at the screen a little longer than you mean to."
    );
}

void SceneApartment::goToStreet()
{
    currentBg = AptBg::Default;
    setBgAndText(
        "Narrator",
        "You grab your gear and head for the door.\n"
        "The locks disengage with a mechanical sigh.\n"
        "Night City waits outside — humming, hungry, and already two steps ahead.\n"
        "Time to see what kind of trouble the day has queued up for you."
    );

    sceneFinished = true;
}

void SceneApartment::goBackToSleep()
{
    currentBg = AptBg::Default;
    setBgAndText(
        "Narrator",
        "You flop back onto the bed and let the city noise fade to a distant roar.\n"
        "The world outside keeps moving — gigs, creds, glory, all slipping past.\n"
        "But not today.\n"
        "Today, Night City can run without you.\n"
        ">>> GAME OVER: You chose sleep over glory. Respect. <<<"
    );

    sceneFinished = true;
}
