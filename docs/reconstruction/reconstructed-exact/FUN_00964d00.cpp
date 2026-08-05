// =============================================================================
// FUN_00964d00 — twin of PalantirSub10_DestroyOwnedPtrVecAndComUninit
// -----------------------------------------------------------------------------
// Stable ID: aa_00964d00
// Address:   0x00964d00–0x00964DAA exclusive (170 B)
// Wave:      W35-J 2026-07-29
// Prefer:    reconstructed-exact/PalantirSub10_DestroyOwnedPtrVecAndComUninit.cpp
// =============================================================================

#include <cstdint>

struct IUnknownVtbl {
  void* QueryInterface;
  void* AddRef;
  std::uint32_t (__stdcall* Release)(void* self);
};

struct IUnknownLite {
  IUnknownVtbl* vtbl;
};

extern "C" void __stdcall FUN_00735390(void* elem);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __stdcall CoUninitialize(void);

struct PalantirSub10 {
  std::uint32_t unused0;
  void**        begin;
  void**        end;
  void**        capEnd;
  IUnknownLite* com;
};

extern "C" void __stdcall FUN_00964d00(PalantirSub10* self)
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

  self->begin = nullptr;
  self->end = nullptr;
  self->capEnd = nullptr;
}
