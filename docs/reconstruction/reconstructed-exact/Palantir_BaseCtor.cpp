// =============================================================================
// Palantir_BaseCtor
// -----------------------------------------------------------------------------
// Stable ID: aa_007543b0
// Address:   0x007543b0–0x0075447C exclusive (204 B / 0xCC, autoassault.exe base 0x400000)
// System:    client / Palantir host base constructor
// Generated: 2026-07-29 W35-I dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes win over decompiler signature.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_007543b0
// Evidence:  vtbl PTR_FUN_00a9f76c sealed W34-K as Palantir (ResetDevice log peer);
//            pair complete dtor Palantir_CompleteDtor @ 0x00754320.
// =============================================================================
//
// PURPOSE:
//   Placement / base constructor for the Palantir host object:
//   publish DAT_00d1f058, install Palantir vtbl, CoInitializeEx apartment,
//   construct nested NDResourceCache/AssManager at +0x30 (FUN_0075d470 → DAT_00d1f050),
//   publish path-list StringVecShell at +0xA0 as DAT_00d1f1fc, construct basic_string
//   "." at +0xB4, set tail flags. Returns self. Does not allocate self.
//
// ABI (bytes):
//   stack arg0 = Palantir* self  (MOV ESI,[esp+0x18] after SEH + push ebx/esi)
//   RET 4; EAX = self
//   SEH LAB_009afd58
//
// Sole caller: FUN_007a26c0 (extended host ctor; replaces vtbl with PTR_FUN_00a97170).
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;
  uint8_t* end;
  uint8_t* capEnd;
};

// Opaque host; offsets sealed by this ctor + W34-K complete dtor.
struct Palantir {
  void* vtbl; // +0x00 → PTR_FUN_00a9f76c
  // +0x04..+0x2F: flags / copied globals / zeros / -1
  // +0x30: NDResourceCache host (FUN_0075d470 / FUN_0075d8e0)
  // +0xA0: StringVecShell path list
  // +0xB4: basic_string
  // +0xD0: flags
};

extern "C" void* PTR_FUN_00a9f76c;
extern "C" void* DAT_00d1f01c;
extern "C" void* DAT_00d1f020;
extern "C" Palantir* DAT_00d1f058;
extern "C" StringVecShell* DAT_00d1f1fc;

// Nested host ctor (unowned dual): stack self*; RET 4; sets DAT_00d1f050.
extern "C" void* __stdcall FUN_0075d470(void* cache_at_30);

// IAT
extern "C" long __stdcall CoInitializeEx(void* reserved, unsigned long coinit);
extern "C" void __thiscall BasicString_CtorFromCStr(void* self, const char* s);

// Retail: stack self*; RET 4; EAX=self
extern "C" Palantir* __stdcall Palantir_BaseCtor(Palantir* self)
{
  uint8_t* base = reinterpret_cast<uint8_t*>(self);

  DAT_00d1f058 = self;

  self->vtbl = &PTR_FUN_00a9f76c;
  base[0x04] = 0;
  base[0x05] = 1;
  base[0x06] = 0;

  *reinterpret_cast<void**>(base + 0x08) = DAT_00d1f01c;
  *reinterpret_cast<void**>(base + 0x0C) = DAT_00d1f020;

  *reinterpret_cast<uint32_t*>(base + 0x14) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x18) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x1C) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x20) = 0;

  CoInitializeEx(nullptr, 2u); // COINIT_APARTMENTTHREADED

  *reinterpret_cast<uint32_t*>(base + 0x24) = 0xFFFFFFFFu;
  *reinterpret_cast<uint32_t*>(base + 0x28) = 0;
  *reinterpret_cast<uint32_t*>(base + 0x2C) = 0;

  FUN_0075d470(base + 0x30);

  auto* shell = reinterpret_cast<StringVecShell*>(base + 0xA0);
  DAT_00d1f1fc = shell;
  shell->begin = nullptr;
  shell->end = nullptr;
  shell->capEnd = nullptr;

  BasicString_CtorFromCStr(base + 0xB4, ".");

  base[0xD0] = 1;
  base[0xD1] = 0;
  *reinterpret_cast<uint32_t*>(base + 0xD4) = 0;

  return self;
}

// Scaffold alias (Ghidra name)
extern "C" Palantir* __stdcall FUN_007543b0(Palantir* self)
{
  return Palantir_BaseCtor(self);
}
