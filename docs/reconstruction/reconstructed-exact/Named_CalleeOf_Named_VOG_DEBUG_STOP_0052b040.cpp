// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0052b040
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b040
// Callee of Named_VOG_DEBUG_STOP (+7 other named callers)
// Address:   0x0052b040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, for×1.
//  - Notable callees: CONCAT31, FUN_0052b040, FUN_00538ab0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+7 other named callers)
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

int Named_CalleeOf_Named_VOG_DEBUG_STOP_0052b040(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  int *piVar2;

  uint3 uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint8_t local_4 [4];

  

  piVar2 = (int *)FUN_00538ab0(local_4,&param_1);

  iVar1 = *piVar2;

  uVar3 = (uint3)((uint)iVar1 >> 8);

  if (iVar1 == DAT_00b045b4) {

    return (uint)uVar3 << 8;

  }

  puVar5 = (uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

  for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *param_2 = *puVar5;

    puVar5 = puVar5 + 1;

    param_2 = param_2 + 1;

  }

  return CONCAT31(uVar3,1);

}
