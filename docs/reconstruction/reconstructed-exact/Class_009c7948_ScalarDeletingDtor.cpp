// =============================================================================
// Class_009c7948_ScalarDeletingDtor  (aa_0040d870)
// -----------------------------------------------------------------------------
// Address:   0x0040d870 – 0x0040d88e exclusive (30 B / 0x1E)
//            autoassault.exe, image base 0x400000
// Wave:      W33-A OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=this; stack flags; RET 4; returns this*
// Peer:      Class_009c7938_ScalarDeletingDtor @ 0x0040d590 (W31-E)
// Complete:  Class_009c7948_CompleteDtor @ 0x0040d890 (W32-C)
// =============================================================================

#include <cstdint>

// Derived complete (W32-C): install PTR_FUN_009c7948 then base complete 0040d820.
extern "C" void __fastcall Class_009c7948_CompleteDtor(void* self); // 0x0040d890
extern "C" void __cdecl operator_delete(void* p);

// ECX = this; stack flags; RET 4; returns this*.
// MSVC scalar-deleting destructor (vtbl[0] of PTR_FUN_009c7948).
extern "C" void* __thiscall Class_009c7948_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  Class_009c7948_CompleteDtor(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}

// Scaffold / Ghidra alias
extern "C" void* __thiscall FUN_0040d870(void* self, uint8_t flags)
{
  return Class_009c7948_ScalarDeletingDtor(self, flags);
}
