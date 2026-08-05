// =============================================================================
// LinkPair_CanonAndSort_Inferred  (FUN_006cad30)
// -----------------------------------------------------------------------------
// Stable ID: aa_006cad30
// Address:   0x006cad30  (autoassault.exe, image base 0x400000)
// Body:      0x006cad30–0x006cad7f exclusive (79 B)
// System:    phys / bind link-pair array canonicalize + sort
// Wave:      W28-Q OWN-ONLY dual (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// Pair element: two pointers (8 bytes). Sort/compare key is *(uint32_t*)(obj + 4).
// Nested qsort: FUN_006cac60 (not OWN this wave) — dual-key (a+4, b+4).

#include <cstdint>

struct LinkPair8 {
    void* a;  // +0
    void* b;  // +4
};

// FUN_006cac60 — quicksort pairs on dual key (first+4, second+4)
extern void LinkPair_QuickSort(LinkPair8* array, int lo, int hi, uint32_t unused);

static inline uint32_t Key4(void* p)
{
    return *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(p) + 4);
}

// __cdecl void
void LinkPair_CanonAndSort_Inferred(LinkPair8* array, int count)
{
    if (count == 0)
        return;

    for (int i = 0; i < count; ++i) {
        void* left = array[i].a;
        void* right = array[i].b;
        if (Key4(right) < Key4(left)) {
            array[i].a = right;
            array[i].b = left;
        }
    }

    // Machine: mov byte ptr [stack_count], 0  →  count & 0xffffff00
    uint32_t unused = static_cast<uint32_t>(count) & 0xffffff00u;
    if (count > 1)
        LinkPair_QuickSort(array, 0, count - 1, unused);
}
