// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080fea0, FUN_00920050, FUN_00937560.
//  - Return sites: 2.

// =============================================================================
// Auth_Client_NotifyServerNotAcceptingLogins
// -----------------------------------------------------------------------------
// Purpose:  Client path when the auth/game server refuses new logins: localizes and displays 'The server is not accepting logins...' then returns to an appropriate pre-login screen.
//
// Address:  0x0080fea0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080fea0
// System:   auth-login
//
// Evidence strings (from raw decompile):
//   - "The server is not accepting logins at this time. Please try again in a few moments..."
//
// Notable callees:
//   - FUN_007a69d0 / FUN_007a6de0 / FUN_007fdfb0
//   - FUN_00937560 / FUN_00920050 (screen/nav)
//
// Notes:    Auth UX gate; pairs with account-name and unknown-account handlers.
//
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential verification: OPEN.
// Human rename: 2026-07-23 (string-driven + manual plate).
// =============================================================================

void Auth_Client_NotifyServerNotAcceptingLogins(int param_1)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a69d0();

  if (*(char *)(param_1 + 4) == '\0') {

    uVar4 = 0;

    uVar3 = 1;

    uVar2 = 0xffffffff;

    uVar1 = FUN_007a6de0("The server is not accepting logins at this time. Please try again in a few moments..."

                         ,0xffffffff);

    FUN_007fdfb0(in_EAX,uVar1,uVar2,uVar3,uVar4);

  }

  else {

    FUN_00937560(in_EAX);

    if (*(int *)(in_EAX + 0xf38) != 0) {

      FUN_00920050();

      return;

    }

  }

  return;

}
