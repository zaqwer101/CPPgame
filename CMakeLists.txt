cmake_minimum_required(VERSION 3.1)
project(CPPgame)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cppgame Creature.cpp Hero.cpp Creature_NPC.cpp Location.cpp main.cpp StupidOgre.cpp StupidOgre.h Core.cpp Magic/MagicSpell.cpp Magic/MagicSpell.h Magic/Fireball.cpp Magic/Fireball.h)
target_link_libraries(cppgame ${CURSES_LIBRARIES})