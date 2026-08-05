// =============================================================================
// GfxBodyHolder_ReplaceUnserialize_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0073eb40
// Address:   0x0073eb40  (autoassault.exe, image base 0x400000)
// System:    client / graphics / gfxBody sto load
// Generated: 2026-08-04 W38-R (bytes + decompile; not modernization)
// Exactness: Behavior-preserving. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Replace holder body slot (+4) with a fresh 0x14C GfxBody, peek sto
// chunk tag, dispatch SAMB (gfxBodyMaster) vs GBOD (gfxBody) unserialize.
//
// ABI: thiscall ECX=holder; stack reader; RET 4; EAX = status passthrough.
// SEH: LAB_009b3f3c
//
// REJECT: Named_CalleeOf_* scaffold aliases; product method English without PDB.
// =============================================================================

#include <cstdint>

struct stoChunkReader; // opaque; PeekChunkTag uses ESI=this
struct GfxBody;        // size 0x14C; ctor FUN_00764030

struct GfxBodyHolder {
    void* _unk0;
    GfxBody* body; // +4
};

// Callees (owned elsewhere)
extern void* operator_new(unsigned);
extern void operator_delete(void*);
extern GfxBody* FUN_00764030(void* self); // GfxBody ctor
extern uint32_t FUN_0076a900(void);       // stoChunkReader_PeekChunkTag (ESI)
extern uint32_t FUN_009615c0(GfxBody* body, stoChunkReader* reader); // SAMB
extern uint32_t GfxBody_UnserializeGBOD_Inferred(GfxBody* body, stoChunkReader* reader); // 0x00765740

// Bytes: scalar deleting dtor via vtbl[0](this, 1)
using ScalarDeletingDtor = void(__thiscall*)(void* self, int flags);

uint32_t __thiscall GfxBodyHolder_ReplaceUnserialize_Inferred(
    GfxBodyHolder* holder,
    stoChunkReader* reader)
{
    GfxBody* old = holder->body;
    if (old != nullptr) {
        auto** vtbl = *reinterpret_cast<void***>(old);
        reinterpret_cast<ScalarDeletingDtor>(vtbl[0])(old, 1);
    }

    void* raw = operator_new(0x14C);
    GfxBody* body = (raw != nullptr) ? FUN_00764030(raw) : nullptr;
    holder->body = body;

    // ESI = reader for PeekChunkTag
    uint32_t tag = FUN_0076a900();
    if (tag == 0x424D4153u /* 'SAMB' */) {
        return FUN_009615c0(body, reader);
    }
    return GfxBody_UnserializeGBOD_Inferred(body, reader);
}
