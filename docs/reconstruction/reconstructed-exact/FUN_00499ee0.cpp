// =============================================================================
// FUN_00499ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00499ee0
// Address:   0x00499ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00499ee0 @ 0x00499ee0
// Stable ID: aa_00499ee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×15, return×1.
//  - Notable callees: _fpclass×15, FUN_00499ee0, FUN_0049ca80.
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

void __thiscall FUN_00499ee0(float param_1,float *param_2)



{

  uint uVar1;

  

  uVar1 = _fpclass((double)*param_2);

  if ((uVar1 & 0x207) == 0) {

    uVar1 = _fpclass((double)param_2[1]);

    if ((uVar1 & 0x207) == 0) {

      uVar1 = _fpclass((double)param_2[2]);

      if ((uVar1 & 0x207) == 0) {

        uVar1 = _fpclass((double)param_2[3]);

        if ((uVar1 & 0x207) == 0) {

          uVar1 = _fpclass((double)param_2[4]);

          if ((uVar1 & 0x207) == 0) {

            uVar1 = _fpclass((double)param_2[5]);

            if ((uVar1 & 0x207) == 0) {

              uVar1 = _fpclass((double)param_2[6]);

              if ((uVar1 & 0x207) == 0) {

                uVar1 = _fpclass((double)param_2[7]);

                if ((uVar1 & 0x207) == 0) {

                  uVar1 = _fpclass((double)param_2[8]);

                  if ((uVar1 & 0x207) == 0) {

                    uVar1 = _fpclass((double)param_2[9]);

                    if ((uVar1 & 0x207) == 0) {

                      uVar1 = _fpclass((double)param_2[10]);

                      if ((uVar1 & 0x207) == 0) {

                        uVar1 = _fpclass((double)param_2[0xb]);

                        if (((((uVar1 & 0x207) == 0) &&

                             (0.0 < param_2[0x10] || param_2[0x10] == 0.0)) &&

                            (0.0 < param_2[0x11] || param_2[0x11] == 0.0)) &&

                           (((0.0 < param_2[0x12] || param_2[0x12] == 0.0 &&

                             (0.0 < param_2[0x13] || param_2[0x13] == 0.0)) &&

                            (0.0 < param_2[0x14] || param_2[0x14] == 0.0)))) {

                          uVar1 = _fpclass((double)param_2[0x12]);

                          if ((uVar1 & 0x207) == 0) {

                            uVar1 = _fpclass((double)param_2[0x13]);

                            if ((uVar1 & 0x207) == 0) {

                              uVar1 = _fpclass((double)param_2[0x14]);

                              if ((((uVar1 & 0x207) == 0) &&

                                  (0.0 < param_2[0x15] || param_2[0x15] == 0.0)) &&

                                 (((((uint)param_2[0xf] & 3) != 0 &&

                                   (((((uint)param_2[0xd] & 3) != 0 &&

                                     (0.0 < param_2[0x17] || param_2[0x17] == 0.0)) &&

                                    (0.0 < param_2[0x16] || param_2[0x16] == 0.0)))) &&

                                  (0.0 < param_2[0x18] || param_2[0x18] == 0.0)))) {

                                param_2[0x1d] = param_1;

                                FUN_0049ca80();

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

  return;

}
