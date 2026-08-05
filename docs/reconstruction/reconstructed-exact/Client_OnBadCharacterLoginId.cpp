// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: Client_GetMissionCompleteAudioTable×2, FUN_009313e0×2, FUN_007246d0, FUN_007290e0, FUN_007a4480, FUN_00920050, FUN_00937560, FUN_009493c0.
//  - Strings: "Bad character ID on attempted login.".
//  - Return sites: 4.

// =============================================================================
// Client_OnBadCharacterLoginId
// -----------------------------------------------------------------------------
// Purpose:  Rejects play/login when character ID is invalid.
//
// Address:  0x009494c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_009494c0
// System:   auth
//
// String evidence: "Bad character ID on attempted login."
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_009494c0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_009494c0 using string evidence: "Bad character ID on attempted login."
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void __fastcall Client_OnBadCharacterLoginId(int param_1)

{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int in_EAX;

  int iVar4;

  

  if ((0xb < in_EAX) || (in_EAX < 0)) {

    FUN_007a4480(1,"Bad character ID on attempted login.");

    return;

  }

  *(int *)(param_1 + 0x140) = in_EAX;

  *(uint8_t *)(param_1 + 0x31e8) = 0;

  *(uint8_t *)(param_1 + 0x31e9) = 0;

  *(uint8_t *)(param_1 + 0x31ea) = 0;

  *(uint8_t *)(param_1 + 0x31f4) = 0;

  if (*(int *)(param_1 + 0xe9c + in_EAX * 4) != 0) {

    iVar4 = *(int *)(param_1 + 0xe9c + in_EAX * 4);

    iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + iVar4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = uVar2;

    uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + iVar4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = uVar3;

    iVar4 = Client_GetMissionCompleteAudioTable();

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c0) = uVar2;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c4) = uVar3;

  }

  if (*(int *)(param_1 + 0xcc) != 0) {

    FUN_007290e0(*(int *)(param_1 + 0xcc));

  }

  iVar4 = *(int *)(param_1 + 0xc0);

  if (iVar4 != 0) {

    if (iVar4 == 1) {

      FUN_00937560(param_1);

      if (*(int *)(param_1 + 0xf38) != 0) {

        FUN_00920050();

      }

      FUN_009493c0();

      return;

    }

    if (iVar4 == 2) {

      FUN_009313e0();

      return;

    }

  }

  FUN_009313e0();

  Client_GetMissionCompleteAudioTable();

  FUN_007246d0();

  return;

}
