#include "StdAfx.h"
#include "Digit.h"
#include "string.h"

Digit::Digit(LPCWSTR seq, WCHAR value)
		: m_seq(seq)
		, m_len(lstrlen(seq))
{
	m_value = (value == 0) ? 0 : ToInt(value);
}

Digit::~Digit(void)
{
}

bool Digit::Inc()
{
	if(IsMax()) {
		m_value = 0;
		return true;
	} else {
		++m_value;
		return false;
	}
}

bool Digit::Dec()
{
	if(IsMin()) {
		m_value = m_len - 1;
		return true;
	} else {
		--m_value;
		return false;
	}
}