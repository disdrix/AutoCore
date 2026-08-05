// =============================================================================
// FUN_00709830
// -----------------------------------------------------------------------------
// Stable ID: aa_00709830
// Address:   0x00709830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00709830 @ 0x00709830
// Stable ID: aa_00709830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×1.
//  - Notable callees: FUN_00703130, FUN_00709830, FUN_0070ef50.
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

uint32_t /* width from decompiler */ * FUN_00709830(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  piVar1 = (int *)*param_1;

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00703130(0x4080);

  *puVar2 = param_1;

  puVar4 = puVar2 + 0x80;

  puVar2[0xf] = puVar4;

  puVar2[0x21] = 1;

  puVar2[1] = 1;

  iVar6 = *piVar1;

  puVar2[3] = iVar6;

  puVar2[6] = (iVar6 * 3) / 2;

  puVar2[5] = *piVar1 / piVar1[1];

  puVar2[4] = piVar1[1];

  puVar2[7] = piVar1[2];

  puVar2[8] = piVar1[3];

  puVar2[0xd] = piVar1[6];

  puVar2[0xe] = piVar1[7];

  puVar2[9] = piVar1[4];

  puVar2[10] = piVar1[5];

  puVar2[0x22] = piVar1 + 10;

  puVar2[0x23] = piVar1[0x1a];

  iVar5 = puVar2[8];

  iVar6 = (int)puVar4 + (-(int)puVar4 & 3U) + iVar5 * 4;

  iVar7 = iVar6 + iVar5 * -4;

  puVar2[0x10] = iVar7;

  iVar3 = (iVar5 - puVar2[6]) * 4;

  puVar2[0x11] = iVar7 + iVar3;

  iVar6 = iVar5 * 4 + (-iVar6 & 3U) + iVar6;

  puVar2[0xf] = iVar6;

  iVar6 = iVar6 + iVar5 * -4;

  puVar2[0x12] = iVar6;

  iVar7 = 0;

  puVar2[0x24] = 0;

  puVar2[0x13] = iVar6 + iVar3;

  if (0 < iVar5) {

    do {

      *(uint32_t /* width from decompiler */ *)(puVar2[0x10] + iVar7 * 4) = 0;

      iVar7 = iVar7 + 1;

    } while (iVar7 < (int)puVar2[8]);

  }

  iVar6 = 0;

  if (0 < (int)puVar2[8]) {

    do {

      *(uint32_t /* width from decompiler */ *)(puVar2[0x12] + iVar6 * 4) = 0;

      iVar6 = iVar6 + 1;

    } while (iVar6 < (int)puVar2[8]);

  }

  iVar6 = (-puVar2[0xf] & 3) + puVar2[0xf] + puVar2[3] * 4;

  puVar2[0xf] = iVar6;

  iVar3 = puVar2[7];

  puVar2[0x14] = iVar6 + puVar2[3] * -4;

  iVar6 = iVar3 * 4;

  iVar5 = (-puVar2[0xf] & 3) + iVar6 + 4 + puVar2[0xf];

  puVar2[0xf] = iVar5;

  puVar2[0x18] = iVar5 + iVar3 * -4 + -4;

  iVar5 = puVar2[0xf] + (-puVar2[0xf] & 3) + iVar6;

  puVar2[0xf] = iVar5;

  puVar2[0x15] = iVar5 + iVar3 * -4;

  iVar5 = puVar2[0xf] + (-puVar2[0xf] & 3) + iVar6;

  puVar2[0xf] = iVar5;

  puVar2[0x16] = iVar5 + iVar3 * -4;

  iVar6 = puVar2[0xf] + (-puVar2[0xf] & 3) + iVar6;

  puVar2[0xf] = iVar6;

  puVar2[0x17] = iVar6 + iVar3 * -4;

  iVar6 = puVar2[0xf] + (-puVar2[0xf] & 3) + iVar3 * 0x14;

  puVar2[0xf] = iVar6;

  puVar2[0x19] = iVar6 + iVar3 * -0x14;

  iVar6 = (-puVar2[0xf] & 3) + 0x14 + puVar2[0xf];

  puVar2[0xf] = iVar6;

  iVar6 = iVar6 + -0x14;

  puVar2[0x25] = iVar6;

  FUN_0070ef50(iVar6);

  iVar6 = puVar2[0xf] + (-puVar2[0xf] & 3) + puVar2[5] * 4;

  puVar2[0xf] = iVar6;

  puVar2[0x1a] = iVar6 + puVar2[5] * -4;

  puVar2[0x1b] = 0x28;

  puVar2[2] = 0;

  puVar2[0x1f] = 0;

  puVar2[0x1e] = 0;

  puVar2[0x1d] = 0;

  puVar2[0x20] = 0;

  puVar2[0xb] = 8000;

  puVar2[0xc] = 0;

  puVar2[0x77] = FUN_00710810;

  puVar2[0x78] = 0;

  puVar4 = puVar2 + 0x27;

  iVar6 = 0x10;

  do {

    *puVar4 = 0;

    puVar4 = puVar4 + 5;

    iVar6 = iVar6 + -1;

  } while (iVar6 != 0);

  puVar2[0x7d] = 0;

  puVar2[0x7c] = 0;

  puVar2[0x7b] = 0;

  puVar2[0x7e] = 0;

  puVar2[0x7f] = 0;

  return puVar2;

}
