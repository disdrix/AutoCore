// =============================================================================
// FUN_00662510
// -----------------------------------------------------------------------------
// Stable ID: aa_00662510
// Address:   0x00662510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00662510 @ 0x00662510
// Stable ID: aa_00662510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005eb040×2, FUN_00662510.
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

void __thiscall FUN_00662510(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_2 + 0xc);

  FUN_005eb040(*(int *)(*(int *)(param_2 + 0x10) + 0x3c) + 0x80);

  FUN_005eb040(*(int *)(iVar1 + 0x3c) + 0x80);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = *param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = param_3[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = param_3[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = param_3[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = param_3[4];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = param_3[5];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = param_3[6];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = param_3[7];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = param_3[8];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = param_3[9];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = param_3[10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xbc) = param_3[0xb];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = *param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = param_4[1];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = param_4[2];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = param_4[3];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = param_4[4];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = param_4[5];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = param_4[6];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = param_4[7];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = param_4[8];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = param_4[9];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = param_4[10];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = param_4[0xb];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = param_3[0xc];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = param_3[0xd];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = param_3[0xe];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = param_3[0xf];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = param_4[0xc];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = param_4[0xd];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = param_4[0xe];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = param_4[0xf];

  return;

}
