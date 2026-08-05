// =============================================================================
// FUN_0092dcc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092dcc0
// Address:   0x0092dcc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092dcc0 @ 0x0092dcc0
// Stable ID: aa_0092dcc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, goto×1, return×1, while×1.
//  - Notable callees: FUN_00426120, FUN_0059e290, FUN_0092dcc0.
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

void FUN_0092dcc0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  char unaff_BL;

  int iVar4;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar2 = param_1;

  *(char *)(param_1 + 0xa0e) = unaff_BL;

  iVar4 = 0;

  do {

    if (iVar4 == 0) {

      piVar1 = *(int **)(iVar2 + 0xc78);

      if (piVar1 != (int *)0x0) {

        iVar3 = (**(code **)(*piVar1 + 0x48))();

LAB_0092dcfa:

        if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0xb4) & 0xc) == 0)) {

          FUN_0059e290(&uStack_4,&uStack_8,&param_1,&uStack_c);

          if (unaff_BL == '\x01') {

            param_1 = 10000;

            uStack_c = 10000;

          }

          else if (unaff_BL == '\x02') {

            param_1 = 5000;

            uStack_c = 5000;

          }

          else {

            param_1 = 20000;

            uStack_c = 20000;

          }

          FUN_00426120(uStack_4,uStack_8,param_1,uStack_c);

        }

      }

    }

    else {

      piVar1 = *(int **)(iVar2 + 0xc7c);

      if (piVar1 != (int *)0x0) {

        iVar3 = (**(code **)(*piVar1 + 0x48))();

        goto LAB_0092dcfa;

      }

    }

    iVar4 = iVar4 + 1;

    if (1 < iVar4) {

      return;

    }

  } while( true );

}
