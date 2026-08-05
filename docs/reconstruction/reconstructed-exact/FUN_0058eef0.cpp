// =============================================================================
// FUN_0058eef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058eef0
// Address:   0x0058eef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058eef0 @ 0x0058eef0
// Stable ID: aa_0058eef0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~283 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_004a6d00, FUN_0058eef0, FUN_007873f0.
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

uint8_t * __fastcall FUN_0058eef0(uint8_t *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  float fVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a5815;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  fVar3 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x34);

  *(uint8_t **)(param_1 + 0x28) = param_1 + 0x3bc;

  *puVar1 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  local_4 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = 0;

  param_1[0xb0] = 0;

  *(float *)(param_1 + 0xb4) = fVar3;

  *(float *)(param_1 + 0xb8) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = 0;

  FUN_007873f0();

  fVar3 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = 0;

  *(float *)(param_1 + 0xe8) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = 0;

  *(float *)(param_1 + 0xf8) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *(float *)(param_1 + 0x108) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x168) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

  *(float *)(param_1 + 0xe8) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = 0;

  *(float *)(param_1 + 0xf8) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = 0;

  *(float *)(param_1 + 0x108) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = DAT_00a0f718;

  uVar2 = DAT_00a0f298;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = DAT_00a0f298;

  *(uint32_t /* width from decompiler */ *)(param_1 + 300) = uVar2;

  uVar2 = DAT_00aaa68c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x134) = DAT_00aaa68c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x140) = uVar2;

  uVar2 = DAT_00a0f70c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = DAT_00a0f70c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x138) = uVar2;

  uVar2 = DAT_009c7b84;

  *(float *)(param_1 + 0x11c) = fVar3;

  *(float *)(param_1 + 0x120) = fVar3;

  *(float *)(param_1 + 0x124) = fVar3;

  *(float *)(param_1 + 0x130) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b0) = 0x20;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x144) = 5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x154) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x158) = 0;

  *(uint16_t *)(param_1 + 0x19c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x148) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x168) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x250) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x254) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 600) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x25c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x260) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x268) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x26c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x270) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x278) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x27c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x280) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x284) = 0;

  *(float *)(param_1 + 0x288) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x290) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x294) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x298) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x29c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2b8) = 0;

  *(uint16_t *)(param_1 + 700) = 0;

  FUN_004a6d00();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x788) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x790) = 0;

  param_1[0x794] = 0;

  param_1[0x795] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x798) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x818) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x81c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x820) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x824) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x828) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x82c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x830) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x834) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x838) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x83c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x840) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x844) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x848) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x850) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x854) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x858) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x85c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x860) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x864) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x868) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x86c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x870) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x874) = 0;

  fVar3 = g_flOne;

  param_1[0x878] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x87c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x880) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x884) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x888) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x890) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x894) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x898) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x89c) = 0;

  *(float *)(param_1 + 0x8a0) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8cc) = 0;

  *(float *)(param_1 + 0x8d0) = fVar3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8d4) = 0;

  *(float *)(param_1 + 0x8d8) = fVar3;

  param_1[0x8dc] = 0;

  param_1[0x8e2] = 0;

  param_1[0x8e1] = 0;

  param_1[0x8e0] = 0;

  param_1[0x8e3] = 0;

  param_1[0x8e6] = 0;

  param_1[0x8e5] = 0;

  param_1[0x8e4] = 0;

  param_1[0x8e7] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8ec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8f0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8f4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8f8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8fc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x900) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x904) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x908) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x914) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x918) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x91c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  param_1[0x1d0] = 0;

  param_1[0x2be] = 0;

  param_1[0x33d] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x79c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7a0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7a4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 2000) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7d4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7d8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7dc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e4) = 0;

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x7e8);

  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90c) = 0;

  *(uint16_t *)(param_1 + 0x910) = 0;

  param_1[0x90e] = param_1[0x90e] | 8;

  *(uint8_t **)(param_1 + 0x6b0) = param_1 + 0x3bc;

  *(uint8_t **)(param_1 + 0x6ac) = param_1 + 0x3bc;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x38) = puVar1;

  *(uint8_t **)(param_1 + 0xd8) = param_1;

  *puVar1 = puVar1;

  ExceptionList = local_c;

  return param_1;

}
