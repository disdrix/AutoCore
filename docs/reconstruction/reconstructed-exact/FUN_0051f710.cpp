// =============================================================================
// FUN_0051f710
// -----------------------------------------------------------------------------
// Stable ID: aa_0051f710
// Address:   0x0051f710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051f710 @ 0x0051f710
// Stable ID: aa_0051f710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0051f710, GetTickCount, ROUND.
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



int __fastcall FUN_0051f710(int param_1)



{

  DWORD DVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  

  DVar1 = GetTickCount();

  iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

  uVar5 = DVar1 - *(int *)(param_1 + 0x620);

  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

  iVar3 = (**(code **)(*(int *)(iVar3 + 4 + param_1) + 0x27c))();

  uVar4 = (10 - (int)ROUND((float)(iVar2 * iVar3) * _DAT_009ceefc)) * 60000;

  if (uVar4 < uVar5) {

    return 0;

  }

  return uVar4 - uVar5;

}
