// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_008705c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008705c0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGClient
// Address:   0x008705c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: sprintf×3, FUN_007a6de0×2, FUN_007a69d0, FUN_008705c0.
//  - Strings: "%s %d".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGClient
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_008705c0(int param_1,char *param_2)



{

  int in_EAX;

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  if (param_2 != (char *)0x0) {

    FUN_007a69d0();

    iVar3 = 0;

    piVar1 = (int *)(param_1 + 0x518);

    do {

      if (*piVar1 == in_EAX) {

        iVar4 = *(int *)(param_1 + (iVar3 * 3 + 0x147) * 4);

        if (iVar4 == 0) {

          iVar4 = in_EAX + -9999;

          uVar2 = FUN_007a6de0(&DAT_00a5cb2c,0xffffffff);

          sprintf(param_2,"%s %d",uVar2,iVar4);

        }

        else {

          sprintf(param_2,"%s",iVar4);

        }

        break;

      }

      iVar3 = iVar3 + 1;

      piVar1 = piVar1 + 3;

    } while (iVar3 < 4);

    if (iVar3 == 4) {

      iVar3 = in_EAX + -9999;

      uVar2 = FUN_007a6de0(&DAT_00a5cb2c,0xffffffff);

      sprintf(param_2,"%s %d",uVar2,iVar3);

    }

  }

  return;

}
