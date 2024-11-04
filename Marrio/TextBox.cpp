#include "TextBox.h"
#include "Gui.h"
#include "Game.h"

//TextBox::TextBox(std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName)
//	:TextLable(name, _text, size, _bgSize, fontName)
//{
//	key = sf::Keyboard::Enter;
//	sf::Cursor cursor;
//	cursor.loadFromSystem(sf::Cursor::Text);
//}

void TextBox::initEvents()
{
	clicked = false;
	this->Button1.Pressed([this]() {
		clicked = true;
	});

	if (gui != nullptr)
	{
		this->gui->game->gameEvent.Event([this](sf::Event ev) {
			if (clicked) {
				if (ev.type == sf::Event::KeyPressed)
				{
					if (ev.key.code == sf::Keyboard::LShift || ev.key.code == sf::Keyboard::RShift)
						this->shift = true;

					if (ev.key.code == sf::Keyboard::Enter && shift)
					{
						std::cout << this->shift;
						this->setText(this->getText() + "\n");
					}

					if (ev.key.code == sf::Keyboard::Enter && !shift)
					{
						clicked = false;
	
					}

					if (ev.key.code == sf::Keyboard::BackSpace && !this->getText().empty())
					{
						std::string te = this->getText();
						te.pop_back();
						this->setText(te);
					}
				}
				if (ev.type == sf::Event::KeyReleased)
					if (ev.key.code == sf::Keyboard::LShift || ev.key.code == sf::Keyboard::RShift)
						shift = false;

				if (ev.type == sf::Event::TextEntered)
				{

					if (ev.text.unicode < 128 && ev.text.unicode != 8 && ev.text.unicode != 13 && !shift)
					{
						std::cout << this->getText() + static_cast<char>(ev.text.unicode);
						this->setText(this->getText() + static_cast<char>(ev.text.unicode));
					}
				}
			}
			});
	}
}

TextBox::TextBox(Gui* gui, std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName)
	:TextLable(gui,name, _text, size, _bgSize, fontName)
{
	initEvents();
}
