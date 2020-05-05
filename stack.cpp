#include <iostream>
using namespace std;

template <class T>
class stack
{
private:
    int size;
    int top;
    T *S;

public:
    stack()
    {
        size = 10;
        top = -1;
        S = new T(size);
    }
    stack(int size)
    {
        this->size = size;
        top = -1;
        S = new T(this->size);
    }

    void push(T x);
    T pop();
    T peek(int index);
    T stackTop();
    int isEmpty();
    int isFull();
    void Display();
};

template <class T>
void stack<T>::push(T x)
{
    if (top == size - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        S[top] = x;
    }
}
template <class T>
T stack<T>::pop()
{
    T x = -1;
    if (top == -1)
        printf("stack underflow");
    else
    {
        x = S[top];
        top--;
    }
    return x;
}
template <class T>
T stack<T>::stackTop()
{
    if (isEmpty())
        return -1;
    return S[top];
}
template <class T>
int stack<T>::isFull()
{
    return top == size - 1;
}

template <class T>
void stack<T>::Display()
{
    for (int i = top; i >= 0; i--)
        cout << S[i] << " ";
    cout << endl;
}
template <class T>
int stack<T>::isEmpty()
{
    return top == -1;
}

template <class T>
T stack<T>::peek(int index)
{
    T x = -1;
    if (top - index + 1 < 0)
        cout << "Invalid Index" << endl;
    else
        x = S[top - index + 1];

    return x;
}

int main()
{
    stack<char> st(5);
    st.push('d');
    st.push('g');
    st.push('t');
    st.push('r');
    st.push('y');
    st.push('s');

    st.Display();
    //cout << st.pop();
    cout << st.isEmpty();
    cout << st.isFull();
    cout << st.stackTop();
}