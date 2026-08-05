# Review A (reconstruction fidelity): `aa_00538000` CNDHash_Remove_009cefec

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538000` |
| **VA** | `0x00538000` |
| **Canonical name** | `CNDHash_Remove_009cefec` (CNDHash remove twin; node vtbl `PTR_FUN_009cefec`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00538000_CNDHash_Remove_009cefec.md` |
| **System** | container / CNDHash family |
| **Live tools** | Ghidra `batch_decompile`, `force_decompile`, callee `FUN_004e2ca0`, callers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash remove(key, outValue*)** — `__thiscall` on hash object:

1. If `outValue != null` → `*outValue = 0`.
2. If `this+0x1d` lock set → log `"HashError:remove, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue**.
3. `FUN_004e2ca0(key)` — **find + bucket-unlink** (key@node+0x10, next@+0xc, touch-repair `FUN_00537d30`).
4. Miss → **`0x80004005`** (E_FAIL).
5. Hit:
   - Optional copy `node+0x08` (value) to out, then **clear value to 0**.
   - Unlink ordered list head `+0x14` / tail `+0x18` via node links `[5]/[6]` (`+0x14/+0x18`).
   - Write node vtbl `PTR_FUN_009cefec`.
   - **Dead** `operator_delete(node+0x08)` branch (value already 0 — never taken).
   - Freelist push: `*node = *(this+0x20); *(this+0x20) = node`; `count--`; return **0**.

Primary sealed callers: `FUN_00538e50` (Destroy wrapper), `FUN_005307e0` (HandleEndQuest).

Twin of sealed `0x00538b20` with different node vtbl and residual delete stub.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live A | `batch_decompile` @ `0x00538000` |
| Live B | `force_decompile` @ `0x00538000` — **identical** |
| Bucket helper | `FUN_004e2ca0` @ `0x004e2ca0` |
| Raw | `raw/aa_00538000_FUN_00538000.md` |
| Twin remove | `A_aa_00538b20_CNDHash_Remove` |

---

## 3. Layout (shared CNDHash 0x1c node family)

| Hash off | Role |
|---|---|
| `+0x08` | bucket mask |
| `+0x0c` | count |
| `+0x10` | bucket table* |
| `+0x14` / `+0x18` | ordered list head / tail |
| `+0x1d` | traversal lock |
| `+0x20` | freelist head* |

| Node off | Role |
|---|---|
| `+0x00` | vtbl (`009cefec` here) / freelist next |
| `+0x04` | touch flag |
| `+0x08` | value* |
| `+0x0c` | bucket next |
| `+0x10` | key (u32) |
| `+0x14` / `+0x18` | list next / prev |

---

## 4. Confidence

| Claim | Level |
|---|---|
| CF dual A≡B ≡ raw | **Confirmed** |
| Miss E_FAIL / hit 0 / lock warn-only | **Confirmed** |
| Bucket unlink in `004e2ca0` | **High** |
| `operator_delete` arm dead after value clear | **Confirmed** (body order) |
| Product symbol vs twin | **Probable** |

---

## 5. Recovered CF

```c
// int __thiscall CNDHash_Remove(hash*, uint key, void **outOpt)
if (outOpt) *outOpt = 0;
if (hash->lock) { log remove-locked; /* continue */ }
Node *n = BucketFindUnlink(key); // FUN_004e2ca0
if (!n) return 0x80004005;
if (outOpt) *outOpt = n->value;
n->value = 0;
// list unlink head/tail
n->vtbl = PTR_FUN_009cefec;
// if (n->value) delete — dead
n->vtbl = freelist; freelist = n; count--; return 0;
```
