#include <stdio.h>
void initialisation(int *);
void Tower_of_Hanoi(int *, int, char, char, char);
void initialisation(int *step_count)
{
    *step_count = 0;
}
void Tower_of_Hanoi(int *step_count, int N, char Source, char Aux, char Target)
{
    if (N > 0)
    {
        Tower_of_Hanoi(step_count, (N - 1), Source, Target, Aux);
        printf("\n Step No. %d : Transfer Disk %d from %c to %c", ++(*step_count), N, Source, Target);
        Tower_of_Hanoi(step_count, (N - 1), Aux, Source, Target);
    }
}
void main()
{
    int n, step_no;
    printf("\n Enter the no. of disks:");
    scanf("%d", &n);
    initialisation(&step_no);
    Tower_of_Hanoi(&step_no, n, 'S', 'A', 'T');
} 

/*
Algorithm
Step 1: Define the problem for N disks to be moved from Source to Target using Auxiliary
Step 2: Check if N--1
    If true, move the single disk from Source to Target
    If false, proceed to step 3.
Step 3: Recursively move N-1 disks from Source to Auxiliary, using Target as the helper rod.
Step 4: Move the largest disk (DiskN) directly from Source to Target.
Step 5: Recursively move the N-1 disks from Auxiliary to Target, using Source as the helper rod. 
Step 6: End when all disks are successfully moved from Source to Target in the correct order.
*/