// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e4430
// -----------------------------------------------------------------------------
// Stable ID: aa_008e4430
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
// Address:   0x008e4430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper. Evidence string: "Impossible". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Impossible"
//   - "Trivial"
//   - "Easy"
//   - "Moderate"
//   - "Hard"
//   - "Very Hard"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×13, goto×6, return×2.
//  - Notable callees: FUN_00973820×5, FUN_0052ada0, FUN_0052b080, FUN_007a69d0, FUN_007a6de0, FUN_008e4430, FUN_00973590, sprintf.
//  - Strings: "Impossible"; "Trivial"; "Easy"; "Moderate".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e4430(uint32_t /* width from decompiler */ *param_1)



{

  float fVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *unaff_ESI;

  float10 fVar4;

  char *pcVar5;

  int iVar6;

  float local_10;

  float local_c;

  float local_8;

  float local_4;

  

  if ((in_EAX == 0) || (DAT_00d1b6d8 == 0)) {

    *param_1 = 0xffffffff;

    return;

  }

  iVar2 = *(int *)(*(int *)(in_EAX + 0xa8) + 0x3c);

  iVar6 = *(int *)(iVar2 + 0x4b0);

  iVar2 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x4ac));

  fVar4 = (float10)FUN_0052b080(in_EAX);

  fVar1 = (float)fVar4;

  FUN_007a69d0();

  if (iVar2 < iVar6) {

    local_10 = DAT_00d1b484;

    local_4 = DAT_00d1b490;

    local_8 = DAT_00d1b48c;

    local_c = DAT_00d1b488;

    FUN_00973590(DAT_00d1b484 * DAT_00aaa6f8,DAT_00d1b488 * DAT_00aaa6f8,DAT_00d1b48c * DAT_00aaa6f8

                 ,DAT_00d1b490 * DAT_00aaa6f8);

    if (unaff_ESI == (char *)0x0) goto LAB_008e4707;

    pcVar5 = "Impossible";

  }

  else if (fVar1 <= DAT_00aaa954) {

    if (fVar1 <= DAT_00aaa950) {

      if (fVar1 <= DAT_00a0f524) {

        if (fVar1 <= DAT_00a0f694) {

          if (fVar1 <= g_flZero) {

            local_10 = DAT_00d1b424;

            local_c = DAT_00d1b428;

            local_8 = DAT_00d1b42c;

            local_4 = DAT_00d1b430;

          }

          else {

            local_10 = DAT_00d1b434;

            local_c = DAT_00d1b438;

            local_8 = DAT_00d1b43c;

            local_4 = DAT_00d1b440;

          }

          FUN_00973820(&local_10);

          if (unaff_ESI == (char *)0x0) goto LAB_008e4707;

          pcVar5 = "Trivial";

        }

        else {

          local_c = DAT_00d1b448;

          local_10 = DAT_00d1b444;

          local_8 = DAT_00d1b44c;

          local_4 = DAT_00d1b450;

          FUN_00973820(&local_10);

          if (unaff_ESI == (char *)0x0) goto LAB_008e4707;

          pcVar5 = "Easy";

        }

      }

      else {

        local_c = DAT_00d1b458;

        local_10 = DAT_00d1b454;

        local_8 = DAT_00d1b45c;

        local_4 = DAT_00d1b460;

        FUN_00973820(&local_10);

        if (unaff_ESI == (char *)0x0) goto LAB_008e4707;

        pcVar5 = "Moderate";

      }

    }

    else {

      local_10 = DAT_00d1b464;

      local_c = DAT_00d1b468;

      local_4 = DAT_00d1b470;

      local_8 = DAT_00d1b46c;

      FUN_00973820(&local_10);

      if (unaff_ESI == (char *)0x0) goto LAB_008e4707;

      pcVar5 = "Hard";

    }

  }

  else {

    local_c = DAT_00d1b478;

    local_10 = DAT_00d1b474;

    local_8 = DAT_00d1b47c;

    local_4 = DAT_00d1b480;

    FUN_00973820(&local_10);

    if (unaff_ESI == (char *)0x0) goto LAB_008e4707;

    pcVar5 = "Very Hard";

  }

  uVar3 = FUN_007a6de0(pcVar5,0xffffffff);

  sprintf(unaff_ESI,"%s: %d",uVar3,iVar6);

LAB_008e4707:

  *param_1 = 0xffffffff;

  return;

}
