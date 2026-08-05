# Review A (reconstruction fidelity): `aa_005e0cd0` LootCatalog_FillCandidateIds_QualityTypeBand_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0cd0` |
| **VA** | `0x005e0cd0` |
| **Body end** | `add esp,0x30` / `ret 0x18` (~`0x005e0f52`) |
| **Canonical name** | `LootCatalog_FillCandidateIds_QualityTypeBand_Inferred` |
| **Ghidra name** | `FUN_005e0cd0` |
| **Prior names** | `FUN_005e0cd0`; scaffold Named_CalleeOf…CVO |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005e0cd0_LootCatalog_FillCandidateIds_QualityTypeBand_Inferred.md` |
| **System** | inventory / loot catalog (filtered roll fill path) |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callers, helpers `005e0480`/`005e0590`/`005e1860` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Alternate catalog fill** used by filtered roll `LootCatalog_RollFilteredCandidateId_Inferred` (`0x005e1150`): index into **quality/type banded tables** inside the loot catalog, apply a **random band bias** (`FUN_005e0590`), then **range-copy** candidate dword IDs into the caller’s out-vector via `FUN_005e1860`.

Returns **1** if out-vector ends non-empty, else **0**. Does **not** pick a final ID (caller does).

### Control flow

1. SEH frame `LAB_009a7420`.
2. `typeRow = FUN_005e0480(param_2)` — sparse gear type → compact row (or −1).
3. Map `param_5` → index 0..4 (default 4); map `param_4` → quality band `local_30` ∈ 0..3.
4. `bias = FUN_005e0590()` (random band nudge using level in ESI residual) + `typeRow * 0x32` → linear index.
5. Build primary table cursor: `catalog + 0x10e13c + index*0x140`.
6. **Conditional typed slice** when quality∈[0,2] **or** type-param∈[0,3]:
   - Optional clear helper `FUN_0040f5b0` on a `0x50`-stride cell at `+0x10e04c`.
   - Select cell at `+0x10e00c` with `(typeIndex*0x10 + (4*index + qualityBand)*0x50)`.
   - Count dwords; `FUN_00410420` prep; `FUN_005e1860` copy range into out-vector (`param_3` is out-vector ref; last arg 0).
7. **Always** also copy from the `+0x10e13c` band row into out-vector with `FUN_005e1860(..., *(out+4))` (append / merge semantics residual).
8. Return 1 if `out` non-empty (`(end-begin)>>2 != 0`), else 0.

**Sole live caller:** `FUN_005e1150` (passes `&local_vector` and sentinel `0xffffffff` as last formal in decompiler view).

**Not** unfiltered fill `005e07d0`, not the pick, not exclusion-list logic (lives in `005e1150`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record | `docs/reconstruction/functions/aa_005e0cd0_FUN_005e0cd0.md` |
| Raw / annotated / clean | `aa_005e0cd0_*` / `FUN_005e0cd0.cpp` |
| Live decompile | Ghidra `0x005e0cd0` (2026-07-29) — **≡ scaffold CF** (unreachable-block warnings only) |
| Epilogue | `ret 0x18` (6 stack dwords cleaned; this in ECX) |
| Caller dual | `A\|B_aa_005e1150_LootCatalog_RollFilteredCandidateId_Inferred` |
| Helpers | `005e0480` type map; `005e0590` band bias; `005e1860` range copy |

---

## 3. Signature

```c
// __thiscall; ret 0x18
int __thiscall LootCatalog_FillCandidateIds_QualityTypeBand_Inferred(
    void *catalog,       // this / param_1
    int typeCode,        // param_2 → 005e0480
    void *outVector,     // param_3 — filled by 005e1860
    int qualityOrA,      // param_4 → band 0..3
    int typeOrB,         // param_5 → index 0..4
    int outVectorAgain); // param_6 — used as vector* for emptiness / append base
// returns: 1 if any candidates, else 0
```

Decompiler SEH + dual use of out-vector formals is **Probable** residual (caller passes vector + `0xffffffff` sentinel in dual notes).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Fill-not-pick; returns empty/non-empty | **Confirmed** | |
| Type remap `005e0480` + bias `005e0590` | **Confirmed** | |
| Tables at catalog `+0x10e00c` / `+0x10e04c` / `+0x10e13c` | **Confirmed** | offsets in body |
| Copy via `005e1860` | **Confirmed** | |
| Sole caller `005e1150` | **High** | |
| Distinct from `005e07d0` tables | **High** | different bases |
| Clean ≡ raw ≡ live | **High** | |
| Exact formal product names / sentinel role | **Tentative** | |
| Full cell geometry | **Tentative** | |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH + type/quality maps | **Yes** |
| Bias index + primary row | **Yes** |
| Conditional typed copy | **Yes** |
| Always secondary/band copy | **Yes** |
| Return 1/0 on emptiness | **Yes** |

---

## 6. Gaps / open

1. Why `ret 0x18` vs five obvious stack formals — extra sentinel formal map.
2. `FUN_005e0590` ESI level source (decompiler `unaff_ESI`).
3. Product names for `+0x10e00c` family.
4. Runtime.

**Verdict:** **accept-with-gaps** — fill role + offsets **High**; ABI/formal English residual.
