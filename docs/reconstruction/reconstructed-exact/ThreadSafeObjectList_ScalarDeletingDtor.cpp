// =============================================================================
// ThreadSafeObjectList_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar deleting destructor for ThreadSafeObjectList (vtbl slot 0):
//           run complete dtor body, optionally operator_delete when (flags & 1).
//
// Address:  0x004bcc40–0x004bcc5d  (autoassault.exe, image base 0x400000)
// Body:     30 bytes
// Stable:   aa_004bcc40
// System:   client::util / lock-protected object list
// Ghidra:   FUN_004bcc40
//
// ABI:      __thiscall — ECX = this; stack uint8_t flags; ret 4; EAX = this
// Sibling:  ThreadSafeObjectList_Dtor @ 0x004bcbf0 (complete body, no free)
// Exactness: CF ≡ raw ≡ read_memory (W26-I 2026-07-29).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W26-I seal).
// =============================================================================

#include <cstdint>

// Complete body dual-sealed W25-C.
extern "C" void __thiscall ThreadSafeObjectList_Dtor(void *list /* ECX */);
// Ghidra: FUN_004bcbf0

extern "C" void __cdecl operator_delete(void *p);

/* ThreadSafeObjectList_ScalarDeletingDtor — vtbl[0] of PTR_FUN_009cb368.

   Parameters:
     thisList: ThreadSafeObjectList* in ECX
     flags:    bit0 = 1 → heap free via operator_delete

   Algorithm:
     1) ThreadSafeObjectList_Dtor(this)   // drain + dual CS teardown
     2) if (flags & 1): operator_delete(this)
     3) return this

   Returns: this pointer (EAX) */

void *__thiscall ThreadSafeObjectList_ScalarDeletingDtor(void *thisList /* ECX */,
                                                         uint8_t flags)
{
    ThreadSafeObjectList_Dtor(thisList);

    if ((flags & 1u) != 0) {
        operator_delete(thisList);
    }

    return thisList;
}
