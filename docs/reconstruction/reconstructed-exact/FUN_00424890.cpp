// =============================================================================
// FUN_00424890  (legacy scaffold alias)
// -----------------------------------------------------------------------------
// Stable ID: aa_00424890
// Address:   0x00424890  (autoassault.exe, image base 0x400000)
// Body:      0x00424890 – 0x004248bb
// System:    RNG / MT19937
// Canonical: Rng_Mt19937_Seed  → see Rng_Mt19937_Seed.cpp
// Generated: 2026-07-23 scaffold; plate redirect 2026-07-29 W19-A dual A/B
// Exactness: Behavior-preserving. Prefer Rng_Mt19937_Seed.cpp for sealed body.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Legacy FUN_* scaffold kept for path stability.
 * Dual A/B sealed unit lives at:
 *   docs/reconstruction/reconstructed-exact/Rng_Mt19937_Seed.cpp
 *
 * Byte ABI: EAX = uint32* mt; EDX = seed; loop index in ECX; near RET.
 * Formula: mt[0]=seed; mt[i]=0x6c078965*(mt[i-1]^(mt[i-1]>>30))+i  for i=1..623
 */

#include <cstdint>

// Faithful decompiler-shaped surface (param_1 unused; real seed is EDX via param_2 mapping).
void __fastcall FUN_00424890(uint32_t /*unused_param1*/, uint32_t seed /*EDX*/)
{
    // in_EAX is the state base on entry (not a formal decompiler param).
    // Clean named form: Rng_Mt19937_Seed(mt /*EAX*/, seed /*EDX*/).
    // Implementation body is sealed in Rng_Mt19937_Seed.cpp — do not fork logic here.
    (void)seed;
    // NOTE: Call through Rng_Mt19937_Seed when linking; this unit is documentation alias.
}
