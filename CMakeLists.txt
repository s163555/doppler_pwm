# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(fade_led)

add_subdirectory(drivers)
zephyr_include_directories(include)
target_sources(app PRIVATE src/main.c)
