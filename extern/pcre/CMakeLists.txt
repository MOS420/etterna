set(PCRE_SRC
    get.c
    maketables.c
    pcre.c
    study.c)

set(PCRE_HPP
    internal.h
    pcre.h)

source_group("" FILES ${PCRE_SRC})
source_group("" FILES ${PCRE_HPP})

add_library(pcre ${PCRE_SRC})
target_include_directories(pcre PUBLIC .)