// =============================================================================
// Tracker_ClearOwnedPtrVectorAt11c_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a3d0
// Address:   0x0092a3d0–0x0092a43d  (autoassault.exe, image base 0x400000)
// Size:      110 bytes (0x6E)
// System:    missions-progression
// Sealed:    2026-08-05 MEGA-088 dual (live decompile + read_memory + call-site asm)
// Exactness: Behavior-preserving rewrite of image control flow. Not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// Ghidra:    FUN_0092a3d0
// =============================================================================
//
// PURPOSE
//   Clear the MissionTracker-family owned pointer vector at host+0x11c:
//   scalar-delete every element, then set end := begin without freeing the buffer.
//   Used by Tracker_SetActiveMissionObjective clear/miss paths, tracker refresh
//   helpers, and the vector destroy sibling FUN_0092a600 (which free+zeros after).
//
// ABI (image-sealed, custom dual-register — not thiscall/cdecl)
//   EDI = MissionTracker* host
//   Stack: none
//   AL  = 1 (always)
//   RET (C3)
//
// LAYOUT
//   +0x11c  vector begin  (T**)
//   +0x120  vector end    (T**)
//   +0x124  capacity end  (untouched here; zeroed by FUN_0092a600)
//
// NOTES
//   - Decompiler collapses the delete loop; bytes restore for(p=begin;p!=end;++p).
//   - operator_delete is cdecl (ADD ESP,4). Not noreturn.
//   - memmove size is 0 (MSVC clear tail); end becomes begin.
//   - Product type of T is open → _Inferred.
// =============================================================================

#include <cstdint>
#include <cstring>

using u8  = std::uint8_t;
using u32 = std::uint32_t;

// MSVC CRT scalar delete (image 0x00489822)
void operator_delete(void* p);

// ---------------------------------------------------------------------------
// Primary entry — custom: EDI=tracker, AL=bool(true)
// ---------------------------------------------------------------------------
u8 Tracker_ClearOwnedPtrVectorAt11c_Inferred(void* tracker /*EDI*/)
{
    auto* host = reinterpret_cast<u8*>(tracker);

    void** begin = *reinterpret_cast<void***>(host + 0x11c);
    void** end   = *reinterpret_cast<void***>(host + 0x120);

    // Phase 1: delete each owned pointer element (stride 4)
    for (void** p = begin; p != end; ++p) {
        operator_delete(*p);
    }

    // Phase 2: vector clear — end := begin, buffer retained
    void* first = *reinterpret_cast<void**>(host + 0x11c);
    if (first != nullptr) {
        void* last = *reinterpret_cast<void**>(host + 0x120);
        int count = static_cast<int>((reinterpret_cast<char*>(last) -
                                      reinterpret_cast<char*>(first)) >> 2);
        if (count != 0 && first != last) {
            // Image: memmove(begin, end, 0); end = begin + 0
            std::size_t nbytes = 0;
            void* moved = std::memmove(first, last, nbytes);
            *reinterpret_cast<void**>(host + 0x120) =
                static_cast<char*>(moved) + nbytes;
        }
    }

    return 1;
}

// Ghidra symbol alias used by residual call-site docs.
u8 FUN_0092a3d0(void* tracker /*EDI*/)
{
    return Tracker_ClearOwnedPtrVectorAt11c_Inferred(tracker);
}
