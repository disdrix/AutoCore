// =============================================================================
// LthkWorld_GetPenetrations_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00560c90
// Address:   0x00560c90  (autoassault.exe, image base 0x400000)
// Range:     0x00560c90–0x00560e33 inclusive (420 B / 0x1A4); pad CC after
// System:    interaction-activation (world penetrations / narrowphase dispatch)
// Generated: 2026-08-05 R12-024 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   World **getPenetrations** entry (profiler plate `LthkWorld::getPenetrations`):
//   1) resolve dispatch table (arg or self+0xCC)
//   2) shape extents vcall on query object
//   3) broadphase-collect candidates via self+0xC4
//   4) narrowphase loop: pair-filter via self+0xD0, then cdecl type-pair matrix
//      dispatch at dispatch_table.vtbl[+0x118c + (typeA*0x20+typeB)*4]
//   5) free heap triad buffer when capacity high-bit clear
//
// ABI (sealed)
//   thiscall: ECX = self
//   stack:    query_obj*, user_ctx, dispatch_table*   (RET 0xC)
//   dispatch_table null → self+0xCC
//
// CALL SITES
//   FUN_004ea350 @ 0x004ea7e3  (GetObjectsInArea collect)
//   FUN_005dae50 @ 0x005daf65  (CVOGHBRecreateObject::OnHeartBeat)
//
// DISTINCT FROM
//   FUN_005eb210 — query-object base ctor
//   FUN_005ebec0 — sphere-query collect ctor
//   FUN_00581190 — query sub-init leaf
//
// DECOMPILER CORRECTIONS
//   - unaff_EBX in filter path is wrong; use saved self ([ESP+0x1c] / ESI)
//   - free size comes from capacity field with high-bit test, not puStack as count
//   - pair matrix CALL is cdecl (ADD ESP,0x10)
// =============================================================================

#include <cstdint>

// Image globals (not dualled in R12-024)
extern uint32_t *DAT_00bc5644;   // RDTSC profiler write cursor
extern uint32_t *DAT_00bc5648;   // RDTSC profiler end
extern uint32_t *DAT_00b05060;   // global allocator object*
extern const char DAT_009d2840[]; // "LthkWorld::getPenetrations"
extern const char DAT_009d2830[]; // "Stnarrowphase"
extern const char DAT_009d282c[]; // "lt" (close tag)

// Ghidra-faithful thiscall body (ECX = self).
void __thiscall LthkWorld_GetPenetrations_Inferred(
    int self /* ECX */,
    int *query_obj /* stack */,
    uint32_t user_ctx /* stack */,
    int *dispatch_table /* stack */)
{
  uint8_t ext12[12];
  uint8_t stack_buf[1052];
  uint8_t out_scratch[8];
  char filter_out = 0;

  // triad: begin / count / capacity
  void *triad_begin = stack_buf;
  int triad_count = 0;
  int triad_capacity = static_cast<int>(0x80000080u);

  // optional profiler open
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = reinterpret_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(DAT_009d2840));
    // RDTSC → store low dword; cursor += 3 dwords
    DAT_00bc5644[1] = 0; // rdtsc low (runtime)
    DAT_00bc5644 += 3;
  }

  if (dispatch_table == nullptr) {
    dispatch_table = *reinterpret_cast<int **>(self + 0xCC);
  }

  // shape extents: (**query_obj)->vtbl[+0x18](query_obj[2]+0x20, dispatch[2], &ext12)
  {
    int *inner = reinterpret_cast<int *>(*query_obj);
    auto **vtbl = reinterpret_cast<void **>(*inner);
    auto fn = reinterpret_cast<void(__stdcall *)(int, int, void *)>(vtbl[0x18 / 4]);
    fn(query_obj[2] + 0x20, dispatch_table[2], ext12);
  }

  // broadphase: (**(self+0xC4))->vtbl[+0x24](&out, &triad)
  {
    int *collector = *reinterpret_cast<int **>(self + 0xC4);
    auto **vtbl = reinterpret_cast<void **>(*collector);
    struct Triad {
      void *begin;
      int count;
      int capacity;
    } triad{triad_begin, triad_count, triad_capacity};
    auto fn = reinterpret_cast<void(__thiscall *)(int *, void *, Triad *)>(
        vtbl[0x24 / 4]);
    fn(collector, out_scratch, &triad);
    triad_begin = triad.begin;
    triad_count = triad.count;
    triad_capacity = triad.capacity;
  }

  int typeA = 0;
  {
    int *inner = reinterpret_cast<int *>(*query_obj);
    auto **vtbl = reinterpret_cast<void **>(*inner);
    auto fn = reinterpret_cast<int(__thiscall *)(int *)>(vtbl[0x14 / 4]);
    typeA = fn(inner);
  }

  // profiler Stnarrowphase
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = reinterpret_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(DAT_009d2830));
    DAT_00bc5644[1] = 0;
    DAT_00bc5644 += 3;
  }

  if (triad_count - 1 >= 0) {
    int *slot = reinterpret_cast<int *>(
        reinterpret_cast<uint8_t *>(triad_begin) + 4);
    int remaining = triad_count;
    do {
      int *cand = (*slot == 0)
                      ? nullptr
                      : reinterpret_cast<int *>(*slot - 0x10);

      if (query_obj != cand && cand != nullptr) {
        // CORRECTED filter host: *(self+0xD0)  (not unaff_EBX)
        int *filter_host = *reinterpret_cast<int **>(self + 0xD0);
        int *filter_sub = filter_host + 2; // +0x8
        auto **fvtbl = reinterpret_cast<void **>(*filter_sub);
        auto filter = reinterpret_cast<char *(__thiscall *)(
            int *, char *, int *, int *)>(fvtbl[0]);
        char *ok = filter(filter_sub, &filter_out, query_obj, cand);

        if (ok != nullptr && *ok != '\0' &&
            reinterpret_cast<int *>(*cand) != nullptr) {
          int *cand_inner = reinterpret_cast<int *>(*cand);
          auto **cvtbl = reinterpret_cast<void **>(*cand_inner);
          auto type_fn =
              reinterpret_cast<int(__thiscall *)(int *)>(cvtbl[0x14 / 4]);
          int typeB = type_fn(cand_inner);

          // cdecl matrix dispatch
          auto **dvtbl = reinterpret_cast<void **>(*dispatch_table);
          int index = typeA * 0x20 + typeB;
          auto handler = reinterpret_cast<void(__cdecl *)(
              int *, int *, int *, uint32_t)>(
              dvtbl[0x118c / 4 + index]);
          handler(query_obj, cand, dispatch_table, user_ctx);
        }
      }

      slot += 2; // stride 8
      remaining -= 1;
    } while (remaining != 0);
  }

  // profiler close "lt"
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = reinterpret_cast<uint32_t>(
        reinterpret_cast<uintptr_t>(DAT_009d282c));
    DAT_00bc5644[1] = 0;
    DAT_00bc5644 += 3;
  }

  // free when capacity high-bit clear
  if (triad_capacity >= 0) {
    auto **avtbl = reinterpret_cast<void **>(*DAT_00b05060);
    auto free_fn = reinterpret_cast<void(__thiscall *)(
        uint32_t *, void *, int, int)>(avtbl[0x14 / 4]);
    free_fn(DAT_00b05060, triad_begin,
            (triad_capacity & 0x7fffffff) * 8, 0x12);
  }
  // RET 0xC
}
