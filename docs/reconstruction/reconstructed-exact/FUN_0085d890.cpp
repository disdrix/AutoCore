// =============================================================================
// FUN_0085d890
// -----------------------------------------------------------------------------
// Stable ID: aa_0085d890
// Address:   0x0085d890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085d890 @ 0x0085d890
// Stable ID: aa_0085d890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0085d890.
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

void FUN_0085d890(void)



{

  short sVar1;

  short sVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *unaff_ESI;

  int unaff_EDI;

  

  if (unaff_EDI != 0) {

    if (unaff_ESI != (int *)0x0) {

      uVar3 = (**(code **)(*unaff_ESI + 0x80))();

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x58) = uVar3;

      sVar1 = (**(code **)(*unaff_ESI + 0x8c))();

      iVar4 = (**(code **)(*unaff_ESI + 0x80))();

      *(int *)(unaff_EDI + 0x54) = sVar1 - iVar4;

      sVar1 = *(short *)(*(int *)(unaff_ESI[0x2a] + 0x3c) + 0x4b4);

      sVar2 = (**(code **)(*unaff_ESI + 0x8c))();

      *(int *)(unaff_EDI + 0x50) = (int)sVar1 - (int)sVar2;

      return;

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x54) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x58) = 0;

  }

  return;

}
