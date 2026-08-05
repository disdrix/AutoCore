# Review B (skeptical / adversarial): `aa_0085e820` Client_UI_InventoryCellToPixel

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085e820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085e820_Client_UI_InventoryCellToPixel.md` |
| **System** | `inventory-transfer` |
| **Live re-decompile** | Ghidra 2026-07-29 ≡ raw |
| **Verdict** | **accept-with-gaps** on formula/CF; reject overclaims of bit-exact layout complete |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is a general screen transform | **Falsified** — only window origin + cell×pitch; inventory UI only |
| 2 | Pitch constants are positive | **Falsified** — static floats negative; subtraction yields origin+|p|×cell |
| 3 | cellX uses full 32-bit | **Falsified** — `param_1 & 0xff` |
| 4 | Writes into window fields | **Falsified** — writes through EAX out pair only |
| 5 | Needs CanPlace / network | **Falsified** — pure local math leaf |
| 6 | Clean is modernized API | **Fail attack** — scaffold ≡ raw CF |
| 7 | Runtime scales sealed as constants | **Survives as loads**; values open (static image zero) |
| 8 | Same as PlaceFromCell | **Partial** — same pitch family; Place uses `+0x50c/+0x510` multiply-add; this uses origin−negPitch |

---

## 2. Surviving contract

```
// EAX = int* outXY
// window = param_2; cellX = param_1; cellY = param_3
pitchX = (int)( (float)DAT_00d1e818 * (float)_DAT_00d1e50c * _DAT_00aaa6ac )  // _DAT negative
pitchY = (int)( (float)DAT_00d1e81c * (float)_DAT_00d1e510 * _DAT_00aaa6a8 )
outXY[0] = *(window+0x504) - pitchX * (cellX & 0xff)
outXY[1] = *(window+0x508) - pitchY * (uint)cellY
```

**Callers sealed:** only DropHitTest ghost path xrefs `0x0085f533`, `0x0085f58c`.

---

## 3. What still fails seal

| Topic | Why open |
|---|---|
| Portable C signature | Decompiler `__fastcall` + `in_EAX` out; call sites not fully formalized |
| Live pitch magnitudes | Depend on runtime globals |
| Product English name | Inferred from role + parent dual |

**Verdict:** Formula cannot be attacked away. **accept-with-gaps.**
