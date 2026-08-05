// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_00578f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00578f80
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_no_choices_fro
// Address:   0x00578f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_no_choices_fro: mission/objective helper. Evidence string: "$/emote". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "$emote"
//   - "$/emote"
//   - "$key"
//   - "$/key"
//   - "$imp"
//   - "$/imp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~198 non-empty decompiler lines.
//  - Control keywords: do×26, while×26, if×17, return×4.
//  - Notable callees: strchr×2, strncpy×2, FUN_00578f80.
//  - Strings: "$emote"; "$/emote"; "$key"; "$/key".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_no_choices_fro
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

char * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Dialog_has_00578f80(char *param_1,char *param_2,char *param_3)



{

  char *pcVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  bool bVar5;

  

  pcVar1 = param_1;

  do {

    do {

      do {

        do {

          do {

            do {

              do {

                do {

                  do {

                    do {

                      do {

                        do {

                          do {

                            pcVar1 = strchr(pcVar1,0x5b);

                            if (pcVar1 == (char *)0x0) {

                              return (char *)0x0;

                            }

                            strncpy(param_3,param_1,(int)pcVar1 - (int)param_1);

                            pcVar3 = pcVar1 + 1;

                            param_3[(int)pcVar1 - (int)param_1] = '\0';

                            pcVar1 = strchr(pcVar3,0x5d);

                            if (pcVar1 == (char *)0x0) {

                              return (char *)0x0;

                            }

                            strncpy(param_2,pcVar3,(int)pcVar1 - (int)pcVar3);

                            param_2[(int)pcVar1 - (int)pcVar3] = '\0';

                            pcVar1 = pcVar1 + 1;

                            if (*param_2 != '$') {

                              return pcVar1;

                            }

                            iVar2 = 7;

                            bVar5 = true;

                            pcVar3 = param_2;

                            pcVar4 = "$emote";

                            do {

                              if (iVar2 == 0) break;

                              iVar2 = iVar2 + -1;

                              bVar5 = *pcVar3 == *pcVar4;

                              pcVar3 = pcVar3 + 1;

                              pcVar4 = pcVar4 + 1;

                            } while (bVar5);

                          } while (bVar5);

                          iVar2 = 8;

                          bVar5 = true;

                          pcVar3 = param_2;

                          pcVar4 = "$/emote";

                          do {

                            if (iVar2 == 0) break;

                            iVar2 = iVar2 + -1;

                            bVar5 = *pcVar3 == *pcVar4;

                            pcVar3 = pcVar3 + 1;

                            pcVar4 = pcVar4 + 1;

                          } while (bVar5);

                        } while (bVar5);

                        iVar2 = 5;

                        bVar5 = true;

                        pcVar3 = param_2;

                        pcVar4 = "$key";

                        do {

                          if (iVar2 == 0) break;

                          iVar2 = iVar2 + -1;

                          bVar5 = *pcVar3 == *pcVar4;

                          pcVar3 = pcVar3 + 1;

                          pcVar4 = pcVar4 + 1;

                        } while (bVar5);

                      } while (bVar5);

                      iVar2 = 6;

                      bVar5 = true;

                      pcVar3 = param_2;

                      pcVar4 = "$/key";

                      do {

                        if (iVar2 == 0) break;

                        iVar2 = iVar2 + -1;

                        bVar5 = *pcVar3 == *pcVar4;

                        pcVar3 = pcVar3 + 1;

                        pcVar4 = pcVar4 + 1;

                      } while (bVar5);

                    } while (bVar5);

                    iVar2 = 5;

                    bVar5 = true;

                    pcVar3 = param_2;

                    pcVar4 = "$imp";

                    do {

                      if (iVar2 == 0) break;

                      iVar2 = iVar2 + -1;

                      bVar5 = *pcVar3 == *pcVar4;

                      pcVar3 = pcVar3 + 1;

                      pcVar4 = pcVar4 + 1;

                    } while (bVar5);

                  } while (bVar5);

                  iVar2 = 6;

                  bVar5 = true;

                  pcVar3 = param_2;

                  pcVar4 = "$/imp";

                  do {

                    if (iVar2 == 0) break;

                    iVar2 = iVar2 + -1;

                    bVar5 = *pcVar3 == *pcVar4;

                    pcVar3 = pcVar3 + 1;

                    pcVar4 = pcVar4 + 1;

                  } while (bVar5);

                } while (bVar5);

                iVar2 = 5;

                bVar5 = true;

                pcVar3 = param_2;

                pcVar4 = "$npc";

                do {

                  if (iVar2 == 0) break;

                  iVar2 = iVar2 + -1;

                  bVar5 = *pcVar3 == *pcVar4;

                  pcVar3 = pcVar3 + 1;

                  pcVar4 = pcVar4 + 1;

                } while (bVar5);

              } while (bVar5);

              iVar2 = 6;

              bVar5 = true;

              pcVar3 = param_2;

              pcVar4 = "$/npc";

              do {

                if (iVar2 == 0) break;

                iVar2 = iVar2 + -1;

                bVar5 = *pcVar3 == *pcVar4;

                pcVar3 = pcVar3 + 1;

                pcVar4 = pcVar4 + 1;

              } while (bVar5);

            } while (bVar5);

            iVar2 = 5;

            bVar5 = true;

            pcVar3 = param_2;

            pcVar4 = "$loc";

            do {

              if (iVar2 == 0) break;

              iVar2 = iVar2 + -1;

              bVar5 = *pcVar3 == *pcVar4;

              pcVar3 = pcVar3 + 1;

              pcVar4 = pcVar4 + 1;

            } while (bVar5);

          } while (bVar5);

          iVar2 = 6;

          bVar5 = true;

          pcVar3 = param_2;

          pcVar4 = "$/loc";

          do {

            if (iVar2 == 0) break;

            iVar2 = iVar2 + -1;

            bVar5 = *pcVar3 == *pcVar4;

            pcVar3 = pcVar3 + 1;

            pcVar4 = pcVar4 + 1;

          } while (bVar5);

        } while (bVar5);

        iVar2 = 6;

        bVar5 = true;

        pcVar3 = param_2;

        pcVar4 = "$inst";

        do {

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          bVar5 = *pcVar3 == *pcVar4;

          pcVar3 = pcVar3 + 1;

          pcVar4 = pcVar4 + 1;

        } while (bVar5);

      } while (bVar5);

      iVar2 = 7;

      bVar5 = true;

      pcVar3 = param_2;

      pcVar4 = "$/inst";

      do {

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        bVar5 = *pcVar3 == *pcVar4;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      } while (bVar5);

    } while (bVar5);

    iVar2 = 7;

    bVar5 = true;

    pcVar3 = param_2;

    pcVar4 = "$pause";

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar5 = *pcVar3 == *pcVar4;

      pcVar3 = pcVar3 + 1;

      pcVar4 = pcVar4 + 1;

    } while (bVar5);

    if (!bVar5) {

      return pcVar1;

    }

  } while( true );

}
