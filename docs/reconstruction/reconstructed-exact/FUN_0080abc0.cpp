// =============================================================================
// FUN_0080abc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080abc0
// Address:   0x0080abc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080abc0 @ 0x0080abc0
// Stable ID: aa_0080abc0
// Embedded strings (evidence for future rename):
//   - "Invitation request declined: You cannot invite yourself!"
//   - "Invitation request declined: Your convoy is already full."
//   - "Invitation request declined: Player already in a convoy."
//   - "Invitation request was rejected."
//   - "Invitation request declined: You cannot invite an enemy!"
//   - "Invitation request declined: Player already has a convoy pending."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: return×10, if×4, do×2, while×2, switch×1.
//  - Notable callees: FUN_007a6de0×13, FUN_007fdfb0×10, sprintf×2, FUN_007a69d0, FUN_0080abc0.
//  - Strings: "Invitation request declined: You cannot invite yourself!"; "Invitation request declined: Your convoy is already full."; "Invitation request declined: Player already in a convoy."; "Invitation request was rejected.".
//  - Return sites: 10.

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

void FUN_0080abc0(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  void *pvVar4;

  char *pcVar5;

  int unaff_EBX;

  uint32_t /* width from decompiler */ unaff_EDI;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  char local_114 [20];

  char acStack_100 [256];

  

  FUN_007a69d0();

  if (*(char *)(unaff_EBX + 0x10) == '\0') {

    switch(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14)) {

    case 2:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request declined: You cannot invite yourself!",0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    case 3:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request declined: Your convoy is already full.",0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    case 4:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request declined: Player already in a convoy.",0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    default:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request was rejected.",0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    case 6:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request declined: You cannot invite an enemy!",0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    case 7:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request declined: Player already has a convoy pending.",

                           0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    case 8:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request declined: You are currently waiting on a convoy.",

                           0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    case 9:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Invitation request declined: Player is currently busy.",0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    case 10:

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      uVar2 = FUN_007a6de0("Only the leader of the convoy can invite other members.",0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar2,uVar6,uVar7,uVar8);

      return;

    }

  }

  if (*(char *)(unaff_EBX + 0x11) == '\0') {

    pcVar3 = (char *)FUN_007a6de0("Player",0xffffffff);

    pcVar5 = local_114;

    do {

      cVar1 = *pcVar3;

      *pcVar5 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    pvVar4 = Client_LookupObjectByTfid_Inferred

                       (1,*(uint *)(unaff_EBX + 8),*(uint *)(unaff_EBX + 0xc));

    if (pvVar4 != (void *)0x0) {

      pcVar3 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar4 + 4) + 4) + 4 +

                                            (int)pvVar4) + 0x160))();

      pcVar5 = local_114;

      do {

        cVar1 = *pcVar3;

        *pcVar5 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

    }

    if (*(int *)(unaff_EBX + 0x14) == 9) {

      uVar2 = FUN_007a6de0("is currently busy",0xffffffff);

      pcVar5 = local_114;

      uVar6 = FUN_007a6de0("Invitation request declined",0xffffffff);

      sprintf(acStack_100,"%s: %s %s.",uVar6,pcVar5,uVar2);

    }

    else {

      uVar2 = FUN_007a6de0("has declined your convoy invitation",0xffffffff);

      sprintf(acStack_100,"%s %s.",local_114,uVar2);

    }

    FUN_007fdfb0(unaff_EDI,acStack_100,0xffffffff,1,0);

  }

  return;

}
