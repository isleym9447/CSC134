#include "ui/ui_button.h"

UIButton::UIButton()
    : normalColor(20, 20, 40, 220),
      hoverColor(0, 255, 180, 230),
      textColor(sf::Color::White),
      outlineColor(0, 255, 180, 200),
      hovered(false)
{
    rect.setSize({200.f, 40.f});
    rect.setFillColor(normalColor);
    rect.setOutlineThickness(2.f);
    rect.setOutlineColor(outlineColor);

    label.setCharacterSize(22);
}

void UIButton::setFont(const sf::Font& font)
{
    label.setFont(font);
}

void UIButton::setText(const std::string& text)
{
    label.setString(text);

    // center text inside rect
    sf::FloatRect tb = label.getLocalBounds();
    sf::Vector2f pos = rect.getPosition();
    sf::Vector2f size = rect.getSize();

    label.setOrigin(tb.left + tb.width / 2.f,
                    tb.top + tb.height / 2.f);
    label.setPosition(pos.x + size.x / 2.f, pos.y + size.y / 2.f);
}

void UIButton::setPosition(float x, float y)
{
    rect.setPosition(x, y);
    // re-center text
    setText(label.getString());
}

void UIButton::setPosition(const sf::Vector2f& pos)
{
    setPosition(pos.x, pos.y);
}

void UIButton::setSize(const sf::Vector2f& size)
{
    rect.setSize(size);
    // re-center text
    setText(label.getString());
}

void UIButton::setSize(float width, float height)
{
    setSize(sf::Vector2f(width, height));
}

void UIButton::setColors(const sf::Color& normal,
                         const sf::Color& hover,
                         const sf::Color& text,
                         const sf::Color& outline)
{
    normalColor  = normal;
    hoverColor   = hover;
    textColor    = text;
    outlineColor = outline;

    rect.setOutlineColor(outlineColor);
}

void UIButton::setHovered(bool h)
{
    hovered = h;
}

void UIButton::draw(sf::RenderWindow& window)
{
    rect.setFillColor(hovered ? hoverColor : normalColor);
    label.setFillColor(textColor);

    window.draw(rect);
    window.draw(label);
}

bool UIButton::contains(float x, float y) const
{
    return rect.getGlobalBounds().contains(x, y);
}

bool UIButton::contains(const sf::Vector2f& p) const
{
    return contains(p.x, p.y);
}
