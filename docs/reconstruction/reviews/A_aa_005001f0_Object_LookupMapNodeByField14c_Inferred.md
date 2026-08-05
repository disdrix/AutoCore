# Review A (reconstruction fidelity): `aa_005001f0` Object_LookupMapNodeByField14c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005001f0` |
| **VA** | `0x005001f0` |
| **Canonical name** | `Object_LookupMapNodeByField14c_Inferred` |
| **Ghidra name** | `FUN_005001f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_005001f0_Object_LookupMapNodeByField14c_Inferred.md` |
| **System** | combat / objective (shared map lookup glue) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Thin wrapper**: load dword key from `this+0x14c`, pass address to `FUN_0040b330` (map lower-bound / insert-get node helper):

```text
// ECX = object*
local = *(this + 0x14c)
return FUN_0040b330(map_or_global?, &local)  // decompiler voids return; callers use EAX
```

`FUN_0040b330` (live decompile): try find existing node by key; else build/insert; return `node+0x10` (value blob).

OnDeath: when `local_80` vehicle path, `iVar7 = FUN_005001f0(); local_74 = *(float*)(iVar7 + 0x178)` — loot/credit scalar from looked-up def.

Other callers: `CVOGObjectiveRequirement_Kill_Precheck`, `FUN_00611f20`, `FUN_006170b0`, `FUN_00566490`.

---

## 2. ABI

| Slot | Role |
|------|------|
| **ECX** | object* with key at **+0x14c** |
| **EAX** | pointer to map value (`node+0x10` from `0040b330`) |

Note: decompiler shows `FUN_0040b330` as `__thiscall` with two params — wrapper may rely on implicit map `this` in ECX **after** load, or static/global map. **Gap:** map object identity for `0040b330` thiscall.

---

## 3. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | wrapper + `0040b330` body |
| Callers | OnDeath `004dacb7`; kill precheck; objective FUN_* |
| Field | `+0x14c` key dword |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Loads `+0x14c` only | **High** |
| Delegates to `0040b330` | **High** |
| Callers use return as ptr | **High** |
| Value `+0x178` float used OnDeath | **High** (caller) |
| Map host / this for `0040b330` | **Tentative** |
| Key English (clonebase id?) | **Tentative** |

---

## 5. Gaps

1. Seal `0040b330` map object / ECX at call.
2. Product name of key `+0x14c` and value layout.
3. Decompiler void return on wrapper.

**Verdict:** **accept-with-gaps**.
