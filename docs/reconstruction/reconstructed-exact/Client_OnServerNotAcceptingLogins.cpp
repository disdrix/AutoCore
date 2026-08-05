// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080fea0, FUN_00920050, FUN_00937560.
//  - Return sites: 2.

// =============================================================================
// Client_OnServerNotAcceptingLogins
// -----------------------------------------------------------------------------
// Purpose:  S2C notify: server temporarily not accepting logins.
//
// Address:  0x0080fea0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080fea0
// System:   auth
//
// String evidence: "The server is not accepting logins at this time..."
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0080fea0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0080fea0 using string evidence: "The server is not accepting logins at this time..."
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Client_OnServerNotAcceptingLogins(int param_1)

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
