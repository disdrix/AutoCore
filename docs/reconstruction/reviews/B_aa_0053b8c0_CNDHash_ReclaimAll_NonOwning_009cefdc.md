# Review B (skeptical / adversarial): `aa_0053b8c0` CNDHash_ReclaimAll_NonOwning_009cefdc

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b8c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b8c0_CNDHash_ReclaimAll_NonOwning_009cefdc.md` |
| **Verdict** | **accept** |
| **Tools** | Ghidra `decompile_function` + `read_memory` only |

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Owning reclaim (deletes values) | **Falsified** — no `operator_delete` / no call sites in body |
| 2 | This **is** FreeBuckets | **Falsified** — FreeBuckets `0x0053b880` zeros count + frees table **around** this call |
| 3 | Zeros hash count | **Falsified** — no write to `+0x0c` |
| 4 | Loop is `i < mask` exclusive | **Falsified** — `cmp esi,[ecx+8]; jbe` → **inclusive** |
| 5 | Stack args / stdcall | **Falsified** — bare `c3` after pops; ECX-based |
| 6 | Multiple direct callers | **Falsified as of xrefs** — only FreeBuckets `0x0053b88a` |
| 7 | Same as RemoveAll `0053b330` | **Overstated** — RemoveAll also zeros value `+0x08` and ordered-list fields; this unit does neither |
| 8 | Stamp persists on freelist nodes | **Overstated** — stamp then immediately overwritten by freelist next at `+0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Non-owning freelist reclaim CF | **High** | Double-free if ported as owning |
| Stamp family `009cefdc` | **High** | Cross-family freelist corruption |
| Inclusive mask loop | **High** | Last bucket leak |
| Sole FreeBuckets caller | **High** | Missed teardown path |
| Product English name | **Tentative** | Docs only |
| Runtime / bit-exact | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
ECX = hash; ESI = i = 0
loop:
  bucket = *(*(this+0x10) + i*4); n = *(bucket+4)
  while n:
    next = *(n+0xc)
    *n = 0x009cefdc
    *n = *(this+0x20); *(this+0x20) = n
    n = next
  *(bucket+4) = 0
  i++
  while i <= *(this+8)   ; jbe
ret
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Bytes confirm stamp imm, freelist `+0x20`, inclusive `jbe`, bare ret, **zero** value-delete path.

---

## 4. Surviving contract for AutoCore

```
// thiscall/fastcall hash; bare ret
for i = 0..mask inclusive:
  reclaim chain: stamp 009cefdc, nodes → freelist(+0x20), clear head
  // values NOT deleted; count/table ownership remain with FreeBuckets/dtor
```

**Verdict:** **accept**
