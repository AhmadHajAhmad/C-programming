// (C) __Nawras Kanjo, Josef Abdurahim Almasri, Ahmad Haj Ahmad, group: 30 __ (2024)
// WP2
// Exercise 1
// Submission code: XXXXXX

// include section
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

enum DIRECTION // The enum of directiomm
{
    N, // North
    E, // East
    S, // South
    W // West
};
typedef struct
{
    int xpos; // The x position of the robot
    int ypos; // The y position of the robot
    enum DIRECTION dir; // The direction of the robot
} ROBOT;

void move(ROBOT *robot) // The move function of the robot, passing pointer to a the robot
{
    // source https://www.geeksforgeeks.org/arrow-operator-in-c-c-with-examples/
    if (robot->dir == E)  // if the direction of the robot is east
    {
        robot->xpos++; // Increment the x position by 1
        if (robot->xpos > 99) // Check if the x position is greater than 99
        {
            robot->xpos = 99; // Keep the x position of the robot to 99
            printf("Can't move further. coordinates are: X= %d, Y= %d\n", robot->xpos, robot->ypos);
            return 0;
        }
    }
    else if (robot->dir == N) // if the direction of the robot is to North
    {
        robot->ypos++; // Increment the y position by 1
        if (robot->ypos > 99) // Check if the y position is greater than 99
        {
            robot->ypos = 99; // Keep the y position of the robot to 99
            printf("Can't move further. coordinates are: X= %d, Y= %d\n", robot->xpos, robot->ypos);
            return 0; // return
        }
    }
    else if (robot->dir == W) // if the direction of the robot is to West
    {
        robot->xpos--; // Decrement the x position by 1
        if (robot->xpos < -99) // Check if the x position is less than -99
        {
            robot->xpos = -99; // Keep the x position of the robot to -99
            printf("Can't move further.coordinates are: X= %d, Y= %d\n", robot->xpos, robot->ypos);
            return 0; // return
        }
    }
    else if (robot->dir == S) // if the direction of the robot is to South
    {
        robot->ypos--; // // Decrement the y position by 1
        if (robot->ypos < -99) // Check if the y position is less than -99
        {
            robot->xpos = -99; // Keep the x position of the robot to -99
            printf("Can't move further. coordinates are: X= %d, Y= %d\n", robot->xpos, robot->ypos);
            return 0; // return
        }
    }
}

void turn(ROBOT *robot) // The turn function of the robot, passing pointer to a the robot
{
    if (robot->dir == E) // If the position of the robot is East
    {
        robot->dir = S; // Change the position to South
    }
    else if (robot->dir == N) // If the position of the robot is North
    {
        robot->dir = E; // Change the position to East
    }
    else if (robot->dir == W) // If the position of the robot is West
    {
        robot->dir = N; // Change the position to North
    }
    else if (robot->dir == S) // If the position of the robot is South
    {
        robot->dir = W; // Change the position to West
    }
}

// main method aka the program
int main()
{
    ROBOT robot = {0, 0, N}; // Assign the intitial position and direction
    char direction[] = {'N', // Array of characters of directions
                        'E',
                        'S',
                        'W'};

    while (1)
    {
        char instruction[99]; // The characters array that the user will enter 'm' or 't'

        printf("\nEnter starting xpos: ");
        scanf("%d", &robot.xpos); // Assign the x position of the robot
        printf("\nEnter starting ypos: ");
        scanf("%d", &robot.ypos); // Assign the y position to the robot
        robot.dir = N; // Assign the robot the direction North

        printf("\nEnter instructions: ");
        scanf("%32s", instruction); // Take the instructions of the robot from the user

        for (size_t i = 0; i < strlen(instruction); i++)  // For loop that iterate over the instructions
        {
            if (instruction[i] == 'z') // When user enter the character 'z' the robot will stop moving
            {
                return 0; // return 0 to stop the program
            }
            else if (instruction[i] == 'm') // If the input is 'm'
            {
                move(&robot); // Call the function more and pass the address of the robot
            }
            else if (instruction[i] == 't') // If the input is 't'
            {
                turn(&robot); // Call the function turn and pass the address of the robot
            }
        }
        printf("Robot coordinates are: X= %d, Y= %d\n", robot.xpos, robot.ypos);
    }
    return 0;
}
