// =============================================================================
// FUN_006c0fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0fb0
// Address:   0x006c0fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c0fb0 @ 0x006c0fb0
// Stable ID: aa_006c0fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×7, return×6, for×4, while×3, do×1, goto×1.
//  - Notable callees: FUN_005e03a0×4, FUN_006c0d20, FUN_006c0fb0, FUN_00718340.
//  - Return sites: 6.

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

int FUN_006c0fb0(void)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  undefined *puVar4;

  char *pcVar5;

  uint uVar6;

  char *pcVar7;

  int iVar8;

  

  if (DAT_009cbf60 != 0) {

    iVar3 = FUN_006c0d20(PTR_s_NetDevilVOG_00af0c50);

    if (DAT_009cbf60 != iVar3) {

      iVar3 = FUN_005e03a0(

                          "Havok client keycode is invalid.\nPlease check that you have entered it correctly in keycode.cpp\nIf this problem persists please contact Havok.com for assistance.\nNo simulation possible."

                          );

      return iVar3;

    }

    DAT_00d09210 = 1;

    return iVar3;

  }

  iVar3 = FUN_00718340();

  cVar2 = *PTR_s_NetDevilVOG_00af0c50;

  puVar4 = PTR_s_NetDevilVOG_00af0c50;

  while (cVar2 != '-') {

    if (cVar2 == '\0') {

      iVar3 = FUN_005e03a0(

                          "Havok evaluation key has expired or is invalid.\nPlease contact Havok.com for an extension.\nNo simulation possible."

                          );

      return iVar3;

    }

    pcVar7 = puVar4 + 1;

    puVar4 = puVar4 + 1;

    cVar2 = *pcVar7;

  }

  pcVar7 = puVar4 + 1;

  cVar2 = puVar4[1];

  pcVar5 = pcVar7;

  while (cVar2 != '-') {

    if (cVar2 == '\0') {

      iVar3 = FUN_005e03a0(

                          "Havok evaluation key has expired or is invalid.\nPlease contact Havok.com for an extension.\nNo simulation possible."

                          );

      return iVar3;

    }

    pcVar1 = pcVar5 + 1;

    pcVar5 = pcVar5 + 1;

    cVar2 = *pcVar1;

  }

  if (pcVar7 != pcVar5) {

    iVar8 = (int)&DAT_00a0d19c - (int)pcVar7;

    do {

      if (((*pcVar7 == '\0') || (pcVar7[iVar8] == '\0')) || (*pcVar7 != pcVar7[iVar8]))

      goto LAB_006c110c;

      pcVar7 = pcVar7 + 1;

    } while (pcVar7 != pcVar5);

  }

  uVar6 = ((pcVar5[4] + -0x41) * 0x1000 | (pcVar5[3] + -0x41) * 0x100 |

           (pcVar5[7] + -0x41) * 0x1000000 | (pcVar5[2] + -0x41) * 0x10 |

           (pcVar5[6] + -0x41) * 0x100000 | (pcVar5[5] + -0x41) * 0x10000 |

           pcVar5[8] * 0x10000000 + 0xf0000000U | (int)pcVar5[1] - 0x41U) ^ DAT_00a0d198;

  iVar8 = uVar6 - (int)uVar6 % 0x15180;

  if ((iVar3 < iVar8) && (iVar8 - iVar3 < 0xed4e00)) {

    DAT_00d09210 = 1;

    return (int)uVar6 / 0x15180;

  }

LAB_006c110c:

  iVar3 = FUN_005e03a0(

                      "Havok evaluation key has expired or is invalid.\nPlease contact Havok.com for an extension.\nNo simulation possible."

                      );

  return iVar3;

}
