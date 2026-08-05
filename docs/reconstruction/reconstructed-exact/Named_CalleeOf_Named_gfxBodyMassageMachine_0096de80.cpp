// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_0096de80
// -----------------------------------------------------------------------------
// Stable ID: aa_0096de80
// Callee of Named_gfxBodyMassageMachine
// Address:   0x0096de80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0096de80.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

void Named_CalleeOf_Named_gfxBodyMassageMachine_0096de80(void)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0xf4);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 4) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 8) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x20);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x24);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x28);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x2c);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x140) = 0xffffffff;

  return;

}
