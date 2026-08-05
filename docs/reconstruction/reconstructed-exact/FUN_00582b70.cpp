// =============================================================================
// FUN_00582b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00582b70
// Address:   0x00582b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00582b70 @ 0x00582b70
// Stable ID: aa_00582b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: CONCAT31, FUN_005819e0, FUN_00581ab0, FUN_00582b70.
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

uint __thiscall FUN_00582b70(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  float *pfVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  uint in_EAX;

  int iVar6;

  float *unaff_ESI;

  uint uStack_24;

  int iStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  int *piStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  if (param_2 == (int *)0x0) {

    return in_EAX & 0xffffff00;

  }

  uStack_14 = param_3;

  piStack_18 = param_2;

  uStack_1c = 0x582b98;

  FUN_005819e0();

  uStack_14 = param_3;

  piStack_18 = param_2;

  uStack_1c = 0x582ba1;

  FUN_00581ab0();

  uStack_14 = param_3;

  piStack_18 = param_2;

  uStack_1c = 0x582bc0;

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0x8c + param_1) + 0xb0))();

  iStack_20 = *(int *)(*(int *)(param_1 + -0x8c) + 4) + -0xc + param_1;

  uStack_1c = 0x10;

  uStack_24 = 0x582bd7;

  (**(code **)(*param_2 + 0x14))();

  iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

  pfVar1 = (float *)(iVar6 + -0xc + param_1);

  *pfVar1 = *(float *)(iVar6 + -0xc + param_1) + *unaff_ESI;

  pfVar1[1] = unaff_ESI[1] + pfVar1[1];

  pfVar1[2] = unaff_ESI[2] + pfVar1[2];

  pfVar1[3] = unaff_ESI[3] + pfVar1[3];

  uStack_24 = 0x10;

  (**(code **)(*param_2 + 0x14))(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 4 + param_1);

  (**(code **)(*param_2 + 0x14))(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x2c + param_1);

  (**(code **)(*param_2 + 0x14))(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 0x30 + param_1,4);

  uStack_24 = uStack_24 & 0xffffff00;

  (**(code **)(*param_2 + 0x14))(&uStack_24,1);

  iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

  puVar2 = (uint *)(iVar6 + 0xf0 + param_1);

  *puVar2 = *puVar2 ^ *(uint *)(iVar6 + 0xf0 + param_1) & 0x200;

  fVar5 = g_flOne;

  iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

  if (*(int *)(iVar6 + 0x18 + param_1) != 0) {

    iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

    pfVar1 = (float *)(iVar6 + -0xc + param_1);

    if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {

      *(float *)(iVar6 + -0xc + param_1) = g_flOne;

    }

    iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

    pfVar1 = (float *)(iVar6 + -4 + param_1);

    if (*pfVar1 <= 0.0 && *pfVar1 != 0.0) {

      *(float *)(iVar6 + -4 + param_1) = fVar5;

    }

    iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

    iVar3 = *(int *)(*(int *)(iVar6 + 0x18 + param_1) + 0xe4f8);

    if ((float)*(int *)(iVar3 + 0x10) * *(float *)(iVar3 + 0x18) <

        *(float *)(iVar6 + -0xc + param_1)) {

      iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

      iVar3 = *(int *)(*(int *)(iVar6 + 0x18 + param_1) + 0xe4f8);

      *(float *)(iVar6 + param_1 + -0xc) =

           (float)*(int *)(iVar3 + 0x10) * *(float *)(iVar3 + 0x18) - fVar5;

    }

    iVar3 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

    iVar4 = *(int *)(*(int *)(iVar3 + 0x18 + param_1) + 0xe4f8);

    iVar6 = iVar3 + param_1;

    if ((float)*(int *)(iVar4 + 0x14) * *(float *)(iVar4 + 0x18) < *(float *)(iVar3 + -4 + param_1))

    {

      iVar6 = *(int *)(*(int *)(param_1 + -0x8c) + 4);

      iVar3 = *(int *)(*(int *)(iVar6 + 0x18 + param_1) + 0xe4f8);

      iVar6 = iVar6 + param_1;

      *(float *)(iVar6 + -4) = (float)*(int *)(iVar3 + 0x14) * *(float *)(iVar3 + 0x18) - fVar5;

    }

  }

  return CONCAT31((int3)((uint)iVar6 >> 8),1);

}
