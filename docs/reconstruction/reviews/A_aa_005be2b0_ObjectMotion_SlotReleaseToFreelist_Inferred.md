# Review A (reconstruction fidelity): `aa_005be2b0` ObjectMotion_SlotReleaseToFreelist_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be2b0` |
| **VA** | `0x005be2b0`–`0x005be2e9` exclusive |
| **Body** | **57** bytes / `0x39` |
| **Canonical name** | `ObjectMotion_SlotReleaseToFreelist_Inferred` |
| **Ghidra name** | `FUN_005be2b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-I) |
| **Counterpart** | `reviews/B_aa_005be2b0_ObjectMotion_SlotReleaseToFreelist_Inferred.md` |
| **System** | client object motion / reaction slot freelist |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + callers/xrefs + empty-callee decompile |
| **Verdict** | **accept** |

---

## 1. Purpose

Freelist-release a motion slot payload:

1. If `node[+0x8]` (child) non-null → empty thiscall `FUN_004b0bd0(child)`, push child onto freelist via dword0, clear `+0x8`.
2. Empty thiscall `FUN_004b0bd0(node)`.
3. Push node onto freelist via dword0.

Call sites always pass **`ECX = DAT_00b036c0`** (global freelist head).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | full body @ `0x005be2b0` |
| Bounds | `get_function_by_address` → `005be2b0`–`005be2e9` |
| Body bytes | `read_memory` 64 B @ entry (ends `C2 04 00` + `CC`) |
| Callee | `FUN_004b0bd0` decompile = empty return |
| Callers | SlotListTick `0x005bb624`; teardown `0x005bbd0e` — both `B9 C0 36 B0 00` |
| Raw / annotated / clean | W28-I updated |

**Not performed:** Launcher, runtime golden, product demangle.

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = freelist head*; stack SlotNode*; RET 4; void
void ObjectMotion_SlotReleaseToFreelist_Inferred(SlotNode **head, SlotNode *node);
```

| Formal | Source | Conf |
|---|---|---|
| this / ECX | freelist head* (`DAT_00b036c0` at sites) | **High** |
| node | Stack[0x4] after push | **High** |
| cleanup | `RET 4` | **High** |
| return | void | **High** |

---

## 4. Control flow checklist

| Stage | Match | Conf |
|---|---|---|
| Child null skip | **Yes** | **High** |
| Child dtor stub + freelist push + clear | **Yes** | **High** |
| Node dtor stub + freelist push | **Yes** | **High** |
| ret 4 | **Yes** | **High** |
| Two callers, shared global freelist | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 57 B / ret 4 | **Confirmed** | `read_memory` |
| Algorithm freelist + child@+0x8 | **Confirmed** | decomp ≡ bytes |
| ECX is freelist not motion host | **Confirmed** | `mov ecx, 0x00B036C0` at both sites |
| `FUN_004b0bd0` empty | **Confirmed** | live decompile |
| Product English | **Inferred** | `_Inferred` |
| Runtime | **Open** | |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Semantic role of empty `FUN_004b0bd0` (stripped vs nop by design).
3. Runtime freelist integrity under nested child.

**Verdict:** **accept** — CF + ABI + freelist global sealed; product name residual only.
