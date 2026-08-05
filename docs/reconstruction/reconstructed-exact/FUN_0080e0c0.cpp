// =============================================================================
// FUN_0080e0c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e0c0
// Address:   0x0080e0c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080e0c0 @ 0x0080e0c0
// Stable ID: aa_0080e0c0
// Embedded strings (evidence for future rename):
//   - "Unable to add to Experimentation."
//   - "Unable to add to Reverse Engineering."
//   - "Unable to add to Memorization."
//   - "Unable to add to Tinkering."
//   - "RND Add Failed."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×4, goto×3, return×2, switch×1.
//  - Notable callees: Client_RefreshOpenMissionUiWindows×2, Client_RefreshMissionDialogChrome, FUN_00531960, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080e0c0.
//  - Strings: "Unable to add to Experimentation."; "Unable to add to Reverse Engineering."; "Unable to add to Memorization."; "Unable to add to Tinkering.".
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

void FUN_0080e0c0(void)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EDI;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  FUN_007a69d0();

  switch(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 4)) {

  case 0:

    if (*(char *)(unaff_EDI + 0xc) != '\0') {

      iVar1 = *(int *)(in_EAX + 0xe98);

      *(char *)(iVar1 + 0x599) = *(char *)(iVar1 + 0x599) + *(char *)(unaff_EDI + 8);

LAB_0080e179:

      *(uint *)(iVar1 + 0x634) = *(uint *)(iVar1 + 0x634) | 0x40;

      FUN_00531960(-*(short *)(unaff_EDI + 8));

      Client_RefreshMissionDialogChrome();

      Client_RefreshOpenMissionUiWindows(in_EAX);

      return;

    }

    pcVar3 = "Unable to add to Experimentation.";

    break;

  case 1:

    if (*(char *)(unaff_EDI + 0xc) != '\0') {

      iVar1 = *(int *)(in_EAX + 0xe98);

      *(char *)(iVar1 + 0x598) = *(char *)(iVar1 + 0x598) + *(char *)(unaff_EDI + 8);

      goto LAB_0080e179;

    }

    pcVar3 = "Unable to add to Reverse Engineering.";

    break;

  case 2:

    if (*(char *)(unaff_EDI + 0xc) != '\0') {

      iVar1 = *(int *)(in_EAX + 0xe98);

      *(char *)(iVar1 + 0x59a) = *(char *)(iVar1 + 0x59a) + *(char *)(unaff_EDI + 8);

      goto LAB_0080e179;

    }

    pcVar3 = "Unable to add to Memorization.";

    break;

  case 3:

    if (*(char *)(unaff_EDI + 0xc) != '\0') {

      iVar1 = *(int *)(in_EAX + 0xe98);

      *(char *)(iVar1 + 0x59b) = *(char *)(iVar1 + 0x59b) + *(char *)(unaff_EDI + 8);

      goto LAB_0080e179;

    }

    pcVar3 = "Unable to add to Tinkering.";

    break;

  default:

    pcVar3 = "RND Add Failed.";

  }

  uVar6 = 0;

  uVar5 = 1;

  uVar4 = 0xffffffff;

  uVar2 = FUN_007a6de0(pcVar3,0xffffffff);

  FUN_007fdfb0(in_EAX,uVar2,uVar4,uVar5,uVar6);

  Client_RefreshOpenMissionUiWindows(in_EAX);

  return;

}
