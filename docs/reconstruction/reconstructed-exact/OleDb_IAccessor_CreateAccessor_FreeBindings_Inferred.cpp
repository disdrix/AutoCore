// =============================================================================
// OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00422830
// Address:   0x00422830 – 0x00422879  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB IAccessor
// Twin:      reconstructed-exact/FUN_00422830.cpp (same body)
// Generated: 2026-07-29 W20-J dual seal
// Exactness: Behavior-preserving rewrite from read_memory + decompile.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   IAccessor::CreateAccessor (vtbl+0x10) then free binding-row heap ptrs at +0x14
//   for cBindings entries (stride 0x48). Returns HRESULT.

#include <cstdint>

struct IAccessor_Inferred {
    void **vtbl;
};

using CreateAccessor_fn = int32_t(__stdcall *)(
    IAccessor_Inferred *self,
    uint32_t dwAccessorFlags,
    uint32_t cBindings,
    void *rgBindings,
    uint32_t cbRowSize,
    void *phAccessor,
    void *rgStatus);

extern void __cdecl operator_delete(void *p);

int32_t OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred(
    IAccessor_Inferred *iface /*EAX*/,
    uint32_t cBindings /*ECX*/,
    uint8_t *bindings /*EDX*/,
    void *phAccessor /*stack*/,
    uint32_t cbRowSize /*stack*/)
{
    void **vtbl = iface->vtbl;
    uint32_t flags = 2u;
    if (*reinterpret_cast<int32_t *>(bindings + 0x24) != 0) {
        flags = 3u;
    }

    auto create = reinterpret_cast<CreateAccessor_fn>(vtbl[0x10 / 4]);
    int32_t hr = create(
        iface, flags, cBindings, bindings, cbRowSize, phAccessor, nullptr);

    uint8_t *p = bindings;
    for (uint32_t n = cBindings; n != 0; --n) {
        operator_delete(*reinterpret_cast<void **>(p + 0x14));
        p += 0x48;
    }
    return hr;
}
