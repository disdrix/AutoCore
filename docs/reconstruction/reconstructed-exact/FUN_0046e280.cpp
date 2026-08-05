// =============================================================================
// FUN_0046e280  /  Net_SockaddrIn_InitInvalid
// -----------------------------------------------------------------------------
// Stable ID: aa_0046e280
// Address:   0x0046e280  (autoassault.exe, image base 0x400000)
// System:    network / sockaddr_in fill (invalid endpoint)
// Generated: 2026-07-29 (W16-P OWN dual; live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
// Initialize a 16-byte sockaddr_in-layout buffer to the invalid endpoint
//   { sin_family = AF_INET (2),
//     sin_port   = htons(0xFFFF) = 0xFFFF,
//     sin_addr   = 0xFFFFFFFF (INADDR_NONE),
//     rest       = 0 }
// via shared thiscall helper FUN_0067b0a0, then return the same pointer.
//
// Used as a placeholder when no real peer address is available (e.g.
// Client_EncryptAndPrepareAuthRequest when auth-server slot is null/-1).
//
// ABI: __cdecl; one stack arg; returns arg in EAX.

// READABILITY:
//  - Body size: 30 bytes (0046e280–0046e29d) + CC pad.
//  - Callee: FUN_0067b0a0 @ 0x0067b0a0 (thiscall; ret 8).
//  - Constants: both stack args 0xFFFFFFFF.
//  - Decompiler elides ECX; bytes seal mov ecx, esi (esi = param_1).

/*
 * Behavioral notes:
 * - Stack hygiene: mov dword ptr [esp+0xC], 0 overwrites saved-ecx slot before call.
 * - Callee zeros 16 bytes, stores AF_INET, addr, htons(port).
 * - Runtime / differential verification: OPEN.
 */

// Callee @ 0x0067b0a0:
//   undefined4 * __thiscall FUN_0067b0a0(undefined4 *this, undefined4 addr, u_short port);

uint32_t /* width from decompiler */ FUN_0046e280(uint32_t /* width from decompiler */ param_1)
{
  // Sealed: ECX = param_1 before call (thiscall into FUN_0067b0a0).
  // Decompiler text omits ECX; equivalent call:
  //   FUN_0067b0a0(/*this=*/param_1, 0xffffffff, 0xffffffff);
  FUN_0067b0a0(0xffffffff, 0xffffffff);

  return param_1;
}
