// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0055a5f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055a5f0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0055a5f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×3, for×2, return×1.
//  - Notable callees: FUN_0055a5f0, FUN_0055c250, FUN_00787270.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

void * __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0055a5f0(int param_1)



{

  void *pvVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a48af;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x24);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    FUN_00787270();

    *(float *)((int)pvVar1 + 0x10) = g_flOne;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x20) = 0;

    *(void **)((int)pvVar1 + 0xc) = pvVar1;

  }

  *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  local_4 = 0xffffffff;

  if (*(int *)(param_1 + 0x18) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) / 0x1c;

  }

  FUN_0055c250(iVar2);

  if (*(int *)(param_1 + 0x18) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18)) / 0x1c;

  }

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

  puVar5 = *(uint32_t /* width from decompiler */ **)((int)pvVar1 + 0x18);

  for (uVar3 = (uint)(iVar2 * 0x1c) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {

    *(uint8_t *)puVar5 = *(uint8_t *)puVar4;

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  }

  ExceptionList = local_c;

  return pvVar1;

}
