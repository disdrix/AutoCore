// =============================================================================
// Rng_Mt19937_Extract
// -----------------------------------------------------------------------------
// Stable ID: aa_00424830
// Address:   0x00424830  (autoassault.exe, image base 0x400000)
// Body:      0x00424830 – 0x00424882 (exclusive end; 82 B)
// System:    RNG / MT19937
// Generated: 2026-07-23 scaffold FUN_00424830; refined 2026-07-29 W20-C dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29 W20-C):
 * - Extract one tempered uint32 from MT19937 state.
 * - ABI: EAX = Mt19937State* on entry; body uses ESI; near RET; result in EAX.
 * - if remaining(+0x9c4)==0 → Rng_Mt19937_Twist (ESI ABI sibling @ 0x004248c0).
 * - --remaining; y = *cursor++; temper; return y.
 * - Temper masks in body (0xff3a58ad / 0xffffdf8c pre-shift form) ≡ classic
 *   MT19937 (0x9d2c5680 / 0xefc60000 post-shift form); shifts 11/7/15/18.
 * - Layout shared with Twist/Seed: mt[624] @0, cursor @+0x9c0, remaining @+0x9c4,
 *   object size 0x9c8.
 * - 34 call xrefs across client RNG consumers.
 *
 * Decompiler shows in_EAX; clean documents EAX ABI explicitly.
 */

#include <cstdint>

static constexpr uint32_t kMtN = 624; // 0x270

struct Mt19937State {
    uint32_t  mt[kMtN];       // +0x000
    uint32_t* cursor;         // +0x9c0
    int32_t   remaining;      // +0x9c4
}; // 0x9c8

// Sibling: ESI state ABI; sets remaining=624, cursor=&mt[0]
void Rng_Mt19937_Twist(Mt19937State* state /* ESI */);

// MSVC register ABI used by retail: state in EAX; return tempered u32 in EAX.

uint32_t Rng_Mt19937_Extract(Mt19937State* state /* EAX */)
{
    if (state->remaining == 0) {
        Rng_Mt19937_Twist(state);
    }

    state->remaining = state->remaining - 1;
    uint32_t y = *state->cursor;
    state->cursor = state->cursor + 1;

    y ^= y >> 11;
    y ^= (y & 0xff3a58adu) << 7;
    y ^= (y & 0xffffdf8cu) << 15;
    return (y >> 18) ^ y;
}

// Equivalent textbook temper (same 32-bit result):
//   y ^= y >> 11;
//   y ^= (y << 7)  & 0x9d2c5680u;
//   y ^= (y << 15) & 0xefc60000u;
//   return y ^ (y >> 18);

// Legacy export name
uint32_t FUN_00424830(void);
