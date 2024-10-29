
#include <iostream>
#include"Vector.h"
using namespace std;


int main()
{
	Vector a(10, 3);
	a.print();

	a[0] = 10;
	a.print();
	for (size_t i = 0; i < a.getSize(); i++)
	{
		a[i] = (i + 1) * 10;
	}
	a.print();
	cout << a[222] << endl;

	Vector b = a(2, 4);
	b.print();
    cout << "==============Push back===========" << endl;
    cout <<endl;
	b.pushBack(30);
	b.print();

    cout << "==============Find Index===========" << endl;
    cout << endl;
    int index = b.find(30);
    if (index != -1) {
        cout << "Value 30 found at index: " << index <<endl;
    }
    else {
        cout << "Value 30 not found." <<endl;
    }
    cout << endl;
    cout << "======================="<<endl;
    Vector vec(5);
	vec.print();
    cout << "==============Push front===========" << endl;
    cout << endl;
    vec.pushFront(3);
    vec.print(); 
    vec.pushFront(7);
    vec.print();

    cout << "============== Insert ===========" << endl;
    cout << endl;
    vec.insert(15, 2);
    vec.print(); 

    cout << "==============Pop Back===========" << endl;
    cout << endl;
    vec.popBack();
    vec.print(); 

    cout << "============= Pop Front ===========" << endl;
    cout << endl;
    vec.popFront();
    vec.print(); 

    cout << "============== Remove index ===========" << endl;
    cout << endl;
    vec.remove(1);
    vec.print(); 

    cout <<endl;
    Vector vec1(9, 10);
    vec1.print();
    Vector vec2(11, 12);
    vec2.print(); 

    cout << "============== Operator + ===========" << endl;
    cout << endl;
    Vector resultVec = vec1 + vec2;
    resultVec.print(); 

    cout << "============== Operator - ===========" << endl;
    cout << endl;
    Vector diffVec = vec1 - vec2;
    diffVec.print(); 

    cout << "============== Operator * ===========" << endl;
    cout << endl;
    Vector scaledVec = vec1 * 2;
    scaledVec.print(); 

    cout << "==============  int() ===========" << endl;
    cout << endl;
    int sum = vec1.operator int(); 
    cout << "Sum of elements in vec: " << sum <<endl;

    cout << "============== char * ===========" << endl;
    cout << endl;
    char* charArray = (char*)vec1.operator char* (); 
    cout << "Vector as string: " << charArray <<endl;

    delete[] charArray; 





   
}

