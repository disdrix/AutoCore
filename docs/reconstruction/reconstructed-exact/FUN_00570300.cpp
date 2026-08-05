// =============================================================================
// FUN_00570300
// -----------------------------------------------------------------------------
// Stable ID: aa_00570300
// Address:   0x00570300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00570300 @ 0x00570300
// Stable ID: aa_00570300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: return×2, do×1, if×1, while×1.
//  - Notable callees: FUN_00570300, FUN_00570340.
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

int __fastcall FUN_00570300(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = *(int *)(param_1 + 0x14);

  do {

    if (iVar3 == 0) {

      return 0;

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(iVar3 + 8);

    puVar2 = (uint32_t /* width from decompiler */ *)(iVar3 + 0x10);

    iVar3 = *(int *)(iVar3 + 0x14);

    iVar4 = FUN_00570340(*puVar2,*puVar1,0);

  } while (-1 < iVar4);

  return iVar4;

}
