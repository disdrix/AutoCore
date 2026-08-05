// =============================================================================
// FUN_0082af20
// -----------------------------------------------------------------------------
// Stable ID: aa_0082af20
// Address:   0x0082af20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0082af20 @ 0x0082af20
// Stable ID: aa_0082af20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~94 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_007b08d0, FUN_0082af20.
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

void __thiscall FUN_0082af20(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  float fVar3;

  uint8_t *puVar4;

  uint32_t /* width from decompiler */ uStack_4c;

  float *pfStack_48;

  int *piStack_44;

  uint8_t *puStack_40;

  float fStack_3c;

  float fStack_30;

  uint8_t auStack_2c [12];

  uint8_t auStack_20 [8];

  uint8_t local_18 [20];

  

  fStack_3c = 1.4013e-45;

  puStack_40 = local_18;

  piStack_44 = (int *)0x82af3e;

  piVar1 = (int *)(**(code **)(*param_1 + 0x140))();

  if (0 < *piVar1) {

    piStack_44 = (int *)0x1;

    pfStack_48 = (float *)auStack_20;

    uStack_4c = 0x82af5b;

    iVar2 = (**(code **)(*param_1 + 0x140))();

    if (0 < *(int *)(iVar2 + 4)) {

      piStack_44 = (int *)0x1;

      pfStack_48 = &fStack_30;

      uStack_4c = 0x82af76;

      piVar1 = (int *)(**(code **)(*param_1 + 0x140))();

      fStack_3c = (float)*param_2 / (float)*piVar1;

      uStack_4c = 1;

      iVar2 = (**(code **)(*param_1 + 0x140))(auStack_20);

      fStack_30 = fStack_30 / (float)*(int *)(iVar2 + 4);

      if (param_1[0x149] != 0) {

        piStack_44 = (int *)0x1;

        pfStack_48 = (float *)local_18;

        uStack_4c = 0x82afdb;

        piVar1 = (int *)(**(code **)(*(int *)param_1[0x149] + 0x140))();

        fStack_30 = (float)(int)((float)*piVar1 * fStack_3c);

        uStack_4c = 1;

        (**(code **)(*(int *)param_1[0x149] + 0x140))(auStack_20);

        puVar4 = &stack0xffffffc8;

        (**(code **)(*(int *)param_1[0x149] + 300))(puVar4);

        (**(code **)(*(int *)param_1[0x149] + 0x34c))();

        fVar3 = 1.4013e-45;

        piVar1 = (int *)(**(code **)(*(int *)param_1[0x149] + 0x120))(auStack_2c,1,0);

        puStack_40 = (uint8_t *)(int)((float)*piVar1 * (float)puVar4);

        iVar2 = (**(code **)(*(int *)param_1[0x149] + 0x120))(&stack0xffffffc8,1,0);

        pfStack_48 = (float *)(int)((float)*(int *)(iVar2 + 4) * fVar3);

        (**(code **)(*(int *)param_1[0x149] + 0x118))(&uStack_4c);

      }

      if (param_1[0x14a] != 0) {

        piStack_44 = (int *)0x1;

        pfStack_48 = (float *)local_18;

        uStack_4c = 0x82b0be;

        piVar1 = (int *)(**(code **)(*(int *)param_1[0x14a] + 0x140))();

        fStack_30 = (float)(int)((float)*piVar1 * fStack_3c);

        uStack_4c = 1;

        (**(code **)(*(int *)param_1[0x14a] + 0x140))(auStack_20);

        puVar4 = &stack0xffffffc8;

        (**(code **)(*(int *)param_1[0x14a] + 300))(puVar4);

        (**(code **)(*(int *)param_1[0x14a] + 0x34c))();

        fVar3 = 1.4013e-45;

        piVar1 = (int *)(**(code **)(*(int *)param_1[0x14a] + 0x120))(auStack_2c,1,0);

        puStack_40 = (uint8_t *)(int)((float)*piVar1 * (float)puVar4);

        iVar2 = (**(code **)(*(int *)param_1[0x14a] + 0x120))(&stack0xffffffc8,1,0);

        pfStack_48 = (float *)(int)((float)*(int *)(iVar2 + 4) * fVar3);

        (**(code **)(*(int *)param_1[0x14a] + 0x118))(&uStack_4c);

      }

      if (param_1[0x14b] != 0) {

        piStack_44 = (int *)0x1;

        pfStack_48 = (float *)local_18;

        uStack_4c = 0x82b1a1;

        piVar1 = (int *)(**(code **)(*(int *)param_1[0x14b] + 0x140))();

        fStack_30 = (float)(int)((float)*piVar1 * fStack_3c);

        uStack_4c = 1;

        (**(code **)(*(int *)param_1[0x14b] + 0x140))(auStack_20);

        puVar4 = &stack0xffffffc8;

        (**(code **)(*(int *)param_1[0x14b] + 300))(puVar4);

        (**(code **)(*(int *)param_1[0x14b] + 0x34c))();

        fVar3 = 1.4013e-45;

        piVar1 = (int *)(**(code **)(*(int *)param_1[0x14b] + 0x120))(auStack_2c,1,0);

        puStack_40 = (uint8_t *)(int)((float)*piVar1 * (float)puVar4);

        iVar2 = (**(code **)(*(int *)param_1[0x14b] + 0x120))(&stack0xffffffc8,1,0);

        pfStack_48 = (float *)(int)((float)*(int *)(iVar2 + 4) * fVar3);

        (**(code **)(*(int *)param_1[0x14b] + 0x118))(&uStack_4c);

      }

    }

  }

  piStack_44 = param_2;

  pfStack_48 = (float *)0x82b26a;

  FUN_007b08d0();

  return;

}
