// =============================================================================
// FUN_005c5b00
// -----------------------------------------------------------------------------
// Stable ID: aa_005c5b00
// Address:   0x005c5b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c5b00 @ 0x005c5b00
// Stable ID: aa_005c5b00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×16, return×3.
//  - Notable callees: _fpclass×12, ABS×2, NAN×2, CONCAT21, CONCAT31, FUN_005c5b00.
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

uint __fastcall FUN_005c5b00(int param_1)



{

  float fVar1;

  ushort uVar2;

  uint3 uVar3;

  uint in_EAX;

  int iVar4;

  uint uVar5;

  

  if ((((*(int *)(param_1 + 0x68) != 0) && (DAT_009d9e64 < *(float *)(param_1 + 0x6c))) &&

      (DAT_009d9e64 < ABS(*(float *)(param_1 + 0x70)))) &&

     (DAT_009d9e64 < ABS(*(float *)(param_1 + 0x74)))) {

    iVar4 = (**(code **)(**(int **)(param_1 + 0x68) + 0x14))();

    in_EAX = iVar4 - 1;

    if ((in_EAX == 0) && ((*(byte *)(param_1 + 0x78) & 0x7f) == 0)) {

      uVar2 = *(ushort *)(param_1 + 0x7a);

      in_EAX = (uint)uVar2;

      if (((uVar2 & 0x7f) == uVar2) && ((*(uint *)(param_1 + 0x7c) & 0xfffffffe) == 0)) {

        uVar5 = _fpclass((double)*(float *)(param_1 + 8));

        if ((uVar5 & 0x207) == 0) {

          uVar5 = _fpclass((double)*(float *)(param_1 + 0xc));

          if ((uVar5 & 0x207) == 0) {

            uVar5 = _fpclass((double)*(float *)(param_1 + 0x10));

            if ((uVar5 & 0x207) == 0) {

              uVar5 = _fpclass((double)*(float *)(param_1 + 0x14));

              if ((uVar5 & 0x207) == 0) {

                uVar5 = _fpclass((double)*(float *)(param_1 + 0x18));

                if ((uVar5 & 0x207) == 0) {

                  uVar5 = _fpclass((double)*(float *)(param_1 + 0x1c));

                  if ((uVar5 & 0x207) == 0) {

                    uVar5 = _fpclass((double)*(float *)(param_1 + 0x20));

                    if ((uVar5 & 0x207) == 0) {

                      uVar5 = _fpclass((double)*(float *)(param_1 + 0x24));

                      if ((uVar5 & 0x207) == 0) {

                        uVar5 = _fpclass((double)*(float *)(param_1 + 0x28));

                        if ((uVar5 & 0x207) == 0) {

                          uVar5 = _fpclass((double)*(float *)(param_1 + 0x2c));

                          if ((uVar5 & 0x207) == 0) {

                            uVar5 = _fpclass((double)*(float *)(param_1 + 0x30));

                            if ((uVar5 & 0x207) == 0) {

                              uVar5 = _fpclass((double)*(float *)(param_1 + 0x34));

                              if ((((uVar5 & 0x207) == 0) && (*(ushort *)(param_1 + 0x3c) < 0x20))

                                 && (((*(uint *)(param_1 + 0x38) & 0xffff0000) == 0 &&

                                     ((*(int *)(param_1 + 4) < 10 &&

                                      (*(short *)(param_1 + 0x3e) != -1)))))) {

                                fVar1 = *(float *)(param_1 + 0x4c);

                                uVar3 = CONCAT21((short)(uVar5 >> 0x10),

                                                 (fVar1 == DAT_00aaa668) << 6 |

                                                 (NAN(fVar1) || NAN(DAT_00aaa668)) << 2 | 2U |

                                                 fVar1 < DAT_00aaa668);

                                uVar5 = (uint)uVar3 << 8;

                                if ((fVar1 == DAT_00aaa668) ||

                                   (0.0 < *(float *)(param_1 + 0x4c) ||

                                    *(float *)(param_1 + 0x4c) == 0.0)) {

                                  return CONCAT31(uVar3,1);

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

        return uVar5 & 0xffffff00;

      }

    }

  }

  return in_EAX & 0xffffff00;

}
