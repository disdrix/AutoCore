# Review B (skeptical / adversarial): `aa_00538200` CNDHash_ReclaimAll_ValueOwning_009cefec

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00538200_CNDHash_ReclaimAll_ValueOwning_009cefec.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Non-owning reclaim (values external) | **Falsified** — `operator_delete` on `node+8` when non-null |
| 2 | This **is** FreeBuckets | **Falsified** — FreeBuckets `0x00539110` zeros count + frees table **around** this call |
| 3 | Calls scalar dtor `FUN_00537550` | **Falsified** — only stamps vtbl then freelist-push; no vcall |
| 4 | `operator_delete` never returns (Ghidra) | **Falsified** — `add esp,4` / freelist push follow the call |
| 5 | Loop is `i < mask` exclusive | **Falsified** — `cmp ebp,[ebx+8]; jbe` → **inclusive** (`i <= mask`) |
| 6 | Zeros hash count | **Falsified** — no write to `+0x0c` |
| 7 | Stack args / stdcall | **Falsified** — bare `c3` after pops |
| 8 | Multiple direct callers | **Falsified as of xrefs** — only FreeBuckets `0x0053911a` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Owning value delete CF | **High** | Pending-objective / state leak |
| Freelist stamp family | **High** | Cross-family freelist corruption |
| Inclusive mask loop | **High** | Last bucket leak |
| Decomp noreturn gap | **High** | False “unreachable” analysis |

---

## 3. Surviving contract

```
// thiscall hash; bare ret
for i = 0..mask inclusive:
  reclaim chain: delete values, nodes → freelist(+0x20), clear head
// count and table ownership remain with FreeBuckets/dtor
```

**Verdict:** **accept-with-gaps**
