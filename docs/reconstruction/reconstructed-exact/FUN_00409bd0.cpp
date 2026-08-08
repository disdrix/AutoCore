// =============================================================================
// FUN_00409bd0  — twin of StdSort_RanItStride16_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00409bd0
// Address:   0x00409bd0–0x00409cb9 inclusive (234 B / 0xEA)
// Canonical: StdSort_RanItStride16_Inferred
// Agent:     MEGA-043 OWN-ONLY dual 2026-08-05
// Exactness: Machine-faithful CF from live decompile; ABI sealed.
// Terminal:  false
// =============================================================================

#include <cstdint>

// Prefer the named clean source for port notes.
// This twin keeps the Ghidra symbol for inventory lockstep.

extern "C" void __cdecl FUN_00409f90(void *out_pair, int first, int last, std::uint32_t pred);
extern "C" void __cdecl FUN_0040a410(int first, int last, std::uint32_t pred);
extern "C" void __cdecl FUN_0040a820(int first, int last, std::uint32_t pred);
extern "C" void __cdecl FUN_0040a380(int first, int last, std::uint32_t pred);

// __cdecl; plain RET; stride-16 introsort (MSVC std::_Sort pattern)
extern "C" void __cdecl FUN_00409bd0(int param_1, int param_2, int param_3, std::uint32_t param_4)
{
    int iVar1;
    int local_8;
    int local_4;

    iVar1 = param_2 - param_1;
    do {
        iVar1 = iVar1 >> 4;
        if (iVar1 < 0x21) {
LAB_00409c67:
            if (1 < iVar1) {
                FUN_0040a410(param_1, param_2, param_4);
            }
            return;
        }
        if (param_3 < 1) {
            if (0x20 < iVar1) {
                if (0x10 < (int)(param_2 - param_1 & 0xfffffff0U)) {
                    FUN_0040a820(param_1, param_2, param_4);
                }
                FUN_0040a380(param_1, param_2, param_4);
                return;
            }
            goto LAB_00409c67;
        }
        FUN_00409f90(&local_8, param_1, param_2, param_4);
        iVar1 = local_4;
        param_3 = param_3 / 2 + (param_3 / 2) / 2;
        if ((int)(local_8 - param_1 & 0xfffffff0U) < (int)(param_2 - local_4 & 0xfffffff0U)) {
            FUN_00409bd0(param_1, local_8, param_3, param_4);
            param_1 = iVar1;
        } else {
            FUN_00409bd0(local_4, param_2, param_3, param_4);
            param_2 = local_8;
        }
        iVar1 = param_2 - param_1;
    } while (true);
}
