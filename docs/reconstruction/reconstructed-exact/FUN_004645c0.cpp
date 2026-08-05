// =============================================================================
// FUN_004645c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004645c0
// Address:   0x004645c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004645c0 @ 0x004645c0
// Stable ID: aa_004645c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_004645c0.
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

void FUN_004645c0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EBX;

  

  if (param_1 != param_2) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 8);

    puVar2 = param_1;

    for (; param_2 != puVar1; param_2 = param_2 + 2) {

      *puVar2 = *param_2;

      puVar2[1] = param_2[1];

      puVar2 = puVar2 + 2;

    }

    *(uint32_t /* width from decompiler */ **)(unaff_EBX + 8) = puVar2;

  }

  *in_EAX = param_1;

  return;

}
