#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 * @grid1: First sandpile.
 * @grid2: Second sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    // Add corresponding values of each cell
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Perform toppling operation until the pile is stable
    while (!is_stable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}

// Auxiliary function to check if the sandpile is stable
int is_stable(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return 0; // Not stable
        }
    }

    return 1; // Stable
}

// Auxiliary function to perform the toppling operation
void topple(int grid[3][3])
{
    int topple_grid[3][3] = {{0}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                topple_grid[i][j] -= 4; // Distribute 4 grains to neighbors
                if (i > 0)
                    topple_grid[i - 1][j]++;
                if (i < 2)
                    topple_grid[i + 1][j]++;
                if (j > 0)
                    topple_grid[i][j - 1]++;
                if (j < 2)
                    topple_grid[i][j + 1]++;
            }
        }
    }

    // Update the original grid with the results of toppling
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] += topple_grid[i][j];
        }
    }
}

// Function to print the grid
void print_grid(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
