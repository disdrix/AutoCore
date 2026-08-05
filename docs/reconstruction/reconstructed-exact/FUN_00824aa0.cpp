// =============================================================================
// FUN_00824aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00824aa0
// Address:   0x00824aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00824aa0 @ 0x00824aa0
// Stable ID: aa_00824aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_007b08d0, FUN_00824aa0.
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

void __fastcall FUN_00824aa0(int *param_1)



{

  int *piVar1;

  int iVar2;

  float unaff_ESI;

  float fVar3;

  uint8_t **ppuStack_44;

  uint8_t *puStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint8_t *puStack_38;

  int *piStack_34;

  uint8_t *puStack_30;

  int iStack_2c;

  uint8_t auStack_18 [8];

  uint8_t local_10 [4];

  float fStack_c;

  int *piStack_4;

  

  iStack_2c = 1;

  puStack_30 = local_10;

  piStack_34 = (int *)0x824ab8;

  piVar1 = (int *)(**(code **)(*param_1 + 0x140))();

  if (0 < *piVar1) {

    piStack_34 = (int *)0x1;

    puStack_38 = auStack_18;

    uStack_3c = 0x824ad6;

    iVar2 = (**(code **)(*param_1 + 0x140))();

    if (0 < *(int *)(iVar2 + 4)) {

      piStack_34 = (int *)0x1;

      puStack_38 = &stack0xffffffd8;

      uStack_3c = 0x824af1;

      piVar1 = (int *)(**(code **)(*param_1 + 0x140))();

      fStack_c = (float)*piStack_4 / (float)*piVar1;

      uStack_3c = 1;

      puStack_40 = auStack_18;

      puStack_30 = (uint8_t *)(float)piStack_4[1];

      ppuStack_44 = (uint8_t **)0x824b1f;

      (**(code **)(*param_1 + 0x140))();

      if (param_1[0x142] != 0) {

        piStack_34 = (int *)0x1;

        puStack_38 = local_10;

        uStack_3c = 0x824b56;

        (**(code **)(*(int *)param_1[0x142] + 0x140))();

        uStack_3c = 1;

        puStack_40 = auStack_18;

        ppuStack_44 = (uint8_t **)0x824b7d;

        iVar2 = (**(code **)(*(int *)param_1[0x142] + 0x140))();

        iStack_2c = (int)((float)*(int *)(iVar2 + 4) * (float)puStack_38);

        ppuStack_44 = &puStack_30;

        (**(code **)(*(int *)param_1[0x142] + 300))();

        piVar1 = (int *)(**(code **)(*(int *)param_1[0x142] + 0x120))(&stack0xffffffdc,1,0);

        puStack_38 = (uint8_t *)(int)((float)*piVar1 * unaff_ESI);

        fVar3 = 0.0;

        iVar2 = (**(code **)(*(int *)param_1[0x142] + 0x120))(&puStack_30,1,0);

        puStack_40 = (uint8_t *)(int)((float)*(int *)(iVar2 + 4) * fVar3);

        (**(code **)(*(int *)param_1[0x142] + 0x118))(&ppuStack_44);

      }

      if (param_1[0x143] != 0) {

        piStack_34 = (int *)0x1;

        puStack_38 = local_10;

        uStack_3c = 0x824c27;

        (**(code **)(*(int *)param_1[0x143] + 0x140))();

        uStack_3c = 1;

        puStack_40 = auStack_18;

        ppuStack_44 = (uint8_t **)0x824c4e;

        iVar2 = (**(code **)(*(int *)param_1[0x143] + 0x140))();

        iStack_2c = (int)((float)*(int *)(iVar2 + 4) * (float)puStack_38);

        ppuStack_44 = &puStack_30;

        (**(code **)(*(int *)param_1[0x143] + 300))();

      }

    }

  }

  piStack_34 = piStack_4;

  puStack_38 = (uint8_t *)0x824c7c;

  FUN_007b08d0();

  return;

}
