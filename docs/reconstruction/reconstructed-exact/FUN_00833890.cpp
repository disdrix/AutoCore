// =============================================================================
// FUN_00833890
// -----------------------------------------------------------------------------
// Stable ID: aa_00833890
// Address:   0x00833890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00833890 @ 0x00833890
// Stable ID: aa_00833890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0076f5f0×2, FUN_00972bd0×2, fcos×2, fsin×2, FUN_007abe70, FUN_00833390, FUN_00833890.
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



uint32_t /* width from decompiler */ __thiscall FUN_00833890(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int *piVar1;

  int iVar2;

  float10 fVar3;

  float10 fVar4;

  float fVar5;

  float fVar6;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  fVar6 = g_flOne;

  if (((*(char *)(param_1 + 0x5d0) != '\0') && (*(int *)(param_1 + 0x508) != 0)) &&

     (DAT_00d1d864 != '\0')) {

    fVar5 = 0.0;

    *(uint8_t *)(param_1 + 0x5dc) = 0;

    iVar2 = DAT_00d1d870 - _DAT_00d1d878;

    local_28 = 0.0;

    local_24 = fVar6;

    local_20 = 0.0;

    FUN_0076f5f0(&local_1c,&local_28);

    fVar3 = (float10)(DAT_00d1d86c - _DAT_00d1d874) * (float10)_DAT_00aaa9d8;

    fVar4 = (float10)fsin(fVar3);

    local_10 = (float)((float10)local_1c * fVar4);

    local_c = (float)((float10)local_18 * fVar4);

    local_8 = (float)((float10)local_14 * fVar4);

    fVar3 = (float10)fcos(fVar3);

    local_4 = (float)fVar3;

    FUN_00972bd0(&local_10);

    local_1c = fVar6;

    local_18 = fVar5;

    local_14 = fVar5;

    FUN_0076f5f0(&local_28,&local_1c);

    fVar3 = (float10)iVar2 * (float10)_DAT_00aaa9d8;

    fVar4 = (float10)fsin(fVar3);

    local_10 = (float)((float10)local_28 * fVar4);

    local_c = (float)((float10)local_24 * fVar4);

    local_8 = (float)((float10)local_20 * fVar4);

    fVar3 = (float10)fcos(fVar3);

    local_4 = (float)fVar3;

    FUN_00972bd0(&local_10);

    local_10 = *(float *)(param_1 + 0x590);

    local_c = *(float *)(param_1 + 0x594);

    local_8 = *(float *)(param_1 + 0x598);

    local_4 = *(float *)(param_1 + 0x59c);

    if (*(int *)(param_1 + 0x508) != 0) {

      piVar1 = *(int **)(*(int *)(param_1 + 0x508) + 0x48);

      if (piVar1 != (int *)0x0) {

        (**(code **)(*piVar1 + 0x14))(&local_10);

      }

      (**(code **)(**(int **)(param_1 + 0x508) + 0x44))();

      FUN_00833390();

    }

  }

  FUN_007abe70(param_2,param_3);

  return 1;

}
