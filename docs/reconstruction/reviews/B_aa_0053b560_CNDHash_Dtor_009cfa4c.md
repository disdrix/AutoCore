# Review B (skeptical / adversarial): `aa_0053b560` CNDHash_Dtor_009cfa4c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b560` |
| **VA** | `0x0053b560` |
| **Canonical name** | `CNDHash_Dtor_009cfa4c` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b560_CNDHash_Dtor_009cfa4c.md` |
| **Live tools** | Independent decompile + reclaim twin + scalar dtor |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Dtor frees payload values | Reclaim `0053b610` only freelist-push; **no** `operator_delete` on `node+8` | **Falsified** owning-dtor claim |
| 2 | Same as Recreate | Recreate uses owning reclaim (`005381x0`) + realloc; dtor frees table + freelist slabs, no Alloc | **Falsified** merge |
| 3 | Lock aborts dtor | Continues | **Falsified** |
| 4 | Identical to `0053b670`/`780`/`810` | Different object vtbl + FreeBuckets/reclaim stamps | **Falsified** |
| 5 | `0059c8a0` runs on hash base `this` with mask@+8 | Would treat mask as pointer — unsafe; freelist-vector role required | **Attack raises** ECX residual — **Probable** subobject |

---

## 2. Surviving contract

```
Dtor_009cfa4c:
  vtbl re-stamp; lock log non-fatal
  FreeBuckets non-owning reclaim + free table
  freelist slab vector teardown
```

### Traps

1. **Payload ownership is external** for this family’s dtor reclaim — callers must free values before dtor or accept leak.
2. **Do not** confuse with Destroy-by-key (`00538e00`) which does owning delete.
3. Scalar dtor `0053b540` may free the `0x34` object after this.

**Verdict:** **accept-with-gaps.** Accept A.
