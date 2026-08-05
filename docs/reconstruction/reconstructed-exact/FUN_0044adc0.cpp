// =============================================================================
// FUN_0044adc0  (scaffold twin of Phy_CPConnectionPair_ReleaseClear)
// -----------------------------------------------------------------------------
// Stable ID: aa_0044adc0
// Address:   0x0044adc0 – 0x0044ae50  (autoassault.exe, image base 0x400000)
// System:    physics-cpconnection
// Twin:      reconstructed-exact/Phy_CPConnectionPair_ReleaseClear.cpp
// Generated: 2026-07-29 W22-S dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + stdcall ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern void *ExceptionList;
extern uint8_t LAB_009bcaea;
extern void FUN_00437150(int *slot);

// Ghidra name retained. Bytes: __stdcall 1 arg, ret 4.
void __stdcall FUN_0044adc0(uint32_t *param_1)
{
    int *piVar1;
    int *piVar2;
    int *piVar3;
    void *pvStack_c;
    uint8_t *puStack_8;
    uint32_t local_4;

    puStack_8 = &LAB_009bcaea;
    pvStack_c = ExceptionList;
    local_4 = 1;
    piVar1 = reinterpret_cast<int *>(param_1 + 3);
    ExceptionList = &pvStack_c;
    param_1[2] = 0;
    piVar3 = reinterpret_cast<int *>(*piVar1);
    if (piVar3 != nullptr) {
        piVar2 = piVar3 + 1;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
            // call dword ptr [eax+8] with this = obj
            reinterpret_cast<void(__thiscall *)(int *)>(*(void **)(*piVar3 + 8))(piVar3);
        }
        *piVar1 = 0;
    }
    *param_1 = 0;
    piVar3 = reinterpret_cast<int *>(param_1[1]);
    if (piVar3 != nullptr) {
        piVar2 = piVar3 + 1;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
            reinterpret_cast<void(__thiscall *)(int *)>(*(void **)(*piVar3 + 8))(piVar3);
        }
        param_1[1] = 0;
    }
    local_4 = local_4 & 0xffffff00;
    FUN_00437150(piVar1);
    local_4 = 0xffffffff;
    FUN_00437150(reinterpret_cast<int *>(param_1 + 1));
    ExceptionList = pvStack_c;
}
