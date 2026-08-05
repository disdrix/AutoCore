// =============================================================================
// CVOGCharacter_GetResourceBalanceByType  (FUN_0052ada0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052ada0
// Address:   0x0052ada0  (autoassault.exe, image base 0x400000)
// System:    missions-progression (shared resource map; also item-cost / UI)
// Dual:      A/B 2026-07-29 — CF/ABI/map sealed; product English open
// Exactness: Behavior-preserving rewrite of decompiler + assembly-backed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Return character resource/currency balance for typeId from ordered map at
//   char+0x584. Missing type (end sentinel char+0x588) → -1.
//   Mission: CheckMissionRequirements Discipline gate (+0x104 / +0x108).
//
// Convention: MSVC __thiscall
//   ECX  = Character*
//   stack0 = typeId (int)
//   return = balance (int) or -1
//   RET 4

#include <cstdint>

// Ordered-map find: writes matching node or end-sentinel into *outNode.
// Assembly: this=map@+0x584, args = &outNode, &key.
void __thiscall FUN_00418b80(void* mapHeader, void** outNode, int* key);

int __thiscall CVOGCharacter_GetResourceBalanceByType(void* character /*ECX*/, int typeId)
{
    void* node;
    int key;

    key = typeId;
    // Live asm: LEA ECX,[this+0x584]; push &key; push &node; CALL FUN_00418b80
    FUN_00418b80(
        (void*)((std::uint8_t*)character + 0x584),
        &node,
        &key);

    if (node == *(void**)((std::uint8_t*)character + 0x588)) {
        return -1;
    }
    return *(int*)((std::uint8_t*)node + 0x10);
}

// Ghidra symbol alias (scaffold name preserved for xref search)
int __thiscall FUN_0052ada0(void* character, int typeId)
{
    return CVOGCharacter_GetResourceBalanceByType(character, typeId);
}
