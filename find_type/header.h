# pragma once

template<class T, class... ListOfTypes>
struct find_type{};
 
template<class T> 
struct find_type<T> : std::false_type{};

template<class T, class... RestOfTypes>
struct find_type<T,T,RestOfTypes...> : std::true_type{};

template<class T, class T0, class... RestOfTypes>
struct find_type<T,T0,RestOfTypes...> : find_type<T,RestOfTypes...>{};