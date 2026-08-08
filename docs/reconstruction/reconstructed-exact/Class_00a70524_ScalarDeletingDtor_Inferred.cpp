// =============================================================================
// Class_00a70524_ScalarDeletingDtor_Inferred  (aa_004165f0)
// -----------------------------------------------------------------------------
// Address:   0x004165f0 – 0x0041660E exclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9I-J OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; stack flags; RET 4; returns this*
// Complete:  FUN_008327f0 (install PTR_FUN_00a70524, chain FUN_0082d540)
// Domain:    peer ctor FUN_00832830 loads "i_m_chatlog.xml" (UI chatlog class)
// =============================================================================

#include <cstdint>

// Complete dtor (not dualed here): sets vtbl 00a70524 then base complete.
extern "C" void __fastcall FUN_008327f0(void* self); // 0x008327f0
extern "C" void __cdecl operator_delete(void* p);

// ECX = this; stack flags; RET 4; returns this*.
// MSVC scalar-deleting destructor (vtbl[0] of PTR_FUN_00a70524).
extern "C" void* __thiscall Class_00a70524_ScalarDeletingDtor_Inferred(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_008327f0(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}

// Scaffold / Ghidra alias
extern "C" void* __thiscall FUN_004165f0(void* self, uint8_t flags)
{
  return Class_00a70524_ScalarDeletingDtor_Inferred(self, flags);
}
