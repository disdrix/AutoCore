// =============================================================================
// Snd_Use_box_select_sound_group_priority
// -----------------------------------------------------------------------------
// Stable ID: aa_008209c0
// Address:   0x008209c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Snd_Use_box_select_sound_group_priority @ 0x008209c0
// Stable ID: aa_008209c0
// Embedded strings (evidence for future rename):
//   - "Sound Priority Highest"
//   - "Use this box to select a sound group for this priority level"
//   - "Sound Priority Lowest"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×10, do×2, goto×2, while×2, for×1, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, FUN_004073a0, FUN_00818fe0, Snd_Use_box_select_sound_group_priority, __RTDynamicCast.
//  - Strings: "Sound Priority Highest"; "Use this box to select a sound group for this priority level"; "Sound Priority Lowest".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Use this box to select a sound group for this priority level"
 * Domain alias of FUN_008209c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Snd_Use_box_select_sound_group_priority(int param_1)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  char *pcVar9;

  int local_10;

  uint32_t /* width from decompiler */ uStack_4;

  

  local_10 = 0;

  do {

    iVar4 = FUN_00818fe0();

    iVar1 = param_1 + local_10 * 0x14;

    *(int *)(iVar1 + 0xee4) = iVar4;

    if (local_10 == 0) {

      if (*(int *)(iVar4 + 0x600) != 0) {

        pcVar9 = "Sound Priority Highest";

LAB_00820a28:

        (**(code **)(**(int **)(iVar4 + 0x600) + 0x1d8))(pcVar9,1,1);

        (**(code **)(**(int **)(iVar4 + 0x600) + 0x34c))();

LAB_00820a44:

        if (*(int *)(iVar4 + 0x600) != 0) {

          (**(code **)(**(int **)(iVar4 + 0x600) + 0x308))

                    ("Use this box to select a sound group for this priority level");

        }

      }

    }

    else {

      if (local_10 != 8) goto LAB_00820a44;

      if (*(int *)(iVar4 + 0x600) != 0) {

        pcVar9 = "Sound Priority Lowest";

        goto LAB_00820a28;

      }

    }

    piVar2 = *(int **)(*(int *)(iVar4 + 0x708) + 0x930);

    if (piVar2 != (int *)0x0) {

      *(uint8_t *)((int)piVar2 + 0x489) = 1;

      piVar5 = (int *)(**(code **)(*piVar2 + 0x170))(0xb);

      piVar2[0x8b] = *piVar5;

      piVar5 = (int *)__RTDynamicCast(piVar2[0xac],0,&CNDUIWindow::RTTI_Type_Descriptor,

                                      &CNDUIDialog::RTTI_Type_Descriptor,0);

      if ((piVar5 != (int *)0x0) && ((int *)piVar5[0x12f] == piVar2)) {

        (**(code **)(*piVar5 + 0x1c8))(0);

        (**(code **)(*piVar5 + 0x3c0))(0);

      }

    }

    iVar7 = local_10 + 1;

    local_10 = 0;

    iVar8 = 0x260;

    do {

      uStack_4 = (**(code **)(**(int **)(iVar4 + 0x708) + 0x448))

                           (*(uint32_t /* width from decompiler */ *)

                             ((int)&CBtnMission::RTTI_Type_Descriptor.pVFTable + iVar8));

      iVar6 = *(int *)(iVar1 + 0xeec);

      if ((iVar6 == 0) ||

         ((uint)(*(int *)(iVar1 + 0xef4) - iVar6 >> 2) <=

          (uint)(*(int *)(iVar1 + 0xef0) - iVar6 >> 2))) {

        FUN_004073a0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0xef0),1,&uStack_4);

      }

      else {

        puVar3 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0xef0);

        *puVar3 = uStack_4;

        *(uint32_t /* width from decompiler */ **)(iVar1 + 0xef0) = puVar3 + 1;

      }

      iVar6 = Client_GetMissionCompleteAudioTable();

      if (*(int *)(iVar8 + iVar6) == iVar7) {

        (**(code **)(**(int **)(iVar4 + 0x708) + 0x460))(local_10);

      }

      local_10 = local_10 + 1;

      iVar8 = iVar8 + 4;

    } while (iVar8 < 0x284);

    local_10 = iVar7;

    if (8 < iVar7) {

      return;

    }

  } while( true );

}
