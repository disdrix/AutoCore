// =============================================================================
// FUN_00966760  /  GfxStatsMonitor_RecreateResourceManagerQuery_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00966760
// Address:   0x00966760  (autoassault.exe, image base 0x400000)
// System:    graphics / gfxDevice Device Reset (Stats Monitor)
// Generated: 2026-08-04 W38-Z (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow + bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: EDI = host* (Stats Monitor at device+0x79c); plain RET; always 0.
// Body: 0x00966760–0x0096678e (47 B)
// =============================================================================

#include <cstdint>

// DAT_00d1f044 → gfx device wrapper*; *wrapper = IDirect3DDevice9*
// vtbl+0x1d8 = IDirect3DDevice9::CreateQuery
// imm 5 = D3DQUERYTYPE_RESOURCEMANAGER

extern void **DAT_00d1f044;

// Portable form (host explicit; retail uses EDI).
uint32_t FUN_00966760(void *host)
{
  void *dev = *DAT_00d1f044;
  void **vtbl = *(void ***)dev;
  auto CreateQuery = (int32_t(__stdcall *)(void *, uint32_t, void **))vtbl[0x1d8 / 4];
  void **ppQuery = (void **)((uint8_t *)host + 0x3d4);
  int32_t hr = CreateQuery(dev, 5, ppQuery);
  *((uint8_t *)host + 0x3d8) = 0;
  if (hr < 0) {
    *ppQuery = nullptr;
  }
  return 0;
}
