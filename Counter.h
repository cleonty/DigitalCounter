#ifndef COUNTER_H
#define COUNTER_H

#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "Digit.h"


/// �������, ��������� �� ��������
class Counter
{
public:
	// �����������
	// type - ������ � ������ ��������
	// value - ������ �������� ��������
	Counter(LPCWSTR type, LPCWSTR value = NULL);

	// ����������� ��������
	void Inc();	

	// ��������� ��������
	void Dec();	

	// ���������� �� ������������ ��������
	bool IsMax() const; 

	// ���������� �� ����������� ��������
	bool IsMin() const; 

	// ������ � ������ ��������
	LPCWSTR Type() const
	{ return m_type; }

	// �����������
	int Capacity() const 
	{ return m_capacity; }

	// ������� ��������
	LPCWSTR Value() const 
	{ return (LPCWSTR)m_lpStrValue; }

	operator LPCWSTR()
	{ return (LPCWSTR)m_lpStrValue; }

	// ������������� ������� ��������
	void SetValue(LPCWSTR value); 

	friend std::wostream& operator<<(std::wostream &os, const Counter &counter);
	friend std::wistream& operator>>(std::wistream &is, Counter &counter);

	// ������������ ����� ��� �������
	static void RegisterDigit(WCHAR name, LPCWSTR seq); 
	
	// ���������� ������ � ������������������� ��������
	// ��� ������������������� �������
	static LPCWSTR GetSeq(WCHAR name); 

	virtual ~Counter(void);

private:
	// ����������� ����������� � �������� ������������ �� ���������,
	// ���� ��������
	Counter(const Counter&);
	Counter &operator=(const Counter &rsh);

	// ��������� ��������� ������������� �������� �������� � ������ m_lpStrValue
	void SetStrValue(); 

	// ������ � ������ ��������
	LPCWSTR m_type;

	// �����������
	int m_capacity;
	
    // ���������� ����� ��� ���������� �������� ��������
	mutable WCHAR *m_lpStrValue;
	
	// �������
	std::vector<Digit> m_digits;

    // ������������������ �������
	static std::map<WCHAR, LPCWSTR> m_knownDigits;
};

#endif