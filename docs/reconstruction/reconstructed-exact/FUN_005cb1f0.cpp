// =============================================================================
// FUN_005cb1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005cb1f0
// Address:   0x005cb1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005cb1f0 @ 0x005cb1f0
// Stable ID: aa_005cb1f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005c9be0×4, FUN_0040f540, FUN_00413f00, FUN_004ce940, FUN_005092b0, FUN_005cb1f0.
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

void __fastcall FUN_005cb1f0(int param_1)



{

  short sVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x10c) + 4) + -100 + param_1) + 0x3c);

  if ((iVar2 != 0) &&

     (((sVar1 = *(short *)(iVar2 + 0x3f4), sVar1 == 10 || (sVar1 == 0xb)) &&

      (iVar2 = FUN_004ce940(), iVar2 != 0)))) {

    iVar2 = FUN_005c9be0();

    if ((*(int *)(iVar2 + 4) != 0) && (*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 != 0)) {

      iVar2 = FUN_005c9be0();

      iVar2 = *(int *)(iVar2 + 8);

      iVar3 = FUN_005c9be0();

      if ((iVar2 != *(int *)(iVar3 + 4)) &&

         (iVar2 = FUN_005092b0(*(uint16_t *)(iVar2 + -4)), 0 < (short)iVar2)) {

        iVar3 = FUN_0040f540();

        FUN_00413f00(iVar3 - iVar2);

      }

    }

  }

  iVar2 = FUN_005c9be0();

  if ((*(int *)(iVar2 + 4) != 0) && (*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2 != 0)) {

    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -4;

  }

  return;

}
