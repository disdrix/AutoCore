// =============================================================================
// RefCountedPtr3Flags_DefaultCtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f530
// Address:   0x0096f530–0x0096f53f inclusive (16 B / 0x10)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared util — refcounted handle + 3 flag bytes default ctor
// Wave:      W35-G 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Default-construct an 8-byte handle shell:
//     +0..+3  pointer = nullptr
//     +4,+5,+6  three flag/status bytes = 0
//     +7        not written (padding under stride-8 hosts)
//   Peer dtor FUN_0096f510 releases *this via payload refcount / vtbl[+8].
//   Distinct from RefCountedPtr_DefaultCtor_Inferred (0x0096ef70) which only
//   nulls the pointer dword.
//
// ABI:
//   ECX = this; no stack formals; bare RET (C3); returns this in EAX.
//   Decompiler shows void — incorrect for return.
//
// BYTES:
//   8B C1 33 C9 89 08 88 48 04 88 48 05 88 48 06 C3
//
// CALLERS: 28 xrefs (CVOGTacArc_ctor, ParticleFluidPhase FUN_004c0640 ×2,
//   graphics load paths, vector_ctor of 2 elements @ FUN_00457720, …).
//
// =============================================================================

#include <cstdint>

struct RefCountedPtr3Flags {
  void*    ptr;     // +0x00
  uint8_t  flag0;   // +0x04
  uint8_t  flag1;   // +0x05
  uint8_t  flag2;   // +0x06
  // +0x07 pad (not written by this ctor)
};

// Ghidra: FUN_0096f530 / void __fastcall … — return type WRONG
extern "C" RefCountedPtr3Flags* __fastcall RefCountedPtr3Flags_DefaultCtor_Inferred(
    RefCountedPtr3Flags* self /*ECX*/)
{
  self->ptr = nullptr;
  self->flag0 = 0;
  self->flag1 = 0;
  self->flag2 = 0;
  return self; // EAX
}
