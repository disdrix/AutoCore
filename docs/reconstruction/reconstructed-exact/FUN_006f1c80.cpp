// =============================================================================
// FUN_006f1c80
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1c80
// Address:   0x006f1c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1c80 @ 0x006f1c80
// Stable ID: aa_006f1c80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_006f1c80.
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

void __thiscall FUN_006f1c80(int param_1,int param_2)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  

  *(int *)(param_1 + 0x38) = *(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x24);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c);

  iVar3 = 0;

  if (0 < *(int *)(param_2 + 0x2c)) {

    piVar2 = (int *)(param_1 + 0x44);

    piVar1 = (int *)(param_2 + 0x30);

    do {

      piVar2[-1] = *piVar1;

      *piVar2 = piVar1[1] - *piVar1;

      iVar3 = iVar3 + 1;

      piVar1 = piVar1 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar3 < *(int *)(param_2 + 0x2c));

  }

  return;

}
