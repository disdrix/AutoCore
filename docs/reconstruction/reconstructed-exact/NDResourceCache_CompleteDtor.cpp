// =============================================================================
// NDResourceCache_CompleteDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_0075d8e0
// Address:   0x0075d8e0–0x0075d9BF exclusive (223 B / 0xDF, autoassault.exe base 0x400000)
// System:    assets / NDResourceCache + AssManager host complete destructor
// Generated: 2026-07-29 W35-I dual A/B (decompile + read_memory past Ghidra end)
// Exactness: Behavior-preserving CF + ABI from full-body hex. Bytes win.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_0075d8e0  (body end 0x0075d955 is WRONG — noreturn truncate)
// Evidence:  Palantir+0x30 subobject; DAT_00d1f050 clear; AssPreloader log path.
// =============================================================================
//
// PURPOSE:
//   Complete destructor for the NDResourceCache / AssManager-shaped host that
//   lives at Palantir+0x30 and is published as DAT_00d1f050 by ctor FUN_0075d470.
//   Tears down NestedHash entries, AssPreloader (+0x6c), std tree (+0x58),
//   critical section (+0x3c), OwnedPtrTable (+0x28), list shell (+0x04), then
//   clears DAT_00d1f050. Does NOT free `self` (embedded subobject / stack this).
//
// ABI (bytes):
//   stack arg0 = NDResourceCache* self  (MOV EBP,[esp+0x1c])
//   RET 4; void
//   SEH LAB_009adb86
//
// Callers: Palantir_CompleteDtor (PUSH self+0x30); SEH Unwind sites.
// =============================================================================

#include <cstdint>

struct NDResourceCache {
  // +0x00 NestedHash_Sentinel0x14 head (FUN_0043bdf0)
  // +0x04 list / aux shell (FUN_00415e90)
  // +0x14.. table block (deleted if non-null)
  // +0x28 OwnedPtrTable (FUN_0040d9c0)
  // +0x3c CRITICAL_SECTION
  // +0x54 flag byte (1 after ctor)
  // +0x58 std tree host (head @ +0x5c)
  // +0x6c AssPreloader*
};

extern "C" void* DAT_00d1f050;

// Nested / library callees (unowned duals except OwnedPtrTable_Clear sealed elsewhere)
extern "C" void __fastcall FUN_0075d6f0(void* /*unused_ecx*/); // ESI=self NestedHash teardown
extern "C" void __fastcall FUN_00971050(void* preloader);      // ECX=AssPreloader*
extern "C" void __stdcall FUN_00971180(void* preloader);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void* __stdcall FUN_0043c220(void* out, void* begin, void* end); // EDI=tree host
extern "C" void __stdcall DeleteCriticalSection(void* cs);
extern "C" void __fastcall FUN_0040d9c0(void); // ESI=OwnedPtrTable* (self+0x28)
extern "C" void __fastcall FUN_00415e90(void); // ESI=list shell (self+0x04)

// Retail: stack self*; RET 4; no operator_delete(self)
extern "C" void __stdcall NDResourceCache_CompleteDtor(NDResourceCache* self)
{
  uint8_t* base = reinterpret_cast<uint8_t*>(self);

  // NestedHash / tracked-resource teardown (ESI = self)
  FUN_0075d6f0(nullptr);

  void* pre = *reinterpret_cast<void**>(base + 0x6c);
  if (pre != nullptr) {
    FUN_00971050(pre);
    pre = *reinterpret_cast<void**>(base + 0x6c);
    if (pre != nullptr) {
      FUN_00971180(pre);
      operator_delete(pre);
    }
    *reinterpret_cast<void**>(base + 0x6c) = nullptr;
  }

  // Std tree at +0x58: erase all nodes, free head, null head/size
  void** tree = reinterpret_cast<void**>(base + 0x58);
  void* head = tree[1]; // +0x5c
  void* begin = *reinterpret_cast<void**>(head);
  uint8_t out_it[4];
  FUN_0043c220(out_it, begin, head);
  operator_delete(tree[1]);
  tree[1] = nullptr;
  tree[2] = nullptr;

  DeleteCriticalSection(base + 0x3c);
  base[0x54] = 0;

  // OwnedPtrTable at +0x28 (ESI convention in retail)
  FUN_0040d9c0();

  void* blk = *reinterpret_cast<void**>(base + 0x14);
  if (blk != nullptr) {
    operator_delete(blk);
  }
  *reinterpret_cast<void**>(base + 0x14) = nullptr;
  *reinterpret_cast<uint32_t*>(base + 0x18) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x1C) = 0;

  // List shell at +0x04 (ESI convention): tidy nodes, then free head block at +0x08
  FUN_00415e90();
  operator_delete(*reinterpret_cast<void**>(base + 0x08));
  *reinterpret_cast<void**>(base + 0x08) = nullptr;

  DAT_00d1f050 = nullptr;
}

// Scaffold alias (Ghidra name)
extern "C" void __stdcall FUN_0075d8e0(NDResourceCache* self)
{
  NDResourceCache_CompleteDtor(self);
}
