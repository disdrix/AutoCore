// =============================================================================
// CNDUIWindow_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00423e50
// Address:   0x00423e50–0x00423e6d inclusive (30 B / 0x1E, autoassault.exe base 0x400000)
// System:    skills-abilities residual / UI CNDUIWindow MSVC scalar-deleting destructor
// Generated: 2026-08-05 MEGA-139 dual A/B (decompile + analyze + xrefs + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00423e50
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for CNDUIWindow primary vtbl
//   PTR_FUN_00a960ac (vtbl[0]). Always runs complete dtor FUN_007b5be0
//   (CNDUIWindow_CompleteDtor). If (flags & 1), operator_delete the host
//   heap block. Returns this in EAX. Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// TWINS / RELATED:
//   FUN_007b5be0 / CNDUIWindow_CompleteDtor — complete body (dualed WQ9K-F)
//   FUN_007b5dd0                             — ctor twin; installs same vtbl
//   RTTI .?AVCNDUIWindow@@ @ 0x00afe1b4
//   vtbl dword @ 0x00a960ac = 0x00423e50
// =============================================================================

#include <cstdint>

// Complete dtor — dualed parent aa_007b5be0 (not owned here).
extern "C" void __fastcall CNDUIWindow_CompleteDtor(void* self);
// Ghidra also labels it FUN_007b5be0:
extern "C" void __fastcall FUN_007b5be0(void* self);

extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_00423e50(void* this, uint8_t flags)
extern "C" void* __thiscall CNDUIWindow_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  FUN_007b5be0(self);  // CNDUIWindow_CompleteDtor

  if ((flags & 1u) != 0u) {
    operator_delete(self);  // @ 0x00489822; machine ADD ESP,4 after call
  }

  return self;
}
