// =============================================================================
// FUN_0080e4c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080e4c0
// Address:   0x0080e4c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080e4c0 @ 0x0080e4c0
// Stable ID: aa_0080e4c0
// Embedded strings (evidence for future rename):
//   - "Error opening Refinery, either character or refinery don\'t exist."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007fca10×2, Client_RefreshOpenMissionUiWindows, FUN_00691630, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080e4c0.
//  - Return sites: 3.

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

void FUN_0080e4c0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  FUN_007a69d0();

  if (*(char *)(unaff_EDI + 0x18) != '\0') {

    iVar1 = *(int *)(in_EAX + 0xe98);

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    if ((*(int *)(unaff_EDI + 8) == *(int *)(iVar2 + 0x164 + iVar1)) &&

       (*(int *)(unaff_EDI + 0xc) == *(int *)(iVar2 + 0x168 + iVar1))) {

      if (*(int *)(in_EAX + 0x1054) == 0) {

        return;

      }

      FUN_007fca10();

      if (*(int *)(*(int *)(in_EAX + 0x1040) + 0x528) == 0) {

        FUN_007fca10();

      }

      Client_RefreshOpenMissionUiWindows(in_EAX);

      FUN_00691630();

      return;

    }

  }

  uVar6 = 0;

  uVar5 = 1;

  uVar4 = 0xffffffff;

  uVar3 = FUN_007a6de0("Error opening Refinery, either character or refinery don\'t exist.",

                       0xffffffff);

  FUN_007fdfb0(in_EAX,uVar3,uVar4,uVar5,uVar6);

  return;

}
