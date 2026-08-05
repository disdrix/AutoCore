// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00478d10
// -----------------------------------------------------------------------------
// Stable ID: aa_00478d10
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x00478d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00478d10.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00478d10(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if ((param_2 != 0) && (puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + 0x1c), puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

    puVar2[6] = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = 0;

    *puVar2 = 0;

    puVar2[1] = 0;

    puVar2[3] = 0;

    puVar2[8] = 0;

    puVar2[9] = 0;

    puVar2[0xc] = 0;

    puVar2[0xd] = 0;

    puVar1 = puVar2 + 0x14a;

    puVar2[0x19] = puVar1;

    puVar2[0x12] = puVar1;

    puVar2[0x11] = puVar1;

    return 0;

  }

  return 0xfffffffe;

}
