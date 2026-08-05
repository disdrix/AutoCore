// =============================================================================
// Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0046e280
// Alias of FUN_0046e280 / Net_SockaddrIn_InitInvalid
// -----------------------------------------------------------------------------
// Stable ID: aa_0046e280
// Callee of Client_EncryptAndPrepareAuthRequest (+ many other net helpers)
// Address:   0x0046e280  (autoassault.exe, image base 0x400000)
// System:    network / sockaddr_in fill (invalid endpoint)
// Generated: 2026-07-29 (W16-P OWN dual)
// Exactness: Behavior-preserving rewrite. Not modernization.
// =============================================================================

// PURPOSE:
// Auth-client path: when *(client+0x30)==0 or **(client+0x30)==-1, fill a stack
// 16-byte endpoint with AF_INET / INADDR_NONE / port 0xFFFF and continue login prep.
// Same leaf is shared across dozens of net helpers (FUN_0067c*, FUN_00727*–00729*).
// Role is address fill only — not DES/credential crypto (that stays in the parent).

// Identical CF to FUN_0046e280
uint32_t /* width from decompiler */ Named_CalleeOf_Client_EncryptAndPrepareAuthRequest_0046e280(
    uint32_t /* width from decompiler */ param_1)
{
  // Sealed: ECX = param_1 (thiscall into FUN_0067b0a0)
  FUN_0067b0a0(0xffffffff, 0xffffffff);
  return param_1;
}
