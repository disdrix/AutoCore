# Review A (reconstruction fidelity): `aa_00545a90` CNDHash_Insert

| Field | Value |
|---|---|
| **Stable ID** | `aa_00545a90` |
| **VA** | `0x00545a90` |
| **Canonical name** | `CNDHash_Insert` (twin; node vtbl `PTR_FUN_009d01ac`) |
| **Ghidra name** | `FUN_00545a90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00545a90_CNDHash_Insert.md` |
| **System** | container / missions-progression (continent object hash) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Generic **CNDHash insert(key, value)** — `__thiscall` on hash object — **same control flow** as named twins (`0x0053c360` / `0x0053c560` / …) but stamps node vtbl **`PTR_FUN_009d01ac`**.

CF (live decompile ≡ clean scaffold ≡ bytes):

1. Null `value` → **`0x80004003`** (`E_POINTER`); **`ret 0x0c`**.
2. If `this+0x1d` (traversal lock) ≠ 0 → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue** (no abort).
3. If `softIfExists != 0` and `CNDHash_LookupByKey` hits → **return 1** (no insert).
4. Else if lookup hits → log `"Duplicate hash insert %u, failing out"` → **`0x80004005`** (`E_FAIL`).
5. Alloc node via `FUN_0053ada0` (0x1c freelist slab family).
6. Init: vtbl `009d01ac`, touch byte `+0x04=0`, value `+0x08`, key `+0x10`, bucket link `+0x0c`, list links `+0x14/+0x18`.
7. Bucket index `key & *(this+8)`; table `*(this+0x10)`; head-insert at sentinel `+4`; `FUN_00537d30` integrity walk.
8. Append global list head `+0x14` / tail `+0x18`; `count++` at `+0xc`; return **0**.

**Caller:** `FUN_00541950` after `Mission_tContinentObject` (`0x007dbce0`) load — inserts each **0x154** row with key = first dword, value = row pointer, soft flag **0**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00545a90_*`, `reconstructed-exact/FUN_00545a90.cpp` |
| Function record | `functions/aa_00545a90_FUN_00545a90.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00545a90` (2026-07-29) |
| Bytes | `read_memory` 96 B — null-value → `B8 03 40 00 80` / **`C2 0C 00`**; lock byte `cmp [edi+0x1d]` |
| Twin duals (CF evidence) | `A_aa_0053c560_CNDHash_Insert.md`, `0053c360`/`0053c660`/`0053c760` |
| Lookup | `CNDHash_LookupByKey` @ `0x005b0920` |
| Allocator / repair | `FUN_0053ada0`, `FUN_00537d30` |
| Loader parent | `FUN_00541950` + `A_aa_007dbce0_Mission_tContinentObject.md` |
| Vtbl slot | `read_memory` @ `0x009d01ac` → first entry `0x005431d0` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `int __thiscall(this, uint key, void *value, char softIfExists)` | **Confirmed** | `ret 0xc` = 3 stack args + this |
| Null value → `0x80004003` | **Confirmed** | bytes + body |
| Hard dup → `0x80004005` + log | **Confirmed** | body + string |
| Soft path hit → return **1** | **Confirmed** | body |
| Lock +0x1d log-only | **Confirmed** | falls through |
| Hash layout +8 mask / +c count / +10 buckets / +14/+18 list / +1d lock | **High** | twin family |
| Node layout 0x1c + this vtbl **009d01ac** | **High** | body write |
| Distinct from mission twins by **vtbl only** | **High** | CF match; vtbl differs |
| Continent object table consumer | **High** | `00541950` only caller |
| Freelist ECX into `0053ada0` | **Open** | elided |
| Product soft-flag English | **Probable** | Ghidra allowDuplicate / soft-skip |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Clean | Live |
|---|---|---|---|
| Null → E_POINTER | Y | Y | Y |
| Lock log + continue | Y | Y | Y |
| Soft hit → 1 | Y | Y | Y |
| Hard hit → E_FAIL | Y | Y | Y |
| Alloc + vtbl 009d01ac | Y | Y | Y |
| Bucket head-insert + repair | Y | Y | Y |
| List append + count++ + 0 | Y | Y | Y |

### Recovered CF

```c
// int __thiscall CNDHash_Insert(CNDHash *this, uint key, void *value, char softIfExists)
// THIS VA: node vtbl = PTR_FUN_009d01ac  (continent-object loader family)

if (value == NULL) return 0x80004003;
if (this->lockedForTraversal /*+0x1d*/) {
  log("HashError:insert, already locked for traversal");
  log("VOG_DEBUG_STOP");
}
if (softIfExists && CNDHash_LookupByKey(this, key)) return 1;
if (CNDHash_LookupByKey(this, key)) {
  log("Duplicate hash insert %u, failing out", key);
  return 0x80004005;
}
Node *n = NodeAlloc();              // FUN_0053ada0
n->vtbl = PTR_FUN_009d01ac;
n->touched = 0; n->value = value; n->key = key;
// bucket head-insert; FUN_00537d30; list append; count++
return 0;
```

---

## 5. Layout (this body + twin family)

### CNDHash (partial)

| Off | Field |
|---|---|
| +0x08 | mask |
| +0x0c | count |
| +0x10 | buckets* |
| +0x14 | listHead |
| +0x18 | listTail |
| +0x1d | lockedForTraversal (char) |

### Node (vtbl `009d01ac`)

| Off | Field |
|---|---|
| +0x00 | vtbl |
| +0x04 | touch flag |
| +0x08 | value* |
| +0x0c | bucket next |
| +0x10 | key |
| +0x14 | list next |
| +0x18 | list prev |

---

## 6. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00541950` | post-`007dbce0` row install |
| Callee | `CNDHash_LookupByKey` | dup check |
| Callee | `FUN_0053ada0` | node alloc |
| Callee | `FUN_00537d30` | bucket integrity |
| Callee | `FUN_007a4480` | debug log |

---

## 7. Gaps / open

1. Freelist this-link for `FUN_0053ada0`.
2. Full method table at `009d01ac` (dtor/value ownership).
3. Hash object offset on parent (`00541950` this for insert elided in decompile).
4. Runtime insert capture; bit-exact deferred.
5. **Do not merge** call sites with mission twins `0053c360`/`0053c560`/… — vtbl differs.

**Verdict:** **accept-with-gaps** — insert CF Confirmed; twin-vtbl + continent consumer High.
