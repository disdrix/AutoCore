// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004f6ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f6ee0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
// Address:   0x004f6ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004cd220, FUN_004f6ee0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004f6ee0(int param_1)



{

  int iVar1;

  int iVar2;

  float10 fVar3;

  

  **(uint8_t **)(param_1 + 0x1a4) = 0;

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

  iVar2 = *(int *)(param_1 + 0x1a4);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb4);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc);

  iVar1 = *(int *)(param_1 + 0x1a4);

  fVar3 = (float10)FUN_004cd220(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x10),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x18));

  *(float *)(*(int *)(param_1 + 0x1a4) + 0x20) = (float)((float10)*(float *)(iVar1 + 0x14) - fVar3);

  iVar1 = *(int *)(param_1 + 0x1a4);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c) = 0;

  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x3c);

  iVar2 = *(int *)(param_1 + 0x1a4);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a4) + 0x80) = 0;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a4) + 0x7c) = 0;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a4) + 0x84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = 1;

  return;

}
