#ifndef DIGIT_H
#define DIGIT_H

#pragma once

 

/// Разряд
class Digit
{
public:
	// Конструктор
	// type - тип счетчика
	// seq - строка, задающая последовательность значений
	// value - начальное значение
	Digit(LPCWSTR seq, WCHAR value = 0);

	virtual ~Digit(void);

	// Увеличивает значение цифры, возвращает true, если необходим перенос в старший разряд
	bool Inc();

	// Уменьшает значение цифры, возвращает true, если необходим заем из старшего разряда
	bool Dec();

	// Возвращает true при достижении максимального значения
	bool IsMax() const
	{ return m_value == m_len - 1; }

	// Возвращает true при достижении минимального значения
	bool IsMin() const
	{ return m_value == 0; }

	// Строковое представление текущего значения
	WCHAR Value() const
	{ return ToChar(m_value); }

	// Устанавивает текущее значение
	void SetValue(WCHAR value)
	{ m_value = ToInt(value); }

protected:
	// Числовое значение разряда в символьное
	WCHAR ToChar(int value) const
	{ return m_seq[value]; }

	// Символьное значение в числовое
	int ToInt(WCHAR value) const
	{ return (int)(wcschr(m_seq, 	value) - m_seq); }

private:
	// Внутренний счетчик
	int m_value;

	// Последовательность принимаемых значений
	LPCWSTR m_seq;

	// Количество значений, которое может принимать разряд
	int m_len;
};

#endif