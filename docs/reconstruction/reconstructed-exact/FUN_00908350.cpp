// =============================================================================
// FUN_00908350
// -----------------------------------------------------------------------------
// Stable ID: aa_00908350
// Address:   0x00908350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00908350 @ 0x00908350
// Stable ID: aa_00908350
// Embedded strings (evidence for future rename):
//   - "Deposit:"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007a69d0×2, FUN_007a6de0×2, FUN_00513e70, FUN_00907dc0, FUN_00908350, FUN_00977a30, __alldiv.
//  - Strings: "Deposit:".
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

void __fastcall FUN_00908350(int *param_1)



{

  char cVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  int iVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  if (param_1[0x1a3] != 0) {

    cVar1 = (**(code **)(*param_1 + 0x3d8))();

    if (cVar1 != '\0') {

      (**(code **)(*(int *)param_1[0x1a3] + 0x1d8))(0,1,1);

      (**(code **)(*(int *)param_1[0x1a3] + 0x34c))();

      if (in_EAX != (int *)0x0) {

        cVar1 = FUN_00513e70();

        if (cVar1 == '\0') {

          iVar2 = (**(code **)(*in_EAX + 0x168))();

        }

        else {

          iVar2 = (**(code **)(*in_EAX + 0x25c))();

          iVar3 = (**(code **)(*in_EAX + 0x168))();

          iVar2 = iVar2 * iVar3;

        }

        iVar4 = FUN_00907dc0();

        iVar3 = *(int *)param_1[0x1a3];

        uVar6 = 0xffffffff;

        pcVar5 = "Deposit:";

        FUN_007a69d0("Deposit:",0xffffffff);

        uVar6 = FUN_007a6de0(pcVar5,uVar6);

        (**(code **)(iVar3 + 0x250))(uVar6);

        (**(code **)(*(int *)param_1[0x1a3] + 0x250))(&DAT_00a2a000);

        __alldiv((longlong)(iVar4 * 2) * (longlong)iVar2,1000,0);

        FUN_00977a30();

        return;

      }

      iVar2 = *(int *)param_1[0x1a3];

      uVar6 = 0xffffffff;

      pcVar5 = "Deposit:";

      FUN_007a69d0("Deposit:",0xffffffff);

      uVar6 = FUN_007a6de0(pcVar5,uVar6);

      (**(code **)(iVar2 + 0x250))(uVar6);

    }

  }

  return;

}
