# Review B (skeptical / adversarial): `aa_004138d0` CNDHash_Recreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004138d0` |
| **VA** | `0x004138d0` |
| **Canonical name** | `CNDHash_Recreate` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004138d0_CNDHash_Recreate.md` |
| **Live tools** | Independent `force_decompile` + entry `read_memory` + callee bodies |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `__thiscall` ECX=hash | **Falsified** — EAX; `push esi; mov esi,eax` |
| 2 | Lock aborts recreate | **Falsified** — log only; destroy/alloc still run |
| 3 | `hash+8` remains bucket **count** after return | **Falsified** — Alloc decrements to **mask** |
| 4 | BL is raw bucket count | **Falsified** — log2; `1 << (BL&0x1f)` |
| 5 | Frees widgets | **Falsified** — only hash structure; values already detached by Clear |
| 6 | Multi-caller fan-in | **Falsified for sealed set** — sole caller ClearItemWidgets |

---

## 2. Decisive machine dataflow

```text
// entry
ESI = EAX (hash)
if [ESI+0x1d]: log Recreate-locked; log VOG_DEBUG_STOP
call 00413e20          // EAX = ESI
[ESI+0x1c] = BL
[ESI+8]    = 1 << BL
[ESI+0x18] = 0; [ESI+0x14] = 0
call 00413d80          // ESI = hash (unaff_ESI)
ret
```

A ≡ B on live force. Nested:

- **Destroy** zeros `+0xc` count, freelist-walks buckets, frees slab + ptr array.
- **Alloc** requires `0 < *(+0x1c) < 0x11`, builds `n` buckets of 0xc sentinels, then `*(+8)--`.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Recreate CF | **High** | Sheet clear leaves corrupt map |
| Mask post-condition | **High** | Insert bucket wrong |
| log2 domain 1..16 | **High** (Alloc gate) | throw E_POINTER if out of range |
| Product class name | **Probable** | CNDHash family only |

---

## 4. Surviving contract

```text
// After ClearItemWidgets detach loop:
//   EAX = window+0x570 hash; BL = prior log2 (or desired)
CNDHash_Recreate();
// empty hash; mask at +8; freelist intact at +0x20
```

**Verdict:** **accept-with-gaps.** Accept A.
