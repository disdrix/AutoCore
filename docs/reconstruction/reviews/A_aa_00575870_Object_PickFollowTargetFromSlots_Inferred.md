# Review A (reconstruction fidelity): `aa_00575870` Object_PickFollowTargetFromSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575870` |
| **VA** | `0x00575870` |
| **Body** | `0x00575870`–`0x00575a85` |
| **Canonical name** | `Object_PickFollowTargetFromSlots_Inferred` |
| **Ghidra name** | `FUN_00575870` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_00575870` (chain-only; superseded for role) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00575870_Object_PickFollowTargetFromSlots_Inferred.md` |
| **System** | combat / convoy-follow target selection |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callees, constant `DAT_00aaa8a8` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Pick a follow / convoy-linked target TFID** from a small set of slot TFIDs on `this`, with range and validity gates. Returns **`uint64` TFID** or **`-1`** (`0xFFFFFFFFFFFFFFFF`).

```c
// __thiscall; ret 8 (two stack formals)
uint64_t __thiscall Object_PickFollowTargetFromSlots_Inferred(
    Object *this, Object *pOtherOrAnchor, float *pPosXZ /* uses [0] and [2] */);
```

### High-level loop

1. If `pOtherOrAnchor == NULL` → **return -1**.
2. If **`this+0x190 == 0`** (flag off) → return **anchor’s own TFID** at `anchor+0x164/0x168` (via vobj header).
3. If anchor field **`+0xa8`** (relative) is 0 → **return -1**.
4. Call anchor vfunc **`+0x1a0`** (get world position side-effect / touch).
5. Ensure working vector at **`this+0x1f8` / `+0x1fc`**:
   - If empty/null → `FUN_005756a0` rebuilds from up to **4** slot TFIDs at **`this+0x198`** (count byte **`this+0x1d8`**).
   - If still empty → **-1**.
6. If vector non-empty: **Fisher–Yates shuffle** via `FUN_00575b30(begin, end, 0)`.
7. Pop front TFID pair (`FUN_0051bdd0` erase-at / shift); **`Client_LookupObjectByTfid_Inferred(1, lo, hi)`**.
8. If object found:
   - Get position via vfunc **`+0x1a0`**.
   - **XZ distance** `sqrt((dz)^2 + (dx)^2)` (no Y) vs **`DAT_00aaa8a8 = 300.0f`** (`hex 00 00 96 43`).
   - In range:
     - If vector size after pop **`== 1`** (`FUN_00419170`) → **return that TFID**.
     - Else find slot index `FUN_005747e0(lo,hi)`; if &lt;0 → **-1**.
     - Resolve slot object `FUN_00574760(idx)`; if non-null and vfunc **`+0x198` returns 0** → return **that object’s TFID** (`+0x164/+0x168`).
   - Out of range: if vector empty after pop → fall back to **anchor TFID**; else continue loop.
9. If lookup miss: if vector still non-empty continue; else loop condition uses size helper (effectively retry / drain).

**Sole live caller:** `FUN_00521510` — if `this+0xcb0 == 0` return self TFID; else call this and if **-1** fall back to self TFID.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / clean | `aa_00575870_*` |
| Live decompile | complex loop; ≡ raw spine |
| Range constant | `read_memory 0x00aaa8a8` → `00009643` = **300.0f** |
| Rebuild slots | `FUN_005756a0` — copy ≤4 TFIDs from `+0x198` using count `+0x1d8` into vector `+0x1f8` |
| Shuffle | `FUN_00575b30` — rand Fisher–Yates on 8-byte pairs |
| Pop | `FUN_0051bdd0` — erase 8-byte element, shrink end by 8 |
| Size | `FUN_00419170` — `(end-begin)>>3` |
| Slot find / get | `FUN_005747e0` / `FUN_00574760` |
| World lookup | `Client_LookupObjectByTfid_Inferred` `0x004bb0a0` |
| Caller | `FUN_00521510` `0x00521510` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Return type u64 TFID or -1 | **Confirmed** | |
| Flag `+0x190` short-circuit → anchor TFID | **Confirmed** | |
| Slot table `+0x198` ×4, count `+0x1d8` | **High** | rebuild helper |
| Work vector `+0x1f8/+0x1fc` of 8-byte TFID pairs | **Confirmed** | |
| Shuffle before pick | **Confirmed** | `00575b30` |
| XZ-only range vs **300.0f** | **Confirmed** | constant + formula |
| TFID fields `+0x164/+0x168` on objects | **High** | CONCAT44 pattern |
| Product “convoy/follow” English | **Probable** | slots + range + OnDeath chain alias |
| Vfunc `+0x1a0` = get world pos | **High** | float* use |
| Vfunc `+0x198` gate meaning | **Medium** | false → accept TFID |
| Full loop termination on all miss paths | **Medium** | decomp `while(true)` with size checks |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Null anchor → -1 | **Yes** |
| Flag off → anchor TFID | **Yes** |
| Rebuild empty vector from slots | **Yes** |
| Shuffle + pop + lookup | **Yes** |
| Range gate 300 XZ | **Yes** |
| In-range slot resolve / return TFID | **Yes** |
| Out-of-range empty → anchor TFID | **Yes** |
| Caller 521510 fallback self | **Yes** (caller unit) |

---

## 5. Layout (this object — follow host)

| Offset | Role |
|---|---|
| `+0x190` | enable flag (0 → always use anchor TFID) |
| `+0x198` | TFID slot table (4 × stride 0x10; lo/hi at +0/+4) |
| `+0x1d8` | slot count byte (0..4) used by rebuild |
| `+0x1f8` | vector begin (u64 TFID*) |
| `+0x1fc` | vector end |
| `+0x200` | vector capacity end (rebuild growth) |

---

## 6. Gaps

1. Product name for host class / follow vs convoy vs party.
2. Exact meaning of vfunc `+0x198` false (alive? not busy? not self?).
3. Why shuffle (fairness among near targets) — behavioral only.
4. Runtime deferred.

**Verdict:** **accept-with-gaps** — range, slots, shuffle, TFID return sealed; product English residual.
