# Review B (skeptical / adversarial): `aa_0043c660` GuardedVector_ClearAndSwap

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c660` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-A) |
| **Counterpart** | `reviews/A_aa_0043c660_GuardedVector_ClearAndSwap.md` |
| **Scratch** | `tmp/a_0043c660.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler void/no-args is complete ABI | **Falsified** — ESI/EDI are live register formals |
| 2 | Function is Resize itself | **Falsified** — Resize is nested clear; this unit swaps after |
| 3 | Swaps full object including CS | **Falsified** — only +0x04/+0x08/+0x0c/+0x10; CS stays on EDI |
| 4 | Always takes CS | **Falsified** — gated on `[EDI+0x2c]` |
| 5 | Clears EDI | **Falsified** — clears **ESI** then swaps (EDI ends empty only after swap) |
| 6 | Product name retail | **Overstated** — inferred structural |
| 7 | Body / epilogue | **Survives** — 137 B, `ADD ESP,0x10; RET` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI=A EDI=B | **High** | Wrong object cleared/swapped |
| CS +0x14 / flag +0x2c | **High** | Race / deadlock |
| Resize ECX=0 clear | **High** | Leaves A elements live |
| Header-only swap | **High** | Corrupts CS if over-swapped |
| Parent semantics | **Medium** | Wrong ownership story |
| Product English | **Inferred** | Naming only |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if [edi+0x2c]: EnterCS(edi+0x14)
  FUN_0043c7e0()  // unaff ESI/EDI; bytes force ECX=0, EAX=ESI
  swap +4,+8,+0xc,+0x10
  if flag: LeaveCS

bytes @ clear site:
  33 C9 8B C6 E8 44 01 00 00   ; XOR ECX,ECX; MOV EAX,ESI; CALL 0043c7e0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23.  
Nested Resize dual sealed W28-D (accept-with-gaps on its own nested insert free — not this unit's free).

---

## 4. Surviving contract for AutoCore

```
// GuardedVector clear-and-swap under optional lock on B:
//   ESI = A (cleared to size 0 first)
//   EDI = B (optional CS at +0x14, flag +0x2c)
//   then swap slots/capacity/begin/size only
// Do not swap CS fields. Do not skip Resize clear before swap.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/CS/swap set with no material residual in body free → **accept**.
