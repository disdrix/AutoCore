// =============================================================================
// UI_qb_btn_slot_off_008e3f20
// -----------------------------------------------------------------------------
// Stable ID: aa_008e3f20
// Address:   0x008e3f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for UI_qb_btn_slot_off_008e3f20 @ 0x008e3f20
// Stable ID: aa_008e3f20
// Embedded strings (evidence for future rename):
//   - "i_d_qb_2d_btn_slot_off.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×1.
//  - Notable callees: UI_qb_btn_slot_off_008e3f20.
//  - Strings: "i_d_qb_2d_btn_slot_off.dds".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_d_qb_2d_btn_slot_off.dds"
 * Domain alias of FUN_008e3f20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void UI_qb_btn_slot_off_008e3f20(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uStack_104;

  

  iVar1 = (**(code **)(*param_2 + 700))();

  if (((iVar1 == 0) || (*(char *)(param_1 + 0x7e3) != '\0')) &&

     (*(int *)(DAT_00d1b6d8 + 0xcd0) == 0)) {

    iVar1 = *param_2;

    pcVar3 = "i_d_qb_2d_btn_slot_off.dds";

    puVar4 = &uStack_104;

    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

      pcVar3 = pcVar3 + 4;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = *(uint16_t *)pcVar3;

    *(char *)((int)puVar4 + 2) = pcVar3[2];

    (**(code **)(iVar1 + 0x50))(&uStack_104,1,0);

    (**(code **)(*param_2 + 0x15c))(0,&stack0xfffffeec);

    (**(code **)(*param_2 + 0x2c4))();

  }

  if (*(char *)(param_1 + 0x7e2) == '\0') {

    iVar1 = *param_2;

    pcVar3 = "i_d_qb_2d_btn_slot_off.dds";

    puVar4 = &uStack_104;

    for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar4 = *(uint32_t /* width from decompiler */ *)pcVar3;

      pcVar3 = pcVar3 + 4;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = *(uint16_t *)pcVar3;

    *(char *)((int)puVar4 + 2) = pcVar3[2];

    (**(code **)(iVar1 + 0x50))(&uStack_104,1,0);

    (**(code **)(*param_2 + 0x15c))(0,&stack0xfffffeec);

    (**(code **)(*param_2 + 0x2c4))();

  }

  return;

}
