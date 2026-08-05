// =============================================================================
// FUN_00477310
// -----------------------------------------------------------------------------
// Stable ID: aa_00477310
// Address:   0x00477310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477310 @ 0x00477310
// Stable ID: aa_00477310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~151 non-empty decompiler lines.
//  - Control keywords: if×16, goto×5, do×4, while×4, for×4, return×2.
//  - Notable callees: FUN_00477310.
//  - Return sites: 2.

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

void FUN_00477310(uint *param_1,uint param_2)



{

  char cVar1;

  uint uVar2;

  uint8_t *in_EAX;

  uint8_t *puVar3;

  char cVar4;

  int iVar5;

  uint uVar6;

  

  cVar1 = (char)param_1[2];

  uVar2 = *param_1;

  cVar4 = (char)param_2;

  if (((cVar1 == '\x02') || ((cVar1 == '\x06' && ((param_2 & 0x400000) != 0)))) &&

     (*(char *)((int)param_1 + 10) == '\x04')) {

    if (*(char *)((int)param_1 + 9) == '\b') {

      uVar6 = uVar2;

      puVar3 = in_EAX;

      if (cVar4 < '\0') {

        if (1 < uVar2) {

          iVar5 = uVar2 - 1;

          do {

            puVar3[3] = in_EAX[4];

            puVar3[4] = in_EAX[5];

            puVar3[5] = in_EAX[6];

            iVar5 = iVar5 + -1;

            in_EAX = in_EAX + 4;

            puVar3 = puVar3 + 3;

          } while (iVar5 != 0);

          *(uint8_t *)((int)param_1 + 0xb) = 0x18;

          param_1[1] = uVar2 * 3;

          *(uint8_t *)((int)param_1 + 10) = 3;

          goto LAB_0047759e;

        }

      }

      else {

        for (; uVar6 != 0; uVar6 = uVar6 - 1) {

          *in_EAX = puVar3[1];

          in_EAX[1] = puVar3[2];

          in_EAX[2] = puVar3[3];

          in_EAX = in_EAX + 3;

          puVar3 = puVar3 + 4;

        }

      }

      *(uint8_t *)((int)param_1 + 0xb) = 0x18;

      param_1[1] = uVar2 * 3;

      *(uint8_t *)((int)param_1 + 10) = 3;

    }

    else {

      uVar6 = uVar2;

      puVar3 = in_EAX;

      if (cVar4 < '\0') {

        if (1 < uVar2) {

          iVar5 = uVar2 - 1;

          do {

            in_EAX[6] = puVar3[8];

            in_EAX[7] = puVar3[9];

            in_EAX[8] = puVar3[10];

            in_EAX[9] = puVar3[0xb];

            in_EAX[10] = puVar3[0xc];

            in_EAX[0xb] = puVar3[0xd];

            iVar5 = iVar5 + -1;

            in_EAX = in_EAX + 6;

            puVar3 = puVar3 + 8;

          } while (iVar5 != 0);

        }

      }

      else {

        for (; uVar6 != 0; uVar6 = uVar6 - 1) {

          *in_EAX = puVar3[2];

          in_EAX[1] = puVar3[3];

          in_EAX[2] = puVar3[4];

          in_EAX[3] = puVar3[5];

          in_EAX[4] = puVar3[6];

          in_EAX[5] = puVar3[7];

          in_EAX = in_EAX + 6;

          puVar3 = puVar3 + 8;

        }

      }

      *(uint8_t *)((int)param_1 + 0xb) = 0x30;

      param_1[1] = uVar2 * 6;

      *(uint8_t *)((int)param_1 + 10) = 3;

    }

    goto LAB_0047759e;

  }

  if (cVar1 != '\0') {

    if (cVar1 != '\x04') goto LAB_0047759e;

    if ((param_2 & 0x400000) == 0) {

      return;

    }

  }

  if (*(char *)((int)param_1 + 10) != '\x02') goto LAB_0047759e;

  if (*(char *)((int)param_1 + 9) == '\b') {

    uVar6 = uVar2;

    puVar3 = in_EAX;

    if (cVar4 < '\0') {

      if (uVar2 != 0) {

        do {

          *puVar3 = *in_EAX;

          in_EAX = in_EAX + 2;

          uVar6 = uVar6 - 1;

          puVar3 = puVar3 + 1;

        } while (uVar6 != 0);

        *(uint8_t *)((int)param_1 + 0xb) = 8;

        param_1[1] = uVar2;

        goto LAB_0047759a;

      }

    }

    else {

      for (; uVar6 != 0; uVar6 = uVar6 - 1) {

        *in_EAX = puVar3[1];

        in_EAX = in_EAX + 1;

        puVar3 = puVar3 + 2;

      }

    }

    *(uint8_t *)((int)param_1 + 0xb) = 8;

    param_1[1] = uVar2;

  }

  else {

    uVar6 = uVar2;

    puVar3 = in_EAX;

    if (cVar4 < '\0') {

      if (1 < uVar2) {

        iVar5 = uVar2 - 1;

        do {

          in_EAX[2] = puVar3[4];

          in_EAX[3] = puVar3[5];

          iVar5 = iVar5 + -1;

          in_EAX = in_EAX + 2;

          puVar3 = puVar3 + 4;

        } while (iVar5 != 0);

      }

    }

    else {

      for (; uVar6 != 0; uVar6 = uVar6 - 1) {

        *in_EAX = puVar3[2];

        in_EAX[1] = puVar3[3];

        in_EAX = in_EAX + 2;

        puVar3 = puVar3 + 4;

      }

    }

    *(uint8_t *)((int)param_1 + 0xb) = 0x10;

    param_1[1] = uVar2 * 2;

  }

LAB_0047759a:

  *(uint8_t *)((int)param_1 + 10) = 1;

LAB_0047759e:

  if ((param_2 & 0x400000) != 0) {

    *(byte *)(param_1 + 2) = (byte)param_1[2] & 0xfb;

  }

  return;

}
