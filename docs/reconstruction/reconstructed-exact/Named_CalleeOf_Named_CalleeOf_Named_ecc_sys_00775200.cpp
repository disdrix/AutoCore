// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00775200
// -----------------------------------------------------------------------------
// Stable ID: aa_00775200
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00775200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×15, goto×11, while×4, return×2, do×1.
//  - Notable callees: FUN_007716f0×8, FUN_00772190×6, FUN_00770650×3, FUN_00770770×3, FUN_00772390×3, FUN_00770250×2, FUN_00770710×2, FUN_00770540.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00775200(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  bool bVar3;

  int local_80 [3];

  byte *local_74;

  int local_70 [3];

  byte *local_64;

  int local_60 [3];

  byte *local_54;

  int local_50 [3];

  byte *local_44;

  int local_40 [3];

  byte *local_34;

  int local_30 [3];

  byte *local_24;

  int local_20 [3];

  byte *local_14;

  int local_10 [3];

  byte *local_4;

  

  if ((param_2[2] == 1) || (*param_2 == 0)) {

    iVar1 = -3;

  }

  else {

    iVar1 = FUN_00771cb0(local_10,local_20,local_40,local_50,local_60,local_30,local_80,local_70,0);

    if (iVar1 == 0) {

      iVar1 = FUN_00774f50(param_1,local_10);

      if ((iVar1 == 0) && (iVar1 = FUN_00770650(), iVar1 == 0)) {

        if ((local_10[0] < 1) ||

           ((((*local_4 & 1) != 0 || (local_20[0] < 1)) || ((*local_14 & 1) != 0)))) {

          iVar1 = FUN_00770650();

          if ((iVar1 == 0) && (iVar1 = FUN_00770650(), iVar1 == 0)) {

            FUN_00770250();

            FUN_00770250();

            do {

              bVar3 = local_40[0] == 0;

              while ((bVar3 || local_40[0] < 0 || ((*local_34 & 1) != 0))) {

                while ((0 < local_50[0] && ((*local_44 & 1) == 0))) {

                  iVar1 = FUN_00772190(local_50);

                  if (((iVar1 != 0) ||

                      ((((0 < local_80[0] && ((*local_74 & 1) != 0)) ||

                        ((0 < local_70[0] && ((*local_64 & 1) != 0)))) &&

                       ((iVar1 = FUN_00772390(), iVar1 != 0 ||

                        (iVar1 = FUN_007716f0(local_70), iVar1 != 0)))))) ||

                     ((iVar1 = FUN_00772190(local_80), iVar1 != 0 ||

                      (iVar1 = FUN_00772190(local_70), iVar1 != 0)))) goto LAB_007755dc;

                }

                iVar1 = FUN_007707a0();

                if (iVar1 == -1) {

                  iVar1 = FUN_007716f0(local_50);

                  if ((iVar1 != 0) || (iVar1 = FUN_007716f0(local_80), iVar1 != 0))

                  goto LAB_007755dc;

                  piVar2 = local_70;

                }

                else {

                  iVar1 = FUN_007716f0(local_40);

                  if ((iVar1 != 0) || (iVar1 = FUN_007716f0(local_60), iVar1 != 0))

                  goto LAB_007755dc;

                  piVar2 = local_30;

                }

                iVar1 = FUN_007716f0(piVar2);

                if (iVar1 != 0) goto LAB_007755dc;

                bVar3 = false;

                if (local_40[0] == 0) {

                  iVar1 = FUN_00770770();

                  if (iVar1 != 0) {

                    iVar1 = -3;

                    goto LAB_007755dc;

                  }

                  iVar1 = FUN_00770770();

                  goto joined_r0x0077556a;

                }

              }

              iVar1 = FUN_00772190(local_40);

            } while ((iVar1 == 0) &&

                    (((((local_60[0] < 1 || ((*local_54 & 1) == 0)) &&

                       ((local_30[0] < 1 || ((*local_24 & 1) == 0)))) ||

                      ((iVar1 = FUN_00772390(), iVar1 == 0 &&

                       (iVar1 = FUN_007716f0(local_30), iVar1 == 0)))) &&

                     ((iVar1 = FUN_00772190(local_60), iVar1 == 0 &&

                      (iVar1 = FUN_00772190(local_30), iVar1 == 0))))));

          }

        }

        else {

          iVar1 = -3;

        }

      }

      goto LAB_007755dc;

    }

  }

  return iVar1;

joined_r0x0077556a:

  if (iVar1 != -1) goto LAB_00775591;

  iVar1 = FUN_00772390();

  if (iVar1 != 0) goto LAB_007755dc;

  iVar1 = FUN_00770770();

  goto joined_r0x0077556a;

LAB_00775591:

  iVar1 = FUN_00770710();

  while (iVar1 != -1) {

    iVar1 = FUN_007716f0(local_80);

    if (iVar1 != 0) goto LAB_007755dc;

    iVar1 = FUN_00770710();

  }

  FUN_00770540();

  iVar1 = 0;

LAB_007755dc:

  FUN_00772250(local_10,local_20,local_40,local_50,local_60,local_30,local_80,local_70,0);

  return iVar1;

}
