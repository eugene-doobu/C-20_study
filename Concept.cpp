#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

// Concept:: 컴파일 타임에 결정

// 1) Requires Clause
template<typename T>
requires integral<T>
void TestConcpt1(T number) {
    cout << number << endl;
}

// 2) Trailing Requires Clause
template<typename T>
void TestConcpt2(T number) requires integral<T>{
    cout << number << endl;
}

// 3) Constrained Template Parameter
template<integral T>
void TestConcpt3(T number) {
    cout << number << endl;
}

// 4) Abbreviated Function Template
void TestConcpt4(integral auto number) {
    cout << number << endl;
}

void StrictSort(random_access_iterator auto begin, random_access_iterator auto end) {
    //Sort
}

class GameObject {

};

class Knight : public GameObject {

};

template<typename T>
requires derived_from<T, GameObject>
void TestObj(T* obj) {

}

template<typename T>
concept MyConcept = !is_integral_v<T> && derived_from<T, GameObject>;

template<typename T>
concept Addable = requires (T a, T b) {
    a + b;
};

template<typename T>
concept Equality = requires(T a, T b) {
    {a == b} -> convertible_to<bool>;
    {a != b} -> convertible_to<bool>;
};

int main()
{
    TestConcpt1(5);
    // TestConcpt1(5.5); #error

    vector<int> v;
    StrictSort(v.begin(), v.end());

    list<int> li;
    //StrictSort(li.begin(), li.end()); # error

    TestObj(new Knight);
    //TestObj(new int); # error
}
