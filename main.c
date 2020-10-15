#include <stdio.h>
#include <stdlib.h>
#define max 20
int sizeg;
int matrix[max][max];
int conn[max][max];
int val;
int swing;
void create(void) {
    int begin;
    int end;
    val = 0;
    swing = 0;
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
            conn[begin][end] = matrix[begin][end];
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
                conn[begin][end] = matrix[begin][end];
                conn[end][begin] = 0;
            }
            else {
            matrix[begin][end] = 1;
            matrix[end][begin] = 1;
            conn[begin][end] = 1;
            val++;
            }
        }
    }
}

void check(void) {
    int key;
    key = 0;
    for(int i = 1; i <= sizeg; i++) {
        for(int j = 1;j <= sizeg; j++) {
            if ((swing != 0) || (conn[i][j] > 1)) {
            key++;
            }
        }
    }
            if (key == 0) {
                if (val >= (sizeg - 1)) {  //  ? (sizeg - 1)*(sizeg - 2)/2
                    printf("The graph is connected");

                }
                else {
                    printf("The graph is not connected\n");
                }
            }
            else {
                printf("The graph is not connected\n");
            }
}
void show(void) {
    int i, j;
    for (i = 1; i <= sizeg; i++) {
        for (j = 1; j <= sizeg; j++) {
            printf("%4d",matrix[i][j]);
        }
        printf("\n");
    }

}
int main(void) {
    create();
    show();
    check();
    FILE *step;
    step = fopen("Test.dot","w+");
    fprintf(step,"graph G { \n");
    for(int a = 1; a <= sizeg;a++) {
        fprintf(step,"%d;\n",a);
    }
    for(int i = 1; i <= sizeg; i++) {
        for(int j = 1;j <= sizeg; j++) {
            if(i != j) {
                if(conn[i][j] == 0) {
                    fprintf(step,"\n");
                }
                else {
                    for(int k = 1;k <= conn[i][j];k++) {
                        fprintf(step,"%d -- %d;\n",i,j);
                    }
                }
            }
            else {
                if(conn[i][j]!=0) {
                    for(int b = 1;b <= conn[i][j];b++) {
                        fprintf(step,"%d -- %d;\n",i,j);
                    }
                }
                else {
                printf("\n");
                }
            }
        }
    }
    fprintf(step,"}\n") ;
    fclose(step);
    //"cd <Path to the location of file>"
   // "dot -Tpng <Name of dot file> -o <Name of png file that you're creating>"
    return 0;
}
