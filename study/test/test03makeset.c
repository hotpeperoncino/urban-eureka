#include "bdd.h"
#include "test.h"
int main(int ac,char**av)
{
  BDD a,b,c,d,e,f,g,h,i;
  bdd_init(N_NODES, CACHESIZE);
  bdd_setvarnum(8);
  a = bdd_ithvar(0);
  b = bdd_ithvar(1);
  c = bdd_ithvar(2);
  d = bdd_ithvar(3);

  int sets[] = {0,1,2,3};
  g = bdd_makeset(sets, 4);

  bdd_fnprintdot("test03makeset.dot", g);
  bdd_done();
}
