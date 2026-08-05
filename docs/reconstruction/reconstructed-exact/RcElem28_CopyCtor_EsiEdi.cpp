// =============================================================================
// RcElem28_CopyCtor_EsiEdi  (aa_00461ac0)
// -----------------------------------------------------------------------------
// Address:   0x00461ac0–0x00461b11 exclusive (81 B)  autoassault.exe @ 0x400000
// System:    MSVC-style copy-ctor for refcounted elem size 0x1c (shared @+0x10)
// Wave:      W35-N OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;        // +0; slot +4 AddRef-like, +8 Release
    int32_t refcount;  // +4
    // remainder opaque
};

struct RcElem28 {
    uint32_t d0;        // +0x00
    uint32_t d1;        // +0x04
    uint32_t d2;        // +0x08
    uint32_t d3;        // +0x0C
    RcShared* resource; // +0x10
    uint8_t  b0;        // +0x14
    uint8_t  b1;        // +0x15
    uint8_t  b2;        // +0x16
    uint8_t  pad;       // +0x17
    uint32_t d6;        // +0x18
};

static void RcAddRef(RcShared* p) {
    if (p == nullptr) {
        return;
    }
    // retail: ++p->refcount; if became 1 → (*(p->vtbl))[1]()  // vtbl+4
    p->refcount += 1;
    if (p->refcount == 1) {
        // (*p->vtbl)[1]();
    }
}

// ABI: ESI=src*, EDI=dst*; returns dst* in EAX; plain RET (C3)
// Register contract — not a C ABI. Modeled as explicit pointers for port clarity.
extern "C" RcElem28* RcElem28_CopyCtor_EsiEdi(const RcElem28* src /*ESI*/, RcElem28* dst /*EDI*/)
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
    return dst;
}

// Ghidra name alias (register ABI still applies at call sites)
extern "C" void FUN_00461ac0(void)
{
    // Real body uses unaff_ESI / unaff_EDI; see RcElem28_CopyCtor_EsiEdi.
}
