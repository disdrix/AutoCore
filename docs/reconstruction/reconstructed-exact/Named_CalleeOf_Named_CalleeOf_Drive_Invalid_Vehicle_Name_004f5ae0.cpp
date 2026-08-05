// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Invalid_Vehicle_Name_004f5ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f5ae0
// Callee of Named_CalleeOf_Drive_Invalid_Vehicle_Name (+1 other named callers)
// Address:   0x004f5ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Invalid_Vehicle_Name: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Drive_Invalid_Vehicle_Name (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×7, do×3, while×3, for×3, return×1.
//  - Notable callees: FUN_004f5ae0, FUN_00764030, FUN_007b6730, FUN_007b6a20, FUN_00989e00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Invalid_Vehicle_Name (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_CalleeOf_Drive_Invalid_Vehicle_Name_004f5ae0(int param_1,char param_2,char *param_3)



{

  int *piVar1;

  char cVar2;

  char *pcVar3;

  int iVar4;

  uint uVar5;

  char *pcVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char *pcVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ local_124;

  char acStack_120 [2];

  uint32_t /* width from decompiler */ auStack_11e [66];

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a2ca5;

  local_14 = ExceptionList;

  if (param_2 < '\b') {

    piVar1 = (int *)(param_1 + 0x34c + param_2 * 4);

    ExceptionList = &local_14;

    if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

      ExceptionList = &local_14;

      (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

      *piVar1 = 0;

    }

    pcVar3 = param_3;

    do {

      cVar2 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar2 != '\0');

    local_124 = (void *)((int)pcVar3 - (int)(param_3 + 1));

    if (local_124 != (void *)0x0) {

      acStack_120[0] = '\0';

      acStack_120[1] = '\0';

      puVar7 = auStack_11e;

      for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar7 = 0;

        puVar7 = puVar7 + 1;

      }

      *(uint16_t *)puVar7 = 0;

      pcVar3 = param_3;

      do {

        cVar2 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      pcVar8 = (char *)((int)&local_124 + 3);

      do {

        pcVar6 = pcVar8 + 1;

        pcVar8 = pcVar8 + 1;

      } while (*pcVar6 != '\0');

      pcVar6 = param_3;

      for (uVar5 = (uint)((int)pcVar3 - (int)param_3) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar6;

        pcVar6 = pcVar6 + 4;

        pcVar8 = pcVar8 + 4;

      }

      pcVar9 = acStack_120;

      uVar10 = 0xffffffff;

      for (uVar5 = (int)pcVar3 - (int)param_3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

        *pcVar8 = *pcVar6;

        pcVar6 = pcVar6 + 1;

        pcVar8 = pcVar8 + 1;

      }

      FUN_007b6a20(pcVar9,0xffffffff);

      cVar2 = FUN_007b6730(pcVar9,uVar10);

      if (cVar2 != '\0') {

        local_124 = operator_new(0x14c);

        uStack_c = 0;

        if (local_124 == (void *)0x0) {

          iVar4 = 0;

        }

        else {

          iVar4 = FUN_00764030();

        }

        uStack_c = 0xffffffff;

        *piVar1 = iVar4;

        FUN_00989e00(&local_124,param_3);

        iVar4 = (**(code **)(*(int *)*piVar1 + 0x5c))(&local_124);

        if (iVar4 < 0) {

          if ((uint32_t /* width from decompiler */ *)*piVar1 != (uint32_t /* width from decompiler */ *)0x0) {

            (*(code *)**(uint32_t /* width from decompiler */ **)*piVar1)(1);

          }

          *piVar1 = 0;

        }

      }

    }

  }

  ExceptionList = local_14;

  return;

}
