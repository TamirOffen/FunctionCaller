#include <iostream>
#include <vector>

template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
{
    if(start < 0 || start >= (int)(vec.size())){
        //throw BadInput;
        return;
    }else if(stop < 0 || stop >= (int)(vec.size())){
        //throw BadInput;
        return;
    }else if(step <= 0){
        //throw BadInput;
        return;
    }

    std::vector<T> new_vec;
    if(start >= stop){
        return new_vec;//Returns an empty vector.
    }

    for (int i = start ; i < stop ; i += step){
        new_vec.push_back(vec[i]);
    }
    return new_vec;
}


//For testing
int main ()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> vec_sliced = slice(vec, 0, 3, 6);

    for (int x : vec_sliced) std::cout << x << " ";
    return 0;
}