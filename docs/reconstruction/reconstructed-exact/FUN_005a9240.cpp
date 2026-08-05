// =============================================================================
// FUN_005a9240
// -----------------------------------------------------------------------------
// Stable ID: aa_005a9240
// Address:   0x005a9240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a9240 @ 0x005a9240
// Stable ID: aa_005a9240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×10, do×2, while×2, return×1.
//  - Notable callees: FUN_004506a0×3, FUN_004507a0, FUN_005a9240.
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

void __thiscall FUN_005a9240(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  char cVar6;

  int iVar7;

  int local_8;

  int iStack_4;

  

  if (*(char *)(param_1 + 0x11c) != '\0') {

    cVar3 = *(char *)(param_1 + 0xb0);

    cVar6 = '\0';

    if ('\0' < cVar3) {

      do {

        if (((*(int *)(param_1 + 0xe8) == 0) || (cVar6 < '\0')) || (cVar3 <= cVar6)) {

          local_8 = 0;

        }

        else {

          local_8 = *(int *)(param_1 + 0xe8) + cVar6 * 0x14c;

        }

        if (local_8 != 0) {

          iVar4 = *(int *)(param_2 + 4);

          if ((iVar4 == 0) ||

             ((uint)(*(int *)(param_2 + 0xc) - iVar4 >> 2) <=

              (uint)(*(int *)(param_2 + 8) - iVar4 >> 2))) {

            FUN_004507a0(*(uint32_t /* width from decompiler */ *)(param_2 + 8),1,&local_8);

          }

          else {

            piVar2 = *(int **)(param_2 + 8);

            *piVar2 = local_8;

            *(int **)(param_2 + 8) = piVar2 + 1;

          }

        }

        cVar3 = *(char *)(param_1 + 0xb0);

        cVar6 = cVar6 + '\x01';

      } while (cVar6 < cVar3);

    }

    piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

    if ((piVar2 != (int *)0x0) && (iVar4 = (**(code **)(*piVar2 + 0x1d4))(), iVar4 != 0)) {

      iVar4 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1d4)

              )();

      local_8 = *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0xac + iVar4) + 0x3c);

      if ((*(int *)(param_1 + 0xec) != 0) && (iVar4 = 0, 0 < *(int *)(param_1 + 0xf0))) {

        iVar7 = 0;

        do {

          if (local_8 != 0) {

            uVar5 = (uint)('\0' < (char)iVar4);

            iVar1 = uVar5 + local_8;

            if (*(char *)(uVar5 + 0x680 + local_8) != '\0') {

              iStack_4 = *(int *)(param_1 + 0xec) + iVar7;

              FUN_004506a0(&iStack_4);

            }

            if (*(char *)(iVar1 + 0x682) != '\0') {

              iStack_4 = *(int *)(param_1 + 0xec) + 0x14c + iVar7;

              FUN_004506a0(&iStack_4);

              iStack_4 = *(int *)(param_1 + 0xec) + 0x298 + iVar7;

              FUN_004506a0(&iStack_4);

            }

          }

          iVar4 = iVar4 + 1;

          iVar7 = iVar7 + 0x3e4;

        } while (iVar4 < *(int *)(param_1 + 0xf0));

      }

    }

  }

  return;

}
