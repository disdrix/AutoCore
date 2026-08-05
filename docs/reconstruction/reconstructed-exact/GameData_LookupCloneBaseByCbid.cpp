// =============================================================================
// GameData_LookupCloneBaseByCbid
// -----------------------------------------------------------------------------
// Stable ID: aa_00404d70
// Address:   0x00404d70–0x00404d7a  (autoassault.exe, image base 0x400000)
// System:    clonebase / game data
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - 10-byte tail-call thunk: MOV ECX,[ECX+0xF10]; JMP CNDHash_LookupByKey.
 * - ABI: __thiscall; ECX = game-data host (call sites: DAT_00b041fc); stack uint32 cbid;
 *   RET 4 from Lookup; returns void* clonebase def or NULL in EAX.
 * - Decompiler "void" return is incorrect — callers use EAX.
 * - Sole callee: CNDHash_LookupByKey @ 0x005b0920 (sealed aa_005b0920).
 */

#include <cstdint>

// External (owned / sealed elsewhere)
extern "C" void* __thiscall CNDHash_LookupByKey(void* hash /* ECX */, uint32_t key);

/* GameData_LookupCloneBaseByCbid
   Thin host method: lookup clonebase / item definition by CBID in the hash at this+0xf10.
   Typical call site:
     mov ecx, [DAT_00b041fc]
     push cbid
     call GameData_LookupCloneBaseByCbid
*/

void* __thiscall GameData_LookupCloneBaseByCbid(void* self /* ECX */, uint32_t cbid)
{
  void* hash = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(self) + 0xf10);
  return CNDHash_LookupByKey(hash, cbid);
}
