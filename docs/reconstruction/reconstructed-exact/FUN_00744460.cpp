// =============================================================================
// FUN_00744460
// -----------------------------------------------------------------------------
// Stable ID: aa_00744460
// Address:   0x00744460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00744460 @ 0x00744460
// Stable ID: aa_00744460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00436f80, FUN_00439810, FUN_00744460, FUN_00767160.
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

void FUN_00744460(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  undefined *puVar1;

  uint uVar2;

  int unaff_EBX;

  int *piVar3;

  

  FUN_00439810();

  piVar3 = *(int **)(unaff_EBX + 0x50);

  if (piVar3 != *(int **)(unaff_EBX + 0x54)) {

    do {

      puVar1 = (undefined *)*piVar3;

      if ((undefined *)*piVar3 == (undefined *)0x0) {

        puVar1 = PTR_DAT_00afa2bc;

      }

      if (in_EAX[7] == 0) {

        uVar2 = FUN_00436f80(in_EAX,puVar1);

      }

      else {

        uVar2 = FUN_00767160(&DAT_00a9d6f8,puVar1);

        in_EAX[1] = in_EAX[1] | uVar2;

        in_EAX[8] = 0;

        uVar2 = (**(code **)(*(int *)*in_EAX + 0x18))(&DAT_00a97b84,2);

      }

      in_EAX[1] = in_EAX[1] | uVar2;

      piVar3 = piVar3 + 1;

    } while (piVar3 != *(int **)(unaff_EBX + 0x54));

  }

  return;

}
