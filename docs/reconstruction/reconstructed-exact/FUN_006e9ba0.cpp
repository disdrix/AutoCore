// =============================================================================
// FUN_006e9ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_006e9ba0
// Address:   0x006e9ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e9ba0 @ 0x006e9ba0
// Stable ID: aa_006e9ba0
// Embedded strings (evidence for future rename):
//   - "TtMopp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: rdtsc×2, FUN_005d6a40, FUN_0063a3f0, FUN_006e9ba0, FUN_007004a0.
//  - Strings: "TtMopp".
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

void FUN_006e9ba0(uint32_t /* width from decompiler */ *param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  uint64_t uVar1;

  float unaff_EBX;

  float unaff_ESI;

  float local_f4;

  float local_f0;

  float fStack_ec;

  float fStack_e8;

  float fStack_e4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_ac;

  float fStack_a8;

  float fStack_a4;

  float fStack_a0;

  int iStack_9c;

  uint32_t /* width from decompiler */ *puStack_98;

  int iStack_94;

  uint8_t local_50 [76];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtMopp";

    uVar1 = rdtsc();

    local_f4 = (float)uVar1;

    DAT_00bc5644[1] = local_f4;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_0063a3f0(*(int *)(param_2 + 8) + 0x20,param_1[2] + 0x20);

  (**(code **)(*(int *)*param_1 + 0x18))(local_50,*(uint32_t /* width from decompiler */ *)(param_3 + 8),&local_f0);

  FUN_005d6a40(*(int *)(param_2 + 8) + 0x20,param_3 + 0x10);

  fStack_a0 = *(float *)(param_3 + 8);

  puStack_98 = param_1;

  fStack_cc = (unaff_ESI + fStack_ec) * DAT_00a0f298;

  iStack_94 = param_2;

  fStack_c8 = (fStack_e8 + unaff_EBX) * DAT_00a0f298;

  fStack_c4 = (fStack_e4 + local_f4) * DAT_00a0f298;

  fStack_c0 = (fStack_e0 + local_f0) * DAT_00a0f298;

  fStack_bc = fStack_dc + fStack_cc;

  fStack_b8 = fStack_d8 + fStack_c8;

  fStack_b4 = fStack_d4 + fStack_c4;

  fStack_b0 = fStack_d0 + fStack_c0;

  fStack_ac = (fStack_ec - unaff_ESI) * DAT_00a0f298 + fStack_a0;

  fStack_a8 = (fStack_e8 - unaff_EBX) * DAT_00a0f298 + fStack_a0;

  fStack_a4 = (fStack_e4 - local_f4) * DAT_00a0f298 + fStack_a0;

  iStack_9c = param_3;

  fStack_a0 = (fStack_e0 - local_f0) * DAT_00a0f298 + fStack_a0;

  FUN_007004a0(&fStack_cc,param_4,param_5);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
