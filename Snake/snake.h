#ifndef SNAKE_H
#define SNAKE_H

//贪吃蛇的区域
#define SNAKE_WIDTH  64
#define SNAKE_HEIGHT 48
//图像的大小
#define SNAKE_SIZE 10

class Snake
{
public:
    Snake();

    int updateSnake();
    void setSnakeDirect(int dr);
    int getSnakeDirect();
    int getSnakeWorkspaceValue(int s_x, int s_y);
    int getSnakeWorkspaceSize(int *width, int *height);
    int getSnakeScore();

private:
    int snake_workspace[SNAKE_WIDTH+5][SNAKE_HEIGHT+5];
    int snake_direct;
    int snake_head_x;
    int snake_head_y;
    int snake_max;
    int snake_score;
    void generateFood();
    int snakeMove();

};

#endif // SNAKE_H
