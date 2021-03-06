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

#ifndef SHIRO_TUPLE_DETAIL_TUPLE_ELEMENT_HPP
#define SHIRO_TUPLE_DETAIL_TUPLE_ELEMENT_HPP

#include <shiro/tuple/tuple_fwd.hpp>

namespace shiro {

template <std::size_t I, typename Tuple>
class tuple_element;
template <std::size_t I, typename... Types>
class tuple_element<I, detail::tuple::tuple_types<Types...>> {
  static_assert(0 <= I && I < sizeof...(Types), "tuple index out of range");
 public:
  using type =
      typename detail::tuple::tuple_types<Types...>::template at<I>::type;
};

}  // namespace shiro

#endif  // #ifndef SHIRO_TUPLE_DETAIL_TUPLE_ELEMENT_HPP
