# Review B (skeptical / adversarial): `aa_004bcf90` CNDHash_Ctor_009cb45c

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bcf90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004bcf90_CNDHash_Ctor_009cb45c.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `param_2` is bucket **count** | Body does `1 << param_2` into +0x08 | **Falsified** — param is **log2** exponent |
| 2 | Same as `FUN_004bce90` / mergeable | vtbl `009cb45c` vs `009cb450`; Alloc `004bc840` vs `004bc7a0` | **Falsified** — distinct stamps |
| 3 | Bare `ret` / cdecl | Exit `C2 04 00` | **Falsified** — `ret 4` thiscall stack formal |
| 4 | Returns void | Exit `8B C6` then ret | **Falsified** — returns this in EAX |
| 5 | Writes full 0x34 object | No ESI+0x24 store in body | **Confirmed residual** — +0x24 unwritten (same as other CNDHash ctors) |
| 6 | Many callers | Xrefs only from COList_Constructor | **Confirmed** — sole consumer in this image |
| 7 | Not a CNDHash | Layout +0x08/+0x10/+0x1C/+0x1D matches sealed Lookup/ctor stamps; sibling RemoveAll logs `HashError:RemoveAll…` | **Falsified** — CNDHash family |
| 8 | Alloc is optional | Unconditional `call FUN_004bc840` before epilogue | **Falsified** — always invoked |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| log2 vs count polarity | **High** | 2^N buckets wrong size |
| vtbl stamp 009cb45c | **High** | Wrong virtuals / free path |
| ret 4 / this return | **High** | ABI mismatch |
| Must call Alloc before use | **High** | null buckets / wrong mask |
| Do not use for COList tableC | **High** | Wrong stamp on +0x18 |

---

## 3. Cross-check against raw / bytes

```
raw:   *this=009cb45c; +0x08=1<<log2; FUN_004bc840(); return this
bytes: C7 06 5C B4 9C 00 … 89 56 08 … 88 4E 1C … E8→004bc840 … C2 04 00
host:  COList operator_new(0x34) ×2 optional paths
twin:  004bce90 same body, 50 B4 9C 00 + E8→004bc7a0 only
parallel: CNDHash_Ctor_009ce1a0 (W26-P) identical template
```

---

## 4. Surviving contract for AutoCore

```csharp
// CNDHash stamp 009cb45c — COList hashA/hashB only
object CNDHash_Ctor_009cb45c(CNDHash self, byte log2)
{
    self.vtbl = Vtbl_009cb45c;
    self.field04 = 0;
    self.countOrMask = 1u << (log2 & 0x1f); // provisional N
    self.field0C = 0;
    self.buckets = null;
    self.field14 = self.field18 = 0;
    self.log2 = log2;
    self.lock1d = 0;
    self.freelist = null;
    // +0x24 NOT written
    self.field28 = self.field2C = self.field30 = 0;
    AllocBucketTable_004bc840(self); // converts N → mask N-1
    return self;
}
// ret 4
```

**Port traps to reject:**

- Passing bucket **count** instead of log2.
- Installing vtbl `009cb450` or calling `FUN_004bc7a0` (tableC family).
- Skipping Alloc handoff.
- Zeroing or inventing writes to +0x24 without evidence.
- Using bare `ret` (must be `ret 4`).

---

## 5. Residual gaps (do not block seal)

1. Runtime / image diff.
2. Product English / full vtbl method names.
3. OWN of AllocBucketTable `FUN_004bc840` (mask/`0 < log2 < 0x11` validation is callee-owned).

---

## Verdict

**accept-with-gaps** — adversarial review cannot break the log2-ctor ABI/CF/stamp contract. Residual is non-OWN Alloc detail + verification depth only.
