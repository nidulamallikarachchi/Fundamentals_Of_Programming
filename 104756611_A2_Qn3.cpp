#include <iostream>
#include <cstdlib>
#include <ctime>
#include "splashkit.h"

const int SIZE = 800;

// Define the struct for bar properties
struct bar_properties
{
    int bar_height;
    color bar_color;
};

//Function Prototypes 
color get_random_color();
void fill_array(bar_properties array_rectangles[]);
void draw_bar(bar_properties array_rectangles[]);
void bubble_sort(bar_properties array_rectangles[]);
void selection_sort(bar_properties array_rectangles[]);

int main()
{
    open_window("Array rectangles", 800, 700);
    srand(static_cast<unsigned>(time(nullptr)));
    bar_properties array_rectangles[SIZE];
 

    fill_array(array_rectangles);      // Fill array with random numbers 

    while (!quit_requested())
    {
        process_events();
        clear_screen(COLOR_WHITE);

        draw_line(COLOR_RED, 0,95,800,95);

        fill_rectangle(COLOR_GREEN,10,10,100,30); 
        draw_text("Non-Sorted", COLOR_WHITE, "arial.ttf", 15, 20, 20);

        fill_rectangle(COLOR_GREEN,120,10,100,30); 
        draw_text("Bubble Sort", COLOR_WHITE, "arial.ttf", 15, 130, 20);

        fill_rectangle(COLOR_GREEN,230,10,100,30); 
        draw_text("Selection Sort", COLOR_WHITE, "arial.ttf", 15, 240, 20);
        
        draw_bar(array_rectangles);

        // Buttons

        if (mouse_clicked(LEFT_BUTTON)) 
            { 
                if ((mouse_x() >= 10) && (mouse_x() <= 110) && 
                    (mouse_y() >= 10) && (mouse_y() <= 40)) 
                {
                    clear_screen(COLOR_WHITE); 
                    fill_array(array_rectangles); 
                    draw_bar(array_rectangles);
                }
                if ((mouse_x() >= 120) && (mouse_x() <= 220) && 
                    (mouse_y() >= 10) && (mouse_y() <= 40)) 
                {
                    clear_screen(COLOR_WHITE); 
                    bubble_sort(array_rectangles);
                }
                if ((mouse_x() >= 230) && (mouse_x() <= 430) && 
                    (mouse_y() >= 10) && (mouse_y() <= 40)) 
                {
                    clear_screen(COLOR_WHITE); 
                    selection_sort(array_rectangles);
                }
            }

        refresh_screen(60);
    }
    return 0;
}

// Function to get a random color
color get_random_color()
{
    // Generate a random hue bar_height between 0 and 1
    float hue = static_cast<float>(rand() % 360) / 360.0;

    // The When the hue is divided by the Screen Height, The desired output will not come. Hence divided by 360
    color bar_color = hsb_color(hue, 0.7, 0.8);
    return bar_color;
}

//Fill Array with random Numbers
void fill_array(bar_properties array_rectangles[])
{
    for (int i = 0; i < SIZE; ++i)
    {
        array_rectangles[i].bar_height = rand() % (screen_height() - 100);

        array_rectangles[i].bar_color = get_random_color();
    }
}

// Draw bars
void draw_bar(bar_properties array_rectangles[])
{
    float rectangle_width = 1;
    for (int i = 0; i < SIZE; ++i)
    {
        float x = rectangle_width * i;
        float y = screen_height() - array_rectangles[i].bar_height;

        //Drawing random hue rectangels with the help of struct variable
        fill_rectangle(array_rectangles[i].bar_color, x, y, rectangle_width, array_rectangles[i].bar_height);
    }
}

// Bubble Sort 
void bubble_sort(bar_properties array_rectangles[])
{
    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = 0; j < SIZE - i - 1; ++j)
        {
            if (array_rectangles[j].bar_height > array_rectangles[j + 1].bar_height)
            {
                bar_properties temp = array_rectangles[j];
                array_rectangles[j] = array_rectangles[j + 1];
                array_rectangles[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(bar_properties array_rectangles[])
{
    for (int i = 0; i < SIZE - 1; ++i)
    {
        int minimum_index = i;
        for (int j = i + 1; j < SIZE; ++j)
        {
            if (array_rectangles[j].bar_height < array_rectangles[minimum_index].bar_height)
            {
                minimum_index = j;
            }
        }
        bar_properties temp = array_rectangles[i];
        array_rectangles[i] = array_rectangles[minimum_index];
        array_rectangles[minimum_index] = temp;
    }
}

