// =============================================================================
// GfxIndexBufferFactory_PostRestoreDevice
// -----------------------------------------------------------------------------
// Stable ID: aa_00985610
// Address:   0x00985610–0x009857fb exclusive (491 B / 0x1EB, autoassault.exe base 0x400000)
// System:    client / Palantir graphics — gfxIndexBufferFactory.cpp PostRestoreDevice
// Generated: 2026-08-04 W38-AC dual A/B (decompile + read_memory + sole-caller site)
// Exactness: Behavior-preserving contract. Bytes win on EAX this + EDI into create.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00985610
// =============================================================================
//
// PURPOSE:
//   Post-Reset recreate of hardware index buffers and restore-surface callbacks
//   for every eligible factory map entry. Product name from fail string
//   "Failed PostResoreDevice() on Index Buffers" (typo Resore → Restore).
//
// ABI (bytes + sole caller GfxDevice_Reset @ 0x0075f281):
//   EAX     = GfxIndexBufferFactory*  (MOV EAX, [EBP+0x750] before CALL)
//   RET     = plain C3
//   EAX out = 0 success / HRESULT < 0 soft-fail (from FUN_00743cd0)
//   Hard-fail path does not return (raise + ExitProcess(3))
//
// Product evidence:
//   C:\vog\1_code\palantir\palantir\graphics\gfxIndexBufferFactory.cpp
//   line 0x180: Failed PostResoreDevice() on Index Buffers
//   line 400:   RestoreSurfaceCallback Failed on Index Buffer (%d indices)
//   Parent fail string: "Failed to Reset() device on IB Factory" (gfxDevice.cpp:0x236)
// =============================================================================

#include <cstdint>

// ---------------------------------------------------------------------------
// Sealed control-flow contract (port reference)
// ---------------------------------------------------------------------------
//
// sentinel = *(factory + 0x14)
// if *sentinel == sentinel: return 0
// for (node = *sentinel; node != sentinel; node = rb_successor(node, is_nil@+0x21)):
//   if ((*(uint8_t*)(node + 0x0C) & 0x28) != 0) continue
//   for (slot = *(node+0x14); slot != *(node+0x18); slot += 0x20):
//     EDI = *(GfxDeviceIB**)slot
//     is32 = (*(int*)(EDI + 0x10) == 4)
//     hr = FUN_00743cd0(*(EDI+4), *(EDI+8), is32)   // recreate D3D IB
//     if (hr < 0):
//       code = FUN_0076d1b0(path, 0x180, "Failed PostResoreDevice() on Index Buffers")
//       if (code != 3): return hr
//       write VOGCRASH; raise(0x16); ExitProcess(3)   // noreturn
//     // callback tree at slot+8, is_nil@+0x11
//     for each cb node:
//       obj = *(void**)(host + 0x20); if obj && vtbl[0](host) < 0:
//         log RestoreSurfaceCallback fail (indices @ host+0x1c) — non-fatal
// return 0
//
// Signature (documented; EAX formal is dual-ABI):
//   int GfxIndexBufferFactory_PostRestoreDevice(GfxIndexBufferFactory* factory /*EAX*/)
// ---------------------------------------------------------------------------

using GfxIndexBufferFactory_PostRestoreDevice_Fn = int(*)(void /*EAX factory*/);
