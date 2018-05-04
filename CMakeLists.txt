cmake_minimum_required(VERSION 3.1)
project(CPPgame)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cppgame Sources/Creature.cpp Sources/Hero.cpp Sources/Creature_NPC.cpp Location.cpp main.cpp Sources/StupidOgre.cpp Headers/StupidOgre.h Sources/MagicSpell.cpp Headers/MagicSpell.h Sources/Fireball.cpp Headers/Fireball.h Sources/BaseHeal.cpp Headers/BaseHeal.h)
target_link_libraries(cppgame ${CURSES_LIBRARIES})