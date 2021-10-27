class Prostokat
{
private:
    double width, heigth;
    static int ilosc;

public:
    int getIlosc() { return ilosc; }
    double getA() { return width; }
    double getB() { return heigth; }
    Prostokat(double a, double b);
    Prostokat(Prostokat &p);
    ~Prostokat();
    void draw();
    double L();
    double pole();
};