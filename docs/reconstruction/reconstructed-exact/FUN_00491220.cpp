// =============================================================================
// FUN_00491220
// -----------------------------------------------------------------------------
// Stable ID: aa_00491220
// Address:   0x00491220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00491220 @ 0x00491220
// Stable ID: aa_00491220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00490530, FUN_00491220, FUN_00494b80, FUN_00495130, FUN_00495570.
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

void __thiscall FUN_00491220(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = param_2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 300) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x130) = param_4;

  iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe898);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x8c) = param_2;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = param_3;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = param_4;

  FUN_00494b80(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8),0x42c80000,0);

  param_2 = 0;

  FUN_00495130(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8),&param_2);

  FUN_00490530(&param_2);

  FUN_00495570(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb8));

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = param_2;

  return;

}
