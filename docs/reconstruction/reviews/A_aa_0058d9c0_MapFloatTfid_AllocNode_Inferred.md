# Review A (reconstruction fidelity): `aa_0058d9c0` MapFloatTfid_AllocNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d9c0` |
| **VA** | `0x0058d9c0` |
| **Canonical name** | `MapFloatTfid_AllocNode_Inferred` (was `FUN_0058d9c0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0058d9c0_MapFloatTfid_AllocNode_Inferred.md` |
| **System** | shared container helper (`skills-abilities` gather; also spatial / AI / other maps) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate and zero-init a 0x30-byte map/tree node** used by the float-key + 0x10 payload family:

1. `operator_new(0x30)`
2. Zero `node[0]`, `node[1]`, `node[2]` (left / parent / right) when non-null checks pass
3. `*(u8*)(node+0x28) = 1` (color / flag byte at dword index 10)
4. `*(u8*)(node+0x29) = 0` (isnil = false for a live node; callers often flip head isnil to 1)

Returns node pointer in **EAX** (decompiler shows `void` / omits `return puVar1` — **call-site sealed**).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058d9c0_FUN_0058d9c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0058d9c0_FUN_0058d9c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058d9c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058d9c0_FUN_0058d9c0.md` |
| Gather use | `Skill_GatherTargetsInArea` head setup @ `0x0058d358` |
| Ghidra | `batch_decompile` + `analyze_function_complete` + callers |

**Live re-decompile 2026-07-29 ≡ raw.**

---

## 3. Callers (xref sealed — multi-system)

| Caller | VA | Role (brief) |
|---|---|---|
| `Skill_GatherTargetsInArea` | `0x0058d330` | distance-sort map head |
| `FUN_0058cd60` | `0x0058cd60` | related tree helper |
| `FUN_004ea350` | `0x004ea350` | spatial query (multiple sites) |
| `CVOGHBAIBase_GetTargetFromAggro` | `0x00638ec0` | aggro structure |
| `FUN_004c9aa0` | `0x004c9aa0` | — |
| `FUN_00518c20` | `0x00518c20` | — |
| `FUN_005a1940` | `0x005a1940` | — |

**10** xrefs / **7** distinct callers from `analyze_function_complete`.

### Gather head init pattern (sealed)

```
local_ac = FUN_0058d9c0();
*(u8*)(local_ac + 0x29) = 1;   // head isnil
local_ac[1] = local_ac;          // parent = self
*local_ac = local_ac;            // left = self
local_ac[2] = local_ac;          // right = self
// size counter local_a8 = 0
```

Classic MSVC `_Tree` head/sentinel construction on top of this allocator.

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| `new(0x30)` | **Yes** |
| Zero three link dwords | **Yes** (null-checked oddly: `if (puVar1+i != 0)` always true if base non-null) |
| `+0x28 = 1`, `+0x29 = 0` | **Yes** |
| No key/payload init | **Yes** |
| No tree link-in | **Yes** — pure node factory |

### Signature

```c
// __cdecl, 0 args
MapFloatTfidNode* MapFloatTfid_AllocNode_Inferred(void);
// returns EAX = node*; OOM path: new may throw/return null — body still writes if non-null
```

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Size **0x30** node alloc | **High** | body |
| Links at 0/4/8 zeroed | **High** | body |
| `+0x29` isnil family (same as walkers) | **High** | shared with 0058c7a0/def0/df60 |
| Multi-caller shared factory | **High** | xrefs |
| Return pointer EAX | **High** | all callers assign result |
| Decompiler void omission | **High** artifact | not behavioral |
| Product `std::_Tree_node` name | **Inferred** | layout Probable MSVC-era |
| Color byte English at +0x28 | **Probable** | set to 1 (red/black convention residual) |

---

## 6. Gaps / open

1. OOM behavior of this CRT `operator_new`.
2. Whether insert path uses same allocator for non-head nodes (likely `FUN_0058da40` family).
3. Product / PDB symbol.
4. Full inventory of every map type sharing 0x30 nodes (ownership not this unit).

**Verdict:** **accept-with-gaps** — node factory CF sealed; name `_Inferred`.
