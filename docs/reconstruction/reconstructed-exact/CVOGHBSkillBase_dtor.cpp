// =============================================================================
// CVOGHBSkillBase_dtor
// -----------------------------------------------------------------------------
// Purpose:  Complete object destructor body for CVOGHBSkillBase (non-scalar):
//           restore skill-base vtbl, free skill-owned array @ +0x6a0 and
//           pointer-vector buffer @ +0x6b0..+0x6b8, then tail to base dtor.
//           Does NOT free the CVOGHBSkillBase object itself.
//
// Address:  0x00578a60–0x00578ab2 inclusive  (autoassault.exe, image base 0x400000)
// Body:     83 bytes / 0x53
// Stable:   aa_00578a60
// System:   skills-abilities
// Ghidra:   FUN_00578a60
//
// ABI:      __thiscall — ECX = this; no stack formals; tail JMP CVOGHBBase_dtor
// Sibling:  CVOGHBSkillBase_ScalarDeletingDtor @ 0x00578de0 (vtbl[0]; flags&1 free)
// Family:   CVOGHBSkillBase_ctor @ 0x005788d0 installs PTR_FUN_009d3fdc;
//           CVOGHBBase_dtor @ 0x00508390 (base complete body, dualed);
//           Skill_HB_ClearPtrVectorAt6b0_Inferred @ 0x00578ac0 (OnEnd element walk —
//           NOT merged: this unit frees buffer only).
// Exactness: CF ≡ read_memory ≡ disassemble_function (R12-026). Decompiler
//            noreturn-delete + CALL-vs-JMP corrected below.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN (Terminal false).
// Dual A/B: accept-with-gaps (2026-08-05 R12-026 seal).
// =============================================================================

#include <cstdint>

// Skill-base vtbl installed by CVOGHBSkillBase_ctor / restored here.
// RTTI COL → ".?AVCVOGHBSkillBase@@"
extern "C" void *PTR_FUN_009d3fdc[];

// Dualed base complete dtor (vtbl → 0x009cdab0 + optional owner detach).
extern "C" void __fastcall CVOGHBBase_dtor(void *thisHb /* ECX */);

extern "C" void __cdecl operator_delete(void *p);
extern "C" void __cdecl operator_delete[](void *p);

/* CVOGHBSkillBase_dtor — complete body (non-scalar).

   Parameters:
     thisHb: CVOGHBSkillBase* in ECX

   Algorithm:
     1) Snapshot [this+0x6a0]; *this = &PTR_FUN_009d3fdc
     2) if array: operator_delete[](array); [this+0x6a0] = 0
     3) if [this+0x6b0]: operator_delete(buffer)
     4) zero [this+0x6b0], [this+0x6b4], [this+0x6b8]
     5) tail JMP CVOGHBBase_dtor(this)

   Returns: void (control transfers to base dtor)

   Notes:
     - No element teardown walk on the +0x6b0 vector (OnEnd clears elements).
     - No operator_delete(this) — that is scalar deleting dtor only.
     - CRT delete/delete[] return; do not treat as noreturn.
*/

void __fastcall CVOGHBSkillBase_dtor(void *thisHb /* ECX */)
{
    auto *base = reinterpret_cast<std::uint8_t *>(thisHb);
    void *pArr = *reinterpret_cast<void **>(base + 0x6a0);
    void *pBuf;

    *reinterpret_cast<void **>(thisHb) = PTR_FUN_009d3fdc;

    if (pArr != nullptr) {
        operator_delete[](pArr);
    }
    *reinterpret_cast<void **>(base + 0x6a0) = nullptr;

    pBuf = *reinterpret_cast<void **>(base + 0x6b0);
    if (pBuf != nullptr) {
        operator_delete(pBuf);
    }
    *reinterpret_cast<void **>(base + 0x6b0) = nullptr;
    *reinterpret_cast<void **>(base + 0x6b4) = nullptr;
    *reinterpret_cast<void **>(base + 0x6b8) = nullptr;

    // Machine: MOV ECX,ESI; JMP 0x00508390
    CVOGHBBase_dtor(thisHb);
}
