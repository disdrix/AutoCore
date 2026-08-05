// =============================================================================
// NDResourceCache_IsKeyPresent_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d610
// Address:   0x0075d610–0x0075d63f  (48 B / 0x30; autoassault.exe base 0x400000)
// Ghidra:    FUN_0075d610
// System:    NDResourceCache / NestedHash map present-check
// Dual:      W36-E 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Predicate: does the NestedHash map (NDResourceCache head) contain `key`
//   with a non-null value pointer at node+0x0C?
//   Thin wrapper over HashMap_FindIterator_Inferred (W21-N).
//
// ABI:
//   thiscall ECX = cache/map*; stack (const void* key); RET 4; EAX 0/1.
//
// REJECT: scaffold Named_CalleeOf_*VOG_DEBUG* product aliases.
//

#include <cstdint>

// Nested dual (not owned here): EDI=map, EBX=key*, stack out_it*, RET 4
extern "C" void** __stdcall HashMap_FindIterator_Inferred(void** out_it); // FUN_0044e8c0

// NestedHash / NDResourceCache map head (value nodes: key@+8, value@+0x0C; end@map+0x08)
struct NestedHashMapHead {
  uint32_t _pad00[2];
  void*    end; // +0x08 end sentinel iterator
  // +0x14 bucket table, +0x20 mask, +0x24 bucket count (via FindIterator)
};

struct HashMapNode {
  void*    next;   // +0x00
  uint32_t _pad04;
  uint32_t key;    // +0x08
  void*    value;  // +0x0C resource*
};

extern "C" uint32_t __fastcall NDResourceCache_IsKeyPresent_Inferred(
    NestedHashMapHead* cache /*ECX*/,
    const void* key /*stack*/)
{
  // Machine: PUSH EBX; MOV EBX, key*; PUSH EDI; MOV EDI, ECX;
  //          LEA out,&key_slot; CALL FindIterator; compare; RET 4
  void* it = const_cast<void*>(key); // stack slot reused as out_it

  // Establish register formals for nested find (documented machine ABI)
  // EDI = cache, EBX = key*  — required by HashMap_FindIterator_Inferred
  HashMap_FindIterator_Inferred(&it);

  if (it != cache->end) {
    auto* node = static_cast<HashMapNode*>(it);
    if (node->value != nullptr) {
      return 1;
    }
  }
  return 0;
}
