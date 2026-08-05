// =============================================================================
// FUN_007010b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007010b0
// Address:   0x007010b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007010b0 @ 0x007010b0
// Stable ID: aa_007010b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007010b0, FUN_00702680.
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

int __thiscall

FUN_007010b0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ *param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(int *)(param_1 + 8) = param_1 + 0x14;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0x80000064;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8) = 0x80000064;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b4) = 0;

  *(int *)(param_1 + 0x1b0) = param_1 + 0x1c0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2104) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2108) = 0x80000037;

  *(int *)(param_1 + 0x2100) = param_1 + 0x2110;

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2100);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2104) = 4;

  *puVar1 = *param_2;

  puVar1[1] = param_2[1];

  puVar1[2] = param_2[2];

  puVar1[3] = param_2[3];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x2100) + 0x10) = 0;

  iVar2 = *(int *)(param_1 + 0x2100);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x20) = *param_3;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x24) = param_3[1];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x28) = param_3[2];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c) = param_3[3];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x2100) + 0x30) = 0;

  iVar2 = *(int *)(param_1 + 0x2100);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40) = *param_4;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = param_4[1];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x48) = param_4[2];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x4c) = param_4[3];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x2100) + 0x50) = 0;

  iVar2 = *(int *)(param_1 + 0x2100);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x60) = *param_5;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 100) = param_5[1];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x68) = param_5[2];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x6c) = param_5[3];

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x2100) + 0x70) = 0;

  FUN_00702680();

  return param_1;

}
