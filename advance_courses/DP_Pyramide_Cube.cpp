// C header
#include <math.h>     // pow

// C++ header
#include <iostream>   // cout
#include <vector>     // vector
#include <array>      // array
#include <algorithm>  // sort, unique
#include <limits>     // numerics_limits

int main()
{
    std::vector<uint64_t> cubes;
    uint64_t i = 1,j=0,k=0;

    ///----------------------- Code a modifier -----------------------------------------------------------/
    const uint64_t N = 1000000;
    ///---------------------------------------------------------------------------------------------------/

    while(true)
    {
        j+= (i*i);
        k = pow(i,3);
        if( j < N )
            cubes.push_back(j);
        if( k < N )
            cubes.push_back(k);
        if( j > N && k > N )
            break;
        i++;
    }

    std::sort(cubes.begin() , cubes.end());
    cubes.erase(std::unique(cubes.begin(),cubes.end()), cubes.end());


    //--------------------- Afficher les tailles ----------------------------------------------------------/
    std::cout << "Les tailles des cubes et des pyramides sont :";
    std::for_each(cubes.begin(),cubes.end(),[](int x)
    {
        std::cout << x << " ";
    });
    std::cout << std::endl;


    std::array<uint64_t, N+1 > res;
    res.fill(std::numeric_limits<uint64_t>::max());
    res.at(0) = 0;
    k = cubes.size();

    //-------------------- Algorithme de DP ---------------------------------------------------------------/
    for(uint64_t i = 0; i <= N; i++)
    {
        for(uint64_t j=0; j< k ; j++)
        {
            if(i >= cubes.at(j))
            {
                res.at(i) = std::min(res.at(i),res.at(i-cubes[j]) + 1);
            }
        }
    }

    //-------------------- Afficher la solution ------------------------------------------------------------/
    std::cout << "La solution du probleme est " << res[N];
    return 0;
}

