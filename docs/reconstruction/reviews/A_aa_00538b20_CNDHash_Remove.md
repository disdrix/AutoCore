# Review A (reconstruction fidelity): `aa_00538b20` CNDHash_Remove

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538b20` |
| **VA** | `0x00538b20` |
| **Canonical name** | `CNDHash_Remove` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00538b20_CNDHash_Remove.md` |
| **System** | container / missions-progression (mission hash remove) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash remove(key, outValue*)** — `__thiscall` on hash object (mission-node family):

1. If `outValue != null` → `*outValue = 0` (clear before lookup).
2. If `this+0x1d` (traversal lock) non-zero → log `"HashError:remove, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **does not abort**.
3. Find node by key via **`FUN_004e2ca0`** — this callee **unlinks the node from its bucket chain** (walks chain comparing `node+0x10`, splices `+0x0c`, runs `FUN_00537d30`), returns node* or null.
4. On miss → **HRESULT `0x80004005`** (`E_FAIL`).
5. On hit:
   - If `outValue != null` → `*outValue = node->value` (`node+0x08` / `puVar1[2]`).
   - Clear `node->value = 0`.
   - Unlink from **doubly-linked global list** using head `this+0x14`, tail `this+0x18`, node links `+0x14/+0x18` (indices [5]/[6]).
   - Push node onto freelist: briefly set vtbl `PTR_LAB_009cf024`, then `*node = freelistHead` (`this+0x20`), `this+0x20 = node`.
   - Decrement count `this+0xc`.
   - Return **0**.

GiveMission uses this on **`char+0x538`** (completed hash) when re-granting repeatable missions. CompleteObjective also xrefs.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00538b20_FUN_00538b20.md` |
| Annotated | `docs/reconstruction/raw/aa_00538b20_FUN_00538b20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00538b20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00538b20_FUN_00538b20.md` |
| Fresh decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x00538b20` |
| Bucket unlink helper | `decompile_function` @ `FUN_004e2ca0` (`0x004e2ca0`) |
| Twin remove family | body pattern matches other HashError:remove units |
| Callers | `CVOGReaction_GiveMission`, `CVOGReaction_CompleteObjective` (3 xrefs) |
| Prior residual | `reviews/a_005327c0.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `int __thiscall(this, uint key, void **outValue)` | **High** | Stack 4/8; out optional |
| Out-param zeroed first when non-null | **Confirmed** | body |
| Lock `+0x1d` warn-only | **High** | same policy as insert |
| Miss → `0x80004005` | **Confirmed** | body |
| Hit → return 0, count-- | **Confirmed** | body |
| Value at node+0x08 (`[2]`) copied out then cleared | **High** | matches insert layout |
| List unlink head/tail +0x14/+0x18 | **High** | body |
| Freelist head at **`this+0x20`** | **High** | body; insert dual left freelist Open — this seals reclaim slot |
| Node vtbl family `009cf024` written before freelist overwrite | **High** | body; freelist reuses vtbl dword as next |
| `FUN_004e2ca0` = find+**bucket-unlink** by key | **High** | decompile walks key@+0x10, splices +0xc, returns node |
| `FUN_004e2ca0` ECX = bucket sentinel (not full hash) | **High** (role) | body uses `*(this+4)` as chain head ≡ insert sentinel+4 pattern; remove decompiler elides bucket index step |
| GiveMission `this` = `char+0x538` | **High** | residual asm |
| clean ≡ raw ≡ live | **High** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Optional out=0 | Y | Y | Y |
| Lock log + continue | Y | Y | Y |
| FUN_004e2ca0(key) | Y | Y | Y |
| Miss → E_FAIL | Y | Y | Y |
| Copy value out + clear | Y | Y | Y |
| List unlink head/tail | Y | Y | Y |
| Freelist push @ +0x20 | Y | Y | Y |
| count-- ; return 0 | Y | Y | Y |
| Invented arms | — | **None** | **None** |

### Recovered CF (authoritative)

```c
// int __thiscall CNDHash_Remove(CNDHash *this, uint key, void **outValueOpt)

if (outValueOpt) *outValueOpt = NULL;
if (this->lockedForTraversal /* +0x1d */) {
  log("HashError:remove, already locked for traversal");
  log("VOG_DEBUG_STOP");
}
// Bucket chain: resolve sentinel = buckets[key & mask], then:
Node *n = BucketFindUnlink(sentinel, key);  // FUN_004e2ca0 — unlinks +0xc, FUN_00537d30
if (!n) return 0x80004005;

if (outValueOpt) *outValueOpt = n->value;   // +0x08
n->value = NULL;

// doubly-linked list unlink (head +0x14, tail +0x18)
if (n == this->listHead) this->listHead = n->listNext;
else n->listPrev->listNext = n->listNext;
if (n == this->listTail) this->listTail = n->listPrev;
else n->listNext->listPrev = n->listPrev;

// freelist push (vtbl slot becomes freelist next)
n->vtbl = PTR_LAB_009cf024;                 // transient; immediately overwritten
*(Node**)n = this->freelistHead;            // this+0x20
this->freelistHead = n;
this->count--;                              // +0x0c
return 0;
```

### `FUN_004e2ca0` (bucket find+unlink)

```c
// this = bucket sentinel; chain head at this+4; node next at +0xc; key at +0x10
// On match: splice prev->next = found->next (or update head), FUN_00537d30, return found
// On miss: FUN_00537d30, return 0
```

**Note:** Remove body decompile shows `FUN_004e2ca0(param_2)` only — bucket sentinel selection (`buckets[key&mask]`) is thiscall-elided in Ghidra for the outer call; helper body proves chain-root-at-`this+4` framing.

---

## 5. Param / local renames

| Raw | Preferred | Evidence |
|---|---|---|
| `param_1` | `hash` | ECX; fields +0xc/+14/+18/+1d/+20 |
| `param_2` | `key` | passed to find/unlink |
| `param_3` | `outValue` (optional) | zeroed; filled with node+0x08 |
| `puVar1` | `node` | freelist + list unlink |

---

## 6. Layout additions (beyond insert dual)

| Off | Field | Evidence |
|---|---|---|
| hash+0x20 | `freelistHead` (node*) | remove push; insert alloc likely pops here |
| (insert dual) +08 mask, +0c count, +10 buckets, +14 head, +18 tail, +1d lock | sealed | remove uses same |

Node freelist reuses **vtbl dword** as singly-linked next while on freelist.

---

## 7. Callers

| Site | Role | Conf |
|---|---|---|
| GiveMission @ `00532973` | remove from **`char+0x538`** completed hash on re-grant | **High** |
| CompleteObjective @ `005347b6` / `005347c6` | strip mission hash entries | **High** (xref) |

---

## 8. Gaps / open questions

1. Exact assembly for bucket-sentinel load before `FUN_004e2ca0` (decompiler elision) — role High, encoding Open for bit-exact.
2. Whether miss returns without mutating freelist/list (yes from CF) — Confirmed.
3. Sibling remove VAs (e.g. other HashError:remove) — not dualed here.
4. Runtime remove capture Open.
5. Bit-exact deferred.

**Verdict:** **accept-with-gaps** — remove CF + freelist@+0x20 + bucket unlink via `FUN_004e2ca0` sealed High.
