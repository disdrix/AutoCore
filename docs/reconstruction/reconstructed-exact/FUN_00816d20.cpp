// =============================================================================
// FUN_00816d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00816d20
// Address:   0x00816d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00816d20 @ 0x00816d20
// Stable ID: aa_00816d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00816d20.
//  - Return sites: 3.

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

uint __thiscall FUN_00816d20(int *param_1,int param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  

  if (((param_3 == 40000) && (param_2 == 8)) && (param_1[0xac] != 0)) {

    iVar1 = *(int *)param_1[0xac];

    uVar2 = (**(code **)(*param_1 + 0x78))();

    uVar3 = (**(code **)(iVar1 + 0x338))(8,uVar2);

    return uVar3;

  }

  uVar3 = (**(code **)(*param_1 + 0xd8))();

  if (((char)uVar3 != '\0') && (param_1[0xac] != 0)) {

    uVar3 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar3;

  }

  return uVar3 & 0xffffff00;

}
