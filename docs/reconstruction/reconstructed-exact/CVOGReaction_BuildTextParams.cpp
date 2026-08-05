// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGReaction_BuildTextParams, FUN_004e29c0, FUN_004e29f0.
//  - Return sites: 1.

// =============================================================================
// CVOGReaction_BuildTextParams
// -----------------------------------------------------------------------------
// Purpose:  Insert one text-parameter node into a doubly-linked list rooted
//           at this+0x04 (std::list-like head). Used when reaction dialog /
//           toast code builds substitution parameter chains.
//
// Address:  0x004e4870  (autoassault.exe, image base 0x400000)
// Stable:   aa_004e4870
// System:   missions-progression  (reaction text / dialog params)
//
// Convention: MSVC __thiscall  (this = list host; param = payload)
// Returns:    void
//
// List head at this+0x04:
//   FUN_004e29c0(head, head->next, payload)  → new node
//   FUN_004e29f0(1)                           → post-insert hook (count/ref?)
//   head->next = newNode; newNode->prev link fixed via **(node+4) = node
//
// Exactness: Behavior-preserving decompiler CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// Human-refined: 2026-07-23 (priority_012)
// =============================================================================

#include <cstdint>

// Allocate/link a list node after `pAfter` under head `pHead`, carrying payload.
extern "C" int FUN_004e29c0(int pHead, std::uint32_t pAfter, std::uint32_t payload);

// Post-insert side effect (arg always 1 at this call site).
extern "C" void FUN_004e29f0(int nFlag);

/// @param thisListHost  Object whose +0x04 is the list head pointer.
/// @param payload       Parameter value / string-id blob (undefined4 in decomp).
void __thiscall CVOGReaction_BuildTextParams(int thisListHost, std::uint32_t payload)
{
    int pHead = *reinterpret_cast<int*>(thisListHost + 4);
    // Insert after current head->next successor pointer at head+4
    int pNewNode = FUN_004e29c0(
        pHead,
        *reinterpret_cast<std::uint32_t*>(pHead + 4),
        payload);
    FUN_004e29f0(1);
    *reinterpret_cast<int*>(pHead + 4) = pNewNode;
    // Fix predecessor link: **(newNode+4) = newNode  (circular / bi-dir list)
    **reinterpret_cast<int**>(pNewNode + 4) = pNewNode;
}
