# Review A (reconstruction fidelity): `aa_00537ef0` MissionStagingTree_DestroySubtree

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537ef0` |
| **VA** | `0x00537ef0` |
| **Canonical name** | `MissionStagingTree_DestroySubtree` (role-sealed; product English open) |
| **Ghidra name** | `FUN_00537ef0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00537ef0_MissionStagingTree_DestroySubtree.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested from GiveMission notify `FUN_0052d8b0` @ `0x0052d9f6` (+ range erase helper `FUN_00539150`) |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Destroy a red-black / tree-map subtree** of mission staging nodes:

1. Argument = tree node pointer (stack).
2. If node **is-nil** (`byte node+0x49 != 0`) → no-op return.
3. Else: recurse on **child @ `node+0x8`**, `operator_delete` current node, advance via **`node = *node`** (link at +0), loop until nil.

Used when clearing staging map after mission state notify (`FUN_0052d8b0`) and when `FUN_00539150` wipes full range `[begin, end)`.

Does **not** touch hash tables at `+0x538/+0x540`; only the `std::map`-shaped staging tree nodes.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00537ef0_FUN_00537ef0.md` |
| Annotated | `docs/reconstruction/raw/aa_00537ef0_FUN_00537ef0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00537ef0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00537ef0_FUN_00537ef0.md` |
| Live decompile | `batch_decompile` `0x00537ef0` |
| Live bytes | `read_memory` 48 B — nil test `+0x49`, recurse `+0x8`, `operator_delete` |
| Call sites | `get_assembly_context` `0x0052d9f6` (from `FUN_0052d8b0`); self; `FUN_00539150` |

**Not performed:** `disassemble_bytes`, Launcher.

---

## 3. Body (asm-corrected)

Decompiler collapses to single-node free after one child recurse. **Assembly** shows a **walk loop**:

```text
; EDI = node (stack arg)
cmp byte [EDI+0x49], 0
jnz  done                    ; nil/header → skip
mov  ESI, EDI
loop:
  mov  EAX, [ESI+0x8]
  push EAX
  call FUN_00537ef0          ; destroy child link
  mov  ESI, [ESI]            ; advance linked node
  push EDI
  call operator_delete
  add  esp, 4
  cmp  byte [ESI+0x49], 0
  mov  EDI, ESI
  jz   loop
done:
  ret
```

| Field | Offset | Role |
|---|---|---|
| child | `+0x8` | recursive destroy target |
| next / parent link | `+0` | walk after free |
| is-nil | `+0x49` | MSVC `_Tree` nil flag |

**Calling convention:** stack node pointer; ECX preserved as pass-through on recurse (same ECX pushed through). Prefer documenting as **`void DestroySubtree(Node* node)`** with optional unused ECX from thiscall callers.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Destroys staging tree nodes | **High** | Callers = map clear / range erase |
| Nil gate `+0x49` | **High** | Body + sibling tree walks |
| Recurse child `+0x8` | **High** | Asm + decompile |
| `operator_delete` per node | **High** | Call |
| Exact link polarity (left vs right vs parent) | **Probable** | MSVC layout; not product-named |
| Product symbol | **Open** | |
| Runtime free traces | **Open** | |

---

## 5. Gaps

1. Precise MSVC `_Tree_nod` field names (left/right/parent mapping to +0/+4/+8).
2. Whether ECX `this` is required (callers set ECX=map before some paths; body primarily uses stack node).

**Verdict:** Role + nil/child/delete spine **High**. **accept-with-gaps.**
