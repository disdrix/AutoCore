// =============================================================================
// RPC_rpcMsgGuaranteedOrdered_Method1
// -----------------------------------------------------------------------------
// Stable ID: aa_0059e1c0
// Address:   0x0059e1c0  (autoassault.exe, image base 0x400000)
// System:    networking (TNL RPC / NetClassRep)
// Generated: 2026-07-23 scaffold; 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Virtual getClassRep for RPC_TNLConnection_rpcMsgGuaranteedOrdered.
 * - Returns &DAT_00b04f40 — static TNL::NetClassRepInstance for that class.
 * - Class name string @ 0x009d80cc: "RPC_TNLConnection_rpcMsgGuaranteedOrdered".
 * - CRT init @ 0x009c0eb0 calls FUN_005a2410(this=&DAT_00b04f40, name, group=1,
 *   type=2 NetClassTypeEvent, version=0); atexit FUN_009c3de0.
 * - this (ECX) is unused; dispatch is still __thiscall via vtbl 0x009d7c8c slot 0.
 * - No pack/unpack/execute here (see sibling vtbl slots / aa_005a2a50).
 *
 * Dual A/B 2026-07-29: accept (runtime open).
 */

#include <cstdint>

// Ghidra DAT_00b04f40 — static NetClassRepInstance storage (size 0x38).
// Address fixed in retail image; content filled by CRT ClassRep ctor.
extern "C" std::uint8_t DAT_00b04f40[];

// Ghidra name retained as linkage symbol.
extern "C" void* /* NetClassRep* */ RPC_rpcMsgGuaranteedOrdered_Method1(void)
{
  return &DAT_00b04f40[0];
}

// Semantic alias (documentation only — not a second retail symbol):
// TNL::NetClassRep* RPC_TNLConnection_rpcMsgGuaranteedOrdered::getClassRep() const
// { return &dynClassRep; }
