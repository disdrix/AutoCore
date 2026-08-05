// =============================================================================
// Named_CalleeOf_Named_hkWorld_005e1c80
// -----------------------------------------------------------------------------
// Stable ID: aa_005e1c80
// Callee of Named_hkWorld (+1 other named callers)
// Address:   0x005e1c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_hkWorld (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005e1c80, FUN_005fff00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_hkWorld (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_CalleeOf_Named_hkWorld_005e1c80(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  FUN_005fff00();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  fVar1 = g_flOne;

  *(float *)(param_1 + 0x3c) = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0;

  *(float *)(param_1 + 0x60) = fVar1;

  *(float *)(param_1 + 0x74) = fVar1;

  *(float *)(param_1 + 0x88) = fVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = DAT_00a10e78;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = DAT_00a0f298;

  uVar2 = DAT_00a0f720;

  *(float *)(param_1 + 0xa0) = fVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = uVar2;

  *(uint8_t *)(param_1 + 0xb4) = 1;

  *(uint8_t *)(param_1 + 0xb5) = 2;

  return param_1;

}
