// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0047f540
// -----------------------------------------------------------------------------
// Stable ID: aa_0047f540
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0047f540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_0047f4c0, FUN_0047f540.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0047f540(int param_1,uint8_t *param_2,int param_3)



{

  int iVar1;

  byte bVar2;

  

  iVar1 = FUN_0047f4c0();

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x16ac) = 8;

  if (param_3 != 0) {

    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = (byte)param_1;

    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

    bVar2 = (byte)((uint)param_1 >> 8);

    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = bVar2;

    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = ~(byte)param_1;

    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

    *(byte *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = ~bVar2;

    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

  }

  for (; param_1 != 0; param_1 = param_1 + -1) {

    *(uint8_t *)(*(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 8)) = *param_2;

    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;

    param_2 = param_2 + 1;

  }

  return;

}
