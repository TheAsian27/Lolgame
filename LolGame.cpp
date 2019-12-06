#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>

typedef std::chrono::steady_clock gameclock;

long currTimeAsLong() {
	return std::chrono::time_point_cast<std::chrono::milliseconds>(gameclock::now()).time_since_epoch().count();
}

int main()
{
	//Setup
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Aaron is a furry!");

	long nextTick = currTimeAsLong();

	while (window.isOpen())
	{
		while (nextTick < currTimeAsLong()) {
			/* event handling */
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					goto end;
					break;
				}
			}

			/* Computation */

			nextTick += 31;
			std::cout << currTimeAsLong() << std::endl;
		}

		/* Rendering */
		window.clear(sf::Color::Blue);
		
		window.display();
	}
	end:
	return 0;
}
