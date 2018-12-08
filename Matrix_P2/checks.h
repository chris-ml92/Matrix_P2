#pragma once
#include <type_traits>
#include <utility>
template <typename...>
using void_t = void;

template <typename, typename = void>
struct is_callable : std::false_type
{
};

template <typename TF, class... TArgs>
struct is_callable<TF(TArgs...),
	void_t<decltype(std::declval<TF>()(std::declval<TArgs>()...))>>
	: std::true_type
{
};

template <typename TF>
struct validity_checker
{
	template <typename... Ts>
	constexpr auto operator()(Ts&&...) const
	{
		return is_callable<TF(Ts...)>{};
	}
};

template <typename TF>
constexpr auto is_valid(TF)
{
	return validity_checker<TF>{};
}
