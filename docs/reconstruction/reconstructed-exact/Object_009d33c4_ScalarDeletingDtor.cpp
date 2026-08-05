// =============================================================================
// Object_009d33c4_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00575c00
// Address:   0x00575c00  (autoassault.exe, image base 0x400000)
// Body:      0x00575c00–0x00575c1e exclusive (30 B / 0x1E)
// System:    object scalar deleting dtor (vtbl[0] of PTR_FUN_009d33c4)
// Generated: 2026-07-29 W29-H dual seal
// Exactness: Behavior-preserving rewrite from decompile + read_memory.
//            RET 4 + optional operator_delete fall-through sealed by bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
// MSVC scalar deleting destructor for derived family PTR_FUN_009d33c4.
// Calls complete dtor Object_009d33c4_CompleteDtor (FUN_00575350), then if
// (flags & 1) frees the object storage. Installed as vtbl[0].
//
// Do not merge with complete dtor or Object shared-base dtor FUN_00518ec0.

#include <cstdint>

extern "C" void __thiscall Object_009d33c4_CompleteDtor(void *self); // FUN_00575350
extern "C" void *__cdecl operator_delete(void *p);

// __thiscall; ECX=this; stack flags; returns this; RET 4
void *__thiscall Object_009d33c4_ScalarDeletingDtor(void *self, uint8_t flags)
{
  Object_009d33c4_CompleteDtor(self);
  if ((flags & 1) != 0) {
    operator_delete(self); // image fall-through (Ghidra false-noreturn)
  }
  return self;
}
