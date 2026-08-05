// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004b7330
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7330
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
// Address:   0x004b7330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×1, while×1.
//  - Notable callees: FUN_004b7330.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB
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

uint8_t __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004b7330(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint8_t uVar3;

  int *piVar4;

  

  if ((((*(char *)(param_1 + 10) == '\0') && (*(char *)(param_1 + 9) == '\0')) &&

      (*(int *)(param_1 + 0x1e4) == 0)) && (*(int *)(param_1 + 0x214) == 0)) {

    for (puVar1 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x204);

        puVar1 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x204); puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

      if (*(char *)(puVar1[2] + 0x795) == '\0') {

        return 0;

      }

    }

    uVar3 = 1;

    if (((*(int *)(param_1 + 0x1f0) != 0) && (*(char *)(param_1 + 6) == '\0')) &&

       ((*(char *)(param_1 + 7) == '\0' && (*(char *)(param_1 + 8) == '\0')))) {

      piVar2 = *(int **)(param_1 + 0x1ec);

      piVar4 = (int *)*piVar2;

      if (piVar4 != piVar2) {

        while (*(char *)(piVar4[2] + 0x10b) == '\0') {

          piVar4 = (int *)*piVar4;

          if (piVar4 == piVar2) {

            return uVar3;

          }

        }

        uVar3 = 0;

      }

    }

    return uVar3;

  }

  return 0;

}
