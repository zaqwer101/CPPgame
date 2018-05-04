cmake_minimum_required(VERSION 3.1)
project(CPPgame)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cppgame Sources/Creatures/Creature.cpp Sources/Creatures/Hero.cpp Sources/Creatures/Creature_NPC.cpp Location.cpp main.cpp Sources/Creatures/StupidOgre.cpp Headers/Creatures/StupidOgre.h Sources/Magic/MagicSpell.cpp Headers/Magic/MagicSpell.h Sources/Magic/Fireball.cpp Headers/Magic/Fireball.h)
target_link_libraries(cppgame ${CURSES_LIBRARIES})