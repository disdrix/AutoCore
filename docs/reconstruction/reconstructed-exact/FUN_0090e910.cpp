// =============================================================================
// FUN_0090e910
// -----------------------------------------------------------------------------
// Stable ID: aa_0090e910
// Address:   0x0090e910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090e910 @ 0x0090e910
// Stable ID: aa_0090e910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0074e260, FUN_0090e910.
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

void __fastcall FUN_0090e910(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int *piVar3;

  

  piVar3 = param_1 + 0x184;

  iVar2 = 2;

  do {

    if (*piVar3 != 0) {

      uVar1 = *(uint32_t /* width from decompiler */ *)(*piVar3 + 0x8c);

      (**(code **)(*param_1 + 0x1a8))();

      FUN_0074e260(uVar1);

      if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

      }

      *piVar3 = 0;

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
