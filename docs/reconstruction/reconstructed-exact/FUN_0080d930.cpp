// =============================================================================
// FUN_0080d930
// -----------------------------------------------------------------------------
// Stable ID: aa_0080d930
// Address:   0x0080d930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080d930 @ 0x0080d930
// Stable ID: aa_0080d930
// Embedded strings (evidence for future rename):
//   - "Gadget not found."
//   - "Object to Gadget not found."
//   - "Failed to Gadget object."
//   - "BUG: Server thinks gadgeting worked, can\'t find objects on client."
//   - "BUG: Server thinks gadgeting worked, client can\'t cast gadget properly."
//   - "enhancement_add"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, goto×1.
//  - Notable callees: FUN_00571b60×2, FUN_007a6de0×2, FUN_007fdfb0×2, Client_GetMissionCompleteAudioTable, Client_PlayNamedInterfaceSound, Client_RefreshOpenMissionUiWindows, FUN_00514190, FUN_00571b80.
//  - Strings: "Gadget not found."; "Object to Gadget not found."; "Failed to Gadget object."; "enhancement_add".
//  - Return sites: 4.

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

void FUN_0080d930(void)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  uint32_t /* width from decompiler */ uVar12;

  

  FUN_007a69d0();

  if (*(char *)(in_EAX + 0x2c) == '\0') {

    iVar5 = *(int *)(in_EAX + 0x28);

    if (iVar5 == 1) {

      pcVar9 = "Gadget not found.";

    }

    else if (iVar5 == 2) {

      pcVar9 = "Object to Gadget not found.";

    }

    else {

      if (iVar5 != 3) {

        return;

      }

      pcVar9 = "Failed to Gadget object.";

    }

    uVar8 = 0;

    uVar7 = 1;

    uVar6 = 0xffffffff;

    uVar3 = FUN_007a6de0(pcVar9,0xffffffff);

    FUN_007fdfb0(unaff_ESI,uVar3,uVar6,uVar7,uVar8);

    return;

  }

  piVar4 = (int *)CVOGReaction_ResolveObjectTarget

                            (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x14));

  iVar5 = CVOGReaction_ResolveObjectTarget

                    (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x20),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x24));

  if ((piVar4 == (int *)0x0) || (iVar5 == 0)) {

    pcVar9 = "BUG: Server thinks gadgeting worked, can\'t find objects on client.";

  }

  else {

    iVar5 = (**(code **)(*piVar4 + 0x1fc))();

    if (iVar5 == 0) {

      pcVar9 = "BUG: Server thinks gadgeting worked, client can\'t cast gadget properly.";

    }

    else {

      cVar2 = FUN_00514190(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

      uVar3 = 0;

      if (cVar2 != '\0') {

        uVar12 = 0x1e;

        uVar11 = 0;

        uVar10 = 0;

        uVar8 = 0xffffffff;

        uVar7 = 0xffffffff;

        uVar6 = 0;

        pcVar9 = "enhancement_add";

        Client_GetMissionCompleteAudioTable("enhancement_add",0,0xffffffff,0xffffffff,0,0,0x1e,0);

        Client_PlayNamedInterfaceSound(pcVar9,uVar6,uVar7,uVar8,uVar10,uVar11,uVar12,uVar3);

        if (*(int *)(unaff_ESI + 0xe98) != 0) {

          cVar2 = FUN_00571b60(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

          if (cVar2 == '\0') {

            cVar2 = FUN_00571b60(*(int *)(*(int *)(iVar5 + 4) + 4) + 4 + iVar5);

            if (cVar2 == '\0') goto LAB_0080dad5;

            iVar1 = *(int *)(*(int *)(iVar5 + 4) + 4);

          }

          else {

            iVar1 = *(int *)(*(int *)(iVar5 + 4) + 4);

          }

          FUN_00571b80(iVar1 + 4 + iVar5,1,0);

        }

LAB_0080dad5:

        FUN_00933310(unaff_ESI,1,0,0xffffffff,0xffffffff);

        Client_RefreshOpenMissionUiWindows(unaff_ESI);

        return;

      }

      pcVar9 = "BUG: Gadgeting failed, but Server thinks it worked.";

    }

  }

  uVar8 = 0;

  uVar7 = 1;

  uVar6 = 0xffffffff;

  uVar3 = FUN_007a6de0(pcVar9,0xffffffff);

  FUN_007fdfb0(unaff_ESI,uVar3,uVar6,uVar7,uVar8);

  return;

}
