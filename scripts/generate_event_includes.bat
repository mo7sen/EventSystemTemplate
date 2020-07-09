echo #ifndef __EVENT_INCLUDES_HEADER__ > %2
echo #define __EVENT_INCLUDES_HEADER__ >> %2

for %%i in (%1\*.h) do (echo #include "%%i" >> %2)

echo #endif >> %2