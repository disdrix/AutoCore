// =============================================================================
// FUN_005834f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005834f0
// Address:   0x005834f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005834f0 @ 0x005834f0
// Stable ID: aa_005834f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: fwrite×5, FUN_004e8860, FUN_004e8910, FUN_005813b0, FUN_00581480, FUN_005834f0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005834f0(int param_1,FILE *param_2)



{

  int iVar1;

  byte abStack_3d [5];

  uint8_t auStack_38 [4];

  float fStack_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if (param_2 != (FILE *)0x0) {

    FUN_005813b0(param_2);

    FUN_00581480(param_2);

    local_30 = 0;

    local_2c = 0;

    local_28 = 0;

    local_24 = 0;

    local_20 = DAT_00b04c90;

    local_1c = DAT_00b04c94;

    local_18 = DAT_00b04c98;

    local_14 = DAT_00b04c9c;

    if (*(int **)(param_1 + -0x88) != (int *)0x0) {

      iVar1 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

      FUN_004e8910(iVar1 + 0x90,&local_30);

      iVar1 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

      FUN_004e8860(iVar1 + 0x80,&local_20);

    }

    fStack_34 = g_flOne;

    if (*(int **)(param_1 + -0x88) != (int *)0x0) {

      iVar1 = (**(code **)(**(int **)(param_1 + -0x88) + 0xc))();

      fStack_34 = *(float *)(iVar1 + 0x9c);

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0xb8))

              (fStack_34);

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0xac))

              (param_2);

    fwrite(auStack_38,0x10,1,param_2);

    fwrite(&local_28,0x10,1,param_2);

    fwrite((void *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x2c + param_1),4,1,param_2);

    fwrite((void *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x30 + param_1),4,1,param_2);

    abStack_3d[0] =

         (byte)(*(uint *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0xf0 + param_1) >> 9) & 1;

    fwrite(abStack_3d,1,1,param_2);

    return 1;

  }

  return 0;

}
