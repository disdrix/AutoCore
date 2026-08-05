# Review A (reconstruction fidelity): `aa_00413be0` List_IterateNext_u64

| Field | Value |
|---|---|
| **Stable ID** | `aa_00413be0` |
| **VA** | `0x00413be0` |
| **Canonical name** | `List_IterateNext_u64` (inferred; 64-bit key sibling of `List_IterateNext`) |
| **Ghidra symbol** | `FUN_00413be0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_00413be0_List_IterateNext_u64.md` |
| **System** | `inventory-transfer` / shared `client::list` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**One step of ordered list iteration** under an already-held `List_TraversalLock`, emitting a **64-bit key** (two dwords) per node.

```text
// __thiscall list*, cursor*, outKey64*  →  uint
// ret 8

if (*(list+0x28) == 0) return 0x80070005;   // not locked
if (!TryEnterCriticalSection(list+4)) return 0x80070005;

if (*cursor == 0):
  node = *(list+0x1c)                      // head
  if node: out = {*(node+8), *(node+0xc)}; else out = {0,0}
  *cursor = node
  LeaveCS; return (node == 0) ? 1 : 0      // 1 = empty/done, 0 = have item

node = *cursor
next = *(node+0x10)
if next:
  *cursor = next
  out = {*(next+8), *(next+0xc)}
  LeaveCS; return 0
else:
  *cursor = 0; out = {0,0}
  LeaveCS; return 1                        // end
```

Return codes:

| Code | Meaning |
|---|---|
| `0` | Have key in `*outKey64`; cursor advanced |
| `1` | End / empty |
| `0x80070005` | Not traversal-locked or `TryEnter` failed |

**Sibling:** `List_IterateNext` `0x004022a0` — same CF, but key is **single dword** at `node+4`, next at `node+8`.

Does **not** set or clear the traversal flag. Does **not** mutate membership.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00413be0_FUN_00413be0.md` |
| Annotated | `docs/reconstruction/raw/aa_00413be0_FUN_00413be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00413be0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00413be0_FUN_00413be0.md` |
| Live decompile | Ghidra `decompile` / `force_decompile` @ `0x00413be0` — **A ≡ B ≡ raw** |
| Live bytes | `read_memory` @ `0x00413be0` length 160 — `c2 08 00` |
| 32-bit sibling | live decompile `0x004022a0` |
| Insert twin | `FUN_00573040` stores key at `node+8/+0xc`, next at `+0x10` |
| Callers | `0x00571260` (grid collect), `0x00860700` RebuildItemWidgets (×2) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`; 2 stack args; `ret 8` | **High** | `c2 08 00` |
| Requires `+0x28` lock flag | **High** | Gate before TryEnter |
| Head at `list+0x1c` | **High** | Matches 32-bit sibling / clear |
| Key lo/hi at `node+8` / `node+0xc` | **High** | Decompile + insert twin |
| Next link at `node+0x10` | **High** | Advance path |
| Return 0/1/0x80070005 | **High** | All three exits sealed |
| Semantic "COID/TFID pair" | **High** (usage) / **Probable** (universal) | Rebuild resolves via `ResolveObjectTarget(1, lo, hi)` |
| Product name `List_IterateNext_u64` | **Probable** | No string on VA; role from layout |
| TryEnter vs Enter | **High** | IAT `TryEnterCriticalSection` |

---

## 4. Control flow: clean ≡ raw ≡ force

| Stage | Match |
|---|---|
| Not locked → `0x80070005` | **Yes** |
| TryEnter fail → same | **Yes** |
| Cursor 0 → head seed + 64-bit key | **Yes** |
| Cursor set → next via `+0x10` | **Yes** |
| End → cursor0 + zero key + return 1 | **Yes** |
| LeaveCS on all success paths | **Yes** |
| No flag clear | **Yes** |

### Node layout (64-bit key family)

| Offset | Role |
|---|---|
| `+0x00` | vtbl (scalar dtor used by Clear) |
| `+0x08` / `+0x0c` | key lo / hi |
| `+0x10` | next |
| `+0x14` | prev (insert path) |

Contrast 32-bit family (`0x004022a0`): key `+4`, next `+8`.

---

## 5. Callers

| Caller | Role |
|---|---|
| `FUN_00571260` | Match cell TFID against list during page collect |
| `Client_UI_InventorySheet_RebuildItemWidgets` `0x00860700` | Walk collected COIDs → AddItemWidget |

---

## 6. Gaps

1. Confirm product symbol vs `List_IterateNext` overload naming.
2. Whether any non-COID 64-bit payload uses same iterator (layout allows any u64).
3. Runtime under CS contention (`0x80070005` path).

**Verdict:** **accept-with-gaps** — CF + 64-bit layout **sealed**.
