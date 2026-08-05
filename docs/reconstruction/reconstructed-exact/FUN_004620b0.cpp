// =============================================================================
// FUN_004620b0  — twin of StdVector_UninitializedCopy_RcElem28
// -----------------------------------------------------------------------------
// Stable ID: aa_004620b0
// Address:   0x004620b0–0x00462194 exclusive (228 B)
// Wave:      W35-N OWN-ONLY 2026-07-29
// Canonical: StdVector_UninitializedCopy_RcElem28
// See:       reconstructed-exact/StdVector_UninitializedCopy_RcElem28.cpp
// =============================================================================

#include <cstdint>

// Implementation: StdVector_UninitializedCopy_RcElem28.cpp
// ABI: ECX=src_begin, stack (src_end, dest); EAX=dest_end; plain RET.

extern "C" void* StdVector_UninitializedCopy_RcElem28(void* src_begin, void* src_end, void* dest);

extern "C" void* FUN_004620b0(void* src_begin, void* src_end, void* dest)
{
    return StdVector_UninitializedCopy_RcElem28(src_begin, src_end, dest);
}
