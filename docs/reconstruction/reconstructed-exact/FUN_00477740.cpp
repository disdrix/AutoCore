// =============================================================================
// FUN_00477740
// -----------------------------------------------------------------------------
// Stable ID: aa_00477740
// Address:   0x00477740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477740 @ 0x00477740
// Stable ID: aa_00477740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00476cc0, FUN_00477740, malloc.
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

void * __fastcall FUN_00477740(size_t param_1)



{

  uint uVar1;

  void *pvVar2;

  int unaff_ESI;

  

  uVar1 = *(uint *)(unaff_ESI + 0x6c);

  *(uint *)(unaff_ESI + 0x6c) = uVar1 | 0x100000;

  if (param_1 == 0) {

    pvVar2 = (void *)0x0;

  }

  else {

    if (*(code **)(unaff_ESI + 0x248) == (code *)0x0) {

      pvVar2 = malloc(param_1);

    }

    else {

      pvVar2 = (void *)(**(code **)(unaff_ESI + 0x248))();

    }

    if ((pvVar2 == (void *)0x0) && ((*(byte *)(unaff_ESI + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

  }

  *(uint *)(unaff_ESI + 0x6c) = uVar1;

  return pvVar2;

}
