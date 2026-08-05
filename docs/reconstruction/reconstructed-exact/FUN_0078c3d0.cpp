// =============================================================================
// FUN_0078c3d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078c3d0
// Address:   0x0078c3d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078c3d0 @ 0x0078c3d0
// Stable ID: aa_0078c3d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_0074e260×2, FUN_0078c3d0.
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

void __fastcall FUN_0078c3d0(int param_1)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  

  if (*(int *)(param_1 + 0x2a4) != 0) {

    FUN_0074e260(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x2ac) + 0x8c));

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2ac) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2ac))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2ac) = 0;

    if (*(int *)(param_1 + 0x49c) != 0) {

      FUN_0074e260(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x49c) + 0x8c));

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x49c) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x49c))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x49c) = 0;

    }

    if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2a4) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2a4))(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a4) = 0;

    iVar2 = *(int *)(*(int *)(param_1 + 0x2a8) + 4);

    piVar3 = *(int **)(iVar2 + 0x3c);

    if (piVar3 != (int *)0x0) {

      piVar1 = piVar3 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c) = 0;

  }

  return;

}
