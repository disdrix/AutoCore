// =============================================================================
// FUN_0079a110  (twin of TimerHost_GetTimeFloat)
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a110
// Address:   0x0079a110 – 0x0079a116  (autoassault.exe, image base 0x400000)
// System:    timer-clock
// Twin:      reconstructed-exact/TimerHost_GetTimeFloat.cpp
// Generated: 2026-07-29 W21-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// __fastcall: ECX = param_1; return ST0
float __fastcall FUN_0079a110(int param_1)
{
    return *reinterpret_cast<float *>(param_1 + 0x238);
}
