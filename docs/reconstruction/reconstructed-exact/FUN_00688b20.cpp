// =============================================================================
// FUN_00688b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00688b20
// Address:   0x00688b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00688b20 @ 0x00688b20
// Stable ID: aa_00688b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×12, while×2, return×1.
//  - Notable callees: FUN_0068b820×2, FUN_006871b0, FUN_00687d40, FUN_00688b20, FUN_0068ed90.
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

void __thiscall FUN_00688b20(int *param_1,char param_2,char param_3,char param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  float fVar4;

  float local_18;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009aa052;

  local_10 = ExceptionList;

  local_8 = 0;

  local_18 = -1.0;

  ExceptionList = &local_10;

  if ((param_2 != '\0') && (ExceptionList = &local_10, *(int *)(param_1[4] + 8) == 1)) {

    if (param_1[0xd] == 0) {

      if (*(uint *)param_1[0xc] < 2) {

        fVar4 = *(float *)(*param_1 + 0x14);

      }

      else {

        piVar3 = *(int **)(param_1[0xe] + 4);

        local_18 = *(float *)(*param_1 + 0x14);

        while (fVar4 = local_18, piVar3 != *(int **)(param_1[0xe] + 8)) {

          iVar1 = ((int *)*piVar3)[0xd];

          if (iVar1 == 0) {

            fVar4 = *(float *)(*(int *)*piVar3 + 0x14);

          }

          else {

            fVar4 = *(float *)(iVar1 + 0x10);

          }

          if (fVar4 <= local_18) {

            piVar3 = piVar3 + 1;

          }

          else {

            piVar3 = piVar3 + 1;

            local_18 = fVar4;

          }

        }

      }

    }

    else {

      fVar4 = *(float *)(param_1[0xd] + 0x10);

    }

    ExceptionList = &local_10;

    uVar2 = FUN_00687d40(fVar4);

    FUN_0068b820(uVar2);

  }

  if ((param_4 != '\0') && (*(int *)(param_1[4] + 0xc) == 1)) {

    if (param_1[0xd] == 0) {

      if (*(uint *)param_1[0xc] < 2) {

        local_18 = *(float *)(*param_1 + 0x14);

      }

      else if (local_18 == DAT_00aaa668) {

        piVar3 = *(int **)(param_1[0xe] + 4);

        local_18 = *(float *)(*param_1 + 0x14);

        while (piVar3 != *(int **)(param_1[0xe] + 8)) {

          iVar1 = ((int *)*piVar3)[0xd];

          if (iVar1 == 0) {

            fVar4 = *(float *)(*(int *)*piVar3 + 0x14);

          }

          else {

            fVar4 = *(float *)(iVar1 + 0x10);

          }

          if (fVar4 <= local_18) {

            piVar3 = piVar3 + 1;

          }

          else {

            piVar3 = piVar3 + 1;

            local_18 = fVar4;

          }

        }

      }

    }

    else {

      local_18 = *(float *)(param_1[0xd] + 0x10);

    }

    uVar2 = FUN_006871b0(local_18);

    FUN_0068b820(uVar2);

  }

  if ((param_3 != '\0') && (*(int *)(param_1[4] + 0x10) == 1)) {

    FUN_0068ed90();

  }

  ExceptionList = local_10;

  return;

}
