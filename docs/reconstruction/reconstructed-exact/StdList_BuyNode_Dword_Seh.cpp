// =============================================================================
// StdList_BuyNode_Dword_Seh  (FUN_00418700)
// -----------------------------------------------------------------------------
// Stable ID: aa_00418700
// Address:   0x00418700  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list node helper (SEH-framed)
// Generated: 2026-08-05 MEGA-081 dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Allocate a 0xC-byte MSVC-style list node and initialize:
//   +0x00 = link0, +0x04 = link1, +0x08 = *pValue (dword).
// Returns the node pointer in EAX (0 if operator_new fails).
//
// ABI: __stdcall, ret 0xC (three stack args). Callee: operator_new only (normal path).
// Body range: 0x00418700 .. 0x00418779 (122 B / 0x7A) including SEH frame.
//
// RELATED (context, not this unit):
//   - Twin non-SEH: StdList_BuyNode_Dword @ 0x006759b0 (dualed W20-M)
//   - Incsize peer: FUN_00404840 ("list<T> too long") used by insert wrappers
//   - Prior auto alias Named_CalleeOf_Client_DebugListMissionsStatus_00418700 (retired)
//
// Hex seal (body through RET 0xC):
//   558bec6aff6831c39b0064a100000000506489250000000083ec105356578965f0
//   6a0ce8....83c4048945ecc745fc000000008945e8c645fc0185c074178b4d08
//   89088b550c8950048b4d108b118950088bc8eb0233c9894de4c645fc00c745fc
//   ffffffff8b4df464890d000000005f5e5b8be55dc20c00
//

#include <cstdint>

// Exact CF: SEH setup; operator_new(0xC); if non-null fill three dwords; return node*.
// Decompiler prints void; machine return is EAX (call sites MOV reg,EAX after CALL).
void *StdList_BuyNode_Dword_Seh(void *link0, void *link1, uint32_t *pValue)
{
  // SEH: local_8=-1; puStack_c=&LAB_009bc331; link ExceptionList (omitted as CRT frame)
  uint32_t *node = (uint32_t *)operator_new(0xC);
  if (node != nullptr) {
    node[0] = (uint32_t)(uintptr_t)link0;
    node[1] = (uint32_t)(uintptr_t)link1;
    node[2] = *pValue;
  }
  return node; // EAX
}

// Ghidra symbol alias (decompiler typed void; EAX still holds node*)
void FUN_00418700(uint32_t param_1, uint32_t param_2, uint32_t *param_3)
{
  uint32_t *puVar1;

  // SEH frame present in binary (LAB_009bc331); elided here as non-behavioral for success path
  puVar1 = (uint32_t *)operator_new(0xC);
  if (puVar1 != nullptr) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
  }
  return; // EAX = puVar1 (or 0)
}
