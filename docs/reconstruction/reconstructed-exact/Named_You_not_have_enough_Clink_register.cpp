// =============================================================================
// Named_You_not_have_enough_Clink_register
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a970
// Address:   0x0080a970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_You_not_have_enough_Clink_register @ 0x0080a970
// Stable ID: aa_0080a970
// Embedded strings (evidence for future rename):
//   - "has been registered"
//   - "Your clan"
//   - "%s %s %s."
//   - "is not available, please choose another name"
//   - "The clan name"
//   - "You do not have enough Clink to register a clan."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×4, goto×3, for×1, switch×1, do×1, return×1.
//  - Notable callees: FUN_007a6de0×5, FUN_007fdfb0×2, sprintf×2, FUN_007a69d0, FUN_007fca10, FUN_008073b0, Named_You_not_have_enough_Clink_register.
//  - Strings: "has been registered"; "Your clan"; "%s %s %s."; "is not available, please choose another name".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "You do not have enough Clink to register a clan."
 * Domain alias of FUN_0080a970 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_You_not_have_enough_Clink_register(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ local_20c;

  char local_208 [2];

  uint32_t /* width from decompiler */ local_206 [128];

  

  FUN_007a69d0();

  local_208[0] = '\0';

  local_208[1] = '\0';

  puVar4 = local_206;

  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  switch(*(uint32_t /* width from decompiler */ *)(param_1 + 4)) {

  case 0:

    uVar1 = FUN_007a6de0("has been registered",0xffffffff);

    iVar3 = param_1 + 0xc;

    uVar2 = FUN_007a6de0("Your clan",0xffffffff);

    sprintf(local_208,"%s %s %s.",uVar2,iVar3,uVar1);

    FUN_007fdfb0(in_EAX,local_208,0xffffffff,1,0);

    **(uint32_t /* width from decompiler */ **)(in_EAX + 0x31f0) = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

    FUN_007fca10();

    local_20c = 0x803a;

    FUN_008073b0(4,&local_20c);

    goto switchD_0080a9ad_default;

  case 1:

    uVar1 = FUN_007a6de0("is not available, please choose another name",0xffffffff);

    param_1 = param_1 + 0xc;

    uVar2 = FUN_007a6de0("The clan name",0xffffffff);

    sprintf(local_208,"%s %s %s.",uVar2,param_1,uVar1);

    uVar6 = 0;

    uVar2 = 1;

    uVar1 = 0xffffffff;

    pcVar5 = local_208;

    goto LAB_0080aab2;

  case 2:

    pcVar5 = "You do not have enough Clink to register a clan.";

    break;

  case 3:

    pcVar5 = "Your level is insufficient to register a clan.";

    break;

  case 4:

    if (*(char *)(param_1 + 0xc) == '\0') {

      pcVar5 = "You must enter a clan name first!";

    }

    else {

      pcVar5 = "Invalid clan name, please choose another.";

    }

    break;

  default:

    goto switchD_0080a9ad_default;

  }

  uVar6 = 0;

  uVar2 = 1;

  uVar1 = 0xffffffff;

  pcVar5 = (char *)FUN_007a6de0(pcVar5,0xffffffff);

LAB_0080aab2:

  FUN_007fdfb0(in_EAX,pcVar5,uVar1,uVar2,uVar6);

switchD_0080a9ad_default:

  if (*(int *)(in_EAX + 0x1090) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x1090) + 0x448))();

  }

  if (*(int *)(in_EAX + 0x106c) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x106c) + 0x448))();

  }

  if (*(int *)(in_EAX + 0x1038) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x1038) + 0x448))();

  }

  return;

}
