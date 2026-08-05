// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: CVOGCharacter_SetQuickBarItem, RE, itemCoid.
//  - Return sites: 1.

// =============================================================================
// CVOGCharacter_SetQuickBarItem
// -----------------------------------------------------------------------------
// Purpose:  Bind one quick-bar item COID (int64) on the local player character
//           and mark quick-bar state dirty. No-op when slot >= 100.
//
// Address:  0x00520890  (autoassault.exe, image base 0x400000)
// Stable:   aa_00520890
// System:   skills-abilities  (quick-bar shared with inventory UI)
//
// Convention: __thiscall (this = CVOGCharacter*). RET 0xC
//             (slot + valueLo + valueHi).
//
// Layout:
//   this+0x930 + slot*8  = int64 itemCoid   (-1 / both halves FFFFFFFF = empty)
//   this+0x634          |= 2                dirty bit for quick-bar state
//
// Control flow summary:
//   1) if slot < 100: store lo @ +0x930+slot*8, hi @ +0x934+slot*8; OR dirty
//   2) return
//
// Callers / producers:
//   Client_RecvCreateCharacter - CreateCharacterExtended item array at
//     absolute packet offset 0x410 (100 × int64 item COIDs)
//   QuickBar UI clear / assign paths
//
// Related: CVOGCharacter_SetQuickBarSkill @ 0x005208c0 (skill ids @ +0x74c)
// Exactness: Trivial store; CF mirrors raw. Bit-for-bit deferred.
// Dual reviews: not required (trivial setter).
// =============================================================================

#include <cstdint>

/// @param self     CVOGCharacter* (this).
/// @param slot     Quick-bar slot [0, 100).
/// @param valueLo  Item COID low dword.
/// @param valueHi  Item COID high dword.
void __thiscall CVOGCharacter_SetQuickBarItem(void* self, std::uint8_t slot,
                                              unsigned valueLo,
                                              unsigned valueHi)
{
    if (slot < 100) {
        // char+0x930 + slot*8 = itemCoid int64
        *(unsigned*)((int)self + (unsigned)slot * 8 + 0x930) = valueLo;
        *(unsigned*)((int)self + (unsigned)slot * 8 + 0x934) = valueHi;
        *(unsigned*)((int)self + 0x634) =
            *(unsigned*)((int)self + 0x634) | 2u;
    }
    return;
}
