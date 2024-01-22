#include "sandpiles.h"
#include <stdio.h>

/**
 * sandpiles_sum - Calcule la somme de deux tas de sable.
 * @grid1: Premier tas de sable.
 * @grid2: Deuxième tas de sable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    // Ajoute les valeurs correspondantes de chaque cellule
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Effectue l'opération de basculement jusqu'à ce que le tas soit stable
    while (!is_stable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}

// Fonction auxiliaire pour vérifier si le tas de sable est stable
int is_stable(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return 0; // Non stable
        }
    }

    return 1; // Stable
}

// Fonction auxiliaire pour effectuer l'opération de basculement
void topple(int grid[3][3])
{
    int topple_grid[3][3] = {{0}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                topple_grid[i][j] -= 4; // Distribue 4 grains aux voisins
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

    // Met à jour la grille d'origine avec les résultats du basculement
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] += topple_grid[i][j];
        }
    }
}

// Fonction pour afficher la grille
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
