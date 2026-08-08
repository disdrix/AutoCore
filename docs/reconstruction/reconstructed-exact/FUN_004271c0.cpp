// =============================================================================
// FUN_004271c0  (twin of StdVector_DestroyRuns_0x80_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004271c0
// Address:   0x004271c0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities / UI text-layout vector tidy
// Generated: 2026-08-05 MEGA-128 — machine twin (Ghidra name preserved)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte corrections.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Named clean: StdVector_DestroyRuns_0x80_Inferred.cpp
// Scaffold retired: Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004271c0.cpp
//
// ABI: EBX = vector*; void; RET (C3).
// Bytes: 0x004271c0–0x00427204 inclusive (69 B).
// =============================================================================

#include <cstdint>

extern void operator_delete(void*);
extern void __fastcall FUN_00426f70(void* elem /* ECX */);

// Ghidra signature is void(void); real ABI is EBX-this.
void FUN_004271c0(void)
{
    // unaff_EBX = vector shell*
    // iVar2 = begin = *(EBX+4)
    // if begin == 0: zero +4/+8/+0xC; return
    // iVar1 = end = *(EBX+8)
    // for (; begin != end; begin += 0x80) FUN_00426f70(/*ECX=begin*/)
    // operator_delete(*(void**)(EBX+4))
    // zero +4/+8/+0xC  — decompiler false-noreturn omits this; bytes seal it
    // RET

    int iVar1;
    int unaff_EBX; // real: EBX register
    int iVar2;

    iVar2 = *(int*)(unaff_EBX + 4);
    if (iVar2 == 0) {
        *(uint32_t*)(unaff_EBX + 4) = 0;
        *(uint32_t*)(unaff_EBX + 8) = 0;
        *(uint32_t*)(unaff_EBX + 0xc) = 0;
        return;
    }
    iVar1 = *(int*)(unaff_EBX + 8);
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0x80) {
        FUN_00426f70((void*)(intptr_t)iVar2); // ECX = elem
    }
    operator_delete(*(void**)(unaff_EBX + 4));
    // bytes continue (not noreturn):
    *(uint32_t*)(unaff_EBX + 4) = 0;
    *(uint32_t*)(unaff_EBX + 8) = 0;
    *(uint32_t*)(unaff_EBX + 0xc) = 0;
}
