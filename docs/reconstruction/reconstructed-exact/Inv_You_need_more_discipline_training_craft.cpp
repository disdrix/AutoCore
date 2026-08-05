// =============================================================================
// Inv_You_need_more_discipline_training_craft
// -----------------------------------------------------------------------------
// Stable ID: aa_008e3820
// Address:   0x008e3820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Inv_You_need_more_discipline_training_craft @ 0x008e3820
// Stable ID: aa_008e3820
// Embedded strings (evidence for future rename):
//   - "You need more discipline training to craft this item!"
//   - "Requires at least %d discipline in %s to craft this!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007a69d0×2, FUN_007a6de0×2, sprintf×2, FUN_00403450, FUN_0052b040, Inv_You_need_more_discipline_training_craft, block.
//  - Strings: "You need more discipline training to craft this item!"; "Requires at least %d discipline in %s to craft this!".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "You need more discipline training to craft this item!"
 * Domain alias of FUN_008e3820 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x008e391b) */



void __fastcall Inv_You_need_more_discipline_training_craft(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *unaff_EDI;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t *puVar6;

  uint8_t local_288 [128];

  uint8_t local_208 [42];

  uint8_t auStack_1de [466];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009abccc;

  local_c = ExceptionList;

  if ((unaff_EDI != (char *)0x0) && (param_1 != 0)) {

    ExceptionList = &local_c;

    cVar2 = FUN_0052b040(*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x4ac),

                         local_208);

    if (cVar2 == '\0') {

      sprintf(unaff_EDI,"You need more discipline training to craft this item!");

      ExceptionList = local_c;

      return;

    }

    uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xa8) + 0x3c) + 0x4b0);

    puVar6 = local_288;

    uVar3 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(auStack_1de,uVar3);

    uStack_4 = 0;

    uVar3 = 0xffffffff;

    FUN_007a69d0(puVar6,0xffffffff);

    uVar3 = FUN_007a6de0(puVar6,uVar3);

    uVar5 = 0xffffffff;

    pcVar4 = "Requires at least %d discipline in %s to craft this!";

    FUN_007a69d0("Requires at least %d discipline in %s to craft this!",0xffffffff,uVar1,uVar3);

    pcVar4 = (char *)FUN_007a6de0(pcVar4,uVar5);

    sprintf(unaff_EDI,pcVar4);

  }

  ExceptionList = local_c;

  return;

}
