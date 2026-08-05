// =============================================================================
// FUN_006ee680
// -----------------------------------------------------------------------------
// Stable ID: aa_006ee680
// Address:   0x006ee680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006ee680 @ 0x006ee680
// Stable ID: aa_006ee680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006ee680.
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

void FUN_006ee680(int *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  local_8 = param_1[2];

  local_4 = param_1;

  piVar1 = *(int **)(*param_1 + 0xc);

  local_c = param_1[1];

  local_10 = piVar1;

  iVar2 = (**(code **)(*(int *)*param_2 + 0x14))();

  iVar3 = (**(code **)(*piVar1 + 0x14))();

  (**(code **)(*param_3 + 0x218c + (iVar3 * 0x20 + iVar2) * 4))(&local_10,param_2,param_3,param_4);

  return;

}
