// =============================================================================
// CNDUIWndBuffered_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_004293f0
// Address:   0x004293f0–0x0042940d exclusive (29 B / 0x1D, autoassault.exe base 0x400000)
// System:    skills-abilities / CNDUIWndBuffered / MSVC scalar-deleting destructor
// Generated: 2026-08-05 R10-009 dual A/B (decompile_function + analyze_function_complete
//            + read_memory + xrefs). No disassemble_bytes.
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_004293f0
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting destructor for CNDUIWndBuffered (RTTI-sealed parent class;
//   primary vtbl PTR_FUN_00a99f74 slot 0). Always runs complete dtor
//   CNDUIWndBuffered_CompleteDtor (FUN_0078ca80). If (flags & 1), operator_delete
//   the host heap block. Returns this in EAX. Epilogue ret 4.
//
// ABI:
//   __thiscall; ECX=this; stack flags (cleaned as 4 bytes); ret 4; returns this*.
//   Entry: 56 8B F1 …
//   Exit:  8B C6 5E C2 04 00
//
// PEERS:
//   FUN_0078ca80 / CNDUIWndBuffered_CompleteDtor — complete body (112 B; no free)
//   CNDUIWndBuffered_Ctor_Inferred @ 0x0078caf0
//   operator_delete @ 0x00489822
//   Derived complete caller: CWndVehicle_CompleteDtor @ 0x00834520
// =============================================================================

#include <cstdint>

extern "C" void __thiscall CNDUIWndBuffered_CompleteDtor(void* self);  // FUN_0078ca80
extern "C" void operator_delete(void* p);

// Machine: void* __thiscall FUN_004293f0(void* this, uint8_t flags)
extern "C" void* __thiscall CNDUIWndBuffered_ScalarDeletingDtor(void* self, uint8_t flags)
{
  // ESI = self (bytes: 56 8B F1)
  CNDUIWndBuffered_CompleteDtor(self);

  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }

  return self;
}
