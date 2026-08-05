// =============================================================================
// Named_convoy_been_found_you_wish_join
// -----------------------------------------------------------------------------
// Stable ID: aa_0080fa50
// Address:   0x0080fa50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_convoy_been_found_you_wish_join @ 0x0080fa50
// Stable ID: aa_0080fa50
// Embedded strings (evidence for future rename):
//   - "has invited you to join a convoy"
//   - "%s %s."
//   - "A convoy has been found. Do you wish to join?"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_007a6de0×2, FUN_007fdfb0×2, Client_MaybeShowFirstTimeTip, FUN_00573a90, FUN_007a69d0, FUN_008073b0, Named_convoy_been_found_you_wish_join, sprintf.
//  - Strings: "has invited you to join a convoy"; "%s %s."; "A convoy has been found. Do you wish to join?".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "A convoy has been found. Do you wish to join?"
 * Domain alias of FUN_0080fa50 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_convoy_been_found_you_wish_join(int param_1)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ auStack_118 [4];

  uint8_t uStack_107;

  uint32_t /* width from decompiler */ uStack_104;

  char acStack_100 [256];

  

  if ((*(int **)(param_1 + 0x1118) != (int *)0x0) && (*(int *)(param_1 + 0xf40) != 0)) {

    cVar1 = (**(code **)(**(int **)(param_1 + 0x1118) + 0x3d8))();

    if (cVar1 != '\0') {

      auStack_118[0] = 0x8006;

      uStack_104 = 9;

      uStack_107 = 0;

      FUN_008073b0(0x18,auStack_118);

      return;

    }

  }

  FUN_007a69d0();

  iVar2 = FUN_00573a90(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x10),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x14));

  if (iVar2 == 0) {

    pcVar4 = (char *)(in_EAX + 0x18);

    *(uint8_t *)(param_1 + 0x30f4) = 1;

    if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {

      uVar3 = FUN_007a6de0("has invited you to join a convoy",0xffffffff);

      sprintf(acStack_100,"%s %s.",pcVar4,uVar3);

      FUN_007fdfb0(param_1,acStack_100,0x4e2d,1,0);

      Client_MaybeShowFirstTimeTip(0x21);

      return;

    }

    uVar7 = 0;

    uVar6 = 1;

    uVar5 = 0x4e2d;

    uVar3 = FUN_007a6de0("A convoy has been found. Do you wish to join?",0xffffffff);

    FUN_007fdfb0(param_1,uVar3,uVar5,uVar6,uVar7);

  }

  else {

    auStack_118[0] = 0x8006;

    uStack_104 = 9;

    uStack_107 = 0;

    if (*(int **)(param_1 + 0xc7c) != (int *)0x0) {

      cVar1 = (**(code **)(**(int **)(param_1 + 0xc7c) + 8))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(param_1 + 0xc7c) + 0x18))(0xffffffff,auStack_118,0x18,0);

        return;

      }

    }

  }

  return;

}
