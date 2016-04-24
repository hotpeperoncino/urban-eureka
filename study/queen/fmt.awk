{
    n = $0;
    sub("\[label=\"0\"\]", "[label=\"X[0][0]\"]", n);
    sub("\[label=\"1\"\]", "[label=\"X[0][1]\"]", n);
    sub("\[label=\"2\"\]", "[label=\"X[0][2]\"]", n);
    sub("\[label=\"3\"\]", "[label=\"X[0][3]\"]", n);
    sub("\[label=\"4\"\]", "[label=\"X[1][0]\"]", n);
    sub("\[label=\"5\"\]", "[label=\"X[1][1]\"]", n);
    sub("\[label=\"6\"\]", "[label=\"X[1][2]\"]", n);
    sub("\[label=\"7\"\]", "[label=\"X[1][3]\"]", n);
    sub("\[label=\"8\"\]", "[label=\"X[2][0]\"]", n);
    sub("\[label=\"9\"\]", "[label=\"X[2][1]\"]", n);
    sub("\[label=\"10\"\]", "[label=\"X[2][2]\"]", n);
    sub("\[label=\"11\"\]", "[label=\"X[2][3]\"]", n);
    sub("\[label=\"12\"\]", "[label=\"X[3][0]\"]", n);
    sub("\[label=\"13\"\]", "[label=\"X[3][1]\"]", n);
    sub("\[label=\"14\"\]", "[label=\"X[3][2]\"]", n);
    sub("\[label=\"15\"\]", "[label=\"X[3][3]\"]", n);
    sub("\[style=dotted\]", "[style=dotted,label=\"F\"]", n);
    sub("\[style=filled\]", "[style=filled,label=\"T\"]", n);
    print n;
}
