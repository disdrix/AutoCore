// =============================================================================
// FUN_0092f440
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f440
// Address:   0x0092f440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092f440 @ 0x0092f440
// Stable ID: aa_0092f440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007a69d0, FUN_0092f440.
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

void FUN_0092f440(void)



{

  char cVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_c;

  int local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_c = 0x805e;

  iVar2 = FUN_007a69d0();

  local_8 = (int)*(char *)(iVar2 + 0x2c);

  local_4 = 0;

  if (*(int *)(unaff_ESI + 0xc7c) != 0) {

    cVar1 = (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 8))();

    if (cVar1 != '\0') {

      (**(code **)(**(int **)(unaff_ESI + 0xc7c) + 0x18))(0xffffffff,&local_c,0xc,0);

    }

  }

  return;

}
