// =============================================================================
// FUN_00934e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00934e00
// Address:   0x00934e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00934e00 @ 0x00934e00
// Stable ID: aa_00934e00
// Embedded strings (evidence for future rename):
//   - "cinema\\intro.bik"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00720d40×2, Client_GetMissionCompleteAudioTable, FUN_00720180, FUN_007209a0, FUN_0075e7e0, FUN_0075ebd0, FUN_0075ec90, FUN_007a69d0.
//  - Strings: "cinema\\intro.bik".
//  - Return sites: 1.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00934e00(void)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_EBP;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  uVar4 = 0;

  uVar6 = 0;

  uVar5 = 0xffffffff;

  FUN_00720d40(0xffffffff,0);

  FUN_00720180(uVar5,uVar6);

  (**(code **)(**(int **)(unaff_EDI + 0x1168) + 4))(0);

  FUN_0075e7e0(0);

  FUN_0075ebd0(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0xde8) + 0x28),0xf,&stack0xfffffff8,0x3f800000,0

              );

  FUN_0075ec90();

  Sleep(0xfa);

  _DAT_00d1a800 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x3188);

  puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_EDI + 0xde8) + 0x28);

  uVar5 = puVar2[1];

  piVar1 = (int *)*puVar2;

  puVar2 = (uint32_t /* width from decompiler */ *)Client_GetMissionCompleteAudioTable();

  DAT_00d17754 = *puVar2;

  DAT_00d17744 = uVar5;

  DAT_00d17748 = piVar1;

  (**(code **)(*piVar1 + 0x38))(piVar1,0,&DAT_00d1774c);

  if (unaff_EBP == 0) {

    iVar3 = FUN_007a69d0();

    if (*(int *)(iVar3 + 0x2c) == 1) {

      uVar4 = 2;

    }

    else if (*(int *)(iVar3 + 0x2c) == 2) {

      uVar4 = 1;

    }

    FUN_009284c0("cinema\\intro.bik",uVar4);

  }

  FUN_00927fe0(1);

  FUN_009282f0();

  (**(code **)(**(int **)(unaff_EDI + 0x1168) + 4))(1);

  uVar5 = 1;

  FUN_00720d40(1);

  FUN_007209a0(uVar5);

  return;

}
