// =============================================================================
// Class_00a7000c_ScalarDeletingDtor_Inferred  (aa_00416350)
// -----------------------------------------------------------------------------
// Address:   0x00416350 – 0x0041636e exclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9I-H OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; stack flags; RET 4; returns this*
// Vtbl:      PTR_FUN_00a7000c[0] @ 0x00a7000c
// Complete:  FUN_00832fa0 (not OWN)
// =============================================================================

#include <cstdint>

// Complete dtor for class of vtbl PTR_FUN_00a7000c:
// installs *this = &PTR_FUN_00a7000c; frees owned ptr at this[0x122]; chains base.
extern "C" void __fastcall FUN_00832fa0(void* self); // 0x00832fa0 (thiscall ECX)
extern "C" void __cdecl operator_delete(void* p);

// ECX = this; stack flags; RET 4; returns this*.
// MSVC scalar-deleting destructor (vtbl[0] of PTR_FUN_00a7000c).
extern "C" void* __thiscall Class_00a7000c_ScalarDeletingDtor_Inferred(
    void* self,
    uint8_t flags)
{
  FUN_00832fa0(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}

// Scaffold / Ghidra alias
extern "C" void* __thiscall FUN_00416350(void* self, uint8_t flags)
{
  return Class_00a7000c_ScalarDeletingDtor_Inferred(self, flags);
}
