#include "MyClass.hpp"
#include "Gui.h"
#include "Game.h"
sf::Color MyClass::RandomColor(int min, int max) {
    if (max > 255)
        max = 255;
    if (min < 0)
        min = 0;

    return sf::Color(Random(min, max), Random(min, max), Random(min, max));
}

void MyClass::GlobalUI::setName(const std::string& newName) {
    name = newName;
}

void MyClass::GlobalUI::setBgSize(const sf::Vector2f& newBgSize) {
    bgSize = newBgSize;
}

void MyClass::GlobalUI::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;
}

void MyClass::GlobalUI::setBgColor(const sf::Color& newBgColor) {
    bgColor = newBgColor;
}

void MyClass::GlobalUI::setTransparency(int value) {
    if (value < 0) value = 0;
    if (value > 255) value = 255;
    transparency = value;
    bgColor = sf::Color(bgColor.r, bgColor.g, bgColor.b, transparency);
}

void MyClass::GlobalUI::setStrokeTransparency(int value)
{
    if (value < 0) value = 0;
    if (value > 255) value = 255;
    strokeTransparency = value;
    strokeColor = sf::Color(strokeColor.r, strokeColor.g, strokeColor.b, strokeTransparency);

}

void MyClass::GlobalUI::setStrokeThickness(int value)
{
    strokeThickness = value;
}

void MyClass::GlobalUI::setStrokeColor(const sf::Color& newColor)
{
    strokeColor = newColor;
}

// Implémentation des getters
std::string MyClass::GlobalUI::getName() const {
    return name;
}

sf::Vector2f MyClass::GlobalUI::getBgSize() const {
    return bgSize;
}

sf::Vector2f MyClass::GlobalUI::getPosition() const {
    return position;
}

sf::Color MyClass::GlobalUI::getBgColor() const {
    return bgColor;
}

int MyClass::GlobalUI::getTransparency() const {
    return transparency;
}

int MyClass::GlobalUI::getStrokeThickness() const
{
    return strokeThickness;
}

int MyClass::GlobalUI::getStrokeTransparency() const
{
    return strokeTransparency;
}

sf::Color MyClass::GlobalUI::getStrokeColor() const
{
    return strokeColor;
}

float magnitude2D(float x, float y) {
    return std::sqrt(x * x + y * y);
}



void MyClass::GlobalUI::Bupdate()
{
    Events();
  
  //  bg.setSize(this->bgSize);
    this->bg.setFillColor(this->getBgColor());
    this->bg.setOutlineThickness(this->getStrokeThickness());
    this->bg.setOutlineColor(this->getStrokeColor());
}






void MyClass::GlobalUI::Events()
{

    sf::Mouse mouse;
    sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(mouse.getPosition().x - gui->game->getPosition().x), static_cast<float>(mouse.getPosition().y) - gui->game->getPosition().y);
    sf::FloatRect gb = bg.getGlobalBounds();

    if (gb.contains(mousePos))
    {
        isHover = true;
        hoverIsLeave = false;
        hover.HoverAction();
    }

    else if (isHover && !hoverIsLeave)
    {
        isHover = false;
        hoverIsLeave = true;
        hover.HoverLeaveAction();
    }

}

void MyClass::GlobalUI::initUI(Gui* gui)
{
    isClicked = true;
    this->gui = gui;
     isHover = false;
     hoverIsLeave = false;
    this->transparency = 0;
    this->bgColor = sf::Color::White;
    this->position = sf::Vector2f(0.f, 0.f);
    this->bgSize = sf::Vector2f(50.f, 50.f);
    this->name = "UI";
    strokeColor = sf::Color::Black;
    strokeThickness = 0;
    strokeTransparency = 0;
    

  


    gui->game->gameEvent.Event([this , gui](sf::Event eventType) {
        sf::Mouse mouse;
        sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(mouse.getPosition().x - gui->game->getPosition().x), static_cast<float>(mouse.getPosition().y) - gui->game->getPosition().y);
        sf::FloatRect gb = bg.getGlobalBounds();

        if (eventType.type == sf::Event::EventType::MouseButtonPressed)
        {
                if (gb.contains(mousePos) && isClicked)
                {
                    isClicked = false;
                    Button1.ClickAction();
                }
           
        }
        if (eventType.type == sf::Event::MouseButtonReleased)
        {
            if (gb.contains(mousePos) && !isClicked)
            {
                isClicked = true;
                Button1.PressedAction();
            }
        }
});

}




void HoverEvent::Hover(listener Listener)
{
    this->hoverListeners.push_back(Listener);
}

void HoverEvent::HoverLeave(listener Listener)
{
    this->hoverLeaveListeners.push_back(Listener);
}

void HoverEvent::HoverLeaveAction()
{
    for (const auto& func : this->hoverLeaveListeners)
    {
        func();
    }
}

void HoverEvent::HoverAction()
{
    for  (const auto &func : this->hoverListeners)
    {
        func();
    }
}

void Button1Event::Click(listener Listener)
{
    this->ClickLiseners.push_back(Listener);

}

void Button1Event::Pressed(listener Listener)
{
    this->PressedListeners.push_back(Listener);

}

void Button1Event::ClickAction()
{
    for (const auto& func : this->ClickLiseners)
    {
        func();
    }
}

void Button1Event::PressedAction()
{
    for (const auto& func : this->PressedListeners)
    {
        func();
    }
}


//GlobalObject



void MyClass::GlobalObject::setParent(MyClass::GlobalObject* parent)
{
    this->parent = parent;
}

void MyClass::GlobalObject::setName(const std::string newName)
{
    this->name = newName;
}

void MyClass::GlobalObject::setSize(const sf::Vector2f newBgSize)
{
    this->size = newBgSize;
 /*   rect.width = this->size.x;
    rect.height = this->size.y;*/
    sprite.setPosition(size);

}

void MyClass::GlobalObject::setPosition(const sf::Vector2f newPosition)
{
    this->position = newPosition;
    //rect.left = this->position.x;
    //rect.top = this->position.y;
    sprite.setPosition(position);

   
}

void MyClass::GlobalObject::setColor(const sf::Color newBgColor)
{
    this->color = newBgColor;
    sprite.setColor(this->color);
}

void MyClass::GlobalObject::setTransparency(int value)
{
    if (value < 0) value = 0;
    if (value > 255) value = 255;
    transparency = value;
    color = sf::Color(color.r, color.g, color.b, transparency);
}

void MyClass::GlobalObject::TextureRep(bool value)
{
    texture.setRepeated(value);
}

std::string MyClass::GlobalObject::getName() const
{
    return this->name;
}

sf::Vector2f MyClass::GlobalObject::getSize() const
{
    return this->size;
}

sf::Vector2f MyClass::GlobalObject::getPosition() const
{
    return this->position;
}

sf::Color MyClass::GlobalObject::getColor() const
{
    return this->color;
}

int MyClass::GlobalObject::getTransparency() const
{
    return this->transparency;
}

bool const MyClass::GlobalObject::LoadTexture(sf::String& path)
{
    sprite.setTexture(texture);
    return texture.loadFromFile(path);
}



void MyClass::GlobalObject::BUpdate() {
    Events();
}

void MyClass::GlobalObject::Events()
{
}

void MyClass::GlobalObject::initObject()
{
    this->name = "";
    this->position = sf::Vector2f(0.f, 0.f);
    this->size = sf::Vector2f(50.f, 25.f);
    canCollide = true;
    transparency = 0;
    color = sf::Color::White;
}



