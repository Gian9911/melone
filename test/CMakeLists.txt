cmake_minimum_required(VERSION 3.5)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp CharacterTest.cpp itemTest.cpp ChestTest.cpp HeroTest.cpp minionTest.cpp)
add_executable(runCharacterTests ${TEST_SOURCE_FILES})
target_link_libraries(runCharacterTests gtest gtest_main core sfml-graphics sfml-window sfml-system)