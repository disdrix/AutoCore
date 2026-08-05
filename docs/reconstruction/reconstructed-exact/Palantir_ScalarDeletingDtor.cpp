// =============================================================================
// Palantir_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004447e0
// Address:   0x004447e0–0x004447FE exclusive (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    client / Palantir host scalar deleting destructor
// Generated: 2026-07-29 W35-J dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes win on ESI/this and RET 4.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004447e0
// Vtbl:      PTR_FUN_00a9f76c[0] = this; [1] = FUN_00754480 (Palantir::ResetDevice peer)
// Complete:  Palantir_CompleteDtor aa_00754320 (W34-K)
// =============================================================================
//
// PURPOSE:
//   MSVC scalar deleting destructor for Palantir:
//   run complete dtor (members + nested + globals), then free `this` iff flags&1.
//
// ABI (bytes):
//   ECX = Palantir* this   (MOV ESI,ECX)
//   stack: unsigned char flags
//   RET 4; returns this in EAX
// =============================================================================

#include <cstdint>

struct Palantir {
  void* vtbl;
  // remainder owned by complete dtor — see Palantir_CompleteDtor.cpp
};

extern "C" void __fastcall Palantir_CompleteDtor(Palantir* self); // 0x00754320
extern "C" void __cdecl operator_delete(void* p);

// Retail: ECX=this; stack flags; RET 4; returns this
extern "C" void* __thiscall Palantir_ScalarDeletingDtor(Palantir* self, unsigned char flags)
{
  Palantir_CompleteDtor(self);
  if ((flags & 1) != 0)
    operator_delete(self);
  return self;
}

// Scaffold alias (Ghidra name)
extern "C" void* __thiscall FUN_004447e0(Palantir* self, unsigned char flags)
{
  return Palantir_ScalarDeletingDtor(self, flags);
}
