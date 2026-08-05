# Review A (reconstruction fidelity): `aa_0040dc40` List_ClearDestroy

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dc40` |
| **VA** | `0x0040dc40` |
| **Canonical name** | `List_ClearDestroy` (inferred) |
| **Ghidra symbol** | `FUN_0040dc40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0040dc40_List_ClearDestroy.md` |
| **System** | `inventory-transfer` / shared `client::list` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Destroy every node** in a critical-section list and zero head/count fields — **only when not traversal-locked**.

```text
// thiscall/fastcall list in ECX

EnterCriticalSection(list+4)
if (*(list+0x28) != 0):          // TraversalLock held
  LeaveCriticalSection(list+4)
  throw 0x80070005               // E_ACCESSDENIED-style COM HRESULT
node = *(list+0x1c)              // head
while node:
  *(list+0x1c) = node[4]         // head = next (dword index 4 → +0x10)
  (*node->vtbl)(1)               // scalar-deleting dtor
  node = *(list+0x1c)
*(list+0x24) = 0
*(list+0x20) = 0
*(list+0x1c) = 0                 // count/tail/head family cleared
LeaveCriticalSection(list+4)
```

Used as dtor/teardown for temporary COID lists (e.g. end of `Client_UI_InventorySheet_RebuildItemWidgets`) and other list owners.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040dc40_FUN_0040dc40.md` |
| Annotated | `docs/reconstruction/raw/aa_0040dc40_FUN_0040dc40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0040dc40.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040dc40_FUN_0040dc40.md` |
| Live decompile | Ghidra `decompile` / `force_decompile` @ `0x0040dc40` — **A ≡ B ≡ raw** |
| Live bytes | `read_memory` @ `0x0040dc40` length 128 — SEH + EnterCS + lock throw |
| Callers | `FUN_0040db30` / `0040dbc0` (list dtor chain), `0x00860700` Rebuild, `0x008e5e00`, `0x008ff5a0` |
| Sibling | TraversalLock soft-fail vs this **throw** |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EnterCS then check lock flag | **High** | Decompile + bytes |
| Locked → Leave + throw `0x80070005` | **High** | `C7 … 05 00 07 80` + `_CxxThrowException` |
| Walk head `+0x1c`; next via `node+0x10` (`puVar1[4]`) | **High** | Matches u64 node layout |
| Scalar dtor `vtbl[0](1)` | **High** | `push 1; call [edx]` |
| Zero `+0x24`, `+0x20`, `+0x1c` | **High** | Three dword stores |
| Does **not** free the list object itself | **High** | Only nodes |
| Name `List_ClearDestroy` | **Probable** | Role sealed; no string |
| Field English for `+0x20/+0x24` (tail/count) | **Probable** | Insert increments `+0x24` family via `param_1[9]` |

---

## 4. Control flow: clean ≡ raw ≡ force

| Stage | Match |
|---|---|
| SEH frame | **Yes** (`__chkstk` / large frame artifact) |
| EnterCS(`+4`) | **Yes** |
| If `+0x28` → Leave + throw | **Yes** |
| While head: unlink next, dtor(1) | **Yes** |
| Zero three fields; LeaveCS | **Yes** |
| Dual A≡B | **Yes** |

### Instruction seal (throw / loop core)

```text
8B F1                 mov esi, ecx
8D 7E 04              lea edi, [esi+4]
57 FF 15 …            EnterCriticalSection
8B 4E 1C              mov ecx, [esi+0x1c]   ; head
38 5E 28              cmp [esi+0x28], bl
74 1C                 jz  destroy_loop
57 FF 15 …            LeaveCriticalSection
C7 45 EC 05 00 07 80  ; 0x80070005
… _CxxThrowException
; loop: mov head, [node+0x10]; push 1; call [vtbl]; reload head
```

---

## 5. Callers

| Caller | Role |
|---|---|
| `FUN_0040db30` / `FUN_0040dbc0` | List object destructor helpers |
| `Client_UI_InventorySheet_RebuildItemWidgets` | Teardown stack-local COID list |
| `FUN_008e5e00` / `FUN_008ff5a0` | Other list owners |

---

## 6. Gaps

1. Exact English for `+0x20` vs `+0x24` (tail vs count) without insert dual cross-read.
2. Whether 32-bit key lists share this exact clear (next at `+0x10` implies **u64 node family** — 32-bit next is `+8`).
3. Runtime throw under concurrent TraversalLock.

**Note on (2):** Loop uses `puVar1[4]` = `+0x10` next — correct for u64 nodes used by Rebuild's local list (`PTR_FUN_00a34140`). Confirm before reusing on pure 32-bit key lists.

**Verdict:** **accept-with-gaps** — destroy CF + lock throw **sealed**.
