// =============================================================================
// FUN_0074efe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074efe0
// Address:   0x0074efe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0074efe0 @ 0x0074efe0
// Stable ID: aa_0074efe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0074efe0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0074efe0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ unaff_ESI;

  

  if (*(int *)(param_1 + 0xc) != 0) {

    if (in_EAX == 0) {

      in_EAX = (**(code **)(**(int **)(param_1 + 0xc) + 0xec))(*(int **)(param_1 + 0xc));

    }

    uVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x38))(*(int **)(param_1 + 0xc),in_EAX,param_2)

    ;

    iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x4c))

                      (*(int **)(param_1 + 0xc),uVar1,unaff_ESI);

    if (iVar2 != 0) {

      iVar2 = (**(code **)(**(int **)(param_1 + 0xc) + 0x54))

                        (*(int **)(param_1 + 0xc),iVar2,param_2,0xffffffff);

      if (-1 < iVar2) {

        return 0;

      }

    }

  }

  return 0xffffffff;

}
