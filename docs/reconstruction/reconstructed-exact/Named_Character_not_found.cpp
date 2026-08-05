// =============================================================================
// Named_Character_not_found
// -----------------------------------------------------------------------------
// Stable ID: aa_0080eeb0
// Address:   0x0080eeb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Character_not_found @ 0x0080eeb0
// Stable ID: aa_0080eeb0
// Embedded strings (evidence for future rename):
//   - "Character not found!"
//   - "has been removed from your ignore list"
//   - "%s %s."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, for×1.
//  - Notable callees: FUN_007a6de0×2, FUN_008f8200×2, FUN_00573a90, FUN_00573ce0, FUN_007a69d0, Named_Character_not_found, __RTDynamicCast, sprintf.
//  - Strings: "Character not found!"; "has been removed from your ignore list"; "%s %s.".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Character not found!"
 * Domain alias of FUN_0080eeb0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Character_not_found(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  if (*(char *)(unaff_ESI + 4) == '\0') {

    uVar2 = FUN_007a6de0("Character not found!",0xffffffff);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar2,0);

    }

  }

  else {

    iVar1 = FUN_00573a90(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc));

    if ((iVar1 != 0) && (*(char *)(iVar1 + 0x10) != '\0')) {

      local_108[0] = '\0';

      local_108[1] = '\0';

      puVar5 = local_106;

      for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar5 = 0;

        puVar5 = puVar5 + 1;

      }

      *(uint16_t *)puVar5 = 0;

      uVar2 = FUN_007a6de0("has been removed from your ignore list",0xffffffff);

      sprintf(local_108,"%s %s.",(char *)(iVar1 + 0x10),uVar2);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

      }

    }

    iVar1 = *(int *)(in_EAX + 0xe98);

    iVar4 = *(int *)(*(int *)(iVar1 + 4) + 4);

    FUN_00573ce0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x164 + iVar1),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + iVar1),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc));

    if (*(int *)(in_EAX + 0x1038) != 0) {

      piVar3 = (int *)__RTDynamicCast(*(int *)(in_EAX + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor,

                                      &CDlgTabsSocial::RTTI_Type_Descriptor,0);

      (**(code **)(*piVar3 + 0x448))();

      return;

    }

  }

  return;

}
