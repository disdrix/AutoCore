# Review A (reconstruction fidelity): `aa_0048a060` SoftCastHitList_SortIfCountGt1_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048a060` |
| **VA** | `0x0048a060`–`0x0048a082` inclusive (**35 B** / `0x23`) |
| **Canonical name** | `SoftCastHitList_SortIfCountGt1_Inferred` |
| **Ghidra name** | `FUN_0048a060` |
| **Prior scaffold** | `FUN_0048a060` (2026-07-23 trio) |
| **Rejected misname** | generic `Named_CalleeOf_*` not present; reject "always sort", "cdecl free function", "distance hard-coded here" |
| **Review date** | `2026-08-05` (MEGA-116 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` |
| **System** | interaction-activation (soft-cast hit list) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` / `get_function_callees` + `get_xrefs_to` + `get_function_by_address` + call-site context in `FUN_00925820`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **sort gate** for the soft-cast hit-list container used by world-click interaction:

```text
SoftCastHitList_SortIfCountGt1_Inferred(this)
  count = this->count            // +0x14
  if count > 1:
    FUN_00489f20(this->array_base, 0, count-1, this & 0xFFFFFF00)
  return
```

Sole retail caller: dualed **`Client_InteractWorldClickHub`** (`0x00925820`) after soft-cast fill (`FUN_0055e1e0` → `FUN_006ca890`). Post-sort walk resolves objects via `FUN_0040afb0` on hit slot `+0x20`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-116 append) | `docs/reconstruction/raw/aa_0048a060_FUN_0048a060.md` |
| Annotated | `docs/reconstruction/raw/aa_0048a060_FUN_0048a060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SoftCastHitList_SortIfCountGt1_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048a060.cpp` |
| Function record | `docs/reconstruction/functions/aa_0048a060_FUN_0048a060.md` |
| Named record | `docs/reconstruction/functions/aa_0048a060_SoftCastHitList_SortIfCountGt1_Inferred.md` |
| Live | decompile ≡ scaffold CF; body hex 35 B; 1 CALL xref; ECX this at call site |
| Parent hub | dualed `Client_InteractWorldClickHub` (W17-C) |
| Sort core | `FUN_00489f20` (MEGA-115 residual; elem 0x30 / key float +0x14) |
| Container ctor | `FUN_0040c410` (+0x10 base, +0x14 count) |

---

## 3. Signature (sealed)

```c
// ECX = SoftCastHitList* this; void; bare RET
void __thiscall SoftCastHitList_SortIfCountGt1_Inferred(SoftCastHitList *this);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`MOV EAX,[ECX+0x14]`; call site `LEA ECX,[ESP+0xe0]`) | **Confirmed** |
| stack args | none | **Confirmed** |
| return | void; no EAX contract | **Confirmed** |
| cleanup | bare **`RET`** (`C3`) | **Confirmed** |
| count field | **`this+0x14`** | **Confirmed** |
| array field | **`this+0x10`** | **Confirmed** |

**Note:** Decompiler `__fastcall(uint param_1)` is register ECX as integer; assembly + call site seal **thiscall object**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Seed stack local from ECX; zero low byte | **Yes** (`PUSH ECX` / `MOV byte [ESP],0`) | **Confirmed** |
| Load count; compare to 1 | **Yes** | **Confirmed** |
| Skip sort when count ≤ 1 | **Yes** (`JLE`) | **Confirmed** |
| Push cookie, count-1, 0, base; CALL `00489f20` | **Yes** | **Confirmed** |
| `ADD ESP,0x10` cdecl cleanup | **Yes** | **Confirmed** |
| Epilog POP ECX / RET | **Yes** | **Confirmed** |
| No other callees / branches | **Yes** | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (gate + single dispatch) |
| External callers | **1** — `FUN_00925820` / `Client_InteractWorldClickHub` |
| Xref count | **1** UNCONDITIONAL_CALL @ `0x00925c3e` |
| Callees | `FUN_00489f20` only |
| Site role | after soft-cast fill; before multi-hit walk / pick |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| count>1 gate + full-range sort dispatch | **Yes** |
| Soft-cast hit container (ctor + fill + hub walk) | **Yes** (structural) |
| Sort key = float @ elem+0x14, stride 0x30 | **Yes** (in callee; not re-dualed) |
| Product / PDB English for type or key | **No** |

**Decision:** promote **`SoftCastHitList_SortIfCountGt1_Inferred`**. Reject claims that this function itself compares distances or resolves objects. Reject free-function / non-thiscall ports.

---

## 7. Gaps / open

1. Product English for hit-list class and float key (distance vs other).
2. Sort-core dual `0x00489f20` is MEGA-115 OWN residual.
3. Runtime / bit-exact / differential (no Launcher).

**Verdict:** **accept-with-gaps** — machine CF/ABI/call graph sealed; product English open → `_Inferred`.
