// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_hkWorld_006cafd0
// -----------------------------------------------------------------------------
// Stable ID: aa_006cafd0
// Callee of Named_CalleeOf_Named_hkWorld
// Address:   0x006cafd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_006cafd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_hkWorld
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_hkWorld_006cafd0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint8_t *puVar2;

  int iVar3;

  int local_4;

  

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x118c);

  puVar2 = (uint8_t *)(param_1 + 0x418e);

  local_4 = 0x20;

  do {

    iVar3 = 0x20;

    do {

      puVar1[-0x400] = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

      *puVar1 = FUN_0056f570;

      puVar1[0x400] = FUN_0056f570;

      puVar1[0x800] = FUN_0056f570;

      *puVar2 = 100;

      puVar1 = puVar1 + 1;

      puVar2 = puVar2 + 3;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  return;

}
