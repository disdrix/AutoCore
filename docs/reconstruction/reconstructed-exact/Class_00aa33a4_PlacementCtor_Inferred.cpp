// =============================================================================
// Class_00aa33a4_PlacementCtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00457720
// Address:   0x00457720–0x004577aa  (autoassault.exe, image base 0x400000)
// System:    host class placement ctor (HostPtrTable12 slot5, size 0x44)
// Generated: scaffold 2026-07-23 as FUN_00457720; dual A/B seal 2026-07-29 (W36-I)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement-construct a 0x44 host: primary vtbl PTR_FUN_00aa33a4, then three
//   pairs of 8-byte element arrays via eh_vector_constructor_iterator
//   (vtbl handles @ +0x14 / +0x24, RefCountedPtr3Flags @ +0x34).
//
// ABI (bytes):
//   stdcall 1 formal (self*); SEH LAB_009bca04; RET 4; returns self in EAX.
//   Body 139 B / 0x8B.
//
// CALLER:
//   FUN_0073c810 HostPtrTable12_Bootstrap_EDI slot5 @ 0x0073c99c
//   (operator_new(0x44) → this → FUN_00731130 post-init).
//
// ELEMENT CTORS (unowned except W35-G RefCountedPtr3Flags):
//   FUN_00437440 / FUN_00437450  — vtbl 00a9db18 + null ptr
//   LAB_00437630 / FUN_00437640  — vtbl 00a9da80 + null ptr
//   FUN_0096f530 / FUN_0096f510  — RefCountedPtr3Flags_DefaultCtor_Inferred
//

#include <cstdint>

extern "C" void __fastcall FUN_00437440(void* elem /*ECX*/);
extern "C" void __fastcall FUN_00437450(void* elem /*ECX*/);
extern "C" void __fastcall LAB_00437630(void* elem /*ECX*/); // leaf: vtbl 00a9da80, +4=0
extern "C" void __fastcall FUN_00437640(void* elem /*ECX*/);
extern "C" void __fastcall FUN_0096f530(void* elem /*ECX*/); // RefCountedPtr3Flags_DefaultCtor
extern "C" void __fastcall FUN_0096f510(void* elem /*ECX*/);

// MSVC eh vector ctor iterator (image import / CRT)
extern "C" void __stdcall _eh_vector_constructor_iterator_(
    void* array, uint32_t size, int count,
    void (__fastcall *ctor)(void*),
    void (__fastcall *dtor)(void*));

extern "C" void* PTR_FUN_00aa33a4; // primary vtbl

struct Class_00aa33a4 {
  void*    vtbl;           // +0x00
  uint32_t unwritten04[4]; // +0x04…+0x13  not written by this ctor
  uint8_t  pair_a9db18[16];// +0x14  2 × 8-byte
  uint8_t  pair_a9da80[16];// +0x24  2 × 8-byte
  uint8_t  pair_rcflags[16];// +0x34  2 × RefCountedPtr3Flags
}; // 0x44

// Retail: stack(self*); RET 4; return self
extern "C" Class_00aa33a4*
Class_00aa33a4_PlacementCtor_Inferred(Class_00aa33a4* self /* stack */)
{
  // SEH frame LAB_009bca04
  self->vtbl = &PTR_FUN_00aa33a4;

  _eh_vector_constructor_iterator_(
      self->pair_a9db18, 8, 2, FUN_00437440, FUN_00437450);

  _eh_vector_constructor_iterator_(
      self->pair_a9da80, 8, 2, LAB_00437630, FUN_00437640);

  _eh_vector_constructor_iterator_(
      self->pair_rcflags, 8, 2, FUN_0096f530, FUN_0096f510);

  return self;
}

// Ghidra twin symbol
extern "C" Class_00aa33a4* FUN_00457720(Class_00aa33a4* self)
{
  return Class_00aa33a4_PlacementCtor_Inferred(self);
}
