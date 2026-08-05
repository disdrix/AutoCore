// =============================================================================
// RcElem28_AssignBackward  (aa_00461ef0)
// -----------------------------------------------------------------------------
// Address:   0x00461ef0–0x00461f7a exclusive (138 B)  autoassault.exe @ 0x400000
// System:    MSVC-style assign-backward / copy_backward for refcounted elem 0x1c
// Wave:      W35-P OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;
    int32_t refcount;
};

struct RcElem28 {
    uint32_t d0;
    uint32_t d1;
    uint32_t d2;
    uint32_t d3;
    RcShared* resource;
    uint8_t  b0;
    uint8_t  b1;
    uint8_t  b2;
    uint32_t d6;
};

static void RcAddRef(RcShared* p) {
    if (p == nullptr) return;
    p->refcount += 1;
    if (p->refcount == 1) {
        // (*p->vtbl)[1]();
    }
}

static void RcRelease(RcShared* p) {
    if (p == nullptr) return;
    p->refcount -= 1;
    if (p->refcount == 0) {
        // (*p->vtbl)[2]();
    }
}

static void RcAssign(RcElem28* dest, const RcElem28* src) {
    dest->d0 = src->d0;
    dest->d1 = src->d1;
    dest->d2 = src->d2;
    dest->d3 = src->d3;
    RcShared* src_res = src->resource;
    RcAddRef(src_res);
    RcRelease(dest->resource);
    dest->resource = src_res;
    dest->b0 = src->b0;
    dest->b1 = src->b1;
    dest->b2 = src->b2;
    dest->d6 = src->d6;
}

// ABI: EAX=dest_end*, stack (first*, last*); plain RET; returns final dest*
RcElem28* RcElem28_AssignBackward(
    RcElem28* dest_end,   /* EAX */
    RcElem28* first,      /* stack */
    RcElem28* last)       /* stack */
{
    if (first == last) {
        return dest_end;
    }
    do {
        --last;
        --dest_end;
        RcAssign(dest_end, last);
    } while (last != first);
    return dest_end;
}
