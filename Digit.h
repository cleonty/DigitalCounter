#ifndef DIGIT_H
#define DIGIT_H

#pragma once

 

/// ������
class Digit
{
public:
	// �����������
	// type - ��� ��������
	// seq - ������, �������� ������������������ ��������
	// value - ��������� ��������
	Digit(LPCWSTR seq, WCHAR value = 0);

	virtual ~Digit(void);

	// ����������� �������� �����, ���������� true, ���� ��������� ������� � ������� ������
	bool Inc();

	// ��������� �������� �����, ���������� true, ���� ��������� ���� �� �������� �������
	bool Dec();

	// ���������� true ��� ���������� ������������� ��������
	bool IsMax() const
	{ return m_value == m_len - 1; }

	// ���������� true ��� ���������� ������������ ��������
	bool IsMin() const
	{ return m_value == 0; }

	// ��������� ������������� �������� ��������
	WCHAR Value() const
	{ return ToChar(m_value); }

	// ������������ ������� ��������
	void SetValue(WCHAR value)
	{ m_value = ToInt(value); }

protected:
	// �������� �������� ������� � ����������
	WCHAR ToChar(int value) const
	{ return m_seq[value]; }

	// ���������� �������� � ��������
	int ToInt(WCHAR value) const
	{ return (int)(wcschr(m_seq, 	value) - m_seq); }

private:
	// ���������� �������
	int m_value;

	// ������������������ ����������� ��������
	LPCWSTR m_seq;

	// ���������� ��������, ������� ����� ��������� ������
	int m_len;
};

#endif