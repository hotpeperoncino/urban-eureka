/**************************************************************************
  BDD demonstration of the N-Queen chess problem.
  -----------------------------------------------
  The BDD variables correspond to a NxN chess board like:

     0    N      2N     ..  N*N-N
     1    N+1    2N+1   ..  N*N-N+1
     2    N+2    2N+2   ..  N*N-N+2
     ..   ..     ..     ..  ..
     N-1  2N-1   3N-1   ..  N*N-1

   So for example a 4x4 is:

     0 4  8 12
     1 5  9 13
     2 6 10 14
     3 7 11 15

   One solution is then that 2,4,11,13 should be true, meaning a queen
   should be placed there:

     . X . .
     . . . X
     X . . .
     . . X .
     
**************************************************************************/
#include <stdlib.h>
#include "bdd.h"
#include <iostream>

using namespace std;

int N;                /* Size of the chess board */
bdd **X;              /* BDD variable array */
bdd queen;            /* N-queen problem express as a BDD */

int snap_i = 0;
int snap_j = 0;

/* Build the requirements for all other fields than (i,j) assuming
   that (i,j) has a queen */
void build(int i, int j)
{
   bdd a=bddtrue, b=bddtrue, c=bddtrue, d=bddtrue, g=bddtrue;
   int k,l;
   
      /* No one in the same column */
   for (l=0 ; l<N ; l++)
      if (l != j)
	 a &= X[i][j] >> !X[i][l];

   if (i == snap_i && j == snap_j)
     bdd_fnprintdot("queen-a.dot", a);
   
      /* No one in the same row */
   for (k=0 ; k<N ; k++)
      if (k != i)
	 b &= X[i][j] >> !X[k][j];

   if (i == snap_i && j == snap_j)
     bdd_fnprintdot("queen-b.dot", b);   

      /* No one in the same up-right diagonal */
   for (k=0 ; k<N ; k++)
   {
      int ll = k-i+j;
      if (ll>=0 && ll<N)
	 if (k != i)
	    c &= X[i][j] >> !X[k][ll];
   }

   if (i == snap_i && j == snap_j)
     bdd_fnprintdot("queen-c.dot", c);
   
      /* No one in the same down-right diagonal */
   for (k=0 ; k<N ; k++)
   {
      int ll = i+j-k;
      if (ll>=0 && ll<N)
	 if (k != i)
	    d &= X[i][j] >> !X[k][ll];
   }

   if (i == snap_i && j == snap_j)
     bdd_fnprintdot("queen-d.dot", d);
   
   g = a & b & c & d;

   if (i == snap_i && j == snap_j)
     bdd_fnprintdot("queen-g.dot", g);


   queen &= a & b & c & d;

   if (i == snap_i && j == snap_j)
     bdd_fnprintdot("queen-snap.dot", queen);
}


int main(int ac, char **av)
{
   int n,i,j;
   
   if (ac < 2)
   {
      fprintf(stderr, "USAGE:  queen N snapi snapj\n");
      return 1;
   }

   N = atoi(av[1]);
   if (N <= 0)
   {
      fprintf(stderr, "USAGE:  queen N\n");
      return 1;
   }
   if (ac >= 4) {
     snap_i = atoi(av[2]);
     snap_j = atoi(av[3]);
   }

      /* Initialize with 100000 nodes, 10000 cache entries and NxN variables */
   bdd_init(N*N*256, 10000);
   bdd_setvarnum(N*N);

   queen = bddtrue;
   
      /* Build variable array */
   X = new bdd*[N];
   for (n=0 ; n<N ; n++)
      X[n] = new bdd[N];

   for (i=0 ; i<N ; i++)
      for (j=0 ; j<N ; j++)
	 X[i][j] = bdd_ithvar(i*N+j);
   
//   bdd_printtable(X[0][0]);

      /* Place a queen in each row */
   for (i=0 ; i<N ; i++)
   {
      bdd e = bddfalse;
      for (j=0 ; j<N ; j++)
	 e |= X[i][j];
      queen &= e;
   }

   printf("queen-1\n");
   bdd_printtable(queen);
   bdd_printset(queen);
   printf("\n");
   bdd_fnprintdot("queen-1.dot", queen);   
   
      /* Build requirements for each variable(field) */
   for (i=0 ; i<N ; i++)
      for (j=0 ; j<N ; j++)
       {
	  cout << "Adding position " << i << "," << j << "\n" << flush;
	  build(i,j);
       }
   
   printf("queen-2\n");
   bdd_printtable(queen);
   bdd_printset(queen);
   printf("\n");
   bdd_fnprintdot("queen-2.dot", queen);   

      /* Print the results */
   {
   cout << "There are " << bdd_satcount(queen) << " solutions\n";
   cout << "one is:\n";
   bdd solution = bdd_satone(queen);
   cout << bddset << solution << endl;
   }
   bdd_done();
   
   return 0;
}
