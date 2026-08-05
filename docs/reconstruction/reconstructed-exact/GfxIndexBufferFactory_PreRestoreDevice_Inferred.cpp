// =============================================================================
// GfxIndexBufferFactory_PreRestoreDevice_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00985580
// Address:   0x00985580–0x00985601 exclusive (129 B / 0x81, autoassault.exe base 0x400000)
// System:    client / Palantir graphics — index-buffer factory pre-Reset teardown
// Generated: 2026-08-04 W38-AC dual A/B (decompile + read_memory + sole-caller site)
// Exactness: Behavior-preserving contract. Bytes win on EAX this + ESI into leaf.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00985580
// =============================================================================
//
// PURPOSE:
//   Device-lost / pre-Reset release of DEFAULT-pool (and related) hardware index
//   buffers owned by the index-buffer factory map. Walks factory tree @ +0x14 and
//   for each eligible node releases every gfxDeviceIB slot via FUN_00743c50
//   (unlock-all, IDirect3DIndexBuffer9::Release, clear, stats).
//
// ABI (bytes + sole caller GfxDevice_Reset @ 0x0075f0dc):
//   EAX  = GfxIndexBufferFactory*  (MOV EAX, [EBP+0x750] before CALL)
//   RET  = plain C3
//   void return (no consumer of EAX)
//
// Product pairing:
//   Twin PostRestore: GfxIndexBufferFactory_PostRestoreDevice @ 0x00985610
//   Parent cascade (shutdown): …, this, FUN_009864e0 (VB pre), …
//   Method English "PreRestoreDevice" is **Inferred** (no local string); position
//   is pre-IDirect3DDevice9::Reset resource release.
// =============================================================================

#include <cstdint>

// ---------------------------------------------------------------------------
// Sealed control-flow contract (port reference)
// ---------------------------------------------------------------------------
//
// sentinel = *(factory + 0x14)
// for (node = *sentinel; node != sentinel; node = rb_successor(node, is_nil@+0x21)):
//   if ((*(uint8_t*)(node + 0x0C) & 0x28) != 0) continue
//   for (p = *(node+0x14); p != *(node+0x18); p += 0x20):
//     ESI = *(void**)p          // GfxDeviceIB*
//     FUN_00743c50()            // ESI formal — release device resources
// return
//
// Signature (documented; EAX formal is dual-ABI, not portable MSVC thiscall):
//   void GfxIndexBufferFactory_PreRestoreDevice(GfxIndexBufferFactory* factory /*EAX*/)
// ---------------------------------------------------------------------------

// Leaf not owned here: FUN_00743c50 @ 0x00743c50 (gfxDeviceIB release).
// Alias for Ghidra name stability.
using GfxIndexBufferFactory_PreRestoreDevice_Inferred_Fn = void(*)(void /*EAX factory*/);
