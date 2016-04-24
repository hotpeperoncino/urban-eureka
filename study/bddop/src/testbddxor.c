#include "bdd.h"
#include "test.h"
int main(int ac,char**av)
{
  BDD a,b,c;
  bdd_init(N_NODES, CACHESIZE);
  bdd_setvarnum(2);
  a = bdd_ithvar(0);
  b = bdd_ithvar(1);  
  c = bdd_xor(a, b);
  bdd_fnprintdot("xor.dot", c);
  bdd_done();
}
