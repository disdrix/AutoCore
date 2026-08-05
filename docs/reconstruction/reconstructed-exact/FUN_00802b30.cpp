// =============================================================================
// FUN_00802b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00802b30
// Address:   0x00802b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00802b30 @ 0x00802b30
// Stable ID: aa_00802b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: Client_QuickBar_ActivateSlot, FUN_00802b30, FUN_0089fe10, FUN_0089fe40.
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

void FUN_00802b30(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if (*(int **)(unaff_EDI + 0x10b0) != (int *)0x0) {

    cVar1 = (**(code **)(**(int **)(unaff_EDI + 0x10b0) + 0x3d8))();

    if (cVar1 != '\0') {

      cVar1 = FUN_0089fe40();

      if (cVar1 != '\0') {

        uVar4 = 0xffffffff;

        uVar3 = 0;

        uVar2 = FUN_0089fe10(0,0xffffffff);

        Client_QuickBar_ActivateSlot(uVar2,uVar3,uVar4);

      }

    }

  }

  return;

}
