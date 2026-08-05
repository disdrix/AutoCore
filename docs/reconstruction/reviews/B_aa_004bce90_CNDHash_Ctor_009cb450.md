# Review B (skeptical / adversarial): `aa_004bce90` CNDHash_Ctor_009cb450

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bce90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bce90_CNDHash_Ctor_009cb450.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Same ctor as hashA/hashB (`FUN_004bcf90`) | vtbl + Alloc immediates differ | **Falsified** — must not merge |
| 2 | Fixed log2=5 is inside this body | Body takes stack log2; COList site pushes 5 | **Confirmed nuance** — production constant is **caller-owned** |
| 3 | `param_2` is bucket count | `1 << param_2` | **Falsified** — log2 exponent |
| 4 | Bare `ret` | `C2 04 00` | **Falsified** — ret 4 |
| 5 | Optional Alloc | unconditional call `FUN_004bc7a0` | **Falsified** |
| 6 | Can reuse medal Alloc `FUN_0051ba40` | Different stamp/sentinels (`009cb348` vs `009ce090`) | **Falsified** — stamp-local Alloc only |
| 7 | Multiple direct callers | single xref from COList_Constructor | **Confirmed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Distinct stamp 009cb450 | **High** | Wrong COList tableC virtuals |
| log2 polarity | **High** | wrong N/mask |
| ret 4 / this return | **High** | ABI mismatch |
| Production always log2=5 | **High** (caller) | wrong tableC capacity if port changes site |
| Do not call FUN_004bc840 | **High** | wrong bucket-head stamp |

---

## 3. Cross-check against raw / bytes

```
raw:   *this=009cb450; +0x08=1<<log2; FUN_004bc7a0(); return this
bytes: C7 06 50 B4 9C 00 … E8→004bc7a0 … C2 04 00
diff:  only vtbl imm + call rel vs 004bcf90
host:  COList always new(0x34)+this(5) → +0x18
```

---

## 4. Surviving contract for AutoCore

```csharp
// CNDHash stamp 009cb450 — COList tableC only
object CNDHash_Ctor_009cb450(CNDHash self, byte log2)
{
    self.vtbl = Vtbl_009cb450;
    // same field zeroing as CNDHash_Ctor_009cb45c
    self.countOrMask = 1u << (log2 & 0x1f);
    self.log2 = log2;
    self.lock1d = 0;
    // +0x24 NOT written
    AllocBucketTable_004bc7a0(self);
    return self;
}
// COList production: CNDHash_Ctor_009cb450(new(0x34), 5)
// ret 4
```

**Port traps to reject:**

- Using `CNDHash_Ctor_009cb45c` / `FUN_004bc840` for tableC.
- Treating fixed 5 as hardcoded inside this body (it is a call-site constant).
- Passing bucket count instead of log2.
- Skipping Alloc or inventing +0x24 init.

---

## 5. Residual gaps (do not block seal)

1. Runtime / image diff.
2. Product English / full vtbl method names.
3. OWN of AllocBucketTable `FUN_004bc7a0`.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break the distinct-stamp log2-ctor contract or the COList fixed-arg-5 production wiring. Residual is non-OWN Alloc detail + verification depth only.
