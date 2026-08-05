// =============================================================================
// FUN_00654a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00654a90
// Address:   0x00654a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00654a90 @ 0x00654a90
// Stable ID: aa_00654a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00654a90.
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

void __fastcall FUN_00654a90(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  float *pfStack_70;

  float *pfStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 8)) {

    do {

      piVar1 = (int *)(*(int *)(param_1 + 4) + iVar3 * 4);

      fVar4 = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + iVar3 * 4) + 0x3c) + 0x2c);

      if (fVar4 == 0.0) {

        fVar4 = 0.0;

      }

      else {

        fVar4 = g_flOne / fVar4;

      }

      if (fVar4 != 0.0) {

        iVar2 = *(int *)(*piVar1 + 0x3c);

        local_50 = *(float *)(iVar2 + 0x70);

        local_4c = *(float *)(iVar2 + 0x74);

        local_48 = *(float *)(iVar2 + 0x78);

        local_44 = *(float *)(iVar2 + 0x7c);

        iVar2 = *(int *)(*piVar1 + 0x3c);

        local_40 = *(float *)(iVar2 + 0x80) + local_50;

        local_3c = *(float *)(iVar2 + 0x84) + local_4c;

        local_38 = *(float *)(iVar2 + 0x88) + local_48;

        local_34 = *(float *)(iVar2 + 0x8c) + local_44;

        iVar2 = *(int *)(*piVar1 + 0x3c);

        local_30 = *(float *)(iVar2 + 0x90) + local_50;

        local_2c = *(float *)(iVar2 + 0x94) + local_4c;

        local_28 = *(float *)(iVar2 + 0x98) + local_48;

        local_24 = *(float *)(iVar2 + 0x9c) + local_44;

        iVar2 = *(int *)(*piVar1 + 0x3c);

        local_20 = *(float *)(iVar2 + 0xa0) + local_50;

        local_1c = *(float *)(iVar2 + 0xa4) + local_4c;

        local_18 = *(float *)(iVar2 + 0xa8) + local_48;

        uStack_64 = DAT_00d03510;

        uStack_68 = 0xffff0000;

        pfStack_6c = &local_40;

        local_14 = *(float *)(iVar2 + 0xac) + local_44;

        pfStack_70 = &local_50;

        (**(code **)(**(int **)(param_1 + -8) + 0x1c))();

        (**(code **)(**(int **)(param_1 + -8) + 0x1c))

                  (&stack0xffffffa0,&local_40,0xff00ff00,DAT_00d03510);

        (**(code **)(**(int **)(param_1 + -8) + 0x1c))

                  (&pfStack_70,&local_40,0xff0000ff,DAT_00d03510);

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(param_1 + 8));

  }

  return;

}
