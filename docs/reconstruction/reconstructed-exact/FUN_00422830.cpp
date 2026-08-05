// =============================================================================
// OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred  (Ghidra: FUN_00422830)
// -----------------------------------------------------------------------------
// Stable ID: aa_00422830
// Address:   0x00422830 – 0x00422879  (autoassault.exe, image base 0x400000)
// System:    COM / OLE DB IAccessor
// Generated: 2026-07-29 W20-J dual seal (bytes authoritative; decompiler understates)
// Exactness: Behavior-preserving rewrite from read_memory + decompile. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Call IAccessor::CreateAccessor at vtbl+0x10 with flags 2 or 3 (from
//   bindings[+0x24] != 0), then free each binding row's pointer at +0x14 for
//   cBindings entries (stride 0x48). Return CreateAccessor HRESULT.

// READABILITY:
//   - Decompiler scaffold collapsed args and free loop; this clean restores them.
//   - Product names for phAccessor/cbRowSize/flag bits are inferred (OLE DB).

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

// Custom ABI: iface in EAX, cBindings in ECX, bindings in EDX,
// phAccessor @ [esp+4], cbRowSize @ [esp+8]; plain RET.
int32_t OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred(
    IAccessor_Inferred *iface /*EAX*/,
    uint32_t cBindings /*ECX*/,
    uint8_t *bindings /*EDX*/,
    void *phAccessor /*stack*/,
    uint32_t cbRowSize /*stack*/)
{
    void **vtbl = iface->vtbl;
    uint32_t flags = 2u; // DBACCESSOR_ROWDATA
    if (*reinterpret_cast<int32_t *>(bindings + 0x24) != 0) {
        flags = 3u; // ROWDATA | PASSBYREF — inferred
    }

    auto create = reinterpret_cast<CreateAccessor_fn>(vtbl[0x10 / 4]);
    int32_t hr = create(
        iface,
        flags,
        cBindings,
        bindings,
        cbRowSize,
        phAccessor,
        /*rgStatus*/ nullptr);

    uint8_t *p = bindings;
    uint32_t n = cBindings;
    while (n != 0) {
        operator_delete(*reinterpret_cast<void **>(p + 0x14));
        p += 0x48; // 0x14 + 0x34 per image loop
        --n;
    }
    return hr;
}

// Ghidra symbol alias (scaffold name)
int32_t FUN_00422830(IAccessor_Inferred *iface /*EAX*/,
                     uint32_t cBindings /*ECX*/,
                     uint8_t *bindings /*EDX*/,
                     void *phAccessor,
                     uint32_t cbRowSize)
{
    return OleDb_IAccessor_CreateAccessor_FreeBindings_Inferred(
        iface, cBindings, bindings, phAccessor, cbRowSize);
}
