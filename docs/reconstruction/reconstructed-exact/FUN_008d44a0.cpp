// =============================================================================
// FUN_008d44a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008d44a0
// Address:   0x008d44a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d44a0 @ 0x008d44a0
// Stable ID: aa_008d44a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_008d42b0×2, FUN_008d44a0.
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

void FUN_008d44a0(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_8 = 0x80;

  local_4 = 0x20;

  if (*(int *)(unaff_ESI + 0x78c) != 0) {

    iVar3 = FUN_008d42b0(&local_8);

    if (iVar3 != 0) {

      piVar1 = *(int **)(unaff_ESI + 0x78c);

      iVar2 = *piVar1;

      uVar4 = (**(code **)(*piVar1 + 0x2d8))(1);

      uVar4 = (**(code **)(*piVar1 + 0x2c8))(uVar4);

      (**(code **)(iVar2 + 0x54))(iVar3,uVar4);

    }

  }

  if (*(int *)(unaff_ESI + 0x790) != 0) {

    iVar3 = FUN_008d42b0(&local_8);

    if (iVar3 != 0) {

      piVar1 = *(int **)(unaff_ESI + 0x790);

      iVar2 = *piVar1;

      uVar4 = (**(code **)(*piVar1 + 0x2d8))(1);

      uVar4 = (**(code **)(*piVar1 + 0x2c8))(uVar4);

      (**(code **)(iVar2 + 0x54))(iVar3,uVar4);

    }

  }

  return;

}
