// =============================================================================
// FUN_005f2f60
// -----------------------------------------------------------------------------
// Stable ID: aa_005f2f60
// Address:   0x005f2f60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005f2f60 @ 0x005f2f60
// Stable ID: aa_005f2f60
// Embedded strings (evidence for future rename):
//   - "true"
//   - "false"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: strncmp×2, FUN_005f2d70, FUN_005f2f60, builtin_strncpy.
//  - Strings: "o/_"; "true"; "false".
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

int __fastcall FUN_005f2f60(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ unaff_EDI;

  char acStack_14 [4];

  char cVar3;

  uint8_t *puStack_8;

  

  builtin_strncpy(acStack_14,"o/_",4);

  FUN_005f2d70();

  acStack_14[0] = '\x06';

  acStack_14[1] = '\0';

  acStack_14[2] = '\0';

  acStack_14[3] = '\0';

  (**(code **)(**(int **)(param_1 + 8) + 0x14))();

  iVar1 = (**(code **)(**(int **)(param_1 + 8) + 8))(&stack0xfffffff4,6);

  if (3 < iVar1) {

    iVar2 = strncmp(acStack_14,"true",4);

    if ((iVar2 == 0) &&

       ((((iVar1 == 4 || (cVar3 = (char)unaff_EDI, cVar3 == ' ')) || (cVar3 == '\t')) ||

        ((cVar3 == '\r' || (cVar3 == '\n')))))) {

      *puStack_8 = 1;

      (**(code **)(**(int **)(param_1 + 8) + 0x18))();

      (**(code **)(**(int **)(param_1 + 8) + 0xc))(4);

      return param_1;

    }

  }

  if (4 < iVar1) {

    iVar2 = strncmp(acStack_14,"false",4);

    if ((iVar2 == 0) &&

       (((iVar1 == 5 || (cVar3 = (char)((uint)unaff_EDI >> 8), cVar3 == ' ')) ||

        ((cVar3 == '\t' || ((cVar3 == '\r' || (cVar3 == '\n')))))))) {

      *puStack_8 = 0;

      (**(code **)(**(int **)(param_1 + 8) + 0x18))();

      (**(code **)(**(int **)(param_1 + 8) + 0xc))(5);

      return param_1;

    }

  }

  (**(code **)(**(int **)(param_1 + 8) + 0x18))();

  return param_1;

}
