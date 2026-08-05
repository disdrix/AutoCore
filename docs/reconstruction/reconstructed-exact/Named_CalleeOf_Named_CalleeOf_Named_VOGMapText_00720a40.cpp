// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGMapText_00720a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00720a40
// Callee of Named_CalleeOf_Named_VOGMapText
// Address:   0x00720a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGMapText: map/sector helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: InitializeCriticalSection×2, FUN_00720a40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGMapText
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

uint8_t * Named_CalleeOf_Named_CalleeOf_Named_VOGMapText_00720a40(uint8_t *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uVar1 = DAT_00aaa668;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009abdd9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  param_1[0x10] = 1;

  param_1[0x11] = 0;

  param_1[0x12] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  param_1[0x17] = 0;

  param_1[0x19] = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = uVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x90);

  for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x158));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));

  param_1[1] = 0;

  *param_1 = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  ExceptionList = local_c;

  return param_1;

}
