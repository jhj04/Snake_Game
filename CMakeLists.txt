cmake_minimum_required(VERSION 3.27)
project(Kookmin_Univ_Cpp_Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lncurses")

# ncurses 라이브러리 찾기
find_package(Curses REQUIRED)

# 인클루드 디렉토리 추가
include_directories(${CURSES_INCLUDE_DIR})


add_executable(Kookmin_Univ_Cpp_Project main.cpp
        include/GameMap.h
        GameMap.cpp
        Snake.cpp
        include/Snake.h)

# 실행 파일과 ncurses 라이브러리 링크
target_link_libraries(Kookmin_Univ_Cpp_Project ${CURSES_LIBRARIES})