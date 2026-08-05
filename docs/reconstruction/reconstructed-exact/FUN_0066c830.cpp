// =============================================================================
// FUN_0066c830
// -----------------------------------------------------------------------------
// Stable ID: aa_0066c830
// Address:   0x0066c830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066c830 @ 0x0066c830
// Stable ID: aa_0066c830
// Embedded strings (evidence for future rename):
//   - "TtDashpot"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005070b0×2, FUN_005070d0×2, FUN_005d68f0×2, rdtsc×2, FUN_0066c830.
//  - Strings: "TtDashpot".
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



void __thiscall FUN_0066c830(int param_1,float *param_2)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  int iVar10;

  int iVar11;

  uint64_t uVar12;

  char *pcVar13;

  float fVar14;

  float fVar15;

  uint8_t auStack_4d [5];

  uint8_t auStack_48 [3];

  uint8_t local_45;

  float local_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtDashpot";

    uVar12 = rdtsc();

    DAT_00bc5644[1] = (int)uVar12;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_44 = *param_2 * _DAT_009e7a68;

  FUN_005d68f0(*(int *)(*(int *)(param_1 + 0x18) + 0x3c) + 0x80,param_1 + 0x20);

  iVar10 = *(int *)(*(int *)(param_1 + 0x18) + 0x3c);

  FUN_005d68f0(*(int *)(*(int *)(param_1 + 0x1c) + 0x3c) + 0x80,param_1 + 0x30);

  iVar11 = *(int *)(*(int *)(param_1 + 0x1c) + 0x3c);

  fVar2 = *(float *)(iVar10 + 0x40);

  fVar3 = *(float *)(iVar11 + 0x40);

  fVar4 = *(float *)(iVar10 + 0x44);

  fVar5 = *(float *)(iVar10 + 0x48);

  fVar6 = *(float *)(iVar11 + 0x44);

  fVar7 = *(float *)(iVar11 + 0x48);

  fVar8 = *(float *)(iVar10 + 0x4c);

  fVar9 = *(float *)(iVar11 + 0x4c);

  fVar14 = *(float *)(param_1 + 0x40) * local_44;

  pfVar1 = (float *)(param_1 + 0x50);

  *(float *)(param_1 + 0x54) = (local_2c - local_3c) * fVar14;

  *(float *)(param_1 + 0x58) = (local_28 - local_38) * fVar14;

  *(float *)(param_1 + 0x5c) = (local_24 - local_34) * fVar14;

  fVar14 = fVar14 * (local_30 - local_40);

  *pfVar1 = fVar14;

  fVar15 = *(float *)(param_1 + 0x44) * local_44;

  *pfVar1 = fVar14 + fVar15 * (fVar2 - fVar3);

  *(float *)(param_1 + 0x54) = *(float *)(param_1 + 0x54) + (fVar4 - fVar6) * fVar15;

  *(float *)(param_1 + 0x58) = *(float *)(param_1 + 0x58) + (fVar5 - fVar7) * fVar15;

  *(float *)(param_1 + 0x5c) = *(float *)(param_1 + 0x5c) + (fVar8 - fVar9) * fVar15;

  local_20 = *pfVar1 * DAT_00aaa668;

  iVar10 = *(int *)(param_1 + 0x18);

  local_1c = *(float *)(param_1 + 0x54) * DAT_00aaa668;

  local_18 = *(float *)(param_1 + 0x58) * DAT_00aaa668;

  local_14 = *(float *)(param_1 + 0x5c) * DAT_00aaa668;

  pcVar13 = (char *)FUN_005070b0(&local_45);

  if ((*pcVar13 == '\0') && (*(int *)(iVar10 + 0x44) != 0)) {

    FUN_005070d0();

  }

  (**(code **)(**(int **)(iVar10 + 0x3c) + 0x60))(&local_20,&local_30);

  iVar10 = *(int *)(param_1 + 0x1c);

  pcVar13 = (char *)FUN_005070b0(auStack_4d);

  if ((*pcVar13 == '\0') && (*(int *)(iVar10 + 0x44) != 0)) {

    FUN_005070d0();

  }

  (**(code **)(**(int **)(iVar10 + 0x3c) + 0x60))(pfVar1,auStack_48);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar12 = rdtsc();

    DAT_00bc5644[1] = (int)uVar12;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
