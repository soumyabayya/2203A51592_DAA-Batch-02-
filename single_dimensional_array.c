#include <stdio.h>
int main()
{
int x [20], i, N;
printf ("Enter the Number of Elements:");
scanf("%d", &N);
printf ("Enter the Elements of array:\n");
for (i=0; i < N; i++)
{
scanf("%d", &x [i]);
}
printf ("The Elements in the Array are:");
for (i = 0; i < N; i++)
{
printf(" %d",x[i]);
}
}
