// =============================================================================
// FUN_00803290
// -----------------------------------------------------------------------------
// Stable ID: aa_00803290
// Address:   0x00803290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803290 @ 0x00803290
// Stable ID: aa_00803290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00803290, GetObjectA, MulDiv.
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

void __thiscall FUN_00803290(int *param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int local_3c [15];

  

  piVar2 = local_3c;

  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {

    *piVar2 = 0;

    piVar2 = piVar2 + 1;

  }

  GetObjectA((HANDLE)param_1[0x4d],0x3c,local_3c);

  local_3c[0] = MulDiv(param_2,0x60,0x48);

  local_3c[0] = -local_3c[0];

  (**(code **)(*param_1 + 0x6c))(local_3c);

  return;

}
