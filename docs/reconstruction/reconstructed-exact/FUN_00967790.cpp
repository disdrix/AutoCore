// =============================================================================
// FUN_00967790
// -----------------------------------------------------------------------------
// Stable ID: aa_00967790
// Address:   0x00967790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00967790 @ 0x00967790
// Stable ID: aa_00967790
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×15, do×4, while×4, return×3, goto×1.
//  - Notable callees: FUN_00967790.
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

uint FUN_00967790(int param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  int local_20;

  uint local_1c;

  int *local_18;

  int local_14;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  if ((*(byte *)(param_2 + 8) & 1) != 0) {

    local_1c = 1;

LAB_009677fe:

    local_8 = 0;

    if (0 < *DAT_00d1f62c) {

      local_14 = 0;

      local_4 = 0x7c - param_1;

      local_c = (int)&DAT_00d1a56c - (int)param_2;

      local_10 = 0x28;

      piVar2 = (int *)(param_1 + 0x38);

      local_18 = param_2;

      piVar6 = DAT_00d1f62c;

      do {

        local_20 = 0;

        if (*(int *)(param_1 + 0x48) != 0) {

          iVar1 = *(int *)(param_1 + 8) + local_14;

          iVar5 = *local_18;

          iVar4 = piVar2[-4];

          if ((iVar5 < piVar2[-4]) && (iVar4 = iVar5, (*(byte *)((int)param_2 + 0x21) & 0x20) != 0))

          {

            local_1c = local_1c | 2;

          }

          if (0 < iVar4) {

            iVar5 = *piVar2 * 4;

            do {

              (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(*(int *)(iVar1 + 8) + iVar5) + 0x3c))(local_20)

              ;

              if ((*(byte *)((int)param_2 + 0x21) & 0x40) == 0) {

                piVar2[-4] = piVar2[-4] + -1;

                *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;

                *piVar2 = *piVar2 + 1;

              }

              local_20 = local_20 + 1;

              iVar5 = iVar5 + 4;

              piVar6 = DAT_00d1f62c;

            } while (local_20 < iVar4);

          }

        }

        piVar3 = local_18;

        if ((local_18[4] == 1) && (local_20 < *local_18)) {

          do {

            if (*(code **)(local_10 + (int)piVar6) != (code *)0x0) {

              (**(code **)(local_10 + (int)piVar6))(local_20);

              piVar3 = local_18;

              piVar6 = DAT_00d1f62c;

            }

            local_20 = local_20 + 1;

          } while (local_20 < *piVar3);

        }

        if (local_20 != *(int *)(local_c + (int)piVar3)) {

          if (*(int *)(DAT_00d1f05c + 4) != 0) {

            piVar3 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

            (**(code **)(*piVar3 + 0x50))

                      (piVar3,*(uint32_t /* width from decompiler */ *)(local_4 + (int)piVar2 + (int)piVar6),&local_20,

                       0xffffffff);

            piVar3 = local_18;

            piVar6 = DAT_00d1f62c;

          }

          *(int *)(local_c + (int)piVar3) = local_20;

        }

        local_14 = local_14 + 0x10;

        local_10 = local_10 + 0x2c;

        local_8 = local_8 + 1;

        local_18 = piVar3 + 1;

        piVar2 = piVar2 + 1;

      } while (local_8 < *piVar6);

    }

    return local_1c;

  }

  local_1c = 0;

  if (*(int *)(param_1 + 0x48) != 0) {

    iVar1 = 0;

    if (0 < *DAT_00d1f62c) {

      piVar2 = (int *)(param_1 + 0x28);

      do {

        if ((param_2[iVar1 + 4] == 2) && (*piVar2 < param_2[iVar1])) {

          return 0;

        }

        if ((0 < *piVar2) && (0 < param_2[iVar1])) {

          local_1c = 1;

        }

        iVar1 = iVar1 + 1;

        piVar2 = piVar2 + 1;

      } while (iVar1 < *DAT_00d1f62c);

      if (local_1c != 0) goto LAB_009677fe;

    }

  }

  return 0;

}
