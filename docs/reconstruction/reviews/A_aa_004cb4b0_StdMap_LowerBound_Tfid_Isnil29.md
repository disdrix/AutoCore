# Review A (reconstruction fidelity): `aa_004cb4b0` StdMap_LowerBound_Tfid_Isnil29

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4b0` |
| **VA** | `0x004cb4b0`–`0x004cb4eb` (**59 B**) |
| **Canonical name** | `StdMap_LowerBound_Tfid_Isnil29` |
| **Ghidra name** | `FUN_004cb4b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-N) |
| **Counterpart** | `reviews/B_aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md` |
| **System** | MSVC map lower_bound / TFID-shaped key |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return lower_bound node for TFID-shaped `(u32 lo, i32 hi)` key in a map with isnil at `node+0x29`. Leaf helper for object TFID map and peers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-N append) | `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_LowerBound_Tfid_Isnil29.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004cb4b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md` |
| Consumer dual | `aa_004c8970` Object_TFIDMapLookup… (W30-T **accept-with-gaps**) |
| Live | decompile ≡ bytes leaf walk |

---

## 3. Signature (sealed)

```c
// ECX = map host (head@+4); stack pKey; RET 4; Node* in EAX
Node* __fastcall StdMap_LowerBound_Tfid_Isnil29(void* map, const KeyU32I32* pKey);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX | **High** |
| pKey | stack `[ESP+4]` | **High** |
| cleanup | `C2 04 00` | **High** |
| return | EAX = candidate node (or head) | **High** |

---

## 4. Control flow (bytes authority)

```
head = *(this+4)
if head->parent.isnil: return head
cand = head; node = root
while !node.isnil:
  if search <= node.key:  // hi signed, then lo unsigned
    cand = node; node = left
  else:
    node = right
return cand
```

| Stage | Match | Conf |
|---|---|---|
| head@+4 / root=parent | decompile ≡ bytes | **High** |
| isnil@+0x29 | `80 79 29 00` | **High** |
| key lo@+0x10 hi@+0x14 | `[4]`/`[5]` compares | **High** |
| lower_bound (no equality) | no post-gate in body | **High** |
| leaf | no CALLs | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (59 B) — see raw W31-N append.

Epilogue: `5F 5E C2 04 00`. Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | leaf |
| Callers | `004c8970`, `004ca760`, `004cba00`, `004cc400`, `005a0470` |
| Closes | W30-T residual “Nested helper `FUN_004cb4b0` not OWN” |

---

## 7. Gaps

- Product map / value type at node `+0x20`.
- Whether all hosts share one class or layout clones.
- Runtime / bit-exact / differential.

---

## 8. Verdict

ABI/CF/key layout/lower_bound semantics sealed. Product English residual → **accept-with-gaps**.
