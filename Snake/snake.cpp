#include <iostream>
#include <time.h>
#include "snake.h"

Snake::Snake()
{
    int i,j;

    //初始化贪吃蛇画板
    //边框值：-2；其余值都为0
    //蛇头的值为1； 蛇身都是>0;
    //食物的值为-1；
    for (i=0; i<SNAKE_WIDTH+5;++i){
        for (j=0; j<SNAKE_HEIGHT+5; ++j){
            if (i==0 || j==0 || i==SNAKE_WIDTH || j==SNAKE_HEIGHT)
                snake_workspace[i][j] = -2;
            else
                snake_workspace[i][j] = 0;
        }
    }

    //设置蛇头初始值在图形中间
    snake_head_x = SNAKE_WIDTH/2;
    snake_head_y = SNAKE_HEIGHT/2;
    snake_workspace[snake_head_x][snake_head_y] = 1;
    snake_max = 1;//蛇的长度
    //从蛇头开始，每增加一节身体，蛇身值+1
    //|1|2|3|4|5|6|7|
    //1为蛇头

    //随机生成食物位置
    generateFood();

    //设置蛇头运动的方向，默认向上
    //1: 向上；    //2: 向下；    //3: 向左；    //4: 向右
    snake_direct = 1;

    // 得分默认为0
    snake_score = 0;
}

void Snake::generateFood()
{
    //随机设置食物的位置
    //食物位置的值应设置为-1
    int food_x;
    int food_y;
    srand((unsigned int)time(nullptr));
    food_x = (rand()%(SNAKE_WIDTH-5))+3;
    food_y = (rand()%(SNAKE_HEIGHT-5))+3;
    snake_workspace[food_x][food_y] = -1;
}

int Snake::snakeMove()
{
    int new_head_x;
    int new_head_y;

    bool eat_food = false;
    int snake_dr = snake_direct;
    switch (snake_dr){
        case 1: //向上
            new_head_x = snake_head_x;
            new_head_y = snake_head_y-1;
            break;
        case 2: //向下
            new_head_x = snake_head_x;
            new_head_y = snake_head_y+1;
            break;
        case 3: //向左
            new_head_x = snake_head_x-1;
            new_head_y = snake_head_y;
            break;
        case 4: //向右
            new_head_x = snake_head_x+1;
            new_head_y = snake_head_y;
            break;

    }

    // 碰到边界了或者碰到蛇的身体
    if (snake_workspace[new_head_x][new_head_y] == -2 || snake_workspace[new_head_x][new_head_y]>0){
        return -2;
    }

    // 吃到食物了
    if (snake_workspace[new_head_x][new_head_y] == -1){
        eat_food = true;
        snake_max++;
    }

    // 刷新蛇的身体
    // 这个方法有点笨，应该用vector保持蛇身体的坐标，可以直接把蛇身都设置成值
    int i,j;
    for (i=0; i<SNAKE_WIDTH; ++i)
        for (j=0; j<SNAKE_HEIGHT; ++j){
            if (snake_workspace[i][j]>0){

                // 新的蛇头默认设置为1，其他蛇身依次加上1，仍然按照顺序排列
                snake_workspace[i][j]++;

                //如果没有吃到食物，蛇移动后，需要将蛇尾清零，因为蛇往前走了一步
                if (snake_workspace[i][j] > snake_max){
                    snake_workspace[i][j] = 0;
                }                
            }
        }
    //设置新的蛇头
    snake_head_x = new_head_x;
    snake_head_y = new_head_y;
    snake_workspace[snake_head_x][snake_head_y] = 1;

    // 吃了食物，重新生成
    if (eat_food){
        generateFood();
        snake_score=snake_score+10;//得分加10分
    }
    return 0 ;
}

void Snake::setSnakeDirect(int dr)
{
    //设置蛇头运动的方向
    //1: 向上；   2: 向下；  3: 向左   4: 向右
    //如果不在范围内，则不更改蛇的运动方向
    //运动方向不能掉头
    int org_dr = snake_direct;
    if ((dr==1&&org_dr!=2) || (org_dr!=1&&dr==2) || (dr==3&&org_dr!=4) || (org_dr!=3&&dr==4)){
        snake_direct = dr;
    }
}

int Snake::getSnakeWorkspaceSize(int *width, int *height)
{
    if (width == NULL || height == NULL)
        return -1;

    *width = SNAKE_WIDTH;
    *height = SNAKE_HEIGHT;
    return 0;
}

int Snake::updateSnake()
{
    return snakeMove();
}

int Snake::getSnakeDirect()
{
    return snake_direct;
}

int Snake::getSnakeWorkspaceValue(int s_x, int s_y)
{
    return snake_workspace[s_x][s_y];
}

int Snake::getSnakeScore()
{
    return snake_score;
}
