// =============================================================================
// FUN_00765020
// -----------------------------------------------------------------------------
// Stable ID: aa_00765020
// Address:   0x00765020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00765020 @ 0x00765020
// Stable ID: aa_00765020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1, for×1.
//  - Notable callees: FUN_00456960×2, FUN_007649c0, FUN_00765020, memmove.
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

void FUN_00765020(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *local_20;

  uint8_t local_1c [4];

  uint32_t /* width from decompiler */ *local_18;

  uint32_t /* width from decompiler */ *local_14;

  int local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b2780;

  pvStack_c = ExceptionList;

  puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  local_18 = (uint32_t /* width from decompiler */ *)0x0;

  local_14 = (uint32_t /* width from decompiler */ *)0x0;

  local_10 = 0;

  local_4 = 0;

  puVar5 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 4);

  ExceptionList = &pvStack_c;

  if (puVar5 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8)) {

    local_20 = puVar5 + 1;

    ExceptionList = &pvStack_c;

    do {

      iVar2 = (**(code **)(*(int *)*puVar5 + 4))();

      if (iVar2 == 0x47534b4e) {

        if ((puVar4 == (uint32_t /* width from decompiler */ *)0x0) ||

           ((uint)(local_10 - (int)puVar4 >> 2) <= (uint)((int)puVar3 - (int)puVar4 >> 2))) {

          FUN_00456960(puVar3);

          puVar4 = local_18;

        }

        else {

          *puVar3 = *puVar5;

          local_14 = puVar3 + 1;

        }

        puVar3 = local_14;

        memmove(puVar5,local_20,(*(int *)(unaff_ESI + 8) - (int)local_20 >> 2) * 4);

        *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -4;

      }

      else {

        puVar5 = puVar5 + 1;

        local_20 = local_20 + 1;

      }

    } while (puVar5 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8));

  }

  FUN_007649c0(local_1c,&LAB_00437a10,1);

  puVar4 = local_14;

  puVar3 = local_18;

  for (puVar5 = local_18; puVar5 != puVar4; puVar5 = puVar5 + 1) {

    iVar2 = *(int *)(unaff_ESI + 4);

    if ((iVar2 == 0) ||

       ((uint)(*(int *)(unaff_ESI + 0xc) - iVar2 >> 2) <=

        (uint)(*(int *)(unaff_ESI + 8) - iVar2 >> 2))) {

      FUN_00456960(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

    }

    else {

      puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

      *puVar1 = *puVar5;

      *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8) = puVar1 + 1;

    }

  }

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = pvStack_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(puVar3);

}
