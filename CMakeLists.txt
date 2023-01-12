cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(mvc VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h)
file(GLOB vector_editor_cpp
 "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(mvc ${vector_editor_cpp})

set_target_properties(mvc PROPERTIES
    CMAKE_CXX_STANDARD 17
    CMAKE_CXX_STANDARD_REQUIRED ON
)
target_include_directories(mvc
    PRIVATE 
    include
    "${CMAKE_BINARY_DIR}"
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
include(CPack)
