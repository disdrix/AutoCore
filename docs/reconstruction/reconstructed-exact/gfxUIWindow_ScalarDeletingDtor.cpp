// =============================================================================
// gfxUIWindow_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004401b0
// Address:   0x004401b0–0x004401cd inclusive (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    gfxUIWindow / MSVC scalar-deleting destructor
// Generated: 2026-08-05 MEGA-129 dual A/B (decompile + disassemble_function +
//            read_memory + RTTI COL). Exactness: behavior-preserving rewrite.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004401b0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for gfxUIWindow (vtbl[0] of PTR_FUN_00a9f304).
//   RTTI COL 0x00ab96a4 → type_info 0x00afe190 → .?AVgfxUIWindow@@.
//   Always runs complete dtor FUN_00759de0 (gfxUIWindow_CompleteDtor).
//   If (flags & 1), operator_delete the host. Returns this; ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags; ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// BODY HEX (30 B):
//   568bf1e8289c3100f644240801740956e85d96040083c4048bc65ec20400
//
// TWINS / RELATED:
//   FUN_00759de0  — gfxUIWindow_CompleteDtor (dualed WQ9L-F; no free this)
//   FUN_007b5be0  — CNDUIWindow_CompleteDtor (derived; chains into complete)
//   PTR_FUN_00a9f304[0] = this VA
// =============================================================================

#include <cstdint>

extern "C" void __thiscall FUN_00759de0(void* self);  // gfxUIWindow_CompleteDtor
extern "C" void operator_delete(void* p);             // @ 0x00489822

// Machine: void* __thiscall FUN_004401b0(void* this, uint8_t flags)
extern "C" void* __thiscall gfxUIWindow_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_00759de0(self);

  if ((flags & 1u) != 0u) {
    // push ESI; call operator_delete; add esp, 4
    operator_delete(self);
  }

  // mov eax, esi; pop esi; ret 4
  return self;
}
