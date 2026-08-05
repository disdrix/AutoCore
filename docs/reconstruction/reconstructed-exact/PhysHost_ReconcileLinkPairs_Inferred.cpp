// =============================================================================
// PhysHost_ReconcileLinkPairs_Inferred  (Ghidra: FUN_00634450)
// -----------------------------------------------------------------------------
// Stable ID: aa_00634450
// Address:   0x00634450 – 0x0063453f  (autoassault.exe, image base 0x400000)
// Size:      240 bytes (0xF0); epilogue ret 4
// System:    phys / host link-pair reconcile
// Dual:      W29-R 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Not bit-exact certified.
// =============================================================================
//
// PURPOSE:
//   When host embeds a manager at +8, rebuild link-pair membership for the host
//   after pose/AABB change. Dual local worklists (stride *8) collect current vs
//   desired pairs via manager[+0xc4] vtbl+0x14; CanonAndSort both sides; Sorted
//   DiffWalk reconciles; compact host+0x3c pointer list; release both worklists.
//
// ABI (machine):
//   thiscall; ECX = host; 1 stack formal (query param); ret 4; void
//
// DECOMPILER RESIDUALS (documented, not invented away silently):
//   - "param_1 == -0xc" is MSVC null-this for member +0x1c
//   - "uVar2 = 1" is the vcall flag literal, not second-list count
//   - FUN_006caaa0 thiscall ECX = *(mgr+0x138) omitted by decompiler surface
// =============================================================================

#include <cstdint>

// Nested (sealed elsewhere where dual exists):
// FUN_0062d960  — LocalWorklist init (stride *8) vs DAT_00b05060
// FUN_0055f4c0  — LocalWorklist_Release_Inferred
// FUN_006cad30  — LinkPair_CanonAndSort_Inferred
// FUN_006caaa0  — LinkPair_SortedDiffWalk_Inferred
// FUN_005fff20  — compact nulls in pointer vector (EAX = vec desc)

extern "C" void __thiscall FUN_0062d960(std::uint32_t *desc /*ECX*/, std::uint32_t count);
extern "C" void __fastcall FUN_0055f4c0(std::uint32_t *desc /*ECX*/);
extern "C" void FUN_006cad30(void *pairs, int count);
extern "C" void __thiscall FUN_006caaa0(
    int handler_table /*ECX*/,
    void *left_pairs, int left_count,
    void *right_pairs, int right_count,
    int predicate_or_ctx);
extern "C" void FUN_005fff20(void); // in_EAX = pointer-vector desc

// Ghidra: FUN_00634450
void __thiscall PhysHost_ReconcileLinkPairs_Inferred(
    int host /*ECX*/,
    std::uint32_t query_param /*stack*/)
{
  int mgr;
  int link_slot;
  int pred;
  // Stack worklist descriptors + query outs (layout matches sub esp,0x2C surface)
  std::uint32_t wl_a[5];
  std::uint32_t wl_b[5];
  void *list_a_ptr = nullptr;
  int list_a_count = 0;
  void *list_b_ptr = nullptr;
  int list_b_count = 0;
  int slot_holder;

  mgr = *reinterpret_cast<int *>(host + 8);
  if (mgr == 0) {
    return;
  }

  // Dual LocalWorklist init from manager capacity field +0x238
  FUN_0062d960(wl_a, *reinterpret_cast<std::uint32_t *>(mgr + 0x238));
  FUN_0062d960(wl_b, *reinterpret_cast<std::uint32_t *>(mgr + 0x238));

  // Null-this safe pointer to host+0x1c (MSVC: host == (T*)-0xC ? 0 : host+0x1C)
  if (host == -0xc) {
    link_slot = 0;
  } else {
    link_slot = host + 0x1c;
  }
  slot_holder = link_slot;

  // Query: *(mgr+0xc4)->vtbl + 0x14
  // Args (stack): &slot_holder, query_param, flag=1, list outs into worklists
  (**(void (***)(int *, std::uint32_t, int, void *, void **))(
      **reinterpret_cast<int **>(mgr + 0xc4) + 0x14))(
      &slot_holder, query_param, 1, /*list_b out*/ &list_b_ptr,
      /*list_a out*/ reinterpret_cast<void **>(&list_a_ptr));
  // Note: decompiler surface packs outs into local_28/iStack_24/local_14; machine
  // fills worklist slabs + counts. list_* here stand for those outs.

  if (list_a_count != 0 || list_b_count != 0 || list_a_ptr != nullptr ||
      list_b_ptr != nullptr) {
    FUN_006cad30(list_a_ptr, list_a_count);
    FUN_006cad30(list_b_ptr, list_b_count);

    if (*reinterpret_cast<int *>(mgr + 0xd0) == 0) {
      pred = 0;
    } else {
      pred = *reinterpret_cast<int *>(mgr + 0xd0) + 8;
    }

    // Machine ECX = *(mgr+0x138) — decompiler omits this
    FUN_006caaa0(*reinterpret_cast<int *>(mgr + 0x138), list_a_ptr, list_a_count,
                 list_b_ptr, list_b_count, pred);

    // Compact pointer list at host+0x3c (FUN_005fff20 uses EAX = desc)
    // lea eax,[host+0x3c]; call FUN_005fff20
    FUN_005fff20();
  }

  FUN_0055f4c0(wl_b);
  FUN_0055f4c0(wl_a);
}
