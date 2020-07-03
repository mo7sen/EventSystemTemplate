cmake_minimum_required(VERSION 3.1)

project(event_system VERSION 0.1 LANGUAGES C)

if(DEFINED EVENT_DIRECTORY)

	message("Found EVENT_DIRECTORY")

	file(MAKE_DIRECTORY "${event_system_SOURCE_DIR}/generated")

	set(GENERATED_EVENT_HEADERS    ${event_system_SOURCE_DIR}/generated/event_headers.h)
	set(GENERATED_EVENT_CATEGORIES ${event_system_SOURCE_DIR}/generated/event_categories.h)
	set(GENERATED_EVENT_TYPES      ${event_system_SOURCE_DIR}/generated/event_types.h)
	set(GENERATED_EVENT_DATAS      ${event_system_SOURCE_DIR}/generated/event_datas.h)

	execute_process(COMMAND sh ${event_system_SOURCE_DIR}/scripts/generate_event_categories.sh ${EVENT_DIRECTORY} ${GENERATED_EVENT_CATEGORIES})
	execute_process(COMMAND sh ${event_system_SOURCE_DIR}/scripts/generate_event_datas.sh      ${EVENT_DIRECTORY} ${GENERATED_EVENT_DATAS})
	execute_process(COMMAND sh ${event_system_SOURCE_DIR}/scripts/generate_event_includes.sh   ${EVENT_DIRECTORY} ${GENERATED_EVENT_HEADERS})
	execute_process(COMMAND sh ${event_system_SOURCE_DIR}/scripts/generate_event_types.sh      ${EVENT_DIRECTORY} ${GENERATED_EVENT_TYPES})
else()
	message("Did not find EVENT_DIRECTORY")
endif()

configure_file(cmake_config.h.in cmake_config.h)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND EXTRA_INCLUDES 
	"include"
	"${event_system_SOURCE_DIR}"
	"${event_system_BINARY_DIR}"
)

add_library(event_system 
	"src/EventSystem.c"
)

# target_link_libraries(evol ${EXTRA_LIBS})
target_include_directories(event_system PUBLIC ${EXTRA_INCLUDES})
