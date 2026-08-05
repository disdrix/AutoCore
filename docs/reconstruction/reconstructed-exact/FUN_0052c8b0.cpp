// =============================================================================
// FUN_0052c8b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052c8b0
// Address:   0x0052c8b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052c8b0 @ 0x0052c8b0
// Stable ID: aa_0052c8b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, while×1.
//  - Notable callees: Experience_EnsureLevelTableLoaded_INFERRED×2, FUN_0052c8b0, StdMap_LowerBoundByIntKey_INFERRED.
//  - Return sites: 2.

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

uint FUN_0052c8b0(int param_1)



{

  void *pvVar1;

  int *extraout_EAX;

  int iVar2;

  uint uVar3;

  uint local_8;

  void *local_4;

  

  uVar3 = 1;

  while( true ) {

    local_8 = uVar3 & 0xffff;

    if (g_nExperienceLevelTableReady == 0) {

      Experience_EnsureLevelTableLoaded_INFERRED();

    }

    StdMap_LowerBoundByIntKey_INFERRED(&g_pExperienceLevelMap_INFERRED,&local_4,(int *)&local_8);

    pvVar1 = (void *)*extraout_EAX;

    if (g_nExperienceLevelTableReady == 0) {

      Experience_EnsureLevelTableLoaded_INFERRED();

    }

    if (pvVar1 == g_pExperienceLevelMapEnd) {

      iVar2 = 0x7fffffff;

    }

    else {

      iVar2 = *(int *)((int)pvVar1 + 0x10);

    }

    if (param_1 < iVar2) break;

    uVar3 = uVar3 + 1;

    if (0xfe < (int)uVar3) {

      return 0xff;

    }

  }

  return uVar3;

}
