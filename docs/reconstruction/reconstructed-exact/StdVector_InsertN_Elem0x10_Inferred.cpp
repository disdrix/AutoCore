// =============================================================================
// StdVector_InsertN_Elem0x10_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00408640
// Address:   0x00408640–0x0040887c exclusive  (572 B / 0x23C)
// Module:    autoassault.exe (image base 0x400000)
// System:    util / container (MSVC std::vector _Insert_n)
// Generated: 2026-08-04 WQ9H-H dual seal (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime / differential: OPEN
//
// PURPOSE: Insert `count` copies of *value at iterator `where` into a
//   vector of 16-byte (0x10) POD elements. Grows capacity 1.5× when needed.
//
// ABI: ECX = count; EDX = vector* (+4 begin, +8 end, +0xC capEnd);
//      stack: T* where, const T* value (4 dwords); RET 8.
//
// Caller (1): FUN_00930360 @ 0x009305c5 (count forced to 1 at site).
// Twins: StdVector_InsertN_Dword_Inferred (0x004073a0, stride 4 / thiscall);
//        InsertN elem 0x28 residual FUN_00408050.
// Callees undualed: FUN_00409b60, FUN_00407000, FUN_0040a670,
//                   FUN_0045f050, FUN_00465bc0, FUN_00418130.
// =============================================================================

#include <stdint.h>
#include <stdlib.h>

// External helpers (Ghidra names until dualed)
extern "C" uint32_t FUN_00418130(void);
extern "C" void *operator_new(uint32_t size);
extern "C" void operator_delete(void *p);
extern "C" uint32_t FUN_00409b60(uint32_t dst_or_a, uint32_t b, uint32_t c);
extern "C" int FUN_00407000(const uint32_t *value_local /* + unaff ESI/EDI */);
extern "C" uint32_t FUN_0040a670(uint32_t a, uint32_t b, uint32_t c, uint32_t d);
extern "C" void FUN_0045f050(uint32_t a);
extern "C" void FUN_00465bc0(void);

struct VecElem0x10 {
  uint32_t w0, w1, w2, w3;
};

struct VectorElem0x10 {
  void *unused0;     // +0  (allocator / padding in MSVC layout used here)
  uint8_t *begin;    // +4
  uint8_t *end;      // +8
  uint8_t *cap_end;  // +0xC
};

// ECX=count, EDX=vec*, stack where + value*
void __fastcall StdVector_InsertN_Elem0x10_Inferred(
    uint32_t count /*ECX*/,
    VectorElem0x10 *vec /*EDX*/,
    uint8_t *where /*stack*/,
    const VecElem0x10 *value /*stack*/)
{
  VecElem0x10 value_local;
  uint32_t capacity;
  uint32_t size;
  uint8_t *begin;
  void *newbuf;
  uint32_t new_bytes;
  uint32_t old_size;
  int gap_bytes;

  value_local = *value;
  begin = vec->begin;
  if (begin == 0) {
    capacity = 0;
  } else {
    capacity = (uint32_t)(vec->cap_end - begin) >> 4;
  }

  if (count == 0) {
    return;
  }

  if (begin == 0) {
    size = 0;
  } else {
    size = (uint32_t)(vec->end - begin) >> 4;
  }

  // max_size for 0x10 elements ≈ 0x0FFFFFFF
  if (0x0FFFFFFFu - size < count) {
    FUN_00418130();
    // throw path; begin may be restored by EH
  }

  // re-read size after potential throw path side effects (matches decompile)
  if (begin == 0) {
    size = 0;
  } else {
    size = (uint32_t)(vec->end - begin) >> 4;
  }

  if (capacity < size + count) {
    // grow: 1.5× then exact floor
    uint32_t new_cap = capacity;
    if (0x0FFFFFFFu - (new_cap >> 1) < new_cap) {
      new_cap = 0;
    } else {
      new_cap = new_cap + (new_cap >> 1);
    }
    if (begin == 0) {
      size = 0;
    } else {
      size = (uint32_t)(vec->end - begin) >> 4;
    }
    if (new_cap < size + count) {
      if (begin == 0) {
        size = 0;
      } else {
        size = (uint32_t)(vec->end - begin) >> 4;
      }
      new_cap = size + count;
    }
    new_bytes = new_cap << 4;
    newbuf = operator_new(new_bytes);
    // prefix [begin, where)
    FUN_00409b60((uint32_t)vec->begin, (uint32_t)where, /*dst ctx*/ (uint32_t)newbuf);
    // construct-N of value_local at hole (customcc ESI/EDI inside helper)
    FUN_00407000((const uint32_t *)&value_local);
    // suffix [where, end)
    FUN_00409b60((uint32_t)where, (uint32_t)vec->end, /*dst*/ 0);

    if (vec->begin == 0) {
      old_size = 0;
    } else {
      old_size = (uint32_t)(vec->end - vec->begin) >> 4;
    }
    if (vec->begin != 0) {
      operator_delete(vec->begin);
    }
    vec->cap_end = (uint8_t *)newbuf + new_bytes;
    vec->end = (uint8_t *)newbuf + (count + old_size) * 0x10;
    vec->begin = (uint8_t *)newbuf;
    return;
  }

  // capacity sufficient — in-place insert
  {
    uint8_t *end = vec->end;
    if ((uint32_t)(end - where) >> 4 < count) {
      gap_bytes = (int)(count * 0x10);
      FUN_0040a670((uint32_t)where, (uint32_t)(where + gap_bytes), (uint32_t)vec, 0);
      FUN_00407000((const uint32_t *)&value_local);
      vec->end = vec->end + gap_bytes;
    } else {
      gap_bytes = (int)(count * 0x10);
      end = (uint8_t *)FUN_0040a670(
          (uint32_t)(end - count * 0x10), (uint32_t)end, (uint32_t)vec, 0);
      vec->end = end;
      FUN_0045f050(0);
    }
    FUN_00465bc0();
  }
}

// Scaffold Ghidra name
void __fastcall FUN_00408640(
    uint32_t count, int vec, int where, uint32_t *value)
{
  StdVector_InsertN_Elem0x10_Inferred(
      count,
      (VectorElem0x10 *)vec,
      (uint8_t *)where,
      (const VecElem0x10 *)value);
}
