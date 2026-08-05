// =============================================================================
// PhysSim_LtBroadPhase_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00629d90
// Address:   0x00629d90  (autoassault.exe, image base 0x400000)
// System:    physics / sub-island broadphase + narrowphase
// Generated: 2026-07-29 W28-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// PURPOSE: Sub-island "LtBroadPhase" pipeline: AABB expand, 3-axis sweep pair gen,
// optional static-pair merge, commit pair list (FUN_006297e0), then narrowphase.
// NOT integrate / applyAction (see FUN_00628f70 under FUN_00561b60).
// ABI: thiscall; ECX=subIsland; 2 stack args; ret 8.
// Profile: "LtBroadPhase", "StCalcAabbs", "St3AxisSweep", "StExamine".
// Constant: DAT_00a0f298 = 0.5f margin scale.
// Name: Ghidra FUN_00629d90; inferred PhysSim_LtBroadPhase_Inferred.
//

#include <cstdint>

// Decompiler residual: Ghidra shows (uint param_1, int *param_2) with param_1 in ECX.
// Call site (FUN_00561910): ECX=subIsland, push stepBlock, push ctx → ret 8.
// Body uses ECX object as sub-island throughout.

void __thiscall PhysSim_LtBroadPhase_Inferred(uint32_t subIsland /* ECX */, int *stepBlockOrCtx /* stack */)
{
  float fVar1;
  int iVar2;
  uint64_t uVar3;
  float fVar4;
  float fVar5;
  uint32_t uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  uint8_t *puVar12;
  int *piStack_44;
  int local_40;
  int iStack_3c;
  float fStack_38;
  uint32_t local_34;
  uint32_t local_30;
  int local_2c;
  uint32_t local_28;
  uint32_t uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  uint8_t local_14[4];
  uint32_t uStack_10;
  uint32_t uStack_c;

  // profile open "LtBroadPhase"
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)"LtBroadPhase";
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }

  local_34 = subIsland;
  FUN_0062d960(*(uint32_t *)(*(int *)(subIsland + 0x20) + 0x238));
  FUN_0062d960(*(uint32_t *)(*(int *)(subIsland + 0x20) + 0x238));

  // scratch: bodyCount * 0x20 AABB slots
  piVar11 = DAT_00b05060;
  iVar10 = *(int *)(subIsland + 0x40);
  piVar9 = DAT_00b05060 + 3;
  local_2c = iVar10 * 0x20;
  if (*piVar9 < local_2c) {
    local_40 = (**(int (**)(int))(*DAT_00b05060 + 0x24))(local_2c);
  } else {
    local_40 = DAT_00b05060[2];
    DAT_00b05060[2] = local_40 + local_2c;
    piVar11[3] = *piVar9 + iVar10 * -0x20;
  }

  // scratch: aligned pointer table
  piVar11 = DAT_00b05060;
  piVar9 = DAT_00b05060 + 3;
  local_30 = iVar10 * 4 + 0xfU & 0xfffffff0;
  if (*piVar9 < (int)local_30) {
    piStack_44 = (int *)(**(int (**)(int))(*DAT_00b05060 + 0x24))(local_30);
  } else {
    piStack_44 = (int *)DAT_00b05060[2];
    DAT_00b05060[2] = (int)piStack_44 + local_30;
    piVar11[3] = *piVar9 - local_30;
  }

  // margin = *(float*)(*(parentWorld+0xcc)+8) * 0.5f
  fStack_38 = *(float *)(*(int *)(*(int *)(subIsland + 0x20) + 0xcc) + 8) * DAT_00a0f298;

  // "StCalcAabbs"
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)"StCalcAabbs";
    uVar3 = rdtsc();
    iStack_3c = (int)uVar3;
    DAT_00bc5644[1] = iStack_3c;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  iVar10 = *(int *)(subIsland + 0x40);
  piVar9 = *(int **)(subIsland + 0x3c);
  iVar8 = local_40;
  piVar11 = piStack_44;
  if (-1 < iVar10 + -1) {
    do {
      iVar2 = *piVar9;
      if ((uint32_t *)(iVar2 + 0xc) == (uint32_t *)0x0) {
        iVar7 = 0;
      } else {
        iVar7 = iVar2 + 0x1c;
      }
      *piVar11 = iVar7;
      (**(code **)(**(int **)(iVar2 + 0xc) + 0x18))(*(int *)(iVar2 + 0x14) + 0x20, fStack_38, iVar8);
      piVar9 = piVar9 + 1;
      iVar10 = iVar10 + -1;
      subIsland = local_34;
      iVar8 = iVar8 + 0x20;
      piVar11 = piVar11 + 1;
    } while (iVar10 != 0);
  }

  // "St3AxisSweep"
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)"St3AxisSweep";
    uVar3 = rdtsc();
    local_34 = (uint32_t)uVar3;
    DAT_00bc5644[1] = local_34;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  puVar12 = local_14;
  (**(code **)(*stepBlockOrCtx + 0x14))(piStack_44, local_40, *(uint32_t *)(subIsland + 0x40), &local_28);
  fVar4 = fStack_38;

  // "StExamine"
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)"StExamine";
    uVar3 = rdtsc();
    uStack_10 = (uint32_t)uVar3;
    DAT_00bc5644[1] = uStack_10;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }

  // optional static-pair merge from subIsland+0x74/+0x78
  if (0 < *(int *)(subIsland + 0x78)) {
    fVar1 = (float)(*(int *)(subIsland + 0x78) + (int)fStack_38);
    if ((int)(local_34 & 0x7fffffff) < (int)fVar1) {
      fVar5 = (float)((local_34 & 0x7fffffff) * 2);
      if ((int)fVar5 <= (int)fVar1) {
        fVar5 = fVar1;
      }
      FUN_005b3300(&iStack_3c, fVar5, 8);
    }
    iVar10 = 0;
    if (0 < *(int *)(subIsland + 0x78)) {
      iVar8 = (int)fVar4 * 8;
      do {
        iVar2 = *(int *)(subIsland + 0x74);
        *(uint32_t *)(iVar8 + iStack_3c) = *(uint32_t *)(iVar2 + iVar10 * 8);
        *(uint32_t *)(iVar8 + 4 + iStack_3c) = *(uint32_t *)(iVar2 + 4 + iVar10 * 8);
        iVar10 = iVar10 + 1;
        iVar8 = iVar8 + 8;
      } while (iVar10 < *(int *)(subIsland + 0x78));
    }
    *(uint32_t *)(subIsland + 0x78) = 0;
    fStack_38 = fVar1;
  }

  // free AABB pointer table
  piVar9 = DAT_00b05060;
  if ((piStack_44 == (int *)0x0) ||
      ((puVar12 != (uint8_t *)DAT_00b05060[5] &&
        ((uint8_t *)DAT_00b05060[5] != (uint8_t *)0x0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - (int)piStack_44;
    piVar9[3] = piVar9[3] + (int)piStack_44;
  } else {
    (**(code **)(*DAT_00b05060 + 0x28))(puVar12, piStack_44);
  }

  // free AABB buffer
  piVar9 = DAT_00b05060;
  if ((local_40 == 0) || ((local_40 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - local_40;
    piVar9[3] = piVar9[3] + local_40;
  } else {
    (**(code **)(*DAT_00b05060 + 0x28))(local_40, local_40);
  }

  // commit pairs into sub-island collision storage
  FUN_006297e0(iStack_3c, fStack_38, local_28, uStack_24);
  *(uint8_t *)(subIsland + 0x30) = 1;

  // profile close "lt"
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)&DAT_009d282c;
    uVar3 = rdtsc();
    uStack_10 = (uint32_t)uVar3;
    DAT_00bc5644[1] = uStack_10;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }

  // free pair-related scratch (tag 0x12)
  piVar9 = DAT_00b05060;
  uVar6 = iStack_18 * 8 + 0xfU & 0xfffffff0;
  if ((uVar6 == 0) || ((iStack_1c != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - uVar6;
    piVar9[3] = piVar9[3] + uVar6;
  } else {
    (**(code **)(*DAT_00b05060 + 0x28))(iStack_1c, uVar6);
  }
  if (-1 < iStack_20) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_28, iStack_20 * 8, 0x12);
  }
  piVar9 = DAT_00b05060;
  uVar6 = local_2c * 8 + 0xfU & 0xfffffff0;
  if ((uVar6 == 0) || ((local_30 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {
    DAT_00b05060[2] = DAT_00b05060[2] - uVar6;
    piVar9[3] = piVar9[3] + uVar6;
  } else {
    (**(code **)(*DAT_00b05060 + 0x28))(local_30, uVar6);
  }
  if (-1 < (int)local_34) {
    (**(code **)(*DAT_00b05060 + 0x14))(iStack_3c, local_34 * 8, 0x12);
  }

  // narrowphase branch on parentWorld+0x23e
  if (*(char *)(*(int *)(subIsland + 0x20) + 0x23e) == '\0') {
    FUN_00629c40(uStack_c);
    return;
  }
  FUN_00629990(uStack_c);
  return;
}

// External symbols (not owned by this dual):
// DAT_00bc5644/48, DAT_00b05060, DAT_00a0f298 (0.5f), DAT_009d282c ("lt")
// FUN_0062d960, FUN_005b3300, FUN_006297e0, FUN_00629c40, FUN_00629990, rdtsc
