#include <stdlib.h>
#include <string.h>
#include "bdd.h"
#include "test.h"
int getopcode(char*);
int main(int ac,char**av)
{
  BDD a,b,c,d;
  bdd_init(N_NODES, CACHESIZE);
  bdd_setvarnum(4);
  int opcode = bddop_and;
  if (ac == 2) {
    char *op = *(av+1);
    opcode = getopcode(op);
  }
  a = bdd_ithvar(0);
  b = bdd_ithvar(1);
  c = bdd_ithvar(2);
  d = bdd_ithvar(3);
  d = bdd_appex(a, b, opcode, c);
  bdd_fnprintdot("appex.dot", d);
  bdd_done();
}
int getopcode(char *op)
{
#define OP(n) if (!strcmp(op,#n)) { return bddop_##n; }
  OP(and);OP(biimp);OP(diff);OP(imp);
  OP(invimp);OP(less);OP(nand);
  OP(nor);OP(or);OP(xor);
  return bddop_and;
}
