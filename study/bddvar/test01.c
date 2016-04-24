#include <stdlib.h>
#include <string.h>
#include "bdd.h"
#include "test.h"
void main(int ac,char**av)
{
  BDD a,b,c,d,e,f,g,h;
  bdd_init(N_NODES, CACHESIZE);
  bdd_setvarnum(8);
  a = bdd_ithvar(0);
  b = bdd_ithvar(1);
  c = bdd_ithvar(2);
  d = bdd_ithvar(3);
  e = bdd_ithvar(4);
  f = bdd_ithvar(5);
  g = bdd_ithvar(6);
  h = bdd_ithvar(7);
  a = bddtrue;
  c = bddtrue;
  e = bddtrue;
  c = bdd_and(c, bdd_imp(a, bdd_not(b))); // c &= a => !b
  e = bdd_and(e, bdd_imp(a, bdd_not(d))); // e &= a => !d
  h = bddtrue;
  h = bdd_and(h, bdd_and(c, e));  // h &= (c & e);
  bdd_fnprintdot("test01-a.dot", a);
  bdd_fnprintdot("test01-c.dot", c);
  bdd_fnprintdot("test01-h.dot", h);  
  bdd_done();
}
