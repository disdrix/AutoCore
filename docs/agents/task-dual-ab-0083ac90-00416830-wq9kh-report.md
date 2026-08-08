# Dual A/B report — WQ9K-H OWN-ONLY (`0x0083ac90`, `0x00416830`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-H**  
**Scope:** VAs `0x0083ac90`, `0x00416830` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + `disassemble_function`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-H**.  
**Work item:** WQ-009 depth-8 residual dual seal (shopveh reindex + Class_00a733ec factory).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0083ac90` ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred | **accept-with-gaps** — ABI/window/id-base/sole-swap-caller/clear paths sealed; product English + helper duals residual |
| `aa_00416830` Class_00a733ec_Factory_WithFreeCallback_Inferred | **accept-with-gaps** — size/layout/ABI/free-cb/vtbl sealed; call-graph empty + product English residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): thiscall-on-reindex, full-list-rebuild, always-swap, free-on-clear, thiscall-factory, UNI_BUTTONS-as-class, merge-factory-with-dtor all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

**These two VAs are not twins** — only depth-8 residual co-owners (shop reindex + factory neighborhood).

---

## VA `0x0083ac90` — sealed facts

1. **Body:** `0x0083ac90`–`0x0083aeb4` inclusive (**549 B** / `0x225`); pad `CC` after **`RET 4`**.
2. **ABI:** **EAX** = select index; stack **host***; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** Shopveh list **five-slot window reindex** around select:
   - Gate: `select >= 0 && select <= host+0x4fc`.
   - Write `host+0x500 = select`.
   - For `list_i ∈ [select-2, select+2]`: map `slot = list_i - select + 2`; if slot live, ensure control id encodes `list_i` via base **`0x9ca4`**.
   - Match → refresh (`FUN_0083a860` / `FUN_0083a880` / `FUN_0083abf0`).
   - Mismatch → scan other slots for donor; if found load **ESI/EDI** and **`CALL 0x00833160`** (dualed swap; **sole caller** @ `0x0083ad72`); else `FUN_0083abf0`.
   - Always finish with `SetId(list_i + 0x9ca4)`.
   - Leading/trailing unused slots: optional `FUN_00833d50` if `obj+0x508`, then `SetId(-1)`.
4. **Classification:** worker.
5. **Xrefs:** 4 UNCONDITIONAL_CALL (`0083af5f`, `0083b311`, `0088d8f3`, `0088d962`).
6. **Callees:** `FUN_00833160`, `FUN_0083a860`, `FUN_0083a880`, `FUN_0083abf0`, `FUN_00833d50`, vtbl `+0x74`/`+0x78`.
7. **Name:** `ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred` (Ghidra `FUN_0083ac90`). Shopveh English from caller graph + prior dual of swap — `_Inferred`.
8. **Decompile ≡ assembly CF** for window/id/swap; decompiler register reuse cleaned via disasm listing.

### Gaps

- Product demangle for host / slot class.  
- Helper duals `0083a860` / `0083a880` / `0083abf0` / `00833d50` not OWN.  
- Dead `CMP EBX,5` post-swap branch.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0083ac90_FUN_0083ac90.md` |
| Annotated | `docs/reconstruction/raw/aa_0083ac90_FUN_0083ac90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0083ac90.cpp` |
| Function | `docs/reconstruction/functions/aa_0083ac90_FUN_0083ac90.md` |
| Function named | `docs/reconstruction/functions/aa_0083ac90_ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred.md` |

---

## VA `0x00416830` — sealed facts

1. **Body:** `0x00416830`–`0x00416892` inclusive (**99 B** / `0x63`); pad `CC` after **`RET 4`**.
2. **ABI:** stack **context**; returns **object*** / null in EAX; **`RET 4`**; **not** thiscall.
3. **Semantics:** Heap factory for **Class_00a733ec** size **0x14**:
   - SEH frame + `operator_new(0x14)`.
   - Null-new → return null.
   - Else: `+0` = `PTR_FUN_00a733ec`; `+4` = context; `+8`/`+0xc` = 0; `+0x10` = `LAB_00573240`.
4. **Free callback** (`0x00573240` bytes): if context non-null, `context->vtbl[0](flags=1)` (scalar-delete owned context).
5. **Vtbl proof:** `*(u32*)0x00a733ec == 0x00416f00` = dualed `Class_00a733ec_ScalarDeletingDtor_Inferred` (WQ9J-E).
6. **Twin factory:** `FUN_004168c0` same layout, free-callback **null** (WQ9K-I OWN — not dualled here).
7. **Xrefs:** **0** CALL; DATA only for vtbl/callback constants.
8. **Name:** `Class_00a733ec_Factory_WithFreeCallback_Inferred` (Ghidra `FUN_00416830`). Reject `"UNI_BUTTONS"` as class English (adjacent rdata only).
9. **Decompile ≡ raw CF**; size/fields/RET sealed by **bytes**.

### Gaps

- Product / RTTI demangle.  
- Empty CALL graph (reachability open).  
- Twin factory dual residual (WQ9K-I).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416830_FUN_00416830.md` |
| Annotated | `docs/reconstruction/raw/aa_00416830_FUN_00416830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a733ec_Factory_WithFreeCallback_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416830.cpp` |
| Function | `docs/reconstruction/functions/aa_00416830_FUN_00416830.md` |
| Function named | `docs/reconstruction/functions/aa_00416830_Class_00a733ec_Factory_WithFreeCallback_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
ShopVehList_ReindexFiveSlotWindowAroundSelect_Inferred (0x0083ac90)  [OWN WQ9K-H]
  ├─ sole CALL → ShopVehObject_SwapSelectState_ESI_EDI_Inferred (0x00833160)  [dualed WQ9J-D]
  ├─ refresh helpers FUN_0083a860 / FUN_0083a880 / FUN_0083abf0 / FUN_00833d50  [residual]
  └─ drive parents FUN_0083aff0 / FUN_0088d8b0 / FUN_0088d910                   [residual]

Class_00a733ec_Factory_WithFreeCallback_Inferred (0x00416830)        [OWN WQ9K-H]
  ├─ vtbl PTR_FUN_00a733ec[0] = Class_00a733ec_ScalarDeletingDtor (0x00416f00) [dualed WQ9J-E]
  ├─ free thunk LAB_00573240 (scalar-delete context)                            [not a fn symbol]
  └─ twin factory FUN_004168c0 (null free cb)                                   [OWN WQ9K-I]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0083ac90-00416830-wq9kh-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0083ac90` | Port as **stdcall** list-window reindex: EAX select + stack host, **RET 4**. Five slots at `host+0x50c`, select at `+0x500`, count at `+0x4fc`, id base **`0x9ca4`**. On conflict call dualed ESI/EDI swap. Clear unused slots to id `-1`. Not full list rebuild; not thiscall. |
| `00416830` | Port as **stdcall factory**: `new(0x14)`, install vtbl `00a733ec`, context at +4, free cb `LAB_00573240` at +0x10, **RET 4**. Pair with dualed scalar dtor. Distinct from null-cb twin `004168c0`. |
| Pair with | Swap `00833160` + dtor `00416f00` already dualed; twin factory when WQ9K-I lands. **Do not** merge the two OWN VAs into one type. |
| Naming caution | Keep `_Inferred` until RTTI/product English sealed. Reject UNI_BUTTONS as class name. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (shopveh UI reindex + util/factory — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x0083ac90`, `0x00416830`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank paste).  
- Odd behavior preserved: empty factory CALL graph; dead post-swap `CMP EBX,5`; adjacent UNI_BUTTONS not class English.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
