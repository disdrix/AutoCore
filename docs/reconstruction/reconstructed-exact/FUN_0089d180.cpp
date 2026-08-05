// =============================================================================
// FUN_0089d180
// -----------------------------------------------------------------------------
// Stable ID: aa_0089d180
// Address:   0x0089d180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089d180 @ 0x0089d180
// Stable ID: aa_0089d180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00792490, FUN_0089d180.
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

void __fastcall FUN_0089d180(int *param_1)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ auStack_18 [2];

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar2 != '\0') && (DAT_00d1b6d8 != 0)) {

    auStack_18[0] = 0x207c;

    iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);

    uStack_10 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + DAT_00d1b6d8);

    uStack_c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + DAT_00d1b6d8);

    if (g_pSectorNetConnection_INFERRED != (void *)0x0) {

      (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 0x18))(0xffffffff,auStack_18,0x18,0);

    }

    DAT_00d1d8f4 = 1;

    DAT_00d1d8f5 = 0;

    if (DAT_00d1d8dc != (int *)0x0) {

      (**(code **)(*DAT_00d1d8dc + 4))(0);

    }

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
