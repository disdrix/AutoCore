// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0067b110×2, FUN_0046e280, FUN_0046f620, FUN_0067ba30, FUN_00727c00, FUN_007290e0, closesocket, shutdown.
//  - Strings: "[Closing TCP Connection]"; "AuthServer".
//  - Return sites: 2.

// =============================================================================
// AuthClient_CloseTcpConnection
// -----------------------------------------------------------------------------
// Purpose:  Closes Auth TCP connection and traces '[Closing TCP Connection]'.
//
// Address:  0x007290e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_007290e0
// System:   auth
//
// String evidence: "[Closing TCP Connection]","AuthServer"
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_007290e0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_007290e0 using string evidence: "[Closing TCP Connection]","AuthServer"
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

uint32_t /* width from decompiler */ AuthClient_CloseTcpConnection(int param_1)

{

  SOCKET *pSVar1;

  bool bVar2;

  bool bVar3;

  uint8_t local_2c [16];

  uint8_t local_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af5a8;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x1c) != 0) {

    if ((*(int **)(param_1 + 0x30) == (int *)0x0) || (**(int **)(param_1 + 0x30) == -1)) {

      ExceptionList = &local_c;

      FUN_0046e280(local_2c);

      local_4 = 1;

      bVar3 = false;

      bVar2 = true;

    }

    else {

      ExceptionList = &local_c;

      FUN_0067ba30(local_1c);

      local_4 = 0;

      bVar3 = true;

      bVar2 = false;

    }

    FUN_00727c00("[Closing TCP Connection]","AuthServer");

    local_4 = 0;

    if (bVar2) {

      FUN_0067b110();

    }

    local_4 = 0xffffffff;

    if (bVar3) {

      FUN_0067b110();

    }

    pSVar1 = *(SOCKET **)(param_1 + 0x34);

    if (pSVar1 != (SOCKET *)0x0) {

      if (*pSVar1 != 0xffffffff) {

        shutdown(*pSVar1,2);

        closesocket(*pSVar1);

        *pSVar1 = 0xffffffff;

      }

      FUN_0046f620();

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x30));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  return 0;

}
