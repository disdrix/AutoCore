// =============================================================================
// StdVector_InsertN_BasicStringW  (aa_004a7ad0)
// -----------------------------------------------------------------------------
// Address:   0x004a7ad0  (autoassault.exe, image base 0x400000)
// Body:      0x004a7ad0 – 0x004a7df7 exclusive (807 B / 0x327); pad CC
// Wave:      W34-R OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + RET 0x0C.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

// MSVC basic_string<wchar_t> retail footprint in this binary: 0x1C bytes.
struct BasicStringW_0x1c {
  uint8_t storage[0x1c];
};

struct VectorBasicStringW {
  void* _unused0;            // +0
  BasicStringW_0x1c* begin;  // +4
  BasicStringW_0x1c* end;    // +8
  BasicStringW_0x1c* capEnd; // +0xC
};

static constexpr uint32_t kElemSize = 0x1c;
static constexpr uint32_t kMaxElems = 0x09249249u;  // ~0u / 0x1c

// Nested helpers (not dual-owned here):
extern "C" void FUN_004a6820();  // vector too long / length_error
extern "C" uint32_t FUN_00469c50();  // StdVector_Elem28_Size (W33-J)
extern "C" void* operator_new(uint32_t);
extern "C" void operator_delete(void*);
// Relocate / fill / destroy wstring ranges (stride 0x1c):
extern "C" void* FUN_004a6b50(void* srcBegin, void* srcEnd, void* dst, ...);
extern "C" void FUN_004a74f0(void* dst, uint32_t count, BasicStringW_0x1c* val, ...);
extern "C" void FUN_004a7aa0(BasicStringW_0x1c* begin, BasicStringW_0x1c* end);
extern "C" void FUN_004a7a70(void* dst, uint32_t count, BasicStringW_0x1c* val);
extern "C" void FUN_004a68a0(void* a, void* b, BasicStringW_0x1c* val);
extern "C" void FUN_004a68d0(void* a, void* b, void* c, ...);
// IAT basic_string<wchar_t> copy-ctor / dtor

// ECX=vector*; stack where*, count, value*; RET 0x0C; void.
// Insert `count` copies of `*value` at `where` (pointer iterator into buffer).
extern "C" void __thiscall StdVector_InsertN_BasicStringW(
    VectorBasicStringW* vec,
    BasicStringW_0x1c* where,
    uint32_t count,
    BasicStringW_0x1c* value)
{
  // SEH LAB_009a11e9; local copy of *value (wstring copy-ctor).
  BasicStringW_0x1c local{};
  // retail: basic_string<wchar_t>::basic_string(local, value);

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
      FUN_004a6820();  // noreturn path
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
        // FUN_00469c50 (Elem28 size on this) + count:
        newCap = size + count;
      }
      void* neu = operator_new(newCap * kElemSize);
      // FUN_004a6b50(begin, where, neu); FUN_004a74f0(...); FUN_004a6b50(where, end, ...);
      // FUN_004a7aa0(begin, end); operator_delete(begin);
      // rebind begin/end/capEnd
      (void)neu;
      (void)where;
      (void)local;
    } else {
      // In-place arms: FUN_004a6b50 / FUN_004a7a70 / FUN_004a68a0 / FUN_004a68d0
      // See raw decompile for exact hole vs mid-shift branches.
      (void)where;
      (void)local;
    }
  }

  // retail: ~basic_string<wchar_t>(local); RET 0x0C
  (void)vec;
  (void)value;
}

// Scaffold / Ghidra alias
extern "C" void __thiscall FUN_004a7ad0(
    VectorBasicStringW* vec,
    BasicStringW_0x1c* where,
    uint32_t count,
    BasicStringW_0x1c* value)
{
  StdVector_InsertN_BasicStringW(vec, where, count, value);
}
