// =============================================================================
// FUN_005b83e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b83e0
// Address:   0x005b83e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b83e0 @ 0x005b83e0
// Stable ID: aa_005b83e0
// Embedded strings (evidence for future rename):
//   - "CVOGFXParameterInstance::DoParameterUpdates"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: for×5, if×5, return×1.
//  - Notable callees: FUN_005b83e0, FUN_0076cef0, FUN_0076cf00, FUN_00973770.
//  - Strings: "CVOGFXParameterInstance::DoParameterUpdates".
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

void __fastcall FUN_005b83e0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  int *piVar6;

  int *piVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6b48;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CVOGFXParameterInstance::DoParameterUpdates");

  iVar1 = *(int *)(param_1 + 4);

  local_4 = 0;

  for (; iVar1 != param_1; iVar1 = *(int *)(iVar1 + 4)) {

    iVar2 = *(int *)(iVar1 + 0xc);

    if (iVar2 != 0) {

      iVar3 = *(int *)(iVar2 + 4);

      piVar7 = (int *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 0x10));

      if ((iVar3 == 3) || (iVar3 == 4)) {

        uVar5 = *(uint *)(iVar1 + 0x18);

        if (uVar5 == 2) {

          *(short *)piVar7 = (short)(int)*(float *)(iVar2 + 0x14);

        }

        else if (uVar5 == 4) {

          *piVar7 = (int)*(float *)(iVar2 + 0x14);

        }

        else {

          piVar6 = (int *)(iVar2 + 0x14);

          for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

            *piVar7 = *piVar6;

            piVar6 = piVar6 + 1;

            piVar7 = piVar7 + 1;

          }

          for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

            *(char *)piVar7 = (char)*piVar6;

            piVar6 = (int *)((int)piVar6 + 1);

            piVar7 = (int *)((int)piVar7 + 1);

          }

        }

      }

      else if (iVar3 == 7) {

        FUN_00973770(iVar2 + 0x14);

        *(uint16_t *)piVar7 = 0xffff;

        *(uint8_t *)((int)piVar7 + 2) = 0xff;

      }

      else {

        uVar5 = *(uint *)(iVar1 + 0x18);

        piVar6 = (int *)(iVar2 + 0x14);

        for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

          *piVar7 = *piVar6;

          piVar6 = piVar6 + 1;

          piVar7 = piVar7 + 1;

        }

        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

          *(char *)piVar7 = (char)*piVar6;

          piVar6 = (int *)((int)piVar6 + 1);

          piVar7 = (int *)((int)piVar7 + 1);

        }

      }

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
