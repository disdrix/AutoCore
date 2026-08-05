// =============================================================================
// FUN_007701a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007701a0
// Address:   0x007701a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007701a0 @ 0x007701a0
// Stable ID: aa_007701a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_007701a0.
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

void FUN_007701a0(void)



{

  uint8_t uVar1;

  int in_EAX;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  

  iVar2 = in_EAX + -1;

  iVar3 = 0;

  if (0 < iVar2) {

    do {

      uVar1 = *(uint8_t *)(iVar3 + unaff_ESI);

      *(uint8_t *)(iVar3 + unaff_ESI) = *(uint8_t *)(iVar2 + unaff_ESI);

      *(uint8_t *)(iVar2 + unaff_ESI) = uVar1;

      iVar3 = iVar3 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar3 < iVar2);

  }

  return;

}
