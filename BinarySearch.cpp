#include <iostream>
using namespace std;

class AbstractDataType//Declaring a class for abstractdatatype
{
public:
    int *array;//Creating pointer

    int size = 0;//Initializing the size of the array with zero
    int length = 0;//Initializing the length of the array with zero
    int Binary_Search(int Lower_Index, int Higher_index, int key);//Declaring a member function for binary search
};

int AbstractDataType::Binary_Search(int Lower_Index, int Higher_index, int key)//Defining the member function outside of the class
{

    while (Lower_Index <= Higher_index)//Condition for the termination of the loop
    {
        int Mid_index = (Lower_Index + Higher_index) / 2;// Calculating the mid index
        if (array[Mid_index] == key)//Checking if the element of the mid index is equals to key or not
        {
            return Mid_index;//If maches then return that index
        }
        else if (array[Mid_index] < key)//If the key element is great then middle index elenent then change the value of low index 
        {
            Lower_Index = Mid_index + 1;//Updating that index
        }
        else
        {
            Higher_index = Mid_index - 1;//If less them ,then update the higher index by middle index minus 1
        }
    }
    return -1;//If the element was not found then return invailid index
}

int main()
{
    AbstractDataType adt;//Declaring class object named as adt
    int key, number_of_elements;//Declaring some variables
    adt.array = new int[20];//Creating the space for the array in the heap mamory
    adt.size = 20;//size is given as 20
    cout << "Enter the number of elements" << endl;
    cin >> number_of_elements;//number of elements in the array
    adt.length = number_of_elements;//Giving the value of numeber of the elements to lenght 
    cout << "Enter the elements in sorted form " << endl;
    for (int i = 0; i < number_of_elements; i++)
    {
        cin >> adt.array[i];//Taking the array input
    }

    cout << "Enter the key that you want to search in the sorted array" << endl;
    cin >> key;//Taking the array as input from user

    cout << "The index of " << key << " element is " << adt.Binary_Search(0, adt.length - 1, key);//Calling the function

    return 0;
}
