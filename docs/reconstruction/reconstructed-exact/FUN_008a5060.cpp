// =============================================================================
// FUN_008a5060
// -----------------------------------------------------------------------------
// Stable ID: aa_008a5060
// Address:   0x008a5060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a5060 @ 0x008a5060
// Stable ID: aa_008a5060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×8, do×3, while×3, return×2, goto×1.
//  - Notable callees: FUN_00411900×2, CONCAT44, FUN_00402c40, FUN_00404840, FUN_0040fb90, FUN_00415e90, FUN_00418700, FUN_00574730.
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

void FUN_008a5060(int param_1)



{

  int iVar1;

  int *piVar2;

  bool bVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  longlong lVar7;

  int *local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint8_t local_18 [4];

  void *local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b6183;

  local_c = ExceptionList;

  if (((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 0xcb0) == 0)) ||

     (*(int *)(DAT_00d1b6d8 + 0x540) == 0)) {

    return;

  }

  ExceptionList = &local_c;

  FUN_008a2940();

  local_14 = (void *)FUN_0040fb90();

  local_10 = 0;

  local_4 = 0;

  local_1c = 0;

  FUN_00402c40();

  local_20 = (int *)FUN_00411900(&local_1c);

  if (local_20 != (int *)0x0) {

    do {

      piVar5 = (int *)(param_1 + 0x5d0);

      bVar3 = true;

      iVar6 = 0;

      do {

        if (!bVar3) break;

        lVar7 = FUN_00574730(iVar6);

        if ((lVar7 != -1) &&

           (iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4),

           lVar7 != CONCAT44(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + DAT_00d1b6d8),

                             *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + DAT_00d1b6d8)))) {

          piVar2 = (int *)*piVar5;

          piVar4 = (int *)*piVar2;

          if (piVar4 != piVar2) {

            do {

              if (piVar4[2] == *local_20) break;

              piVar4 = (int *)*piVar4;

            } while (piVar4 != piVar2);

            if (piVar4 != piVar2) goto LAB_008a5166;

          }

          bVar3 = false;

        }

LAB_008a5166:

        iVar6 = iVar6 + 1;

        piVar5 = piVar5 + 3;

      } while (iVar6 < 4);

      if (bVar3) {

        local_20 = (int *)*local_20;

        piVar5 = (int *)((int)local_14 + 4);

        iVar6 = FUN_00418700(local_14,*(uint32_t /* width from decompiler */ *)((int)local_14 + 4),&local_20);

        FUN_00404840(1);

        *piVar5 = iVar6;

        **(int **)(iVar6 + 4) = iVar6;

      }

      local_20 = (int *)FUN_00411900(&local_1c);

    } while (local_20 != (int *)0x0);

    local_20 = (int *)0x0;

  }

  *(uint8_t *)(*(int *)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;

  FUN_008a4900(local_18,0,0);

  FUN_008a2df0();

  local_4 = 0xffffffff;

  FUN_00415e90();

                    /* WARNING: Subroutine does not return */

  operator_delete(local_14);

}
