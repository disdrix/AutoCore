// READABILITY (auto CF):
//  - Body size: ~108 non-empty decompiler lines.
//  - Control keywords: if×21, return×11.
//  - Notable callees: FUN_007fdfb0×10, FUN_00879790.
//  - Strings: "You need a vehicle to participate!"; "Your faction must be eligible!"; "Your class must be eligible!"; "Minimum level cannot be greater than your current level!".
//  - Return sites: 11.

// =============================================================================
// Drive_Maximum_value_cannot_be_less_than_your_current_v
// -----------------------------------------------------------------------------
// Stable ID: aa_00879790
// Address:   0x00879790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Maximum value cannot be less than your current vehicle's value!"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Drive_Maximum_value_cannot_be_less_than_your_current_v(void)



{

  int in_EAX;

  int iVar1;

  char unaff_BL;

  uint64_t uVar2;

  

  if ((in_EAX != 0) && (DAT_00d1b6d8 != 0)) {

    if (*(int *)(DAT_00d1b6d8 + 0x250) == 0) {

      if (unaff_BL != '\0') {

        FUN_007fdfb0(&DAT_00d1a840,"You need a vehicle to participate!",0xffffffff,1,0);

        return 0;

      }

    }

    else {

      iVar1 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

              (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

      if ((*(int *)(in_EAX + 0xc) < iVar1) ||

         ((*(int *)(in_EAX + 0xc) <= iVar1 &&

          (*(uint *)(in_EAX + 8) <=

           *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))))) {

        iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) +

                        0x3c);

        if (*(char *)(*(byte *)(iVar1 + 0x532) + 0x20 + in_EAX) == '\0') {

          if (unaff_BL != '\0') {

            FUN_007fdfb0(&DAT_00d1a840,"Your faction must be eligible!",0xffffffff,1,0);

            return 0;

          }

        }

        else if (*(char *)(*(byte *)(iVar1 + 0x531) + 0x23 + in_EAX) == '\0') {

          if (unaff_BL != '\0') {

            FUN_007fdfb0(&DAT_00d1a840,"Your class must be eligible!",0xffffffff,1,0);

            return 0;

          }

        }

        else {

          iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8)

                              + 0x27c))();

          if (iVar1 < (int)(uint)*(byte *)(in_EAX + 0x27)) {

            if (unaff_BL != '\0') {

              FUN_007fdfb0(&DAT_00d1a840,"Minimum level cannot be greater than your current level!",

                           0xffffffff,1,0);

              return 0;

            }

          }

          else {

            iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 +

                                         DAT_00d1b6d8) + 0x27c))();

            if ((int)(uint)*(byte *)(in_EAX + 0x28) < iVar1) {

              if (unaff_BL != '\0') {

                FUN_007fdfb0(&DAT_00d1a840,"Maximum level cannot be less than your current level!",

                             0xffffffff,1,0);

                return 0;

              }

            }

            else {

              iVar1 = *(int *)(DAT_00d1b6d8 + 0x6d0 + *(int *)(in_EAX + 4) * 4);

              if (iVar1 < (int)(uint)*(ushort *)(in_EAX + 0x2a)) {

                if (unaff_BL != '\0') {

                  FUN_007fdfb0(&DAT_00d1a840,

                               "Minimum rank cannot be greater than your rank on an arena of this size!"

                               ,0xffffffff,1,0);

                  return 0;

                }

              }

              else if ((int)(uint)*(ushort *)(in_EAX + 0x2c) < iVar1) {

                if (unaff_BL != '\0') {

                  FUN_007fdfb0(&DAT_00d1a840,

                               "Maximum rank cannot be less than your rank on an arena of this size!"

                               ,0xffffffff,1,0);

                  return 0;

                }

              }

              else {

                uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 4)

                                                      + 4) + 4 + *(int *)(DAT_00d1b6d8 + 0x250)) +

                                    0x16c))();

                iVar1 = (int)((ulonglong)uVar2 >> 0x20);

                if ((iVar1 < *(int *)(in_EAX + 0x3c)) ||

                   ((iVar1 <= *(int *)(in_EAX + 0x3c) && ((uint)uVar2 <= *(uint *)(in_EAX + 0x38))))

                   ) {

                  if ((*(char **)(in_EAX + 0x14) != (char *)0x0) &&

                     (**(char **)(in_EAX + 0x14) != '\0')) {

                    return 1;

                  }

                  if (unaff_BL != '\0') {

                    FUN_007fdfb0(&DAT_00d1a840,"The match needs a name!",0xffffffff,1,0);

                  }

                }

                else if (unaff_BL != '\0') {

                  FUN_007fdfb0(&DAT_00d1a840,

                               "Maximum value cannot be less than your current vehicle\'s value!",

                               0xffffffff,1,0);

                  return 0;

                }

              }

            }

          }

        }

      }

      else if (unaff_BL != '\0') {

        FUN_007fdfb0(&DAT_00d1a840,"Entry fee cannot be greater than your total funds!",0xffffffff,1

                     ,0);

        return 0;

      }

    }

  }

  return 0;

}
