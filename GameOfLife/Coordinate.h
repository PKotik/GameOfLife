#pragma once
class Coordinate
{
private:
	float coor_x, coor_y;
	float len_x, len_y;
public:
    Coordinate() : coor_x(0), coor_y(0), len_x(0), len_y(0) {}
    Coordinate(float x, float y) : coor_x(x), coor_y(y), len_x(0), len_y(0) {}
    Coordinate(float x, float y, float lx, float ly)
        : coor_x(x), coor_y(y), len_x(lx), len_y(ly) {
    }
    ~Coordinate() = default;

    // get
    float X() const { return coor_x; }
    float Y() const { return coor_y; }
    float farX() const { return coor_x + len_x; }
    float farY() const { return coor_y + len_y; }

    // set
    void X(float newX) { coor_x = newX; }
    void Y(float newY) { coor_y = newY; }
    void lenX(float newLenX) { len_x = newLenX; }
    void lenY(float newLenY) { len_y = newLenY; }

    // compare
    bool operator==(const Coordinate& coor) const {
        return (coor_x >= coor.X() && coor_x <= coor.farX()) &&
            (coor_y >= coor.Y() && coor_y <= coor.farY());
    }
};