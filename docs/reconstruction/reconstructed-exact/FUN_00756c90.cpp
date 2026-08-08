// =============================================================================
// FUN_00756c90  (scaffold synonym)
// -----------------------------------------------------------------------------
// Stable ID: aa_00756c90
// Address:   0x00756c90  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (UI tab/group chrome helper)
// Generated: 2026-07-23 scaffold; refined R12-003 2026-08-05 dual seal
// Canonical: UI_Widget_MoveToFrontInParentGroup_Inferred
// Exactness: Behavior-preserving rewrite of decompiler + disasm CF.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual reviews:
//   reviews/A_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md
//   reviews/B_aa_00756c90_UI_Widget_MoveToFrontInParentGroup_Inferred.md
// Named clean: reconstructed-exact/UI_Widget_MoveToFrontInParentGroup_Inferred.cpp
// =============================================================================

#include <cstdint>
#include <cstring>

extern "C" void FUN_00456960(std::uint32_t count_ecx, void* vec_edx, void* insert_pos_stack);

// Retail ABI: widget in EDI; no stack args; EAX return; RET.
// Clean form takes widget* for readability — callers must place EDI.
extern "C" std::uint32_t FUN_00756c90(void* widget /*EDI*/)
{
    auto* w = reinterpret_cast<std::uint8_t*>(widget);
    auto* group = *reinterpret_cast<std::uint8_t**>(w + 0x88);
    if (group == nullptr) {
        return 0xFFFFFFFFu;
    }

    auto** begin = *reinterpret_cast<void***>(group + 0x94);
    auto** end   = *reinterpret_cast<void***>(group + 0x98);

    if (begin != nullptr && (end - begin) == 1) {
        return 0;
    }

    for (auto** p = begin; p != end; ++p) {
        if (*p == widget) {
            std::memmove(p, p + 1,
                         static_cast<std::size_t>(
                             reinterpret_cast<char*>(end) - reinterpret_cast<char*>(p + 1)));
            *reinterpret_cast<void***>(group + 0x98) =
                *reinterpret_cast<void***>(group + 0x98) - 1;
            break;
        }
    }

    begin = *reinterpret_cast<void***>(group + 0x94);
    FUN_00456960(1u, group + 0x90, begin);
    return 0;
}
