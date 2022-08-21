#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
	virtual int getArea() = 0;
};

class HeightandWidth {
private:
	int height, width;

public:
	HeightandWidth(int height, int width) {
		setHeight(height);
		setWidth(width);
	}

	void setHeight(int height) {
		this->height = height;
	}

	void setWidth(int width) {
		this->width = width;
	}

	int getHeight() {
		return this->height;
	}

	int getWidth() {
		return this->width;
	}
};

class Rectangle: public HeightandWidth, public Shape {
public:
	Rectangle(int height, int width): HeightandWidth(height, width) {
		HeightandWidth(height, width);
	}

	int getArea() {
		int height = getHeight();
		int width = getWidth();

		return height * width;
	}
};

class Triangle: public HeightandWidth, public Shape {
public:
	Triangle(int height, int width): HeightandWidth(height, width) {
		HeightandWidth(height, width);
	}

	int getArea() {
		int height = getHeight();
		int width = getWidth();

		return (height * width) / 2;
	}
};

class Circle: public Shape {
private:
	const int PI = 3.14;
	int radius;

public:
	Circle(int radius) {
		setRadius(radius);
	}

	void setRadius(int radius) {
		this->radius = radius;
	}

	int getRadius() {
		return this->radius;
	}

	int getArea() {
		int radius = getRadius();

		return PI * radius * radius;
	}
};

class Solution {
public:
	void solve() {
		int height1, width1, height2, width2, radius;
		cin >> height1 >> width1 >> height2 >> width2 >> radius;

		Rectangle rectangle(height1, width1);
		Triangle triangle(height2, width2);
		Circle circle(radius);

		int rectangleArea = rectangle.getArea();
		int triangleArea = triangle.getArea();
		int circleArea = circle.getArea();
		int totalArea = rectangleArea + triangleArea + circleArea;

		cout << "The total area of these shapes is" << " " << totalArea << "\n";

	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution solution;

	solution.solve();

	return 0;
}
