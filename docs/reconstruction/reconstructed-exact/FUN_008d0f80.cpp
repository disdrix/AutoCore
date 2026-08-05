// =============================================================================
// FUN_008d0f80
// -----------------------------------------------------------------------------
// Stable ID: aa_008d0f80
// Address:   0x008d0f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d0f80 @ 0x008d0f80
// Stable ID: aa_008d0f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~182 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_008d0f80, FUN_008d7420.
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

void FUN_008d0f80(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int extraout_ECX;

  uint8_t *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  

  FUN_008d7420();

  puVar2 = (uint8_t *)(extraout_ECX + 0x5c0);

  iVar4 = 3;

  do {

    puVar2[-3] = 0;

    *puVar2 = 0;

    uVar1 = DAT_00aaa84c;

    puVar2 = puVar2 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5c3) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5c7) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5cb) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5cf) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5d3) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5d7) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5db) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5df) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5e3) = 0x1010101;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x624) = uVar1;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x628) = DAT_00aaa848;

  uVar1 = DAT_00aaa844;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x638) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x63c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x640) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x644) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x648) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x64c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x650) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x654) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x658) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x65c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x664) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x668) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x66c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x670) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x674) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x67c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x680) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x684) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x688) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x68c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x690) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x694) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x698) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x69c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6a0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6a4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6a8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6ac) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6b0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6b4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6b8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6bc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6c0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6c4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6c8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6cc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6d0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6d4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6d8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6dc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6e0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6e4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6e8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6ec) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6f0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6f4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6f8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x6fc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x700) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x704) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x708) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x70c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x710) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x714) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x718) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x62c) = uVar1;

  puVar3 = (uint32_t /* width from decompiler */ *)(extraout_ECX + 0x724);

  iVar4 = 2;

  do {

    puVar3[-2] = 0;

    *puVar3 = 0;

    puVar3[2] = 0;

    puVar3[4] = 0;

    puVar3[6] = 0;

    puVar3[8] = 0;

    puVar3[10] = 0;

    puVar3[0xc] = 0;

    puVar3[0x12] = 0;

    puVar3[0x14] = 0;

    puVar3[0x16] = 0;

    puVar3[0x18] = 0;

    puVar3 = puVar3 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x80c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x828) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x860) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x810) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x82c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x864) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x814) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x830) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x868) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x818) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x834) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x86c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x81c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x838) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x870) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x820) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x83c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x874) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x824) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x840) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x878) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7f0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x844) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7f4) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x848) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7f8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x84c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7fc) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x850) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x800) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x854) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x804) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x858) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x808) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x85c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x75c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x760) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x764) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x768) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x78c) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x790) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5b0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5b8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x8ec) = 0;

  *(uint8_t *)(extraout_ECX + 0x5bc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x568) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x588) = 4;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x578) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x57c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x580) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x584) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x590) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x594) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x58c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x5a0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7a0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7a4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7a8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7ac) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7b0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7b4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7b8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7bc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7c0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7c4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7c8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7cc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 2000) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7d4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7d8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7dc) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7e0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7e4) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7e8) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x7ec) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x8f0) = 0;

  *(uint32_t /* width from decompiler */ *)(extraout_ECX + 0x8f4) = 0;

  return;

}
