// =============================================================================
// FUN_00752df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00752df0
// Address:   0x00752df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752df0 @ 0x00752df0
// Stable ID: aa_00752df0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, switch×1, goto×1, while×1.
//  - Notable callees: FUN_00412d80×2, FUN_00435b40×2, FUN_00752df0, FUN_00969e50, FUN_00969fc0.
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

void FUN_00752df0(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint32_t /* width from decompiler */ *param_4,int param_5,

                 uint32_t /* width from decompiler */ param_6)



{

  int *piVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  uint8_t *puVar5;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ *puVar6;

  int local_124;

  uint32_t /* width from decompiler */ uStack_120;

  uint32_t /* width from decompiler */ uStack_11c;

  uint32_t /* width from decompiler */ uStack_118;

  float fStack_114;

  uint8_t auStack_110 [64];

  uint8_t local_d0 [64];

  uint8_t auStack_90 [64];

  uint8_t local_50 [76];

  

  local_124 = *(int *)(in_EAX + 0x40);

  if (local_124 < 1) {

    if (param_3 != 1) {

      param_2 = &DAT_00d1ec20;

    }

    (**(code **)(*(int *)*DAT_00d1f044 + 0xb0))((int *)*DAT_00d1f044,0x100,param_2);

    return;

  }

  piVar1 = *(int **)(*(int *)(param_1 + 8) + 0xc);

  puVar6 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x48);

  do {

    switch(puVar6[-1]) {

    case 0:

      (**(code **)(*piVar1 + 0x98))(piVar1,*puVar6,param_2);

      break;

    case 1:

      iVar2 = *(int *)(param_1 + 8);

      uVar3 = *puVar6;

      piVar4 = *(int **)(iVar2 + 0xc);

      (**(code **)(*piVar4 + 0xa0))(piVar4,uVar3,param_2,param_3);

      piVar4 = *(int **)(iVar2 + 0xc);

      (**(code **)(*piVar4 + 0xe0))(piVar4,uVar3,0,param_3);

      break;

    case 2:

      iVar2 = *(int *)(param_1 + 8);

      piVar4 = *(int **)(iVar2 + 0xc);

      (**(code **)(*piVar4 + 0x80))(piVar4,*puVar6,param_6,param_5 + 1);

      piVar4 = *(int **)(iVar2 + 0xc);

      (**(code **)(*piVar4 + 0xe0))(piVar4,unaff_EBX,0,param_5 + 1);

      break;

    case 3:

      puVar5 = auStack_90;

      FUN_00435b40();

      piVar4 = piVar1;

      goto LAB_00752fd3;

    case 8:

      FUN_00412d80(auStack_110,param_2,DAT_00d1f05c + 0x30);

      piVar4 = *(int **)(*(int *)(param_1 + 8) + 0xc);

      (**(code **)(*piVar4 + 0x98))(piVar4,*puVar6,auStack_110);

      break;

    case 9:

      iVar2 = *piVar1;

      uVar3 = FUN_00969fc0(0xffffffff);

      (**(code **)(iVar2 + 0x50))(piVar1,*puVar6,uVar3);

      break;

    case 10:

      iVar2 = *piVar1;

      uVar3 = FUN_00969e50(0xffffffff);

      (**(code **)(iVar2 + 0x50))(piVar1,*puVar6,uVar3);

      break;

    case 0xb:

      uStack_120 = *param_4;

      uStack_11c = param_4[1];

      uStack_118 = param_4[2];

      fStack_114 = g_flOne;

      (**(code **)(*piVar1 + 0x88))(piVar1,*puVar6,&uStack_120);

      break;

    case 0xc:

      FUN_00412d80(local_d0,param_2,DAT_00d1f05c + 0xb0);

      puVar5 = local_50;

      FUN_00435b40();

      piVar4 = *(int **)(*(int *)(param_1 + 8) + 0xc);

LAB_00752fd3:

      (**(code **)(*piVar4 + 0x98))(piVar4,*puVar6,puVar5);

    }

    puVar6 = puVar6 + 2;

    local_124 = local_124 + -1;

    if (local_124 == 0) {

      return;

    }

  } while( true );

}
