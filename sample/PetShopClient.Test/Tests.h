#pragma once

#include <boost/test/unit_test.hpp>

#include <cpprest/details/basic_types.h>
#include <cpprest/asyncrt_utils.h>

namespace std {
	inline ostream& operator<<(ostream& out, const wstring& value)
	{
		out << utility::conversions::to_utf8string(value);
		return out;
	}
}