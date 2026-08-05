# Review B (skeptical / adversarial): `NDSpecialFX_LivenessDone_Inferred` / `FUN_004b7330` @ `0x004b7330`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b7330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-H) |
| **Counterpart** | `reviews/A_aa_004b7330_NDSpecialFX_LivenessDone_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** DeactivateClear | **Falsified** — leaf probe only; HostTick calls `FUN_004b7150` after |
| 2 | thiscall with stack formals / `ret N` | **Falsified** — plain `C3`; ECX only; no stack cleanup |
| 3 | Returns void / float | **Falsified** — AL 0\|1 (`32 C0` / `B0 01`) |
| 4 | Non-zero means “still live” | **Falsified** — HostTick B-review: non-zero → DeactivateClear (**done**) |
| 5 | Walks destroy-pending `+0x90e` | **Falsified** — tests payload `+0x795` / `+0x10B` only |
| 6 | Has callees / side effects | **Falsified** — leaf; no stores |
| 7 | Product name is retail string | **Overstated** — no string xref; `_Inferred` only |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF / four return sites | **High** | Wrong HostTick deactivate gate |
| AL bool plain RET | **High** | ABI break |
| HostTick polarity (1=done) | **High** | Never-deactivate or instant-kill FX |
| Product English of flags | **Medium** | Docs only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
if host residual (+9,+A,+1e4,+214) active: AL=0; RET
for node in list(+0x204):
  if payload(+0x795)==0: AL=0; RET
AL=1
if +0x1f0 && !+6 && !+7 && !+8:
  for node in list(+0x1ec):
    if payload(+0x10b)!=0: AL=0; break
RET AL
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Body ends `32 C0 C3` then `CC` pad before `FUN_004b73c0`.

---

## 4. Surviving contract for AutoCore

```
// ECX = fx host; plain ret; AL 0|1
// HostTick:
if NDSpecialFX_LivenessDone(fx):   // FUN_004b7330 != 0
  DeactivateClear(fx)
  return 1                         // deactivated
// else continue child tick / free destroy-pending
```

Port must **not** invert polarity. Do not free children inside this leaf.

---

## 5. Verdict

Adversarial pass **confirms** A: leaf CF/ABI/HostTick polarity sealed; product name residual only → **accept**.
