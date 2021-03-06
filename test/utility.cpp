///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) fimbul 2014.
// https://github.com/fimbul/Shiro
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
///////////////////////////////////////////////////////////////////////////////

#include <type_traits>
#include <utility>

#include <shiro/utility.hpp>

int main() {
  /* logical_and */
  {
    static_assert(shiro::logical_and_c<true>::value, "");
    static_assert(!shiro::logical_and_c<false>::value, "");
    static_assert(shiro::logical_and_c<true, true, true>::value, "");
    static_assert(!shiro::logical_and_c<true, true, false>::value, "");
    static_assert(!shiro::logical_and_c<true, false, true>::value, "");
    static_assert(!shiro::logical_and_c<true, false, false>::value, "");
    static_assert(!shiro::logical_and_c<false, true, true>::value, "");
    static_assert(!shiro::logical_and_c<false, true, false>::value, "");
    static_assert(!shiro::logical_and_c<false, false, true>::value, "");
    static_assert(!shiro::logical_and_c<false, false, false>::value, "");
    static_assert(shiro::logical_and<std::true_type, std::true_type,
                                     std::true_type>::value,
                  "");
    static_assert(!shiro::logical_and<std::true_type, std::true_type,
                                      std::false_type>::value,
                  "");
    static_assert(!shiro::logical_and<std::true_type, std::false_type,
                                      std::true_type>::value,
                  "");
    static_assert(!shiro::logical_and<std::true_type, std::false_type,
                                      std::false_type>::value,
                  "");
    static_assert(!shiro::logical_and<std::false_type, std::true_type,
                                      std::true_type>::value,
                  "");
    static_assert(!shiro::logical_and<std::false_type, std::true_type,
                                      std::false_type>::value,
                  "");
    static_assert(!shiro::logical_and<std::false_type, std::false_type,
                                      std::true_type>::value,
                  "");
    static_assert(!shiro::logical_and<std::false_type, std::false_type,
                                      std::false_type>::value,
                  "");
  }

  /* logical_or */
  {
    static_assert(shiro::logical_or_c<true>::value, "");
    static_assert(!shiro::logical_or_c<false>::value, "");
    static_assert(shiro::logical_or_c<true, true, true>::value, "");
    static_assert(shiro::logical_or_c<true, true, false>::value, "");
    static_assert(shiro::logical_or_c<true, false, true>::value, "");
    static_assert(shiro::logical_or_c<true, false, false>::value, "");
    static_assert(shiro::logical_or_c<false, true, true>::value, "");
    static_assert(shiro::logical_or_c<false, true, false>::value, "");
    static_assert(shiro::logical_or_c<false, false, true>::value, "");
    static_assert(!shiro::logical_or_c<false, false, false>::value, "");
    static_assert(shiro::logical_or<std::true_type>::value, "");
    static_assert(!shiro::logical_or<std::false_type>::value, "");
    static_assert(shiro::logical_or<std::true_type>::value, "");
    static_assert(!shiro::logical_or<std::false_type>::value, "");
    static_assert(shiro::logical_or<std::true_type, std::true_type,
                                    std::true_type>::value,
                  "");
    static_assert(shiro::logical_or<std::true_type, std::true_type,
                                    std::false_type>::value,
                  "");
    static_assert(shiro::logical_or<std::true_type, std::false_type,
                                    std::true_type>::value,
                  "");
    static_assert(shiro::logical_or<std::true_type, std::false_type,
                                    std::false_type>::value,
                  "");
    static_assert(shiro::logical_or<std::false_type, std::true_type,
                                    std::true_type>::value,
                  "");
    static_assert(shiro::logical_or<std::false_type, std::true_type,
                                    std::false_type>::value,
                  "");
    static_assert(shiro::logical_or<std::false_type, std::false_type,
                                    std::true_type>::value,
                  "");
    static_assert(!shiro::logical_or<std::false_type, std::false_type,
                                     std::false_type>::value,
                  "");
  }

  /* index_sequence_range */
  {
    static_assert(
        std::is_same<typename shiro::index_sequence_range<0, 10>::type,
                     std::index_sequence<0, 1, 2, 3, 4, 5, 6, 7, 8, 9> >::value,
        "");
    static_assert(
        std::is_same<typename shiro::index_sequence_range<5, 10>::type,
                     std::index_sequence<5, 6, 7, 8, 9> >::value,
        "");
    static_assert(
        std::is_same<typename shiro::index_sequence_range<0, 10, 2>::type,
                     std::index_sequence<0, 2, 4, 6, 8> >::value,
        "");
    static_assert(
        std::is_same<typename shiro::index_sequence_range<0, 10, 3>::type,
                     std::index_sequence<0, 3, 6, 9> >::value,
        "");
    static_assert(
        std::is_same<typename shiro::index_sequence_range<2, 10, 2>::type,
                     std::index_sequence<2, 4, 6, 8> >::value,
        "");
    static_assert(
        std::is_same<typename shiro::index_sequence_range<2, 10, 3>::type,
                     std::index_sequence<2, 5, 8> >::value,
        "");
  }
}
