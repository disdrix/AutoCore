// =============================================================================
// FUN_008e9140
// -----------------------------------------------------------------------------
// Stable ID: aa_008e9140
// Address:   0x008e9140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e9140 @ 0x008e9140
// Stable ID: aa_008e9140
// Embedded strings (evidence for future rename):
//   - "i_d_con_2d_wnd_chat_mute.dds"
//   - "i_d_con_2d_wnd_chat_active.dds"
//   - "i_d_con_2d_wnd_chat_speak.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, while×2, do×1, goto×1.
//  - Notable callees: CONCAT31, FUN_0066ec30, FUN_008e9140.
//  - Strings: "i_d_con_2d_wnd_chat_mute.dds"; "i_d_con_2d_wnd_chat_active.dds"; "i_d_con_2d_wnd_chat_speak.dds".
//  - Return sites: 3.

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

void FUN_008e9140(int param_1,int param_2,int param_3,char param_4)



{

  int *piVar1;

  bool bVar2;

  uint uVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char local_5;

  uint local_4;

  

  bVar2 = false;

  local_5 = '\0';

  local_4 = local_4 & 0xffffff00;

  iVar6 = 0;

  while( true ) {

    uVar3 = local_4;

    if (DAT_00d1b634 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = DAT_00d1b638 - DAT_00d1b634 >> 2;

    }

    if (iVar5 <= iVar6) break;

    piVar1 = *(int **)(DAT_00d1b634 + iVar6 * 4);

    if ((*piVar1 == param_2) && (piVar1[1] == param_3)) {

      local_4 = CONCAT31(local_4._1_3_,(char)piVar1[3]);

      bVar2 = true;

    }

    iVar6 = iVar6 + 1;

  }

  if (!bVar2) {

    return;

  }

  iVar6 = 0;

  puVar7 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5f8);

  do {

    iVar5 = puVar7[-8];

    if ((iVar5 == 0) || (*(int *)(iVar5 + 0x500) == 0)) {

LAB_008e91f2:

      (**(code **)(*(int *)*puVar7 + 0x50))("i_d_con_2d_wnd_chat_mute.dds",0,0);

      (**(code **)(*(int *)*puVar7 + 0x34c))();

    }

    else if ((*(int *)(iVar5 + 0x508) == param_2) && (*(int *)(iVar5 + 0x50c) == param_3)) {

      FUN_0066ec30(uVar3,&local_5);

      if (local_5 == '\0') {

        cVar4 = (**(code **)(**(int **)(param_1 + 0x5f8 + iVar6 * 4) + 0xd0))();

        if (cVar4 == '\0') {

          (**(code **)(**(int **)(param_1 + 0x5f8 + iVar6 * 4) + 0xcc))(1);

        }

        piVar1 = *(int **)(param_1 + 0x5f8 + iVar6 * 4);

        if (param_4 == '\0') {

          (**(code **)(*piVar1 + 0x50))("i_d_con_2d_wnd_chat_active.dds",0,0);

        }

        else {

          (**(code **)(*piVar1 + 0x50))("i_d_con_2d_wnd_chat_speak.dds");

        }

        (**(code **)(**(int **)(param_1 + 0x5f8 + iVar6 * 4) + 0x34c))();

        return;

      }

      goto LAB_008e91f2;

    }

    iVar6 = iVar6 + 1;

    puVar7 = puVar7 + 1;

    if (3 < iVar6) {

      return;

    }

  } while( true );

}
