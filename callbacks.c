//Peter Eberhard

//system libraries rarely have bugs, do them first
#include <stdbool.h>
#include <stdio.h>  

//custom libraries
#include "bko.h"

//header files next
#include "structs.h"
#include "debug.h"

//my own header file last
#include "callbacks.h"

bool ball_comparison(void* pointer_1, void* pointer_2)
{       
        //assign pointers to correct type
        struct Ball* ball_1_pointer = pointer_1;
        struct Ball* ball_2_pointer = pointer_2;

        //compare
        if(ball_1_pointer->y_position > ball_2_pointer->y_position) return true;
        return false;
}

// action function that prints a single ball
void print_a_ball(void* pointer1)
{
    struct Ball* ball_pointer = pointer1;
    printf("Ball %d is at (%8.5lf, %8.5lf) with velocity (%8.5lf, %8.5lf).\n", (int) ball_pointer->color, ball_pointer->x_position, ball_pointer->y_position, ball_pointer->x_velocity, ball_pointer->y_velocity);
    if(DEBUG)printf("DEBUG: Ball %d has pointer %p\n", ball_pointer->color, (void*)ball_pointer);

}

// action function that prints a single block
void print_a_block(void* pointer1)
{
    struct Block* block_pointer = pointer1;
    printf("Block %d is at (%8.5lf, %8.5lf).\n", (int) block_pointer->color, block_pointer->x_position, block_pointer->y_position);
    if(DEBUG)printf("DEBUG: Block %d has pointer %p\n", block_pointer->color, (void*)block_pointer);

}

// draws a single ball
void draw_a_ball(void* pointer1)
{
    struct Ball* ball_pointer = pointer1;
    bko_ball((int) ball_pointer->color, ball_pointer->x_position, ball_pointer->y_position);
}

//draws a single block
void draw_a_block(void* pointer1)
{
    struct Block* block_pointer = pointer1;
    
    bko_block((int) block_pointer->color, block_pointer->x_position, block_pointer->y_position);

}