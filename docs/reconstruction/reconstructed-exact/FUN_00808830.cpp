// =============================================================================
// FUN_00808830
// -----------------------------------------------------------------------------
// Stable ID: aa_00808830
// Address:   0x00808830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00808830 @ 0x00808830
// Stable ID: aa_00808830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00808830.
//  - Return sites: 2.

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

void __fastcall FUN_00808830(int param_1)



{

  int in_EAX;

  

  if (*(char *)(in_EAX + 4) != '\0') {

    CVOGReaction_SpawnObject

              (*(void **)(param_1 + 0xe04),*(uint32_t /* width from decompiler */ *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc)

              );

    return;

  }

  CVOGReaction_RemoveObject

            (*(void **)(param_1 + 0xe04),*(uint *)(in_EAX + 8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),

             *(char *)(in_EAX + 5));

  return;

}
