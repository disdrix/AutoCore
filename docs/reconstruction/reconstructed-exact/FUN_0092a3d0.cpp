// =============================================================================
// FUN_0092a3d0  (twin of Tracker_ClearOwnedPtrVectorAt11c_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a3d0
// Address:   0x0092a3d0–0x0092a43d  (autoassault.exe, image base 0x400000)
// Size:      110 bytes (0x6E)
// System:    missions-progression
// Sealed:    2026-08-05 MEGA-088 dual
// Named:     Tracker_ClearOwnedPtrVectorAt11c_Inferred
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================
//
// PURPOSE: Clear MissionTracker owned pointer vector at +0x11c (delete elems,
//          end:=begin). See Tracker_ClearOwnedPtrVectorAt11c_Inferred.cpp.
//
// ABI: EDI=tracker; no stack args; AL=1; RET.
// =============================================================================

#include <cstdint>
#include <cstring>

using u8 = std::uint8_t;

void operator_delete(void* p);

u8 FUN_0092a3d0(void* tracker /*EDI*/)
{
    auto* host = reinterpret_cast<u8*>(tracker);

    void** begin = *reinterpret_cast<void***>(host + 0x11c);
    void** end   = *reinterpret_cast<void***>(host + 0x120);

    for (void** p = begin; p != end; ++p) {
        operator_delete(*p);
    }

    void* first = *reinterpret_cast<void**>(host + 0x11c);
    if (first != nullptr) {
        void* last = *reinterpret_cast<void**>(host + 0x120);
        int count = static_cast<int>((reinterpret_cast<char*>(last) -
                                      reinterpret_cast<char*>(first)) >> 2);
        if (count != 0 && first != last) {
            std::size_t nbytes = 0;
            void* moved = std::memmove(first, last, nbytes);
            *reinterpret_cast<void**>(host + 0x120) =
                static_cast<char*>(moved) + nbytes;
        }
    }

    return 1;
}
