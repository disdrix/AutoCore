# Review A (reconstruction fidelity): `aa_00403680` CombatFloaterVector_InsertN_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403680` |
| **VA** | `0x00403680` |
| **Canonical name** | `CombatFloaterVector_InsertN_0x38_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00403680_CombatFloaterVector_InsertN_0x38_Inferred.md` |
| **System** | `missions-progression` / combat floater UI |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style `vector<T>::insert` / reallocate for **T size 0x38** (combat floater POD). Copies 14 dwords of payload into a stack temp, then:

1. **Realloc path** when `size + n > capacity`: grow capacity (`cap + cap/2`, or forced fit), `operator_new`, relocate prefix / insert n / suffix, `delete` old buffer, update begin/end/cap.
2. **In-place shift paths** when capacity suffices: move tail, construct new elements from payload template.

Early-out if `n == 0`. Overflow guard uses magic `0x4924924` (= `0x7fffffff / 0x38`) via `FUN_00418130` on impossible growth.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Ghidra decompile | `0x00403680` |
| Raw | `docs/reconstruction/raw/aa_00403680_FUN_00403680.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00403680.cpp` |
| Caller | `FUN_00402e20` (insert one) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Layout `+4 begin / +8 end / +0xc cap` | **High** | Same as enqueue parent |
| Element **0x38**; max count `0x4924924` | **High** | Division / compare |
| Payload snapshot 14 dwords | **High** | Loop `i=0xe` |
| Geometric grow `cap + (cap>>1)` | **High** | Classic MSVC vector |
| `operator_new` / `operator_delete` on realloc | **High** | Body |
| Helpers `FUN_004044c0` relocate, `FUN_00402ea0` fill-n, `FUN_004044e0` assign range | **Probable** | Roles from call shape; product names open |
| XP-unrelated | **High** | Storage only |

---

## 4. Gaps

1. Exact semantics of `FUN_004044c0` / `FUN_00402ea0` / `FUN_004044e0` / `FUN_00690970` (uninitialized-move vs copy).
2. Whether floater POD has non-trivial ctor (appears POD dword copy).

**Verdict:** **accept-with-gaps**
