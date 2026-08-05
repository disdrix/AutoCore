// =============================================================================
// FUN_008452f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008452f0
// Address:   0x008452f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008452f0 @ 0x008452f0
// Stable ID: aa_008452f0
// Embedded strings (evidence for future rename):
//   - "\nCOID: %I64i\n"
//   - "CBID: %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: sprintf×2, FUN_008452f0.
//  - Strings: "\nCOID: %I64i\n"; "CBID: %d".
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

uint32_t /* width from decompiler */ FUN_008452f0(void)



{

  int *unaff_ESI;

  int unaff_EDI;

  char local_80 [128];

  

  sprintf(local_80,"\nCOID: %I64i\n",*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x160),

          *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x164));

  (**(code **)(*unaff_ESI + 0x250))(local_80);

  sprintf(&stack0xffffff7c,"CBID: %d",*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0xa8) + 0x34));

  (**(code **)(*unaff_ESI + 0x250))(&stack0xffffff7c);

  return 3;

}
