// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: CVOGCharacter_SetQuickBarSkill, RE, skillId.
//  - Return sites: 1.

// =============================================================================
// CVOGCharacter_SetQuickBarSkill
// -----------------------------------------------------------------------------
// Purpose:  Bind one quick-bar skill id on the local player character and mark
//           quick-bar state dirty. No-op when slot >= 100.
//
// Address:  0x005208c0  (autoassault.exe, image base 0x400000)
// Stable:   aa_005208c0
// System:   skills-abilities
//
// Convention: __thiscall (this = CVOGCharacter*). RET 0x8 (slot + skillId).
//
// Layout:
//   this+0x74c + slot*4  = int32 skillId   (0 or -1 = empty depending on path)
//   this+0x634          |= 2               dirty bit for quick-bar state
//
// Control flow summary:
//   1) if slot < 100: store skillId; OR dirty bit 2 at +0x634
//   2) return
//
// Callers / producers:
//   Client_RecvCreateCharacter - CreateCharacterExtended skill array at
//     absolute packet offset 0x730 (100 × int32)
//   QuickBar UI assign / clear paths
//   Client_SendQuickBarUpdate* siblings may round-trip this state
//
// Empty-check note (auto-map): skillId == -1 AND item COID both half-words
//   == 0xFFFFFFFF (see CVOGCharacter_SetQuickBarItem).
//
// Exactness: Trivial store; CF mirrors raw. Bit-for-bit deferred.
// Dual reviews: not required (trivial setter; sibling of SetQuickBarItem).
// =============================================================================

#include <cstdint>

/// @param self     CVOGCharacter* (this).
/// @param slot     Quick-bar slot [0, 100).
/// @param skillId  Skill id to bind (0 / -1 empty per producer).
void __thiscall CVOGCharacter_SetQuickBarSkill(void* self, std::uint8_t slot,
                                               int skillId)
{
    if (slot < 100) {
        // char+0x74c + slot*4 = skillId
        *(int*)((int)self + (unsigned)slot * 4 + 0x74c) = skillId;
        *(unsigned*)((int)self + 0x634) =
            *(unsigned*)((int)self + 0x634) | 2u;
    }
    return;
}
