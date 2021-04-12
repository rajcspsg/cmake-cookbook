cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(chapter-04-03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(sum_integers sum_integers.cpp)


option(ENABLE_UNIT_TESTS "Enable unit tests" on)
message(STATUS "Enable Testing: ${ENABLE_UNIT_TESTS}")

if(ENABLE_UNIT_TESTS)
  include(FetchContent)

  fetchcontent_declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0
  )

  fetchcontent_getproperties(googletest)

  if(NOT googletest_POPULATED)
    fetchcontent_populate(googletest)

    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    # Prevent GoogleTest from using PThreads
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

    # adds the targers: gtest, gtest_main, gmock, gmock_main
    add_subdirectory(
      ${googletest_SOURCE_DIR}
      ${googletest_BINARY_DIR}
    )

    if(MSVC)
      foreach(_tgt gtest gtest_main gmock gmock_main)
        target_compile_definitions(
          ${_tgt}
          PRIVATE
          "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
        )
      endforeach()
    endif()
  endif()


add_executable(cpp_test "")

target_sources(
  cpp_test
  PRIVATE
  test.cpp
)

target_link_libraries(
  cpp_test
  PRIVATE
  sum_integers
  gtest_main
)

enable_testing()

add_test(
  NAME google_test
  COMMAND $<TARGET_FILE:cpp_test>
)

endif()
