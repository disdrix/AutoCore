// =============================================================================
// RcElem28_AssignRange  (aa_00461e60)
// -----------------------------------------------------------------------------
// Address:   0x00461e60–0x00461eea exclusive (138 B)  autoassault.exe @ 0x400000
// System:    MSVC-style forward assign-range for refcounted elem size 0x1c
// Wave:      W37-Y OWN-ONLY 2026-08-04
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

// ABI: EAX=dest*, stack src_first*, src_last*; plain RET; returns final dest*
// Parent may push a third stack dword (unread by this leaf) and ADD ESP,0xC.
extern "C" RcElem28* RcElem28_AssignRange(
    RcElem28* dest,       /* EAX */
    RcElem28* src_first,  /* stack0 */
    RcElem28* src_last)   /* stack1 exclusive */
{
    if (src_first == src_last) {
        return dest;
    }
    RcElem28* d = dest;
    for (RcElem28* s = src_first; s != src_last; ++s, ++d) {
        d->d0 = s->d0;
        d->d1 = s->d1;
        d->d2 = s->d2;
        d->d3 = s->d3;
        RcShared* src_res = s->resource;
        RcAddRef(src_res);
        RcRelease(d->resource);
        d->resource = src_res;
        d->b0 = s->b0;
        d->b1 = s->b1;
        d->b2 = s->b2;
        d->d6 = s->d6;
    }
    return d;
}
