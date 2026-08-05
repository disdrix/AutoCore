// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, goto×1.
//  - Notable callees: CONCAT31×2, FUN_007a6de0×2, FUN_007fdfb0×2, Client_RefreshOpenMissionUiWindows, FUN_0052ace0, FUN_00571010, FUN_00571620, FUN_007a69d0.
//  - Return sites: 5.

// =============================================================================
// Inv_Failed_removing_item_from_refinery_Object_not_found_in_i
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence literal: "Failed removing item from refinery: Object not found in inventory, but was on server."
//           Behavior is preserved from the FUN_0080e360 clean capture; this file
//           is a named entry point for reconstruction indexing and coverage.
//
// Address:  0x0080e360  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080e360
// System:   inventory-transfer
//
// Naming:   Derived from informative string(s) in raw capture under
//           docs/reconstruction/raw/aa_0080e360_*.md
//           Original Ghidra symbol: FUN_0080e360
//
// Exactness: Body mirrors reconstructed-exact/FUN_0080e360*.cpp when present;
//            otherwise a stub plate points at the raw decompile.
//            Control flow and offsets are not invented here.
// =============================================================================

// =============================================================================
// Inv_Failed_removing_item_from_refinery_Object_not_found_in_i
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e360
// Address:   0x0080e360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "Failed removing item from refinery: Object not found in inventory, but was on se"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Inv_Failed_removing_item_from_refinery_Object_not_found_in_i(void)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  int unaff_ESI;

  char *pcVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  

  FUN_007a69d0();

  if (*(char *)(unaff_ESI + 0x20) == '\0') {

    uVar9 = 0;

    uVar8 = 1;

    uVar7 = 0xffffffff;

    uVar3 = FUN_007a6de0("Failed removing item from refinery: Item not in refinery or out of inventory space."

                         ,0xffffffff);

    FUN_007fdfb0(in_EAX,uVar3,uVar7,uVar8,uVar9);

    return;

  }

  if (*(char *)(unaff_ESI + 0x21) == '\0') {

    piVar4 = (int *)CVOGReaction_ResolveObjectTarget

                              (1,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14)

                              );

    if (piVar4 == (int *)0x0) {

      pcVar6 = "Failed removing item from refinery: Object not found on COList.";

    }

    else {

      (**(code **)(*piVar4 + 0x24c))

                (*(uint8_t *)(unaff_ESI + 0x18),*(uint8_t *)(unaff_ESI + 0x19));

      (**(code **)(*piVar4 + 0x260))(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c));

      cVar2 = FUN_00571620(piVar4,CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) >> 8),

                                           *(uint8_t *)(unaff_ESI + 0x18)),

                           CONCAT31((int3)((uint)*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0xe98) + 0x250)

                                          >> 8),*(uint8_t *)(unaff_ESI + 0x19)),

                           *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c));

      if (cVar2 != '\0') goto LAB_0080e3fd;

      pcVar6 = "Failed removing item from refinery: Couldn\'t add item from refinery to inventory.";

    }

  }

  else {

    piVar4 = (int *)FUN_00571010(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14)

                                );

    if (piVar4 != (int *)0x0) {

      iVar1 = *piVar4;

      iVar5 = (**(code **)(iVar1 + 0x25c))();

      (**(code **)(iVar1 + 0x260))(iVar5 + *(int *)(unaff_ESI + 0x1c));

LAB_0080e3fd:

      FUN_0052ace0();

      Client_RefreshOpenMissionUiWindows(in_EAX);

      if (*(int **)(in_EAX + 0x1054) == (int *)0x0) {

        return;

      }

      cVar2 = (**(code **)(**(int **)(in_EAX + 0x1054) + 0xd0))();

      if (cVar2 == '\0') {

        return;

      }

      FUN_0089bf50();

      return;

    }

    pcVar6 = "Failed removing item from refinery: Object not found in inventory, but was on server."

    ;

  }

  uVar9 = 0;

  uVar8 = 1;

  uVar7 = 0xffffffff;

  uVar3 = FUN_007a6de0(pcVar6,0xffffffff);

  FUN_007fdfb0(in_EAX,uVar3,uVar7,uVar8,uVar9);

  return;

}
