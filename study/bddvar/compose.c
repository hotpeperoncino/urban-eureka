#include <stdlib.h>
#include <string.h>
#include "bdd.h"
#include "test.h"
void main(int ac,char**av)
{
  BDD a,b,c,d;
  bdd_init(N_NODES, CACHESIZE);
  bdd_setvarnum(4);
  a = bdd_ithvar(0);
  b = bdd_ithvar(1);
  c = bdd_ithvar(2);
  d = bdd_ithvar(3);
  d = bdd_compose(a, b, c);
  bdd_fnprintdot("compose.dot", d);
  bdd_done();
}
