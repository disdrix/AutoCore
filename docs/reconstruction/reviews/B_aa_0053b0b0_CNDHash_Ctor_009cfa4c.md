# Review B (skeptical / adversarial): `aa_0053b0b0` CNDHash_Ctor_009cfa4c

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b0b0` |
| **VA** | `0x0053b0b0` |
| **Canonical name** | `CNDHash_Ctor_009cfa4c` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0053b0b0_CNDHash_Ctor_009cfa4c.md` |
| **Live tools** | Independent force decompile + callee `005378d0` + xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `+0x08` is always mask in ctor body | Ctor stores **size** `1<<bits`; mask written only after `FUN_005378d0` (`size-1`) | **Falsified** “mask at write” — two-phase |
| 2 | This is also Insert/Remove | Body only inits + AllocBuckets | **Falsified** merge |
| 3 | Twin ctor `0053b1b0` is identical | Same field map; different object vtbl `009cfa58` + different AllocBuckets twin | **Falsified** full identity |
| 4 | Bits unchecked | AllocBuckets requires `1 <= bits <= 16` else throw E_POINTER-shaped | **Attack fails** — range in callee |
| 5 | Freelist slab fields unused | Inserts use freelist@+0x20; FreelistPop uses +0x28 vector | **Attack fails** — must zero |
| 6 | force changes CF | force ≡ batch | **Attack fails** |

---

## 2. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor field map + vtbl | **Confirmed** | Wrong hash base layout |
| Size→mask via AllocBuckets | **Confirmed** | Off-by-one bucket index |
| Twin ctor separation | **High** | Cross-wire objective vs mission hash |
| Product bits default 8 | **High** residual / **Open** all sites |
| `+0x24` uninitialized | **Open** | Residual field |

---

## 3. Cross-check

```
force ≡ batch.

Callee: FUN_005378d0 (bucket table + sentinels vtbl 009ceff4, mask = size-1)

Xrefs (3):
  0060b924 / 0060b985 / 0060b9be — region mission hash construction

Twin: FUN_0053b1b0 → vtbl 009cfa58, AllocBuckets FUN_00537970
```

### Traps

1. **Do not** treat `+0x08` as mask before AllocBuckets returns.
2. **Do not** call Insert before ctor completes AllocBuckets (null table).
3. **Do not** merge with `0053b1b0` — different object vtbl / sentinel family.

---

## 4. Surviving contract

```
CNDHash_Ctor_009cfa4c(this, log2Bits):
  vtbl=009cfa4c; size=1<<log2Bits; zero lists/count/freelist
  log2Bits@+0x1c; lock=0
  AllocBuckets → table[size]; each sentinel 0xc; mask=size-1
  return this
```

**Verdict:** **accept-with-gaps.** Accept A.
