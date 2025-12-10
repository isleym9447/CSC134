#ifndef UI_TEXTBOX_H
#define UI_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <string>

class UITextBox {
public:
    UITextBox();

    // Load a font for the text
    bool loadFont(const std::string& fontPath);

    // Set speaker name + dialogue line
    void setDialogue(const std::string& speaker, const std::string& text);

    // Update typewriter effect
    void update(float dt);

    // Draw box, name, and text
    void draw(sf::RenderWindow& window);

    // Skip typewriter and show whole line
    void revealAll();

    bool isFinished() const { return shownChars >= fullText.size(); }

private:
    sf::RectangleShape box;
    sf::RectangleShape nameBox;

    sf::Text nameText;
    sf::Text dialogueText;

    std::string fullText;
    std::size_t shownChars;
    float charsPerSecond;
    float timeAccumulator;
};

#endif
