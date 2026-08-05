// =============================================================================
// FUN_00508390 — scaffold alias → CVOGHBBase_dtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00508390
// Address:   0x00508390
// Canonical: CVOGHBBase_dtor  (see CVOGHBBase_dtor.cpp for authoritative clean)
// Dual A/B:  accept (2026-07-29 W21-A)
// =============================================================================

#include <cstdint>

extern "C" void *PTR_FUN_009cdab0[];
extern "C" uint32_t __thiscall FUN_005085b0(void *listMgr, void *hb);

void __fastcall CVOGHBBase_dtor(void *thisHb);

// Keep Ghidra symbol as export for xref-friendly includes.
extern "C" void __fastcall FUN_00508390(void *param_1)
{
  void *pOwner;
  void *pListMgr;

  pOwner = *reinterpret_cast<void **>(reinterpret_cast<char *>(param_1) + 0x18);
  *reinterpret_cast<void **>(param_1) = PTR_FUN_009cdab0;
  if (pOwner != nullptr) {
    pListMgr = *reinterpret_cast<void **>(reinterpret_cast<char *>(pOwner) + 0xB0);
    if (pListMgr != nullptr) {
      FUN_005085b0(pListMgr, param_1);
    }
  }
  return;
}
