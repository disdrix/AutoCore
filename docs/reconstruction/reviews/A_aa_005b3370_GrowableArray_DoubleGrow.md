# Review A (reconstruction fidelity): `aa_005b3370` GrowableArray_DoubleGrow

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b3370` |
| **VA** | `0x005b3370` |
| **Canonical name** | `GrowableArray_DoubleGrow` (inferred) |
| **Ghidra symbol** | `FUN_005b3370` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_005b3370_GrowableArray_DoubleGrow.md` |
| **System** | `util` / shared buffer grow (HB lists, phys arrays, framework) |
| **Verdict** | **accept** |

---

## 1. Purpose

Generic **pointer/value array capacity grow**: doubles capacity (or starts at **1** if capacity was 0), allocates `newCap * elementSize` via global allocator `DAT_00b05060` vtbl **`+0x10`** (tag `0x12`), **copies** old payload with `FUN_006380a0`, **frees** old buffer via vtbl **`+0x14`** only when stored capacity raw is **≥ 0** (high bit clear → owned heap; high bit set e.g. `0x80000000` → do not free), then stores new pointer and sets capacity field to **newCap** (positive, owned).

Layout of grow header at `param_1`:

| Offset | Field |
|---|---|
| `+0x00` | `void* data` |
| `+0x04` | `int capacity` (element count capacity; 0 → first alloc 1) |
| `+0x08` | `int capacityRaw` / free sentinel (`& 0x7fffffff` used by callers; signed test here for free) |

`param_2` = **element size in bytes** (HB lists pass `4`; other sites pass stride).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005b3370_FUN_005b3370.md` | ≡ live |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005b3370.cpp` | CF ≡ raw |
| Live decompile | Ghidra MCP `0x005b3370` | **≡ raw** |
| Live `read_memory` | entry 80 B | double / alloc tag `0x12` sealed |
| Parent duals | `A_aa_005078f0` Enqueue, `A_aa_00507950` Tick, `A_aa_0055eb80` ActivateHost | Grow policy already cited |
| Physics | `fn_005fd390_buildFramework`, AVD ctor | Array append grow |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `newCap = capacity*2; if capacity==0 → 1` | **High** | `lea ebp,[eax+eax]` / `mov ebp,1` |
| Alloc `(newCap * elemSize, 0x12)` via `DAT_00b05060+0x10` | **High** | `push 0x12; imul; call [eax+0x10]` |
| Copy `oldCount(=capacity)*elemSize` bytes old→new | **High** | `FUN_006380a0` |
| Free old only if `(int)capacityRaw >= 0` | **High** | `test eax,eax / js skip` then `+0x14` |
| Free size uses `(capacityRaw & 0x7fffffff) * elemSize` | **High** | Decompile |
| Store `data=new`; `capacityRaw = newCap` (positive) | **High** | End stores |
| **Does not** update count field (callers keep count) | **High** | Only three dwords in header touched: ptr + raw cap; middle stays old cap until… wait: stores `param_1[2]=iVar2` (newCap) and `*param_1=uVar1`; does **not** write `[1]` — capacity at +4 remains **old** until caller? |

**Clarify from decompile:**

```c
iVar2 = param_1[1] * 2;
if (param_1[1] == 0) iVar2 = 1;
uVar1 = alloc(iVar2 * param_2, 0x12);
FUN_006380a0(uVar1, *param_1, param_1[1] * param_2);
if ((int)param_1[2] >= 0)
  free(*param_1, (param_1[2] & 0x7fffffff) * param_2, 0x12);
*param_1 = uVar1;
param_1[2] = iVar2;   // capacityRaw = newCap
// param_1[1] NOT written
```

Callers (Enqueue) compare `count == (capRaw & 0x7fffffff)` where cap is at **`+0x08`** (index 2), not index 1. So layout is:

| Index | Enqueue pending (`this+0x28`) | Grow field role |
|---|---|---|
| `[0]` | data ptr | rewritten |
| `[1]` | **count** | **unchanged** by grow (copy length uses it as “old size”) |
| `[2]` | capacity raw | rewritten to newCap |

**Correction:** `param_1[1]` is **count**, not capacity. Grow doubles **count** to form new capacity when full (`count == cap` ⇒ `newCap = count*2`). When empty first push, count is 0 ⇒ newCap 1. Copy size = `count * elemSize`.

This matches Enqueue dual: “double count (≡ cap when full), or 1 if 0”.

| Claim (corrected) | Confidence |
|---|---|
| `[1]` = live **count** (copy length; not updated here) | **High** |
| `[2]` = capacity raw (new capacity stored here) | **High** |
| newCap = `count*2` or `1` if count==0 | **High** |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| `newCap = count? count*2 : 1` | Yes |
| Alloc `newCap * elemSize`, tag `0x12` | Yes |
| Memcpy old `count * elemSize` | Yes |
| Conditional free old by signed raw cap | Yes |
| Publish new ptr + new capacity raw | Yes |
| Count field untouched | Yes |

---

## 5. Callers

Very wide: `CVOGHBList_Enqueue`, `CVOGHBList_Tick`, `PhysSim_ActivateHost`, vehicle framework component arrays, many `FUN_0055e*` / `FUN_0062*` list helpers (50+ xrefs returned, truncated).

---

## 6. Gaps / open

1. Product name of allocator object `DAT_00b05060`.
2. Whether any caller expects `[1]` to become capacity (none observed; would break).
3. Runtime not required for CF seal.

**Verdict:** **accept** — grow policy, free sentinel, element-size parameter, and header layout sealed.
