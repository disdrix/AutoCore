# Review A (reconstruction fidelity): `aa_004d28c0` CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d28c0` |
| **VA** | `0x004d28c0`–`0x004d296b` |
| **Canonical name** | `CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred` (Ghidra `FUN_004d28c0`) |
| **Ghidra name** | `FUN_004d28c0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Client_RecvCreateCharacter_004d28c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d28c0_CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred.md` |
| **System** | sector-map / vehicle-combat-pools |
| **Live tools** | `batch_decompile`, xrefs, parent dual `aa_004cf3b0` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**On sector level-index transition**, walk a tracked object list and **rescale each object's combat pools** from `oldLevel` → `newLevel`:

```c
// __thiscall
void CVOGSectorMap_NotifyLevelIndexChange_RescalePools_Inferred(
    SectorMap *this, int oldLevel, int newLevel);
```

Gates (all must pass):

| Gate | Meaning |
|---|---|
| `this != (SectorMap*)-0xA0` | Null-outer subobject guard (classic MSVC `this != -offset`) |
| `*(char*)(this+0x100) == 0` | Mode / suppress flag |
| `*(int*)(this+0xac) != 2` | Type / state exclusion |
| `oldLevel != newLevel` | No-op if unchanged |
| `newLevel < 0x10 \|\| oldLevel < 0x10` | At least one side in table-useful range |

Then:

1. Clamp each level: if `> 0xE` → `0xF` (table max index 15).
2. `FUN_004bade0()` lock / enter.
3. `listRoot = *(this+0xe4e8)`; iterate pointer vector `listRoot+0x2c .. +0x30` (dword elements).
4. For each object: `Object_ScaleCombatPoolsByLevelTable_Inferred(obj, oldLevel, newLevel)` (`FUN_004cf3b0`).
5. `FUN_004badf0()` unlock / leave.

**Sole static callers:** `FUN_004d32c0` (enter/+1) and `FUN_004d3310` (leave/−1).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x004d28c0` ≡ raw |
| Callee dual | `A/B_aa_004cf3b0_Object_ScaleCombatPoolsByLevelTable_Inferred` |
| Parents | `004d32c0` / `004d3310` |
| Level table | `DAT_009cc390` (via `004cf3b0`) |
| Raw / clean | `raw/aa_004d28c0_*`, `reconstructed-exact/FUN_004d28c0.cpp` |

---

## 3. Authoritative body (decompile)

```c
if (this == (void*)-0xA0) return;
if (*(char*)(this+0x100) != 0) return;
if (*(int*)(this+0xac) == 2) return;
if (oldLevel == newLevel) return;
if (!(newLevel < 0x10 || oldLevel < 0x10)) return;
if (newLevel > 0xE) newLevel = 0xF;
if (oldLevel > 0xE) oldLevel = 0xF;
FUN_004bade0();
root = *(this+0xe4e8);
for (i = 0; i < vec_count(root+0x2c, root+0x30); ++i)
  FUN_004cf3b0(vec[i], oldLevel, newLevel);
FUN_004badf0();
```

---

## 4. Layout (this body)

| Off | Field | Role |
|---|---|---|
| `+0xac` | state/type dword | skip when `== 2` |
| `+0x100` | suppress byte | skip when nonzero |
| `+0xe4e8` | list owner* | vector of objects to rescale at `+0x2c/+0x30` |

---

## 5. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| Level clamp ≤ 0xF | **Confirmed** |
| Calls `004cf3b0` per listed object | **Confirmed** |
| Only enter/leave index twins call it | **Confirmed** (xrefs) |
| Lock pair `004bade0`/`004badf0` | **High** CF; product English open |
| List identity at `+0xe4e8` | **Probable** (vector of combat-relevant objs) |
| Product name | **Open** (`_Inferred`) |

**Verdict:** **accept-with-gaps.**
