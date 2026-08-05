// =============================================================================
// Gfx_DeviceStateCache_Clear_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00966630
// Address:   0x00966630  (autoassault.exe, image base 0x400000)
// System:    gfx / device state cache
// Generated: 2026-08-04 W38-Y OWN-ONLY dual
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Clear per-stage texture caches and host resource slots used by the
//          gfx state tracker (DAT_00d1f048). Called on successful GfxDevice_Reset
//          before republishing host[0..2] from recreated device objects.
//
// ABI: EDX = host*; ECX unused; plain RET; void; leaf.
// Body: 0x00966630–0x00966674 exclusive (68 B / 0x44).
// Twin init: FUN_00966690 (full host init + same zero block).
// Ghidra: FUN_00966630. Reject Named_CalleeOf_Named_gfxDevice_00966630.
// =============================================================================

#include <cstdint>
#include <cstring>

// Globals (image VAs — keep as extern until named duals seal them)
extern uint32_t DAT_00d0e128[16];  // per-stage texture/object cache
extern uint32_t DAT_00d0e0e8[16];  // per-stage companion cache
extern uint32_t DAT_00d1a568;
extern uint32_t DAT_00d1a564;
extern uint32_t DAT_00d1a558;
extern uint32_t DAT_00d1a55c;

// EDX = host*; no stack args
void Gfx_DeviceStateCache_Clear_Inferred(uint32_t *host)
{
  // REP STOSD × 16
  for (int i = 0; i < 16; ++i) {
    DAT_00d0e128[i] = 0;
  }
  for (int i = 0; i < 16; ++i) {
    DAT_00d0e0e8[i] = 0;
  }

  DAT_00d1a568 = 0;
  DAT_00d1a564 = 0;
  DAT_00d1a558 = 0;
  DAT_00d1a55c = 0;

  host[0] = 0;     // +0x00
  host[1] = 0;     // +0x04
  host[2] = 0;     // +0x08
  host[0xf] = 0;   // +0x3C
}
