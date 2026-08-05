// =============================================================================
// FUN_0067e3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067e3a0
// Address:   0x0067e3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067e3a0 @ 0x0067e3a0
// Stable ID: aa_0067e3a0
// Embedded strings (evidence for future rename):
//   - "Received missing packet %lu."
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
//   - "Received a packet out of sequence (%lu, expected %lu) - packet lost!"
//   - "seq %d too far out of order to keep - discarding"
//   - "Session %lu: seq %d too far out of order to keep - need to receive sequence %lu: discardin"
//   - "Session %lu: discarding duplicate packet (%lu expecting %lu)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~144 non-empty decompiler lines.
//  - Control keywords: if×18, return×4, do×2, while×2.
//  - Notable callees: FUN_0076cec0×5, vog_LogMessage×5, FUN_0067da10×2, memmove×2, FUN_0067bfa0, FUN_0067c590, FUN_0067e3a0, FUN_00680000.
//  - Strings: "Received missing packet %lu."; "seq %d too far out of order to keep - discarding"; "Session %lu: discarding duplicate packet (%lu expecting %lu)".
//  - Return sites: 4.

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

char __thiscall FUN_0067e3a0(int param_1,uint *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  uint *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int *piVar9;

  char local_11;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar4 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9871;

  local_c = ExceptionList;

  uVar2 = param_2[1];

  local_11 = '\x01';

  ExceptionList = &local_c;

  if ((*(uint *)(param_1 + 0x2a08) < uVar2) &&

     (ExceptionList = &local_c, uVar2 < *(uint *)(param_1 + 0x2a0c))) {

    puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2958);

    puVar7 = puVar8;

    if (puVar8 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x295c)) {

      do {

        puVar7 = puVar7 + 1;

        piVar9 = (int *)*puVar8;

        if ((piVar9[1] == uVar2) || ((uint)piVar9[1] < uVar2)) {

          ExceptionList = &local_c;

          memmove(puVar8,puVar7,(*(int *)(param_1 + 0x295c) - (int)puVar7 >> 2) * 4);

          *(int *)(param_1 + 0x295c) = *(int *)(param_1 + 0x295c) + -4;

          *(int *)(param_1 + 0x2a18) = *(int *)(param_1 + 0x2a18) - *(int *)(*piVar9 + 0xc);

          puVar8 = (uint32_t /* width from decompiler */ *)*piVar9;

          piVar1 = puVar8 + 5;

          *piVar1 = *piVar1 + -1;

          if (*piVar1 == 0) {

            (**(code **)*puVar8)(1);

          }

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar9);

        }

        puVar8 = puVar8 + 1;

      } while (puVar8 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x295c));

    }

    ExceptionList = &local_c;

    *(uint *)(param_1 + 0x2a08) = uVar2;

    if ((((*(int *)(param_1 + 0x2958) == 0) ||

         (param_2 = (uint *)(*(int *)(param_1 + 0x295c) - *(int *)(param_1 + 0x2958) >> 2),

         param_2 == (uint *)0x0)) &&

        ((*(int *)(param_1 + 0x2948) == 0 ||

         (param_2 = (uint *)(*(int *)(param_1 + 0x294c) - *(int *)(param_1 + 0x2948) >> 2),

         param_2 == (uint *)0x0)))) && (*(char *)(param_1 + 0x2a10) == '\0')) {

      FUN_0067c590(0);

    }

  }

  iVar5 = param_4;

  if (param_4 != 0) {

    uVar2 = *puVar4;

    uVar3 = *(uint *)(param_1 + 0x2a04);

    if (uVar2 == uVar3) {

      if (*(char *)(param_1 + 0x2a30) != '\0') {

        uVar6 = FUN_0076cec0(&param_2,"Received missing packet %lu.",uVar2);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x480,1,uVar6);

        *(uint8_t *)(param_1 + 0x2a30) = 0;

      }

      local_11 = FUN_0067da10(puVar4,param_3,iVar5);

      if (((local_11 == '\x01') && (*(int *)(param_1 + 0x2938) != 0)) &&

         (param_2 = (uint *)(*(int *)(param_1 + 0x293c) - *(int *)(param_1 + 0x2938) >> 2),

         param_2 != (uint *)0x0)) {

        puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2938);

        puVar7 = (uint32_t /* width from decompiler */ *)*puVar8;

        if (puVar7[2] == *(int *)(param_1 + 0x2a04)) {

          memmove(puVar8,puVar8 + 1,(*(int *)(param_1 + 0x293c) - (int)(puVar8 + 1) >> 2) * 4);

          *(int *)(param_1 + 0x293c) = *(int *)(param_1 + 0x293c) + -4;

          FUN_0067da10(puVar7 + 2,*puVar7,puVar7[1]);

          operator_delete__((void *)*puVar7);

                    /* WARNING: Subroutine does not return */

          operator_delete(puVar7);

        }

      }

    }

    else if (*(uint *)(param_1 + 0x2a04) < uVar2) {

      if (*(char *)(param_1 + 0x2a30) == '\0') {

        uVar6 = FUN_0076cec0(&param_2,

                             "Received a packet out of sequence (%lu, expected %lu) - packet lost!",

                             uVar2,uVar3);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x4b1,1,uVar6);

        *(int *)(param_1 + 0x2a34) = *(int *)(param_1 + 0x2a34) + 1;

        if (*(int *)(param_1 + 0x2a3c) != 0) {

          piVar9 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x6c);

          *piVar9 = *piVar9 + 1;

        }

        *(uint8_t *)(param_1 + 0x2a30) = 1;

      }

      if (uVar2 - *(int *)(param_1 + 0x2a04) < 0x40) {

        piVar9 = *(int **)(param_1 + 0x2938);

        if (piVar9 != *(int **)(param_1 + 0x293c)) {

          do {

            if (uVar2 <= *(uint *)(*piVar9 + 8)) break;

            piVar9 = piVar9 + 1;

          } while (piVar9 != *(int **)(param_1 + 0x293c));

          if ((piVar9 != *(int **)(param_1 + 0x293c)) && (uVar2 == *(uint *)(*piVar9 + 8))) {

            ExceptionList = local_c;

            return '\x01';

          }

        }

        param_2 = operator_new(0x18);

        local_4 = 0;

        if (param_2 == (void *)0x0) {

          param_2 = (uint *)0x0;

        }

        else {

          param_2 = (uint *)FUN_0067bfa0(puVar4,param_3,param_4);

        }

        local_4 = 0xffffffff;

        FUN_00680000(&param_4,piVar9,&param_2);

      }

      else {

        uVar6 = FUN_0076cec0(&param_2,"seq %d too far out of order to keep - discarding",*puVar4);

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x4d4,1,uVar6);

        uVar6 = FUN_0076cec0(&param_2,

                             "Session %lu: seq %d too far out of order to keep - need to receive sequence %lu: discarding"

                             ,*(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),*puVar4,

                             *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a04));

        vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                       ,0x4d5,1,uVar6);

      }

    }

    else {

      uVar6 = FUN_0076cec0(&param_3,"Session %lu: discarding duplicate packet (%lu expecting %lu)",

                           *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),uVar2,uVar3);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"

                     ,0x4db,1,uVar6);

    }

  }

  ExceptionList = local_c;

  return local_11;

}
