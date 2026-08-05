// =============================================================================
// NDResourceCache_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d470
// Address:   0x0075d470–0x0075d506  (151 B / 0x97; autoassault.exe base 0x400000)
// System:    NDResourceCache host (DAT_00d1f050); embedded at AssManager+0x0c
// Generated: 2026-07-23 scaffold as FUN_0075d470; dual A/B seal 2026-07-29 (W35-B)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Placement-construct the NDResourceCache / Ass resource host:
//     NestedHash@+0, aux zeros, CS@+0x3c, std tree@+0x5c, AssPreloader ensure@+0x6c.
//   Publishes DAT_00d1f050 = self. Outer AssManager client (FUN_007543b0 /
//   DAT_00d1f058) embeds this object at outer+0x0c.
//
// ABI:
//   stack(self*); RET 4; returns self in EAX. Not ECX-thiscall.
//
// REJECT: scaffold Named_CalleeOf_*Client_InitI* product aliases.
//

#include <cstdint>
#include <windows.h>

// Nested / dualed callees (not owned here)
extern "C" void* __stdcall NestedHash_Ctor_Sentinel0x14_Inferred(void* self); // FUN_0043bdf0
extern "C" void* StdTree_AllocNode_0x1c_Inferred(void);                       // FUN_005ae2b0
extern "C" void  __stdcall AssManager_EnsureAssPreloader_Inferred(void* host); // FUN_0075d3c0

// Global published by this ctor
extern "C" void* DAT_00d1f050;

// Host layout (writes sealed; product English open)
struct NDResourceCache {
  uint8_t  nested_hash[0x28]; // +0x00 NestedHash (sentinel 0x14 + 9 buckets)
  // +0x28..+0x2b unwritten by this ctor
  uint32_t aux_2c;            // +0x2c
  uint32_t aux_30;            // +0x30
  uint32_t aux_34;            // +0x34
  uint32_t aux_38;            // +0x38
  CRITICAL_SECTION cs;        // +0x3c  (MSVC; DebugInfo..SpinCount)
  // CS ends @ +0x54; lock-enable flag written as byte @ +0x54 = 1
  uint8_t  cs_initialized;    // +0x54 (overlay end of CS / adjacent flag)
  uint8_t  pad_55[0x07];
  void*    tree_head;         // +0x5c  StdTree node 0x1c
  uint32_t tree_size;         // +0x60
  uint32_t field_64;          // +0x64
  uint8_t  field_68;          // +0x68
  uint8_t  pad_69[0x03];
  void*    ass_preloader;     // +0x6c  AssPreloader* (Ensure may construct)
}; // span ≥ 0x70

extern "C" NDResourceCache* __stdcall NDResourceCache_Ctor_Inferred(NDResourceCache* self)
{
  // SEH LAB_009acd33 omitted in clean (present in retail body)
  DAT_00d1f050 = self;

  NestedHash_Ctor_Sentinel0x14_Inferred(self);

  self->aux_2c = 0;
  self->aux_30 = 0;
  self->aux_34 = 0;
  self->aux_38 = 0;

  InitializeCriticalSection(&self->cs);
  self->cs_initialized = 1;

  void* head = StdTree_AllocNode_0x1c_Inferred();
  self->tree_head = head;
  // Head pattern (sealed; matches W16-G StdTree_AllocNode dual):
  *reinterpret_cast<uint8_t*>(static_cast<uint8_t*>(head) + 0x19) = 1; // isnil
  *reinterpret_cast<void**>(static_cast<uint8_t*>(head) + 4) = head;   // parent
  *reinterpret_cast<void**>(head) = head;                              // left
  *reinterpret_cast<void**>(static_cast<uint8_t*>(head) + 8) = head;   // right
  self->tree_size = 0;

  self->field_64 = 0;
  self->field_68 = 0;
  self->ass_preloader = nullptr;
  AssManager_EnsureAssPreloader_Inferred(self);

  return self;
}

// Ghidra twin symbol
extern "C" NDResourceCache* __stdcall FUN_0075d470(NDResourceCache* self)
{
  return NDResourceCache_Ctor_Inferred(self);
}
