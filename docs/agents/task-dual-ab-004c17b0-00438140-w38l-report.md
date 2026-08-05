# Dual A/B report — W38-L OWN `aa_004c17b0` + `aa_00438140`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-L  
**Scope:** VAs `0x004c17b0`, `0x00438140` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` → **W38-L**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c17b0` ParticleFluidLiquidChild_HostLink_Ctor_Inferred | **accept-with-gaps** — thiscall/RET4/8 B layout/vtbl `009cb7a4`/list push_back/sole liquid-child caller sealed; product English + list-helper duals residual |
| `aa_00438140` StdTree_InsertAndRebalance_Val8_Isnil15_Inferred | **accept-with-gaps** — EDI map/RET 0x10/max `0x1ffffffd`/Val8 color@+0x14 isnil@+0x15/always-insert+RB/6 callers sealed; buynode+rotate duals + product English residual |

---

## VA `0x004c17b0` — sealed facts

1. **Body:** `0x004c17b0`–`0x004c17fe` inclusive (**79 B** / `0x4F`; pad `CC` then next). Epilogue **`C2 04 00`**.
2. **ABI:** **ECX=`HostLink* this`**, stack **`host*`**, returns **`this`**, **`RET 4`**.
3. **Semantics:** Ctor for **8-byte** host-link subobject (liquid-child embed @ `+0x18`):
   - `*this = PTR_LAB_009cb7a4` (slot0 → `0x004c09c0`).
   - `*(this+4) = host`.
   - If `host != null`: push_back `this` onto host list — sentinel **`*(host+8)`**, size **`*(host+0xC)`** via `FUN_006759b0` (0xC node) + `FUN_004c20b0(1)` (IncSize thiscall ECX=`host+4` so size @ +8).
   - Splice: `head->prev = node`; `node->prev->next = node` (insert before sentinel).
