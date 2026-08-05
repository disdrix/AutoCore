// =============================================================================
// FUN_009382d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009382d0
// Address:   0x009382d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009382d0 @ 0x009382d0
// Stable ID: aa_009382d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_009382d0.
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

void FUN_009382d0(void)



{

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4;

  uint8_t local_3;

  

  if ((DAT_00d1b6d8 != 0) && (DAT_00d1b894 != 0)) {

    local_c = *(uint32_t /* width from decompiler */ *)(DAT_00d1b894 + 0x5ec);

    local_8 = *(uint32_t /* width from decompiler */ *)(DAT_00d1b894 + 0x524);

    local_4 = *(uint8_t *)(DAT_00d1b894 + 0x528);

    local_3 = *(uint8_t *)(DAT_00d1b894 + 0x538);

    local_10 = 0x2082;

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,&local_10,0x10,0);

    }

  }

  return;

}
