#pragma once

// switch������ ��� �ϱ� ����
size_t constexpr HashCode(string_view key)
{
	return key.front() ? static_cast<unsigned int>(key.front()) + 0xEDB8832Full * HashCode(key.data() + 1) : 8603;
}