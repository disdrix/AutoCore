// =============================================================================
// FUN_00658c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00658c80
// Address:   0x00658c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00658c80 @ 0x00658c80
// Stable ID: aa_00658c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_005070b0×3, FUN_005070d0×3, FUN_006456f0×2, FUN_005d68f0, FUN_005d6ae0, FUN_00645450, FUN_00645580, FUN_00645890.
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

void __thiscall FUN_00658c80(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  int iVar5;

  char *pcVar6;

  float unaff_ESI;

  float unaff_EDI;

  float fVar7;

  float fStack_184;

  float local_180;

  float local_17c;

  float local_178;

  float local_174;

  float fStack_168;

  float fStack_164;

  float fStack_160;

  float fStack_15c;

  float fStack_158;

  uint32_t /* width from decompiler */ local_154;

  float local_150;

  float local_14c;

  float local_148;

  float local_144;

  float fStack_140;

  float fStack_13c;

  float fStack_138;

  uint8_t auStack_134 [8];

  uint8_t auStack_12c [8];

  uint8_t auStack_124 [4];

  float local_120;

  float local_11c;

  float local_118;

  float local_114;

  uint32_t /* width from decompiler */ uStack_110;

  uint32_t /* width from decompiler */ uStack_10c;

  uint32_t /* width from decompiler */ uStack_108;

  uint32_t /* width from decompiler */ uStack_104;

  float fStack_100;

  uint32_t /* width from decompiler */ uStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  float fStack_f4;

  float fStack_f0;

  float fStack_ec;

  float fStack_e8;

  uint8_t auStack_d4 [48];

  uint8_t auStack_a4 [4];

  uint8_t local_a0 [44];

  uint8_t auStack_74 [48];

  uint8_t auStack_44 [64];

  

  iVar4 = *(int *)(param_1 + 0x18);

  FUN_005d68f0(*(int *)(iVar4 + 0x3c) + 0x80);

  iVar5 = *(int *)(iVar4 + 0x3c);

  local_150 = local_120 - *(float *)(param_1 + 0x30);

  local_180 = local_120 - *(float *)(iVar5 + 0x70);

  local_14c = local_11c - *(float *)(param_1 + 0x34);

  local_148 = local_118 - *(float *)(param_1 + 0x38);

  local_144 = local_114 - *(float *)(param_1 + 0x3c);

  local_154 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x2c);

  local_17c = local_11c - *(float *)(iVar5 + 0x74);

  local_178 = local_118 - *(float *)(iVar5 + 0x78);

  local_174 = local_114 - *(float *)(iVar5 + 0x7c);

  FUN_00645450();

  (**(code **)(**(int **)(iVar4 + 0x3c) + 0x38))();

  uStack_108 = 0;

  uStack_10c = 0;

  uStack_110 = 0;

  uStack_f8 = 0;

  uStack_fc = 0;

  uStack_104 = 0;

  fStack_e8 = 0.0;

  fStack_f0 = 0.0;

  fStack_f4 = 0.0;

  local_114 = fStack_158;

  fStack_100 = fStack_158;

  fStack_ec = fStack_158;

  FUN_006456f0(auStack_d4,auStack_a4);

  FUN_006456f0(auStack_74,auStack_d4);

  FUN_00645580(auStack_44);

  iVar5 = FUN_00645890(0x33d6bf95);

  if (iVar5 == 0) {

    iVar5 = *(int *)(iVar4 + 0x3c);

    fStack_138 = *(float *)(param_1 + 0x4c);

    local_144 = *(float *)(iVar5 + 0x40) * fStack_138;

    fStack_140 = *(float *)(iVar5 + 0x44) * fStack_138;

    fStack_13c = *(float *)(iVar5 + 0x48) * fStack_138;

    fStack_138 = *(float *)(iVar5 + 0x4c) * fStack_138;

    pcVar6 = (char *)FUN_005070b0(&stack0xfffffe7b);

    if ((*pcVar6 == '\0') && (*(int *)(iVar4 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar4 + 0x3c) + 0x50))(&local_144);

    iVar5 = *(int *)(iVar4 + 0x3c);

    fVar1 = *(float *)(iVar5 + 0x50);

    fVar2 = *(float *)(param_1 + 0x4c);

    fStack_184 = *(float *)(iVar5 + 0x54) * fVar2;

    local_180 = *(float *)(iVar5 + 0x58) * fVar2;

    local_17c = *(float *)(iVar5 + 0x5c) * fVar2;

    pcVar6 = (char *)FUN_005070b0(&stack0xfffffe77);

    if ((*pcVar6 == '\0') && (*(int *)(iVar4 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar4 + 0x3c) + 0x54))(&stack0xfffffe78);

    (**(code **)(**(int **)(iVar4 + 0x3c) + 0x58))(auStack_12c,&stack0xfffffe74);

    fVar7 = *(float *)(param_1 + 0x44) * param_2[1];

    fVar3 = *(float *)(param_1 + 0x40);

    fStack_f4 = (float)local_a0 * fVar3 + fVar7 * fStack_164;

    fStack_f0 = unaff_EDI * fVar3 + fStack_160 * fVar7;

    fStack_ec = unaff_ESI * fVar3 + fStack_15c * fVar7;

    fStack_e8 = fVar1 * fVar2 * fVar3 + fStack_158 * fVar7;

    FUN_005d6ae0(auStack_124,&fStack_f4);

    fStack_138 = 0.0;

    local_178 = 0.0 - local_178;

    local_180 = 0.0 - local_180;

    fStack_184 = 0.0 - fStack_184;

    local_17c = 0.0 - local_17c;

    fVar1 = *(float *)(*(int *)(iVar4 + 0x3c) + 0x2c);

    fStack_168 = local_17c * local_17c + local_180 * local_180 + fStack_184 * fStack_184;

    if (fVar1 != 0.0) {

      fStack_138 = g_flOne / fVar1;

    }

    fStack_138 = *(float *)(param_1 + 0x48) * *param_2 * fStack_138;

    if (fStack_138 * fStack_138 < fStack_168) {

      fVar1 = fStack_138 / SQRT(fStack_168);

      fStack_184 = fStack_184 * fVar1;

      local_180 = local_180 * fVar1;

      local_17c = local_17c * fVar1;

      local_178 = local_178 * fVar1;

    }

    pcVar6 = (char *)FUN_005070b0(&stack0xfffffe6b);

    if ((*pcVar6 == '\0') && (*(int *)(iVar4 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(iVar4 + 0x3c) + 0x60))(&fStack_184,auStack_134);

  }

  return;

}
