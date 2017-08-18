// CounterTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Counter.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Counter::RegisterDigit(L'd', L"0123456789");
	Counter::RegisterDigit(L'x', L"0123456789abcdef");
	Counter::RegisterDigit(L'X', L"0123456789ABCDEF");
	Counter::RegisterDigit(L'à', L"àáâãäåæçèêëìíîïğñòóôõö÷øùúûüışÿ");
	Counter::RegisterDigit(L'À', L"ÀÁÂÃÄÅÆÇÈÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß");
	Counter::RegisterDigit(L'U', L"À1Á2Â3Ã4Ä5");

	int i;
	const int N = 1000;
	Counter counter(L"dàU");

	for(i = 0; i < N; i++) {
		counter.Inc();
	}
	assert(lstrcmp(counter.Value(), L"3çÀ") == 0);

	for(int i = 0; i < N; i++) {
		counter.Dec();
	}
	assert(lstrcmp(counter.Value(), L"0àÀ") == 0);

	return 0;
}

