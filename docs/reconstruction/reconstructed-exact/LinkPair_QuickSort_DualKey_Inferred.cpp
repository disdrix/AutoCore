// =============================================================================
// LinkPair_QuickSort_DualKey_Inferred  (FUN_006cac60)
// -----------------------------------------------------------------------------
// Stable ID: aa_006cac60
// Address:   0x006cac60  (autoassault.exe, image base 0x400000)
// Body:      0x006cac60–0x006cad2f exclusive (207 B / 0xCF)
// System:    phys / bind link-pair dual-key quicksort
// Wave:      W29-Q OWN-ONLY dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Left partition recurses; right partition via outer-loop tail.
//            4th arg is unused (dead pass-through from CanonAndSort).
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

struct LinkPair8 {
    void* a;  // +0
    void* b;  // +4
};

static inline uint32_t Key4(void* p)
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(p) + 4);
}

// Dual-key less: (a.key4, b.key4) < (pA, pB)  — unsigned
static inline bool PairLess(const LinkPair8& p, uint32_t pA, uint32_t pB)
{
    uint32_t a = Key4(p.a);
    if (a < pA)
        return true;
    if (a != pA)
        return false;
    return Key4(p.b) < pB;
}

static inline bool PivotLessPair(uint32_t pA, uint32_t pB, const LinkPair8& p)
{
    uint32_t a = Key4(p.a);
    if (pA < a)
        return true;
    if (pA != a)
        return false;
    return pB < Key4(p.b);
}

// __cdecl void
void LinkPair_QuickSort_DualKey_Inferred(
    LinkPair8* array,
    int lo,
    int hi,
    uint32_t unused)
{
    (void)unused;

    for (;;) {
        int mid = (lo + hi) >> 1;
        void* pivotA = array[mid].a;
        void* pivotB = array[mid].b;
        uint32_t pA = Key4(pivotA);
        uint32_t pB = Key4(pivotB);

        int i = lo;
        int j = hi;

        do {
            while (PairLess(array[i], pA, pB))
                ++i;
            while (PivotLessPair(pA, pB, array[j]))
                --j;

            if (j < i)
                break;

            if (j != i) {
                LinkPair8 tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);

        if (lo < j)
            LinkPair_QuickSort_DualKey_Inferred(array, lo, j, unused);

        lo = i;
        if (hi <= i)
            return;
        // continue outer loop with [i, hi]
    }
}
