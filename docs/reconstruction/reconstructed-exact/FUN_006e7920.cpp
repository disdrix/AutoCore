// =============================================================================
// FUN_006e7920
// -----------------------------------------------------------------------------
// Stable ID: aa_006e7920
// Address:   0x006e7920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e7920 @ 0x006e7920
// Stable ID: aa_006e7920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_006cb7d0×3, FUN_006e7920.
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

void __thiscall FUN_006e7920(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3,int *param_4)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int *piVar4;

  char *pcVar5;

  int *piVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int local_1c;

  int *local_10;

  int local_c;

  int local_8;

  int *local_4;

  

  piVar4 = param_4;

  iVar1 = *param_2;

  local_8 = param_2[2];

  local_4 = param_2;

  local_1c = 0;

  if (0 < *(int *)(param_1 + 0x10)) {

    do {

      local_10 = *(int **)(*(int *)(iVar1 + 0xc) + local_1c * 8);

      local_c = local_1c;

      pcVar5 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)piVar4[1])

                                 (&param_4,piVar4,param_3,param_2,iVar1,local_1c);

      if (*pcVar5 == '\0') {

        piVar2 = *(int **)(*(int *)(param_1 + 0xc) + local_1c * 4);

        piVar6 = (int *)FUN_006cb7d0();

        if (piVar2 != piVar6) {

          (**(code **)(*piVar2 + 0x14))();

          puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + local_1c * 4);

          uVar9 = FUN_006cb7d0();

          goto LAB_006e7a25;

        }

      }

      else {

        piVar2 = *(int **)(*(int *)(param_1 + 0xc) + local_1c * 4);

        piVar6 = (int *)FUN_006cb7d0();

        if (piVar2 == piVar6) {

          uVar9 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

          iVar3 = *piVar4;

          iVar7 = (**(code **)(*local_10 + 0x14))();

          iVar8 = (**(code **)(*(int *)*param_3 + 0x14))();

          puVar10 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + local_1c * 4);

          uVar9 = (**(code **)(iVar3 + 0x18c + (iVar7 * 0x20 + iVar8) * 4))

                            (&local_10,param_3,piVar4,uVar9);

LAB_006e7a25:

          *puVar10 = uVar9;

        }

        else {

          (**(code **)(*piVar2 + 0x1c))(&local_10,param_3,piVar4);

        }

      }

      local_1c = local_1c + 1;

    } while (local_1c < *(int *)(param_1 + 0x10));

  }

  return;

}
