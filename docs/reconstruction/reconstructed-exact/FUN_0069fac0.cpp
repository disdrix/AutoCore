// =============================================================================
// FUN_0069fac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0069fac0
// Address:   0x0069fac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069fac0 @ 0x0069fac0
// Stable ID: aa_0069fac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×2, do×1, return×1.
//  - Notable callees: isspace×2, FUN_0069fac0, sscanf.
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

char * FUN_0069fac0(void)



{

  char *pcVar1;

  char cVar2;

  char *in_EAX;

  int iVar3;

  char *unaff_EBX;

  

  iVar3 = isspace((int)*in_EAX);

  while (iVar3 != 0) {

    pcVar1 = in_EAX + 1;

    in_EAX = in_EAX + 1;

    iVar3 = isspace((int)*pcVar1);

  }

  sscanf(in_EAX,"%s");

  pcVar1 = unaff_EBX + 1;

  do {

    cVar2 = *unaff_EBX;

    unaff_EBX = unaff_EBX + 1;

  } while (cVar2 != '\0');

  return in_EAX + ((int)unaff_EBX - (int)pcVar1);

}
