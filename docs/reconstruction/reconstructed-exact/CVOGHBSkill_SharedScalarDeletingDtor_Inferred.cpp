// =============================================================================
// CVOGHBSkill_SharedScalarDeletingDtor_Inferred
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar deleting destructor shared as vtbl[0] across many
//           CVOGHBSkill_* subclass tables: run CVOGHBSkillBase complete dtor
//           body (via thunk), optionally operator_delete when (flags & 1).
//
// Address:  0x00651190–0x006511ae exclusive  (autoassault.exe, image base 0x400000)
// Body:     30 bytes / 0x1E
// Stable:   aa_00651190
// System:   skills-abilities
// Ghidra:   FUN_00651190
//
// ABI:      __thiscall — ECX = this; stack uint8_t flags; ret 4; EAX = this
// Complete: thunk 0x00548f90 → FUN_00578a60 (CVOGHBSkillBase complete dtor)
// Twin VA:  CVOGHBSkillBase_ScalarDeletingDtor @ 0x00578de0 (base vtbl only;
//           same pattern, different address — do not merge)
// Family:   CVOGHBBase_ScalarDeletingDtor @ 0x00508630 is the HB-base twin pattern
// Exactness: CF ≡ raw ≡ read_memory ≡ disassemble_function (R12-001).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN (Terminal false).
// Dual A/B: accept-with-gaps (2026-08-05 R12-001 seal).
// =============================================================================

#include <cstdint>

// Complete destructor body for CVOGHBSkillBase (restores PTR_FUN_009d3fdc, frees
// skill-owned fields, tails CVOGHBBase_dtor). Entered via JMP thunk 0x00548f90
// in the retail image; dual residual not owned by this VA.
extern "C" void __fastcall FUN_00578a60(void *thisHb /* ECX */);

extern "C" void __cdecl operator_delete(void *p);

/* CVOGHBSkill_SharedScalarDeletingDtor_Inferred — vtbl[0] of many skill subclasses.

   Parameters:
     thisHb: CVOGHBSkill* / CVOGHBSkillBase* layout in ECX
     flags:  bit0 = 1 → heap free via operator_delete

   Algorithm:
     1) FUN_00578a60(this)          // complete body (via 0x00548f90 thunk)
     2) if (flags & 1): operator_delete(this)
     3) return this

   Returns: this pointer (EAX)

   Notes:
     - No array-delete path (flags&2 unused).
     - No direct UNCONDITIONAL_CALL sites; entry is virtual via subclass vtbl[0]
       or computed call after push 1 (owner-null destroy).
     - Distinct from complete-body-only FUN_00578a60 (no free / no flags).
     - Distinct from base scalar 0x00578de0 (PTR_FUN_009d3fdc only).
*/

void *__thiscall CVOGHBSkill_SharedScalarDeletingDtor_Inferred(void *thisHb /* ECX */,
                                                              uint8_t flags)
{
    FUN_00578a60(thisHb);

    if ((flags & 1u) != 0) {
        operator_delete(thisHb);
    }

    return thisHb;
}
