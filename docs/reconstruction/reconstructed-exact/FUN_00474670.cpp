// =============================================================================
// FUN_00474670
// -----------------------------------------------------------------------------
// Stable ID: aa_00474670
// Address:   0x00474670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00474670 @ 0x00474670
// Stable ID: aa_00474670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×3.
//  - Notable callees: FUN_00474670.
//  - Return sites: 4.

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

void __thiscall FUN_00474670(byte *param_1,int *param_2,int param_3)



{

  char cVar1;

  byte bVar2;

  int iVar3;

  byte *pbVar4;

  int in_EAX;

  int iVar5;

  

  iVar5 = *param_2;

  cVar1 = (char)param_2[2];

  if (((cVar1 == '\x02') && (param_3 != 0)) &&

     (iVar3 = iVar5, pbVar4 = param_1, *(char *)((int)param_2 + 9) == '\b')) {

    for (; iVar3 != 0; iVar3 = iVar3 + -1) {

      *pbVar4 = *(byte *)((((*param_1 & 0xf8) << 5 | param_1[1] & 0xf8) * 4 |

                          (int)(uint)param_1[2] >> 3) + param_3);

      param_1 = param_1 + 3;

      pbVar4 = pbVar4 + 1;

    }

    bVar2 = *(byte *)((int)param_2 + 9);

    *(byte *)((int)param_2 + 0xb) = bVar2;

    *(uint8_t *)(param_2 + 2) = 3;

    *(uint8_t *)((int)param_2 + 10) = 1;

    if (7 < bVar2) {

      param_2[1] = (uint)(bVar2 >> 3) * iVar5;

      return;

    }

  }

  else {

    if (((cVar1 != '\x06') || (param_3 == 0)) ||

       (iVar3 = iVar5, pbVar4 = param_1, *(char *)((int)param_2 + 9) != '\b')) {

      if (((cVar1 == '\x03') && (in_EAX != 0)) && (*(char *)((int)param_2 + 9) == '\b')) {

        for (; iVar5 != 0; iVar5 = iVar5 + -1) {

          *param_1 = *(byte *)((uint)*param_1 + in_EAX);

          param_1 = param_1 + 1;

        }

      }

      return;

    }

    for (; iVar3 != 0; iVar3 = iVar3 + -1) {

      *pbVar4 = *(byte *)((((*param_1 & 0xf8) << 5 | param_1[1] & 0xf8) * 4 |

                          (int)(uint)param_1[2] >> 3) + param_3);

      param_1 = param_1 + 4;

      pbVar4 = pbVar4 + 1;

    }

    bVar2 = *(byte *)((int)param_2 + 9);

    *(byte *)((int)param_2 + 0xb) = bVar2;

    *(uint8_t *)(param_2 + 2) = 3;

    *(uint8_t *)((int)param_2 + 10) = 1;

    if (7 < bVar2) {

      param_2[1] = (uint)(bVar2 >> 3) * iVar5;

      return;

    }

  }

  param_2[1] = (uint)bVar2 * iVar5 + 7 >> 3;

  return;

}
