{
    n = $0;
    sub("\[label=\"0\"\]", "[label=\"a\"]", n);
    sub("\[label=\"1\"\]", "[label=\"b\"]", n);
    sub("\[label=\"2\"\]", "[label=\"c\"]", n);        
    sub("\[style=dotted\]", "[style=dotted,label=\"F\"]", n);
    sub("\[style=filled\]", "[style=filled,label=\"T\"]", n);
    print n;
}
