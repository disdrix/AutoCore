# Review B (skeptical / adversarial): `aa_0040d980` GuardedVector_PopFront

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-B) |
| **Counterpart** | `reviews/A_aa_0040d980_GuardedVector_PopFront.md` |
| **Scratch** | `tmp/a_0040d980.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — all offsets off **EAX** |
| 2 | Returns front value / pointer | **Falsified** — void; no load from pages |
| 3 | Frees page or runs dtor | **Falsified** — leaf; only `+0xc`/`+0x10` writes |
| 4 | Wrap uses element capacity not page×4 | **Falsified** — `ADD EDI,EDI` twice on page cap → ×4 |
| 5 | CS-guarded | **Falsified** — no Enter/Leave |
| 6 | Product name retail | **Overstated** — inferred `GuardedVector_PopFront` |
| 7 | Same as EraseRange single-element | **Falsified** — no memmove/shift; pure header advance |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX container + plain RET | **High** | Wrong object |
| begin wrap at cap×4 | **High** | Ring desync |
| size-- / empty begin=0 | **High** | Ghost elements |
| No element free | **High** | Leak if caller wrong |
| Product English | **Inferred** | Naming only |
| Parent dtor order | **Open** | Caller residual |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if size!=0:
    begin++; if cap*4 <= begin: begin=0
    size--; if size==0: begin=0

bytes (50 B):
  MOV ECX,[EAX+10]; TEST/JZ
  ADD [EAX+0C],1
  load begin/cap; cap*4 via double ADD EDI,EDI
  CMP/JA; optional begin=0
  DEC size; if zero begin=0
  RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full hex sealed.

Polarity vs W29-B PushFront: push decreases begin / may alloc; pop increases begin / never alloc — sealed pair shape.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector pop_front (unlocked header-only):
//   EAX = container (+0x08 page cap, +0x0c begin, +0x10 size)
//   if size==0: no-op
//   else: begin = (begin+1) mod (cap*4) conceptually;
//         bytes: begin++; if begin >= cap*4: begin=0
//         size--; if size==0: begin=0
// Do not invent returning front value or free of page here.
// Callers that own non-POD elements must destroy separately.
```

---

## 5. Verdict

Adversarial pass **confirms** A on full leaf CF/ABI; naming is structural only and does not block CF seal → **accept**.
