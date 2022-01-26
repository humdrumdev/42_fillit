int sq_root(int num)
{
    int sqr;

    sqr = 2;
    while ((sqr * sqr) < num)
        sqr++;
    return (sqr);
}