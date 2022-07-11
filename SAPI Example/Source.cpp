#define _ATL_APARTMENT_THREADED

#pragma warning(disable : 4996)

#include <sapi.h>
#include <sphelper.h> // SPCAT_VOICES
#include <atlbase.h>

extern CComModule ComModule;

void LogLine(const char* msg)
{
	printf("%s\n", msg);
} 

int main(void) {
	ISpVoice* pVoice = NULL;

	LogLine("Beginning initialization");
	
	if (FAILED(::CoInitialize(NULL)))
		return false;

	// HRESULT hr = SpCreateBestObject(SPCAT_VOICES, L"Gender=Male", NULL, &pVoice);
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
	
	if (SUCCEEDED(hr))
	{
		LogLine("Speaking");

		hr = pVoice -> Speak(L"Hello world!", 0, NULL);
		hr = pVoice->Speak(L"A quick brown fox jumps over a lazy dog! <pitch middle = '+9'/>", SPF_IS_XML, NULL);
		
		pVoice->Release();
		pVoice = NULL;
	}

	::CoUninitialize();
	return true;
}