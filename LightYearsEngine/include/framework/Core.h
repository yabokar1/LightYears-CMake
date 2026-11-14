#pragma once
#include <stdio.h>
#include <functional>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>

namespace ly
{
	template<typename T>
	using unique = std::unique_ptr<T>;

	template<typename T>
	using shared = std::shared_ptr<T>;

	template<typename T>
	using weak = std::weak_ptr<T>;

	template<typename T>
	using list = std::vector<T>;

	template<typename KeyType, typename ValueType, typename Predicate = std::less<KeyType>>
	using map = std::map<KeyType, ValueType, Predicate>;

	template<typename KeyType, typename ValueType, typename hasher = std::hash<KeyType>>
	using dictionary = std::unordered_map<KeyType, ValueType, hasher>;

#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}
