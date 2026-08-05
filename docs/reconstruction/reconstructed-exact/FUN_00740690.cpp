// =============================================================================
// FUN_00740690
// -----------------------------------------------------------------------------
// Stable ID: aa_00740690
// Address:   0x00740690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00740690 @ 0x00740690
// Stable ID: aa_00740690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_00740690×2, FUN_0073ff40, FUN_00740260.
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

void __thiscall FUN_00740690(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,char *param_4)



{

  int iVar1;

  int *piVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  piVar2 = param_3;

  if (1 < *(uint *)(param_4 + 0x5c)) {

    FUN_00740260(param_3,param_4);

    param_3[1] = param_3[1] + *(int *)(param_1 + 8) + 3;

    if (*param_4 != '\0') {

      *param_3 = *param_3 + *(int *)(param_1 + 0xc);

      iVar5 = 0;

      if ((*(int *)(param_4 + 0x40) != 0) &&

         (iVar4 = *(int *)(param_4 + 0x44) - *(int *)(param_4 + 0x40) >> 2, 0 < iVar4)) {

        if (*(uint *)(param_4 + 0x74) == 0) {

          param_3 = (int *)0x0;

        }

        else {

          param_3 = (int *)(*(uint *)(param_4 + 0x54) / *(uint *)(param_4 + 0x74));

        }

        iVar6 = *(int *)(param_4 + 0x5c);

        if (0 < iVar4) {

          do {

            iVar1 = *(int *)(*(int *)(param_4 + 0x40) + iVar5 * 4);

            FUN_00740690(param_2,piVar2,iVar1);

            if (*(uint *)(iVar1 + 0x74) == 0) {

              uVar3 = 0;

            }

            else {

              uVar3 = *(uint *)(iVar1 + 0x54) / *(uint *)(iVar1 + 0x74);

            }

            param_3 = (int *)((int)param_3 - uVar3);

            iVar6 = iVar6 - *(int *)(iVar1 + 0x5c);

            iVar5 = iVar5 + 1;

          } while (iVar5 < iVar4);

        }

        if ((int)param_3 < 0) {

          param_3 = (int *)0x0;

        }

        if (iVar6 < 0) {

          iVar6 = 0;

        }

        FUN_0073ff40(param_1,param_3,iVar6);

        piVar2[1] = piVar2[1] + *(int *)(param_1 + 8) + 3;

      }

      *piVar2 = *piVar2 - *(int *)(param_1 + 0xc);

    }

  }

  return;

}
