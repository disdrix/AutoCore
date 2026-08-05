// =============================================================================
// FUN_004b8dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b8dc0
// Address:   0x004b8dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b8dc0 @ 0x004b8dc0
// Stable ID: aa_004b8dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, do×4, while×4, return×2.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_004b6fc0, FUN_004b7e50, FUN_004b8dc0, FUN_0058e930, FUN_005bbb90, FUN_007203b0, FUN_00720d40.
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

void __thiscall FUN_004b8dc0(int param_1,char param_2,uint32_t /* width from decompiler */ param_3)



{

  uint uVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  if (param_2 != *(char *)(param_1 + 0xb)) {

    *(char *)(param_1 + 0xb) = param_2;

    piVar2 = (int *)**(int **)(param_1 + 0x1e0);

    if (piVar2 != *(int **)(param_1 + 0x1e0)) {

      do {

        FUN_005bbb90(*(uint8_t *)(param_1 + 0xb),param_3);

        piVar2 = (int *)*piVar2;

      } while (piVar2 != (int *)*(int *)(param_1 + 0x1e0));

    }

    piVar2 = (int *)**(int **)(param_1 + 0x204);

    if (piVar2 != *(int **)(param_1 + 0x204)) {

      do {

        FUN_0058e930(*(uint8_t *)(param_1 + 0xb));

        piVar2 = (int *)*piVar2;

      } while (piVar2 != (int *)*(int *)(param_1 + 0x204));

    }

    if (*(char *)(param_1 + 0xb) != '\0') {

      FUN_004b7e50(0,0,0,0,0,0);

      FUN_004b6fc0();

      return;

    }

    piVar2 = (int *)**(int **)(param_1 + 0x1ec);

    if (piVar2 != *(int **)(param_1 + 0x1ec)) {

      do {

        iVar4 = piVar2[2];

        uVar1 = (uint)*(byte *)(iVar4 + 0x128);

        uVar6 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x124);

        uVar5 = 0;

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x120);

        Client_GetMissionCompleteAudioTable(uVar3,uVar6,uVar1,iVar4,0);

        FUN_00723b20(uVar3,uVar6,uVar1,iVar4,uVar5);

        piVar2 = (int *)*piVar2;

      } while (piVar2 != (int *)*(int *)(param_1 + 0x1ec));

    }

    if ((*(int *)(param_1 + 0x1fc) != 0) &&

       (piVar2 = (int *)**(int **)(param_1 + 0x1f8), piVar2 != *(int **)(param_1 + 0x1f8))) {

      do {

        iVar4 = piVar2[2];

        uVar6 = 1;

        FUN_00720d40(iVar4,1);

        FUN_007203b0(iVar4,uVar6);

        piVar2 = (int *)*piVar2;

      } while (piVar2 != (int *)*(int *)(param_1 + 0x1f8));

    }

  }

  return;

}
