# Review A (reconstruction fidelity): `aa_005063c0` Object_SetRootField60_WalkParentChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005063c0` |
| **VA** | `0x005063c0` |
| **Canonical name** | `Object_SetRootField60_WalkParentChain_Inferred` |
| **Ghidra symbol** | `FUN_005063c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005063c0_Object_SetRootField60_WalkParentChain_Inferred.md` |
| **System** | object hierarchy / activate (nested from `Vehicle_ActivateEnterWorld` via `setDrivingInputs`) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **thiscall** hierarchy walker:

1. While `this+0xAC != 0`, set `this = *(this+0xAC)` (follow parent chain).
2. At the **root** (first object with `+0xAC == 0`), store **`root+0x60 = param_2`** (dword).
3. Return.

Does **not** write intermediates — only the root. Callers:

| Caller | Typical `param_2` |
|---|---|
| `Vehicle_ActivateEnterWorld` `0x00503f30` | **0** (clear root field) when owner / vehicle parent chain present |
| `CVOGSpawnPoint_SetObjectActiveState` `0x00564700` | active-state related dword (caller dual residual) |

ActivateEnterWorld also has a **direct** store path when `owner+0xAC == 0` (`owner+0x60 = 0`) that **does not** call this unit — same field, no walk needed.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_005063c0_*`, `reconstructed-exact/FUN_005063c0.cpp` |
| Function record | `functions/aa_005063c0_FUN_005063c0.md` |
| Parent | `Vehicle_ActivateEnterWorld`, `CVOGSpawnPoint_SetObjectActiveState` |
| Ghidra | `decompile_function` + `read_memory` 32 B @ entry |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Parent link at **+0xAC** | **High** | Body while-loop |
| Only **root** gets `+0x60` write | **High** | Store after walk |
| `param_2` dword width | **High** CF | `mov […+0x60], arg` |
| Product meaning of `+0x60` | **Tentative** | No string; activate clears to 0 |
| Product meaning of `+0xAC` parent | **Probable** | Common object parent link |
| Cycle safety | **Open** | No visited set; assumes tree |

---

## 4. Control flow seal

```
Object_SetRootField60_WalkParentChain_Inferred(obj, value):
  while *(obj + 0xAC) != 0:
    obj = *(obj + 0xAC)
  *(obj + 0x60) = value
```

Live bytes open with `cmp dword [ecx+0xac], 0` / walk / store.

---

## 5. Gaps / open

1. Name `+0x60` product field (active token? owner context? spawn root flag?).
2. Full spawn-point caller argument matrix.
3. Cycle / deep-chain behavior untested.

**Verdict:** **accept-with-gaps**
