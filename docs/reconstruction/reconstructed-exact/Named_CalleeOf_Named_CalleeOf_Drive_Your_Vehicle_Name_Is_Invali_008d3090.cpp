// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_008d3090
// -----------------------------------------------------------------------------
// Stable ID: aa_008d3090
// Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
// Address:   0x008d3090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: SQRT×8, FUN_008cf7f0, FUN_008d3090, FUN_0090f8e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invalid_Please_Choose
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Drive_Your_Vehicle_Name_Is_Invali_008d3090(void)



{

  float *pfVar1;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  

  if (DAT_00d1b77c != 0) {

    *(uint8_t *)(unaff_ESI + 0x5bc) = 0;

    iVar3 = DAT_00d1b77c;

    fVar5 = *(float *)(DAT_00d1b77c + 0x5f0) - *(float *)(DAT_00d1b77c + 0x608);

    iVar2 = *(int *)(*(int *)(DAT_00d1b77c + 0x2a4) + 8);

    pfVar1 = (float *)(DAT_00d1b77c + 0x600);

    fVar6 = *(float *)(DAT_00d1b77c + 0x5ec) - *(float *)(DAT_00d1b77c + 0x604);

    fVar7 = *(float *)(DAT_00d1b77c + 0x5e8) - *pfVar1;

    local_44 = g_flOne;

    fVar10 = *(float *)(DAT_00d1b77c + 0x604) - *(float *)(iVar2 + 0x94);

    fVar4 = *(float *)(DAT_00d1b77c + 0x600) - *(float *)(iVar2 + 0x90);

    fVar9 = *(float *)(DAT_00d1b77c + 0x608) - *(float *)(iVar2 + 0x98);

    fVar8 = fVar4 * fVar4 + fVar10 * fVar10 + fVar9 * fVar9;

    if (g_flZero < SQRT(fVar8)) {

      local_44 = SQRT(fVar6 * fVar6 + fVar5 * fVar5 + fVar7 * fVar7) / SQRT(fVar8);

    }

    if (g_flZero == SQRT(fVar8)) {

      local_24 = *pfVar1;

      local_20 = *(float *)(DAT_00d1b77c + 0x604);

      local_1c = *(float *)(DAT_00d1b77c + 0x608);

      *(float *)(DAT_00d1b77c + 0x5e8) = *pfVar1;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x5ec) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x604);

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x5f0) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x608);

    }

    else {

      local_44 = *(float *)(unaff_ESI + 0x5b8) * local_44;

      fVar5 = g_flOne;

      if (local_44 < g_flOne) {

        fVar5 = local_44;

      }

      local_1c = *(float *)(iVar2 + 0x98) + fVar5 * fVar9;

      local_20 = *(float *)(iVar2 + 0x94) + fVar5 * fVar10;

      local_24 = fVar4 * fVar5 + *(float *)(iVar2 + 0x90);

      *(uint8_t *)(unaff_ESI + 0x5bc) = 1;

    }

    iVar2 = DAT_00d1b77c;

    local_30 = *(float *)(DAT_00d1b77c + 0x5c4);

    local_2c = *(float *)(DAT_00d1b77c + 0x5c8);

    local_28 = *(float *)(DAT_00d1b77c + 0x5cc);

    fVar9 = *(float *)(DAT_00d1b77c + 0x5d0) - local_30;

    fVar10 = *(float *)(DAT_00d1b77c + 0x5dc) - *(float *)(DAT_00d1b77c + 0x5d0);

    fVar4 = *(float *)(DAT_00d1b77c + 0x5d8) - local_28;

    fVar5 = *(float *)(DAT_00d1b77c + 0x5e4) - *(float *)(DAT_00d1b77c + 0x5d8);

    fVar7 = *(float *)(DAT_00d1b77c + 0x5d4) - local_2c;

    fVar8 = *(float *)(DAT_00d1b77c + 0x5e0) - *(float *)(DAT_00d1b77c + 0x5d4);

    local_44 = g_flOne;

    fVar6 = fVar4 * fVar4 + fVar7 * fVar7 + fVar9 * fVar9;

    if (g_flZero < SQRT(fVar6)) {

      local_44 = SQRT(fVar10 * fVar10 + fVar8 * fVar8 + fVar5 * fVar5) / SQRT(fVar6);

    }

    if (g_flZero == SQRT(fVar6)) {

      *(float *)(DAT_00d1b77c + 0x5dc) = *(float *)(DAT_00d1b77c + 0x5d0);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5e0) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5d4);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5e4) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5d8);

      iVar2 = DAT_00d1b77c;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x5c4) = *(uint32_t /* width from decompiler */ *)(DAT_00d1b77c + 0x5d0);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5c8) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5d4);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5cc) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x5d8);

      local_30 = *(float *)(DAT_00d1b77c + 0x5d0);

      local_2c = *(float *)(DAT_00d1b77c + 0x5d4);

      local_28 = *(float *)(DAT_00d1b77c + 0x5d8);

    }

    else {

      local_44 = *(float *)(unaff_ESI + 0x5b8) * local_44;

      if (g_flOne <= local_44) {

        local_44 = g_flOne;

      }

      *(uint8_t *)(unaff_ESI + 0x5bc) = 1;

      iVar2 = DAT_00d1b77c;

      local_30 = fVar9 * local_44 + local_30;

      local_2c = fVar7 * local_44 + local_2c;

      *(float *)(DAT_00d1b77c + 0x5c4) = local_30;

      local_28 = local_28 + fVar4 * local_44;

      *(float *)(iVar2 + 0x5c8) = local_2c;

      *(float *)(iVar2 + 0x5cc) = local_28;

    }

    FUN_0090f8e0(local_24,local_20,local_1c,local_30,local_2c,local_28);

    if (*(char *)(unaff_ESI + 0x5bc) == '\0') {

      FUN_008cf7f0(1);

    }

  }

  return;

}
