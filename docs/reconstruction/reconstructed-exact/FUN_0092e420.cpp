// =============================================================================
// FUN_0092e420
// -----------------------------------------------------------------------------
// Stable ID: aa_0092e420
// Address:   0x0092e420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092e420 @ 0x0092e420
// Stable ID: aa_0092e420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0092e420.
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

void __fastcall FUN_0092e420(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  

  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xd44) != param_1)) {

    local_18[0] = 0x20b9;

    iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    local_10 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + DAT_00d1b6d8);

    local_c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + DAT_00d1b6d8);

    local_8 = (uint8_t)param_1;

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,local_18,0x18,0);

    }

  }

  return;

}
