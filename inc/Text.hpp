#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

namespace sz
{
    class MyText
    {
        std::string m_text;
        float m_ShowTime;
        sf::RenderWindow& m_window;
        sf::Font m_font;
        sf::SoundBuffer m_buffer;
        sf::Sound m_sound;
        sf::Color getRandomColor() const
        {
            return sf::Color(rand() % 256, rand() % 256, rand() % 256);
        }

    public:
        MyText(sf::RenderWindow& window, const std::string& text, float ShowTime)
            : m_window(window), m_text(text), m_ShowTime(ShowTime)
        {
            if (!m_font.loadFromFile("assets\\arial.ttf"))
            {
                std::cout << "Error while loading arial.ttf" << std::endl;
            }

            if (!m_buffer.loadFromFile("assets\\sound.wav"))
            {
                std::cout << "Error while loading sound.wav" << std::endl;
            }
            m_sound.setBuffer(m_buffer);
        }

        void verbAnimationText()
        {
            sf::Text text;
            text.setFont(m_font);
            text.setCharacterSize(30);
            text.setStyle(sf::Text::Bold);

            sf::Clock clock;

            float charShowTime = m_ShowTime / static_cast<float>(m_text.size()-1);

            sf::Color currentColor = getRandomColor();
            m_window.clear(currentColor);

            for (int i = 0; i < m_text.size(); ++i)
            {
                if (m_text[i] != ' ' && !ispunct(m_text[i]))
                {
                    currentColor = getRandomColor();
                }

                text.setString(m_text.substr(0, i+1));

                m_window.clear(currentColor);
                m_window.draw(text);
                m_window.display();

                if (m_text[i + 1] == '\0')
                    break;

                sf::sleep(sf::seconds(charShowTime));
            }

            m_sound.play();

            sf::sleep(sf::seconds(2));
        }
    };
}

