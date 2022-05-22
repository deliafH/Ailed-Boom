#include <SFML/Graphics.hpp>
#include"Sources/Application.h"
#include<list>
#include<stack>
using namespace sf;

int main()
{
	srand(time(NULL));

	Application application;
	application.Run();
}
