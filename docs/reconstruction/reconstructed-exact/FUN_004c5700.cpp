// =============================================================================
// FUN_004c5700
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5700
// Address:   0x004c5700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c5700 @ 0x004c5700
// Stable ID: aa_004c5700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0053e090×13, FUN_0040d2a0×2, CVOGPhysics_ApplyImpulseVector, FUN_00404c90, FUN_004c5700, FUN_004cd220, SQRT.
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

void __fastcall FUN_004c5700(int param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  float10 fVar10;

  

  iVar6 = *(int *)(param_1 + -0x4f8);

  if ((iVar6 == 0) || ((*(char *)(iVar6 + 0x40) != '\0' && (*(int *)(iVar6 + 8) != 0)))) {

    *(uint8_t *)(param_1 + -0x4e0) = 0;

  }

  else {

    if (*(char *)(param_1 + -0x4e0) == '\0') {

      *(uint8_t *)(param_1 + -0x4e0) = 1;

      if (*(int *)(param_1 + -0x4f8) == 0) {

        puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + param_1 + -0x47c);

      }

      else {

        puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4f8) + 0x3c) + 0xb0);

      }

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_0053e090();

      *puVar7 = *puVar9;

      puVar7[1] = puVar9[1];

      puVar7[2] = puVar9[2];

      puVar7[3] = puVar9[3];

      iVar6 = *(int *)(*(int *)(param_1 + -0x4f8) + 0x3c);

      iVar8 = FUN_0053e090();

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x40);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x44);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x48);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x4c);

      iVar6 = *(int *)(*(int *)(param_1 + -0x4f8) + 0x3c);

      iVar8 = FUN_0053e090();

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x50);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x54);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x58);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x5c);

      return;

    }

    if (*(int *)(param_1 + -0x4f8) == 0) {

      pfVar4 = (float *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + param_1 + -0x47c);

    }

    else {

      pfVar4 = (float *)(*(int *)(*(int *)(param_1 + -0x4f8) + 0x3c) + 0xb0);

    }

    fVar1 = *pfVar4;

    fVar2 = pfVar4[1];

    fVar3 = pfVar4[2];

    pfVar4 = (float *)FUN_0053e090();

    if (SQRT((fVar1 - *pfVar4) * (fVar1 - *pfVar4) +

             (fVar2 - pfVar4[1]) * (fVar2 - pfVar4[1]) + (fVar3 - pfVar4[2]) * (fVar3 - pfVar4[2]))

        <= DAT_00a0f694) {

      puVar9 = (uint32_t /* width from decompiler */ *)FUN_00404c90();

      puVar7 = (uint32_t /* width from decompiler */ *)FUN_0053e090();

      *puVar7 = *puVar9;

      puVar7[1] = puVar9[1];

      puVar7[2] = puVar9[2];

      puVar7[3] = puVar9[3];

      iVar6 = *(int *)(*(int *)(param_1 + -0x4f8) + 0x3c);

      iVar8 = FUN_0053e090();

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x40);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x44);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x48);

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x4c);

    }

    else {

      uVar5 = FUN_0053e090();

      FUN_0040d2a0(uVar5);

      iVar6 = FUN_0053e090();

      CVOGPhysics_ApplyImpulseVector(iVar6 + 0x20);

    }

    iVar6 = FUN_0053e090();

    puVar9 = (uint32_t /* width from decompiler */ *)FUN_0053e090();

    fVar10 = (float10)FUN_004cd220(*puVar9,*(uint32_t /* width from decompiler */ *)(iVar6 + 8));

    iVar6 = FUN_0053e090();

    if (*(float *)(iVar6 + 4) < (float)fVar10) {

      iVar6 = FUN_0053e090();

      *(float *)(iVar6 + 4) = (float)fVar10;

      uVar5 = FUN_0053e090();

      FUN_0040d2a0(uVar5);

      return;

    }

  }

  return;

}
