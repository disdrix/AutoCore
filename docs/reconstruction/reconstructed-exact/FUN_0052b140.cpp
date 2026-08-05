// =============================================================================
// FUN_0052b140
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b140
// Address:   0x0052b140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052b140 @ 0x0052b140
// Stable ID: aa_0052b140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_0052ada0×5, FUN_0052b040×5, FUN_0052b140, FUN_00538ab0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0052b140(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ local_410;

  uint8_t local_40c [4];

  int local_408 [4];

  int iStack_3f8;

  int iStack_3f4;

  int iStack_3f0;

  short sStack_3ec;

  short sStack_3ea;

  short sStack_3e8;

  short sStack_3e6;

  short sStack_3e4;

  short sStack_3e2;

  uint8_t auStack_208 [516];

  

  local_410 = param_2;

  piVar2 = (int *)FUN_00538ab0(local_40c,&local_410);

  if (*piVar2 != DAT_00b045b4) {

    iVar3 = *(int *)(param_1 + 4);

    piVar2 = (int *)(*piVar2 + 0x10);

    piVar5 = local_408;

    for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {

      *piVar5 = *piVar2;

      piVar2 = piVar2 + 1;

      piVar5 = piVar5 + 1;

    }

    iVar4 = (**(code **)(*(int *)(*(int *)(iVar3 + 4) + 4 + param_1) + 0x27c))();

    iVar3 = local_408[2];

    if ((sStack_3e2 <= iVar4) &&

       (((((local_408[2] != -1 && (cVar1 = FUN_0052b040(local_408[2],auStack_208), cVar1 != '\0'))

          && (iVar3 = FUN_0052ada0(iVar3), sStack_3ec <= iVar3)) ||

         ((((((iVar3 = local_408[3], local_408[3] != -1 &&

              (cVar1 = FUN_0052b040(local_408[3],auStack_208), cVar1 != '\0')) &&

             (iVar3 = FUN_0052ada0(iVar3), sStack_3ea <= iVar3)) ||

            (((iVar3 = iStack_3f8, iStack_3f8 != -1 &&

              (cVar1 = FUN_0052b040(iStack_3f8,auStack_208), cVar1 != '\0')) &&

             (iVar3 = FUN_0052ada0(iVar3), sStack_3e8 <= iVar3)))) ||

           (((iStack_3f4 != -1 && (cVar1 = FUN_0052b040(iStack_3f4,auStack_208), cVar1 != '\0')) &&

            (iVar3 = FUN_0052ada0(iStack_3f4), sStack_3e6 <= iVar3)))) ||

          (((iStack_3f0 != -1 && (cVar1 = FUN_0052b040(iStack_3f0,auStack_208), cVar1 != '\0')) &&

           (iVar3 = FUN_0052ada0(iStack_3f0), sStack_3e4 <= iVar3)))))) ||

        (((local_408[2] == -1 && (local_408[3] == -1)) &&

         ((iStack_3f8 == -1 && ((iStack_3f4 == -1 && (iStack_3f0 == -1)))))))))) {

      return 1;

    }

  }

  return 0;

}
