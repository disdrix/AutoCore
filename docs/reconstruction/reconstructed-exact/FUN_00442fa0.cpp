// =============================================================================
// FUN_00442fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00442fa0
// Address:   0x00442fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00442fa0 @ 0x00442fa0
// Stable ID: aa_00442fa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00442fa0, FUN_00443040, FUN_004433a0.
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

void FUN_00442fa0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint unaff_EBX;

  int unaff_EDI;

  

  iVar1 = *(int *)(unaff_EDI + 4);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(unaff_EDI + 8) - iVar1) / 0x14;

  }

  if (uVar2 < unaff_EBX) {

    FUN_00443040(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),&param_1);

    return;

  }

  if (((iVar1 != 0) && (unaff_EBX < (uint)((*(int *)(unaff_EDI + 8) - iVar1) / 0x14))) &&

     (iVar1 + unaff_EBX * 0x14 != *(int *)(unaff_EDI + 8))) {

    uVar3 = FUN_004433a0(param_1);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = uVar3;

  }

  return;

}
