// =============================================================================
// FUN_00605a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00605a50
// Address:   0x00605a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605a50 @ 0x00605a50
// Stable ID: aa_00605a50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004d5720, FUN_00605a50.
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

uint32_t /* width from decompiler */ __thiscall FUN_00605a50(int param_1,float *param_2)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  

  if (param_2 == (float *)0x0) {

    return 0;

  }

  *(uint8_t *)(param_1 + -0x18) = 1;

  iVar3 = *(int *)(*(int *)(param_1 + -0xcc) + 4) + -0x4c + param_1;

  (**(code **)((int)*param_2 + 0x14))(iVar3,0x10);

  iVar2 = *(int *)(*(int *)(param_1 + -0xcc) + 4);

  pfVar1 = (float *)(iVar2 + -0x4c + param_1);

  *pfVar1 = *(float *)(iVar2 + -0x4c + param_1) + *param_2;

  pfVar1[1] = param_2[1] + pfVar1[1];

  pfVar1[2] = param_2[2] + pfVar1[2];

  pfVar1[3] = param_2[3] + pfVar1[3];

  (**(code **)((int)*param_2 + 0x14))

            (*(int *)(*(int *)(param_1 + -0xcc) + 4) + -0x3c + param_1,0x10);

  (**(code **)((int)*param_2 + 0x14))((char *)(param_1 + -0x20),1);

  (**(code **)((int)*param_2 + 0x14))((int *)(param_1 + -0x1c),4);

  if (6 < iVar3) {

    (**(code **)((int)*param_2 + 0x14))(*(int *)(*(int *)(param_1 + -0xcc) + 4) + -0xbc + param_1,4)

    ;

  }

  if ((*(char *)(param_1 + -0x20) == '\x05') &&

     (iVar3 = *(int *)(param_1 + -0x1c), DAT_00af48c4 <= iVar3)) {

    DAT_00af48c4 = iVar3 + 1;

  }

  if (*(int *)(*(int *)(*(int *)(param_1 + -0xcc) + 4) + -0x28 + param_1) != 0) {

    FUN_004d5720(param_1 + -0xd0);

  }

  return 1;

}
