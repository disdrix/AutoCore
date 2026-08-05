// =============================================================================
// FUN_0090fb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0090fb20
// Address:   0x0090fb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090fb20 @ 0x0090fb20
// Stable ID: aa_0090fb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00755db0×2, FUN_00755e80×2, FUN_0076c4d0×2, FUN_004ba600, FUN_00590120, FUN_00593d70, FUN_0090fb20.
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

void FUN_0090fb20(int param_1)



{

  int iVar1;

  int iVar2;

  char cVar3;

  

  FUN_004ba600();

  FUN_00590120();

  FUN_00593d70();

  iVar1 = *(int *)(DAT_00d17944 + 0x170);

  if (iVar1 != 0) {

    iVar2 = *(int *)(param_1 + 0x2a8);

    *(uint8_t *)(iVar2 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40);

    FUN_0076c4d0();

    cVar3 = (**(code **)(**(int **)(iVar2 + 8) + 8))(iVar1);

    if (cVar3 != '\0') {

      FUN_00755db0(iVar1);

      FUN_00755e80(iVar1);

    }

  }

  iVar1 = *(int *)(DAT_00d17944 + 0x184);

  if (iVar1 != 0) {

    iVar2 = *(int *)(param_1 + 0x2a8);

    *(uint8_t *)(iVar2 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40);

    FUN_0076c4d0();

    cVar3 = (**(code **)(**(int **)(iVar2 + 8) + 8))(iVar1);

    if (cVar3 != '\0') {

      FUN_00755db0(iVar1);

      FUN_00755e80(iVar1);

    }

  }

  return;

}
