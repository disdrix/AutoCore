// =============================================================================
// FUN_0074d990
// -----------------------------------------------------------------------------
// Stable ID: aa_0074d990
// Address:   0x0074d990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074d990 @ 0x0074d990
// Stable ID: aa_0074d990
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\animation\\anmPriorityBlendController.cpp"
//   - "Cannot BindAnimation() when animation is in priority table!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: BindAnimation, FUN_00445620, FUN_0044a070, FUN_0044c270, FUN_0074d990, vog_LogMessage.
//  - Strings: ",

                 0x171,1,".
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

void __thiscall FUN_0074d990(int *param_1,int param_2,byte *param_3)



{

  int *piVar1;

  int *piVar2;

  void *pvVar3;

  uint uVar4;

  uint local_20;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad9de;

  local_c = ExceptionList;

  if ((*param_3 & 4) == 0) {

    ExceptionList = &local_c;

    FUN_0044c270(0,0);

    uVar4 = 0;

    if (*(int *)(param_2 + 4) == 0) {

      local_20 = 0;

    }

    else {

      local_20 = *(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2;

    }

    if (local_20 != 0) {

      do {

        piVar1 = (int *)(**(code **)(*(int *)param_1[1] + 4))

                                  (*(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 4) + uVar4 * 4));

        if (piVar1 != (int *)0x0) {

          piVar2 = (int *)FUN_0044a070();

          if (*piVar2 == 0) {

            pvVar3 = operator_new(0x38);

            if (pvVar3 == (void *)0x0) {

              pvVar3 = (void *)0x0;

            }

            else {

              *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x2c) = 0;

              *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x30) = 0;

              *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x34) = 0;

            }

            uStack_4 = 0xffffffff;

            *piVar2 = (int)pvVar3;

            (**(code **)(*piVar1 + 8))(pvVar3);

          }

          FUN_00445620();

        }

        uVar4 = uVar4 + 1;

      } while (uVar4 < local_20);

    }

    if ((*param_3 & 1) != 0) {

      (**(code **)(*param_1 + 0x30))(param_3);

    }

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmPriorityBlendController.cpp",

                 0x171,1,"Cannot BindAnimation() when animation is in priority table!");

  ExceptionList = local_c;

  return;

}
