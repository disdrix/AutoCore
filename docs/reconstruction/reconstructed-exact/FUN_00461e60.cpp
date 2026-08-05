// =============================================================================
// FUN_00461e60  →  RcElem28_AssignRange
// -----------------------------------------------------------------------------
// Stable ID: aa_00461e60
// Address:   0x00461e60–0x00461eea exclusive (138 B)
// Wave:      W37-Y OWN-ONLY 2026-08-04
// Twin of:   reconstructed-exact/RcElem28_AssignRange.cpp
// =============================================================================

#include <cstdint>

// See RcElem28_AssignRange.cpp for typed reconstruction.
// ABI: EAX=dest*, stack src_first*, src_last*; plain RET; returns final dest*.

extern "C" uint32_t* RcElem28_AssignRange(uint32_t* dest,
                                          uint32_t* src_first,
                                          uint32_t* src_last);

extern "C" uint32_t* FUN_00461e60(uint32_t* src_first, uint32_t* src_last) {
    // Decompiler shows 2 stack formals + in_EAX dest; match that surface.
    uint32_t* dest;
#if defined(_MSC_VER)
    __asm { mov dest, eax }
#else
    dest = nullptr; // non-MSVC: formal incomplete without EAX
#endif
    return RcElem28_AssignRange(dest, src_first, src_last);
}
