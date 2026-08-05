// =============================================================================
// StdVector_UninitializedCopy_RcElem28  (aa_004620b0)
// -----------------------------------------------------------------------------
// Address:   0x004620b0–0x00462194 exclusive (228 B)  autoassault.exe @ 0x400000
// System:    MSVC uninitialized_copy for refcounted elem size 0x1c
// Wave:      W35-N OWN-ONLY 2026-07-29
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
    uint8_t  pad;
    uint32_t d6;
};

static void RcAddRef(RcShared* p) {
    if (p == nullptr) {
        return;
    }
    p->refcount += 1;
    if (p->refcount == 1) {
        // (*p->vtbl)[1]();  // vtbl+4 when count becomes 1
    }
}

// Per-element construct (same fields as RcElem28_CopyCtor_EsiEdi / FUN_00461ac0)
static void RcElem28_UninitConstruct(RcElem28* dst, const RcElem28* src)
{
    dst->d0 = src->d0;
    dst->d1 = src->d1;
    dst->d2 = src->d2;
    dst->d3 = src->d3;
    RcShared* res = src->resource;
    RcAddRef(res);
    dst->resource = res;
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    dst->d6 = src->d6;
}

// ABI: ECX=src_begin, stack (src_end, dest); EAX=dest_end; plain RET (caller cleans 8)
// Ghidra labels __thiscall — bytes are plain C3, not RET 8.
extern "C" RcElem28* StdVector_UninitializedCopy_RcElem28(
    RcElem28* src_begin, /* ECX */
    RcElem28* src_end,   /* stack */
    RcElem28* dest)      /* stack */
{
    // SEH LAB_009be5a1 present in retail; elided on happy path.
    for (; src_begin != src_end; ++src_begin) {
        if (dest != nullptr) {
            RcElem28_UninitConstruct(dest, src_begin);
        }
        ++dest; // +0x1c
    }
    return dest;
}

// Ghidra name alias
extern "C" RcElem28* FUN_004620b0(
    RcElem28* src_begin,
    RcElem28* src_end,
    RcElem28* dest)
{
    return StdVector_UninitializedCopy_RcElem28(src_begin, src_end, dest);
}
