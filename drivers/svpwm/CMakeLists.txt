# Copyright (c) 2021 Teslabs Engineering S.L.
# SPDX-License-Identifier: Apache-2.0

zephyr_library()
#zephyr_library_sources_ifdef(CONFIG_SPINNER_SVPWM_STM32 svpwm_stm32.c)
zephyr_library_sources(svpwm_stm32.c)
