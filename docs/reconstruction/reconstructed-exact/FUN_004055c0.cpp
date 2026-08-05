// =============================================================================
// FUN_004055c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004055c0
// Address:   0x004055c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004055c0 @ 0x004055c0
// Stable ID: aa_004055c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, goto×1, return×1.
//  - Notable callees: FUN_004055c0, FUN_00406560, FUN_004e2320.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004055c0; evidence only — no invented semantics):
//  - Entry: `int __thiscall FUN_004055c0(int param_1,uint *param_2)`.
//  - Branches: if (iVar2 != *(param_1 + 4)); if ((*(iVar2 + 0x14) < puVar1[1]) || ((*(iVar2 + 0x14) <= puVar1[1] && (*...).
//  - Calls: FUN_004e2320(param_2); FUN_00406560(&param_2,iVar2,&local_10).
//  - Goto: LAB_00405610.
//  - Returns (1 site(s)): `iVar2 + 0x18`.




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

int __thiscall FUN_004055c0(int param_1,uint *param_2)



{

  uint *puVar1;

  int iVar2;

  int *piVar3;

  uint local_10;

  uint local_c;

  uint32_t /* width from decompiler */ local_8;

  

  puVar1 = param_2;

  iVar2 = FUN_004e2320(param_2);

  if (iVar2 != *(int *)(param_1 + 4)) {

    if ((*(int *)(iVar2 + 0x14) < (int)puVar1[1]) ||

       ((*(int *)(iVar2 + 0x14) <= (int)puVar1[1] && (*(uint *)(iVar2 + 0x10) <= *puVar1))))

    goto LAB_00405610;

  }

  local_10 = *puVar1;

  local_c = puVar1[1];

  local_8 = 0;

  piVar3 = (int *)FUN_00406560(&param_2,iVar2,&local_10);

  iVar2 = *piVar3;

LAB_00405610:

  return iVar2 + 0x18;

}
