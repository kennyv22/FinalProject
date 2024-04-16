cmake_minimum_required(VERSION 3.5)

project(FlashcardProgram)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

include_directories(include)

add_executable(FlashcardPrgram
	src/main.c
	src/forth.c
	src/flashcard.c
	src/tracking.c
	
)


enable_testing()

add_executable(FlashcardTests tests/test_flashcard.c)
target_link_libraries(FlashcardTests FlashcardProgram)

add_test(NAME FlashcardFunctionalityTest COMMAND FlashcardTests)

