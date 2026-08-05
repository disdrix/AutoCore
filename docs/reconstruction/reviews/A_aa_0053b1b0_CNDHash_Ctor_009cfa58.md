# Review A (reconstruction fidelity): `aa_0053b1b0` CNDHash_Ctor_009cfa58

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053b1b0` |
| **VA** | `0x0053b1b0` |
| **Canonical name** | `CNDHash_Ctor` (hash object vtbl `PTR_FUN_009cfa58`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity |
| **Counterpart** | `reviews/B_aa_0053b1b0_CNDHash_Ctor_009cfa58.md` |
| **System** | container / CNDHash family / objective tables |
| **Live tools** | batch decompile, twin ctor, AllocBuckets twin, xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**CNDHash constructor twin** — same control flow as `FUN_0053b0b0`, differences only:

| Item | This VA | Twin `0053b0b0` |
|---|---|---|
| Object vtbl | `PTR_FUN_009cfa58` | `PTR_FUN_009cfa4c` |
| Bucket alloc | `FUN_00537970` | `FUN_005378d0` |
| Sentinel vtbl (in alloc) | `009ceffc` | `009ceff4` |

Field layout, bits arg, size→mask conversion, freelist/list zeroing: **identical**.

Residual `a_0053fff0`: objective insert hash uses this ctor (bits=8). Xref: `0060b955`.

---

## 2. Confidence

| Claim | Level |
|---|---|
| CF ≡ twin ctor (vtbl/alloc only delta) | **Confirmed** |
| Layout map shared | **Confirmed** |
| Alloc via `FUN_00537970` | **Confirmed** |
| Product objective-hash binding | **High** residual |

---

## 3. Recovered CF

```c
// CNDHash* __thiscall Ctor(this, byte log2Bits)  // twin of 0053b0b0
this->vtbl = PTR_FUN_009cfa58;
// same zeroing + size=1<<bits as 0053b0b0
AllocBuckets_00537970(this);  // sentinels vtbl 009ceffc; mask=size-1
return this;
```

---

## 4. Gaps

Same as twin: `+0x24`, exact product class name, object-vtbl methods.

**Verdict:** **accept-with-gaps** — twin ctor sealed High; do not merge VAs.
