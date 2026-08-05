// =============================================================================
// FUN_00774210
// -----------------------------------------------------------------------------
// Stable ID: aa_00774210
// Address:   0x00774210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00774210 @ 0x00774210
// Stable ID: aa_00774210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~217 non-empty decompiler lines.
//  - Control keywords: if×59, return×1.
//  - Notable callees: FUN_00772390×16, FUN_007716f0×12, FUN_00771a00×8, FUN_00774e60×5, FUN_00770280×4, FUN_00770650×4, FUN_00771b60×4, FUN_00771c00×4.
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

int FUN_00774210(int *param_1)



{

  int iVar1;

  int *in_EAX;

  int iVar2;

  uint8_t local_d4 [16];

  uint8_t local_c4 [16];

  int local_b4;

  uint8_t local_b0 [16];

  uint8_t local_a0 [16];

  uint8_t local_90 [16];

  uint8_t local_80 [16];

  uint8_t local_70 [16];

  uint8_t local_60 [16];

  uint8_t local_50 [16];

  uint8_t local_40 [16];

  uint8_t local_30 [16];

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  iVar2 = FUN_00771cb0(local_10,local_90,local_b0,local_a0,local_60,local_20,local_70,local_50,

                       local_30,local_80,local_40,local_d4,local_c4,0);

  if (iVar2 == 0) {

    local_b4 = *param_1;

    if (*in_EAX < *param_1) {

      local_b4 = *in_EAX;

    }

    local_b4 = local_b4 / 3;

    iVar1 = local_b4 * 0x1c;

    iVar2 = FUN_00771b60(iVar1);

    if (iVar2 == 0) {

      iVar2 = FUN_00770650();

      if (iVar2 == 0) {

        FUN_00770280();

        FUN_00771b60(iVar1);

        iVar2 = FUN_00770650();

        if (iVar2 == 0) {

          FUN_00770280();

          iVar2 = FUN_00771b60(iVar1);

          if (iVar2 == 0) {

            iVar2 = FUN_00770650();

            if (iVar2 == 0) {

              FUN_00770280();

              FUN_00771b60(iVar1);

              iVar2 = FUN_00770650();

              if (iVar2 == 0) {

                FUN_00770280();

                iVar2 = FUN_00774e60(local_20,local_30,local_10);

                if (iVar2 == 0) {

                  iVar2 = FUN_00774e60(local_50,local_40,local_60);

                  if (iVar2 == 0) {

                    iVar2 = FUN_00771a00(local_20,local_d4);

                    if (iVar2 == 0) {

                      iVar2 = FUN_00772390();

                      if (iVar2 == 0) {

                        iVar2 = FUN_00771a00(local_d4,local_d4);

                        if (iVar2 == 0) {

                          iVar2 = FUN_00772390();

                          if (iVar2 == 0) {

                            iVar2 = FUN_00771a00(local_30,local_c4);

                            if (iVar2 == 0) {

                              iVar2 = FUN_00772390();

                              if (iVar2 == 0) {

                                iVar2 = FUN_00771a00(local_c4,local_c4);

                                if (iVar2 == 0) {

                                  iVar2 = FUN_00772390();

                                  if (iVar2 == 0) {

                                    iVar2 = FUN_00774e60(local_d4,local_c4,local_90);

                                    if (iVar2 == 0) {

                                      iVar2 = FUN_00771a00(local_50,local_d4);

                                      if (iVar2 == 0) {

                                        iVar2 = FUN_00772390();

                                        if (iVar2 == 0) {

                                          iVar2 = FUN_00771a00(local_d4,local_d4);

                                          if (iVar2 == 0) {

                                            iVar2 = FUN_00772390();

                                            if (iVar2 == 0) {

                                              iVar2 = FUN_00771a00(local_40,local_c4);

                                              if (iVar2 == 0) {

                                                iVar2 = FUN_00772390();

                                                if (iVar2 == 0) {

                                                  iVar2 = FUN_00771a00(local_c4,local_c4);

                                                  if (iVar2 == 0) {

                                                    iVar2 = FUN_00772390();

                                                    if (iVar2 == 0) {

                                                      iVar2 = FUN_00774e60(local_d4,local_c4,

                                                                           local_a0);

                                                      if (iVar2 == 0) {

                                                        iVar2 = FUN_00772390();

                                                        if (iVar2 == 0) {

                                                          iVar2 = FUN_00772390();

                                                          if (iVar2 == 0) {

                                                            iVar2 = FUN_00772390();

                                                            if (iVar2 == 0) {

                                                              iVar2 = FUN_00772390();

                                                              if (iVar2 == 0) {

                                                                iVar2 = FUN_00774e60(local_d4,

                                                  local_c4,local_b0);

                                                  if (iVar2 == 0) {

                                                    iVar2 = FUN_007716f0(local_90);

                                                    if (iVar2 == 0) {

                                                      iVar2 = FUN_007716f0(local_a0);

                                                      if (iVar2 == 0) {

                                                        iVar2 = FUN_00772190(local_90);

                                                        if (iVar2 == 0) {

                                                          iVar2 = FUN_00772190(local_a0);

                                                          if (iVar2 == 0) {

                                                            iVar2 = FUN_007716f0(local_b0);

                                                            if (iVar2 == 0) {

                                                              iVar2 = FUN_007716f0(local_b0);

                                                              if (iVar2 == 0) {

                                                                iVar2 = FUN_007716f0(local_90);

                                                                if (iVar2 == 0) {

                                                                  iVar2 = FUN_007716f0(local_a0);

                                                                  if (iVar2 == 0) {

                                                                    iVar2 = FUN_00772b90(3);

                                                                    if (iVar2 == 0) {

                                                                      iVar2 = FUN_007716f0(local_90)

                                                                      ;

                                                                      if (iVar2 == 0) {

                                                                        iVar2 = FUN_00772b90(3);

                                                                        if (iVar2 == 0) {

                                                                          iVar2 = FUN_007716f0(

                                                  local_a0);

                                                  if (iVar2 == 0) {

                                                    iVar2 = FUN_00771920(local_b0,3,local_b0);

                                                    if (iVar2 == 0) {

                                                      iVar2 = FUN_007716f0(local_b0);

                                                      if (iVar2 == 0) {

                                                        iVar2 = FUN_007716f0(local_b0);

                                                        if (iVar2 == 0) {

                                                          iVar2 = FUN_007716f0(local_90);

                                                          if (iVar2 == 0) {

                                                            iVar2 = FUN_007716f0(local_a0);

                                                            if (iVar2 == 0) {

                                                              iVar2 = FUN_00771f00(local_90,local_90

                                                                                   ,0);

                                                              if (iVar2 == 0) {

                                                                iVar2 = FUN_00771f00(local_a0,

                                                  local_a0,0);

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

    FUN_00772250(local_10,local_90,local_b0,local_a0,local_60,local_20,local_70,local_50,local_30,

                 local_80,local_40,local_d4,local_c4,0);

  }

  return iVar2;

}
