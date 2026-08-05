// =============================================================================
// FUN_007fbb70
// -----------------------------------------------------------------------------
// Stable ID: aa_007fbb70
// Address:   0x007fbb70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fbb70 @ 0x007fbb70
// Stable ID: aa_007fbb70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007fbb70.
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

void __fastcall FUN_007fbb70(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int in_EAX;

  

  if (((param_2 == 0) || (*(int *)(in_EAX + 0x309c) == 0)) ||

     (param_2 == *(int *)(*(int *)(in_EAX + 0x309c) + 0x518))) {

    *(uint8_t *)(in_EAX + 0x30b4) = 1;

    *(uint8_t *)(in_EAX + 0x30b5) = 0;

    if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {

      (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);

    }

  }

  return;

}
