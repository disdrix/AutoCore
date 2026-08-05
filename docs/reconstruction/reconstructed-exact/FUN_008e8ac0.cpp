// =============================================================================
// FUN_008e8ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e8ac0
// Address:   0x008e8ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e8ac0 @ 0x008e8ac0
// Stable ID: aa_008e8ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, while×1.
//  - Notable callees: FUN_008e8ac0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ FUN_008e8ac0(uint param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int unaff_EBX;

  

  if ((param_1 & param_2) == 0xffffffff) {

    return 0;

  }

  iVar2 = 0;

  piVar3 = (int *)(unaff_EBX + 0x52c);

  while (((iVar1 = *piVar3, iVar1 == 0 || (*(uint *)(iVar1 + 8) != param_1)) ||

         (*(uint *)(iVar1 + 0xc) != param_2))) {

    iVar2 = iVar2 + 1;

    piVar3 = piVar3 + 1;

    if (3 < iVar2) {

      return 0;

    }

  }

  return *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x52c + iVar2 * 4);

}
