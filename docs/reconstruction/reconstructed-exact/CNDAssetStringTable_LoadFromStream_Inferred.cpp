// =============================================================================
// CNDAssetStringTable_LoadFromStream_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0099c1c0
// Address:   0x0099c1c0–0x0099c29b inclusive (220 B / 0xDC, autoassault.exe base 0x400000)
// System:    CND asset string table stream load
// Generated: 2026-08-04 W37-I dual A/B (decompile + read_memory + caller context)
// Exactness: Behavior-preserving outer CF + ABI. Host layout partially opaque.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0099c1c0
// Product:   sole wrapper of CNDAssetStringTable::Unserialize (FUN_0099bba0 / W34-J)
// =============================================================================
//
// PURPOSE:
//   If stream is null → return false.
//   Else construct a temporary host shell (vtbl PTR_FUN_00a983b4 + ResourceCache-family
//   body), configure field10=0x4000 / flag=1, call CNDAssetStringTable_Unserialize,
//   tidy optional vector, destroy host, return unserialize AL.
//
// ABI:
//   one stack formal (stream*); RET 4; returns uint8_t in AL;
//   SEH LAB_009b13f2; epilogue ADD ESP,0xA8; RET 4.
//
// CALLER:
//   FUN_004d73c0 @ 0x004d74d7 — when *(host+0x8c) in (0x30,0x34);
//   RAII pair FUN_0099c140(0) / FUN_0099c130 around this call.
// =============================================================================

#include <cstdint>

struct StreamReader;

extern "C" void* PTR_FUN_00a983b4;

// ResourceCache-family (W31-F family)
extern "C" void* FUN_00989cf0(void* cache); // ctor
extern "C" void  FUN_00989c10(void* cache); // dtor
// EDI=cache, ECX=field10, stack flag, RET 4
extern "C" void  ResourceCache_SetField10AndConfigure_Inferred(uint32_t flag);

// Product unserialize — 3 stack args, RET 0x0C, AL=1
extern "C" uint8_t CNDAssetStringTable_Unserialize(void* host_table,
                                                   void* scratch,
                                                   StreamReader* reader);

extern "C" void FUN_00426ed0(void* a, void* b);
extern "C" void operator_delete(void* p);

// Retail: stream on stack; RET 4; AL success
extern "C" uint8_t CNDAssetStringTable_LoadFromStream_Inferred(StreamReader* stream)
{
  // SEH LAB_009b13f2 omitted

  if (stream == nullptr)
    return 0;

  // Stack host (simplified):
  //   host_base.vtbl = PTR_FUN_00a983b4
  //   cache body via FUN_00989cf0
  //   optional vector triple zeroed
  alignas(4) uint8_t host_storage[0x90];
  alignas(4) uint8_t scratch[4];
  void* vec_begin = nullptr;
  void* vec_end = nullptr;
  void* vec_cap = nullptr;
  (void)vec_end;
  (void)vec_cap;

  void* cache = host_storage + 4; // decompiler local_90; vtbl at local_94
  FUN_00989cf0(cache);
  *reinterpret_cast<void**>(host_storage) = &PTR_FUN_00a983b4;

  // Bytes: MOV ECX,0x4000; PUSH 1; LEA EDI,cache; CALL FUN_00989ef0
  // Cannot express EDI-this in portable C; document ABI in comment.
  // ResourceCache_SetField10AndConfigure_Inferred(/*flag*/1) with ECX=0x4000, EDI=cache
  (void)0x4000;
  ResourceCache_SetField10AndConfigure_Inferred(1);

  uint8_t ok = CNDAssetStringTable_Unserialize(host_storage, scratch, stream);

  if (vec_begin != nullptr) {
    FUN_00426ed0(vec_end, /*retail second*/nullptr);
    operator_delete(vec_begin); // decompiler false-noreturn
  }

  *reinterpret_cast<void**>(host_storage) = &PTR_FUN_00a983b4;
  FUN_00989c10(cache);
  return ok;
}
