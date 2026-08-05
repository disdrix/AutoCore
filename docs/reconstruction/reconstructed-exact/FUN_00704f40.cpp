// =============================================================================
// FUN_00704f40
// -----------------------------------------------------------------------------
// Stable ID: aa_00704f40
// Address:   0x00704f40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00704f40 @ 0x00704f40
// Stable ID: aa_00704f40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00702f40, FUN_00702fa0, FUN_00703130, FUN_00704f40.
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

uint32_t /* width from decompiler */ * FUN_00704f40(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_00703130(0x5e30);

  *puVar5 = param_1;

  puVar2 = (uint32_t /* width from decompiler */ *)*param_1;

  puVar5[0x19] = 1;

  puVar5[10] = puVar5 + 0x1c;

  uVar6 = FUN_00702f40(*puVar2);

  puVar5[1] = uVar6;

  puVar5[2] = puVar2[1] << 1;

  puVar5[3] = puVar2[1];

  puVar5[4] = puVar2[2];

  piVar1 = puVar5 + 8;

  puVar5[5] = (int)puVar2[1] / (int)puVar2[2];

  puVar5[6] = puVar2[3];

  FUN_00702fa0(uVar6,0x19,piVar1);

  puVar5[0x1a] = puVar2 + 10;

  *piVar1 = *piVar1 << 1;

  puVar5[0x1b] = puVar2[0x12];

  iVar3 = puVar5[3];

  iVar7 = iVar3 * 4;

  iVar8 = puVar5[10] + (-puVar5[10] & 3) + iVar7;

  puVar5[0xb] = iVar8 + iVar3 * -4;

  iVar8 = (-iVar8 & 3U) + iVar8 + iVar7;

  puVar5[0xc] = iVar8 + iVar3 * -4;

  iVar4 = puVar5[2];

  iVar9 = iVar4 * 4;

  iVar8 = (-iVar8 & 3U) + iVar8 + iVar9;

  puVar5[0xd] = iVar8 + iVar4 * -4;

  iVar8 = (-iVar8 & 3U) + iVar8 + iVar9;

  puVar5[7] = 1;

  puVar5[0xe] = iVar8 + iVar4 * -4;

  iVar9 = (-iVar8 & 3U) + iVar8 + iVar9;

  iVar8 = (-iVar9 & 3U) + 0x100 + iVar9;

  puVar5[0x10] = iVar8 + -0x100;

  puVar5[0xf] = iVar9 + iVar4 * -4;

  iVar8 = (-iVar8 & 3U) + 0x100 + iVar8;

  puVar5[0x11] = iVar8 + -0x100;

  iVar7 = (-iVar8 & 3U) + iVar8 + iVar7;

  puVar5[0x12] = iVar7 + iVar3 * -4;

  iVar3 = puVar5[6];

  iVar9 = iVar3 * 4;

  iVar8 = (-iVar7 & 3U) + iVar7 + iVar9;

  puVar5[0x13] = iVar8 + iVar3 * -4;

  iVar8 = (-iVar8 & 3U) + iVar8 + iVar9;

  puVar5[0x14] = iVar8 + iVar3 * -4;

  iVar8 = (-iVar8 & 3U) + iVar8 + iVar9;

  puVar5[0x15] = iVar8 + iVar3 * -4;

  iVar9 = (-iVar8 & 3U) + iVar8 + 4 + iVar9;

  puVar5[0x16] = iVar9 + iVar3 * -4 + -4;

  iVar8 = (-iVar9 & 3U) + iVar9 + puVar5[5] * 4;

  iVar9 = (-iVar8 & 3U) + iVar8 + iVar3 * 8;

  puVar5[10] = iVar9;

  puVar5[0x18] = iVar8 + puVar5[5] * -4;

  puVar5[0x17] = iVar9 + iVar3 * -8;

  puVar5[9] = 0;

  return puVar5;

}
