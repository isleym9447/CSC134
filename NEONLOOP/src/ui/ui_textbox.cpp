#include "ui/ui_textbox.h"
#include <iostream>

UITextBox::UITextBox()
: shownChars(0),
  charsPerSecond(40.0f),
  timeAccumulator(0.0f)
{
    // Main textbox at bottom
    box.setSize(sf::Vector2f(1280.f - 80.f, 200.f));
    box.setPosition(40.f, 720.f - 230.f);
    box.setFillColor(sf::Color(10, 10, 30, 220));
    box.setOutlineThickness(2.f);
    box.setOutlineColor(sf::Color(0, 255, 255, 200)); // neon cyan

    // Name box above left
    nameBox.setSize(sf::Vector2f(250.f, 40.f));
    nameBox.setPosition(box.getPosition().x + 10.f, box.getPosition().y - 45.f);
    nameBox.setFillColor(sf::Color(10, 10, 30, 230));
    nameBox.setOutlineThickness(2.f);
    nameBox.setOutlineColor(sf::Color(255, 0, 255, 200)); // neon magenta

    nameText.setCharacterSize(20);
    nameText.setFillColor(sf::Color::White);

    dialogueText.setCharacterSize(22);
    dialogueText.setFillColor(sf::Color::White);
    dialogueText.setPosition(box.getPosition().x + 20.f, box.getPosition().y + 20.f);
}

bool UITextBox::loadFont(const std::string& fontPath) {
    static sf::Font font; // shared so we don't reload per instance

    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font: " << fontPath << "\n";
        return false;
    }
    nameText.setFont(font);
    dialogueText.setFont(font);
    return true;
}

void UITextBox::setDialogue(const std::string& speaker, const std::string& text) {
    nameText.setString(speaker);
    nameText.setPosition(nameBox.getPosition().x + 10.f, nameBox.getPosition().y + 8.f);

    fullText = text;
    shownChars = 0;
    timeAccumulator = 0.f;
    dialogueText.setString("");
}

void UITextBox::update(float dt) {
    if (shownChars >= fullText.size())
        return;

    timeAccumulator += dt;
    float secondsPerChar = 1.f / charsPerSecond;

    while (timeAccumulator >= secondsPerChar && shownChars < fullText.size()) {
        shownChars++;
        timeAccumulator -= secondsPerChar;
        dialogueText.setString(fullText.substr(0, shownChars));
    }
}

void UITextBox::draw(sf::RenderWindow& window) {
    window.draw(box);
    window.draw(nameBox);
    window.draw(nameText);
    window.draw(dialogueText);
}

void UITextBox::revealAll() {
    shownChars = fullText.size();
    dialogueText.setString(fullText);
}
