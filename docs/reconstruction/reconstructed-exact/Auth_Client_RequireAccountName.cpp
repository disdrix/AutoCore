// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_008c92b0.
//  - Strings: "You need to specify your Account Name!".
//  - Return sites: 2.

// =============================================================================
// Auth_Client_RequireAccountName
// -----------------------------------------------------------------------------
// Purpose:  Login form validation: if account-name field is empty/null, show 'You need to specify your Account Name!' and return failure so login does not proceed.
//
// Address:  0x008c92b0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008c92b0
// System:   auth-login
//
// Evidence strings (from raw decompile):
//   - "You need to specify your Account Name!"
//
// Notable callees:
//   - FUN_007a69d0
//   - FUN_007a6de0
//   - FUN_007fdfb0
//
// Notes:    Returns 0 fail / 1 ok. Uses client field at +0x590 vtbl text getters.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

uint32_t /* width from decompiler */ Auth_Client_RequireAccountName(void)



{

  int iVar1;

  char *pcVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  if (*(int *)(unaff_ESI + 0x590) != 0) {

    iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x590) + 0x1dc))();

    if (iVar1 != 0) {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x590) + 0x1dc))();

      if (*pcVar2 != '\0') {

        return 1;

      }

    }

    uVar6 = 0;

    uVar5 = 1;

    uVar4 = 0xffffffff;

    uVar3 = 0xffffffff;

    pcVar2 = "You need to specify your Account Name!";

    FUN_007a69d0("You need to specify your Account Name!",0xffffffff,0xffffffff,1,0);

    uVar3 = FUN_007a6de0(pcVar2,uVar3);

    FUN_007fdfb0(&DAT_00d1a840,uVar3,uVar4,uVar5,uVar6);

  }

  return 0;

}
