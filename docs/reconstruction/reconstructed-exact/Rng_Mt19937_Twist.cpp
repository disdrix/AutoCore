// =============================================================================
// Rng_Mt19937_Twist
// -----------------------------------------------------------------------------
// Stable ID: aa_004248c0
// Address:   0x004248c0  (autoassault.exe, image base 0x400000)
// Body:      0x004248c0 – 0x00424965
// System:    RNG / MT19937
// Generated: 2026-07-23 scaffold FUN_004248c0; refined 2026-07-29 W18-K dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29 W18-K):
 * - Leaf MT19937 twist. State base in ESI (no stack args; near RET).
 * - N=624 (0x270), M=397 (0x18d), MATRIX_A=0x9908b0df.
 * - Loops: 227 (N-M) with lag +M, then 396 (M-1) with lag -(N-M), then last wrap.
 * - After twist: remaining(+0x9c4)=624, cursor(+0x9c0)=&mt[0] (=esi).
 * - Sibling extract FUN_00424830: if remaining==0 call twist; then --remaining,
 *   *cursor++, temper. Sibling init FUN_00424890: seed with 0x6c078965 ×624.
 * - Object size 0x9c8 at alloc sites (mt[624] + cursor + remaining).
 *
 * Decompiler shows unaff_ESI; clean documents ESI ABI explicitly.
 * Index form below ≡ decompiler pointer walk (including last element mt[M-1] lag).
 */

#include <cstdint>

static constexpr uint32_t kMtN     = 624;          // 0x270
static constexpr uint32_t kMtM     = 397;          // 0x18d
static constexpr uint32_t kMtNM    = kMtN - kMtM;  // 227 = 0xe3
static constexpr uint32_t kMatrixA = 0x9908b0dfu;

struct Mt19937State {
    uint32_t  mt[kMtN];       // +0x000
    uint32_t* cursor;         // +0x9c0  (set to &mt[0] after twist)
    int32_t   remaining;      // +0x9c4  (set to 624 after twist)
}; // 0x9c8

// MSVC register ABI used by retail: state in ESI.

static inline uint32_t TwistStep(uint32_t a, uint32_t b, uint32_t lag)
{
    /* Decompiler form:
     *   ((a ^ b) & 0x7ffffffe ^ a) >> 1  ^  (-(b & 1) & MATRIX_A)  ^ lag
     * ≡ classic ( (a&0x80000000)|(b&0x7fffffff) )>>1  ^ (b&1 ? MATRIX_A : 0) ^ lag
     */
    return ((((a ^ b) & 0x7ffffffeu) ^ a) >> 1)
           ^ (static_cast<uint32_t>(-(static_cast<int32_t>(b & 1))) & kMatrixA)
           ^ lag;
}

void Rng_Mt19937_Twist(Mt19937State* state /* ESI */)
{
    uint32_t* mt = state->mt;
    int i;
    uint32_t* p = mt;

    /* Loop 1: i = 0 .. N-M-1  (count 0xe3 = 227), lag +M */
    i = static_cast<int>(kMtNM);
    do {
        uint32_t* next = p + 1;
        --i;
        *p = TwistStep(*p, p[1], p[kMtM]);
        p = next;
    } while (i != 0);

    /* Loop 2: count 0x18c = 396 = M-1, lag -(N-M) */
    i = static_cast<int>(kMtM - 1);
    do {
        uint32_t* cur = p;
        p = cur + 1;
        --i;
        *cur = TwistStep(*cur, cur[1], cur[-(static_cast<int>(kMtNM))]);
    } while (i != 0);

    /* Last element mt[N-1]: couple with mt[0], lag mt[M-1]
     * Decompiler: *puVar2 = f(*puVar2, *unaff_ESI, puVar1[-0xe2])
     * with puVar2 @ mt[623], puVar1 @ mt[622] → [-0xe2] = mt[396].
     */
    *p = TwistStep(*p, mt[0], (p - 1)[-(static_cast<int>(kMtNM) - 1)]);
    /* Equivalent index form (same write):
     *   mt[kMtN - 1] = TwistStep(mt[kMtN - 1], mt[0], mt[kMtM - 1]);
     */

    state->remaining = static_cast<int32_t>(kMtN); // 0x270 @ +0x9c4
    state->cursor    = mt;                         // +0x9c0 = esi
}

// Legacy export name (ESI state)
void FUN_004248c0(void);
