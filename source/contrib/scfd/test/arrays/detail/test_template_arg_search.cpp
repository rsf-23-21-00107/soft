// Copyright © 2016-2020 Ryabkov Oleg Igorevich, Evstigneev Nikolay Mikhaylovitch

// This file is part of SCFD.

// SCFD is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2 only of the License.

// SCFD is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with SCFD.  If not, see <http://www.gnu.org/licenses/>.



#include <iostream>
#include <scfd/arrays/detail/template_arg_search.h>

#include "gtest/gtest.h"

using namespace scfd::arrays::detail;

/*template<int Sz, int... Dims>
bool perform_test(int test_n, static_vec::vec<int,Sz> &dyn_sizes, int correct_aswer)
{
    int answer = size_calculator<int, Dims...>::get(dyn_sizes);
    std::cout << "Test " << test_n << ": " << answer << " " << correct_aswer;
    if (answer == correct_aswer) 
        std::cout << " OK" << std::endl;
    else 
        std::cout << " FAILED!" << std::endl;
    return answer == correct_aswer;
}*/

TEST(DetailTemplateArgSearchTest, ValueOneTest) 
{
    auto found_index = template_arg_search<int, double, int,int,double>::value;
    ASSERT_EQ(found_index,2);
}
