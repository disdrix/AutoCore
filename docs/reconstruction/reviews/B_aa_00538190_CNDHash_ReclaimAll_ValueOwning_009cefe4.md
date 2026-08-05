# Review B (skeptical / adversarial): `aa_00538190` CNDHash_ReclaimAll_ValueOwning_009cefe4

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538190` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-K) |
| **Counterpart** | `reviews/A_aa_00538190_CNDHash_ReclaimAll_ValueOwning_009cefe4.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Non-owning reclaim (values external) | **Falsified** — `operator_delete` on `node+8` when non-null |
| 2 | This **is** FreeBuckets | **Falsified** — FreeBuckets `0x005390d0` zeros count + frees table **around** this call |
| 3 | Same stamp as twin `00538200` | **Falsified** — stamp imm is `e4 ef 9c 00` = `009cefe4`, not `009cefec` |
| 4 | `operator_delete` never returns (Ghidra) | **Falsified** — `add esp,4` / freelist push follow the call |
| 5 | Loop is `i < mask` exclusive | **Falsified** — `cmp ebp,[ebx+8]; jbe` → **inclusive** (`i <= mask`) |
| 6 | Zeros hash count | **Falsified** — no write to `+0x0c` |
| 7 | Stack args / stdcall | **Falsified** — bare `c3` after pops |
| 8 | Multiple direct callers | **Falsified as of xrefs** — only FreeBuckets `FUN_005390d0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Owning value delete CF | **High** | Mission-state / hash value leak |
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
// node stamp family = 009cefe4
```

---

## 4. Open questions

1. Product symbol.
2. Value pointee type at `+0x08` for this family.
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
