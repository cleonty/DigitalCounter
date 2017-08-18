#ifndef COUNTER_H
#define COUNTER_H

#pragma once
#include <map>
#include <vector>
#include <iostream>
#include "Digit.h"


/// Счетчик, состоящий из разрядов
class Counter
{
public:
	// Конструктор
	// type - строка с типами разрядов
	// value - строка значений разрядов
	Counter(LPCWSTR type, LPCWSTR value = NULL);

	// Увеличивает значение
	void Inc();	

	// Уменьшает значение
	void Dec();	

	// Достигнуто ли максимальное значение
	bool IsMax() const; 

	// Достигнуто ли минимальное значение
	bool IsMin() const; 

	// Строка с типами разрядов
	LPCWSTR Type() const
	{ return m_type; }

	// Разрядность
	int Capacity() const 
	{ return m_capacity; }

	// Текущее значение
	LPCWSTR Value() const 
	{ return (LPCWSTR)m_lpStrValue; }

	operator LPCWSTR()
	{ return (LPCWSTR)m_lpStrValue; }

	// Устанавливает текущее значение
	void SetValue(LPCWSTR value); 

	friend std::wostream& operator<<(std::wostream &os, const Counter &counter);
	friend std::wistream& operator>>(std::wistream &is, Counter &counter);

	// Регистрирует новый тип разряда
	static void RegisterDigit(WCHAR name, LPCWSTR seq); 
	
	// Возвращает строку с последовательностью значений
	// для зарегистрированного разряда
	static LPCWSTR GetSeq(WCHAR name); 

	virtual ~Counter(void);

private:
	// Конструктор копирования и оператор присваивания не реализуем,
	// явно запретим
	Counter(const Counter&);
	Counter &operator=(const Counter &rsh);

	// Формирует строковое представление значения счетчика в буфере m_lpStrValue
	void SetStrValue(); 

	// строка с типами разрядов
	LPCWSTR m_type;

	// разрядность
	int m_capacity;
	
    // внутренний буфер для строкового значения счетчика
	mutable WCHAR *m_lpStrValue;
	
	// разряды
	std::vector<Digit> m_digits;

    // зарегистрированные разряды
	static std::map<WCHAR, LPCWSTR> m_knownDigits;
};

#endif