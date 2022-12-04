#include <SFML/Graphics.hpp>
#include<ctime>

using namespace sf;
using namespace std;
const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800;
const string WINDOW_TITLE = "SFML Lesson 3";
const float FPS = 500;
float dx = rand() % 30 - 15;
float dy = rand() % 30 - 15;
int main()
{
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(FPS);

    //создание игровых объектов

    float sizew = 20.f;
    float sizeh = 80.f;
    float otstup = 50.f;
    srand(time(nullptr));
    RectangleShape r;
    r.setSize(Vector2f(sizew, sizeh));
    r.setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
    r.setPosition(otstup, WINDOW_HEIGHT / 2 - sizeh / 2);

    RectangleShape r1;
    r1.setSize(Vector2f(sizew, sizeh));
    r1.setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
    r1.setPosition(WINDOW_WIDTH - (7 * otstup) / 5, WINDOW_HEIGHT / 2 - sizeh / 2);

    CircleShape circl;
    float radius = 25.f;
    circl.setRadius(radius);
    circl.setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
    circl.setPosition(WINDOW_WIDTH / 2 - radius, WINDOW_HEIGHT / 2 - radius);

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }
        //об
        circl.move(dx, dy);
        if ((circl.getPosition().x + 2 * radius >= WINDOW_WIDTH) or (circl.getPosition().x <= 0)) {
            dx = -dx;
        }
        if ((circl.getPosition().y + 2 * radius >= WINDOW_HEIGHT) or (circl.getPosition().y <= 0)) {
            dy = -dy;
        }
        // Отрисовка окна 
        window.clear();
        window.draw(r);
        window.draw(r1);
        window.draw(circl);
        window.display();
    }
    return 0;
}