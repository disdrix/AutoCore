// =============================================================================
// FUN_008d8680
// -----------------------------------------------------------------------------
// Stable ID: aa_008d8680
// Address:   0x008d8680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d8680 @ 0x008d8680
// Stable ID: aa_008d8680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0076f5f0×2, fcos×2, fsin×2, FUN_007907b0, FUN_008d76f0, FUN_008d8680.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_008d8680(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int extraout_EDX;

  int extraout_EDX_00;

  float10 fVar1;

  float10 fVar2;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((*(char *)(param_1 + 0x56c) != '\0') && (DAT_00d1d864 != '\0')) {

    if ((*(int *)(param_1 + 0x568) == 2) &&

       ((*(int *)(param_1 + 0x548) != 0 && (*(int *)(*(int *)(param_1 + 0x548) + 0x48) != 0)))) {

      local_20 = 0.0;

      local_1c = g_flOne;

      local_18 = 0.0;

      FUN_0076f5f0(&local_10,&local_20);

      fVar1 = (float10)(DAT_00d1d86c - _DAT_00d1d874) * (float10)_DAT_00aaa9f4 *

              (float10)DAT_00a0f298;

      fVar2 = (float10)fsin(fVar1);

      local_20 = (float)((float10)local_10 * fVar2);

      local_1c = (float)((float10)local_c * fVar2);

      local_18 = (float)((float10)local_8 * fVar2);

      fVar1 = (float10)fcos(fVar1);

      local_14 = (float)fVar1;

      (**(code **)(**(int **)(extraout_EDX + 0x48) + 0x20))(&local_20);

      FUN_008d76f0();

    }

    else if ((*(int *)(param_1 + 0x544) != 0) &&

            ((*(int *)(*(int *)(param_1 + 0x544) + 0x48) != 0 &&

             (*(char *)(param_1 + 0x56d) == '\0')))) {

      local_10 = 0.0;

      local_c = g_flOne;

      local_8 = 0.0;

      FUN_0076f5f0(&local_20,&local_10);

      fVar1 = (float10)(DAT_00d1d86c - _DAT_00d1d874) * (float10)_DAT_00aaa9f4 *

              (float10)DAT_00a0f298;

      fVar2 = (float10)fsin(fVar1);

      local_10 = (float)((float10)local_20 * fVar2);

      local_c = (float)((float10)local_1c * fVar2);

      local_8 = (float)((float10)local_18 * fVar2);

      fVar1 = (float10)fcos(fVar1);

      local_4 = (float)fVar1;

      (**(code **)(**(int **)(extraout_EDX_00 + 0x48) + 0x20))(&local_10);

    }

  }

  FUN_007907b0(param_2,param_3);

  return;

}
