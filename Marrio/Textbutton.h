//#ifndef _TEXTBUTTON_
//#define _TEXTBUTTON_
//#include "TextLable.h"
//#include <functional>
//#include <vector>
//
//class ButtonClick1
//{
//public:
//	using listner = std::function<void(sf::Vector2f)>;
//	using Unlistner = std::function<void(sf::Vector2f)>;
//
//	void Perssed(listner func);
//	void UnPerssed(listner func);
//
//	void Luncher(sf::Vector2f pos);
//	void UnLuncher(sf::Vector2f pos);
//
//private:
//	std::vector<listner> list;
//	std::vector<Unlistner> Unlist;
//
//};
//class ButtonClick2
//{
//public:
//	using listner = std::function<void(sf::Vector2f)>;
//	using Unlistner = std::function<void(sf::Vector2f)>;
//
//	void Perssed(listner func);
//	void UnPerssed(listner func);
//
//	void Luncher(sf::Vector2f pos);
//	void UnLuncher(sf::Vector2f pos);
//
//private:
//	std::vector<listner> list;
//	std::vector<Unlistner> Unlist;
//
//};
//
//
//class Textbutton :public TextLable
//{
//private:
//	sf::Keyboard::Key key;
//	bool shift;
//	void initEvents();
//public:
//	//events
//	ButtonClick1 MouseButton1;
//	ButtonClick2 MouseButton2;
//
//	Textbutton(Gui* gui, std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName);
//};
//#endif // !_TEXTBOX_
//
//
