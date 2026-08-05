// =============================================================================
// FUN_006e3850
// -----------------------------------------------------------------------------
// Stable ID: aa_006e3850
// Address:   0x006e3850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e3850 @ 0x006e3850
// Stable ID: aa_006e3850
// Embedded strings (evidence for future rename):
//   - "TtSphereSphere"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: rdtsc×2, FUN_006e3850, SQRT.
//  - Strings: "TtSphereSphere".
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

void FUN_006e3850(int *param_1,int *param_2,int param_3,int *param_4)



{

  float fVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint64_t uVar5;

  float fVar6;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  int *local_20;

  int *local_1c;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtSphereSphere";

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  iVar2 = *param_2;

  local_20 = param_1;

  iVar3 = param_1[2];

  local_1c = param_2;

  iVar4 = param_2[2];

  local_30 = *(float *)(iVar3 + 0x50) - *(float *)(iVar4 + 0x50);

  local_2c = *(float *)(iVar3 + 0x54) - *(float *)(iVar4 + 0x54);

  local_28 = *(float *)(iVar3 + 0x58) - *(float *)(iVar4 + 0x58);

  fVar1 = local_30 * local_30 + local_2c * local_2c + local_28 * local_28;

  fVar6 = *(float *)(param_3 + 8) + *(float *)(iVar2 + 0xc) + *(float *)(*param_1 + 0xc);

  if (fVar1 < fVar6 * fVar6) {

    if (fVar1 <= g_flZero) {

      local_30 = DAT_00af4f90;

      local_2c = DAT_00af4f94;

      local_28 = DAT_00af4f98;

      local_24 = DAT_00af4f9c;

      local_34 = g_flZero;

    }

    else {

      fVar6 = g_flOne / SQRT(fVar1);

      local_30 = local_30 * fVar6;

      local_2c = local_2c * fVar6;

      local_28 = local_28 * fVar6;

      local_24 = (*(float *)(iVar3 + 0x5c) - *(float *)(iVar4 + 0x5c)) * fVar6;

      local_34 = fVar6 * fVar1;

    }

    fVar1 = *(float *)(iVar2 + 0xc);

    local_40 = local_30 * fVar1 + *(float *)(iVar4 + 0x50);

    local_3c = local_2c * fVar1 + *(float *)(iVar4 + 0x54);

    local_38 = local_28 * fVar1 + *(float *)(iVar4 + 0x58);

    local_34 = local_34 - (*(float *)(iVar2 + 0xc) + *(float *)(*param_1 + 0xc));

    (**(code **)(*param_4 + 4))(&local_40);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar5 = rdtsc();

    DAT_00bc5644[1] = (int)uVar5;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
