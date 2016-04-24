#include "bdd.h"
#include "test.h"
int main(int ac,char**av)
{
  BDD a,b,c,d;
  bdd_init(N_NODES, CACHESIZE);
  bdd_setvarnum(3);
  a = bdd_ithvar(0);
  b = bdd_ithvar(1);
  c = bdd_ithvar(2);    
  d = bdd_ite(a, b, c);
  bdd_fnprintdot("ite.dot", d);
  bdd_done();
}
