// =============================================================================
// FUN_0080efe0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080efe0
// Address:   0x0080efe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080efe0 @ 0x0080efe0
// Stable ID: aa_0080efe0
// Embedded strings (evidence for future rename):
//   - "Character not found!"
//   - "has been added to your ignore list"
//   - "%s %s."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1, for×1.
//  - Notable callees: FUN_007a6de0×2, FUN_008f8200×2, FUN_005740f0, FUN_007a69d0, FUN_0080efe0, __RTDynamicCast, sprintf.
//  - Strings: "Character not found!"; "has been added to your ignore list"; "%s %s.".
//  - Return sites: 2.

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

void __fastcall FUN_0080efe0(int param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *pcVar7;

  int iVar8;

  char local_108 [2];

  uint32_t /* width from decompiler */ local_106 [64];

  

  FUN_007a69d0();

  if (*(char *)(in_EAX + 4) == '\0') {

    uVar6 = FUN_007a6de0("Character not found!",0xffffffff);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar6,0);

    }

  }

  else {

    puVar4 = operator_new(0x28);

    iVar8 = *(int *)(param_1 + 0xe98);

    iVar3 = *(int *)(*(int *)(iVar8 + 4) + 4);

    *puVar4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar8);

    puVar4[1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar8);

    pcVar1 = (char *)(in_EAX + 0x10);

    puVar4[2] = *(uint32_t /* width from decompiler */ *)(in_EAX + 8);

    puVar4[3] = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

    pcVar7 = pcVar1;

    do {

      cVar2 = *pcVar7;

      pcVar7[(int)puVar4 + (0x10 - (int)pcVar1)] = cVar2;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    FUN_005740f0(puVar4);

    if (*(int *)(param_1 + 0x1038) != 0) {

      piVar5 = (int *)__RTDynamicCast(*(int *)(param_1 + 0x1038),0,&CVOGDialog::RTTI_Type_Descriptor

                                      ,&CDlgTabsSocial::RTTI_Type_Descriptor,0);

      (**(code **)(*piVar5 + 0x448))();

    }

    local_108[0] = '\0';

    local_108[1] = '\0';

    puVar4 = local_106;

    for (iVar8 = 0x3f; iVar8 != 0; iVar8 = iVar8 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *(uint16_t *)puVar4 = 0;

    uVar6 = FUN_007a6de0("has been added to your ignore list",0xffffffff);

    sprintf(local_108,"%s %s.",pcVar1,uVar6);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_108,0);

      return;

    }

  }

  return;

}
