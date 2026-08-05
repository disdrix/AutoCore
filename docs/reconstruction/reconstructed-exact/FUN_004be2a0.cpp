// =============================================================================
// ListTrackedObj_CompleteDtor  (aa_004be2a0)
// -----------------------------------------------------------------------------
// Address:   0x004be2a0  (autoassault.exe, image base 0x400000)
// Wave:      W30-P OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite from decompile + full-body read_memory.
//            Ignore Ghidra false-noreturn on operator_delete (bytes fall through).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// Dual base vtbl installed at end of complete dtor.
extern uint32_t PTR_LAB_009cb5cc;

extern uint32_t DAT_00b03734;
extern uint32_t DAT_00b0373c;
extern void* DAT_00b03730;

extern "C" void __fastcall FUN_004bf740(void* list_host /* this+0x10 */);
extern "C" void __fastcall FUN_0074b580(void* member); // empty body
extern "C" void __fastcall FUN_00763f60(void* member);
extern "C" void __cdecl operator_delete(void* p);

// Large list-tracked object. Complete dtor only (does not free this).
// Callers typically: ListTrackedObj_CompleteDtor(p); operator_delete(p);
extern "C" void __fastcall ListTrackedObj_CompleteDtor(uint32_t* self)
{
  // SEH: LAB_009a1833, EH state starts at 9 (omitted structural detail).

  // Flag @ +0x5D0 (param_1[0x174])
  if (*reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(self) + 0x5D0) != 0) {
    // List cleanup around +0x10/+0x14/+0x18 (nested blob optional vtbl[+8] + delete).
    // Bytes walk more than one node; then:
    FUN_004bf740(reinterpret_cast<char*>(self) + 0x10);
  }

  DAT_00b03734 -= 1;

  // Intrusive DLL unlink: prev@+0, next@+4
  uint32_t* prev = reinterpret_cast<uint32_t*>(self[0]);
  uint32_t* next = reinterpret_cast<uint32_t*>(self[1]);
  prev[1] = self[1];
  next[0] = self[0];

  DAT_00b0373c -= 1;
  if (DAT_00b0373c == 0) {
    void* global_inst = DAT_00b03730;
    if (global_inst != nullptr) {
      ListTrackedObj_CompleteDtor(reinterpret_cast<uint32_t*>(global_inst));
      operator_delete(global_inst);
    }
    DAT_00b03730 = nullptr;
  } else if (static_cast<int32_t>(DAT_00b0373c) < 0) {
    DAT_00b0373c = 0;
  }

  // Vector buffer @ +0x58C / +0x590 / +0x594
  void* buf_a = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x58C);
  if (buf_a != nullptr) {
    operator_delete(buf_a);
  }
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x58C) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x590) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x594) = 0;

  // Vector buffer @ +0x57C / +0x580 / +0x584
  void* buf_b = *reinterpret_cast<void**>(reinterpret_cast<char*>(self) + 0x57C);
  if (buf_b != nullptr) {
    operator_delete(buf_b);
  }
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x57C) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x580) = 0;
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 0x584) = 0;

  // Member dtors EH 6..1
  FUN_0074b580(reinterpret_cast<char*>(self) + 0x474);
  FUN_0074b580(reinterpret_cast<char*>(self) + 0x444);
  FUN_0074b580(reinterpret_cast<char*>(self) + 0x414);
  FUN_00763f60(reinterpret_cast<char*>(self) + 0x2C8);
  FUN_00763f60(reinterpret_cast<char*>(self) + 0x17C);
  FUN_00763f60(reinterpret_cast<char*>(self) + 0x30);

  // Base vtbl install (dual subobjects)
  self[8] = reinterpret_cast<uint32_t>(&PTR_LAB_009cb5cc); // +0x20
  self[4] = reinterpret_cast<uint32_t>(&PTR_LAB_009cb5cc); // +0x10
}

// Scaffold alias
extern "C" void __fastcall FUN_004be2a0(uint32_t* self)
{
  ListTrackedObj_CompleteDtor(self);
}
