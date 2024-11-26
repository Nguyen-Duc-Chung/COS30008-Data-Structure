//Main.cpp
#include <iostream>
#include "Particle2D.h"
using namespace std;
int main()
{
	cout << "A simple particle simulation\n" << endl;
	Particle2D obj(
		0.0f,
		10.0f,
		Vector2D(10.0f, 20.0f),
		Vector2D(4.0f, 15.0f), Vector2D(0.0f, -0.1f)
	);
	do
	{
		cout << obj << endl;
		obj.update();
	} while (obj.getPosition().getY() >= 20.0f);
	cout << obj << endl;
	return 0;
}









//#include <iostream>
//#include "Vector2D.h"
//using namespace std;
//
//int main() {
//    // Creating two Vector2D objects
//    Vector2D v1(3.0f, 4.0f);  // Represents the point (3, 4)
//    Vector2D v2(1.0f, 2.0f);  // Represents the point (1, 2)
//
//    // Displaying the vectors
//    cout << "Vector 1: " << v1 << endl;
//    cout << "Vector 2: " << v2 << endl;
//
//    // Demonstrating vector addition
//    Vector2D sum = v1 + v2;
//    cout << "Sum of v1 and v2: " << sum << endl;
//
//    // Demonstrating vector subtraction
//    Vector2D difference = v1 - v2;
//    cout << "Difference of v1 and v2: " << difference << endl;
//
//    // Demonstrating scalar multiplication
//    Vector2D scaled = v1 * 2.0f;
//    cout << "v1 scaled by 2: " << scaled << endl;
//
//    // Demonstrating dot product : dotProduct = (v1.fX * v2.fX) + (v1.fY * v2.fY)
//    float dotProduct = v1.dot(v2);
//    cout << "Dot product of v1 and v2: " << dotProduct << endl;
//
//    // Demonstrating cross product :  v1​×v2​=x1​⋅y2​−y1​⋅x2​
//    float crossProduct = v1.cross(v2);
//    cout << "Cross product of v1 and v2: " << crossProduct << endl;
//
//    // Demonstrating vector length
//    float length = v1.length();
//    cout << "Length of v1: " << length << endl;
//
//    // Demonstrating normalization
//    Vector2D normalized = v1.normalize();
//    cout << "Normalized v1: " << normalized << endl;
//
//    // Demonstrating direction (angle) in degrees
//    float angle = v1.direction();
//    cout << "Direction of v1 (angle in degrees): " << angle << endl;
//
//    return 0;
//}







