// =============================================================================
// FUN_004bdb10
// -----------------------------------------------------------------------------
// Stable ID: aa_004bdb10
// Address:   0x004bdb10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004bdb10 @ 0x004bdb10
// Stable ID: aa_004bdb10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004bdb10, FUN_0074c9c0.
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

void __fastcall FUN_004bdb10(int param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  while( true ) {

    if ((*(int *)(param_1 + 0x18) != 0) &&

       (piVar1 = *(int **)(*(int *)(param_1 + 0x18) + 0xc), *piVar1 != 0)) {

      piVar1 = (int *)*piVar1;

      uVar3 = (**(code **)(*piVar1 + 0xc))();

      uVar4 = (**(code **)(*piVar1 + 0x48))(uVar3);

      FUN_0074c9c0(&DAT_00d1eb60,uVar4,uVar3);

    }

    if ((*(int *)(param_1 + 0x18) == 0) ||

       (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar2 == 0)) break;

    *(int *)(param_1 + 0x18) = iVar2;

  }

  *(uint8_t *)(param_1 + 0x5c4) = 1;

  return;

}
