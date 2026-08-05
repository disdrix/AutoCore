# Dual A/B report — W21-S OWN `0x00871150` + `0x0089a260`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00871150`, `0x0089a260`. Dual A/B + artifacts.  
**Agent:** W21-S  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ `analyze_function_complete` / callers / callees). No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00871150` UiHost_RefreshTrackedNodeWidgets_Inferred | **accept-with-gaps** — **1192-byte EAX-this multi-widget refresh sealed** (`ret 4`; bank `+0x5e8..+0x600`; node id pair `+8/+0xc`; selection rebind) |
| `aa_0089a260` UI_RefinePanel_InsertCommodityListRow_Inferred | **accept-with-gaps** — **3600-byte refine row binder sealed** (`ret 0x10`; filter/tier/label/list A·B; flag unused) |

---

## Sealed facts — `0x00871150`

1. **ABI:** host in **EAX**, stack `TrackedNode*`, **`ret 4`**. Body `0x00871150`–`0x008715f8` (**1192 B**).
2. **Gates:** host `vtbl+0x3d8` visible; null node.
3. **Prep:** `FUN_007fd970` after `CL = *(u8*)(node+0x1c) - 0x0f` (bytes; decomp under-reports).
4. **Widget bank (host dword idx → byte):** `0x17a→+0x5e8`, `0x17b→+0x5ec`, `0x17c→+0x5f0`, `0x17d→+0x5f4`, `0x17e→+0x5f8`, `0x17f→+0x5fc`, `0x180→+0x600`. Each optional; vtbl `0x45c/460/464/34c`.
5. **Node:** id pair `+8/+0xc`; ushort `+0x14`; short/byte `+0x1c`; flag `+0`.
6. **Selection:** if `DAT_00d1b6d8` selected pair matches, re-call `vtbl+0x464` on bound widgets.
7. **Callers:** `FUN_00871600`, `FUN_008718a0`, `FUN_008718d0`, `FUN_008719d0`.
8. **Name:** `UiHost_RefreshTrackedNodeWidgets_Inferred` — role-sealed **INFERRED**.

---

## Sealed facts — `0x0089a260`

1. **ABI:** stdcall **4** stack args `(host, entry, qty, flag)`, **`ret 0x10`**. Body `0x0089a260`–`0x0089b06f` (**3600 B**). **flag unused**.
2. **Gates:** null entry; null `entry+0x3c` def.
3. **Filter `host+0x52c`:** mode `1` qty≥1; modes `2/3/4/6` require `def+0x4c8` ∈ {0,1,2,3}; mode `7` map-filter via `FUN_0052d450` + `Map_LowerBoundFindByIntKey` on `entry+0x34`.
4. **Label:** locale name from `def+0x92`; quality prefix EN (`Salvaged|Patched|Functional|Perfect`) / DE (Verwertbar*/Aufbereitet*/Hochwertig*/Perfekt*) / FR-style full name; formats `"[0|%i] %s"` / `"[0|%i] %s, %s"`.
5. **Insert:** `FUN_00599dd0` mod slots → list `host+0x56c` if ≥1 else require `def+0x4d0 != -1` and list `host+0x568`; vtbl `+0x45c` then `+0x464` with `entry+0x34`.
6. **Caller:** only `FUN_0089bc30` (×2 sites).
7. **Name:** `UI_RefinePanel_InsertCommodityListRow_Inferred` — **INFERRED**.

---

## Gaps

1. Product English for host class, widget slots, filter modes, tier enum.
2. Exact vtbl `0x45c/460/464/34c` argument packs (decomp residual both units).
3. Nested dual residual: `FUN_007fd970`, `FUN_008705c0`, `FUN_0051fa10/0051f910`, mode-7 map path.
4. Why callers pass unused `flag` into `0089a260`.
5. Runtime / bit-exact / differential — open.

---

## Files

### `aa_00871150` UiHost_RefreshTrackedNodeWidgets_Inferred

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00871150_UiHost_RefreshTrackedNodeWidgets_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00871150_UiHost_RefreshTrackedNodeWidgets_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00871150_FUN_00871150.md` |
| Named record | `docs/reconstruction/functions/aa_00871150_UiHost_RefreshTrackedNodeWidgets_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiHost_RefreshTrackedNodeWidgets_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00871150.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_00871150_FUN_00871150.md` |
| Annotated | `docs/reconstruction/raw/aa_00871150_FUN_00871150.annotated.md` |
| Scratch | `tmp/a_00871150.md` |

### `aa_0089a260` UI_RefinePanel_InsertCommodityListRow_Inferred

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0089a260_UI_RefinePanel_InsertCommodityListRow_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0089a260_UI_RefinePanel_InsertCommodityListRow_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0089a260_FUN_0089a260.md` |
| Named record | `docs/reconstruction/functions/aa_0089a260_UI_RefinePanel_InsertCommodityListRow_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_RefinePanel_InsertCommodityListRow_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_0089a260.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_0089a260_FUN_0089a260.md` |
| Annotated | `docs/reconstruction/raw/aa_0089a260_FUN_0089a260.annotated.md` |
| Scratch | `tmp/a_0089a260.md` |

| Report | `docs/agents/task-dual-ab-00871150-0089a260-w21s-report.md` |

---

## AutoCore impact

- **RefreshTrackedNodeWidgets:** when clearing tracked garage/UI pairs (`008718a0`), refresh must rebind the multi-widget bank from node id pair — not a single label. Host arrives in **EAX**, not ECX. Do not free/clear the node inside the refresh helper.
- **InsertCommodityListRow:** refine rebuild ports must call a per-row filter+label+insert helper (not inline into rebuild). Honor filter mode / tier / mod-slot list split (`+0x568` vs `+0x56c`) and `def+0x4d0 != -1` on the no-mods path. Fourth stack arg may be ignored safely.
