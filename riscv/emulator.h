#ifndef _EMULATOR_H
#define _EMULATOR_H

#include <stdint.h>

enum emulatorCode{
    EMU_POWEROFF,
    EMU_REBOOT,
    EMU_UNKNOWN
};

int riscv_emu();
int load_sd_file( uint32_t part, const char filename[] );

#endif