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

  f = bdd_or(a, b);
  g = bdd_or(c, d);
  
  h = bdd_compose(f, g, c);

  bdd_fnprintdot("test02compose-a.dot", a);
  bdd_fnprintdot("test02compose-f.dot", f);  
  bdd_fnprintdot("test02compose-g.dot", g);
  bdd_fnprintdot("test02compose.dot", h);
  bdd_done();
}
