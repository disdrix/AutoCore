// =============================================================================
// GfxStatsMonitor_RecreateResourceManagerQuery_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00966760
// Address:   0x00966760  (autoassault.exe, image base 0x400000)
// System:    graphics / gfxDevice Device Reset (Stats Monitor)
// Generated: 2026-08-04 W38-Z dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler + machine bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: After IDirect3DDevice9::Reset, recreate the Stats Monitor's
// IDirect3DQuery9 of type D3DQUERYTYPE_RESOURCEMANAGER (5) into host+0x3d4,
// clear issued flag host+0x3d8, and swallow CreateQuery failure (always return 0).
//
// ABI (machine-sealed):
//   Retail: EDI = StatsMonitor host*  (parent: device+0x79c)
//   No stack formals; plain RET (c3)
//   Returns always 0 in EAX
// Body: 0x00966760–0x0096678e inclusive (47 B / 0x2F)
//
// Parent: FUN_0075eff0 Device Reset (gfxDevice.cpp); product fail string
//   "Failed to Reset() device on Stats Monitor" is unreachable (return always 0).
// Device: **DAT_00d1f044 → IDirect3DDevice9*; vtbl+0x1d8 = CreateQuery.
// =============================================================================

#include <cstdint>

// Minimal COM-shaped stubs for readability (not linked against D3D headers).
struct IDirect3DQuery9;
struct IDirect3DDevice9Vtbl {
  void *pad[0x76]; // methods 0..117
  // method index 118 @ +0x1d8
  int32_t (__stdcall *CreateQuery)(void *this_dev, uint32_t type, IDirect3DQuery9 **out_query);
};
struct IDirect3DDevice9 {
  IDirect3DDevice9Vtbl *lpVtbl;
};

// Published gfx device wrapper pointer (first field = IDirect3DDevice9*).
extern IDirect3DDevice9 **DAT_00d1f044;

// Host layout (partial):
//   +0x3d4  IDirect3DQuery9*
//   +0x3d8  uint8_t flag (cleared)

// Portable reconstruction (host explicit). Retail passes host in EDI.
uint32_t GfxStatsMonitor_RecreateResourceManagerQuery_Inferred(void *host)
{
  IDirect3DDevice9 *dev = *DAT_00d1f044;
  IDirect3DQuery9 **ppQuery = (IDirect3DQuery9 **)((uint8_t *)host + 0x3d4);
  int32_t hr = dev->lpVtbl->CreateQuery(dev, /*D3DQUERYTYPE_RESOURCEMANAGER*/ 5, ppQuery);
  *((uint8_t *)host + 0x3d8) = 0;
  if (hr < 0) {
    *ppQuery = nullptr;
  }
  return 0;
}
