#include <iostream>
#include <cmath>
    class functs {
    public:
        double a = 0.3;
        double b = 0.4;
        double c = 0.1;
        double d = 0.5;
        double u = 1.0;
        double y = 0.0;
        void println(double val) {
            std::cout << val << std::endl;
        }
        // Линейная модель
        double linear(double y, int n, int t) const{
            if (n < t) {
                println(y);
                return linear(a * y + b * u, n + 1, t);
            }
            println(y);
            return a * y + b * u;
        }
};
int main() {
    functs f;
    std::cout << "Линейная модель" << std::endl;
    std::cout << f.linear(f.y, 0, 10) << std::endl;
    std::cout << "                   " << std::endl;
    std::cout << "Нелинейная модель" << std::endl;
    f.println(f.y);
    double y_prev = f.y;
    double u_prev = f.u;
    f.y = f.a * f.y - f.b * y_prev * y_prev + f.c * 1.0 + f.d * sin(1.0);
    for (int i = 1; i < 10; i++) {
        f.println(f.y);
        double temp = f.y;
        f.y = f.a * f.y - f.b * y_prev * y_prev + f.c * f.u + f.d * sin(u_prev);
        y_prev = temp;
        u_prev = f.u;
    }
    return 0;
}
