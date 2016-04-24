#include "bdd.h"
#include "test.h"
int main(int ac,char**av)
{
  BDD a,b,c;
  bdd_init(N_NODES, CACHESIZE);
  a = bdd_true();
  bdd_fnprintdot("true.dot", a);
  bdd_done();
}
