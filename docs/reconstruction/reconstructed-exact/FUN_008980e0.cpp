// =============================================================================
// FUN_008980e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008980e0
// Address:   0x008980e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008980e0 @ 0x008980e0
// Stable ID: aa_008980e0
// Embedded strings (evidence for future rename):
//   - "if_text_2"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, goto×1, return×1.
//  - Notable callees: Client_GetMissionCompleteAudioTable, Client_PlayNamedInterfaceSound, Client_SendSectorPacket, FUN_007fca10, FUN_0087b500, FUN_008980e0.
//  - Strings: "if_text_2".
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

void __thiscall FUN_008980e0(int param_1,int param_2,int param_3)



{

  char cVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ local_8;

  uint local_4;

  

  if (param_2 == 8) {

    if (param_3 != 40000) {

      if ((param_3 != 0x9c41) || (DAT_00d1b6d8 == 0)) goto LAB_008981b4;

      local_8 = 0x20bd;

      local_4 = 0;

      cVar1 = (**(code **)(**(int **)(param_1 + 0x534) + 0x3bc))();

      if (cVar1 != '\0') {

        local_4 = local_4 | 4;

      }

      cVar1 = (**(code **)(**(int **)(param_1 + 0x538) + 0x3bc))();

      if (cVar1 != '\0') {

        local_4 = local_4 | 0x40;

      }

      cVar1 = (**(code **)(**(int **)(param_1 + 0x53c) + 0x3bc))();

      if (cVar1 != '\0') {

        local_4 = local_4 | 1;

      }

      Client_SendSectorPacket(&DAT_00d1a840,8,&local_8);

      uVar9 = 0;

      uVar8 = 0x1e;

      uVar7 = 0;

      uVar6 = 0;

      uVar5 = 0xffffffff;

      uVar4 = 0xffffffff;

      uVar3 = 0;

      pcVar2 = "if_text_2";

      Client_GetMissionCompleteAudioTable("if_text_2",0,0xffffffff,0xffffffff,0,0,0x1e,0);

      Client_PlayNamedInterfaceSound(pcVar2,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);

    }

    FUN_007fca10();

  }

LAB_008981b4:

  FUN_0087b500(param_2,param_3);

  return;

}
