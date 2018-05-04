cmake_minimum_required(VERSION 3.1)
project(CPPgame)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(cppgame Creatures/Creature.cpp Creatures/Hero.cpp Creatures/Creature_NPC.cpp Core/Location.cpp main.cpp Creatures/StupidOgre.cpp Creatures/StupidOgre.h Magic/MagicSpell.cpp Magic/MagicSpell.h Magic/Fireball.cpp Magic/Fireball.h Magic/BaseHeal.cpp Magic/BaseHeal.h)
target_link_libraries(cppgame ${CURSES_LIBRARIES})