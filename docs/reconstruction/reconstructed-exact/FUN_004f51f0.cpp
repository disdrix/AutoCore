// =============================================================================
// FUN_004f51f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f51f0
// Address:   0x004f51f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f51f0 @ 0x004f51f0
// Stable ID: aa_004f51f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_004f51f0.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_004f51f0(int param_1)



{

  int *piVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  piVar1 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);

  if ((piVar1 == (int *)0x0) || (iVar3 = (**(code **)(*piVar1 + 0x1d8))(), iVar3 == 0)) {

    uVar4 = 0;

  }

  else {

    iVar3 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1d8))

                      ();

    uVar4 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xa4 + iVar3);

  }

  iVar3 = 0;

  do {

    piVar1 = *(int **)(iVar3 + *(int *)(param_1 + 0x260));

    if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x3c))(), cVar2 != '\0')) {

      if (*(char *)((int)piVar1 + 0xcb) != '\0') {

        return 0;

      }

      cVar2 = (**(code **)(*piVar1 + 0x4c))(uVar4);

      if (cVar2 == '\0') {

        return 0;

      }

    }

    iVar3 = iVar3 + 4;

    if (0xb < iVar3) {

      return 1;

    }

  } while( true );

}
