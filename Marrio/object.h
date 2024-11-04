#include  "MyClass.hpp"
#include <string>
#include <ostream>
#ifndef _OBJECT_
#define _OBJECT_
class object: public MyClass::GlobalObject 
{

public:
	object(std::string name,MyClass::GlobalObject *parent , int uniqueId);
	void update();
	void  render(sf::RenderTarget *target) ;

};
#endif // !_OBJECT_



