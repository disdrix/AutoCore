// =============================================================================
// FUN_008e39f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e39f0
// Address:   0x008e39f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e39f0 @ 0x008e39f0
// Stable ID: aa_008e39f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, return×1.
//  - Notable callees: FUN_0040f0c0×2, FUN_008e39f0.
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

void __fastcall FUN_008e39f0(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  FUN_0040f0c0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x7ec) + 4));

  *(int *)(*(int *)(param_1 + 0x7ec) + 4) = *(int *)(param_1 + 0x7ec);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7f0) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x7ec) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7ec);

  *(int *)(*(int *)(param_1 + 0x7ec) + 8) = *(int *)(param_1 + 0x7ec);

  FUN_0040f0c0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x7f8) + 4));

  *(int *)(*(int *)(param_1 + 0x7f8) + 4) = *(int *)(param_1 + 0x7f8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7fc) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x7f8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7f8);

  *(int *)(*(int *)(param_1 + 0x7f8) + 8) = *(int *)(param_1 + 0x7f8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x518) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x520) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x524) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x774) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x778) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x77c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x780) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x51c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x57c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x580) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x570) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x584) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x574) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x588) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x578) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58c) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5b8);

  iVar4 = 5;

  do {

    iVar3 = 5;

    do {

      puVar2[0x19] = 0;

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  iVar4 = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x54c);

  do {

    puVar2[-7] = 0;

    *puVar2 = 0;

    *(uint8_t *)(param_1 + 0x7da + iVar4) = 0;

    iVar4 = iVar4 + 1;

    puVar2 = puVar2 + 1;

  } while (iVar4 < 7);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7d4) = 0;

  fVar1 = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x748) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 2000) = 0;

  *(uint8_t *)(param_1 + 0x7e1) = 0;

  *(uint8_t *)(param_1 + 0x7e2) = 0;

  *(uint8_t *)(param_1 + 0x7d8) = 0;

  *(uint8_t *)(param_1 + 0x7e3) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x750) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x754) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x758) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x75c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x760) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x764) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x768) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x76c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x770) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x784) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x788) = 0;

  *(uint8_t *)(param_1 + 0x7d9) = 1;

  *(float *)(param_1 + 0x7e4) = fVar1;

  return;

}
