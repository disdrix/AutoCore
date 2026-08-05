// =============================================================================
// StdList_BuyNode_Dword  (FUN_006759b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_006759b0
// Address:   0x006759b0  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list node helper
// Generated: 2026-07-29 W20-M dual seal (prior scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE: Allocate a 0xC-byte MSVC-style list node and initialize:
//   +0x00 = link0, +0x04 = link1, +0x08 = *pValue (dword).
// Returns the node pointer in EAX (0 if operator_new fails).
//
// ABI: __stdcall, ret 0xC (three stack args). Callee: operator_new only.
// Body range: 0x006759b0 .. 0x006759d6 (39 B). Hex seal:
//   6a0c e8.. 83c404 85c0 7416 8b4c2404 8b542408 8908 8b4c240c
//   895004 8b11 895008 c20c00
//
// RELATED (context, not this unit):
//   - StdList_PushPayloadNode 0x00480350 (size++ + link after buy)
//   - Auth / sound / UI list inserts (many CALL xrefs)
//   - Prior auto alias Named_CalleeOf_Auth_AuthServer_006759b0 (misleading domain)
//

#include <cstdint>

// Exact CF: operator_new(0xC); if non-null fill three dwords; return node*.
void *StdList_BuyNode_Dword(void *link0, void *link1, uint32_t *pValue)
{
  uint32_t *node = (uint32_t *)operator_new(0xC);
  if (node != nullptr) {
    node[0] = (uint32_t)(uintptr_t)link0;
    node[1] = (uint32_t)(uintptr_t)link1;
    node[2] = *pValue;
  }
  return node;
}

// Ghidra symbol alias (decompiler typed void; EAX still holds node*)
void FUN_006759b0(uint32_t param_1, uint32_t param_2, uint32_t *param_3)
{
  uint32_t *puVar1;

  puVar1 = (uint32_t *)operator_new(0xC);
  if (puVar1 != nullptr) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
  }
  return;
}
