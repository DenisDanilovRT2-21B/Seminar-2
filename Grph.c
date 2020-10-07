#include <stdio.h>
#include <stdlib.h>
#define max 10
int sizeg;
int matrix[max][max];
int val;
int edge;
int swing;
void create(void) {
    int begin;
    int end;
    val = 0;
    swing = 0;
    edge = 0;
    printf("Enter the number of nodes: ");
    scanf("%d",&sizeg);
    for (int i = 1; i <= max; i++) {
        printf("Enter the %d edge (if you want to exit type 0 0) : ", i);
        scanf("%d %d", &begin, &end);
        if ((begin == 0) && (end == 0)) {
            break;
        }
        else if ((begin == end) && (begin <= sizeg)) {
            printf("Add swing\n");
            matrix[begin][end] = matrix[begin][end] + 1;
            val++;
            swing++;
        }
        else if (begin > sizeg || end > sizeg || begin <= 0 || end <= 0) {
            printf("Error.Try again\n");
            i--;
        }
        else {
            if (((matrix[begin][end] >= 1) && (matrix[end][begin] >= 1)) && (begin != end)) {
                printf("Add edge\n");
                matrix[begin][end] = matrix[begin][end] + 1;
                matrix[end][begin] = matrix[end][begin] + 1;
                edge++;
                val++;
            }
            else {
            matrix[begin][end] = 1;
            matrix[end][begin] = 1;
            val = 1;
            edge = 1;
            }
        }
    }
}

void check(void) {
    if (val >= ((sizeg - 1)*(sizeg - 2))/2) {
        printf("The graph is connected\n");
    }
    else {
        printf("The graph is not connected\n");
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
 /*   FILE *step;
    step = fopen("Test.txt","w+");
    fprintf(step,"graph G { \n");
    for(int i = 1; i <= sizeg; i++) {
        for(int j = 1;j <= sizeg; j++) {
            swing = matrix[i][j];
            val = matrix[i][j];
            if(i == j) {
                if(i == 0) {
                    printf("\n");
                }
                else {
                    for(int k;k <= swing;k++) {
                        fprintf("%d -- %d",i,j);
                    } 
                } 
            }
            else {
                if((i!=0) && (j!=0)) {
                    for(int b;b <= val;b++) {
                        fprintf("%d -- %d",i,j);
                    }
                } 
                else {
                printf("\n");
                } 
            } 
        } 
    } 
    fprintf(step,"}\n") ;
    fclose(step); */
   // system("dot -Tpng Test.dot -o Test_dot.png");
    setlocale(0,""); 
    create();
    show();
    check();
    return 0;
}