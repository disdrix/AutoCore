// =============================================================================
// FUN_0075e2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e2d0
// Address:   0x0075e2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075e2d0 @ 0x0075e2d0
// Stable ID: aa_0075e2d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_0043bcc0, FUN_0044e8c0, FUN_00745e20, FUN_00745f80, FUN_0075e2d0, FUN_00970b20, FUN_00971a20.
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

uint32_t /* width from decompiler */ __fastcall FUN_0075e2d0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  char cVar3;

  int local_4;

  

  local_4 = param_1;

  FUN_0044e8c0(&local_4);

  iVar2 = local_4;

  if ((local_4 != *(int *)(param_1 + 8)) &&

     (puVar1 = *(uint32_t /* width from decompiler */ **)(local_4 + 0xc), *(int *)(local_4 + 0x10) == 0)) {

    if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

      if (*(int *)(param_1 + 0x6c) != 0) {

        FUN_00971a20(local_4 + 8,1);

      }

    }

    else {

      cVar3 = FUN_00745e20();

      if (cVar3 == '\0') {

        if (*(int *)(param_1 + 0x6c) != 0) {

          FUN_00970b20(*(int *)(param_1 + 0x6c));

        }

        FUN_00745f80();

        (**(code **)*puVar1)(1);

        FUN_0043bcc0(&stack0x00000000,iVar2);

        return 1;

      }

    }

  }

  return 0;

}
