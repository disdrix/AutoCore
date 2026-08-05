// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0046c300
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c300
// Callee of Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x0046c300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0044fc90, FUN_0046c300, FUN_0046cbc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0046c300(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = *(int *)(in_EAX + 4);

  local_4 = param_1;

  if ((iVar1 != 0) &&

     ((uint)((*(int *)(in_EAX + 8) - iVar1) / 0x24) <

      (uint)((*(int *)(in_EAX + 0xc) - iVar1) / 0x24))) {

    iVar1 = *(int *)(in_EAX + 8);

    FUN_0044fc90(param_1);

    *(int *)(in_EAX + 8) = iVar1 + 0x24;

    return;

  }

  FUN_0046cbc0(&local_4,*(uint32_t /* width from decompiler */ *)(in_EAX + 8),param_1);

  return;

}
