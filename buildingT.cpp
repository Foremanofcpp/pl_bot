#include "hthread.h"

HINTERNET hinternet, hsite, hData;
LPCWSTR UserAgent = L"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.135 Safari/537.36 Edge/12.246";
LPCWSTR HOST = L"pl120.plemiona.pl";
static TCHAR hdrs[] = _T("Content-Type: application/x-www-form-urlencoded");
int connection()
{
	hinternet = InternetOpen(
		UserAgent,
		INTERNET_OPEN_TYPE_PRECONFIG,
		NULL,
		NULL,
		0);

	hsite = InternetConnect(
		hinternet,
		HOST,
		INTERNET_DEFAULT_HTTP_PORT,
		NULL,
		NULL,
		INTERNET_SERVICE_HTTP,
		0,
		0);

	hData = HttpOpenRequest(
		hsite,
		NULL,//GET
		akcja.c_str(),
		NULL,
		NULL,
		NULL,
		INTERNET_FLAG_KEEP_CONNECTION,
		0);

	HttpSendRequest(
		hData,
		hdrs,//lpszHeaders
		-1L,//dwHeadersLength 
		NULL,//lpOptional -->use for POST
		0);
}
