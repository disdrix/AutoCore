// =============================================================================
// CVOGHBSkillBase_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar deleting destructor for CVOGHBSkillBase (vtbl slot 0):
//           run complete dtor body, optionally operator_delete when (flags & 1).
//
// Address:  0x00578de0–0x00578dfe exclusive  (autoassault.exe, image base 0x400000)
// Body:     30 bytes / 0x1E
// Stable:   aa_00578de0
// System:   skills-abilities
// Ghidra:   FUN_00578de0
//
// ABI:      __thiscall — ECX = this; stack uint8_t flags; ret 4; EAX = this
// Sibling:  FUN_00578a60 complete dtor (no free, no flags formal; not dualed here)
// Family:   CVOGHBSkillBase_ctor @ 0x005788d0 installs PTR_FUN_009d3fdc;
//           CVOGHBBase_ScalarDeletingDtor @ 0x00508630 is the base-class twin pattern
// Exactness: CF ≡ raw ≡ read_memory ≡ disassemble_function (R11-006).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN (Terminal false).
// Dual A/B: accept (2026-08-05 R11-006 seal).
// =============================================================================

#include <cstdint>

// Complete destructor body for CVOGHBSkillBase (restores PTR_FUN_009d3fdc, frees
// owned fields, tails CVOGHBBase_dtor). Dualed separately if residual-owned.
extern "C" void __fastcall FUN_00578a60(void *thisHb /* ECX */);

extern "C" void __cdecl operator_delete(void *p);

/* CVOGHBSkillBase_ScalarDeletingDtor — vtbl[0] of PTR_FUN_009d3fdc.

   Parameters:
     thisHb: CVOGHBSkillBase* in ECX
     flags:  bit0 = 1 → heap free via operator_delete

   Algorithm:
     1) FUN_00578a60(this)          // complete body
     2) if (flags & 1): operator_delete(this)
     3) return this

   Returns: this pointer (EAX)

   Notes:
     - No array-delete path (flags&2 unused).
     - No CODE callers; entry is virtual via vtbl[0] @ 0x009d3fdc.
     - Distinct from complete-body-only FUN_00578a60 (no free / no flags).
*/

void *__thiscall CVOGHBSkillBase_ScalarDeletingDtor(void *thisHb /* ECX */, uint8_t flags)
{
    FUN_00578a60(thisHb);

    if ((flags & 1u) != 0) {
        operator_delete(thisHb);
    }

    return thisHb;
}
