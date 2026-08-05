// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_0091f1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091f1f0
// Callee of Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i
// Address:   0x0091f1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i: mission/objective helper. Evidence string: "Already contacting INC!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Already contacting INC!"
//   - "Cannot process while in Hazard Mode!"
//   - "Cannot process while in town!"
//   - "Cannot process while in an arena!"
//   - "Cannot process under your current status!"
//   - "Cannot process while frozen by GM!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×15, goto×9, while×5, return×3, do×1, for×1.
//  - Notable callees: FUN_007a6de0×2, FUN_008f8200×2, FUN_005134e0, FUN_007a69d0, FUN_007fb690, FUN_0091f1f0, GetTickCount, sprintf.
//  - Strings: "Already contacting INC!"; "Cannot process while in Hazard Mode!"; "Cannot process while in town!"; "Cannot process while in an arena!".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i
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

void Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_0091f1f0(int param_1)



{

  uint uVar1;

  char cVar2;

  int iVar3;

  DWORD DVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  int unaff_ESI;

  char *pcVar7;

  char acStack_100 [256];

  

  FUN_007a69d0();

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (0 < *(int *)(unaff_ESI + 0xc24)) {

    pcVar7 = "Already contacting INC!";

    goto LAB_0091f496;

  }

  if (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0') {

    pcVar7 = "Cannot process while in Hazard Mode!";

    goto LAB_0091f496;

  }

  if ((*(char *)(DAT_00d1b644 + 0xf5) != '\0') && (param_1 != 2)) {

    pcVar7 = "Cannot process while in town!";

    goto LAB_0091f496;

  }

  if (*(char *)(DAT_00d1b644 + 0xf6) != '\0') {

    pcVar7 = "Cannot process while in an arena!";

    goto LAB_0091f496;

  }

  iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x19c

                      ))();

  if ((iVar3 != 0) &&

     (iVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x19c))(),

     (*(uint *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0x180 + iVar3) >> 3 & 1) == 0)) {

    (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x19c))();

    cVar2 = FUN_005134e0();

    if (cVar2 == '\0') {

      uVar1 = *(uint *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xb8 + DAT_00d1b6d8);

      if ((uVar1 & 0xc2) != 0) {

        pcVar7 = "Cannot process under your current status!";

        goto LAB_0091f496;

      }

      if ((uVar1 & 1) != 0) {

        pcVar7 = "Cannot process while frozen by GM!";

        goto LAB_0091f496;

      }

      if (((DAT_00d1b960 != (int *)0x0) &&

          (cVar2 = (**(code **)(*DAT_00d1b960 + 0x3d8))(), cVar2 != '\0')) &&

         (cVar2 = (**(code **)(*DAT_00d1b960 + 0xd0))(), cVar2 != '\0')) {

        pcVar7 = "Cannot contact INC right now!";

        goto LAB_0091f496;

      }

      DVar4 = GetTickCount();

      *(DWORD *)(unaff_ESI + 0xc20) = DVar4;

      *(int *)(unaff_ESI + 0xc30) = param_1;

      if (param_1 == 0) {

LAB_0091f36c:

        uVar6 = 10000;

      }

      else {

        if (param_1 != 1) {

          if (param_1 != 2) goto LAB_0091f37d;

          goto LAB_0091f36c;

        }

        uVar6 = 5000;

      }

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc24) = uVar6;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc28) = uVar6;

LAB_0091f37d:

      uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x1b0))();

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc2c) = uVar6;

      puVar5 = (uint32_t /* width from decompiler */ *)

               (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                           0x1a0))();

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc40) = *puVar5;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc44) = puVar5[1];

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc48) = puVar5[2];

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc4c) = puVar5[3];

      iVar3 = *(int *)(unaff_ESI + 0xc24) / 1000;

      pcVar7 = (char *)FUN_007a6de0("Contacting INC... Please do nothing for %d seconds!",0xffffffff

                                   );

      sprintf(acStack_100,pcVar7,iVar3);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,acStack_100,0);

      }

      FUN_007fb690(0,(float)*(int *)(unaff_ESI + 0xc24) * g_flMsToSeconds_Inferred,0,

                   "Contacting INC...",DAT_00afdf08,DAT_00afdef0,0,0);

      return;

    }

  }

  pcVar7 = "Cannot process while invisible!";

LAB_0091f496:

  uVar6 = FUN_007a6de0(pcVar7,0xffffffff);

  if (DAT_00d1b8dc != 0) {

    FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar6,0);

  }

  return;

}
