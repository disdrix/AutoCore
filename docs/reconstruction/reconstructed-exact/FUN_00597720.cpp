// =============================================================================
// FUN_00597720
// -----------------------------------------------------------------------------
// Stable ID: aa_00597720
// Address:   0x00597720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00597720 @ 0x00597720
// Stable ID: aa_00597720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~200 non-empty decompiler lines.
//  - Control keywords: for×5, do×3, while×3, return×1.
//  - Notable callees: FUN_005969f0×2, FUN_00596c90×2, FUN_005963a0, FUN_00596b40, FUN_00597720.
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

uint8_t * __thiscall FUN_00597720(uint8_t *param_1,uint8_t *param_2)



{

  uint8_t *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  *param_1 = *param_2;

  FUN_00596c90(param_2 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x30);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 0x34);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x34);

  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar5 = puVar5 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x54);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x58);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 0x60);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x60);

  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar5 = puVar5 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xa8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xac);

  param_1[0xb0] = param_2[0xb0];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xbc);

  FUN_005969f0(param_2 + 0xc0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xd0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xd4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xd8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xdc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe0);

  FUN_005963a0(param_2 + 0xe4);

  FUN_00596c90(param_2 + 0x1c0);

  puVar1 = param_1 + 0x1d0;

  iVar2 = (int)param_2 - (int)param_1;

  iVar4 = 0x7f;

  do {

    *puVar1 = puVar1[iVar2];

    puVar1 = puVar1 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x250) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x250);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x254) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x254);

  *(uint32_t /* width from decompiler */ *)(param_1 + 600) = *(uint32_t /* width from decompiler */ *)(param_2 + 600);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x25c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x25c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x260) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x260);

  FUN_00596b40(param_2 + 0x264);

  FUN_005969f0(param_2 + 0x274);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x284) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x284);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x288) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x288);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x28c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x290) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x290);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x294) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x294);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x298) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x298);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x29c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x29c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2a0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2a4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2a8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2ac) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2ac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2b0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2b0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2b4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2b4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2b8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2b8);

  *(uint16_t *)(param_1 + 700) = *(uint16_t *)(param_2 + 700);

  puVar1 = param_1 + 0x2be;

  iVar4 = 0x7f;

  do {

    *puVar1 = puVar1[iVar2];

    puVar1 = puVar1 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  puVar1 = param_1 + 0x33d;

  iVar4 = 0x7f;

  do {

    *puVar1 = puVar1[iVar2];

    puVar1 = puVar1 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 0x3bc);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x3bc);

  for (iVar2 = 0xf3; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar5 = puVar5 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x788) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x788);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x78c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x790) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x790);

  param_1[0x794] = param_2[0x794];

  param_1[0x795] = param_2[0x795];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x798) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x798);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 0x79c);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x79c);

  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar5 = puVar5 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7c0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7c4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7c8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7cc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7cc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 2000) = *(uint32_t /* width from decompiler */ *)(param_2 + 2000);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7d4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7d4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7d8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7d8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7dc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7dc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7e0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x7e4);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_2 + 0x7e8);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x7e8);

  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar5 = *puVar3;

    puVar3 = puVar3 + 1;

    puVar5 = puVar5 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x818) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x818);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x81c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x81c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x820) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x820);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x824) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x824);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x828) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x828);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x82c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x82c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x830) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x830);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x834) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x834);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x838) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x838);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x83c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x83c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x840) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x840);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x844) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x844);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x848) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x848);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x84c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x850) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x850);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x854) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x854);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x858) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x858);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x85c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x85c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x860) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x860);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x864) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x864);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x868) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x868);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x86c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x86c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x870) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x870);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x874) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x874);

  param_1[0x878] = param_2[0x878];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x87c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x87c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x880) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x880);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x884) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x884);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x888) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x888);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x88c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x890) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x890);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x894) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x894);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x898) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x898);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x89c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x89c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8a0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8a4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8a8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8a8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8ac) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8ac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8b0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8b4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8b8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8b8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8bc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8bc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8c0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8c4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8c8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8cc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8cc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8d0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8d0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8d4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8d4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8d8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8d8);

  param_1[0x8dc] = param_2[0x8dc];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8e0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8e4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8e8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8e8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8ec) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8ec);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8f0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8f0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8f4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8f4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8f8) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8f8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8fc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x8fc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x900) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x900);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x904) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x904);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x908) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x908);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x90c);

  *(uint16_t *)(param_1 + 0x910) = *(uint16_t *)(param_2 + 0x910);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x914) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x914);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x918) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x918);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x91c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x91c);

  return param_1;

}
