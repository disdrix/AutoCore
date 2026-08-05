// =============================================================================
// FUN_008fc650
// -----------------------------------------------------------------------------
// Stable ID: aa_008fc650
// Address:   0x008fc650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fc650 @ 0x008fc650
// Stable ID: aa_008fc650
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_004fcd80, FUN_004fd970, FUN_008fc650, __RTDynamicCast.
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

void FUN_008fc650(void)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int unaff_ESI;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  iVar4 = 0;

  if (0 < *(int *)(unaff_ESI + 0x51c)) {

    do {

      iVar1 = *(int *)(unaff_ESI + 0x524) + iVar4;

      if ((iVar1 < *(int *)(unaff_ESI + 0x514)) &&

         (*(int *)(*(int *)(unaff_ESI + 0x600) + iVar1 * 4) != 0)) {

        iVar3 = *(int *)(unaff_ESI + 0x528) + -1;

        if (iVar1 == *(int *)(unaff_ESI + 0x52c) + -1) {

          if (iVar3 == iVar1) {

            (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x73c) + iVar4 * 4) + 0x3c8))(0);

          }

          else {

            uVar5 = 1;

LAB_008fc6cc:

            (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x73c) + iVar4 * 4) + 0x3c8))(uVar5);

          }

        }

        else {

          if (iVar3 != iVar1) {

            uVar5 = 0;

            goto LAB_008fc6cc;

          }

          (**(code **)(**(int **)(*(int *)(unaff_ESI + 0x73c) + iVar4 * 4) + 0x3c8))(1,1);

        }

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < *(int *)(unaff_ESI + 0x51c));

  }

  if (*(int *)(unaff_ESI + 0x730) != 0) {

    piVar2 = (int *)__RTDynamicCast(*(int *)(unaff_ESI + 0x730),0,

                                    &CNDUIWndBuffered::RTTI_Type_Descriptor,

                                    &CWndVehicle::RTTI_Type_Descriptor,0);

    if (piVar2[0x142] != 0) {

      FUN_004fd970(*(uint8_t *)(unaff_ESI + 0x528));

      FUN_004fcd80(0);

    }

                    /* WARNING: Could not recover jumptable at 0x008fc737. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*piVar2 + 0x34c))();

    return;

  }

  return;

}
