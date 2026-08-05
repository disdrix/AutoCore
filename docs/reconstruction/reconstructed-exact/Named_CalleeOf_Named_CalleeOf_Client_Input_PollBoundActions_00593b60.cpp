// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00593b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00593b60
// Callee of Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x00593b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper. Evidence string: "MatDiffuse". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "MatDiffuse"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, while×2, do×1, for×1.
//  - Notable callees: FUN_00593b60, FUN_00596f90, FUN_005976d0, FUN_009700f0.
//  - Strings: "MatDiffuse".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_PollBoundActions
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

void Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions_00593b60(float param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int local_44;

  uint32_t /* width from decompiler */ local_40 [4];

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  float local_24;

  uint32_t /* width from decompiler */ local_20 [8];

  

  if (DAT_00b04e44 == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = DAT_00b04e48 - DAT_00b04e44 >> 5;

  }

  iVar7 = uVar4 - 1;

  local_44 = iVar7;

  if (-1 < iVar7) {

    iVar3 = iVar7 * 0x20;

    do {

      *(float *)(iVar3 + 4 + DAT_00b04e44) = *(float *)(iVar3 + 4 + DAT_00b04e44) - param_1;

      local_44 = iVar7;

      if (*(float *)(iVar3 + 4 + DAT_00b04e44) <= 0.0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)(*(int *)(iVar3 + DAT_00b04e44) + 0x78));

      }

      *(float *)(iVar3 + 0x1c + DAT_00b04e44) =

           (*(float *)(iVar3 + 4 + DAT_00b04e44) / *(float *)(iVar3 + 8 + DAT_00b04e44)) *

           *(float *)(iVar3 + 0xc + DAT_00b04e44);

      iVar6 = 0;

      while( true ) {

        iVar2 = *(int *)(*(int *)(iVar3 + DAT_00b04e44) + 0xc0);

        if (iVar2 == 0) {

          iVar2 = 0;

        }

        else {

          iVar2 = *(int *)(*(int *)(iVar3 + DAT_00b04e44) + 0xc4) - iVar2 >> 2;

        }

        if (iVar2 <= iVar6) break;

        FUN_009700f0("MatDiffuse",iVar3 + 0x10 + DAT_00b04e44);

        iVar6 = iVar6 + 1;

      }

      iVar7 = iVar7 + -1;

      iVar3 = iVar3 + -0x20;

      local_44 = iVar7;

    } while (-1 < iVar7);

  }

  local_30 = 0;

  local_2c = 0;

  local_28 = 0;

  local_24 = g_flOne;

  puVar5 = local_40;

  puVar8 = local_20;

  for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {

    *puVar8 = *puVar5;

    puVar5 = puVar5 + 1;

    puVar8 = puVar8 + 1;

  }

  if (DAT_00b04e44 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = DAT_00b04e48 - DAT_00b04e44 >> 5;

  }

  if (uVar4 <= uVar1) {

    if ((DAT_00b04e44 != 0) && (uVar4 < (uint)(DAT_00b04e48 - DAT_00b04e44 >> 5))) {

      FUN_005976d0(&local_44,uVar4 * 0x20 + DAT_00b04e44,DAT_00b04e48);

    }

    return;

  }

  if (DAT_00b04e44 == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = DAT_00b04e48 - DAT_00b04e44 >> 5;

  }

  FUN_00596f90(DAT_00b04e48,uVar4 - iVar7,local_20);

  return;

}
