setlocal ENABLEDELAYEDEXPANSION

echo #ifndef __EVENT_TYPES_HEADER__ > %2
echo #define __EVENT_TYPES_HEADER__ >> %2

for %%i in (%1\*.h) do (
	set cat=%%~ni
	set v=!cat:~0, -5!

	call %~p0\batch_utils\setvar newv cmd /c %~p0\batch_utils\uppercase !v!

	echo !newv!_EVENT,>> %2
)

echo #endif >> %2