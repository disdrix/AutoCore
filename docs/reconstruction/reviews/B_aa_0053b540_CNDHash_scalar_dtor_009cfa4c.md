# Review B (skeptical / adversarial): `aa_0053b540` CNDHash_scalar_dtor_009cfa4c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b540` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b540_CNDHash_scalar_dtor_009cfa4c.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `batch_decompile` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Always `operator_delete`s the object | **Falsified** — only when `flags & 1` |
| 2 | Is the FreeBuckets / reclaim body | **Falsified** — only calls `0053b560` then optional delete |
| 3 | Vector deleting dtor (`flags & 2` array) | **Falsified** — only tests bit 0; no count/loop |
| 4 | Bare `ret` / no stack cleanup | **Falsified** — `ret 4` |
| 5 | Identical to node scalar `00537550` | **Falsified** — object hash dtor chain, not node value free |
| 6 | Owning payload free in this wrapper | **Falsified** — body dtor reclaim is non-owning for this family |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| MSVC scalar-deleting pattern | **High** | Wrong ABI in port |
| Body = `0053b560` only | **High** | Miss lock/FreeBuckets/slab |
| `flags&1` heap free | **High** | Double-free or leak object |
| Vtbl[0] placement | **High** | Wrong virtual dispatch |

---

## 3. Surviving contract

```
void* CNDHash_scalar_dtor_009cfa4c(CNDHash* this, uint8_t flags) {
  CNDHash_Dtor_009cfa4c(this);   // 0053b560
  if (flags & 1) operator_delete(this);
  return this;
}
```

**Verdict:** **accept**
