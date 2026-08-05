// =============================================================================
// FUN_007fdba0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fdba0
// Address:   0x007fdba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fdba0 @ 0x007fdba0
// Stable ID: aa_007fdba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_007fdba0, FUN_008f6990, FUN_008f6b70, FUN_008f6f60, FUN_008f7040.
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

void FUN_007fdba0(void)



{

  char cVar1;

  int unaff_EBX;

  int *piVar2;

  int iVar3;

  uint8_t auStack_8 [8];

  

  piVar2 = (int *)(unaff_EBX + 0x1030);

  iVar3 = 0x3a;

  do {

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 0x10c))();

    }

    piVar2 = piVar2 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  DAT_00af9210 = 0xffffffff;

  piVar2 = *(int **)(unaff_EBX + 0x109c);

  DAT_00af9214 = -1;

  if (piVar2 != (int *)0x0) {

    cVar1 = (**(code **)(*piVar2 + 0x3d8))();

    if (cVar1 != '\0') {

      if (piVar2[0x14d] != 0) {

        if (DAT_00af9214 == -1) {

          iVar3 = (**(code **)(*(int *)piVar2[0x14d] + 0x124))(auStack_8);

          DAT_00af9214 = (int)*(float *)(iVar3 + 4);

        }

        FUN_008f6990();

      }

      FUN_008f7040();

      FUN_008f6f60();

      FUN_008f6b70(piVar2);

    }

  }

  return;

}
