// =============================================================================
// FUN_0043b870
// -----------------------------------------------------------------------------
// Stable ID: aa_0043b870
// Address:   0x0043b870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043b870 @ 0x0043b870
// Stable ID: aa_0043b870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_0043b870.
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

void FUN_0043b870(void)



{

  char *pcVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar3;

  char *pcVar4;

  

  pcVar4 = (char *)*in_EAX;

  uVar3 = 0;

  if (pcVar4 != (char *)0x0) {

    cVar2 = *pcVar4;

    while (cVar2 != '\0') {

      uVar3 = uVar3 * 0x10 + (int)cVar2;

      if ((uVar3 & 0xf0000000) != 0) {

        uVar3 = uVar3 ^ (uVar3 & 0xf0000000) >> 0x18;

      }

      pcVar1 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

      cVar2 = *pcVar1;

    }

  }

  return;

}
