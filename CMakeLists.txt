cmake_minimum_required(VERSION 3.10)
project(pamtest C)
include(GNUInstallDirs)

add_executable(${PROJECT_NAME}
    pamtest.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pam
    pam_misc
)

install(TARGETS pamtest DESTINATION ${CMAKE_INSTALL_BINDIR})
