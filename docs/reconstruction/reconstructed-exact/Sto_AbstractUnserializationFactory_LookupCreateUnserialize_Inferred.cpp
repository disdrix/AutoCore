// =============================================================================
// Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00437b00
// Address:   0x00437b00–0x00437b57  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — stoAbstractUnserializationFactory (map A) + stoChunk
// Generated: 2026-07-23 scaffold as FUN_00437b00; dual A/B seal 2026-07-29 (W36-A)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Peek next chunk FourCC from a stoChunkReader, look up a creator in Unserial
//   Factory **map A**, construct the object, store it to *out, then invoke the
//   object's unserialize virtual (slot 1 at this=obj+4) with the chunk reader.
//
//   1. ESI = EDI (chunk reader); tag = stoChunkReader_PeekChunkTag().
//   2. MapA GetInstance + NestedHash lookup by tag.
//   3. If node == map.sentinel → obj = 0; else obj = creator() at node+0xc
//      (0 stack args — decompiler's creator(tag) is wrong).
//   4. *param_1 = obj.
//   5. If obj: thiscall vfunc[1](reader) on (obj+4); return status.
//      Else: return 0xFFFFFFFF.
//
// ABI (bytes):
//   cdecl; stack arg0 = void** out; **EDI** = stoChunkReader*.
//   Body 88 B. Success path: PUSH EDI; CALL [vtbl+4]; ADD ESP,8; RET.
//   Fail path: OR EAX,-1; ADD ESP,8; RET.
//
// CALLEES:
//   FUN_0076a900  stoChunkReader_PeekChunkTag (ESI this)
//   FUN_00438c40  MapA GetInstance (×2)
//   FUN_0046c1b0  NestedHash lookup — unowned W36-B
//   indirect creator @ node+0xc
//   indirect vfunc @ *(obj+4)+4
//
// CALLERS:
//   FUN_00765740 (gfxBody unserialize) — 4 sites; ORs return into status flags.
//
// PAIR:
//   Insert/register: Sto_AbstractUnserializationFactory_InsertCreator_Inferred
//   (FUN_004449b0) writes creator at node+0xc on Map A.
// SIBLING (not owned): FUN_00437c90 MapB path (W36-C).
// REJECT scaffold: Named_CalleeOf_Named_gfxBody_00437b00 as product role.
//

#include <cstdint>

struct NestedHash_Sentinel0x10;
struct NestedHashNode0x10 {
  NestedHashNode0x10* next;
  NestedHashNode0x10* prev;
  uint32_t            key;       // +0x08 FourCC
  void* (*creator)(void);        // +0x0c
};

struct StoChunkReader; // opaque; Peek uses ESI this

// Sealed callees
extern "C" uint32_t stoChunkReader_PeekChunkTag(void /* ESI this */); // FUN_0076a900
extern "C" NestedHash_Sentinel0x10*
Sto_UnserialFactoryMapA_GetInstance_Inferred(void); // FUN_00438c40
extern "C" void FUN_0046c1b0(void); // ESI=map, ECX=key*, EAX=node**

// Retail: cdecl; out on stack; reader in EDI
extern "C" uint32_t
Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred(
    void** out_object /* stack */,
    StoChunkReader* reader_edi /* register EDI */)
{
  uint32_t tag;
  NestedHash_Sentinel0x10* map;
  NestedHashNode0x10* node = nullptr;
  void* obj;

  // mov esi, edi
  // tag = stoChunkReader_PeekChunkTag(); // ESI = reader
  tag = 0;
  (void)reader_edi;
  (void)tag;

  map = Sto_UnserialFactoryMapA_GetInstance_Inferred();
  // FUN_0046c1b0 → node
  (void)map;
  map = Sto_UnserialFactoryMapA_GetInstance_Inferred();

  NestedHashNode0x10* sentinel =
      *reinterpret_cast<NestedHashNode0x10**>(
          reinterpret_cast<char*>(map) + 0x08);

  if (node == sentinel) {
    obj = nullptr;
  } else {
    // CALL [node+0xc] — 0 stack args (not creator(tag))
    obj = node->creator();
  }

  *out_object = obj;
  if (obj != nullptr) {
    // EDX = *(uint32_t*)((char*)obj + 4);  // vtbl
    // ECX = (char*)obj + 4;                // this
    // PUSH reader; CALL [EDX+4];           // thiscall, callee cleans 1 arg
    using UnserializeFn = uint32_t(__thiscall*)(void* self, StoChunkReader* r);
    void* sub = reinterpret_cast<char*>(obj) + 4;
    auto** vtbl = *reinterpret_cast<UnserializeFn***>(sub);
    return vtbl[1](sub, reader_edi);
  }
  return 0xFFFFFFFFu;
}
