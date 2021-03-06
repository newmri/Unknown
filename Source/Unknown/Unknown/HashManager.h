#pragma once

constexpr size_t HashCode(string_view key)
{
	return key.front() ? static_cast<unsigned int>(key.front()) + 0xEDB8832Full * HashCode(key.data() + 1) : 8603;
}

class HashManager
{
	DECLARE_SINGLETON(HashManager)
};