// =============================================================================
// FUN_008d8820
// -----------------------------------------------------------------------------
// Stable ID: aa_008d8820
// Address:   0x008d8820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d8820 @ 0x008d8820
// Stable ID: aa_008d8820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0076df50×2, FUN_0040d0e0, FUN_0076f5f0, FUN_00791f30, FUN_008d8820, FUN_00972bd0, fcos, fsin.
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



void __thiscall FUN_008d8820(int param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  float10 fVar3;

  float fVar4;

  float unaff_retaddr;

  uint32_t /* width from decompiler */ uVar5;

  float local_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  uint8_t auStack_14 [20];

  

  local_30 = param_2 + *(float *)(param_1 + 0x574);

  *(float *)(param_1 + 0x574) = local_30;

  if (*(int *)(param_1 + 0x544) != 0) {

    (**(code **)(*(int *)(*(int *)(param_1 + 0x544) + 0x40) + 0x28))(local_30);

    piVar1 = *(int **)(*(int *)(param_1 + 0x544) + 0x48);

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x10))(3);

    }

    if ((*(char *)(param_1 + 0x56d) != '\0') &&

       (piVar1 = *(int **)(*(int *)(param_1 + 0x544) + 0x48), piVar1 != (int *)0x0)) {

      uVar5 = 3;

      (**(code **)(*piVar1 + 0x10))(3);

      fVar4 = *(float *)(param_1 + 0x570) * unaff_retaddr * DAT_00a1e728;

      iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x544) + 0x48) + 0xc))(uVar5,fVar4);

      FUN_0040d0e0(iVar2 + 0x80);

      local_30 = 0.0;

      fStack_2c = g_flOne;

      fStack_28 = 0.0;

      FUN_0076f5f0(&fStack_20,&local_30);

      fVar3 = (float10)fsin((float10)(fVar4 * _DAT_00aaaa20));

      local_30 = (float)((float10)fStack_20 * fVar3);

      fStack_2c = (float)((float10)fStack_1c * fVar3);

      fStack_28 = (float)((float10)fStack_18 * fVar3);

      fVar3 = (float10)fcos((float10)(fVar4 * _DAT_00aaaa20));

      fStack_24 = (float)fVar3;

      FUN_0076df50(auStack_14,auStack_14,&local_30);

      iVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x544) + 0x48) + 0xc))();

      FUN_0076df50(auStack_14,auStack_14,iVar2 + 0x80);

      (**(code **)(**(int **)(*(int *)(param_1 + 0x544) + 0x48) + 0x10))(3,auStack_14);

      FUN_00972bd0(uVar5);

    }

  }

  FUN_00791f30(param_2);

  return;

}
