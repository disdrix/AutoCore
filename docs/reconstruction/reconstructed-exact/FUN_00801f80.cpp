// =============================================================================
// FUN_00801f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00801f80
// Address:   0x00801f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00801f80 @ 0x00801f80
// Stable ID: aa_00801f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×1, while×1, for×1.
//  - Notable callees: FUN_00404840, FUN_0040fb90, FUN_00418700, FUN_00801f80, memmove.
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

void __fastcall FUN_00801f80(int param_1)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint uVar7;

  int *local_24;

  int *local_20;

  int local_1c [2];

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bb48d;

  local_c = ExceptionList;

  if ((*(int *)(param_1 + 0x3068) == 0) ||

     (local_1c[0] = *(int *)(param_1 + 0x306c) - *(int *)(param_1 + 0x3068) >> 2, local_1c[0] == 0))

  {

    return;

  }

  ExceptionList = &local_c;

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_0040fb90();

  local_10 = 0;

  local_4 = 0;

  local_20 = *(int **)(param_1 + 0x3068);

  local_14 = puVar5;

  if (local_20 != *(int **)(param_1 + 0x306c)) {

    local_24 = local_20 + 1;

    do {

      piVar1 = (int *)*local_20;

      if ((piVar1 == (int *)0x0) || (cVar4 = (**(code **)(*piVar1 + 0xd0))(), cVar4 != '\0')) {

        local_20 = local_20 + 1;

        local_24 = local_24 + 1;

      }

      else {

        memmove(local_20,local_24,(*(int *)(param_1 + 0x306c) - (int)local_24 >> 2) * 4);

        *(int *)(param_1 + 0x306c) = *(int *)(param_1 + 0x306c) + -4;

        local_1c[0] = (**(code **)(*piVar1 + 0x450))();

        iVar6 = FUN_00418700(puVar5,puVar5[1],local_1c);

        FUN_00404840(1);

        puVar5[1] = iVar6;

        **(int **)(iVar6 + 4) = iVar6;

        piVar2 = (int *)piVar1[0xac];

        cVar4 = (**(code **)(*piVar1 + 0x3d8))();

        if (cVar4 != '\0') {

          (**(code **)(*piVar1 + 0x440))();

        }

        if (piVar2 != (int *)0x0) {

          (**(code **)(*piVar2 + 0xb0))(piVar1);

        }

        (**(code **)*piVar1)(1);

        puVar5 = local_14;

      }

    } while (local_20 != *(int **)(param_1 + 0x306c));

  }

  for (puVar3 = (uint32_t /* width from decompiler */ *)*puVar5; puVar3 != puVar5; puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

    iVar6 = puVar3[2];

    uVar7 = 1 << ((byte)iVar6 & 0x1f);

    DAT_00d17920 = DAT_00d17920 | uVar7;

    DAT_00d17924 = DAT_00d17924 | (int)uVar7 >> 0x1f;

    if (iVar6 == 2) {

      DAT_00d17920 = DAT_00d17920 | 8;

    }

    else if (iVar6 == 5) {

      DAT_00d17920 = DAT_00d17920 | 0x40;

    }

  }

  local_4 = 0xffffffff;

  puVar3 = (uint32_t /* width from decompiler */ *)*puVar5;

  *puVar5 = puVar5;

  puVar5[1] = puVar5;

  local_10 = 0;

  if (puVar3 != puVar5) {

                    /* WARNING: Subroutine does not return */

    operator_delete(puVar3);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar5);

}
