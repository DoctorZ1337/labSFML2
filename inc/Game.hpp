#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Text.hpp"

namespace sz
{
	class Game
	{
		int m_width;
		int m_height;
		std::string m_capture;
		int m_n;
		sf::RenderWindow m_window;
		sf::Font m_font;

	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		bool Setup(int n)
		{
			m_n = n;
			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			if (!m_font.loadFromFile("assets\\arial.ttf"))
			{
				std::cout << "Error while loading arial.ttf" << std::endl;
				return false;
			}
			return true;
		}

		void LifeCycle()
		{
			sf::Clock clock;

			MyText myText(m_window, "Hello 1, 2!", 30);

			while (m_window.isOpen())
			{
				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				myText.verbAnimationText();
				m_window.display();
				m_window.close();
			}
		}
	};
}
