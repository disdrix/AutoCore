// =============================================================================
// FUN_008db6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008db6d0
// Address:   0x008db6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008db6d0 @ 0x008db6d0
// Stable ID: aa_008db6d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_008db6d0.
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

void FUN_008db6d0(void)



{

  int iVar1;

  float *pfVar2;

  int *piVar3;

  int unaff_ESI;

  uint8_t *puVar4;

  float fVar5;

  float fStack_40;

  int iStack_3c;

  uint8_t local_28 [4];

  uint8_t auStack_24 [12];

  uint8_t local_18 [4];

  uint8_t auStack_14 [4];

  uint8_t auStack_10 [16];

  

  if (*(char *)(unaff_ESI + 0x518) == '\0') {

    if (*(int *)(unaff_ESI + 0x52c) == 6) {

      if (*(int *)(unaff_ESI + 0x584) != 0) {

        (**(code **)(**(int **)(unaff_ESI + 0x584) + 4))(1);

      }

      if ((*(int *)(unaff_ESI + 0x580) != 0) && (*(int *)(unaff_ESI + 0x584) != 0)) {

        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))(local_18);

        fStack_40 = (float)DAT_00d1e81c * *(float *)(iVar1 + 4) * DAT_00aaa678;

        pfVar2 = (float *)(**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))(auStack_14);

        fVar5 = 1.4013e-45;

        puVar4 = auStack_10;

        piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x584) + 0x140))

                                  (puVar4,1,(float)DAT_00d1e818 * *pfVar2 * DAT_00aaa67c);

        fStack_40 = (float)((int)(float)puVar4 - *piVar3);

        iStack_3c = (int)fVar5;

        (**(code **)(**(int **)(unaff_ESI + 0x580) + 300))(&fStack_40);

      }

    }

    else {

      if (*(int *)(unaff_ESI + 0x584) != 0) {

        (**(code **)(**(int **)(unaff_ESI + 0x584) + 4))(0);

      }

      if (*(int *)(unaff_ESI + 0x580) != 0) {

        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))(local_28);

        puVar4 = auStack_24;

        pfVar2 = (float *)(**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))

                                    (puVar4,(float)DAT_00d1e81c * *(float *)(iVar1 + 4) *

                                            DAT_00aaa678);

        iStack_3c = (int)(float)puVar4;

        fStack_40 = (float)(int)((float)DAT_00d1e818 * *pfVar2 * DAT_00aaa67c);

        (**(code **)(**(int **)(unaff_ESI + 0x580) + 300))(&fStack_40);

        return;

      }

    }

  }

  else if (*(int *)(unaff_ESI + 0x584) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x584) + 4))(0);

    return;

  }

  return;

}
