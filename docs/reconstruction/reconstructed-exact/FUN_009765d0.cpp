// =============================================================================
// FUN_009765d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009765d0
// Address:   0x009765d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009765d0 @ 0x009765d0
// Stable ID: aa_009765d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×17, goto×4, return×3.
//  - Notable callees: FUN_00567e90×2, CONCAT31, FUN_009765d0, GetTickCount.
//  - Return sites: 3.

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



uint FUN_009765d0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  int in_EAX;

  DWORD DVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  float *unaff_EDI;

  float fVar8;

  float fVar9;

  float fVar10;

  float local_30;

  int local_20;

  int local_1c;

  int local_18;

  int local_14;

  

  uVar5 = 0;

  if ((*(int *)(in_EAX + 0x6c) == 0) ||

     (uVar5 = 0, (*(int *)(in_EAX + 0x70) - *(int *)(in_EAX + 0x6c)) / 0x28 == 0)) {

LAB_00976600:

    return CONCAT31((int3)(uVar5 >> 8),1);

  }

  DVar4 = GetTickCount();

  iVar2 = *(int *)(in_EAX + 4);

  iVar7 = DVar4 - *(int *)(in_EAX + 8);

  uVar5 = 0;

  if (*(int *)(in_EAX + 0x6c) != 0) {

    uVar5 = (*(int *)(in_EAX + 0x70) - *(int *)(in_EAX + 0x6c)) / 0x28;

  }

  uVar3 = *(uint *)(in_EAX + 0x60);

  if (uVar5 <= uVar3) {

    if (*(char *)(in_EAX + 0x30) != '\0') {

      fVar8 = (float)iVar7;

      if (iVar7 < 0) {

        fVar8 = fVar8 + _DAT_00aaa5dc;

      }

      if (fVar8 * g_flMsToSeconds_Inferred < *(float *)(in_EAX + 0x34)) {

        fVar8 = (fVar8 * g_flMsToSeconds_Inferred) / *(float *)(in_EAX + 0x34);

        if (g_flOne <= fVar8) {

          fVar8 = g_flOne;

        }

        fVar9 = g_flOne - fVar8;

        *unaff_EDI = *(float *)(in_EAX + 0x40) * fVar9 + *(float *)(in_EAX + 0x10) * fVar8;

        unaff_EDI[1] = *(float *)(in_EAX + 0x44) * fVar9 + *(float *)(in_EAX + 0x14) * fVar8;

        unaff_EDI[2] = *(float *)(in_EAX + 0x48) * fVar9 + *(float *)(in_EAX + 0x18) * fVar8;

        unaff_EDI[3] = *(float *)(in_EAX + 0x4c) * fVar9 + *(float *)(in_EAX + 0x1c) * fVar8;

        uVar5 = FUN_00567e90(in_EAX + 0x50,in_EAX + 0x20,fVar8);

        return uVar5 & 0xffffff00;

      }

    }

    goto LAB_00976600;

  }

  piVar1 = (int *)(*(int *)(in_EAX + 0x6c) + uVar3 * 0x28);

  local_30 = g_flOne;

  if (*(int *)(*(int *)(in_EAX + 0x6c) + uVar3 * 0x28) == 0) goto LAB_009767eb;

  if ((int)(uVar3 - 1) < 0) {

    local_30 = (float)iVar7;

    if (iVar7 < 0) {

      local_30 = local_30 + _DAT_00aaa5dc;

    }

    fVar8 = (float)*piVar1;

    if (*piVar1 < 0) {

      fVar8 = fVar8 + _DAT_00aaa5dc;

    }

    if (local_30 / fVar8 < g_flOne) {

      iVar6 = *piVar1;

      iVar7 = *piVar1;

      goto LAB_009767c8;

    }

  }

  else {

    local_30 = (float)iVar7;

    if (iVar7 < 0) {

      local_30 = local_30 + _DAT_00aaa5dc;

    }

    fVar8 = (float)(*piVar1 - piVar1[-10]);

    if (*piVar1 - piVar1[-10] < 0) {

      fVar8 = fVar8 + _DAT_00aaa5dc;

    }

    if (local_30 / fVar8 < g_flOne) {

      iVar6 = *piVar1 - piVar1[-10];

      iVar7 = iVar6;

LAB_009767c8:

      fVar8 = (float)iVar7;

      if (iVar6 < 0) {

        fVar8 = fVar8 + _DAT_00aaa5dc;

      }

      local_30 = local_30 / fVar8;

      goto LAB_009767eb;

    }

  }

  local_30 = g_flOne;

LAB_009767eb:

  fVar8 = (float)piVar1[2];

  fVar9 = (float)piVar1[3];

  local_14 = piVar1[7];

  local_20 = piVar1[4];

  local_1c = piVar1[5];

  local_18 = piVar1[6];

  fVar10 = g_flOne - local_30;

  *unaff_EDI = (float)piVar1[1] * local_30 + *(float *)(in_EAX + 0x40) * fVar10;

  unaff_EDI[1] = *(float *)(in_EAX + 0x44) * fVar10 + fVar8 * local_30;

  fVar8 = local_30 * g_flZero;

  unaff_EDI[2] = *(float *)(in_EAX + 0x48) * fVar10 + fVar9 * local_30;

  unaff_EDI[3] = *(float *)(in_EAX + 0x4c) * fVar10 + fVar8;

  FUN_00567e90((uint32_t /* width from decompiler */ *)(in_EAX + 0x50),&local_20,local_30);

  uVar5 = *(uint *)(in_EAX + 0x60);

  if (*(uint *)(*(int *)(in_EAX + 0x6c) + uVar5 * 0x28) <= DVar4 - iVar2) {

    *(uint *)(in_EAX + 0x60) = uVar5 + 1;

    *(uint *)(in_EAX + 100) = uVar5 + 1;

    *(DWORD *)(in_EAX + 8) = DVar4;

    *(float *)(in_EAX + 0x40) = *unaff_EDI;

    *(float *)(in_EAX + 0x44) = unaff_EDI[1];

    *(float *)(in_EAX + 0x48) = unaff_EDI[2];

    *(float *)(in_EAX + 0x4c) = unaff_EDI[3];

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x50) = *param_1;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x54) = param_1[1];

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x58) = param_1[2];

    uVar5 = param_1[3];

    *(uint *)(in_EAX + 0x5c) = uVar5;

  }

  return uVar5 & 0xffffff00;

}
