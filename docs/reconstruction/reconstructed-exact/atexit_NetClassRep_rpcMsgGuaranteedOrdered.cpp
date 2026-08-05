// =============================================================================
// atexit_NetClassRep_rpcMsgGuaranteedOrdered
// -----------------------------------------------------------------------------
// Purpose:  CRT atexit thunk for the static NetClassRepInstance of
//           RPC_TNLConnection_rpcMsgGuaranteedOrdered. Bakes this =
//           &DAT_00b04f40 and tail-jumps to ClassRep dtor FUN_005a2470
//           (free strdup name; restore base vtbl).
//
// Address:  0x009c3de0  (autoassault.exe, image base 0x400000)
// Body:     0x009c3de0–0x009c3de9 (10 bytes)
// Stable:   aa_009c3de0
// System:   networking / TNL ClassRep CRT
// Ghidra:   FUN_009c3de0
//
// ABI:      atexit callback — no args, no stack cleanup in this unit
//           ECX forced to 0x00b04f40; control does not return here
//
// Exactness: CF mirrors read_memory bytes (mov ecx + jmp). Decompiler
//            "call; return" is equivalent but loses this-binding.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W25-I seal).
// Related:  aa_0059e1c0 getClassRep; FUN_005a2410 ctor; FUN_005a2470 dtor
// =============================================================================

// void __thiscall FUN_005a2470(void* pClassRep);
// extern NetClassRepInstance g_rpcMsgGuaranteedOrdered_ClassRep; // @ 0x00b04f40

/* atexit_NetClassRep_rpcMsgGuaranteedOrdered

   Registered by CRT static init @ 0x009c0eb0 after constructing the ClassRep
   for "RPC_TNLConnection_rpcMsgGuaranteedOrdered" (name @ 0x009d80cc).

   On process exit: run ClassRep dtor on the static object.
*/

void atexit_NetClassRep_rpcMsgGuaranteedOrdered(void)
{
  // mov ecx, 0x00b04f40
  // jmp FUN_005a2470
  FUN_005a2470(/*this=*/ (void *)0x00b04f40);
}
