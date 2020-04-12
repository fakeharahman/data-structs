#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class rect
{
private:
    int len;
    int bre;

public:
    rect(int l, int b);

    int ar()
    {
        return len * bre;
    }
    void change()
    {

        len = 7;
    }
    int getlen()
    {
        return len;
    }
};
rect::rect(int l, int b)
{
    len = l;
    bre = b;
}
int main()
{
    int area;
    rect r(5, 2);
    cout << r.getlen();
    area = r.ar();
    printf("\narea = %d\n", area);
    r.change();
    return 0;
}
