#include "slide_line.h"

/**
 * merge_left - Merge the elements to the left
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void merge_left(int *line, size_t size)
{
    size_t i, j;

    for (i = 0; i < size - 1; i++)
    {
        if (line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    for (i = 0, j = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[j++] = line[i];
        }
    }

    for (; j < size; j++)
    {
        line[j] = 0;
    }
}

/**
 * merge_right - Merge the elements to the right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
static void merge_right(int *line, size_t size)
{
    size_t i, j;

    for (i = size - 1; i > 0; i--)
    {
        if (line[i] == line[i - 1])
        {
            line[i] *= 2;
            line[i - 1] = 0;
        }
    }

    for (i = size - 1, j = size - 1; i < size; i--)
    {
        if (line[i] != 0)
        {
            line[j--] = line[i];
        }
    }

    for (; j < size; j--)
    {
        line[j] = 0;
    }
}

/**
 * slide_line - Slide and merge the array of integers to the left or right
 *
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    if (direction == SLIDE_LEFT)
        merge_left(line, size);
    else if (direction == SLIDE_RIGHT)
        merge_right(line, size);

    return 1;
}
