// =============================================================================
// CVOGHBBase_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar deleting destructor for CVOGHBBase (vtbl slot 0):
//           restore base vtbl, optionally detach from owner list manager,
//           optionally operator_delete when (flags & 1).
//
// Address:  0x00508630–0x00508667  (autoassault.exe, image base 0x400000)
// Body:     55 bytes / 0x37
// Stable:   aa_00508630
// System:   heartbeat / timed-action
// Ghidra:   FUN_00508630
//
// ABI:      __thiscall — ECX = this; stack uint8_t flags; ret 4; EAX = this
// Sibling:  CVOGHBBase_dtor @ 0x00508390 (complete body, no free, no flags)
// Exactness: CF ≡ raw ≡ read_memory. Callee this for FUN_005085b0 corrected
//            from machine (ECX=listMgr, stack=HB*) — decompiler mis-models it.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W23-Q seal).
// =============================================================================

#include <cstdint>

extern "C" void *PTR_FUN_009cdab0[];

// Dual-sealed list remove-by-key: ECX = list manager, stack = HB*.
extern "C" uint32_t __thiscall FUN_005085b0(void *listMgr /* ECX */, void *hb /* stack */);

extern "C" void __cdecl operator_delete(void *p);

/* CVOGHBBase_ScalarDeletingDtor — vtbl[0] scalar deleting dtor.

   Parameters:
     thisHb: CVOGHBBase* in ECX
     flags:  bit0 = 1 → heap free via operator_delete

   Algorithm:
     1) owner = this+0x18
     2) *this = &PTR_FUN_009cdab0  (always)
     3) if owner && *(owner+0xB0): FUN_005085b0(listMgr, this)
     4) if (flags & 1): operator_delete(this)
     5) return this

   Returns: this pointer (EAX) */

void *__thiscall CVOGHBBase_ScalarDeletingDtor(void *thisHb /* ECX */, uint8_t flags)
{
    void *pOwner;
    void *pListMgr;

    pOwner = *reinterpret_cast<void **>(reinterpret_cast<char *>(thisHb) + 0x18);
    *reinterpret_cast<void **>(thisHb) = PTR_FUN_009cdab0;

    if (pOwner != nullptr) {
        pListMgr = *reinterpret_cast<void **>(reinterpret_cast<char *>(pOwner) + 0xB0);
        if (pListMgr != nullptr) {
            // machine: push thisHb; call with ECX = pListMgr
            FUN_005085b0(pListMgr, thisHb);
        }
    }

    if ((flags & 1u) != 0) {
        operator_delete(thisHb);
    }

    return thisHb;
}
