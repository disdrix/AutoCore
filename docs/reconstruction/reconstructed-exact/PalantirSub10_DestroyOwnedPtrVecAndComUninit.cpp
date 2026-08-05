// =============================================================================
// PalantirSub10_DestroyOwnedPtrVecAndComUninit
// -----------------------------------------------------------------------------
// Stable ID: aa_00964d00
// Address:   0x00964d00–0x00964DAA exclusive (170 B / 0xAA, autoassault.exe base 0x400000)
// System:    client / Palantir nested subobject at host+0x10
// Generated: 2026-07-29 W35-J dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes win over decompiler free/null CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00964d00
// Nest:      Palantir_CompleteDtor (aa_00754320 W34-K) calls with self = host+0x10
// =============================================================================
//
// PURPOSE:
//   Destroy the Palantir+0x10 subobject:
//   walk owned-pointer vector [begin,end), complete-dtor + free each element,
//   free the buffer, zero the triad, Release COM at +0x10, CoUninitialize,
//   zero triad again. Does not free the subobject storage itself (embedded).
//
// ABI (bytes):
//   stack self*  (stdcall)
//   RET 4 (C2 04 00); void
//   SEH LAB_009ab766
//
// Layout of subobject (relative to self = Palantir+0x10):
//   +0x00  unused in this body
//   +0x04  void** begin
//   +0x08  void** end
//   +0x0C  void** capEnd
//   +0x10  IUnknown* com  (Release @ vtbl+8)
// =============================================================================

#include <cstdint>

struct IUnknownVtbl {
  void* QueryInterface; // +0
  void* AddRef;         // +4
  std::uint32_t (__stdcall* Release)(void* self); // +8
};

struct IUnknownLite {
  IUnknownVtbl* vtbl;
};

// Element complete dtor — dual unowned (FUN_00735390).
// Observed plate: ~string@0, ~string@0x1c, helper, Release COM@0x48.
extern "C" void __stdcall FUN_00735390(void* elem);

extern "C" void __cdecl operator_delete(void* p);
extern "C" void __stdcall CoUninitialize(void);

struct PalantirSub10 {
  std::uint32_t unused0; // +0x00 — not touched
  void**        begin;   // +0x04
  void**        end;     // +0x08
  void**        capEnd;  // +0x0C
  IUnknownLite* com;     // +0x10
};

// Retail: stdcall 1-arg; RET 4; void
extern "C" void __stdcall PalantirSub10_DestroyOwnedPtrVecAndComUninit(PalantirSub10* self)
{
  void** it = self->begin;
  void** const end = self->end;
  while (it != end) {
    void* elem = *it;
    if (elem != nullptr) {
      FUN_00735390(elem);
      operator_delete(elem);
    }
    ++it;
  }

  if (self->begin != nullptr)
    operator_delete(self->begin);

  self->begin = nullptr;
  self->end = nullptr;
  self->capEnd = nullptr;

  if (self->com != nullptr)
    self->com->vtbl->Release(self->com);
  self->com = nullptr;
  CoUninitialize();

  // MSVC residual: second free of begin is dead after zero above.
  self->begin = nullptr;
  self->end = nullptr;
  self->capEnd = nullptr;
}

// Scaffold alias (Ghidra name)
extern "C" void __stdcall FUN_00964d00(PalantirSub10* self)
{
  PalantirSub10_DestroyOwnedPtrVecAndComUninit(self);
}
