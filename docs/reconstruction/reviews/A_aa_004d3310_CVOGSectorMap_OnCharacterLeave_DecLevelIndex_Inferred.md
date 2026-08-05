# Review A (reconstruction fidelity): `aa_004d3310` CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3310` |
| **VA** | `0x004d3310`–`0x004d335e` |
| **Canonical name** | `CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred` (Ghidra `FUN_004d3310`) |
| **Ghidra name** | `FUN_004d3310` |
| **Prior alias** | `Named_CalleeOf_Named_VOGClient_004d3310` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d3310_CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred.md` |
| **System** | sector-map / combat-pool level index / equip residual |
| **Live tools** | `batch_decompile`, `get_bulk_xrefs`, `get_function_callers` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Sector-map character-leave bookkeeping** on `CVOGSectorMap` (`this`):

```c
// __thiscall
int* CVOGSectorMap_OnCharacterLeave_DecLevelIndex_Inferred(
    SectorMap *this, Object *leaving, char notifyPools);
```

1. `this+0xe818` (**level / power index**, same field combat-pool paths use as table index) **−= 1**.
2. If `notifyPools != 0`: call sibling `FUN_004d28c0(this, oldIndex, newIndex)` with `old = post+1`, `new = post` → optional combat-pool rescale fan-out.
3. Read leaving object's race byte from dual-base walk:
   `leaving → +4 → +4 → +0xac+leaving → +0x3c → +0x532` (byte; 0/1/2 = H/M/B).
4. `this+0xe81c[race] −= 1` (per-race headcount histogram).
5. Return pointer to the decremented race-counter cell.

**Sibling** `FUN_004d32c0` is the **increment** twin (enter / add path): `+0xe818++`, race bucket `++`, same optional `004d28c0` notify with swapped old/new.

**Production caller:** `CompletelyDestroyObject` path `FUN_009440e0` @ `0x00944413` / `0x009446f6` — after `FUN_004d9b50` remove-from-vector, when `FUN_004024b0()` (sector player-count probe) **changes**, pass local-player-present flag as `notifyPools`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x004d3310` ≡ raw |
| Sibling | `FUN_004d32c0` (mirror +1) |
| Notify callee | `FUN_004d28c0` (this batch) |
| Pool rescale | `Object_ScaleCombatPoolsByLevelTable_Inferred` `0x004cf3b0` via `004d28c0` |
| Destroy parent | `FUN_009440e0` CompletelyDestroyObject |
| Raw / clean | `raw/aa_004d3310_*`, `reconstructed-exact/FUN_004d3310.cpp` |
| Sector vector peer | `CVOGSectorMap_AddCharacter` `0x004d35c0` (`+0xe75c`) |

---

## 3. Authoritative body (decompile)

```c
// thiscall
*(this+0xe818) -= 1;
if (notifyPools) {
  FUN_004d28c0(/*ECX=this*/, *(this+0xe818)+1, *(this+0xe818));
}
race = *(byte*)( def_of(leaving) + 0x532 );
*(this+0xe81c + race*4) -= 1;
return this+0xe81c + race*4;
```

---

## 4. Layout (this body)

| Off | Field | Role |
|---|---|---|
| `+0xe818` | levelIndex / power index (dword) | decremented; combat-pool table index source elsewhere |
| `+0xe81c` | raceHist[…] (dword array) | index by def `+0x532` |

Leaving object race path: dual-base `+0xac` → subrecord `+0x3c` → byte `+0x532` (same byte garage UI uses for H/M/B kit labels).

---

## 5. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| `__thiscall` + 2 stack args + char flag | **High** |
| Decrements `+0xe818` then optional `004d28c0` | **Confirmed** |
| Race histogram at `+0xe81c[race]` | **Confirmed** |
| Sibling `004d32c0` is +1 twin | **Confirmed** |
| Called from CompletelyDestroyObject when count changes | **Confirmed** (xrefs) |
| Product name / exact English of `+0xe818` | **Open** (`_Inferred`) |
| Whether `+0xe818` is true “level” vs power band | **Probable** (pool table index 0..0xF) |

**Verdict:** **accept-with-gaps.**
