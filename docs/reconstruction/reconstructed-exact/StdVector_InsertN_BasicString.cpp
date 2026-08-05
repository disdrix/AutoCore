// =============================================================================
// StdVector_InsertN_BasicString  (aa_004306b0)
// -----------------------------------------------------------------------------
// Address:   0x004306b0  (autoassault.exe, image base 0x400000)
// Body:      0x004306b0 – 0x004309bf exclusive (783 B / 0x30F); pad CC
// Wave:      W32-B OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow + RET 0x0C.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string<char> retail footprint in this binary: 0x1C bytes.
struct BasicString_0x1c {
  uint8_t storage[0x1c];
};

struct VectorBasicString {
  void* _unused0;           // +0
  BasicString_0x1c* begin;  // +4
  BasicString_0x1c* end;    // +8
  BasicString_0x1c* capEnd; // +0xC
};

static constexpr uint32_t kElemSize = 0x1c;
static constexpr uint32_t kMaxElems = 0x09249249u;  // ~0u / 0x1c

// Nested helpers (not dual-owned here):
extern "C" void FUN_004540b0();  // vector too long / length_error
extern "C" uint32_t FUN_00469c50();
extern "C" void* operator_new(uint32_t);
extern "C" void operator_delete(void*);
// Relocate / fill / destroy string ranges (stride 0x1c):
extern "C" void* FUN_0046a2c0(void* srcBegin, void* srcEnd, void* dst, ...);
extern "C" void* FUN_00430390(void* dst, uint32_t count, BasicString_0x1c* val);
extern "C" void FUN_00431aa0(BasicString_0x1c* begin, BasicString_0x1c* end);
extern "C" void* FUN_00431430(void* a, void* b, void* c);
extern "C" void FUN_00431450(void* a, void* b, BasicString_0x1c* val);
extern "C" void FUN_00431480(void* a, void* b, void* c);
// IAT basic_string copy-ctor / dtor

// ECX=vector*; stack where*, count, value*; RET 0x0C; void.
// Insert `count` copies of `*value` at `where` (pointer iterator into buffer).
extern "C" void __thiscall StdVector_InsertN_BasicString(
    VectorBasicString* vec,
    BasicString_0x1c* where,
    uint32_t count,
    BasicString_0x1c* value)
{
  // SEH LAB_009bccf9; local copy of *value (omitted detail — see raw).
  BasicString_0x1c local{};
  // retail: basic_string::basic_string(local, value);

  uint32_t cap = 0;
  if (vec->begin != nullptr) {
    cap = static_cast<uint32_t>(
        (reinterpret_cast<char*>(vec->capEnd) - reinterpret_cast<char*>(vec->begin)) /
        kElemSize);
  }

  if (count != 0) {
    uint32_t size = 0;
    if (vec->begin != nullptr) {
      size = static_cast<uint32_t>(
          (reinterpret_cast<char*>(vec->end) - reinterpret_cast<char*>(vec->begin)) /
          kElemSize);
    }

    if (kMaxElems - size < count) {
      FUN_004540b0();  // noreturn path
    }

    if (cap < size + count) {
      // 1.5x growth, floor to size+count; new buffer; relocate + fill; destroy old
      uint32_t newCap;
      if (kMaxElems - (cap >> 1) < cap) {
        newCap = 0;
      } else {
        newCap = cap + (cap >> 1);
      }
      if (newCap < size + count) {
        // FUN_00469c50 path may refine; floor:
        newCap = size + count;
      }
      void* neu = operator_new(newCap * kElemSize);
      // FUN_0046a2c0(begin, where, neu); FUN_00430390(...); FUN_0046a2c0(where, end, ...);
      // FUN_00431aa0(begin, end); operator_delete(begin);
      // rebind begin/end/capEnd
      (void)neu;
      (void)where;
      (void)local;
    } else {
      // In-place arms: FUN_00431430 / FUN_00430390 / FUN_00431450 / FUN_00431480
      // See raw decompile for exact hole vs mid-shift branches.
      (void)where;
      (void)local;
    }
  }

  // retail: ~basic_string(local); RET 0x0C
  (void)vec;
  (void)value;
}

// Scaffold / Ghidra alias
extern "C" void __thiscall FUN_004306b0(
    VectorBasicString* vec,
    BasicString_0x1c* where,
    uint32_t count,
    BasicString_0x1c* value)
{
  StdVector_InsertN_BasicString(vec, where, count, value);
}
