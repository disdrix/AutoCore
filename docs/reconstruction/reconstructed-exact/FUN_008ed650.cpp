// =============================================================================
// FUN_008ed650
// -----------------------------------------------------------------------------
// Stable ID: aa_008ed650
// Address:   0x008ed650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ed650 @ 0x008ed650
// Stable ID: aa_008ed650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007fca10, FUN_008ed650.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_008ed650(void)



{

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint8_t local_38;

  uint8_t local_37;

  

  FUN_007fca10();

  local_50 = 0x2061;

  if (DAT_00d1b6d8 == 0) {

    local_38 = 0;

  }

  else {

    local_38 = *(uint8_t *)(DAT_00d1b6d8 + 0x4ff);

  }

  local_40 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x548);

  local_3c = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x54c);

  local_48 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x544);

  local_37 = 0;

  local_4c = 7;

  if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

    (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,&local_50,0x50,0);

  }

  return;

}
