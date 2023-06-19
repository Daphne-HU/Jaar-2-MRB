# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/daphne/esp/esp-idf/components/bootloader/subproject"
  "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader"
  "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader-prefix"
  "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader-prefix/tmp"
  "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader-prefix/src"
  "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/daphne/Documents/HU/Jaar-2-periode-4/MRB/MRB-git/Jaar-2-MRB/Eindopdacht/Eindopdacht_versie_1/hello_world/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
