#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class UIButton {
public:
    UIButton();

    void setFont(const sf::Font& font);
    void setText(const std::string& text);

    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& pos);

    void setSize(const sf::Vector2f& size);
    // convenience overload
    void setSize(float width, float height);

    void setColors(const sf::Color& normal,
                   const sf::Color& hover,
                   const sf::Color& text,
                   const sf::Color& outline);

    void setHovered(bool h);

    void draw(sf::RenderWindow& window);

    bool contains(float x, float y) const;
    bool contains(const sf::Vector2f& p) const;

private:
    sf::RectangleShape rect;
    sf::Text           label;

    sf::Color normalColor;
    sf::Color hoverColor;
    sf::Color textColor;
    sf::Color outlineColor;

    bool hovered;
};
