# Review A (reconstruction fidelity): `aa_005b2df0` VehicleNet_SkillsHBNodeVector_ReallocInsert_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2df0` |
| **VA** | `0x005b2df0` |
| **Canonical name** | `VehicleNet_SkillsHBNodeVector_ReallocInsert_Inferred` (was `FUN_005b2df0`) |
| **Ghidra symbol** | `FUN_005b2df0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — nested residual of PackUpdate skills path) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b2df0_VehicleNet_SkillsHBNodeVector_ReallocInsert_Inferred.md` |
| **System** | input-drive-control / GhostVehicle SkillsMask pack (MSVC-like vector insert) |
| **Parent** | `FUN_005b30a0` ← Push `0x005b3110` ← PackOwnerSkillsHB |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Insert `count` copies of a 12-byte POD value** into a growable vector (`begin/end/cap` at `this+4/+8/+0xc`), reallocating when capacity is insufficient.

Live structure (stride **0xC** throughout):

1. Snapshot value triple into locals; SEH frame.
2. Capacity `cap = (cap_end-begin)/0xC` (0 if null begin).
3. If `count == 0` → return.
4. Overflow guard: if `count` would exceed `0x15555555 - size` → `FUN_005b2a00()` (length throw path; residual).
5. If `cap < size + count`:
   - New cap = `cap + (cap>>1)` (1.5×) unless half-add overflows → 0 then recompute via `FUN_00480c80` + count.
   - `operator_new(newCap * 0xC)`
   - `FUN_0057fb80` copy `[begin, insert_pos)` → new
   - `FUN_00538710` place-construct `count` copies of value at insert
   - `FUN_0057fb80` copy `[insert_pos, end)` after insert window
   - `operator_delete` old begin (decomp marks noreturn — **hazard**)
   - Rebind begin/end/cap
6. Else in-place branches:
   - Tail shift via `FUN_0057fb80` / `FUN_00456080` / `FUN_00537860` / `FUN_00539e90` depending on distance-to-end vs count.

**VehicleNet role:** only entered from skills HB collector slow path with **count=1**.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005b2df0` |
| Callers | via `005b30a0` (Push slow path) |
| Nested duals (this batch) | `00538710`, `0057fb80`, `00537860`, `00539e90` |

---

## 3. Signature

```c
void __thiscall SkillsHBNodeVector_ReallocInsert(
  Vec12 *this, void *insert_pos, uint count, const uint32_t value[3] /*or ptr*/);
```

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| 0xC element insert with 1.5× grow | **High** |
| Three-phase realloc copy (prefix / fill / suffix) | **High** |
| `operator_delete` noreturn is decomp false | **High** (same class hazard as other vectors) |
| Length limit `0x15555555` | **High CF** |
| Product English for 12-byte payload | **Low** residual |
| Exact throw helper string at `005b2a00` | **Open** residual |

**Verdict:** **accept-with-gaps**
