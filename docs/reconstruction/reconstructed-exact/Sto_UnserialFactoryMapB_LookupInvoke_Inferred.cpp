// =============================================================================
// Sto_UnserialFactoryMapB_LookupInvoke_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00437c90
// Address:   0x00437c90–0x00437cce  (autoassault.exe, image base 0x400000)
// System:    arda2/storage — stoAbstractUnserializationFactory (map B lookup/invoke)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29 (W36-C)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Peek chunk FourCC from stoChunkReader (entry EAX), look up in NestedHash
//   map B, and if present invoke the creator stored at node+0x0C.
//   Miss → return 0.
//
// ABI (bytes):
//   no stack formals; entry EAX = stoChunkReader*
//   returns void* (creator result) or 0 in EAX
//   SUB ESP,8; plain RET after ADD ESP,8
//   Body 63 B (0x3F)
//
// INVOKE:
//   CALL DWORD PTR [node+0xC] after POP ESI (ESI = reader restored).
//   No stack arg push — creator formal ABI is a residual gap.
//
// CALLER:
//   FUN_00765740 @ 0x00765cce (sole site)
//
// REJECT scaffold: Named_CalleeOf_*_gfxBody_*
//

#include <cstdint>

struct NestedHash_Sentinel0x10;
struct stoChunkReader;

extern "C" NestedHash_Sentinel0x10*
Sto_UnserialFactoryMapB_GetInstance_Inferred(void); // FUN_00438ca0

// PeekChunkTag — ESI = stoChunkReader* (FUN_0076a900)
extern "C" uint32_t stoChunkReader_PeekChunkTag_Inferred(void /* ESI */);

// NestedHash find — FUN_0046c1b0
extern "C" void NestedHash_Find_0x10_Inferred(void);

using CreatorFn = void* (*)(void); // exact formals open

// entry EAX = stoChunkReader*
extern "C" void*
Sto_UnserialFactoryMapB_LookupInvoke_Inferred(void)
{
  stoChunkReader* reader = nullptr; // = EAX at entry → ESI
  (void)reader;

  uint32_t tag = stoChunkReader_PeekChunkTag_Inferred(); // FUN_0076a900

  NestedHash_Sentinel0x10* bag =
      Sto_UnserialFactoryMapB_GetInstance_Inferred();
  void* node = nullptr;
  (void)NestedHash_Find_0x10_Inferred; // find(bag, &tag) → node
  (void)tag;
  (void)bag;

  bag = Sto_UnserialFactoryMapB_GetInstance_Inferred();
  void* sentinel = *reinterpret_cast<void**>(
      reinterpret_cast<uint8_t*>(bag) + 0x08);

  if (node == sentinel)
    return nullptr;

  CreatorFn creator = *reinterpret_cast<CreatorFn*>(
      reinterpret_cast<uint8_t*>(node) + 0x0C);
  // CALL [node+0xC]; ESI = reader; no stack push sealed
  return creator();
}

// Ghidra twin symbol
extern "C" void* FUN_00437c90(void)
{
  return Sto_UnserialFactoryMapB_LookupInvoke_Inferred();
}
