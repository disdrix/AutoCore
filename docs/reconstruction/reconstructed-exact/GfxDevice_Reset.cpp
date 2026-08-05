// =============================================================================
// GfxDevice_Reset
// -----------------------------------------------------------------------------
// Stable ID: aa_0075eff0
// Address:   0x0075eff0–0x0075f55f exclusive (1391 B / 0x56F, autoassault.exe base 0x400000)
// System:    client / Palantir graphics — product gfxDevice.cpp Device Reset()
// Generated: 2026-08-04 W37-N dual A/B (decompile + read_memory + sole-caller site)
// Exactness: Behavior-preserving contract. Bytes win on EAX formal + RET 12.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0075eff0
// =============================================================================
//
// PURPOSE:
//   Device-lost recovery Reset for the gfxDevice host: tear down GPU resources /
//   factories, call IDirect3DDevice9::Reset with a 14-dword present block, rebuild
//   factories and caps, publish globals. Returns 0 / -1.
//
// ABI (bytes + sole caller Palantir_ResetDevice 0x00754480):
//   EAX     = present-param seed (Palantir+8: *EAX and EAX[1] overlay local[0..1])
//   stack1  = GfxDevice*   from *[Palantir+0x28]
//   stack2  = uint32_t     from  [Palantir+0xB0]  → present local field
//   stack3  = uint8_t      from  [Palantir+5]     → present local field
//   RET 12 (C2 0C 00)
//   EAX out = 0 success / 0xFFFFFFFF failure
//
// Product evidence:
//   C:\vog\1_code\palantir\palantir\graphics\gfxDevice.cpp
//   "Beginning shutdown for Device Reset()" (line 0x1FE)
//   "Device Reset() complete" (line 0x270)
//   factory fail strings (lines 0x236..0x248)
//   D3D9 Reset / TestCooperativeLevel error strings
// =============================================================================

#include <cstdint>

// ---------------------------------------------------------------------------
// Sealed control-flow contract (port reference; not a line-by-line C port of 1391 B)
// ---------------------------------------------------------------------------
//
// account_teardown(DAT_00d1f614, device fields @ +0x2B8..)
// FUN_0075e710()
// present[14 dwords] = copy device+0x2B8
// present[0] = *EAX; present[1] from EAX[1] (order per decompile/bytes)
// present fields from stack2 / stack3
// vog_LogMessage(gfxDevice.cpp, 0x1FE, 1, "Beginning shutdown for Device Reset()")
// shutdown: FUN_00985f40, FUN_00985580, FUN_009864e0, FUN_009686e0, FUN_0073d8d0
// texture list walk @ device[0x1d5]; optional FUN_0096c8e0
// Release COM @ *(device[0x1e7]+0x3d4); FUN_0073e980; FUN_0074f0c0
// Release device[2], device[3] (default surfaces); null them
// hr = (*device)->vtbl[+0x40](device, &present)   // IDirect3DDevice9::Reset
// if (hr >= 0):
//   (*device)->vtbl[+0x14](device)
//   if FUN_00985610()<0: log IB Factory @0x236; return -1
//   if FUN_00986570()<0: log VB Factory @0x239; return -1
//   if FUN_0096e8e0(device[0x1d5])<0: log Texture Factory @0x23c; return -1
//   if FUN_00968720()<0: log gfxBufferedViews @0x23f; return -1
//   if FUN_0073d870()<0: log Effect Factory @0x242; return -1
//   if FUN_00966760()<0: log Stats Monitor @0x245; return -1
//   if FUN_0074f090()<0: log Global Effect @0x248; return -1
//   FUN_00968680(); FUN_0073be50()
//   write-back present → device+0x2B8; FUN_0075e710()
//   GetDeviceCaps hw (vtbl+0x1c → device+5); optional software caps if device[0x1df]
//   recreate surfaces vtbl+0x48 / vtbl+0xa0; device[4]=device[0xb8]
//   FUN_00966630(); publish DAT_00d1f048[0..2]; clear DAT_00d1f610 slots
//   vog_LogMessage(..., 0x270, 1, "Device Reset() complete")
//   account_rebuild; device[0x1e9]=0; return 0
// else:
//   map D3D HRESULT → FUN_0076c130(product error text)
//   hr2 = (*device)->vtbl[+0x0C](device)  // TestCooperativeLevel
//   log DEVICELOST / DEVICENOTRESET / DRIVERINTERNAL / unknown
//   return -1
//
// Signature (documented; EAX formal is dual-ABI, not portable MSVC):
//   int __stdcall GfxDevice_Reset(GfxDevice* device, uint32_t arg_b0, uint8_t flag5)
//   with live-in EAX = present seed.
// ---------------------------------------------------------------------------

// Alias for Ghidra name stability in twin FUN_0075eff0.cpp include graph.
using GfxDevice_Reset_Fn = int(__stdcall*)(void* device, uint32_t arg_b0, uint8_t flag5);
