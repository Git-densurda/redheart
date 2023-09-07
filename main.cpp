#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>

int main()
{
    std::locale::global(std::locale("ru_RU.utf8"));
    sf::RenderWindow Window;
    Window.create(sf::VideoMode(800, 600), "Мой C++");

    Window.setKeyRepeatEnabled(false);
    Window.setFramerateLimit(24);
    sf::ConvexShape heart;
    heart.setPointCount(100);

    // Радиус сердца
    float radius = 10.0f;

    for (int i = 0; i < 100; i++)
    {
        float angle = i * 2 * M_PI / 100;
        float x = radius * 16 * pow(sin(angle), 3);
        float y = -radius * (13 * cos(angle) - 5 * cos(2 * angle) - 2 * cos(3 * angle) - cos(4 * angle));

        // Смещение сердца в центр окна
        x += 400;
        y += 300;

        heart.setPoint(i, sf::Vector2f(x, y));
    }

    heart.setFillColor(sf::Color::Red);

    // Объект текста
    sf::Font font;
    if (!font.loadFromFile("RAYDIS.ttf")) // Замените "RAYDIS.ttf" на путь к вашему файлу шрифта
    {
        std::cerr << "Не удалось загрузить" << std::endl;
        return 1;
    }

    std::string yourString = "Я люблю C++";
    sf::String sfmlString = sf::String::fromUtf8(yourString.begin(), yourString.end());

    sf::Text text(sfmlString, font, 24);
    text.setFillColor(sf::Color::White);

    float textX = 400; // Начальная позиция X текста
    float textY = 300; // Начальная позиция Y текста

    while (Window.isOpen())
    {
        sf::Event event;
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window.close();
        }

        // Очистка окна
        Window.clear();

        // Отрисовка сердца
        Window.draw(heart);

        // Отрисовка текста с движением
        text.setPosition(textX, textY);
        Window.draw(text);
        textX += 2; // Измените это значение по вашему усмотрению

        // Если текст выходит за пределы окна, верните его в начальную позицию
        if (textX > 800)
        {
            textX = -text.getLocalBounds().width;
        }

        // Отображение всего на экране
        Window.display();
    }

    return 0;
}
