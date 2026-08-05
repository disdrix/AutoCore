# Review A (reconstruction fidelity): `aa_004d9b50` CVOGSectorMap_RemoveCharacter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d9b50` |
| **VA** | `0x004d9b50` |
| **Canonical name** | `CVOGSectorMap_RemoveCharacter_Inferred` (Ghidra `FUN_004d9b50`) |
| **Ghidra name** | `FUN_004d9b50` |
| **Prior alias** | `Named_CalleeOf_Named_VOGClient_004d9b50` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004d9b50_CVOGSectorMap_RemoveCharacter_Inferred.md` |
| **System** | sector-map / character list |
| **Live tools** | `batch_decompile`, xrefs, parent `FUN_009440e0` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Erase one character pointer** from the sector-map character vector and optionally refresh a secondary index structure:

```c
// __fastcall / thiscall-like ECX=SectorMap*
// stack: character* (or dual-base) to remove — decompiler shows as stack0x4 via lower_bound key
void CVOGSectorMap_RemoveCharacter_Inferred(SectorMap *this /*, Object *who */);
```

1. `FUN_0049c5f0` — find erase position in vector `this+0xe75c .. +0xe760` (same vector `CVOGSectorMap_AddCharacter` pushes into).
2. If found (`*it != end`): `memmove` compact; update `+0xe760` end pointer.
3. If flag `*(char*)(this+0xf6) != 0` (same creator-load flag family as AddCharacter):
   - Build temporary red-black/set sentinel via `FUN_0040f400`.
   - For each remaining character: call vfunc **`+0x28c`** → insert key into set (`FUN_0040ed60`).
   - If set size **`== 1`**: `FUN_004bb1c0(0, this+0xe7f0, this+0xe7f4)` resolve; if hit, vfunc **`+0x114(0)`** (reselect / sole-remaining notify).
   - Tear down set (`FUN_0040f2a0` + `operator_delete`).

**Callers:** CompletelyDestroyObject vehicle/character teardown (`0x00943ea8`, `0x009443d3`, `0x009446b4`) and `FUN_0052f260`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x004d9b50` ≡ raw |
| Add twin | `CVOGSectorMap_AddCharacter` `0x004d35c0` |
| Destroy parent | `FUN_009440e0` |
| Follow-on counter | `004d3310` when count delta |
| Raw / clean | `raw/aa_004d9b50_*`, `reconstructed-exact/FUN_004d9b50.cpp` |

---

## 3. Vector layout

| Off | Field | Role |
|---|---|---|
| `+0xe75c` | begin | character* vector begin |
| `+0xe760` | end | character* vector end |
| `+0xe764` | capacity end | (AddCharacter grow path; not written here) |
| `+0xf6` | flag | enables secondary set rebuild |
| `+0xe7f0/+0xe7f4` | TFID-ish pair | sole-remaining resolve args |

---

## 4. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw ≡ live | **Confirmed** |
| Erases from `+0xe75c` character vector | **Confirmed** |
| Inverse of AddCharacter push | **High** |
| Flag `+0xf6` gates set rebuild | **Confirmed** |
| Sole-remaining path when set count==1 | **High** CF |
| Product name of vfunc `+0x28c` / `+0x114` | **Open** |
| Exact stack ABI of erase key vs ECX | **Probable** (parent passes owner from `+0x1dc`) |

**Verdict:** **accept-with-gaps.**
