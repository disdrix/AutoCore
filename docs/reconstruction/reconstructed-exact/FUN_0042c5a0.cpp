// =============================================================================
// FUN_0042c5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042c5a0
// Address:   0x0042c5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042c5a0 @ 0x0042c5a0
// Stable ID: aa_0042c5a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0042c5a0.
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

int __fastcall FUN_0042c5a0(short *param_1)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  

  iVar3 = 0;

  if (0 < *(int *)(in_EAX + 0x24)) {

    piVar2 = *(int **)(in_EAX + 0x2c);

    do {

      iVar1 = *piVar2;

      if ((((*param_1 == *(short *)(iVar1 + 0xf8)) && (param_1[1] == *(short *)(iVar1 + 0xfa))) &&

          (*(int *)(param_1 + 2) == *(int *)(iVar1 + 0xfc))) &&

         (((*(int *)(param_1 + 4) == *(int *)(iVar1 + 0x100) &&

           (*(int *)(param_1 + 6) == *(int *)(iVar1 + 0x104))) &&

          (*(int *)(param_1 + 8) == *(int *)(iVar1 + 0x108))))) {

        return (*(int **)(in_EAX + 0x2c))[iVar3];

      }

      iVar3 = iVar3 + 1;

      piVar2 = piVar2 + 1;

    } while (iVar3 < *(int *)(in_EAX + 0x24));

  }

  return 0;

}
