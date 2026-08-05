// =============================================================================
// FUN_0068a620  (scaffold twin of StdVector_InsertOne_RebindIt_Elem28)
// -----------------------------------------------------------------------------
// Stable ID: aa_0068a620
// Address:   0x0068a620–0x0068a68a exclusive (106 B)
// Wave:      W37-AC 2026-08-04 — keeps FUN_* symbol; prefer named clean.
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_0068a1d0(void* /*where*/, uint32_t /*count*/, const void* /*value*/);

// ECX=vector*; stack outIt*, where*, value*; RET 0x0C
extern "C" void __thiscall FUN_0068a620(
    int vec,
    int* outIt,
    int where,
    uint32_t value_or_ptr)
{
    int begin = *reinterpret_cast<int*>(vec + 4);
    int index;
    if (begin != 0) {
        if ((*reinterpret_cast<int*>(vec + 8) - begin) / 0x1c != 0) {
            index = (where - begin) / 0x1c;
            goto do_insert;
        }
    }
    index = 0;
do_insert:
    FUN_0068a1d0(reinterpret_cast<void*>(where), 1u,
                 reinterpret_cast<const void*>(static_cast<uintptr_t>(value_or_ptr)));
    *outIt = index * 0x1c + *reinterpret_cast<int*>(vec + 4);
}
