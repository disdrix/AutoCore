# Review B (skeptical / adversarial): `aa_004073a0` StdVector_InsertN_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004073a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004073a0_StdVector_InsertN_Dword_Inferred.md` |
| **Verdict** | **accept-with-gaps** on product mangling; **accept** on insert-n dword role |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Mission / fail-notify specific | **Falsified** — 35+ callers across character create, combat, UI, gather, freelist |
| 2 | Element size is always 16 (TFID) | **Falsified** — all math is `>>2` / `*4` dword stride |
| 3 | Always reallocates | **Falsified** — in-place paths when `cap >= size+count` |
| 4 | Growth is 2× | **Falsified** — `cap + (cap>>1)` = 1.5×, then exact `size+count` if still short |
| 5 | This is `push_back` only | **Falsified** — mid-iterator insert; count can be >1; push uses wrapper `FUN_0040dbf0` with count=1 |
| 6 | Product name recovered from string | **Holds as false** — no VA string; `_Inferred` required |
| 7 | `operator_delete` is non-returning (decomp warning) | **Overstated risk** — decompiler SEH noise; triad update after delete is live on success path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-n dword CF | **Confirmed** | Wrong container growth in port |
| Triad offsets | **Confirmed** | Corrupt vector |
| 1.5× growth | **High** | Capacity thrash / OOM path |
| Exact MSVC symbol | Tentative | Cosmetic |
| Relocate helper product names | Partial | Mild (behavior sealed as copy/fill) |

---

## 3. Surviving contract

```
InsertN(vec, pos, count, &value):
  if count==0: return
  size = (end-begin)/4; cap = (capEnd-begin)/4
  if size+count > max: abort helper
  if cap < size+count:
    newCap = max(cap + cap/2, size+count)  // 1.5× then fit
    newBuf = new dword[newCap]
    copy [begin,pos) → newBuf
    fill count copies of *value
    copy [pos,end) after fill
    delete old; update begin/end/capEnd
  else:
    // in-place shift + fill (two sub-paths by room after pos)
```

---

## 4. Residual uncertainty

| # | Item | Blocks utility seal? |
|---|---|---|
| R1 | Template element / allocator type | No (dword bag sufficient) |
| R2 | Demangled name | No (`_Inferred`) |
| R3 | Whether any caller passes non-trivial T with ctor | Mild — body treats plain dword copies |

---

## 5. Concrete checks

1. Re-decompile `0x004073a0` — ≡ raw. **Pass**
2. `FUN_0040dbf0` insert-1 wrapper calls this. **Pass**
3. Callers multi-system. **Pass**
4. Growth formula from body. **Pass**
5. Cross-link FailMissionNotify dual grow chain. **Pass**

---

## 6. Verdict

**accept-with-gaps** — insert-n dword vector growth sealed; product English open under `_Inferred`.
