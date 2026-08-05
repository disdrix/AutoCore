// =============================================================================
// FUN_005a6290
// -----------------------------------------------------------------------------
// Stable ID: aa_005a6290
// Address:   0x005a6290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a6290 @ 0x005a6290
// Stable ID: aa_005a6290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_005a6290.
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

void __fastcall FUN_005a6290(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = 0;

  while( true ) {

    if (*(int *)(param_1 + 0x14) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2;

    }

    if (iVar1 <= iVar3) break;

    iVar1 = iVar3 * 4;

    piVar2 = (int *)(*(int *)(param_1 + 0x14) + iVar1);

    if (*piVar2 != 0) {

      (**(code **)(*(int *)*piVar2 + 0x18))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x134));

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + iVar1) = 0;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x24) + iVar1) = 0xffffffff;

    iVar3 = iVar3 + 1;

  }

  return;

}
