#include "StdAfx.h"
#include <string>
#include "Counter.h"

std::map<WCHAR, LPCWSTR> Counter::m_knownDigits;

Counter::Counter(LPCWSTR type, LPCWSTR value)
		: m_type(type)
		, m_capacity(lstrlen(type))
{
	m_lpStrValue = new WCHAR[m_capacity + 1];
	for(int i = 0; i < m_capacity; ++i) {
		Digit digit(Counter::GetSeq(type[i]), value == NULL ? 0 : value[i]);
		m_digits.push_back(digit);
	}

	SetStrValue();
	m_lpStrValue[m_capacity] = L'\0';
}

void Counter::SetStrValue()
{
	for(int i = 0; i < m_capacity; ++i) {
		m_lpStrValue[i] = m_digits[i].Value();
	}
}

bool Counter::IsMax() const
{
	for(int i = 0; i < m_capacity; ++i)
	{
		if(!m_digits[i].IsMax()) return false;
	}
	return true;
}

bool Counter::IsMin() const
{
	for(int i = 0; i < m_capacity; ++i)
	{
		if(!m_digits[i].IsMin()) return false;
	}
	return true;
}

void Counter::Inc()
{
	if(!IsMax()) {
		int i = m_capacity - 1;
		while(m_digits[i].Inc()) --i;
		SetStrValue();
	}
}

void Counter::Dec()
{
	if(!IsMin()) {
		int i = m_capacity - 1;
		while(m_digits[i].Dec()) --i;
		SetStrValue();
	}
}

void Counter::SetValue(LPCWSTR value)
{
	for(int i = 0; i < m_capacity; ++i) {
		m_digits[i].SetValue(value[i]);
	}
	SetStrValue();
}

Counter::~Counter(void)
{
	delete [] m_lpStrValue;
}

void Counter::RegisterDigit(WCHAR name, LPCWSTR seq)
{
	m_knownDigits.insert(std::make_pair(name, seq));
}

LPCWSTR Counter::GetSeq(WCHAR name)
{
	return m_knownDigits[name];
}

std::wostream& operator<<(std::wostream &os, const Counter &counter)
{
	os << counter.Value();
	return os;
}

std::wistream& operator>>(std::wistream &is, Counter &counter)
{
	std::wstring strValue;
	is >> strValue;
	counter.SetValue(strValue.c_str());
	return is;
}