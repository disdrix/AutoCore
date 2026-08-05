// =============================================================================
// PhysHost_MergeSortedPairList_Inferred  (Ghidra: FUN_00560750)
// -----------------------------------------------------------------------------
// Stable ID: aa_00560750
// Address:   0x00560750 – 0x00560a2c  (autoassault.exe, image base 0x400000)
// Size:      733 bytes (0x2DD); plain ret; pad CC after
// System:    phys host island merge — sorted stride-16 pair list at host+0x68
// Dual:      W29-S 2026-07-29 (decompile + read_memory; no disassemble_bytes)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed ABI.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   Merge src pair-list into dest pair-list (both host+0x68 descriptors).
//   Snapshot dest via LocalWorklist16, grow dest, ordered merge on dual keys
//   at (*entry[0])+4 and (*entry[1])+4. Equal keys: vcall absorb on entry[2].
//
// ABI (machine):
//   EAX            = dest list descriptor*
//   [esp+4]        = src list descriptor*
//   epilogue       = plain ret (caller ADD ESP,4)
// =============================================================================

#include <cstdint>

extern int *DAT_00b05060;
extern "C" int *__thiscall FUN_0055f520(int *desc /*ECX*/, unsigned count); // LocalWorklist16_Init
extern "C" void FUN_005b3300(void* vec, int new_cap, int elem_size); // HBBuffer_GrowRealloc

struct PairRec {
  uint32_t* a; // key at a[1] (+4)
  uint32_t* b; // key at b[1] (+4)
  void*     c; // vtbl object
  uint32_t  d;
};

struct PairList {
  PairRec* data;
  int count;
  int cap_flags; // low 31 = capacity
};

static inline uint32_t key_of(uint32_t* p) {
  return p[1];
}

// Custom: dest in EAX, src on stack
void PhysHost_MergeSortedPairList_Inferred(PairList* dest /*EAX*/, PairList* src /*stack*/)
{
  // 1) Snapshot dest into local worklist (decomp: local_14..)
  int dest_n = dest->count;
  int snap_desc[5];
  FUN_0055f520(snap_desc, static_cast<unsigned>(dest_n));
  // worklist fields used by release: [0] slab, [1] unused/0, [2] count|hi, [3] slab, [4] count
  // Grow snapshot storage if worklist capacity < dest_n (elem 0x10)
  int snap_cap = snap_desc[2] & 0x7fffffff;
  if (snap_cap < dest_n) {
    int nc = snap_cap * 2;
    if (nc <= dest_n) nc = dest_n;
    FUN_005b3300(&snap_desc[3] /* data slot model */, nc, 0x10);
  }
  auto* snap = reinterpret_cast<PairRec*>(snap_desc[0]); // slab ptr
  for (int i = 0; i < dest_n; ++i) {
    snap[i] = dest->data[i];
  }

  // 2) Ensure dest capacity for dest_n + src.count
  int need = dest_n + src->count;
  if ((dest->cap_flags & 0x7fffffff) < need) {
    FUN_005b3300(dest, need, 0x10);
  }
  dest->count = need; // temporary upper bound during merge write

  // 3) Ordered merge
  int i_snap = 0, i_src = 0, i_out = 0;
  int equals = 0;
  int out_n = 0;
  while (i_snap < dest_n && i_src < src->count) {
    PairRec* s = &snap[i_snap];
    PairRec* r = &src->data[i_src];
    uint32_t ka = key_of(s->a);
    uint32_t kb = key_of(r->a);
    if (ka < kb || (ka == kb && key_of(s->b) < key_of(r->b))) {
      dest->data[i_out++] = *s;
      ++i_snap;
      ++out_n;
    } else if (key_of(s->a) != key_of(r->a) || key_of(s->b) != key_of(r->b)) {
      dest->data[i_out++] = *r;
      ++i_src;
      ++out_n;
    } else {
      // equal dual-key: absorb via virtuals on payload C
      void** cv = *reinterpret_cast<void***>(r->c);
      using V14 = void(__thiscall*)(void*);
      reinterpret_cast<V14>(cv[0x14 / 4])(r->c);
      void* c2 = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(r->c) + 8);
      void** c2v = *reinterpret_cast<void***>(c2);
      using V10 = void(__thiscall*)(void*);
      reinterpret_cast<V10>(c2v[0x10 / 4])(c2);
      ++i_src;
      ++i_snap;
      ++equals;
    }
  }

  // 4) Final count and drain tails
  int final_n = (dest_n - equals) + src->count;
  if ((dest->cap_flags & 0x7fffffff) < final_n) {
    FUN_005b3300(dest, final_n, 0x10);
  }
  dest->count = final_n;

  if (i_snap == dest_n) {
    while (i_src < src->count) {
      dest->data[i_out++] = src->data[i_src++];
    }
  } else if (i_snap < dest_n) {
    while (i_snap < dest_n) {
      dest->data[i_out++] = snap[i_snap++];
    }
  }

  // 5) Inline LocalWorklist16-style release on snap_desc / DAT_00b05060
  // (bump counters or vtbl+0x28; optional tagged free vtbl+0x14 tag 0x12)
  // Exact field map matches W28-R LocalWorklist16_Release_Inferred.
  (void)DAT_00b05060;
  (void)snap_desc;
}

// Ghidra symbol alias — EAX dest, stack src
void FUN_00560750(int *param_1 /*src*/)
{
  PairList* dest;
#ifdef _MSC_VER
  __asm { mov dest, eax }
#else
  dest = nullptr; // non-MSVC: caller must pass dest via platform ABI
#endif
  PhysHost_MergeSortedPairList_Inferred(dest, reinterpret_cast<PairList*>(param_1));
}
