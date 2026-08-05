// =============================================================================
// FUN_005131b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005131b0
// Address:   0x005131b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005131b0 @ 0x005131b0
// Stable ID: aa_005131b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00512460, FUN_005131b0, Object_GetRootRaceId.
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

void __thiscall FUN_005131b0(int *param_1,int param_2)



{

  int iVar1;

  RACE_ID_INFERRED RVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  param_1[0x2b] = param_2;

  if (param_2 != 0) {

    if (*(void **)(param_2 + 0xac) == (void *)0x0) {

      RVar2 = *(RACE_ID_INFERRED *)(param_2 + 0x10);

    }

    else {

      RVar2 = Object_GetRootRaceId(*(void **)(param_2 + 0xac));

    }

    param_1[4] = RVar2;

    FUN_00512460(RVar2);

    iVar1 = *param_1;

    uVar3 = (**(code **)(*(int *)param_1[0x2b] + 0x290))();

    (**(code **)(iVar1 + 0x294))(uVar3);

  }

  return;

}
