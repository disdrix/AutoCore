// =============================================================================
// FUN_0044b4f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044b4f0
// Address:   0x0044b4f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044b4f0 @ 0x0044b4f0
// Stable ID: aa_0044b4f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_0044b4f0, FUN_00972cc0, _aligned_malloc.
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

void * FUN_0044b4f0(size_t param_1)



{

  int in_EAX;

  void *pvVar1;

  int extraout_EDX;

  void *pvVar2;

  int iVar3;

  

  if (in_EAX == 0) {

    return (void *)0x0;

  }

  pvVar1 = _aligned_malloc(in_EAX * 0xc0,param_1);

  pvVar2 = pvVar1;

  for (; in_EAX != 0; in_EAX = in_EAX + -1) {

    iVar3 = 0;

    if (pvVar2 != (void *)0x0) {

      FUN_00972cc0();

      iVar3 = extraout_EDX;

    }

    pvVar2 = (void *)(iVar3 + 0xc0);

  }

  return pvVar1;

}
