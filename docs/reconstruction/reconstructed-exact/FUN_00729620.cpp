// =============================================================================
// FUN_00729620
// -----------------------------------------------------------------------------
// Stable ID: aa_00729620
// Address:   0x00729620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00729620 @ 0x00729620
// Stable ID: aa_00729620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×11, return×7, while×2, do×1.
//  - Notable callees: FUN_0071c4d0×2, FUN_00415e90, FUN_005b2ba0, FUN_0067b470, FUN_0071c390, FUN_0071c3d0, FUN_0071c570, FUN_007290e0.
//  - Return sites: 7.

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

uint32_t /* width from decompiler */ __fastcall FUN_00729620(int param_1)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ local_50;

  int local_4c;

  undefined **local_48;

  void *local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  char local_34;

  uint8_t local_33;

  undefined ***local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1121;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x1c) == 0) {

    return 0;

  }

  if ((*(int *)(param_1 + 0x1c) == 1) && (*(int *)(param_1 + 0x34) == 0)) {

    ExceptionList = &local_c;

    cVar3 = FUN_0067b470(&local_4c);

    if (cVar3 != '\0') {

      if (local_4c != 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

        (**(code **)(**(int **)(param_1 + 0x18) + 0xc))(0);

        FUN_00415e90();

        ExceptionList = local_10;

        return 0;

      }

      pvVar4 = operator_new(0x24);

      if (pvVar4 == (void *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = FUN_0071c390();

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = uVar5;

    }

  }

  else if (*(int *)(param_1 + 0x34) != 0) {

    ExceptionList = &local_c;

    cVar3 = FUN_0071c570(*(int *)(param_1 + 0x34));

    if (cVar3 == '\0') {

      uVar5 = FUN_007290e0(param_1);

      ExceptionList = local_c;

      return uVar5;

    }

    cVar3 = FUN_0071c4d0(&local_4c,&local_50);

    while (cVar3 != '\0') {

      FUN_007294e0(param_1,local_50);

      if (*(int *)(param_1 + 0x34) == 0) {

        ExceptionList = local_c;

        return 0;

      }

      cVar3 = FUN_0071c4d0(&local_4c,&local_50);

    }

    if ((*(int *)(param_1 + 0x34) != 0) && (*(int *)(param_1 + 0x4c) != 0)) {

      do {

        piVar1 = *(int **)(**(int **)(param_1 + 0x48) + 8);

        piVar2 = (int *)**(int **)(param_1 + 0x48);

        if (piVar2 != *(int **)(param_1 + 0x48)) {

          *(int *)piVar2[1] = *piVar2;

          *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar2);

        }

        local_48 = &PTR_FUN_00a9d184;

        local_44 = (void *)0x0;

        local_40 = 0;

        local_3c = 0;

        local_38 = 0x400;

        local_34 = '\x01';

        local_33 = 1;

        local_44 = realloc((void *)0x0,0x400);

        local_30 = &local_48;

        local_2c = 0;

        local_24 = 0;

        local_20 = 0;

        local_1c = 0;

        local_18 = 0;

        local_14 = 0;

        local_10 = (void *)0x0;

        local_4 = 2;

        (**(code **)(*piVar1 + 4))(&local_30);

        FUN_0071c3d0(local_48);

        (**(code **)*piVar1)(1);

        FUN_005b2ba0();

        local_4 = 0xffffffff;

        local_48 = &PTR_FUN_00a9d184;

        if (local_34 != '\0') {

          free(local_44);

        }

        local_48 = &PTR_LAB_00a9d774;

      } while (*(int *)(param_1 + 0x4c) != 0);

      ExceptionList = local_c;

      return 0;

    }

  }

  ExceptionList = local_c;

  return 0;

}
