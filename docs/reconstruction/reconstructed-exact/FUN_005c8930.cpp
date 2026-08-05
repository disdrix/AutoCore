// =============================================================================
// FUN_005c8930
// -----------------------------------------------------------------------------
// Stable ID: aa_005c8930
// Address:   0x005c8930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c8930 @ 0x005c8930
// Stable ID: aa_005c8930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00581820, FUN_005c8930.
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

int __fastcall FUN_005c8930(int param_1)



{

  int iVar1;

  uint3 uVar3;

  int iVar2;

  

  uVar3 = (uint3)((uint)param_1 >> 8);

  if ((((*(short *)(param_1 + -0x3c) < 0) || (4 < *(short *)(param_1 + -0x3c))) ||

      (*(int *)(param_1 + -0x38) < 0)) || (0x400 < *(int *)(param_1 + -0x38))) {

    return (uint)uVar3 << 8;

  }

  iVar2 = *(int *)(param_1 + -0x34);

  if ((((-1 < iVar2) && (iVar2 < 0x801)) &&

      ((iVar1 = *(int *)(param_1 + -0x30), iVar2 <= iVar1 && ((-1 < iVar1 && (iVar1 < 0x801)))))) &&

     ((0 < *(int *)(param_1 + -0x2c) && (*(int *)(param_1 + -0x2c) < 0x401)))) {

    iVar2 = *(int *)(*(int *)(param_1 + -0xbc) + 4);

    iVar1 = *(int *)(iVar2 + -0x18 + param_1);

    if (((iVar1 == 0) || (*(char *)(iVar1 + 0x7e) == '\0')) ||

       ((((iVar2 = *(int *)(*(int *)(iVar2 + param_1 + -0x14) + 0x3c), *(int *)(iVar2 + 0x3bc) == -1

          || (*(char *)(param_1 + -0x22) != '\0')) &&

         ((*(int *)(iVar2 + 0x3c0) == -1 || (*(char *)(param_1 + -0x21) != '\0')))) &&

        ((*(int *)(iVar2 + 0x3c4) == -1 || (*(char *)(param_1 + -0x20) != '\0')))))) {

      iVar2 = FUN_00581820();

      return iVar2;

    }

  }

  return (uint)uVar3 << 8;

}
