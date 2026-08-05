// =============================================================================
// RcElem28_Release  (aa_00460d70)
// -----------------------------------------------------------------------------
// Address:   0x00460d70–0x00460d83 exclusive (19 B)  autoassault.exe @ 0x400000
// System:    Per-element Release of shared resource @+0x10 (RC-elem 0x1c)
// Wave:      W36-O OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;       // +0x00; slot +8 = Release/destroy
    int32_t refcount; // +0x04
};

struct RcElem28 {
    uint32_t d0, d1, d2, d3;
    RcShared* resource; // +0x10
    uint8_t b0, b1, b2, pad;
    uint32_t d6;
};

static_assert(sizeof(RcElem28) == 0x1c, "RcElem28 stride");

// ABI: EAX=elem*, RET 0 — or tail-transfer to shared->vtbl[+8] when refcount hits 0.
// Clean form uses a function-pointer call for readability; retail is JMP [vtbl+8].
extern "C" void RcElem28_Release(RcElem28* elem /* EAX */)
{
    RcShared* shared = elem->resource;
    if (shared == nullptr) {
        return;
    }

    shared->refcount -= 1;
    if (shared->refcount != 0) {
        return;
    }

    using ReleaseFn = void (*)(RcShared*);
    auto* vtbl = reinterpret_cast<ReleaseFn*>(shared->vtbl);
    // retail: mov edx, [ecx]; jmp [edx+8]  (this@ECX still = shared)
    vtbl[2](shared);
}
