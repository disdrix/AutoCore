# Review A (reconstruction fidelity): `aa_00537f30` CNDHash_Remove_009cefe4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537f30` |
| **VA** | `0x00537f30` |
| **Canonical name** | `CNDHash_Remove_009cefe4` (remove twin; node vtbl `PTR_FUN_009cefe4`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_00537f30_CNDHash_Remove_009cefe4.md` |
| **System** | container / CNDHash family |
| **Live tools** | Ghidra `batch_decompile`, `force_decompile`, xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash remove(key, outValue*)** — `__thiscall` on hash object (state-blob node family, vtbl `009cefe4`):

1. If `outValue != null` → `*outValue = 0`.
2. If `this+0x1d` lock set → log `"HashError:remove, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue**.
3. `FUN_004e2ca0(key)` — find + **bucket-unlink** (key@+0x10, next@+0xc, touch-repair `FUN_00537d30`).
4. Miss → **`0x80004005`** (E_FAIL).
5. Hit:
   - Optional copy `node+0x08` (value) to out, then **clear value to 0**.
   - Unlink ordered list head `+0x14` / tail `+0x18` via node links `[5]/[6]`.
   - Write node vtbl `PTR_FUN_009cefe4`.
   - **Dead** `operator_delete(node+0x08)` branch (value already cleared — never taken).
   - Freelist push onto `this+0x20`; `count--`; return **0**.

Primary callers: `FUN_00538e00` (owning Destroy wrapper @ `00538e30`), `FUN_005307e0` / HandleEndQuest path @ `00530beb`.

Twin of sealed removes `0x00538b20` / `0x00538000` — same CF, different node vtbl stamp.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live A | `batch_decompile` @ `0x00537f30` |
| Live B | `force_decompile` @ `0x00537f30` — **identical** |
| Raw | `raw/aa_00537f30_FUN_00537f30.md` |
| Function record | `functions/aa_00537f30_FUN_00537f30.md` |
| Destroy owner | `A_aa_00538e00_CNDHash_Destroy_via_00537f30` |
| Twin remove | `A_aa_00538b20_CNDHash_Remove`, `A_aa_00538000_CNDHash_Remove_009cefec` |
| Xrefs | `00538e30`, `00530beb` |

---

## 3. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ raw ≡ force | **Confirmed** |
| Signature `int __thiscall(this, uint key, void **outOpt)` | **High** |
| Miss E_FAIL / hit 0 / lock warn-only | **Confirmed** |
| Bucket unlink in `004e2ca0` | **High** |
| `operator_delete` arm dead after value clear | **Confirmed** (body order) |
| Freelist @ `+0x20`, list @ `+0x14/+0x18` | **Confirmed** |
| Node vtbl stamp `009cefe4` | **Confirmed** |
| True value free is Destroy wrapper, not this unit | **High** |

---

## 4. Recovered CF

```c
// int __thiscall CNDHash_Remove(hash*, uint key, void **outOpt)
if (outOpt) *outOpt = 0;
if (hash->lock /* +0x1d */) { log remove-locked; /* continue */ }
Node *n = BucketFindUnlink(key); // FUN_004e2ca0
if (!n) return 0x80004005;
if (outOpt) *outOpt = n->value;  // +0x08
n->value = 0;
// list unlink head(+0x14)/tail(+0x18)
n->vtbl = PTR_FUN_009cefe4;
// if (n->value) operator_delete — DEAD (value already 0)
freelist_push(hash+0x20, n);     // overwrites vtbl dword as next
hash->count--;                   // +0x0c
return 0;
```

---

## 5. Gaps

1. Bit-exact bucket-sentinel load before `FUN_004e2ca0` (decompiler elision) — role High, encoding Open.
2. Product name for this vtbl family vs mission `009cf024`.
3. Runtime capture Open.

**Verdict:** **accept-with-gaps** — remove CF + freelist + dead-delete stub sealed High.
