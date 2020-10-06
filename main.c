#include <stdio.h>
#include <stdlib.h>
#define max 10
int sizeg;
int matrix[max][max];
int val;
void create(void) {
    int begin;
    int end;
    val = 0;
    printf("Insert number of nodes: ");
    scanf("%d",&sizeg);
    for (int i = 1; i <= max; i++) {
        printf("Insert the nodes of %d edge(For the exit insert nulls) : ", i);
        scanf("%d %d", &begin, &end);
        if ((begin == 0) && (end == 0)) {
            break;
        }
        else if ((begin == end) && (begin <= sizeg)) {
            printf("Adding loop\n");
            matrix[begin][end] = matrix[begin][end] + 1;
            val++;
        }
        else if (begin > sizeg || end > sizeg || begin <= 0 || end <= 0) {
            printf("Error.Try again.\n");
            i--;
        }
        else {
            if (((matrix[begin][end] >= 1) && (matrix[end][begin] >= 1)) && (begin != end)) {
                printf("Adding multiple edges\n");
                matrix[begin][end] = matrix[begin][end] + 1;
                matrix[end][begin] = matrix[end][begin] + 1;
                val++;
            }
            else {
            matrix[begin][end] = 1;
            matrix[end][begin] = 1;
            val = 1;
            }
        }
    }
}

void check(void) {
    if (val >= ((sizeg - 1)*(sizeg - 2))/2) {
        printf("Graph is connected\n");
    }
    else {
        printf("Graph is not connected\n");
    }
}

void show(void) {
    int i, j;
    for (i = 1; i <= sizeg; i++) {
        for (j = 1; j <= sizeg; j++)
            printf("%4d",matrix[i][j]);
        printf("\n");
    }

}
int main(void) {
    create();
    show();
    check();
    return 0;
}

