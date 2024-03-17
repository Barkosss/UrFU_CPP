class Polygon {
public:

    // Получить X координату точки
    long double getX(unsigned int indexPoint) {

    }

    // Получить Y координату точки
    long double getY(unsigned int indexPoint) {

    }

    // Назначить точки
    void getPoint(unsigned int points, long double **arrayPoints) {
        counterPoint = points;
        array = arrayPoints;
    }
    
private:
    unsigned counterPoint;
    long double **array;
};