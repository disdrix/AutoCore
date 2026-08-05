// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_00914500
// -----------------------------------------------------------------------------
// Stable ID: aa_00914500
// Callee of Client_Input_PollBoundActions
// Address:   0x00914500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×15, return×2.
//  - Notable callees: FUN_00914500.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

uint8_t Named_CalleeOf_Client_Input_PollBoundActions_00914500(void)



{

  char cVar1;

  

  cVar1 = (**(code **)(*DAT_00d1b8dc + 0x3d8))();

  if (cVar1 == '\0') {

    cVar1 = (**(code **)(*DAT_00d1b8e0 + 0x3d8))();

    if (cVar1 == '\0') {

      cVar1 = (**(code **)(*DAT_00d1b8e4 + 0x3d8))();

      if (cVar1 == '\0') {

        cVar1 = (**(code **)(*DAT_00d1b8e8 + 0x3d8))();

        if (cVar1 == '\0') {

          cVar1 = (**(code **)(*DAT_00d1b8d4 + 0x3d8))();

          if (cVar1 == '\0') {

            cVar1 = (**(code **)(*DAT_00d1b8f4 + 0x3d8))();

            if (cVar1 == '\0') {

              cVar1 = (**(code **)(*DAT_00d1b8c4 + 0x3d8))();

              if (cVar1 == '\0') {

                cVar1 = (**(code **)(*DAT_00d1b8ec + 0x3d8))();

                if (cVar1 == '\0') {

                  cVar1 = (**(code **)(*DAT_00d1b8c8 + 0x3d8))();

                  if (cVar1 == '\0') {

                    cVar1 = (**(code **)(*DAT_00d1b8f8 + 0x3d8))();

                    if (cVar1 == '\0') {

                      cVar1 = (**(code **)(*DAT_00d1b8fc + 0x3d8))();

                      if (cVar1 == '\0') {

                        cVar1 = (**(code **)(*DAT_00d1b92c + 0x3d8))();

                        if (cVar1 == '\0') {

                          cVar1 = (**(code **)(*DAT_00d1b8f0 + 0xd0))();

                          if (cVar1 == '\0') {

                            cVar1 = (**(code **)(*DAT_00d1b930 + 0x3d8))();

                            if (cVar1 == '\0') {

                              cVar1 = (**(code **)(*DAT_00d1b938 + 0x3d8))();

                              if (cVar1 == '\0') {

                                return 0;

                              }

                            }

                          }

                        }

                      }

                    }

                  }

                }

              }

            }

          }

        }

      }

    }

  }

  return 1;

}
