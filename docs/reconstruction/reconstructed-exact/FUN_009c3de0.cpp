// =============================================================================
// FUN_009c3de0  (scaffold alias → atexit_NetClassRep_rpcMsgGuaranteedOrdered)
// -----------------------------------------------------------------------------
// Stable ID: aa_009c3de0
// Address:   0x009c3de0  (autoassault.exe, image base 0x400000)
// System:    networking / TNL ClassRep CRT
// Generated: 2026-07-29 W25-I seal (replaces 2026-07-23 auto scaffold)
// Exactness: Behavior-preserving; bytes = mov ecx,0x00b04f40; jmp FUN_005a2470
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: atexit_NetClassRep_rpcMsgGuaranteedOrdered.cpp
// Dual A/B: accept (W25-I).
// =============================================================================

void FUN_009c3de0(void)
{
  // Baked this for static ClassRep @ 0x00b04f40; tail to dtor
  FUN_005a2470(/*this=*/ (void *)0x00b04f40);
}
