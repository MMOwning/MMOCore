# Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# file(GLOB_RECURSE sources_Custom Custom/*.cpp Custom/*.h)

set(scripts_STAT_SRCS
  Custom/npc_vip.cpp 
  Custom/cs_fake.cpp  
  Custom/cs_worldchannel.cpp  
  Custom/Congrats_on_Level.cpp
  Custom/firstnpc.cpp
  Custom/serucporter.cpp
  Custom/eventnpc.cpp
  Custom/boss_galadriel.cpp
  Custom/boss_tyranium.cpp
  Custom/boss_anna.cpp
  Custom/racechange.cpp
  Custom/Allianzboss.cpp
  Custom/hordeboss.cpp
  Custom/supportnpc.cpp
  Custom/boss_orrig.cpp
  Custom/boss_tolreos.cpp
  Custom/boss_exitares_schatten.cpp
  Custom/challenge.cpp
  Custom/dark.cpp
  Custom/boss_light.cpp
  Custom/light_hardmode.cpp
  Custom/dark2.cpp
  ${scripts_STAT_SRCS}
#  ${sources_Custom}
  Custom/Transmog/Transmogrification.h
  Custom/Transmog/Transmogrification.cpp
  Custom/Transmog/Transmogrifier.cpp
)

message("  -> Prepared: Custom")
