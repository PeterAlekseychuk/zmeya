#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>

using namespace sf;
using namespace std;

#define WINDOW_HEIGHT 900
#define WINDOW_WIDTH 480
#define SPEED 1
#define CELL_SIZE 100.0f

/**
 * Структура квадратика в змее.
 * Сама змея - массив(скорее всего очередь) из квадратиков.
 */
struct SnakeCell {
    int x;
    int y;
    sf::RectangleShape shape;
    // 4 байта * 2 для интов
    // + хз сколько байт для sf::RectangleShape
};

void keyboard(vector<SnakeCell *> &snake) {
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        snake[0]->shape.move(SPEED, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        snake[0]->shape.move(-SPEED, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        snake[0]->shape.move(0, -SPEED);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        snake[0]->shape.move(0, SPEED);
    }
}



void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int main() {
    int a = 1;
    int b = 2;
    swap(&a,&b);
    cout << a << b;
    /**
     * TODO : узнать что такое структура данных
     * "ОЧЕРЕДЬ"
     */
    vector<SnakeCell *> snake;
    // Создается указатель на голову змеи.
    SnakeCell *head = new SnakeCell();
    //Следующие 2 строки одинаковые
    head->x = 5;
    (*head).x = 5;
    head->y = 5;
    head->shape.setFillColor(sf::Color::Green);
    head->shape.setPosition(WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2);
    head->shape.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));

    //добавили первую клетку(голову) в начало змеи
    snake.push_back(head);

    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "ZMEYKA!");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        keyboard(snake);

        window.clear();
        // пока рисуется только первая ячейка змеи.
        // оператор стрелка -> нужен для допуска к полям УКАЗАТЕЛЯ.
        // Когда в обычный объектах используется точка.
        window.draw(snake[0]->shape);
        window.display();

    }
    return 0;
}
