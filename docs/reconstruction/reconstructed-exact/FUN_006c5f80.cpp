// =============================================================================
// FUN_006c5f80
// -----------------------------------------------------------------------------
// Stable ID: aa_006c5f80
// Address:   0x006c5f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c5f80 @ 0x006c5f80
// Stable ID: aa_006c5f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0056f570, FUN_006c5f80, FUN_006c6120, FUN_006c6130, FUN_006c6140, FUN_006c61e0, FUN_006d11b0, FUN_006d11d0.
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

uint32_t /* width from decompiler */ FUN_006c5f80(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  float10 fVar4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  uint32_t /* width from decompiler */ local_c0;

  float local_b0;

  float local_ac;

  float local_a8;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  uint8_t auStack_88 [8];

  uint8_t local_80 [124];

  

  FUN_006d11b0(param_1);

  FUN_006d1440(0);

  FUN_006d16b0(0);

  local_d0 = 0x3f800000;

  if (*(char *)(param_2 + 0x2c) == '\0') {

    local_c0 = 0;

  }

  FUN_006d13f0(&local_d0);

  local_b0 = 0.5;

  local_ac = 0.2;

  local_a8 = 1.0;

  local_90 = 4;

  local_a0 = 0x3e4ccccd;

  local_9c = 0x3e4ccccd;

  local_98 = 0x3d4ccccd;

  local_94 = 0;

  fVar4 = (float10)FUN_006c6130();

  local_b0 = (float)fVar4;

  fVar4 = (float10)FUN_006c6140();

  local_ac = (float)fVar4;

  fVar4 = (float10)FUN_006c6120();

  local_a8 = (float)fVar4;

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_006c61e0(&local_d0);

  local_a0 = *puVar1;

  local_9c = puVar1[1];

  local_98 = puVar1[2];

  local_94 = puVar1[3];

  FUN_006d1620(&local_b0);

  FUN_006d1660(0);

  if (*(char *)(param_2 + 0x2d) == '\0') {

    local_cc = 0;

    local_c8 = 0;

  }

  else {

    local_c8 = 0x32;

  }

  local_c4 = 5;

  FUN_006d13c0(&local_d0);

  uVar2 = FUN_006d1420(local_80);

  uVar3 = (**(code **)*DAT_00b05060)(uVar2,0x23);

  uVar2 = FUN_006d14a0(auStack_88,uVar3,uVar2);

  (**(code **)(*DAT_00b05060 + 4))(uVar3);

  FUN_0056f570();

  FUN_006d11d0();

  return uVar2;

}
