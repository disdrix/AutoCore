# Review A (reconstruction fidelity): `aa_0042b270` LinkedListHead_ClearNodes_00a9b1dc_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b270` |
| **VA** | `0x0042b270` |
| **Canonical name** | `LinkedListHead_ClearNodes_00a9b1dc_Inferred` (structural) |
| **Ghidra name** | `FUN_0042b270` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_0042b270_LinkedListHead_ClearNodes_00a9b1dc_Inferred.md` |
| **System** | net / TNL unpack teardown helpers |
| **Live tools** | `batch_decompile` 0x0042b270; Damage/TNL/unwind callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Reinstall vtbl + zero-walk** node chain for the same list-head type as `FUN_0042b250`:

1. `*this = PTR_LAB_00a9b1dc` (vtable reset — dtor/clear pattern).
2. `node = this[+4]` (first).
3. While `node != null`:
   - `next = node[2]` (link at +8)
   - `node[0]=0; node[1]=0; node[2]=0`
   - `node = next`

**Does not free** nodes or head storage — only zeroes node fields. Callers (Damage unpack teardown, TNL unpack, SEH unwind `009a6280`) free owning buffers separately after this walk.

Ctor twin: `FUN_0042b250` (empty head). Shared vtbl stamp **`00a9b1dc`**.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw / annotated / clean | `raw/aa_0042b270_*`, `reconstructed-exact/FUN_0042b270.cpp` |
| Function record | `functions/aa_0042b270_FUN_0042b270.md` |
| Ctor twin | `0x0042b250` |
| Callers | `EMSG_Sector_Damage_Unpack`, `TNL_ByteBuffer_UnpackData`, unwind |
| Live | next at `node+8`; no free |

**Three-rep:** present.

---

## 3. Signature

```c
// __fastcall  ECX = head*
void LinkedListHead_ClearNodes(ListHead *this);
```

Node layout (zeroed):

| Off | Cleared |
|---|---|
| +0 | dword 0 |
| +4 | dword 0 |
| +8 | next* → 0 |

---

## 4. Confidence

| Claim | Level |
|---|---|
| Vtbl reinstall `00a9b1dc` | **Confirmed** |
| Next link at node+8 | **Confirmed** |
| Zeroes 3 dwords per node | **Confirmed** |
| No free/delete | **Confirmed** |
| Does not clear head `this+4` after walk | **Confirmed** (stale head ptr may remain) |
| Product dtor name | **Tentative** |

---

## 5. Gaps

1. Whether head `+4` is expected null after (callers may overwrite/free).
2. Node freelist vs raw zero (no freelist push here).
3. Runtime open.

**Verdict:** **accept-with-gaps**
