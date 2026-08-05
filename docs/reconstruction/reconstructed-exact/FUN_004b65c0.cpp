// =============================================================================
// FUN_004b65c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b65c0
// Address:   0x004b65c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b65c0 @ 0x004b65c0
// Stable ID: aa_004b65c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×14, return×3.
//  - Notable callees: _fpclass×12, NAN×2, CONCAT21, CONCAT31, FUN_004b65c0.
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

uint __fastcall FUN_004b65c0(int param_1)



{

  float fVar1;

  uint3 uVar2;

  uint in_EAX;

  uint uVar3;

  

  if (*(int *)(param_1 + 0x68) == 0) {

    return in_EAX & 0xffffff00;

  }

  uVar3 = _fpclass((double)*(float *)(param_1 + 8));

  if ((uVar3 & 0x207) == 0) {

    uVar3 = _fpclass((double)*(float *)(param_1 + 0xc));

    if ((uVar3 & 0x207) == 0) {

      uVar3 = _fpclass((double)*(float *)(param_1 + 0x10));

      if ((uVar3 & 0x207) == 0) {

        uVar3 = _fpclass((double)*(float *)(param_1 + 0x14));

        if ((uVar3 & 0x207) == 0) {

          uVar3 = _fpclass((double)*(float *)(param_1 + 0x18));

          if ((uVar3 & 0x207) == 0) {

            uVar3 = _fpclass((double)*(float *)(param_1 + 0x1c));

            if ((uVar3 & 0x207) == 0) {

              uVar3 = _fpclass((double)*(float *)(param_1 + 0x20));

              if ((uVar3 & 0x207) == 0) {

                uVar3 = _fpclass((double)*(float *)(param_1 + 0x24));

                if ((uVar3 & 0x207) == 0) {

                  uVar3 = _fpclass((double)*(float *)(param_1 + 0x28));

                  if ((uVar3 & 0x207) == 0) {

                    uVar3 = _fpclass((double)*(float *)(param_1 + 0x2c));

                    if ((uVar3 & 0x207) == 0) {

                      uVar3 = _fpclass((double)*(float *)(param_1 + 0x30));

                      if ((uVar3 & 0x207) == 0) {

                        uVar3 = _fpclass((double)*(float *)(param_1 + 0x34));

                        if (((((uVar3 & 0x207) == 0) && (*(ushort *)(param_1 + 0x3c) < 0x20)) &&

                            ((*(uint *)(param_1 + 0x38) & 0xffff0000) == 0)) &&

                           ((*(int *)(param_1 + 4) < 10 && (*(short *)(param_1 + 0x3e) != -1)))) {

                          fVar1 = *(float *)(param_1 + 0x4c);

                          uVar2 = CONCAT21((short)(uVar3 >> 0x10),

                                           (fVar1 == DAT_00aaa668) << 6 |

                                           (NAN(fVar1) || NAN(DAT_00aaa668)) << 2 | 2U |

                                           fVar1 < DAT_00aaa668);

                          uVar3 = (uint)uVar2 << 8;

                          if ((fVar1 == DAT_00aaa668) ||

                             (0.0 < *(float *)(param_1 + 0x4c) || *(float *)(param_1 + 0x4c) == 0.0)

                             ) {

                            return CONCAT31(uVar2,1);

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

  return uVar3 & 0xffffff00;

}
