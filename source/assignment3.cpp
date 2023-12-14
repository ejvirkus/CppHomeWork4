#include "../include/assignment3.hpp"
#include <typeinfo>
#include <type_traits>
#include <functional>
#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include <numeric>
#include <algorithm>

// Algoritmid
Homework::Tasks Homework::assignment3()
{
    using namespace std::literals;

    std::vector numbers0 {5, 2, 8, 1, 3};
    // Sorteeri vektor numbers0 kasutades STL algoritmi
    std::sort(numbers0);
    

    std::string str { "Hello, World!"s };
    // Pööra string str ümber kasutades STL algoritmi
    std::reverse(str);
    
    std::vector numbers1 {5, 2, 8, 1, 3};
    // Leia vektorist numbers1 element 8 kasutades STL algoritmi ja salvesta see muutujasse it
    auto it = std::find(numbers1.begin(), numbers1.end(), 8);
    
    std::vector src {1, 2, 3, 4, 5};
    std::vector<int> dest(src.size()); // {} kasutus siin ei ole erandlikul sobilik
    // Kopeeri vektorist src vektorisse dest kasutades STL algoritmi
    std::copy(src.begin(), src.end(), dest.begin());

    std::vector numbers2 {5, 2, 8, 1, 3, 2, 2};
    // Eemalda vektorist numbers2 kõik elemendid, mille väärtus on 2 kasutades STL algoritmi
    // Vajab 2 STL algoritmi
    numbers2.erase(std::remove(numbers2.begin(), numbers2.end(), 2), numbers2.end());
    

    std::vector numbers3 {5, 2, 8, 1, 3, 2, 2};
    // Asenda vektoris numbers kõik elemendid, mille väärtus on 2, väärtusega 9 kasutades STL algoritmi
    std::replace(numbers3.begin(), numbers3.end(), 2, 9);

    std::vector numbers4 {1, 1, 2, 2, 3, 3, 4, 4};
    // Eemalda vektorist numbers kõik järjestikused duplikaadid kasutades STL algoritmi
    // Vajab 2 STL algoritmi
    numbers4.erase(std::unique(numbers4.begin(), numbers4.end()), numbers4.end());
    

    std::vector numbers5 {1, 2, 3, 4, 5};
    // Kalkuleeri vektori numbers summa kasutades STL algoritmi ja salvesta see muutujasse sum
    int sum = std::accumulate(numbers5.begin(), numbers5.end(), 0);    

    std::vector numbers6 {1, 2, 3, 4, 5};
    std::string str1 {};
    // Salvesta vektori numbers elemendid stringi str1 kujul "1,2,3,4,5," kasutades STL algoritmi
    std::string str1 = std::accumulate(numbers6.begin(), numbers6.end(), std::string{}
                                        [](const std::string& a, int b) {
                                            return a + std::to_string(b) + " ";
                                        });

    // Kontroll, et muutujad on õiget tüüpi ja väärtusega
    Tasks results;
    results.reserve(16ull);

    results.push_back({"numbers0 is sorted"s, std::is_sorted(numbers0.begin(), numbers0.end())});
    results.push_back({"str is reversed"s, str == "!dlroW ,olleH"s});
    results.push_back({"it points to 8"s, *it == 8});
    results.push_back({"dest is a copy of src"s, dest == src});
    results.push_back({"numbers2 has no 2s"s, std::find(numbers2.begin(), numbers2.end(), 2) == numbers2.end()});
    results.push_back({"numbers3 has no 2s"s, std::find(numbers3.begin(), numbers3.end(), 2) == numbers3.end()});
    results.push_back({"numbers3 has 9s"s, std::find(numbers3.begin(), numbers3.end(), 9) != numbers3.end()});
    results.push_back({"numbers4 has no duplicates"s, std::adjacent_find(numbers4.begin(), numbers4.end()) == numbers4.end()});
    results.push_back({"sum is 15"s, sum == 15});
    results.push_back({"str1 is \"1,2,3,4,5,\""s, str1 == "1,2,3,4,5,"s});
    
    return results;
}