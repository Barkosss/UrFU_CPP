class Polygon {
    public:
    long double getX(unsigned int indexPoint);
    long double getY(unsigned int indexPoint);
    void getPoint(unsigned int points, long double **arrayPoints);

    private:
    unsigned counterPoint;
    long double **array;
};