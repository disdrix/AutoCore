// =============================================================================
// FUN_00555bf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00555bf0
// Address:   0x00555bf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00555bf0 @ 0x00555bf0
// Stable ID: aa_00555bf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×11, return×1.
//  - Notable callees: FUN_00553d20×8, FUN_00553f50×4, FUN_004b8dc0×2, FUN_00555bf0, FUN_00558eb0, ROUND.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00555bf0(int param_1,int param_2,float param_3,char param_4)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  float fVar7;

  int local_4;

  

  local_4 = param_1;

  FUN_00558eb0(&local_4,&param_4);

  iVar1 = local_4;

  cVar2 = param_4;

  if (local_4 != *(int *)(param_1 + 0x174)) {

    *(float *)(local_4 + 0x564) = param_3;

    fVar7 = (float)*(int *)(param_1 + 0x3c);

    if (*(int *)(param_1 + 0x3c) < 0) {

      fVar7 = fVar7 + _DAT_00aaa5dc;

    }

    iVar4 = (int)ROUND(fVar7 * param_3);

    *(uint *)(local_4 + 0x560) = g_dwClientTickMs - iVar4;

    if ((*(int *)(local_4 + 0x568) != param_2) && (param_2 != *(int *)(local_4 + 0x56c))) {

      iVar3 = 0;

      if (*(int *)(local_4 + 0x444) != 0) {

        iVar3 = (*(int *)(local_4 + 0x448) - *(int *)(local_4 + 0x444)) / 0x134;

      }

      if (param_2 <= iVar3 + -1) {

        *(uint8_t *)(param_1 + 0x38) = 1;

        *(uint8_t *)(local_4 + 0x55d) = 1;

        if ((((*(int *)(param_1 + 0x17c) != 0) &&

             (param_4 == *(char *)(*(int *)(param_1 + 0x17c) + 0x54c))) &&

            (*(int *)(local_4 + 0x56c) != *(int *)(local_4 + 0x568))) &&

           ((local_4 = iVar4, iVar3 = FUN_00553d20(0), iVar4 = local_4, iVar3 != 0 &&

            (iVar3 = FUN_00553d20(0), iVar4 = local_4, iVar3 != 0)))) {

          FUN_004b8dc0(0,0);

          iVar4 = local_4;

        }

        local_4 = iVar4;

        iVar4 = *(int *)(param_1 + 0x180);

        if (((iVar4 != 0) && (cVar2 == *(char *)(iVar4 + 0x54c))) &&

           ((*(int *)(iVar4 + 0x55c) != *(int *)(iVar4 + 0x558) &&

            ((iVar4 = FUN_00553d20(0), iVar4 != 0 && (iVar4 = FUN_00553d20(0), iVar4 != 0)))))) {

          FUN_004b8dc0(0,0);

        }

        *(int *)(iVar1 + 0x56c) = param_2;

        iVar1 = *(int *)(param_1 + 0x17c);

        if ((iVar1 != 0) && (cVar2 == *(char *)(iVar1 + 0x54c))) {

          if (*(int *)(iVar1 + 0x558) != *(int *)(iVar1 + 0x55c)) {

            uVar6 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x554);

            uVar5 = FUN_00553d20(0);

            FUN_00553f50(1,uVar5,uVar6);

          }

          fVar7 = g_flOne - *(float *)(*(int *)(param_1 + 0x17c) + 0x554);

          uVar6 = FUN_00553d20(0);

          FUN_00553f50(1,uVar6,fVar7);

        }

        iVar1 = *(int *)(param_1 + 0x180);

        if ((iVar1 != 0) && (cVar2 == *(char *)(iVar1 + 0x54c))) {

          if (*(int *)(iVar1 + 0x558) != *(int *)(iVar1 + 0x55c)) {

            uVar6 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x554);

            uVar5 = FUN_00553d20(0);

            FUN_00553f50(1,uVar5,uVar6);

          }

          fVar7 = g_flOne - *(float *)(*(int *)(param_1 + 0x180) + 0x554);

          uVar6 = FUN_00553d20(0);

          FUN_00553f50(1,uVar6,fVar7);

        }

      }

    }

  }

  return;

}
