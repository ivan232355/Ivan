/*
 ============================================================================
 Name        : SNAKE.c
 Author      : 
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    head->controls = default_controls;
}

/*
 Движение головы с учетом текущего направления движения
 */
void go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // macro - размер терминала
    mvprintw(head->y, head->x, " "); // очищаем один символ
    switch (head->direction)
    {
        case LEFT:
            if(head->x <= 0) // Циклическое движение, чтобы не
// уходить за пределы экрана
                head->x = max_x;
            mvprintw(head->y, --(head->x), "%c", ch);
        break;
        case RIGHT:
            mvprintw(head->y, ++(head->x), "%c", ch);
        break;
        case UP:
            mvprintw(--(head->y), head->x, "%c", ch);
        break;
        case DOWN:
            mvprintw(++(head->y), head->x, "%c", ch);
        break;
        default:
        break;
    }
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down)
        snake->direction = DOWN;
    else if (key == snake->controls.up)
        snake->direction = UP;
    else if (key == snake->controls.right)
        snake->direction = RIGHT;
    else if (key == snake->controls.left)
        snake->direction = LEFT;
}

int checkDirection(snake_t* snake, int32_t key)
{
    if (snake->direction == LEFT && key == snake->controls.right)
        return 0;
    if (snake->direction == RIGHT && key == snake->controls.left)
        return 0;
    if (snake->direction == UP && key == snake->controls.down)
        return 0;
    if (snake->direction == DOWN && key == snake->controls.up)
        return 0;
    return 1;
}
/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

/*Функция проверяет, не врезалась ли змея сама в себя.
 * Она проходит по всему хвосту змеи и сравнивает координаты головы со всеми элементами хвоста*/
uint8_t isSnakeHitItself(snake_t *head)
{
    for (size_t i = 1; i < head->tsize; i++)
    {
        if (head->tail[i].x == head->x && head->tail[i].y == head->y)
            return true;
    }
    return false;
}
int main()
{
	 snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
	    initSnake(snake,START_TAIL_SIZE,10,10);
	    initscr();
	    keypad(stdscr, TRUE);
	    raw();
	    noecho();
	    curs_set(FALSE);
	    mvprintw(0, 2,"Use arrows for control. Press 'F10' for EXIT");
	    timeout(0);
	    int key_pressed=0;
	    uint8_t game_over = 0;
	    while( key_pressed != STOP_GAME )
	    {
	        key_pressed = getch();
	        if (checkDirection(snake, key_pressed))
	        {
	        	changeDirection(snake, key_pressed);
	            go(snake);
	            goTail(snake);
	        }
	        timeout(100);
	        //changeDirection(snake, key_pressed);
	        if (isSnakeHitItself(snake))
	        {
	            game_over = 1;
	            mvprintw(snake->y, snake->x, "Game Over!");
	            refresh();
	            while((key_pressed = getch()) != '\n' && key_pressed != '\r')
	            {
	                // Ждем когда пользователь нажмет ENTER
	            }
	            key_pressed = STOP_GAME;
	        }
	    }
	    free(snake->tail);
	    free(snake);
	    endwin();
	    return 0;
}
