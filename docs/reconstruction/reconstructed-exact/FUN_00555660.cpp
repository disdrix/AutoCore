// =============================================================================
// FUN_00555660
// -----------------------------------------------------------------------------
// Stable ID: aa_00555660
// Address:   0x00555660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00555660 @ 0x00555660
// Stable ID: aa_00555660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: CONCAT31×2, FUN_00555660.
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

uint __thiscall FUN_00555660(int param_1,int param_2,char *param_3)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  char *pcVar5;

  undefined3 uVar4;

  

  uVar2 = 0;

  if (*(int *)(param_1 + 0x434) != 0) {

    uVar2 = (*(int *)(param_1 + 0x438) - *(int *)(param_1 + 0x434)) / 0x134;

  }

  if (param_2 < (int)uVar2) {

    iVar3 = param_2 * 0x4d;

    pcVar5 = (char *)(*(int *)(param_1 + 0x434) + param_2 * 0x134);

    do {

      cVar1 = *pcVar5;

      uVar4 = (undefined3)((uint)iVar3 >> 8);

      iVar3 = CONCAT31(uVar4,cVar1);

      *param_3 = cVar1;

      pcVar5 = pcVar5 + 1;

      param_3 = param_3 + 1;

    } while (cVar1 != '\0');

    return CONCAT31(uVar4,1);

  }

  return uVar2 & 0xffffff00;

}
