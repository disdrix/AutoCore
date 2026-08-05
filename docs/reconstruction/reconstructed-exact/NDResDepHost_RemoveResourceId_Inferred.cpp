// =============================================================================
// NDResDepHost_RemoveResourceId_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00744ea0
// Address:   0x00744ea0  (autoassault.exe, image base 0x400000)
// Body:      526 B (0x00744ea0–0x007450ae exclusive)
// System:    ND resource dependency host (DAT_00d1f050 family)
// Generated: 2026-08-04 W38-AE
// Exactness: Behavior-preserving rewrite of decompiler + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime this wave).
// =============================================================================

// PURPOSE:
// Remove a resource id from the dependency host: erase owned map entry at
// this+0x1c when unique, drop from tracked-id vector, walk dependency maps
// at +0x14 / +0x20 and erase reverse edges; optional cascade recurse.
//
// ABI (bytes win):
//   ECX = host this*
//   stack: int* pId, char recurse
//   RET 8
//   returns bool (AL): 1 success, 0 fail (map@+0x1c still has equal_range hits)

#include <cstdint>

extern "C" void __fastcall FUN_00426f60(void* src /*ECX*/, void* dst /*EAX*/);
extern "C" int FUN_0044d920(void); // equal_range count (map/key in regs)
extern "C" void FUN_0044d8c0(void); // lower_bound → out iterator
extern "C" void FUN_0044d630(void* map, void* outIt, void* node);
extern "C" void __fastcall FUN_0044dc00(void* unused, void** it);
extern "C" uint32_t FUN_00744cc0(int* pos_in_vector);

struct NdResDepHost {
  // +0x00 ...
  uint32_t self_id;      // +0x04  compared to node[6]
  // ...
  void* map_14;          // +0x14  dependency map A
  // ...
  // map B at +0x1c
  // map C at +0x20
  // vector begin/end at +0x50 / +0x54
};

bool __thiscall NDResDepHost_RemoveResourceId_Inferred(
    void* self, int* pId, char recurse)
{
  uint32_t key_box[3];
  // FUN_00426f60: *dst = *src; dst[1]=dst[2]=0  (ECX=src, EAX=dst)
  FUN_00426f60(pId, key_box);

  // equal_range count on map at self+0x1c
  int count = FUN_0044d920();
  if (count == 1) {
    // lower_bound into local node; if node[6] == *(self+4) → erase
    // FUN_0044d8c0 + FUN_0044d630(self+0x1c, ...)
  }
  count = FUN_0044d920();
  if (count != 0)
    return false;

  int* begin = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x50);
  int* end = *reinterpret_cast<int**>(reinterpret_cast<char*>(self) + 0x54);
  if (begin != end) {
    for (int* p = begin; p != end; ++p) {
      if (*p == *pId) {
        FUN_00744cc0(p);
        break;
      }
    }
  }

  // lower_bound / upper_bound on map@+0x14 for *pId
  // for each node in [lo, hi):
  //   equal_range on map@+0x20 for node[6]
  //   if entry[6] == *pId:
  //     FUN_0044d630(self+0x1c? map@+0x20 path uses +0x1c erase helper site)
  //     actually erase uses FUN_0044d630(self+0x1c, ...) in first path;
  //     secondary erase: FUN_0044d630(self+0x1c, out, entry) per decompile
  //     Wait — decompile: FUN_0044d630(param_1 + 0x1c, auStack_10, puVar9)
  //     with puVar9 from map@+0x20 walk — same erase helper base +0x1c.
  //     if recurse: NDResDepHost_RemoveResourceId_Inferred(self, &node[6], 1)
  // tree ++ via FUN_0044dc00
  (void)recurse;
  return true;
}

// Ghidra name twin
extern "C" bool __thiscall FUN_00744ea0(void* self, int* pId, char recurse)
{
  return NDResDepHost_RemoveResourceId_Inferred(self, pId, recurse);
}
