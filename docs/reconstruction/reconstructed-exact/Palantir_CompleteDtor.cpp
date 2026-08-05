// =============================================================================
// Palantir_CompleteDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00754320
// Address:   0x00754320–0x007543A9 exclusive (137 B / 0x89, autoassault.exe base 0x400000)
// System:    client / Palantir host complete destructor
// Generated: 2026-07-29 W34-K dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes win over decompiler SEH restore.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00754320
// Evidence:  vtbl peer FUN_00754480 logs Palantir.cpp / "Palantir::ResetDevice failed..."
// =============================================================================
//
// PURPOSE:
//   MSVC complete destructor for the Palantir host object:
//   install dtor-phase vtbl, destroy tail members (string + path StringVecShell),
//   destroy nested subobjects at +0x30 and +0x10, then clear globals
//   DAT_00d1f1fc (path list shell) and DAT_00d1f058 (host singleton).
//   Does NOT free `this` — scalar deleting wrapper is FUN_004447e0 (vtbl[0]).
//
// ABI (bytes):
//   ECX = Palantir*  (MOV ESI,ECX)
//   no stack formals; bare RET (C3); void
//   SEH LAB_009afd1c
//
// Layout used:
//   +0x00  vtbl
//   +0x10  subobject → FUN_00964d00 (cdecl, stack this*)
//   +0x30  subobject → FUN_0075d8e0 (cdecl, stack this*)
//   +0xA0  StringVecShell (path list; also published as DAT_00d1f1fc)
//   +0xB4  basic_string
// =============================================================================

#include <cstdint>

struct StringVecShell {
  void*    pad0;
  uint8_t* begin;
  uint8_t* end;
  uint8_t* capEnd;
};

// Opaque host; only offsets sealed by this dtor are named.
struct Palantir {
  void* vtbl;                 // +0x00
  uint8_t body_10[0x10 - 4];  // +0x04 .. pad to +0x10
  // +0x10 subobject (FUN_00964d00)
  // +0x30 subobject (FUN_0075d8e0)
  // +0xA0 StringVecShell
  // +0xB4 basic_string
};

extern "C" void* PTR_FUN_00a9f76c; // dtor-phase vtbl

extern "C" void __thiscall BasicString_Dtor(void* self); // IAT 0x009c62f4
extern "C" void __fastcall StringVec_Tidy(StringVecShell* self); // 0x00431ae0
extern "C" void __cdecl FUN_0075d8e0(void* sub_at_30); // nested dtor (unowned dual)
extern "C" void __cdecl FUN_00964d00(void* sub_at_10); // nested dtor (unowned dual)

extern "C" StringVecShell* DAT_00d1f1fc; // path-list shell global
extern "C" void*           DAT_00d1f058; // Palantir host global

// Retail: ECX=this; bare ret; no operator_delete
extern "C" void __fastcall Palantir_CompleteDtor(Palantir* self)
{
  uint8_t* base = reinterpret_cast<uint8_t*>(self);

  self->vtbl = &PTR_FUN_00a9f76c;

  BasicString_Dtor(base + 0xB4);

  StringVec_Tidy(reinterpret_cast<StringVecShell*>(base + 0xA0));
  DAT_00d1f1fc = nullptr;

  FUN_0075d8e0(base + 0x30);
  FUN_00964d00(base + 0x10);

  DAT_00d1f058 = nullptr;
}

// Scaffold alias (Ghidra name)
extern "C" void __fastcall FUN_00754320(Palantir* self)
{
  Palantir_CompleteDtor(self);
}
