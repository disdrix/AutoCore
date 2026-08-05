// =============================================================================
// Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00652910
// -----------------------------------------------------------------------------
// Stable ID: aa_00652910
// Callee of Named_SERVER_GOT_GIGO_0x_x
// Address:   0x00652910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SERVER_GOT_GIGO_0x_x: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, return×3.
//  - Notable callees: FUN_00652910.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_SERVER_GOT_GIGO_0x_x
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

void __thiscall Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_00652910(int param_1,uint8_t *param_2,int param_3,int param_4)



{

  uint8_t uVar1;

  

  (**(code **)(**(int **)(param_1 + 8) + 8))(param_2,param_3 * param_4);

  if (*(char *)(param_1 + 0xc) != '\0') {

    if (param_3 == 2) {

      if (0 < param_4) {

        do {

          uVar1 = *param_2;

          *param_2 = param_2[1];

          param_2[1] = uVar1;

          param_2 = param_2 + 2;

          param_4 = param_4 + -1;

        } while (param_4 != 0);

      }

    }

    else if (param_3 == 4) {

      if (0 < param_4) {

        param_2 = param_2 + 2;

        do {

          uVar1 = param_2[-2];

          param_2[-2] = param_2[1];

          param_2[1] = uVar1;

          uVar1 = param_2[-1];

          param_2[-1] = *param_2;

          *param_2 = uVar1;

          param_2 = param_2 + 4;

          param_4 = param_4 + -1;

        } while (param_4 != 0);

        return;

      }

    }

    else if ((param_3 == 8) && (0 < param_4)) {

      param_2 = param_2 + 6;

      do {

        uVar1 = param_2[-6];

        param_2[-6] = param_2[1];

        param_2[1] = uVar1;

        uVar1 = param_2[-5];

        param_2[-5] = *param_2;

        *param_2 = uVar1;

        uVar1 = param_2[-4];

        param_2[-4] = param_2[-1];

        param_2[-1] = uVar1;

        uVar1 = param_2[-3];

        param_2[-3] = param_2[-2];

        param_2[-2] = uVar1;

        param_2 = param_2 + 8;

        param_4 = param_4 + -1;

      } while (param_4 != 0);

      return;

    }

  }

  return;

}
