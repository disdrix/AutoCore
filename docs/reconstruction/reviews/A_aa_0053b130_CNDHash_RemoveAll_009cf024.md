# Review A (reconstruction fidelity): `aa_0053b130` CNDHash_RemoveAll_009cf024

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b130` |
| **VA** | `0x0053b130` |
| **Canonical name** | `CNDHash_RemoveAll` (vtbl stamp `PTR_LAB_009cf024`; non-owning values) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b130_CNDHash_RemoveAll_009cf024.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile, string xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**RemoveAll** — clear every bucket chain without freeing payload objects:

1. If lock `+0x1d` → log `"HashError:RemoveAll, already locked for traversal"` + `VOG_DEBUG_STOP`; continue.
2. If bucket table `+0x10` non-null: for `u = 0 .. mask(+0x08)` inclusive:
   - sentinel = `table[u]`; walk chain from `sentinel+4` via node `+0x0c` (`[3]`).
   - For each node: stamp vtbl `PTR_LAB_009cf024`, clear value `[2]=0`, freelist-push onto `hash+0x20`.
   - Clear sentinel head link `sentinel+4 = 0`.
3. Zero list head `+0x14`, tail `+0x18`, count `+0xc`; return **0**.

**Does not** `operator_delete` values — callers must not expect payload free (or must free before RemoveAll).

String-class family with other RemoveAll twins (`0053b230` etc.) differing only by vtbl constant. Direct Ghidra callers sparse (likely vtbl/indirect); role sealed by string + body.

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B | **Confirmed** |
| Loop `u <= mask` inclusive | **Confirmed** |
| Non-owning clear of values | **Confirmed** |
| Freelist reclaim all nodes | **Confirmed** |
| Product callers | **Open** (no direct xref list) |

---

## 3. Recovered CF

```c
// int __fastcall/__thiscall CNDHash_RemoveAll(hash*)
if (lock) log RemoveAll-locked;
if (table) for (u=0; u<=mask; u++) {
  for (n = sentinel[u].head; n; n = n->bucketNext) {
    n->vtbl = PTR_LAB_009cf024; n->value = 0; freelist_push(n);
  }
  sentinel[u].head = 0;
}
head=tail=null; count=0; return 0;
```
