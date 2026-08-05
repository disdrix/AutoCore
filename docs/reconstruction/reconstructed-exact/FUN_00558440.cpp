// =============================================================================
// FUN_00558440
// -----------------------------------------------------------------------------
// Stable ID: aa_00558440
// Address:   0x00558440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00558440 @ 0x00558440
// Stable ID: aa_00558440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~155 non-empty decompiler lines.
//  - Control keywords: if×7, while×3, return×3, do×1.
//  - Notable callees: FUN_004b99c0, FUN_00555360, FUN_00556a60, FUN_00556da0, FUN_00558440, FUN_00559ac0.
//  - Return sites: 3.

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

void __fastcall FUN_00558440(int param_1)



{

  char cVar1;

  int *piVar2;

  void *pvVar3;

  void **ppvVar4;

  int *piVar5;

  int *piVar6;

  char local_56c [4];

  char local_568 [4];

  char local_564 [4];

  char local_560 [256];

  char local_460 [4];

  char local_45c [4];

  char local_458 [4];

  char local_454 [256];

  char local_354 [4];

  char local_350 [4];

  char local_34c [4];

  char local_348 [256];

  char local_248 [4];

  char local_244 [4];

  char local_240 [4];

  char local_23c [2];

  char local_23a;

  void *local_138;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a46f8;

  local_c = ExceptionList;

  piVar6 = (int *)**(int **)(param_1 + 0x174);

  ExceptionList = &local_c;

  ppvVar4 = &local_c;

  if (piVar6 != *(int **)(param_1 + 0x174)) {

    do {

      ExceptionList = ppvVar4;

      FUN_00555360();

      if (*(char *)((int)piVar6 + 0x571) == '\0') {

        piVar2 = (int *)piVar6[2];

        if (*(char *)((int)piVar2 + 0x571) == '\0') {

          cVar1 = *(char *)(*piVar2 + 0x571);

          piVar6 = piVar2;

          piVar2 = (int *)*piVar2;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar2 + 0x571);

            piVar6 = piVar2;

            piVar2 = (int *)*piVar2;

          }

        }

        else {

          cVar1 = *(char *)(piVar6[1] + 0x571);

          piVar5 = (int *)piVar6[1];

          piVar2 = piVar6;

          while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {

            cVar1 = *(char *)(piVar6[1] + 0x571);

            piVar5 = (int *)piVar6[1];

            piVar2 = piVar6;

          }

        }

      }

      ppvVar4 = ExceptionList;

    } while (piVar6 != *(int **)(param_1 + 0x174));

  }

  FUN_00559ac0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x174) + 4));

  *(int *)(*(int *)(param_1 + 0x174) + 4) = *(int *)(param_1 + 0x174);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x174);

  *(int *)(*(int *)(param_1 + 0x174) + 8) = *(int *)(param_1 + 0x174);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

  if (*(char *)(param_1 + 0x14c) == '\0') {

    pvVar3 = *(void **)(param_1 + 0x148);

    if (pvVar3 != (void *)0x0) {

      FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar3);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = 0;

  }

  *(uint8_t *)(param_1 + 0x44) = 0;

  if (DAT_00b03e64 != '\0') {

    FUN_00556a60();

    local_56c[0] = s_env_time_dawn_009d25f8[0];

    local_56c[1] = s_env_time_dawn_009d25f8[1];

    local_56c[2] = s_env_time_dawn_009d25f8[2];

    local_56c[3] = s_env_time_dawn_009d25f8[3];

    local_560[0] = s_env_time_dawn_009d25f8[0xc];

    local_560[1] = s_env_time_dawn_009d25f8[0xd];

    local_564[0] = s_env_time_dawn_009d25f8[8];

    local_564[1] = s_env_time_dawn_009d25f8[9];

    local_564[2] = s_env_time_dawn_009d25f8[10];

    local_564[3] = s_env_time_dawn_009d25f8[0xb];

    local_568[0] = s_env_time_dawn_009d25f8[4];

    local_568[1] = s_env_time_dawn_009d25f8[5];

    local_568[2] = s_env_time_dawn_009d25f8[6];

    local_568[3] = s_env_time_dawn_009d25f8[7];

    local_45c[0] = s_env_time_midday_009d2570[4];

    local_45c[1] = s_env_time_midday_009d2570[5];

    local_45c[2] = s_env_time_midday_009d2570[6];

    local_45c[3] = s_env_time_midday_009d2570[7];

    local_460[0] = s_env_time_midday_009d2570[0];

    local_460[1] = s_env_time_midday_009d2570[1];

    local_460[2] = s_env_time_midday_009d2570[2];

    local_460[3] = s_env_time_midday_009d2570[3];

    local_354[0] = s_env_time_sunset_009d25e8[0];

    local_354[1] = s_env_time_sunset_009d25e8[1];

    local_354[2] = s_env_time_sunset_009d25e8[2];

    local_354[3] = s_env_time_sunset_009d25e8[3];

    local_458[0] = s_env_time_midday_009d2570[8];

    local_458[1] = s_env_time_midday_009d2570[9];

    local_458[2] = s_env_time_midday_009d2570[10];

    local_458[3] = s_env_time_midday_009d2570[0xb];

    local_454[0] = s_env_time_midday_009d2570[0xc];

    local_454[1] = s_env_time_midday_009d2570[0xd];

    local_454[2] = s_env_time_midday_009d2570[0xe];

    local_454[3] = s_env_time_midday_009d2570[0xf];

    local_348[0] = s_env_time_sunset_009d25e8[0xc];

    local_348[1] = s_env_time_sunset_009d25e8[0xd];

    local_348[2] = s_env_time_sunset_009d25e8[0xe];

    local_348[3] = s_env_time_sunset_009d25e8[0xf];

    local_350[0] = s_env_time_sunset_009d25e8[4];

    local_350[1] = s_env_time_sunset_009d25e8[5];

    local_350[2] = s_env_time_sunset_009d25e8[6];

    local_350[3] = s_env_time_sunset_009d25e8[7];

    local_34c[0] = s_env_time_sunset_009d25e8[8];

    local_34c[1] = s_env_time_sunset_009d25e8[9];

    local_34c[2] = s_env_time_sunset_009d25e8[10];

    local_34c[3] = s_env_time_sunset_009d25e8[0xb];

    local_240[0] = s_env_time_night_009d25d8[8];

    local_240[1] = s_env_time_night_009d25d8[9];

    local_240[2] = s_env_time_night_009d25d8[10];

    local_240[3] = s_env_time_night_009d25d8[0xb];

    local_248[0] = s_env_time_night_009d25d8[0];

    local_248[1] = s_env_time_night_009d25d8[1];

    local_248[2] = s_env_time_night_009d25d8[2];

    local_248[3] = s_env_time_night_009d25d8[3];

    local_23c[0] = s_env_time_night_009d25d8[0xc];

    local_23c[1] = s_env_time_night_009d25d8[0xd];

    local_244[0] = s_env_time_night_009d25d8[4];

    local_244[1] = s_env_time_night_009d25d8[5];

    local_244[2] = s_env_time_night_009d25d8[6];

    local_244[3] = s_env_time_night_009d25d8[7];

    local_4 = 0;

    local_23a = s_env_time_night_009d25d8[0xe];

    FUN_00556da0(0,local_56c);

    if (local_138 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(local_138);

    }

  }

  ExceptionList = local_c;

  return;

}
