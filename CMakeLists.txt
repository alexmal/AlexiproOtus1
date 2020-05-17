cmake_minimum_required(VERSION 3.12)
project(alexipro_otus_01 VERSION 0.0.$ENV{GITHUB_RUN_ID})
message($ENV{GITHUB_RUN_ID})

set(CMAKE_CXX_STANDARD 17)
#include_directories(/usr/local/Cellar/spdlog/1.5.0/include)
#include_directories(/usr/local/include)

#set(PROJECT_VERSION_PATCH 1)

find_package(SPDLog)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(otus_01_cli main.cpp)

add_library(alexipro_otus_01 lib.cpp)

add_executable(test_version test_version.cpp)

set_target_properties(otus_01_cli alexipro_otus_01 test_version PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(test_version alexipro_otus_01 ${Boost_LIBRARIES})
target_link_libraries(otus_01_cli alexipro_otus_01 pthread)

install(TARGETS otus_01_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT alexmal289@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(otus_01_test test_version)
