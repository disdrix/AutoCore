// =============================================================================
// FUN_004b0be0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0be0
// Address:   0x004b0be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b0be0 @ 0x004b0be0
// Stable ID: aa_004b0be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: for×6, return×1.
//  - Notable callees: FUN_004b0be0.
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

void __thiscall FUN_004b0be0(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 0x84);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x84);

  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 0xf8);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0xf8);

  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x170);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x174);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x178);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x17c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x180);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x184) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x184);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x188);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 400) = *(uint32_t /* width from decompiler */ *)(param_2 + 400);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x194);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x198);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x19c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x19c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a0) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1a0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1a4);

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 0x1b0);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x1b0);

  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 0x1d4);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x1d4);

  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x204) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x204);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x208) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x208);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x20c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x210) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x210);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x214) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x214);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x218) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x218);

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 0x21c);

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x21c);

  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  *(uint8_t *)(param_1 + 0x240) = *(uint8_t *)(param_2 + 0x240);

  *(uint8_t *)(param_1 + 0x241) = *(uint8_t *)(param_2 + 0x241);

  *(uint8_t *)(param_1 + 0x242) = *(uint8_t *)(param_2 + 0x242);

  return;

}
