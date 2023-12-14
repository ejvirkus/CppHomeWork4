#pragma once
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
#include <complex>
namespace Homework
{   
    using Tasks = std::vector<std::pair<std::string, bool>>;
    Tasks assignment1();

    // Loo konsept Number, mis kontrollib, et tüüp on arv (int, float, double, jne)
    // Aga ei ole tekst või muu klassi objekt
    template<typename T>
    concept Number = std::is_arithmetic_v<T>;


    // Loo mall funktsioon fun, mis võtab argumendiks 2 arvu ja tagastab selle korrutise
    // Arv (Number) võib olla nii komaga kui ilma aga ei ole tekst või muu klassi objekt
    template<Number T>
    T fun(T a, T b){
        return a*b;
    }


    // Loo klass A, millel on liige on number tüüpi Number
    // Arv (Number) võib olla nii komaga kui ilma aga ei ole tekst või muu klassi objekt
    // ja sisaldab konstruktorit, mis võtab argumendiks number
    // ja sisaldab funktsiooni get_power_of_2, mis tagastab liikme number ruudu
    class A{
    private:
        Number auto number;
    public:
        A(Number auto num) : number(num) {}

        Number auto get_power_of_2() {
            return number * number;
        }
    };
    
}