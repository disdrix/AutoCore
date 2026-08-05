// =============================================================================
// FUN_0096bab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096bab0
// Address:   0x0096bab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096bab0 @ 0x0096bab0
// Stable ID: aa_0096bab0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, return×1.
//  - Notable callees: FUN_0096bab0.
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

void FUN_0096bab0(int param_1)



{

  int iVar1;

  int iVar2;

  int unaff_EBX;

  int iVar3;

  

  if (((((byte)*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) & 0xf) == 1) && (*(int *)(param_1 + 0x30) == 1)) &&

     (1 < *(uint *)(param_1 + 0x48))) {

    iVar3 = 0;

    if (unaff_EBX != 0) {

      iVar1 = *(int *)(param_1 + 0x1c);

      for (iVar2 = *(int *)(param_1 + 0x20);

          ((unaff_EBX < iVar1 || (unaff_EBX < iVar2)) && ((1 < iVar1 && (1 < iVar2))));

          iVar2 = iVar2 / 2) {

        iVar1 = iVar1 / 2;

        iVar3 = iVar3 + 1;

      }

    }

    (**(code **)(**(int **)(param_1 + 0x10) + 0x2c))(*(int **)(param_1 + 0x10),iVar3);

  }

  return;

}
