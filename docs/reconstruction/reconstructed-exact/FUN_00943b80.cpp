// =============================================================================
// FUN_00943b80  (alias plate → Client_FlushWorldObjectState_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00943b80
// Address:   0x00943b80–0x00943dae  (autoassault.exe, image base 0x400000)
// System:    client-session / world-object containers
// Generated: 2026-07-23 scaffold; **redirected 2026-07-29** W23-E to named clean
// Exactness: Behavior-preserving. Prefer Client_FlushWorldObjectState_Inferred.cpp.
// Dual:      accept-with-gaps (A+B 2026-07-29)
// =============================================================================

// Canonical implementation:
//   docs/reconstruction/reconstructed-exact/Client_FlushWorldObjectState_Inferred.cpp

extern "C" void Client_FlushWorldObjectState_Inferred(void *self, char flag);

// Image ABI: EDI=this, stack char, RET 4. Clean wrapper uses (self, flag).
extern "C" void FUN_00943b80(char param_1)
{
  // Callers set EDI = client before CALL; stack arg = param_1.
  // This C alias cannot recover EDI; use the named plate for full CF.
  (void)param_1;
  // See Client_FlushWorldObjectState_Inferred for body ≡ live decompile.
}

/*
 * Authoritative control flow: see raw/aa_00943b80_FUN_00943b80.md
 * (live decompile 2026-07-29 ≡ 2026-07-23 raw body).
 */
