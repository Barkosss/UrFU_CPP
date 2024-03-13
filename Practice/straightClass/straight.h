#pragma once

class Straight {
    public:

    bool operator ==(Straight&right);
    bool operator !=(Straight&right);
    Straight getPointIntersection(Straight&left, Straight&right);
    Straight(long double userX, long double userY);
    Straight() {
        x = 0;
        y = 0;
    };

    private:
    long double x;
    long double y;
};