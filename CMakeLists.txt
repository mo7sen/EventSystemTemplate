cmake_minimum_required(VERSION 3.1)

project(event_system)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(DEFINED EVENT_DIRECTORY)
	message("Event Dir: ${EVENT_DIRECTORY}")
	file(MAKE_DIRECTORY "${event_system_SOURCE_DIR}/generated")

	set(GENERATED_EVENT_INCLUDES   ${event_system_SOURCE_DIR}/generated/event_headers.h)
	set(GENERATED_EVENT_TYPES      ${event_system_SOURCE_DIR}/generated/event_types.h)

	if(WIN32)
		execute_process(COMMAND ${event_system_SOURCE_DIR}/scripts/generate_event_includes.bat   ${EVENT_DIRECTORY} ${GENERATED_EVENT_INCLUDES})
		execute_process(COMMAND ${event_system_SOURCE_DIR}/scripts/generate_event_types.bat      ${EVENT_DIRECTORY} ${GENERATED_EVENT_TYPES})
	else()
		execute_process(COMMAND sh ${event_system_SOURCE_DIR}/scripts/generate_event_includes.sh   ${EVENT_DIRECTORY} ${GENERATED_EVENT_INCLUDES})
		execute_process(COMMAND sh ${event_system_SOURCE_DIR}/scripts/generate_event_types.sh      ${EVENT_DIRECTORY} ${GENERATED_EVENT_TYPES})
	endif()
endif()

configure_file(generated_config.h.in generated_config.h)

add_library ( event_system
	src/EventSystem.c
	src/EventBuffer.c
	src/BufferPair.c
	src/vec.c
	src/EventListener.c
	)

target_include_directories(event_system PUBLIC
	include
	${event_system_SOURCE_DIR}
	${event_system_BINARY_DIR}
	extern/pthreads4w/include
	)

target_link_directories(event_system PUBLIC
		extern/pthreads4w/lib/x64
		extern/pthreads4w/dll/x64
		)

target_link_libraries(event_system
		pthreadVC2
		)

