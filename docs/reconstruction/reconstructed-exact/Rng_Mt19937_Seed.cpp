// =============================================================================
// Rng_Mt19937_Seed
// -----------------------------------------------------------------------------
// Stable ID: aa_00424890
// Address:   0x00424890  (autoassault.exe, image base 0x400000)
// Body:      0x00424890 – 0x004248bb
// System:    RNG / MT19937
// Generated: 2026-07-23 scaffold FUN_00424890; refined 2026-07-29 W19-A dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29 W19-A):
 * - Leaf MT19937 seed / state fill. No callees.
 * - ABI (bytes): EAX = uint32* mt base; EDX = seed written to mt[0].
 *   ECX is the loop index (1..623), not a this-pointer.
 *   Near RET (C3); zero stack args.
 * - Constant F = 0x6c078965 (1812433253) — standard MT19937 init multiplier.
 * - N = 0x270 = 624. Fill uses classic:
 *     mt[i] = F * (mt[i-1] ^ (mt[i-1] >> 30)) + i
 * - Does NOT set cursor (+0x9c0) or remaining (+0x9c4). Sibling twist
 *   Rng_Mt19937_Twist @ 0x004248c0 does that after full regeneration.
 * - Callers: FUN_007a4200 (table fill), FUN_007a42d0 (RNG ctor) — both chain
 *   seed then twist on the 0x9c8 engine block.
 *
 * Decompiler shows unused param_1 + in_EAX; clean documents EAX/EDX ABI.
 */

#include <cstdint>

static constexpr uint32_t kMtN          = 624;          // 0x270
static constexpr uint32_t kMtInitMult   = 0x6c078965u;  // 1812433253

// MSVC register ABI used by retail: mt base in EAX, seed in EDX.

void Rng_Mt19937_Seed(uint32_t* mt /* EAX */, uint32_t seed /* EDX */)
{
    int i = 1;
    *mt = seed;
    do {
        // Pointer-walk form matches bytes: write [eax+4], eax+=4, i++
        mt[1] = ((*mt >> 30) ^ *mt) * kMtInitMult + static_cast<uint32_t>(i);
        i = i + 1;
        mt = mt + 1;
    } while (i < static_cast<int>(kMtN));
    return;
}

// Index form (equivalent):
//   mt[0] = seed;
//   for (uint32_t i = 1; i < kMtN; ++i)
//       mt[i] = kMtInitMult * (mt[i-1] ^ (mt[i-1] >> 30)) + i;
