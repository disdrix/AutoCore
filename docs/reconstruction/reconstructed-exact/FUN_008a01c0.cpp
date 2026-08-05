// =============================================================================
// FUN_008a01c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008a01c0
// Address:   0x008a01c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a01c0 @ 0x008a01c0
// Stable ID: aa_008a01c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0089ff30, FUN_008a01c0.
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

void __thiscall FUN_008a01c0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  if (param_2 != 0) {

    iVar1 = FUN_0089ff30(*(int *)(param_2 + 0x5fc),*(int *)(param_2 + 0x5fc) >> 0x1f);

    if (iVar1 != 0) {

      *(uint8_t *)(iVar1 + 0x4fe) = 0;

    }

  }

  piVar2 = (int *)(param_1 + 0x63c);

  iVar1 = 10;

  do {

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 0x448))();

    }

    piVar2 = piVar2 + 1;

    iVar1 = iVar1 + -1;

  } while (iVar1 != 0);

  return;

}