4. **Classification:** worker.
5. **Callers (1):** `FUN_004c1800` (`ParticleFluidLiquidChild_Ctor_Inferred`, W37-G) @ `0x004c1845` — bytes **`LEA ECX,[ESI+0x18]; PUSH ESI`**.
6. **Callees:** `FUN_006759b0`, `FUN_004c20b0`.
7. **Name:** `ParticleFluidLiquidChild_HostLink_Ctor_Inferred` (Ghidra `FUN_004c17b0`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_*Drive_NDRiver_fx_004c17b0`.
8. **Decompile vs bytes:** CF matches; **bytes win** on IncSize ECX (`host+4`) and value-slot overwrite with `this`. Full hex: raw W38-L append.

### Gaps

- Product/PDB English for host-link / vtbl `009cb7a4` / method `004c09c0`.  
- Full dual of list buynode `FUN_006759b0` + IncSize `FUN_004c20b0`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c17b0_ParticleFluidLiquidChild_HostLink_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c17b0_ParticleFluidLiquidChild_HostLink_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c17b0_FUN_004c17b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c17b0_FUN_004c17b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidLiquidChild_HostLink_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c17b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004c17b0_FUN_004c17b0.md` |
| Function named | `docs/reconstruction/functions/aa_004c17b0_ParticleFluidLiquidChild_HostLink_Ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004c17b0.md` |

---

## VA `0x00438140` — sealed facts

1. **Body:** `0x00438140`–`0x004382be` inclusive (**383 B** / `0x17F`; pad `CC` then next @ `0x004382c0` W38-G). Epilogue **`ADD ESP,0x50; RET 0x10`**. SEH `LAB_009bc919`.
2. **ABI:** **EDI=`map*`** (`head@+4`, `size@+8`); stack **`(out*, addLeft, where*, value*)`**; writes **`*out`**; **`RET 0x10`**. Not ECX-thiscall.
3. **Semantics:** MSVC `_Tree` **always-insert** + RB rebalance for **Val8** (`0x18`):
   - If `size > 0x1ffffffd` → throw `"map/set<T> too long"` / `DAT_00acc388`.
   - `n = FUN_00439110(head, where, head, color=0)` with **ESI=`value*`** (key@+0x0C, mapped@+0x10, isnil@+0x15=0); `size++`.
   - Link: empty head → root/leftmost/rightmost; else left (`addLeft!=0`) or right; maybe update extremities.
   - While parent **color@+0x14** red: recolor uncle or rotate (`FUN_004219b0` L / `FUN_0046f030` R).
   - Paint root black; `*out = n`.
4. **Node family:** Val8 / isnil15 — left@0 parent@4 right@8 key@0x0C mapped@0x10; **color@0x14**; **isnil@0x15**.
5. **Classification:** worker (shared multi-caller always-insert helper).
6. **Callers (6 fn / 24 sites):** `FUN_0041d680`, `FUN_00421050`, `FUN_0043daf0`, `FUN_00452190`, `FUN_004582e0`, `FUN_00458510` (`StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred`, W37-K).
7. **Callees:** `FUN_00439110`, `FUN_004219b0`, `FUN_0046f030`, basic_string / `FUN_00401a40` / `_CxxThrowException`.
8. **Name:** `StdTree_InsertAndRebalance_Val8_Isnil15_Inferred` (Ghidra `FUN_00438140`; **Inferred**). **Reject** scaffold Mission Named_CalleeOf. **Do not** merge with Val12 `005e13b0` (max `0x15555553`, color@+0x18) or claim rotates are W24-O VAs `004e22d0`/`006753b0` (same family, different clones).
9. **Decompile ≡ raw CF**; **bytes win** on EDI map, max constant, RET 0x10, color@+0x14. Closes W37-K residual “full dual of insert helper `FUN_00438140`”. Full hex: raw W38-L append.

### Gaps

- Full dual of buynode `FUN_00439110` + rotate clones `004219b0`/`0046f030`.  
- Product English / demangle for six caller map types.  
- Buynode null OOM path.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00438140_StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00438140_StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00438140_FUN_00438140.md` |
| Annotated | `docs/reconstruction/raw/aa_00438140_FUN_00438140.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00438140.cpp` |
| Function | `docs/reconstruction/functions/aa_00438140_FUN_00438140.md` |
| Function named | `docs/reconstruction/functions/aa_00438140_StdTree_InsertAndRebalance_Val8_Isnil15_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00438140.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c17b0` | Port as **host-link subobject ctor**: **ECX=this (8 B)**, stack **host\***, returns this, **`RET 4`**. Vtbl `009cb7a4`; host @ `+4`. Optional list push_back of `this` on host sentinel @ `+8` / size @ `+0xC` (IncSize thiscall base `host+4`). Do **not** treat ECX as full 0x40 liquid-child. Do **not** invent NDRiver product plate. Nested list helpers stay free. |
| `00438140` | Port as **Val8 always-insert + RB**: **EDI=map**, stack `(out*, addLeft, where*, value*)`, **`RET 0x10`**. Max **`0x1ffffffd`**. Node **0x18** color@**+0x14** isnil@**+0x15**. No key compare — parent owns uniqueness. Pair with insert-or-find `00458510` (W37-K). Do **not** use Val12 thiscall/`0x15555553`/color@+0x18 templates. Rotates are `004219b0`/`0046f030` (not necessarily W24-O sealed VAs). |
| Shared | Closes W38-L OWN pair: **W37-G host-link residual** + **W37-K Val8 insert+RB residual**. Not algorithmically related beyond wave co-ownership. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004c1800` | `ParticleFluidLiquidChild_Ctor_Inferred` (W37-G) — sole caller of `004c17b0` |
| `0x004c1960` | `ParticleFluidPhase_CreateLiquidChild_Inferred` (W34-O) |
| `0x006759b0` | list buynode 0xC |
| `0x004c20b0` | list IncSize / `"list<T> too long"` |
| `0x004c09c0` | vtbl method of `009cb7a4` (unOWN) |
| `0x00458510` | `StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred` (W37-K) — primary dualed parent of `00438140` |
| `0x00439110` | Val8 buynode 0x18 |
| `0x004219b0` / `0x0046f030` | L/R rotate isnil15 clones used here |
| `0x004e22d0` / `0x006753b0` | W24-O sealed isnil15 rotate pair (different VAs) |
| `0x005e13b0` | Val12 InsertAndRebalance peer (W37-K) — do not cross-wire |

Closes W38-L OWN pair: liquid-child host-link subobject ctor under CreateLiquidChild path + Val8 tree insert+RB under isnil15 insert-or-find family.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected Named_CalleeOf / NDRiver / Mission aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit HostLink/NodeVal8 layouts).  
- Val12 insert twin and W24-O rotate VAs deliberately not dualed here (other owners / prior waves).
