#include <iostream>

using namespace std;

// // - ### Requirements:
// 1. write simple calculator using OOP.

// 2. Data Member : _lastNumber, _Result, _preResult, str = {"Clearing", "Adding", "Substring", "Multiplying", "Dividing"} 

// 3. Methods : Clear(), Add(), Subtract(), Multiply(), Divide(), Cancel(), _isZero(), Print Result()

class clsCalculator
{
private:
    float _lastNumber = 0;
    float _result = 0;
    float _previousResult = 0;
    string _lastOperation = "Clear";
    bool _isZero(float number)
    {
        if (number == 0)
        {
            return 1;
        }
        return 0;
    }

public:
    void Clear()
    {
        _lastNumber = 0;
        _result = 0;
        _previousResult = 0;
        _lastOperation = "Clear";
    }
    void Add(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _result += number;
        _lastOperation = "Adding";
    }
    void Substract(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _result -= number;
        _lastOperation = "Substracing";
    }
    void Multiply(float number)
    {
        _lastNumber = number;
        _previousResult = _result;
        _result *= number;
        _lastOperation = "Multiplying";
    }
    void Divid(float number)
    {
        _lastNumber = number;
        if (_isZero(number))
        {
            number = 1;
        }
        _previousResult = _result;
        _result /= number;
        _lastOperation = "Dividing";
    }

    float getFainalResult()
    {
        return _result;
    }

    void cansleLastOperation()
    {
        _lastNumber = 0;
        _lastOperation = "Cancelling Last Operation";
        _result = _previousResult;
    }
    void printResult()
    {
        cout << "Result After " << _lastOperation << " " << _lastNumber << " is: " << _result << endl;
    }
};

int main()
{
    clsCalculator Calculator01;

    Calculator01.Add(10);
    Calculator01.printResult();
    Calculator01.Add(100);
    Calculator01.printResult();
    Calculator01.Substract(20);
    Calculator01.printResult();
    Calculator01.Divid(2);
    Calculator01.printResult();
    Calculator01.Multiply(4);
    Calculator01.printResult();
    Calculator01.cansleLastOperation();
    Calculator01.printResult();
    Calculator01.Clear();
    Calculator01.printResult();
    return 0;
}
