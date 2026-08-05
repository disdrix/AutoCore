// =============================================================================
// FUN_008f1290
// -----------------------------------------------------------------------------
// Stable ID: aa_008f1290
// Address:   0x008f1290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f1290 @ 0x008f1290
// Stable ID: aa_008f1290
// Embedded strings (evidence for future rename):
//   - "(Not Currently In A Clan)"
//   - "Clan Leader"
//   - "%s: %s"
//   - "Clan Member"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×11, goto×2, return×1.
//  - Notable callees: FUN_007a69d0×2, FUN_007a6de0×2, sprintf×2, FUN_008f1290.
//  - Strings: "(Not Currently In A Clan)"; "Clan Leader"; "%s: %s"; "Clan Member".
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

void FUN_008f1290(void)



{

  int iVar1;

  int iVar2;

  uint8_t *puVar3;

  int unaff_ESI;

  int *piVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uStack_150;

  int *piStack_14c;

  uint8_t auStack_13c [8];

  uint8_t auStack_134 [4];

  uint8_t auStack_130 [4];

  uint8_t auStack_12c [12];

  uint8_t auStack_120 [28];

  uint8_t auStack_104 [4];

  char local_100 [4];

  char local_fc [4];

  char local_f8 [248];

  

  iVar1 = *(int *)(unaff_ESI + 0x520);

  if (iVar1 == 0) {

    if (*(int *)(unaff_ESI + 0x538) != 0) {

      piStack_14c = (int *)0x1;

      uStack_150 = 0x8f152c;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1b0))();

      uStack_150 = 1;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1d8))("(Not Currently In A Clan)",1);

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x34c))();

    }

  }

  else {

    if (iVar1 == 1) {

      if (*(int *)(unaff_ESI + 0x538) == 0) goto LAB_008f1551;

      if (*DAT_00d1da30 == -1) {

        local_100 = (char  [4])s_Clan_Leader_00a3847c._0_4_;

        local_fc = (char  [4])s_Clan_Leader_00a3847c._4_4_;

        local_f8._0_4_ = s_Clan_Leader_00a3847c._8_4_;

      }

      else {

        piStack_14c = DAT_00d1da30 + 1;

        uStack_150 = 0xffffffff;

        pcVar5 = "Clan Leader";

        FUN_007a69d0("Clan Leader");

        uStack_150 = FUN_007a6de0(pcVar5);

        sprintf(local_100,"%s: %s");

      }

      piStack_14c = (int *)0x1;

      uStack_150 = 0x8f1477;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1b0))();

      uStack_150 = 1;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1d8))(auStack_104,1);

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x34c))();

      piVar4 = *(int **)(unaff_ESI + 0x538);

      iVar1 = (**(code **)(*piVar4 + 0x140))(&uStack_150,1);

      iVar2 = (**(code **)(*piVar4 + 0x204))(&stack0xfffffeb8);

      if (*(int *)(iVar1 + 4) < *(int *)(iVar2 + 4)) {

        (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1b0))(10);

        (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1d8))(auStack_120,1,0);

      }

      piVar4 = *(int **)(unaff_ESI + 0x538);

      iVar1 = (**(code **)(*piVar4 + 0x140))(auStack_13c,1);

      puVar3 = auStack_134;

    }

    else {

      if ((iVar1 != 2) || (*(int *)(unaff_ESI + 0x538) == 0)) goto LAB_008f1551;

      if (*DAT_00d1da30 == -1) {

        local_100 = (char  [4])s_Clan_Member_00a38470._0_4_;

        local_fc = (char  [4])s_Clan_Member_00a38470._4_4_;

        local_f8._0_4_ = s_Clan_Member_00a38470._8_4_;

      }

      else {

        piStack_14c = DAT_00d1da30 + 1;

        uStack_150 = 0xffffffff;

        pcVar5 = "Clan Member";

        FUN_007a69d0("Clan Member");

        uStack_150 = FUN_007a6de0(pcVar5);

        sprintf(local_100,"%s: %s");

      }

      piStack_14c = (int *)0x1;

      uStack_150 = 0x8f132a;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1b0))();

      uStack_150 = 1;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1d8))(auStack_104,1);

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x34c))();

      piVar4 = *(int **)(unaff_ESI + 0x538);

      iVar1 = (**(code **)(*piVar4 + 0x140))(&stack0xfffffeb8,1);

      iVar2 = (**(code **)(*piVar4 + 0x204))(auStack_130);

      if (*(int *)(iVar1 + 4) < *(int *)(iVar2 + 4)) {

        (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1b0))(10);

        (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1d8))(auStack_120,1,0);

      }

      piVar4 = *(int **)(unaff_ESI + 0x538);

      iVar1 = (**(code **)(*piVar4 + 0x140))(&stack0xfffffebc,1);

      puVar3 = auStack_12c;

    }

    iVar2 = (**(code **)(*piVar4 + 0x204))(puVar3);

    if (*(int *)(iVar1 + 4) < *(int *)(iVar2 + 4)) {

      piStack_14c = (int *)0x2;

      uStack_150 = 0x8f13ea;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1b0))();

      uStack_150 = 0;

      (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x1d8))(auStack_104,1);

    }

  }

LAB_008f1551:

  if (*(int *)(unaff_ESI + 0x538) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x538) + 0x34c))();

  }

  return;

}
