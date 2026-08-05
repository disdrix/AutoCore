// =============================================================================
// Named_d_d_fragments
// -----------------------------------------------------------------------------
// Stable ID: aa_005a1220
// Address:   0x005a1220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_d_d_fragments @ 0x005a1220
// Stable ID: aa_005a1220
// Embedded strings (evidence for future rename):
//   - "Dropped fragment %d vs %d"
//   - "Reassembling fragment %d (%d fragments)."
//   - "Received fragment %d:%d/%d (%d fragments)."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~156 non-empty decompiler lines.
//  - Control keywords: if×19, while×3, for×2, do×1, return×1.
//  - Notable callees: FUN_007a4480×3, CONCAT31×2, FUN_005a4290×2, d×2, FUN_0042b250, FUN_005a0120, Named_d_d_fragments, FUN_005a4180.
//  - Strings: "Dropped fragment %d vs %d"; "Reassembling fragment %d (%d fragments)."; "Received fragment %d:%d/%d (%d fragments).".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Received fragment %d:%d/%d (%d fragments)."
 * Domain alias of FUN_005a1220 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_d_d_fragments(int *param_1,uint *param_2,uint32_t /* width from decompiler */ param_3,uint param_4,uint16_t param_5,

                 uint param_6)



{

  char cVar1;

  size_t _Size;

  int *piVar2;

  int *piVar3;

  int *piVar4;

  void *pvVar5;

  uint uVar6;

  uint uVar7;

  int *piVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a60f9;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  FUN_0076cf00();

  local_4._0_1_ = 1;

  if ((param_4 & 0xffff) != *param_2) {

    if (*param_2 != 0) {

      FUN_007a4480(0,"Dropped fragment %d vs %d");

    }

    *param_2 = param_4 & 0xffff;

    param_2[1] = 0;

    FUN_005a4290();

    *(uint *)(param_2[3] + 4) = param_2[3];

    param_2[4] = 0;

    *(uint *)param_2[3] = param_2[3];

    *(uint *)(param_2[3] + 8) = param_2[3];

  }

  if (param_1 != (int *)0x0) {

    param_1[2] = param_1[2] + 1;

    param_1[2] = param_1[2] + 1;

  }

  local_4._0_1_ = 3;

  FUN_005a4180();

  local_4._0_1_ = 2;

  if (param_1 != (int *)0x0) {

    piVar8 = param_1 + 2;

    *piVar8 = *piVar8 + -1;

    if (*piVar8 == 0) {

      (**(code **)(*param_1 + 8))();

    }

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  if (param_1 != (int *)0x0) {

    piVar8 = param_1 + 2;

    *piVar8 = *piVar8 + -1;

    if (*piVar8 == 0) {

      (**(code **)(*param_1 + 8))();

    }

  }

  param_2[1] = param_2[1] + param_1[4];

  if (param_2[4] == (param_6 & 0xffff)) {

    if (DAT_00b04ec0 != '\0') {

      FUN_007a4480(0,"Reassembling fragment %d (%d fragments).");

    }

    piVar4 = operator_new(0x18);

    local_4._0_1_ = 4;

    piVar8 = (int *)0x0;

    if (piVar4 != (int *)0x0) {

      _Size = param_2[1];

      FUN_0042b250();

      *piVar4 = (int)&PTR_LAB_009d7b00;

      piVar4[4] = _Size;

      pvVar5 = malloc(_Size);

      piVar4[3] = (int)pvVar5;

      *(uint8_t *)(piVar4 + 5) = 1;

      piVar8 = piVar4;

    }

    if (piVar8 != (int *)0x0) {

      piVar8[2] = piVar8[2] + 1;

    }

    piVar4 = *(int **)param_2[3];

    local_4._0_1_ = 5;

    _param_5 = 0;

    if (piVar4 != (int *)param_2[3]) {

      do {

        uVar7 = *(uint *)(piVar4[4] + 0x10);

        puVar9 = *(uint32_t /* width from decompiler */ **)(piVar4[4] + 0xc);

        puVar10 = (uint32_t /* width from decompiler */ *)(piVar8[3] + _param_5);

        for (uVar6 = uVar7 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *puVar10 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar10 = puVar10 + 1;

        }

        for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {

          *(uint8_t *)puVar10 = *(uint8_t *)puVar9;

          puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

          puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

        }

        _param_5 = _param_5 + *(int *)(piVar4[4] + 0x10);

        if (*(char *)((int)piVar4 + 0x15) == '\0') {

          piVar2 = (int *)piVar4[2];

          if (*(char *)((int)piVar2 + 0x15) == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x15);

            piVar4 = piVar2;

            piVar2 = (int *)*piVar2;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar2 + 0x15);

              piVar4 = piVar2;

              piVar2 = (int *)*piVar2;

            }

          }

          else {

            cVar1 = *(char *)(piVar4[1] + 0x15);

            piVar3 = (int *)piVar4[1];

            piVar2 = piVar4;

            while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {

              cVar1 = *(char *)(piVar4[1] + 0x15);

              piVar3 = (int *)piVar4[1];

              piVar2 = piVar4;

            }

          }

        }

      } while (piVar4 != (int *)param_2[3]);

    }

    if (piVar8 != (int *)0x0) {

      piVar8[2] = piVar8[2] + 1;

    }

    FUN_005a0120();

    *param_2 = 0;

    param_2[1] = 0;

    FUN_005a4290();

    *(uint *)(param_2[3] + 4) = param_2[3];

    param_2[4] = 0;

    *(uint *)param_2[3] = param_2[3];

    *(uint *)(param_2[3] + 8) = param_2[3];

    local_4 = CONCAT31(local_4._1_3_,1);

    if (piVar8 != (int *)0x0) {

      piVar4 = piVar8 + 2;

      *piVar4 = *piVar4 + -1;

      if (*piVar4 == 0) {

        (**(code **)(*piVar8 + 8))();

      }

    }

  }

  else if (DAT_00b04ec0 != '\0') {

    FUN_007a4480(0,"Received fragment %d:%d/%d (%d fragments).",*param_2,param_5);

  }

  local_4 = local_4 & 0xffffff00;

  FUN_0076cef0();

  piVar8 = param_1 + 2;

  *piVar8 = *piVar8 + -1;

  local_4 = 0xffffffff;

  if (*piVar8 == 0) {

    (**(code **)(*param_1 + 8))();

  }

  ExceptionList = pvStack_c;

  return;

}
