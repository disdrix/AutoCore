// =============================================================================
// StdVector_CopyCtor_Elem0x18_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0041c140
// Address:   0x0041c140–0x0041c1c9 inclusive (138 B / 0x8A; autoassault.exe base 0x400000)
// System:    skills-abilities (partition; unit role = generic MSVC vector copy-ctor)
// Generated: 2026-08-05 R13-022 OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live decompile + bytes + call sites.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_0041c140.cpp scaffold
// Dual: reviews/A|B_aa_0041c140_StdVector_CopyCtor_Elem0x18_Inferred.md
// Parent dual: 0x0041ba30 StdTree_InsertAndRebalance_CharKey_Isnil21_Inferred
// Callers: FUN_0041d860 (buynode; ECX=node+0x10), FUN_0059a940 (2), FUN_007eaf20 (4)
// Callees: FUN_0041c250 (buy/zero+alloc elem0x18), FUN_00422580 (POD 6-dword Ucopy)
// =============================================================================
//
// PURPOSE:
//   MSVC-style std::vector copy constructor for elements of size 0x18.
//   Count source range, buy fresh buffer (zero triple first), POD-uninitialized_copy,
//   publish dest.end. Empty source → zeroed empty vector.
//
// ABI (sealed):
//   __thiscall; RET 4 (C2 04 00)
//   ECX            = VecShell* dest
//   stack [ESP+4]  = const VecShell* src
//   EAX            = dest
//
// VecShell (fields used):
//   +0x4 begin, +0x8 end, +0xC capacity_end
//   (this+0 unused by this unit / buy helper)
//
// Bytes (epilogue): 5B 8B E5 5D C2 04 00
// Count divide: signed /0x18 via imm 0x2AAAAAAB
// =============================================================================

#include <cstdint>

struct Elem0x18 {
  // 24-byte POD element — six dwords; product English open.
  std::uint32_t w[6];
};

struct VecShell_Elem0x18 {
  std::uint32_t unused0;   // +0x0 — not touched by copy-ctor / buy
  Elem0x18* begin;         // +0x4
  Elem0x18* end;           // +0x8
  Elem0x18* capacity_end;  // +0xC
};

// Residual: zeros +4/+8/+0xC; if n==0 return 0; else operator_new(n*0x18),
// begin=end=p, capacity_end=p+n*0x18, return 1. Max-n gate via FUN_004540b0.
extern "C" char __thiscall Vec_BuyZeroAlloc_Elem0x18_Inferred(
    VecShell_Elem0x18* self /*ECX*/,
    unsigned n /*stack*/);

// Residual: for (p=first; p!=last; p+=1 / +0x18) if (dest) copy 6 dwords; dest++.
// Caller treats EAX as new dest end (decomp may show void).
extern "C" Elem0x18* PodUcopy_Elem0x18_Inferred(
    Elem0x18* first,
    Elem0x18* last,
    Elem0x18* dest /*, VecShell* dest_shell, const VecShell* src_shell unused */);

// SEH frame (LAB_009bce90) omitted in clean plate; control flow preserved.

extern "C" VecShell_Elem0x18* __thiscall StdVector_CopyCtor_Elem0x18_Inferred(
    VecShell_Elem0x18* dest /*ECX*/,
    const VecShell_Elem0x18* src /*stack*/)
{
  int count = 0;
  if (src->begin != nullptr) {
    // (end - begin) / 0x18
    count = static_cast<int>(
        (reinterpret_cast<const char*>(src->end) -
         reinterpret_cast<const char*>(src->begin)) /
        0x18);
  }

  char ok = Vec_BuyZeroAlloc_Elem0x18_Inferred(dest, static_cast<unsigned>(count));
  if (ok != 0) {
    // EH state = 0 around construct range
    dest->end = PodUcopy_Elem0x18_Inferred(src->begin, src->end, dest->begin);
  }
  // EH unlink
  return dest;
}
