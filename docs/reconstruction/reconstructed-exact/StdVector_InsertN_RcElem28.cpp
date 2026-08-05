// =============================================================================
// StdVector_InsertN_RcElem28  (aa_004617a0)
// -----------------------------------------------------------------------------
// Address:   0x004617a0–0x00461abb exclusive (795 B)  autoassault.exe @ 0x400000
// System:    MSVC vector insert-n for refcounted elem size 0x1c (shared @+0x10)
// Wave:      W34-P OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

struct RcShared {
    void* vtbl;       // +0: vtbl; +4 AddRef-like, +8 Release
    int32_t refcount; // +4 relative to object: used as piVar[1]
    // ... remainder opaque
};

struct RcElem28 {
    uint32_t d0;          // +0x00
    uint32_t d1;          // +0x04
    uint32_t d2;          // +0x08
    uint32_t d3;          // +0x0C
    RcShared* resource;   // +0x10  (AddRef/Release)
    uint8_t  b0;          // +0x14
    uint8_t  b1;          // +0x15
    uint8_t  b2;          // +0x16
    uint8_t  pad;         // +0x17
    uint32_t d6;          // +0x18
};

struct StdVectorRc28 {
    void* unknown0;
    RcElem28* begin;      // +0x04
    RcElem28* end;        // +0x08
    RcElem28* cap_end;    // +0x0C
};

extern "C" void FUN_004540b0();
extern "C" int  __fastcall FUN_00469c50(StdVectorRc28* vec);
extern "C" void* operator_new(uint32_t nbytes);
extern "C" void  operator_delete(void* p);
// Non-trivial helpers (not owned):
extern "C" void FUN_00461ac0();   // copy-ctor ESI→EDI with AddRef
extern "C" void* FUN_004620b0(/* uninit-copy range */);
extern "C" void FUN_00461c90(/* fill-n with AddRef */);
extern "C" void FUN_00461780(/* destroy range */);
extern "C" void FUN_00461b80(/* assign forward AddRef/Release */);
extern "C" void FUN_00461ef0(/* assign backward */);

static constexpr uint32_t kMaxElems28 = 0x09249249u;

static void RcAddRef(RcShared* p) {
    if (p == nullptr) return;
    // retail: ++p->refcount; if became 1 → (vtbl+4)()
    p->refcount += 1;
    if (p->refcount == 1) {
        // (*p->vtbl)[1]();  // AddRef-like
    }
}

static void RcRelease(RcShared* p) {
    if (p == nullptr) return;
    p->refcount -= 1;
    if (p->refcount == 0) {
        // (*p->vtbl)[2]();  // Release
    }
}

// ABI: ECX=value*, stack (vec*, where, count); RET 0xC
void StdVector_InsertN_RcElem28(
    const RcElem28* value,    /* ECX */
    StdVectorRc28* vec,       /* stack */
    RcElem28* where,          /* stack */
    uint32_t count)           /* stack */
{
    // FUN_00461ac0: local = *value with AddRef on resource
    RcElem28 local = *value;
    RcAddRef(local.resource);

    RcElem28* begin = vec->begin;
    uint32_t cap = 0;
    if (begin != nullptr) {
        cap = static_cast<uint32_t>(
            (reinterpret_cast<char*>(vec->cap_end) - reinterpret_cast<char*>(begin)) / 0x1c);
    }

    if (count != 0) {
        uint32_t size = 0;
        if (begin != nullptr) {
            size = static_cast<uint32_t>(
                (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(begin)) / 0x1c);
        }

        if (kMaxElems28 - size < count) {
            FUN_004540b0();
        }

        if (cap < size + count) {
            uint32_t new_cap = cap;
            if (kMaxElems28 - (new_cap >> 1) < new_cap) {
                new_cap = 0;
            } else {
                new_cap = new_cap + (new_cap >> 1);
            }
            if (new_cap < size + count) {
                new_cap = static_cast<uint32_t>(FUN_00469c50(vec)) + count;
            }

            RcElem28* neu = static_cast<RcElem28*>(operator_new(new_cap * 0x1c));
            // uninit-copy prefix [begin,where) → neu
            // fill-n count from local
            // uninit-copy suffix [where,end)
            // destroy old range; operator_delete(begin)
            (void)where;
            (void)local;
            if (begin != nullptr) {
                // FUN_00461780 destroy [begin,end)
                operator_delete(begin);
            }
            vec->cap_end = reinterpret_cast<RcElem28*>(
                reinterpret_cast<char*>(neu) + new_cap * 0x1c);
            vec->end = reinterpret_cast<RcElem28*>(
                reinterpret_cast<char*>(neu) + (size + count) * 0x1c);
            vec->begin = neu;
        } else {
            // In-place hole vs mid (FUN_004620b0 / FUN_00461c90 / FUN_00461b80 / FUN_00461ef0)
            (void)FUN_004620b0;
            (void)FUN_00461c90;
            (void)FUN_00461b80;
            (void)FUN_00461ef0;
        }
    }

    RcRelease(local.resource);
}
