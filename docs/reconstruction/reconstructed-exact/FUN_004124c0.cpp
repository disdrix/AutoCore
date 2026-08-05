// =============================================================================
// FUN_004124c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004124c0
// Address:   0x004124c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004124c0 @ 0x004124c0
// Stable ID: aa_004124c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004124c0, FUN_00412730, FUN_00442a50.
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

void FUN_004124c0(uint32_t /* width from decompiler */ param_1)



{

  uint in_EAX;

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  

  iVar2 = *(int *)(unaff_EDI + 4);

  if (iVar2 == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = (*(int *)(unaff_EDI + 8) - iVar2) / 0x18;

  }

  if (uVar1 < in_EAX) {

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(unaff_EDI + 8) - iVar2) / 0x18;

    }

    FUN_00412730(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),in_EAX - iVar2,&param_1);

    return;

  }

  if (iVar2 != 0) {

    if ((in_EAX < (uint)((*(int *)(unaff_EDI + 8) - iVar2) / 0x18)) &&

       (iVar2 + in_EAX * 0x18 != *(int *)(unaff_EDI + 8))) {

      uVar3 = FUN_00442a50(param_1);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = uVar3;

    }

  }

  return;

}
