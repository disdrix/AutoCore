// =============================================================================
// FUN_0080c040
// -----------------------------------------------------------------------------
// Stable ID: aa_0080c040
// Address:   0x0080c040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080c040 @ 0x0080c040
// Stable ID: aa_0080c040
// Embedded strings (evidence for future rename):
//   - "FAILED: Server reports unknown."
//   - "FAILED: Server reports request doesn\'t match."
//   - "FAILED: Server reports don\'t meet requirements."
//   - "FAILED: Server reports not enough money."
//   - "FAILED: Server reports already trained."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, switch×1, goto×1.
//  - Notable callees: FUN_0052ada0, FUN_0052ae30, FUN_00530610, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080c040, FUN_00894290.
//  - Strings: "FAILED: Server reports unknown."; "FAILED: Server reports request doesn\'t match."; "FAILED: Server reports don\'t meet requirements."; "FAILED: Server reports not enough money.".
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

void FUN_0080c040(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EBX;

  int unaff_EDI;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  if (*(int *)(unaff_EDI + 0xe98) != 0) {

    FUN_007a69d0();

    iVar1 = DAT_00d1b8b0;

    if (*(int *)(unaff_EBX + 0x10) != 0) {

      switch(*(int *)(unaff_EBX + 0x10)) {

      case 1:

        pcVar4 = "FAILED: Server reports unknown.";

        break;

      case 2:

        pcVar4 = "FAILED: Server reports request doesn\'t match.";

        break;

      case 3:

        pcVar4 = "FAILED: Server reports don\'t meet requirements.";

        break;

      case 4:

        pcVar4 = "FAILED: Server reports not enough money.";

        break;

      case 5:

        pcVar4 = "FAILED: Server reports already trained.";

        break;

      default:

        goto switchD_0080c0b1_default;

      }

      uVar7 = 0;

      uVar6 = 1;

      uVar5 = 0xffffffff;

      uVar3 = FUN_007a6de0(pcVar4,0xffffffff);

      FUN_007fdfb0(unaff_EDI,uVar3,uVar5,uVar6,uVar7);

      return;

    }

    FUN_00530610(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),1);

    iVar2 = FUN_0052ada0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4));

    if (iVar2 < 1) {

      FUN_0052ae30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc));

    }

    if (iVar1 != 0) {

      FUN_00894c40();

      FUN_00894290();

    }

  }

switchD_0080c0b1_default:

  return;

}
