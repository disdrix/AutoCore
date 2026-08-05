// SUPERSEDED 2026-07-29 W27-D: keyword alias rejected.
// Prefer NDSpecialFX_StopFinalize_Inferred.cpp / FUN_004ba0a0.cpp
// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×12, do×6, while×6, return×2, switch×1.
//  - Notable callees: FUN_005b8340×3, Client_GetMissionCompleteAudioTable, FUN_00498a90, FUN_00498ab0, FUN_004b6a80, FUN_004b9270, FUN_004b9af0, FUN_004ba0a0.
//  - Return sites: 2.

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004ba0a0
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Client_GetMissionCompleteAudioTable"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004ba0a0 clean capture (not modernized).
//
// Address:  0x004ba0a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004ba0a0
// Stable ID: aa_004ba0a0
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004ba0a0_*.md
//           Original Ghidra symbol: FUN_004ba0a0
//
// Exactness: Body mirrors reconstructed-exact/FUN_004ba0a0*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004ba0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ba0a0
// Address:   0x004ba0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "Client_GetMissionCompleteAudioTable"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

char __fastcall Mission_Uses_Client_GetMissionCompleteAudioTable_004ba0a0(int param_1)



{

  int iVar1;

  char cVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  char local_8;

  uint local_4;

  

  local_8 = '\x01';

  cVar2 = '\x01';

  if (*(char *)(param_1 + 8) != '\0') {

    return '\x01';

  }

  piVar5 = *(int **)(param_1 + 0x10);

  if (piVar5 != (int *)0x0) {

    switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0x28)) {

    case 4:

      cVar3 = FUN_004b6a80();

      if (cVar3 != '\0') break;

    case 5:

    case 6:

    case 0xc:

    case 0xd:

    case 0xe:

    case 0x14:

    case 0x15:

      if (*(char *)(param_1 + 0xb) != '\0') {

        cVar2 = '\0';

        uVar4 = (**(code **)(*piVar5 + 0x1cc))();

        FUN_004b9af0(uVar4);

        FUN_004b9270(param_1);

        local_8 = '\0';

      }

    }

  }

  *(uint8_t *)(param_1 + 8) = 1;

  piVar5 = (int *)**(int **)(param_1 + 0x1e0);

  if (piVar5 != *(int **)(param_1 + 0x1e0)) {

    do {

      iVar1 = piVar5[2];

      if (cVar2 != '\0') {

        *(uint8_t *)(iVar1 + 0x7f9) = 1;

      }

      FUN_005b8340();

      iVar6 = iVar1 + 0x14;

      do {

        FUN_005b8340();

        iVar6 = *(int *)(iVar6 + 0x2f4);

      } while (iVar6 != iVar1 + 0x14);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = 0;

      piVar5 = (int *)*piVar5;

      local_8 = cVar2;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x1e0));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x1ec);

  if (piVar5 != *(int **)(param_1 + 0x1ec)) {

    do {

      if ((*(char *)(piVar5[2] + 0x10b) != '\0') && (iVar1 = *(int *)(param_1 + 0x10), iVar1 != 0))

      {

        uVar9 = 0;

        local_4 = (uint)*(byte *)(iVar1 + 0x168);

        uVar4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x160);

        uVar7 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164);

        uVar8 = 0;

        Client_GetMissionCompleteAudioTable(uVar4,uVar7,local_4,0,0);

        FUN_00723b20(uVar4,uVar7,local_4,uVar8,uVar9);

      }

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x1ec));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x204);

  if (piVar5 != *(int **)(param_1 + 0x204)) {

    do {

      FUN_00593e10(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c),cVar2);

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x204));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x210);

  if (piVar5 != *(int **)(param_1 + 0x210)) {

    do {

      if (local_8 != '\0') {

        *(uint *)(piVar5[2] + 0x178) = *(uint *)(piVar5[2] + 0x178) | 0x100;

      }

      FUN_005b8340();

      *(uint32_t /* width from decompiler */ *)piVar5[2] = 0;

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x210));

  }

  piVar5 = (int *)**(int **)(param_1 + 0x21c);

  if (piVar5 != *(int **)(param_1 + 0x21c)) {

    do {

      FUN_00498a90();

      FUN_00498ab0(0);

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)*(int *)(param_1 + 0x21c));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  return local_8;

}
