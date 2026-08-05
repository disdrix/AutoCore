// =============================================================================
// Named_CalleeOf_Client_QuickBarActivateSkillSlot_0089ff80
// -----------------------------------------------------------------------------
// Stable ID: aa_0089ff80
// Callee of Client_QuickBarActivateSkillSlot
// Address:   0x0089ff80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_QuickBarActivateSkillSlot: skill/cast helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0089ff80.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_QuickBarActivateSkillSlot
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

void Named_CalleeOf_Client_QuickBarActivateSkillSlot_0089ff80(void)



{

  char in_AL;

  char cVar1;

  int unaff_ESI;

  

  if (*(char *)(unaff_ESI + 0x522) != '\0') {

    if (in_AL == '\0') {

      if (*(int *)(unaff_ESI + 0x66c) != 0) {

        cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0xd0))();

        if (cVar1 != '\0') {

          *(uint8_t *)(*(int *)(unaff_ESI + 0x66c) + 0x4fe) = 0;

                    /* WARNING: Could not recover jumptable at 0x0089fffc. Too many branches */

                    /* WARNING: Treating indirect jump as call */

          (**(code **)(**(int **)(unaff_ESI + 0x66c) + 0x448))();

          return;

        }

      }

    }

    else if ((in_AL == '\x01') && (*(int *)(unaff_ESI + 0x670) != 0)) {

      cVar1 = (**(code **)(**(int **)(unaff_ESI + 0x670) + 0xd0))();

      if (cVar1 != '\0') {

        *(uint8_t *)(*(int *)(unaff_ESI + 0x670) + 0x4fe) = 0;

                    /* WARNING: Could not recover jumptable at 0x0089ffc6. Too many branches */

                    /* WARNING: Treating indirect jump as call */

        (**(code **)(**(int **)(unaff_ESI + 0x670) + 0x448))();

        return;

      }

    }

  }

  return;

}
