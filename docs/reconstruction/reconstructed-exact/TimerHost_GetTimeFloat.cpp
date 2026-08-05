// =============================================================================
// TimerHost_GetTimeFloat
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a110
// Address:   0x0079a110 – 0x0079a116  (autoassault.exe, image base 0x400000)
// System:    timer-clock
// Twin:      reconstructed-exact/FUN_0079a110.cpp
// Callers:   34 xrefs (anim slots, turret aim, drive/update paths, …)
//            often host = DAT_00b04c74
// Generated: 2026-07-29 W21-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + ECX ABI from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Return *(float *)(host + 0x238). Pure field load; used as clock/time float.

float TimerHost_GetTimeFloat(void *host /*ECX*/)
{
    return *reinterpret_cast<float *>(reinterpret_cast<char *>(host) + 0x238);
}
