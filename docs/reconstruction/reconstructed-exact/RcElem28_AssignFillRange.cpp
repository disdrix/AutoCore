// =============================================================================
// RcElem28_AssignFillRange  (aa_00461b80)
// -----------------------------------------------------------------------------
// Address:   0x00461b80–0x00461bfd exclusive (125 B)  autoassault.exe @ 0x400000
// System:    MSVC-style range fill-by-assign for refcounted elem size 0x1c
// Wave:      W35-P OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;        // +0; +4 AddRef-like, +8 Release
    int32_t refcount;  // +4
};

struct RcElem28 {
    uint32_t d0;          // +0x00
    uint32_t d1;          // +0x04
    uint32_t d2;          // +0x08
    uint32_t d3;          // +0x0C
    RcShared* resource;   // +0x10
    uint8_t  b0;          // +0x14
    uint8_t  b1;          // +0x15
    uint8_t  b2;          // +0x16
    // +0x17 not written by this assign
    uint32_t d6;          // +0x18
};

static void RcAddRef(RcShared* p) {
    if (p == nullptr) return;
    p->refcount += 1;
    if (p->refcount == 1) {
        // (*p->vtbl)[1]();  // vtbl+4, ECX=p
    }
}

static void RcRelease(RcShared* p) {
    if (p == nullptr) return;
    p->refcount -= 1;
    if (p->refcount == 0) {
        // (*p->vtbl)[2]();  // vtbl+8
    }
}

// ABI: EAX=dest_first*, EDI=value*, stack dest_last*; plain RET; void
void RcElem28_AssignFillRange(
    RcElem28* dest_first,     /* EAX */
    const RcElem28* value,    /* EDI */
    RcElem28* dest_last)      /* stack */
{
    for (RcElem28* cur = dest_first; cur != dest_last; ++cur) {
        cur->d0 = value->d0;
        cur->d1 = value->d1;
        cur->d2 = value->d2;
        cur->d3 = value->d3;
        RcShared* src_res = value->resource;
        RcAddRef(src_res);
        RcRelease(cur->resource);
        cur->resource = src_res;
        cur->b0 = value->b0;
        cur->b1 = value->b1;
        cur->b2 = value->b2;
        cur->d6 = value->d6;
    }
}
