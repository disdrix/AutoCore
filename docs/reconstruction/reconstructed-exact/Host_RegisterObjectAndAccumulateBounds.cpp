// =============================================================================
// Host_RegisterObjectAndAccumulateBounds  (aa_007647c0)
// -----------------------------------------------------------------------------
// Address:   0x007647c0–0x0076482d exclusive (109 B)  autoassault.exe @ 0x400000
// System:    host registration + bounds accumulation
// Wave:      W36-L OWN-ONLY 2026-07-29
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>

// Sealed W21-O
extern "C" void Bounds_AccumulateTransformedLocal(
    void* dest_bounds /*ECX*/,
    void* xformRef,
    void* local_bounds,
    void* scaleSrc);

// EAX = vector*, ESI = &value (object*); push_back pointer (capacity/fast path)
extern "C" void FUN_004406e0(void);

struct HostLike {
    void** vtbl;           // +0x00; slot +0x0c used
    uint8_t bounds[0x30];  // +0x04 BoundsVolume dest (layout: W21-O)
    // ...
    // +0xbc: vector<object*> (begin/end/cap) — push target
};

struct ObjectLike {
    void** vtbl;           // +0x00; slots +0x20, +0x5c, +0x80
    uint8_t pad_04[0x24];
    uint8_t localBounds[0x30]; // +0x28 BoundsVolume
    // +0x58, +0x5c, +0x60 linkage gate for virt +0x80
    // +0x64 scaleSrc-like object*
    // +0xbc flag byte bit0 gates virt +0x5c
};

// ABI (thiscall + 1 stack arg, RET 4):
//   ECX    = host*
//   stack0 = object*
//
// Semantics:
//   1) Append object* to host's child pointer vector at host+0xbc.
//   2) Object virtual prep (+0x20 host arg; optional +0x80 / +0x5c).
//   3) host virt +0x0c(local@obj+0x28, scale@obj+0x64) → xformRef.
//   4) Bounds_AccumulateTransformedLocal(host+4, xform, local, scale).

extern "C" void Host_RegisterObjectAndAccumulateBounds(
    HostLike* host /*ECX*/,
    ObjectLike* obj /*stack0*/)
{
    // Retail: lea eax,[host+0xbc]; lea esi,&stack_obj; call FUN_004406e0
    uint8_t* vec = reinterpret_cast<uint8_t*>(host) + 0xbc;
    (void)vec;
    FUN_004406e0();

    using Virt0 = void(__thiscall*)(ObjectLike*, HostLike*);
    using Virt1 = void(__thiscall*)(ObjectLike*);
    using HostVirt = void*(__thiscall*)(HostLike*, void* local, void* scaleSrc);

    auto* ov = obj->vtbl;
    reinterpret_cast<Virt0>(ov[0x20 / 4])(obj, host);

    uint32_t* o = reinterpret_cast<uint32_t*>(obj);
    if (o[0x58 / 4] != 0 && o[0x5c / 4] != 0 &&
        *reinterpret_cast<int*>(static_cast<uintptr_t>(o[0x5c / 4]) + 0x1c) !=
            static_cast<int>(o[0x60 / 4])) {
        reinterpret_cast<Virt1>(ov[0x80 / 4])(obj);
    }

    void* scaleSrc = reinterpret_cast<void*>(static_cast<uintptr_t>(o[0x64 / 4]));
    if ((reinterpret_cast<uint8_t*>(obj)[0xbc] & 1) != 0) {
        reinterpret_cast<Virt1>(ov[0x5c / 4])(obj);
    }

    void* local = reinterpret_cast<uint8_t*>(obj) + 0x28;
    void* xform = reinterpret_cast<HostVirt>(host->vtbl[0x0c / 4])(host, local, scaleSrc);

    void* dest = reinterpret_cast<uint8_t*>(host) + 4;
    Bounds_AccumulateTransformedLocal(dest, xform, local, scaleSrc);
}

// Ghidra twin name
extern "C" void FUN_007647c0(HostLike* host, ObjectLike* obj)
{
    Host_RegisterObjectAndAccumulateBounds(host, obj);
}
