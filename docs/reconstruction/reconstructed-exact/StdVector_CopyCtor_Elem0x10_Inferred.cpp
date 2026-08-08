// =============================================================================
// StdVector_CopyCtor_Elem0x10_Inferred  (FUN_005114e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005114e0
// Address:   0x005114e0–0x00511583 inclusive (164 B / 0xA4)
// System:    skills-abilities (partition R13-029; parent dual 0x00511950)
// Dual A/B:  2026-08-05 R13-029 OWN-ONLY; dual start 2686
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI bytes.
// Bit-for-bit / runtime / diff: OPEN (never Runtime Confirmed here)
// =============================================================================
// PURPOSE
//   MSVC-style std::vector<T> copy constructor for element stride 0x10
//   (16-byte / 4-dword POD). Zeros dest triad, allocates n*0x10, POD
//   uninitialized range-copy via FUN_005dd920.
//
// ABI
//   thiscall: ECX = dest vector*; stack = const src vector*; RET 4; returns this.
//   Vector layout: +0 allocator/proxy (untouched), +4 begin, +8 end, +0xC capEnd.
//
// Callers (OWN evidence only — not dualled here)
//   FUN_005118b0 buynode Node24 @ 0x00511912  (LEA ECX,[ESI+0x10])
//   FUN_0050ba90 skill-map value build @ 0x0050bb93, 0x0050bbae
//
// Callees
//   FUN_004540b0  length_error / "vector too long" (noreturn)
//   operator_new  allocate n*0x10
//   FUN_005dd920  POD uninit_copy 4 dwords/element
// =============================================================================

#include <cstdint>
#include <cstring>
#include <new>

struct StdVector_Elem0x10 {
  void* _proxy_or_alloc; // +0 (untouched by this unit)
  uint8_t* begin;        // +4
  uint8_t* end;          // +8
  uint8_t* capEnd;       // +0xC
};

// Residual range-copy: for each 0x10-byte element, store 4 dwords (null dest skip).
extern "C" uint8_t* FUN_005dd920(const uint8_t* first, const uint8_t* last, uint8_t* dest);
// Noreturn length_error helper (decomp may fake-assign return — ignore).
extern "C" void FUN_004540b0(/*ECX*/ StdVector_Elem0x10* self);

extern "C" StdVector_Elem0x10* __thiscall StdVector_CopyCtor_Elem0x10_Inferred(
    /*ECX*/ StdVector_Elem0x10* self,
    /*stack*/ const StdVector_Elem0x10* src)
{
  uint32_t n = 0;
  if (src->begin != nullptr) {
    // Machine: SUB end,begin; SAR 4
    n = static_cast<uint32_t>(src->end - src->begin) >> 4;
  }

  self->begin = nullptr;
  self->end = nullptr;
  self->capEnd = nullptr;

  if (n == 0)
    return self;

  if (n > 0x0FFFFFFFu) {
    FUN_004540b0(self); // noreturn
  }

  const uint32_t bytes = n << 4; // * 0x10
  uint8_t* buf = static_cast<uint8_t*>(operator new(bytes));
  self->begin = buf;
  self->end = buf;
  self->capEnd = buf + bytes;

  // Uninitialized POD copy [src.begin, src.end) → buf; returns write cursor.
  self->end = FUN_005dd920(src->begin, src->end, buf);
  return self;
}

// Ghidra placeholder twin: FUN_005114e0.cpp
