cmake_minimum_required(VERSION 3.19)
project(FinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinalProject
        main.cpp
        Alec.cpp Alec.h
        NHLstats.cpp NHLstats.h
        Referee.cpp Referee.h
        Game.cpp Game.h
        Player.cpp Player.h
        Team.cpp Team.h)
