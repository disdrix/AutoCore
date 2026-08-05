// =============================================================================
// PalantirSub10_OwnedElem_CompleteDtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00735390
// Address:   0x00735390–0x00735403 exclusive (115 B / 0x73, autoassault.exe base 0x400000)
// System:    client / Palantir — complete dtor for owned element of Palantir+0x10 ptr vec
// Generated: 2026-08-04 W37-N dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Bytes win on stdcall RET 4 and EBX for FUN_00465d70.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_00735390
// =============================================================================
//
// PURPOSE:
//   Complete destructor for heap elements stored in the owned-pointer vector under
//   Palantir nested subobject +0x10. Releases COM at +0x48, tidies 0x24-stride vector
//   at +0x70C (FUN_00465d70 / EBX-this), destroys two std::string members (+0x1C, +0).
//   Does NOT free the element host — caller operator_delete does that.
//
// ABI (bytes):
//   stdcall 1 stack formal (Elem*)
//   RET 4 (C2 04 00)
//   void
//
// Sole caller:
//   PalantirSub10_DestroyOwnedPtrVecAndComUninit (0x00964d00, W35-J) @ 0x00964d37
// =============================================================================

#include <cstdint>

struct IUnknownVtbl {
  void* QueryInterface;
  void* AddRef;
  uint32_t (__stdcall* Release)(void* self);
};

struct IUnknown {
  IUnknownVtbl* lpVtbl;
};

// Unowned: EBX-this vector tidy (begin@+4, end@+8, cap@+0xC; elem stride 0x24).
extern "C" void FUN_00465d70(void /* EBX = VecHost* */);

// MSVC std::string dtor via IAT 0x009c62f4 (thiscall ECX).
extern "C" void __fastcall StdString_Dtor(void* self);

struct PalantirSub10_OwnedElem {
  // +0x00
  uint8_t str_00[0x1C];       // std::string (layout size residual; dtor via IAT)
  // +0x1C
  uint8_t str_1c[0x1C];       // std::string
  // +0x38 .. +0x47 residual
  uint8_t pad_38[0x10];
  // +0x48
  IUnknown* com_48;
  // ... residual through +0x70C
  // +0x70C: vector host for FUN_00465d70
};

// Retail: stdcall; RET 4; void
extern "C" void __stdcall PalantirSub10_OwnedElem_CompleteDtor_Inferred(PalantirSub10_OwnedElem* self)
{
  // SEH state 2: COM then vec
  IUnknown* com = self->com_48;
  if (com != nullptr) {
    com->lpVtbl->Release(com);
  }
  self->com_48 = nullptr;

  // Bytes: LEA EBX, [self+0x70C]; CALL FUN_00465d70
  // FUN_00465d70 uses EBX as this (unaff_EBX in decompile).
  uint8_t* vec_host = reinterpret_cast<uint8_t*>(self) + 0x70C;
  (void)vec_host;
  FUN_00465d70();

  // SEH state 0
  StdString_Dtor(reinterpret_cast<uint8_t*>(self) + 0x1C);

  // SEH state -1
  StdString_Dtor(self);
}
