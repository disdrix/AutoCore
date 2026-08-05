// =============================================================================
// Host_ResetHashQueuesVectors_Inferred  (aa_004bbeb0)
// -----------------------------------------------------------------------------
// Address:   0x004bbeb0  (autoassault.exe, image base 0x400000)
// Wave:      W31-N OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            ECX targets and tail-JMP sealed from bytes (decompiler loses them).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

struct VtblSlot1 {
  void* slot0;
  void (__fastcall *method_plus4)(void* self); // vtbl[+4]
};

struct IfaceVtbl4 {
  VtblSlot1* vtbl;
};

// Sealed W30-G: CNDHash Recreate for stamp family 009cb450.
extern "C" void __fastcall CNDHash_Recreate_009cb450(void* hash /*ECX*/, uint32_t log2 /*stack*/);
// Locked-list drain under CS; throws if traversal flag set (FUN_004bc580).
extern "C" void __fastcall FUN_004bc580(void* list_host /*ECX*/);
// Dword vector resize (size, fill); size=0 clears (FUN_00410420).
extern "C" void __fastcall FUN_00410420(void* vec /*ECX*/, uint32_t new_size, uint32_t fill);

struct Host_ResetTables {
  uint32_t _pad00;
  IfaceVtbl4* pIface04;     // +0x04
  IfaceVtbl4* pIface08;     // +0x08
  uint8_t flag0c;           // +0x0c
  uint8_t flag0d;           // +0x0d
  uint8_t _pad0e[2];
  uint32_t _pad10;
  uint32_t _pad14;
  void* pHash18;            // +0x18 CNDHash* (009cb450)
  void* pQueue1c;           // +0x1c
  void* pQueue20;           // +0x20
  void* pQueue24;           // +0x24
  uint32_t vec28[4];        // +0x28 embedded dword vector (begin/end/cap/...)
  uint32_t vec38[4];        // +0x38
  uint32_t vec48[4];        // +0x48
};

// ECX = host. Bare RET. void.
// Recreate tableC hash (log2=5), drain three locked queues, clear three dword
// vectors, optionally invoke owned iface vtbl[+4] (tail on second).
extern "C" void __fastcall Host_ResetHashQueuesVectors_Inferred(Host_ResetTables* self)
{
  CNDHash_Recreate_009cb450(self->pHash18, 5);
  FUN_004bc580(self->pQueue1c);
  FUN_004bc580(self->pQueue20);
  FUN_004bc580(self->pQueue24);
  FUN_00410420(&self->vec48, 0, 0);
  FUN_00410420(&self->vec28, 0, 0);
  FUN_00410420(&self->vec38, 0, 0);

  if (self->flag0c != 0) {
    IfaceVtbl4* p = self->pIface04;
    p->vtbl->method_plus4(p);
  }
  if (self->flag0d != 0) {
    IfaceVtbl4* p = self->pIface08;
    // retail: POP ESI; JMP [vtbl+4]  — tail call
    p->vtbl->method_plus4(p);
    return;
  }
}

// Scaffold alias
extern "C" void __fastcall FUN_004bbeb0(Host_ResetTables* self)
{
  Host_ResetHashQueuesVectors_Inferred(self);
}
