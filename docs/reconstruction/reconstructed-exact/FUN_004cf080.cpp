// =============================================================================
// FUN_004cf080  (twin of Combat_RollCritMultiplier_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf080
// Address:   0x004cf080 – 0x004cf0f4  (autoassault.exe, image base 0x400000)
// System:    combat-crit
// Twin:      reconstructed-exact/Combat_RollCritMultiplier_Inferred.cpp
// Generated: 2026-07-29 W21-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern float FUN_004cef70(void *param_1, void *param_2);

// Image globals
extern float DAT_00aaa7ac;          // 100.0f @ 0x00aaa7ac
extern double _DAT_009cc1c8;        // 0.01 @ 0x009cc1c8
extern double _DAT_009cc1c0;        // ≈1.2000000476837158 @ 0x009cc1c0
extern float g_flOne;               // 1.0f @ 0x00a0f2a0

// cdecl; return ST0
float FUN_004cf080(int *param_1, uint32_t param_2, uint16_t param_3)
{
    int iVar1;
    float fVar2;

    if (param_1 != nullptr) {
        iVar1 = (**(int(__thiscall ***)(int *))(*param_1 + 0x27c))(param_1);
        fVar2 = FUN_004cef70(param_1, reinterpret_cast<void *>(param_2));
        if (static_cast<float>(static_cast<unsigned>(param_3) % 100)
            <= fVar2 * DAT_00aaa7ac) {
            return static_cast<float>(static_cast<double>(iVar1) * _DAT_009cc1c8
                                      + _DAT_009cc1c0);
        }
    }
    return g_flOne;
}
