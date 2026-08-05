# Review A (reconstruction fidelity): `aa_004bbc70` COList_Destructor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbc70` |
| **VA** | `0x004bbc70`–`0x004bbea4` |
| **Canonical name** | `COList_Destructor` |
| **Ghidra name** | `FUN_004bbc70` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-J) |
| **Counterpart** | `reviews/B_aa_004bbc70_COList_Destructor.md` |
| **System** | client / COList |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` full body (565 B) + callers/callees/xrefs + vtbl rdata strings. Twins: scalar `FUN_004bd1b0`, ctor `FUN_004bbfb0`, list primitives duals. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Destroy a **COList** (cloned-object list host): reinstall vtbl, collect hash-resident objects needing detach onto a stack `ThreadSafeObjectList`, drain via `TakeByCoid`, virtual-delete owned children, free vector buffers.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W26-J) | `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.md` |
| Annotated | `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/COList_Destructor.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bbc70.cpp` |
| Function record | `docs/reconstruction/functions/aa_004bbc70_COList_Destructor.md` |
| List twins | `aa_0040b020`, `aa_004bcbf0`, `aa_004024d0` |
| Take twin | `aa_004bb970` ClonedObjectList_TakeByCoid_Inferred |
| Live | decompile ≡ raw; 565 B; exit `83 C4 44 C3` |

---

## 3. Signature (sealed)

```c
void __thiscall COList_Destructor(COList* this);
// ECX=this; frame 0x44; bare ret; void
```

| Item | Evidence | Conf |
|---|---|---|
| Body size | `004bbc70`–`004bbea4` = **565 B** | **High** |
| Vtbl | `C7 06 48 B4 9C 00` → `0x009cb448` | **High** |
| Product class | rdata `COList::Insert` at `0x009cb464` | **High** |
| Scalar wrapper | `FUN_004bd1b0` = body + optional delete; vtbl[0] | **High** |

---

## 4. Control flow (sealed)

```
*this = PTR_FUN_009cb448
construct stack ThreadSafeObjectList (vtbl 009cb368 + ICS×2)
for hash in {this[1], this[2]}:
  lock hash+0x1d
  walk nodes (+0x14 first, +0x20 next); payload @ +0x0C
  if payload+0xac != 0: AppendPayload(stackList, payload)
  unlock
while payload = PopFront(stackList):
  TakeByCoid(this, payload+0x168, payload+0x160, payload+0x164)
vdel this[6], [7], [8], [9], [1], [2]
ThreadSafeObjectList_Dtor(stackList)
free buffer triples [0x13], [0xf], [0xb]
ret
```

| Stage | Match | Conf |
|---|---|---|
| Stack list layout | **Yes** (bytes + twin seals) | **High** |
| Dual hash walk + 0xac gate | **Yes** | **High** |
| TakeByCoid drain | **Yes** | **High** |
| Owned vdel order | **Yes** | **High** |
| FUN_004bcbf0 on stack (not member) | **Yes** (`lea ecx,[esp+…]`) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Hex / note |
|---|---|
| Entry | `83 EC 44 53 55 8B 2D EC 61 9C 00 56 57 33 DB … C7 06 48 B4 9C 00` |
| Stack vtbl | `C7 44 24 14 68 B3 9C 00` pattern → `PTR_FUN_009cb368` |
| Exit | `5E 5D 5B 83 C4 44 C3` |
| Full body | 565 B @ `0x004bbc70` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Direction | Detail |
|---|---|
| Caller | `FUN_004bd1b0` only |
| Ctor twin | `FUN_004bbfb0` → `DAT_00b04830` from InitInstance |

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / COList class / stack list / drain CF | **High** |
| TakeByCoid field offsets on payload | **High** |
| Vector slot product English | **Partial** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English for hashA/hashB and vector slots.
2. Exact `sizeof(COList)` from ctor (fields through ~+0x54 observed).
3. Runtime hit verification.

**Verdict:** **accept** — CF/ABI/class/list contract sealed; residual is naming depth only.
