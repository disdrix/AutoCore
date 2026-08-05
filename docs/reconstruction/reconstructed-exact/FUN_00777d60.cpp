// =============================================================================
// FUN_00777d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00777d60
// Address:   0x00777d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00777d60 @ 0x00777d60
// Stable ID: aa_00777d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~175 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00777d60.
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

uint32_t /* width from decompiler */ FUN_00777d60(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  int *in_EAX;

  uint uVar17;

  uint uVar18;

  uint uVar19;

  uint uVar20;

  

  iVar1 = in_EAX[1];

  iVar2 = in_EAX[2];

  iVar3 = in_EAX[3];

  iVar4 = in_EAX[4];

  iVar5 = in_EAX[5];

  iVar6 = *in_EAX;

  iVar7 = in_EAX[6];

  iVar8 = in_EAX[7];

  iVar9 = in_EAX[8];

  iVar10 = in_EAX[9];

  iVar11 = in_EAX[10];

  iVar12 = in_EAX[0xb];

  iVar13 = in_EAX[0xc];

  iVar14 = in_EAX[0xd];

  iVar15 = in_EAX[0xe];

  iVar16 = in_EAX[0xf];

  uVar18 = *(uint *)(param_1 + 0x14);

  uVar19 = *(uint *)(param_1 + 0x10);

  uVar20 = *(uint *)(param_1 + 0xc);

  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar18) + *(int *)(param_1 + 8) + -0x28955b88 + iVar6;

  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar20;

  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar19) + iVar1 + -0x173848aa + uVar18;

  uVar18 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar17;

  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar20) + iVar2 + 0x242070db + uVar19;

  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar18;

  uVar20 = ((uVar18 ^ uVar17) & uVar19 ^ uVar17) + iVar3 + -0x3e423112 + uVar20;

  uVar20 = (uVar20 * 0x400000 | uVar20 >> 10) + uVar19;

  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar18) + iVar4 + -0xa83f051 + uVar17;

  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar20;

  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar19) + iVar5 + 0x4787c62a + uVar18;

  uVar18 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar17;

  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar20) + iVar7 + -0x57cfb9ed + uVar19;

  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar18;

  uVar20 = ((uVar18 ^ uVar17) & uVar19 ^ uVar17) + iVar8 + -0x2b96aff + uVar20;

  uVar20 = (uVar20 * 0x400000 | uVar20 >> 10) + uVar19;

  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar18) + iVar9 + 0x698098d8 + uVar17;

  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar20;

  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar19) + iVar10 + -0x74bb0851 + uVar18;

  uVar18 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar17;

  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar20) + iVar11 + -0xa44f + uVar19;

  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar18;

  uVar20 = ((uVar18 ^ uVar17) & uVar19 ^ uVar17) + iVar12 + -0x76a32842 + uVar20;

  uVar20 = (uVar20 * 0x400000 | uVar20 >> 10) + uVar19;

  uVar17 = ((uVar18 ^ uVar19) & uVar20 ^ uVar18) + iVar13 + 0x6b901122 + uVar17;

  uVar17 = (uVar17 * 0x80 | uVar17 >> 0x19) + uVar20;

  uVar18 = ((uVar19 ^ uVar20) & uVar17 ^ uVar19) + iVar14 + -0x2678e6d + uVar18;

  uVar18 = (uVar18 * 0x1000 | uVar18 >> 0x14) + uVar17;

  uVar19 = ((uVar20 ^ uVar17) & uVar18 ^ uVar20) + iVar15 + -0x5986bc72 + uVar19;

  uVar19 = (uVar19 * 0x20000 | uVar19 >> 0xf) + uVar18;

  uVar20 = ((uVar18 ^ uVar17) & uVar19 ^ uVar17) + iVar16 + 0x49b40821 + uVar20;

  uVar20 = (uVar20 * 0x400000 | uVar20 >> 10) + uVar19;

  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar19) + iVar1 + -0x9e1da9e + uVar17;

  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar20;

  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar20) + iVar7 + -0x3fbf4cc0 + uVar18;

  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar17;

  uVar19 = ((uVar18 ^ uVar17) & uVar20 ^ uVar17) + iVar12 + 0x265e5a51 + uVar19;

  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar18;

  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar18) + iVar6 + -0x16493856 + uVar20;

  uVar20 = (uVar20 * 0x100000 | uVar20 >> 0xc) + uVar19;

  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar19) + iVar5 + -0x29d0efa3 + uVar17;

  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar20;

  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar20) + iVar11 + 0x2441453 + uVar18;

  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar17;

  uVar19 = ((uVar18 ^ uVar17) & uVar20 ^ uVar17) + iVar16 + -0x275e197f + uVar19;

  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar18;

  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar18) + iVar4 + -0x182c0438 + uVar20;

  uVar20 = (uVar20 * 0x100000 | uVar20 >> 0xc) + uVar19;

  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar19) + iVar10 + 0x21e1cde6 + uVar17;

  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar20;

  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar20) + iVar15 + -0x3cc8f82a + uVar18;

  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar17;

  uVar19 = ((uVar18 ^ uVar17) & uVar20 ^ uVar17) + iVar3 + -0xb2af279 + uVar19;

  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar18;

  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar18) + iVar9 + 0x455a14ed + uVar20;

  uVar20 = (uVar20 * 0x100000 | uVar20 >> 0xc) + uVar19;

  uVar17 = ((uVar19 ^ uVar20) & uVar18 ^ uVar19) + iVar14 + -0x561c16fb + uVar17;

  uVar17 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar20;

  uVar18 = ((uVar20 ^ uVar17) & uVar19 ^ uVar20) + iVar2 + -0x3105c08 + uVar18;

  uVar18 = (uVar18 * 0x200 | uVar18 >> 0x17) + uVar17;

  uVar19 = ((uVar18 ^ uVar17) & uVar20 ^ uVar17) + iVar8 + 0x676f02d9 + uVar19;

  uVar19 = (uVar19 * 0x4000 | uVar19 >> 0x12) + uVar18;

  uVar20 = ((uVar18 ^ uVar19) & uVar17 ^ uVar18) + iVar13 + -0x72d5b376 + uVar20;

  uVar20 = (uVar20 * 0x100000 | uVar20 >> 0xc) + uVar19;

  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar5 + -0x5c6be + uVar17;

  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar20;

  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar9 + -0x788e097f + uVar18;

  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar17;

  uVar19 = (uVar18 ^ uVar20 ^ uVar17) + iVar12 + 0x6d9d6122 + uVar19;

  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar18;

  uVar20 = (uVar18 ^ uVar19 ^ uVar17) + iVar15 + -0x21ac7f4 + uVar20;

  uVar20 = (uVar20 * 0x800000 | uVar20 >> 9) + uVar19;

  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar1 + -0x5b4115bc + uVar17;

  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar20;

  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar4 + 0x4bdecfa9 + uVar18;

  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar17;

  uVar19 = (uVar18 ^ uVar20 ^ uVar17) + iVar8 + -0x944b4a0 + uVar19;

  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar18;

  uVar20 = (uVar18 ^ uVar19 ^ uVar17) + iVar11 + -0x41404390 + uVar20;

  uVar20 = (uVar20 * 0x800000 | uVar20 >> 9) + uVar19;

  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar14 + 0x289b7ec6 + uVar17;

  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar20;

  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar6 + -0x155ed806 + uVar18;

  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar17;

  uVar19 = (uVar18 ^ uVar20 ^ uVar17) + iVar3 + -0x2b10cf7b + uVar19;

  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar18;

  uVar20 = (uVar18 ^ uVar19 ^ uVar17) + iVar7 + 0x4881d05 + uVar20;

  uVar20 = (uVar20 * 0x800000 | uVar20 >> 9) + uVar19;

  uVar17 = (uVar18 ^ uVar19 ^ uVar20) + iVar10 + -0x262b2fc7 + uVar17;

  uVar17 = (uVar17 * 0x10 | uVar17 >> 0x1c) + uVar20;

  uVar18 = (uVar19 ^ uVar20 ^ uVar17) + iVar13 + -0x1924661b + uVar18;

  uVar18 = (uVar18 * 0x800 | uVar18 >> 0x15) + uVar17;

  uVar19 = (uVar18 ^ uVar20 ^ uVar17) + iVar16 + 0x1fa27cf8 + uVar19;

  uVar19 = (uVar19 * 0x10000 | uVar19 >> 0x10) + uVar18;

  uVar20 = (uVar18 ^ uVar19 ^ uVar17) + iVar2 + -0x3b53a99b + uVar20;

  uVar20 = (uVar20 * 0x800000 | uVar20 >> 9) + uVar19;

  uVar17 = ((~uVar18 | uVar20) ^ uVar19) + iVar6 + -0xbd6ddbc + uVar17;

  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar20;

  uVar18 = ((~uVar19 | uVar17) ^ uVar20) + iVar8 + 0x432aff97 + uVar18;

  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar17;

  uVar19 = ((~uVar20 | uVar18) ^ uVar17) + iVar15 + -0x546bdc59 + uVar19;

  uVar19 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar18;

  uVar20 = ((~uVar17 | uVar19) ^ uVar18) + iVar5 + -0x36c5fc7 + uVar20;

  uVar20 = (uVar20 * 0x200000 | uVar20 >> 0xb) + uVar19;

  uVar17 = ((~uVar18 | uVar20) ^ uVar19) + iVar13 + 0x655b59c3 + uVar17;

  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar20;

  uVar18 = ((~uVar19 | uVar17) ^ uVar20) + iVar3 + -0x70f3336e + uVar18;

  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar17;

  uVar19 = ((~uVar20 | uVar18) ^ uVar17) + iVar11 + -0x100b83 + uVar19;

  uVar19 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar18;

  uVar20 = ((~uVar17 | uVar19) ^ uVar18) + iVar1 + -0x7a7ba22f + uVar20;

  uVar20 = (uVar20 * 0x200000 | uVar20 >> 0xb) + uVar19;

  uVar17 = ((~uVar18 | uVar20) ^ uVar19) + iVar9 + 0x6fa87e4f + uVar17;

  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar20;

  uVar18 = ((~uVar19 | uVar17) ^ uVar20) + iVar16 + -0x1d31920 + uVar18;

  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar17;

  uVar19 = ((~uVar20 | uVar18) ^ uVar17) + iVar7 + -0x5cfebcec + uVar19;

  uVar19 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar18;

  uVar20 = ((~uVar17 | uVar19) ^ uVar18) + iVar14 + 0x4e0811a1 + uVar20;

  uVar20 = (uVar20 * 0x200000 | uVar20 >> 0xb) + uVar19;

  uVar17 = ((~uVar18 | uVar20) ^ uVar19) + iVar4 + -0x8ac817e + uVar17;

  uVar17 = (uVar17 * 0x40 | uVar17 >> 0x1a) + uVar20;

  uVar18 = ((~uVar19 | uVar17) ^ uVar20) + iVar12 + -0x42c50dcb + uVar18;

  uVar18 = (uVar18 * 0x400 | uVar18 >> 0x16) + uVar17;

  uVar19 = ((~uVar20 | uVar18) ^ uVar17) + iVar2 + 0x2ad7d2bb + uVar19;

  uVar19 = (uVar19 * 0x8000 | uVar19 >> 0x11) + uVar18;

  *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + uVar17;

  uVar20 = ((~uVar17 | uVar19) ^ uVar18) + iVar10 + -0x14792c6f + uVar20;

  *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar19;

  *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar18;

  *(uint *)(param_1 + 0xc) = (uVar20 * 0x200000 | uVar20 >> 0xb) + *(int *)(param_1 + 0xc) + uVar19;

  return 0;

}
