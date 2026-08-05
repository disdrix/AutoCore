// =============================================================================
// FUN_00796b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00796b20
// Address:   0x00796b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00796b20 @ 0x00796b20
// Stable ID: aa_00796b20
// Embedded strings (evidence for future rename):
//   - "SetCoop Failed!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~80 non-empty decompiler lines.
//  - Control keywords: if×4, do×4, while×4, for×2, return×1.
//  - Notable callees: FUN_00796520, FUN_007966b0, FUN_00796b20, OutputDebugStringA.
//  - Strings: "SetCoop Failed!".
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

void FUN_00796b20(int param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int unaff_EDI;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ local_5d8 [14];

  uint8_t auStack_5a0 [16];

  uint8_t auStack_590 [8];

  char acStack_588 [264];

  uint32_t /* width from decompiler */ uStack_480;

  uint32_t /* width from decompiler */ uStack_47c;

  uint32_t /* width from decompiler */ uStack_478;

  uint32_t /* width from decompiler */ uStack_474;

  uint32_t /* width from decompiler */ auStack_268 [153];

  

  FUN_00796520(1);

  puVar6 = local_5d8;

  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  iVar3 = param_1 + 0x84;

  (**(code **)(**(int **)(param_1 + 8) + 0x24))

            (*(int **)(param_1 + 8),0,iVar3,&LAB_00796720,local_5d8,0);

  uStack_480 = 0x218;

  uStack_47c = 0x10;

  uStack_478 = 0;

  uStack_474 = 0;

  if (unaff_EDI != 0) {

    piVar5 = (int *)&stack0xfffffa10;

    do {

      piVar7 = piVar5;

      (**(code **)(*(int *)*piVar5 + 0x14))((int *)*piVar5,0x19,&uStack_480);

      pcVar2 = acStack_588;

      do {

        cVar1 = *pcVar2;

        pcVar2 = pcVar2 + 1;

      } while (cVar1 != '\0');

      if (pcVar2 != acStack_588 + 1) {

        pcVar2 = acStack_588;

        do {

          cVar1 = *pcVar2;

          pcVar2 = pcVar2 + 1;

        } while (cVar1 != '\0');

        puVar6 = auStack_268;

        for (iVar4 = 0x91; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar6 = 0;

          puVar6 = puVar6 + 1;

        }

        auStack_268[0] = 0x244;

        (**(code **)(*(int *)*piVar5 + 0x3c))((int *)*piVar5,auStack_268);

        (**(code **)(*(int *)*piVar5 + 0x74))((int *)*piVar5,iVar3,auStack_590,0);

        (**(code **)(*(int *)*piVar5 + 0x78))((int *)*piVar5,iVar3,auStack_5a0,0);

        iVar4 = (**(code **)(*(int *)*piVar5 + 0x34))

                          ((int *)*piVar5,*(uint32_t /* width from decompiler */ *)(param_1 + 0x80),6);

        piVar5 = piVar7;

        if (iVar4 < 0) {

          OutputDebugStringA("SetCoop Failed!");

          piVar5 = piVar7;

        }

        FUN_007966b0();

      }

      piVar5 = piVar5 + 1;

    } while (*piVar5 != 0);

  }

  if (unaff_EDI != 0) {

    piVar5 = (int *)&stack0xfffffa10;

    do {

      (**(code **)(*(int *)*piVar5 + 8))((int *)*piVar5);

      piVar7 = piVar5 + 1;

      *piVar5 = 0;

      piVar5 = piVar7;

    } while (*piVar7 != 0);

  }

  return;

}
