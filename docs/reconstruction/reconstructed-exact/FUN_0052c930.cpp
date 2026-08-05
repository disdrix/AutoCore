// =============================================================================
// FUN_0052c930
// -----------------------------------------------------------------------------
// Stable ID: aa_0052c930
// Address:   0x0052c930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052c930 @ 0x0052c930
// Stable ID: aa_0052c930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0041b1e0, FUN_0051ce00, FUN_0052c930, Map_LowerBoundFindByIntKey.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_0052c930(int param_1,int param_2,float param_3)



{

  float fVar1;

  int *unaff_EDI;

  float fVar2;

  int local_10;

  float local_c;

  uint8_t local_8 [8];

  

  Map_LowerBoundFindByIntKey((void *)(param_1 + 0xc70),&local_10,&param_2,unaff_EDI);

  fVar1 = _DAT_009cfa10;

  if (local_10 == *(int *)(param_1 + 0xc74)) {

    local_10 = param_2;

    local_c = param_3;

    FUN_0041b1e0(local_8,&local_10);

  }

  else {

    fVar2 = *(float *)(local_10 + 0x10) + param_3;

    *(float *)(local_10 + 0x10) = fVar2;

    if ((fVar1 < fVar2) && (fVar2 < g_flMsToSeconds_Inferred)) {

      FUN_0051ce00(&param_2,local_10);

      return;

    }

  }

  return;

}
