#ifdef KEYHOOKLIB_EXPORTS
#define KEYHOOKLIB_API __declspec(dllexport)
#else
#define KEYHOOKLIB_API __declspec(dllimport)
#endif




BOOL KEYHOOKLIB_API WINAPI SetKeyHook(BOOL bInstall);
