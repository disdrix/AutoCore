// =============================================================================
// Named_convoy
// -----------------------------------------------------------------------------
// Stable ID: aa_00865d00
// Address:   0x00865d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_convoy @ 0x00865d00
// Stable ID: aa_00865d00
// Embedded strings (evidence for future rename):
//   - "/convoy "
//   - "/group "
//   - "/cl "
//   - "/clan "
//   - "/gu "
//   - "/guild "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~157 non-empty decompiler lines.
//  - Control keywords: if×23, return×9, goto×4, do×2, while×2.
//  - Notable callees: _stricmp×30, _strnicmp×5, FUN_007944a0, Named_convoy.
//  - Strings: "/c "; "/convoy "; "/g "; "/group ".
//  - Return sites: 9.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "/convoy "
 * Domain alias of FUN_00865d00 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_convoy(void)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  char *pcVar4;

  int iVar5;

  int iVar6;

  int *unaff_ESI;

  int iVar7;

  uint32_t /* width from decompiler */ uStack_7d8;

  uint8_t local_7d0 [988];

  uint8_t auStack_3f4 [4];

  char acStack_3f0 [1008];

  

  iVar3 = unaff_ESI[0x68ae];

  if ((iVar3 != 0) && (*(char *)(iVar3 + 0x494) == ' ')) {

    uStack_7d8 = 0x865d29;

    uVar2 = FUN_007944a0();

    if (uVar2 <= *(uint *)(iVar3 + 0x490)) {

      uStack_7d8 = 1000;

      (**(code **)(*(int *)unaff_ESI[0x68ae] + 0x270))(local_7d0);

      if ((char)uStack_7d8 == '/') {

        iVar3 = _stricmp((char *)&uStack_7d8,"/c ");

        if ((((iVar3 == 0) || (iVar3 = _stricmp((char *)&uStack_7d8,"/convoy "), iVar3 == 0)) ||

            (iVar3 = _stricmp((char *)&uStack_7d8,"/g "), iVar3 == 0)) ||

           (iVar3 = _stricmp((char *)&uStack_7d8,"/group "), iVar3 == 0)) {

          unaff_ESI[0x144] = 3;

        }

        else {

          iVar3 = _stricmp((char *)&uStack_7d8,"/cl ");

          if (((iVar3 == 0) || (iVar3 = _stricmp((char *)&uStack_7d8,"/clan "), iVar3 == 0)) ||

             ((iVar3 = _stricmp((char *)&uStack_7d8,"/gu "), iVar3 == 0 ||

              (iVar3 = _stricmp((char *)&uStack_7d8,"/guild "), iVar3 == 0)))) {

            unaff_ESI[0x144] = 4;

          }

          else {

            iVar3 = _stricmp((char *)&uStack_7d8,"/s ");

            if (((iVar3 == 0) || (iVar3 = _stricmp((char *)&uStack_7d8,"/say "), iVar3 == 0)) ||

               (iVar3 = _stricmp((char *)&uStack_7d8,"/local "), iVar3 == 0)) {

              unaff_ESI[0x144] = 10;

            }

            else {

              iVar3 = _stricmp((char *)&uStack_7d8,"/sh ");

              if ((((iVar3 == 0) || (iVar3 = _stricmp((char *)&uStack_7d8,"/shout "), iVar3 == 0))

                  || (iVar3 = _stricmp((char *)&uStack_7d8,"/b "), iVar3 == 0)) ||

                 ((iVar3 = _stricmp((char *)&uStack_7d8,"/broadcast "), iVar3 == 0 ||

                  (iVar3 = _stricmp((char *)&uStack_7d8,"/1 "), iVar3 == 0)))) {

                unaff_ESI[0x144] = 5;

              }

              else {

                iVar3 = _stricmp((char *)&uStack_7d8,"/lfc ");

                if ((iVar3 == 0) || (iVar3 = _stricmp((char *)&uStack_7d8,"/5 "), iVar3 == 0)) {

                  unaff_ESI[0x144] = 8;

                }

                else {

                  iVar3 = _stricmp((char *)&uStack_7d8,"/tr ");

                  if (((iVar3 == 0) || (iVar3 = _stricmp((char *)&uStack_7d8,"/trade "), iVar3 == 0)

                      ) || (iVar3 = _stricmp((char *)&uStack_7d8,"/4 "), iVar3 == 0)) {

                    unaff_ESI[0x144] = 9;

                  }

                  else {

                    iVar3 = _stricmp((char *)&uStack_7d8,"/fr ");

                    if (((iVar3 == 0) ||

                        (iVar3 = _stricmp((char *)&uStack_7d8,"/french "), iVar3 == 0)) ||

                       (iVar3 = _stricmp((char *)&uStack_7d8,"/2 "), iVar3 == 0)) {

                      unaff_ESI[0x144] = 0xe;

                    }

                    else {

                      iVar3 = _stricmp((char *)&uStack_7d8,"/de ");

                      if (((iVar3 == 0) ||

                          (iVar3 = _stricmp((char *)&uStack_7d8,"/german "), iVar3 == 0)) ||

                         (iVar3 = _stricmp((char *)&uStack_7d8,"/3 "), iVar3 == 0)) {

                        unaff_ESI[0x144] = 0xf;

                      }

                      else {

                        iVar3 = _stricmp((char *)&uStack_7d8,"/fac ");

                        if (((iVar3 != 0) &&

                            (iVar3 = _stricmp((char *)&uStack_7d8,"/faction "), iVar3 != 0)) &&

                           (iVar3 = _stricmp((char *)&uStack_7d8,"/6 "), iVar3 != 0)) {

                          iVar3 = _strnicmp((char *)&uStack_7d8,"/t ",3);

                          if (((iVar3 != 0) &&

                              (iVar3 = _strnicmp((char *)&uStack_7d8,"/tell ",6), iVar3 != 0)) &&

                             ((iVar3 = _strnicmp((char *)&uStack_7d8,"/w ",3), iVar3 != 0 &&

                              (iVar3 = _strnicmp((char *)&uStack_7d8,"/whisper ",9), iVar3 != 0))))

                          {

                            if (DAT_00d1b6d8 == 0) {

                              return;

                            }

                            if (*(int *)(DAT_00d1b6d8 + 0x6b4) < 1) {

                              return;

                            }

                            iVar3 = _strnicmp((char *)&uStack_7d8,"/global ",8);

                            if (iVar3 != 0) {

                              return;

                            }

                            unaff_ESI[0x144] = 1;

                            (**(code **)(*unaff_ESI + 0x444))();

                            (**(code **)(*(int *)unaff_ESI[0x68ae] + 0x3ac))(&DAT_00a1419b);

                            return;

                          }

                          pcVar4 = (char *)&uStack_7d8;

                          iVar3 = 0;

                          do {

                            cVar1 = *pcVar4;

                            pcVar4 = pcVar4 + 1;

                          } while (cVar1 != '\0');

                          iVar5 = (int)pcVar4 - ((int)&uStack_7d8 + 1);

                          iVar7 = 0;

                          if (0 < iVar5) {

                            do {

                              if (*(char *)((int)&uStack_7d8 + iVar7) == ' ')

                              goto joined_r0x008660f9;

                              iVar7 = iVar7 + 1;

                            } while (iVar7 < iVar5);

                          }

LAB_0086612f:

                          acStack_3f0[iVar3] = '\0';

                          if (iVar3 < 1) {

                            return;

                          }

                          unaff_ESI[0x144] = 2;

                          (**(code **)(*unaff_ESI + 0x444))();

                          (**(code **)(*(int *)unaff_ESI[0x68ae] + 0x3ac))(&DAT_00a1419b);

                          if ((int *)unaff_ESI[0x68ad] == (int *)0x0) {

                            return;

                          }

                          (**(code **)(*(int *)unaff_ESI[0x68ad] + 0x3ac))(auStack_3f4);

                          return;

                        }

                        unaff_ESI[0x144] = 0xd;

                      }

                    }

                  }

                }

              }

            }

          }

        }

        (**(code **)(*unaff_ESI + 0x444))();

        (**(code **)(*(int *)unaff_ESI[0x68ae] + 0x3ac))(&DAT_00a1419b);

        return;

      }

    }

  }

  return;

joined_r0x008660f9:

  if (iVar5 <= iVar7) goto LAB_0086612f;

  if (*(char *)((int)&uStack_7d8 + iVar7) != ' ') {

    acStack_3f0[iVar3] = *(char *)((int)&uStack_7d8 + iVar7);

    iVar3 = iVar3 + 1;

  }

  if (((int *)unaff_ESI[0x68ad] != (int *)0x0) &&

     (iVar6 = (**(code **)(*(int *)unaff_ESI[0x68ad] + 0x1d4))(), iVar6 <= iVar3))

  goto LAB_0086612f;

  iVar7 = iVar7 + 1;

  goto joined_r0x008660f9;

}
