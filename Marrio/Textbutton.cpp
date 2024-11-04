//#include "Textbutton.h"
//#include "Gui.h"
//#include "Game.h"
//void Textbutton::initEvents()
//{
//	this->gui->game->gameEvent.Event([this](sf::Event ev) {
//		if (ev.type == sf::Event::MouseButtonPressed)
//		{
//			if (this->bg.getLocalBounds().contains(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y)))
//			{
//				std::cout << "wrkenfkrwbngorewbng";
//			}
//			if(ev.mouseButton.button == sf::Mouse::Left)
//				MouseButton1.Luncher(sf::Vector2f(ev.mouseButton.x , ev.mouseButton.y));
//			
//			if (ev.mouseButton.button == sf::Mouse::Right)
//				MouseButton2.Luncher(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
//			
//		}
//		if (ev.type == sf::Event::MouseButtonReleased)
//		{
//			if (ev.mouseButton.button == sf::Mouse::Left) {
//				MouseButton1.UnLuncher(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
//			}
//			if (ev.mouseButton.button == sf::Mouse::Right) {
//				MouseButton2.UnLuncher(sf::Vector2f(ev.mouseButton.x, ev.mouseButton.y));
//			}
//		}
//	});
//}
//
//Textbutton::Textbutton(Gui* gui, std::string name, std::string _text, int size, sf::Vector2f _bgSize, std::string fontName)
//	:TextLable(gui, name, _text, size, _bgSize, fontName)
//{
//	initEvents();
//}
//
//
//
//void ButtonClick1::Perssed(listner func)
//{
//	this->list.push_back(func);
//}
//
//void ButtonClick1::UnPerssed(listner func)
//{
//	this->Unlist.push_back(func);
//}
//
//void ButtonClick1::Luncher(sf::Vector2f pos)
//{
//	for (auto &func : list )
//	{
//		func(pos);
//	}
//}
//
//void ButtonClick1::UnLuncher(sf::Vector2f pos)
//{
//	for (auto& func : Unlist)
//	{
//		func(pos);
//	}
//}
//
//
//void ButtonClick2::Perssed(listner func)
//{
//	this->list.push_back(func);
//}
//
//void ButtonClick2::UnPerssed(listner func)
//{
//	this->Unlist.push_back(func);
//
//}
//
//void ButtonClick2::UnLuncher(sf::Vector2f pos)
//{
//	for (auto& func : Unlist)
//	{
//		func(pos);
//	}
//}
//void ButtonClick2::Luncher(sf::Vector2f pos)
//{
//	for (auto& func : list)
//	{
//		func(pos);
//	}
//}
//
//
//
