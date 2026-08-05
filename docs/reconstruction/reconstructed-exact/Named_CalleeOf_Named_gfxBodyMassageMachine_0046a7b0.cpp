// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_0046a7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0046a7b0
// Callee of Named_gfxBodyMassageMachine
// Address:   0x0046a7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0043a960, FUN_0046a7b0, FUN_0046a900.
//  - Return sites: 2.

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

void Named_CalleeOf_Named_gfxBodyMassageMachine_0046a7b0(void)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint8_t local_4 [4];

  

  iVar1 = *(int *)(in_EAX + 4);

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(in_EAX + 8) - iVar1) / 0x14) <

      (uint)((*(int *)(in_EAX + 0xc) - iVar1) / 0x14))) {

    iVar1 = *(int *)(in_EAX + 8);

    FUN_0043a960(iVar1);

    *(int *)(in_EAX + 8) = iVar1 + 0x14;

    return;

  }

  FUN_0046a900(local_4,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),unaff_EBX);

  return;

}
