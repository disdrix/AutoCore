// =============================================================================
// FUN_008f5870
// -----------------------------------------------------------------------------
// Stable ID: aa_008f5870
// Address:   0x008f5870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f5870 @ 0x008f5870
// Stable ID: aa_008f5870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_008f5870.
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

void FUN_008f5870(void)



{

  int *piVar1;

  int unaff_EBX;

  int iVar2;

  int iVar3;

  float fVar4;

  

  iVar2 = 0;

  fVar4 = DAT_00af9304;

  do {

    iVar3 = *(int *)(unaff_EBX + 0x508) + iVar2;

    if (0x95 < iVar3) {

      iVar3 = iVar3 + -0x96;

    }

    if (((-1 < iVar3) && (iVar3 < 0x96)) &&

       (piVar1 = *(int **)(unaff_EBX + 0xe88 + iVar3 * 4), piVar1 != (int *)0x0)) {

      if (*(int *)(*(int *)(unaff_EBX + 0x2b0) + 0x50c) == 1) {

        if ((float)piVar1[0x143] <= 0.0 && (float)piVar1[0x143] != 0.0) {

          piVar1[0x143] = (int)fVar4;

        }

      }

      else {

        if (((float)piVar1[0x143] <= fVar4 && fVar4 != (float)piVar1[0x143]) &&

           (DAT_00aaa6cc < (float)piVar1[0x143])) {

          (**(code **)(*piVar1 + 0x34c))();

          fVar4 = DAT_00af9304;

        }

        piVar1[0x143] = DAT_00aaa668;

      }

    }

  } while ((iVar3 != *(int *)(unaff_EBX + 0x50c)) && (iVar2 = iVar2 + 1, iVar2 < 0x96));

  return;

}
