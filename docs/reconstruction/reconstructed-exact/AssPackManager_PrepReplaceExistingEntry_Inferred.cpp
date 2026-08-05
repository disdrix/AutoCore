// =============================================================================
// AssPackManager_PrepReplaceExistingEntry_Inferred  (aa_009847c0)
// -----------------------------------------------------------------------------
// Address:   0x009847c0–0x0098488c exclusive (204 B)  autoassault.exe @ 0x400000
// System:    assPackManager.cpp replace-prep for existing pack entry
// Wave:      W37-Y OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving reconstruction from decompile + read_memory.
//            Nested callees kept as FUN_* (not OWN). Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>
#include <windows.h>

// Host layout (sealed from this + sibling AssPack workers):
//   +0x08  map end sentinel / empty iterator
//   +0x38  CRITICAL_SECTION
//   +0x50  char CS-gate (nonzero → lock)

struct AssPackHost {
    uint8_t  _pad0[0x08];
    void*    map_end;          // +0x08
    uint8_t  _pad1[0x30];
    CRITICAL_SECTION cs;       // +0x38
    uint8_t  _pad2[0x08];
    char     use_cs;           // +0x50
};

// Entry fields used here (map node / pack entry):
//   +0x0C  value region (pushed into deferred RcElem28-stride vector)
//   +0x1C  shared field cleared to DAT_00d1eac0 empty sentinel
//   +0x24  ptr; container at *(+0x24)+0x30 receives push via FUN_00469c80

extern "C" void FUN_00719630(); // path normalize (register formals; not OWN)
extern "C" void FUN_00989e00(void* out_key, const char* name); // thiscall cache @ DAT_00d1eac8
extern "C" void* FUN_0044e8c0(void* out_it); // HashMap find; EDI=map/host, EBX=key*
extern "C" void FUN_00469c80(); // RcElem28-stride vector push/grow; ECX=vec*

extern uint32_t DAT_00d1eac0; // empty shared sentinel
// DAT_00d1eac8: ResourceCache host (ECX for FUN_00989e00)

// ABI: ECX=pathBuf*, EDX=host*, stack nameOrCookie*; RET 4; 0 success / -1 miss
extern "C" int AssPackManager_PrepReplaceExistingEntry_Inferred(
    char* pathBuf /*ECX*/,
    AssPackHost* host /*EDX*/,
    const char* nameOrCookie /*stack0*/)
{
    (void)pathBuf;
    (void)nameOrCookie;

    CRITICAL_SECTION* cs = &host->cs;
    if (host->use_cs != 0) {
        EnterCriticalSection(cs);
    }

    FUN_00719630();

    uint32_t key_storage = 0;
    // FUN_00989e00 with ECX = &DAT_00d1eac8 (resource cache), out=&key_storage, name=pathBuf
    FUN_00989e00(&key_storage, pathBuf);

    void* it = nullptr;
    // FUN_0044e8c0: EDI=host, EBX=&key_storage, stack &it
    FUN_0044e8c0(&it);

    if (it == host->map_end) {
        if (host->use_cs != 0) {
            LeaveCriticalSection(cs);
        }
        return -1;
    }

    // Bytes: *(it+0x1C) = DAT_00d1eac0; FUN_00469c80 on *(it+0x24)+0x30
    *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(it) + 0x1C) = DAT_00d1eac0;
    FUN_00469c80();

    if (host->use_cs != 0) {
        LeaveCriticalSection(cs);
    }
    return 0;
}
