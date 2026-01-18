#include <stdio.h>
void towerOfHanoi(int n, char from, char to, char aux, FILE *fp){
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        fprintf(fp, "Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to, fp);
    printf("Move disk %d from %c to %c\n", n, from, to);
    fprintf(fp, "Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from, fp);
}
int main(){
    int n;
    FILE *fp;

    fp = fopen("hanoi_solution.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\nSolution:\n");
    fprintf(fp, "Tower of Hanoi Solution for %d disks:\n\n", n);
    towerOfHanoi(n, 'A', 'C', 'B', fp);
    fclose(fp);
    printf("\nAll steps have been saved to 'hanoi_solution.txt'\n");
    return 0;
}