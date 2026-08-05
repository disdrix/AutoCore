// =============================================================================
// FUN_00891b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00891b60
// Address:   0x00891b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00891b60 @ 0x00891b60
// Stable ID: aa_00891b60
// Embedded strings (evidence for future rename):
//   - "Team %i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×10, do×3, while×3, return×1.
//  - Notable callees: sprintf×2, FUN_008904a0, FUN_00891480, FUN_00891b60.
//  - Strings: "Team %i".
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

void FUN_00891b60(int param_1,int param_2,ushort param_3,uint32_t /* width from decompiler */ *param_4,int param_5,int param_6

                 )



{

  bool bVar1;

  char cVar2;

  char *pcVar3;

  int *piVar4;

  char *pcVar5;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  int iStack_210;

  int aiStack_204 [64];

  char acStack_104 [260];

  

  bVar1 = false;

  cVar2 = (**(code **)(*unaff_EBX + 0x3d8))();

  if ((cVar2 != '\0') && (unaff_EBX[0x16b] != 3)) {

    bVar1 = true;

  }

  unaff_EBX[0x16c] = param_1;

  unaff_EBX[0x16d] = param_2;

  unaff_EBX[0x16b] = 3;

  FUN_008904a0();

  if ((int *)unaff_EBX[0x159] != (int *)0x0) {

    (**(code **)(*(int *)unaff_EBX[0x159] + 4))(1);

  }

  *(ushort *)(unaff_EBX + 0x166) = param_3;

  aiStack_204[0] = param_5 - (int)param_4;

  iStack_210 = 0;

  piVar7 = unaff_EBX + 0x151;

  puVar6 = param_4;

  do {

    if ((void *)piVar7[0xd] != (void *)0x0) {

      operator_delete__((void *)piVar7[0xd]);

    }

    piVar7[0xd] = 0;

    if ((param_4 == (uint32_t /* width from decompiler */ *)0x0) || (param_3 <= (ushort)iStack_210)) {

      if ((int *)*piVar7 != (int *)0x0) {

        (**(code **)(*(int *)*piVar7 + 4))(0);

      }

      if ((int *)piVar7[4] != (int *)0x0) {

        (**(code **)(*(int *)piVar7[4] + 4))(0);

      }

    }

    else {

      pcVar3 = (char *)*puVar6;

      pcVar5 = pcVar3 + 1;

      do {

        cVar2 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      pcVar3 = operator_new__((uint)(pcVar3 + (1 - (int)pcVar5)));

      piVar7[0xd] = (int)pcVar3;

      pcVar5 = (char *)*puVar6;

      do {

        cVar2 = *pcVar5;

        *pcVar3 = cVar2;

        pcVar5 = pcVar5 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar2 != '\0');

      piVar7[9] = *(int *)((int)puVar6 + (param_6 - (int)param_4));

      if ((int *)*piVar7 != (int *)0x0) {

        (**(code **)(*(int *)*piVar7 + 0xcc))(1);

        piVar4 = (int *)piVar7[0xd];

        if (piVar4 == (int *)0x0) {

          sprintf((char *)aiStack_204,"Team %i",iStack_210);

          piVar4 = aiStack_204;

        }

        (**(code **)(*(int *)*piVar7 + 0x1d8))(piVar4,1,1);

        (**(code **)(*(int *)*piVar7 + 0x15c))(1,piVar7 + 9);

        (**(code **)(*(int *)*piVar7 + 0x34c))();

      }

      piVar7[0x11] = *(int *)((int)puVar6 + aiStack_204[0]);

      if ((int *)piVar7[4] != (int *)0x0) {

        (**(code **)(*(int *)piVar7[4] + 0xcc))(1);

        sprintf(acStack_104,"%d",piVar7[0x11]);

        (**(code **)(*(int *)piVar7[4] + 0x1d8))(acStack_104,1,1);

        (**(code **)(*(int *)piVar7[4] + 0x34c))();

      }

    }

    iStack_210 = iStack_210 + 1;

    puVar6 = puVar6 + 1;

    piVar7 = piVar7 + 1;

  } while ((ushort)iStack_210 < 4);

  if (bVar1) {

    FUN_00891480(unaff_EBX);

  }

  return;

}
