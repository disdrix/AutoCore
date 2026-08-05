// =============================================================================
// FUN_009906e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009906e0
// Address:   0x009906e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009906e0 @ 0x009906e0
// Stable ID: aa_009906e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, return×2, while×2.
//  - Notable callees: FUN_009906e0.
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

int FUN_009906e0(int param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar2 = param_2;

  puStack_8 = &LAB_009ac9e9;

  pvStack_c = ExceptionList;

  iVar7 = 0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_2 + 0x34))();

  (**(code **)(*param_2 + 0x38))();

  if (*(int *)(param_1 + 300) == 0) {

    param_2 = (int *)0x0;

  }

  else {

    param_2 = (int *)(*(int *)(param_1 + 0x130) - *(int *)(param_1 + 300) >> 3);

  }

  if (0 < (int)param_2) {

    do {

      iVar1 = *(int *)(param_1 + 300);

      iVar5 = *(int *)(*(int *)(iVar1 + 4 + iVar7 * 8) + 0x18);

      piVar3 = (int *)(**(code **)(*piVar2 + 0x38))();

      if (iVar5 == *piVar3) {

        piVar3 = (int *)(**(code **)(*piVar2 + 0x34))();

        iVar1 = *(int *)(iVar1 + iVar7 * 8 + 4);

        iVar5 = *(int *)(iVar1 + 8);

        iVar1 = *(int *)(iVar1 + 0x14);

        iVar4 = 0;

        if (0 < iVar1) {

          piVar6 = (int *)(iVar5 + 0xc);

          do {

            if (*piVar6 == *piVar3) {

              iVar5 = iVar4 * 0x10 + iVar5;

              if (iVar5 != 0) {

                ExceptionList = pvStack_c;

                return iVar5;

              }

              break;

            }

            iVar4 = iVar4 + 1;

            piVar6 = piVar6 + 4;

          } while (iVar4 < iVar1);

        }

      }

      iVar7 = iVar7 + 1;

    } while (iVar7 < (int)param_2);

  }

  ExceptionList = pvStack_c;

  return 0;

}
