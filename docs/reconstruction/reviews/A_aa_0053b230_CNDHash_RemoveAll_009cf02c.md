# Review A (reconstruction fidelity): `aa_0053b230` CNDHash_RemoveAll_009cf02c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b230` |
| **VA** | `0x0053b230` |
| **Canonical name** | `CNDHash_RemoveAll` (node vtbl stamp `PTR_FUN_009cf02c`; non-owning) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b230_CNDHash_RemoveAll_009cf02c.md` |
| **System** | container / CNDHash family |
| **Live tools** | batch + force decompile; twin `0053b130` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**RemoveAll** — clear every bucket chain without freeing payload objects (matches sealed `0x0053b130`):

1. Lock `+0x1d` → log `"HashError:RemoveAll, already locked for traversal"` + `VOG_DEBUG_STOP`; continue.
2. If bucket table `+0x10` non-null: for `u = 0 .. mask(+0x08)` **inclusive**:
   - Walk chain from `sentinel+4` via node `+0x0c` (`[3]`).
   - Each node: stamp vtbl **`PTR_FUN_009cf02c`**, clear value `[2]=0`, freelist-push `hash+0x20`.
   - Clear sentinel head `sentinel+4 = 0`.
3. Zero list head/tail `+0x14/+0x18`, count `+0xc`; return **0**.

**Does not** `operator_delete` values. Direct xrefs empty (vtbl/indirect; same as twin).

Node-vtbl family pairs with remove twin `FUN_00538bd0` (`009cf02c`).

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF A≡B ≡ force ≡ twin body shape | **Confirmed** |
| Inclusive `u <= mask` | **Confirmed** |
| Non-owning value clear | **Confirmed** |
| Freelist reclaim all nodes | **Confirmed** |
| Product callers | **Open** (no direct xref) |

---

## 3. Recovered CF

```c
// int __fastcall CNDHash_RemoveAll(hash*)
if (lock) log RemoveAll-locked;
if (table) for (u=0; u<=mask; u++) {
  for (n = sentinel[u].head; n; n = n->bucketNext) {
    n->vtbl = PTR_FUN_009cf02c; n->value = 0; freelist_push(n);
  }
  sentinel[u].head = 0;
}
head=tail=null; count=0; return 0;
```

**Verdict:** **accept-with-gaps** — RemoveAll twin sealed High.
