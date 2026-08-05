// =============================================================================
// FUN_00431c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00431c00
// Address:   0x00431c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00431c00 @ 0x00431c00
// Stable ID: aa_00431c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00431c00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_00431c00(int param_1)



{

  int in_EAX;

  

  *(int *)(in_EAX + 0x210) = *(int *)(in_EAX + 0x210) + -1;

  if (*(int *)(param_1 + 0x34) != *(int *)(in_EAX + 0x210)) {

    *(int *)(*(int *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x210) * 4) + 0x34) =

         *(int *)(param_1 + 0x34);

    *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x208) + *(int *)(param_1 + 0x34) * 4) =

         *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x210) * 4);

    *(int *)(*(int *)(in_EAX + 0x208) + *(int *)(in_EAX + 0x210) * 4) = param_1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x210);

  }

  return;

}
