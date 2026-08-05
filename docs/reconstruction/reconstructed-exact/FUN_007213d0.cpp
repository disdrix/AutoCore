// =============================================================================
// FUN_007213d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007213d0
// Address:   0x007213d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007213d0 @ 0x007213d0
// Stable ID: aa_007213d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, for×1, do×1, while×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable×2, FUN_0071e820, FUN_0071fc20, FUN_007213d0, FUN_007227e0, ROUND.
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

void FUN_007213d0(int param_1,char *param_2)



{

  char cVar1;

  int *piVar2;

  int iVar3;

  char *pcVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  float10 fVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  FUN_0071e820(0);

  Client_GetMissionCompleteAudioTable();

  iVar3 = FUN_0071fc20(0,1,0xffffd8f0,0xffffffff,0);

  if (iVar3 == 0) {

    pcVar4 = param_2;

    puVar5 = (uint32_t /* width from decompiler */ *)(unaff_EBX + 0x250);

    for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *(uint32_t /* width from decompiler */ *)pcVar4;

      pcVar4 = pcVar4 + 4;

      puVar5 = puVar5 + 1;

    }

    pcVar4 = param_2;

    do {

      cVar1 = *pcVar4;

      pcVar4[(unaff_EBX - (int)param_2) + 0x48] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    *(uint8_t *)(unaff_EBX + 0x3a) = 0;

    *(char *)(unaff_EBX + 0x36) = param_2[0xa5];

    if (((*(int **)(unaff_EBX + 0x10) != (int *)0x0) && (*(int *)(unaff_EBX + 0x1c) != 0)) &&

       (piVar2 = (int *)**(int **)(unaff_EBX + 0x10), piVar2 != (int *)0x0)) {

      iVar3 = *piVar2;

      uVar7 = 0;

      Client_GetMissionCompleteAudioTable(0);

      fVar6 = (float10)FUN_007227e0(uVar7);

      (**(code **)(iVar3 + 0x3c))(piVar2,(int)ROUND(fVar6));

    }

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1a8) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1a4) = 0;

    if (*(int *)(param_2 + 0xb8) == 2) {

      *(float *)(unaff_EBX + 0x1b0) = *(float *)(unaff_EBX + 0x2e4) * *(float *)(param_1 + 0x24);

      return;

    }

    *(float *)(unaff_EBX + 0x1b0) = *(float *)(unaff_EBX + 0x2e4) * *(float *)(param_1 + 0x20);

  }

  return;

}
