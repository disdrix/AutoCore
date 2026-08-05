// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00773ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_00773ca0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x00773ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~164 non-empty decompiler lines.
//  - Control keywords: if×45, return×1.
//  - Notable callees: FUN_007716f0×12, FUN_00772390×10, FUN_00774b50×5, FUN_00771a00×4, FUN_00771c00×4, FUN_00770280×2, FUN_00770650×2, FUN_00771b60×2.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00773ca0(void)



{

  int iVar1;

  int *in_EAX;

  int iVar2;

  uint8_t local_94 [16];

  uint8_t local_84 [16];

  uint8_t local_74 [16];

  uint8_t local_64 [16];

  uint8_t local_54 [16];

  uint8_t local_44 [16];

  uint8_t local_34 [16];

  int local_24;

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  iVar2 = FUN_00771cb0(local_10,local_74,local_84,local_64,local_34,local_20,local_54,local_44,

                       local_94,0);

  if (iVar2 == 0) {

    local_24 = *in_EAX / 3;

    iVar1 = local_24 * 0x1c;

    iVar2 = FUN_00771b60(iVar1);

    if (iVar2 == 0) {

      iVar2 = FUN_00770650();

      if (iVar2 == 0) {

        FUN_00770280();

        FUN_00771b60(iVar1);

        iVar2 = FUN_00770650();

        if (iVar2 == 0) {

          FUN_00770280();

          iVar2 = FUN_00774b50(local_20,local_10);

          if (iVar2 == 0) {

            iVar2 = FUN_00774b50(local_44,local_34);

            if (iVar2 == 0) {

              iVar2 = FUN_00771a00(local_20,local_94);

              if (iVar2 == 0) {

                iVar2 = FUN_00772390();

                if (iVar2 == 0) {

                  iVar2 = FUN_00771a00(local_94,local_94);

                  if (iVar2 == 0) {

                    iVar2 = FUN_00772390();

                    if (iVar2 == 0) {

                      iVar2 = FUN_00774b50(local_94,local_74);

                      if (iVar2 == 0) {

                        iVar2 = FUN_00771a00(local_44,local_94);

                        if (iVar2 == 0) {

                          iVar2 = FUN_00772390();

                          if (iVar2 == 0) {

                            iVar2 = FUN_00771a00(local_94,local_94);

                            if (iVar2 == 0) {

                              iVar2 = FUN_00772390();

                              if (iVar2 == 0) {

                                iVar2 = FUN_00774b50(local_94,local_64);

                                if (iVar2 == 0) {

                                  iVar2 = FUN_00772390();

                                  if (iVar2 == 0) {

                                    iVar2 = FUN_00772390();

                                    if (iVar2 == 0) {

                                      iVar2 = FUN_00774b50(local_94,local_84);

                                      if (iVar2 == 0) {

                                        iVar2 = FUN_007716f0(local_74);

                                        if (iVar2 == 0) {

                                          iVar2 = FUN_007716f0(local_64);

                                          if (iVar2 == 0) {

                                            iVar2 = FUN_00772190(local_74);

                                            if (iVar2 == 0) {

                                              iVar2 = FUN_00772190(local_64);

                                              if (iVar2 == 0) {

                                                iVar2 = FUN_007716f0(local_84);

                                                if (iVar2 == 0) {

                                                  iVar2 = FUN_007716f0(local_84);

                                                  if (iVar2 == 0) {

                                                    iVar2 = FUN_007716f0(local_74);

                                                    if (iVar2 == 0) {

                                                      iVar2 = FUN_007716f0(local_64);

                                                      if (iVar2 == 0) {

                                                        iVar2 = FUN_00772b90(3);

                                                        if (iVar2 == 0) {

                                                          iVar2 = FUN_007716f0(local_74);

                                                          if (iVar2 == 0) {

                                                            iVar2 = FUN_00772b90(3);

                                                            if (iVar2 == 0) {

                                                              iVar2 = FUN_007716f0(local_64);

                                                              if (iVar2 == 0) {

                                                                iVar2 = FUN_00771920(local_84,3,

                                                                                     local_84);

                                                                if (iVar2 == 0) {

                                                                  iVar2 = FUN_007716f0(local_84);

                                                                  if (iVar2 == 0) {

                                                                    iVar2 = FUN_007716f0(local_84);

                                                                    if (iVar2 == 0) {

                                                                      iVar2 = FUN_007716f0(local_74)

                                                                      ;

                                                                      if (iVar2 == 0) {

                                                                        iVar2 = FUN_007716f0(

                                                  local_64);

                                                  if (iVar2 == 0) {

                                                    iVar2 = FUN_00771f00(local_74,local_74,0);

                                                    if (iVar2 == 0) {

                                                      iVar2 = FUN_00771f00(local_64,local_64,0);

                                                      if (iVar2 == 0) {

                                                        iVar2 = FUN_00771c00();

                                                        if (iVar2 == 0) {

                                                          iVar2 = FUN_00771c00();

                                                          if (iVar2 == 0) {

                                                            iVar2 = FUN_00771c00();

                                                            if (iVar2 == 0) {

                                                              iVar2 = FUN_00771c00();

                                                              if (iVar2 == 0) {

                                                                iVar2 = FUN_00772390();

                                                                if (iVar2 == 0) {

                                                                  iVar2 = FUN_00772390();

                                                                  if (iVar2 == 0) {

                                                                    iVar2 = FUN_00772390();

                                                                    if (iVar2 == 0) {

                                                                      iVar2 = FUN_00772390();

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

    FUN_00772250(local_10,local_74,local_84,local_64,local_34,local_20,local_54,local_44,local_94,0)

    ;

  }

  return iVar2;

}
