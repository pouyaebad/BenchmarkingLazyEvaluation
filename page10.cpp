// a simple example of using proxy objects to implement Lazy Evaluation

#include <iostream>

using namespace std;


class PointProxy {
public:
	PointProxy(const double x, const double y) : dist_squared{ x * x + y * y } {};

	double getDistSquared(void) const { return dist_squared; };

	operator double() const { cout << " [SQRT Proxy] "; return sqrt(dist_squared); }

	bool operator<(const double d) const { return dist_squared < d * d; }
	bool operator>(const double d) const { return dist_squared > d * d; }

	bool operator<(const PointProxy d) const { return dist_squared < d.getDistSquared(); }
	bool operator>(const PointProxy d) const { return dist_squared > d.getDistSquared(); }

protected:
	const double dist_squared{};
};



class MyPoint {
public:
	MyPoint(const double px, const double py) : x{ px }, y{ py } {};

	double     distanceEager(void) { cout << " [SQRT Point] "; return sqrt(x * x + y * y); };
	PointProxy distanceLazy(void) { return PointProxy{ x, y }; };

protected:
	double x{}, y{};
};



int main() {
	MyPoint p1{ 3.0, 4.0 }, p2{ 7.0, 6.0 };

	cout << "Distance from the Origin is (Eager): " << p1.distanceEager() << "\n";
	cout << "Distance from the Origin is (Lazy) : " << p1.distanceLazy() << "\n\n\n";


	if (p1.distanceLazy() < 6.0)
		cout << "Distance of p1 to origin is less than six - Lazy" << "\n\n";

	if (p1.distanceEager() < 6.0)
		cout << "Distance of p1 to origin is less than six - Eager" << "\n\n\n\n";


	if (p1.distanceLazy() < p2.distanceLazy())
		cout << "p1 is closer to origin than p2 - Lazy" << "\n\n";

	if (p1.distanceEager() < p2.distanceEager())
		cout << "p1 is closer to origin than p2 - Eager" << "\n\n";
}
