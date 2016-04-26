#include "bdd.h"
#include "test.h"
int main(int ac,char**av)
{
  BDD a,b,c,d,e,f,g;
  bdd_init(N_NODES, CACHESIZE);
  bdd_setvarnum(8);
  a = bdd_ithvar(0);
  b = bdd_ithvar(1);
  c = bdd_ithvar(2);
  d = bdd_ithvar(3);

  e = bdd_or(a, b);
  f = bdd_or(a, c);

  g = bdd_apply(e, f, bddop_diff);
  bdd_fnprintdot("test01diff.dot", g);
  bdd_done();
}
