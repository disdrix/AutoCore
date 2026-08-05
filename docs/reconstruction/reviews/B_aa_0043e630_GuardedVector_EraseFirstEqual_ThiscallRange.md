# Review B (skeptical / adversarial): `aa_0043e630` GuardedVector_EraseFirstEqual_ThiscallRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-A) |
| **Counterpart** | `reviews/A_aa_0043e630_GuardedVector_EraseFirstEqual_ThiscallRange.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX thiscall outer (like Resize_Thiscall) | **Falsified** — entry uses ESI with no `MOV ESI,ECX`; same outer as W28-C |
| 2 | Same function as `0043c550` EraseFirstEqual | **Falsified** — distinct VA; nested call is `0043df90` not `0043c8c0` |
| 3 | Contains-only (no mutate) like `0043e5b0` | **Falsified** — hit path always calls EraseRange |
| 4 | Void / no stack args | **Falsified** — `RET 4` + stack key* compare |
| 5 | "string/log chain" role from NDResource residual | **Overstated** — body is pure erase-first-equal; caller context is remove-from-`+0x1c` |
| 6 | Scaffold VOG / Named_CalleeOf plate | **Rejected** — no product evidence |
| 7 | Product class English | **Overstated** — structural GuardedVector name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI container + stack key* + RET 4 + AL | **High** | Stack imbalance / wrong this |
| Optional CS +0x2c/+0x14 | **High** | Race / deadlock if inverted |
| Nested EraseRange_Thiscall one-slot | **High** | Wrong erase ABI (EAX vs ECX) |
| Twin distinction vs W28-C | **High** | Port calls wrong erase family |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Cache races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  unaff_ESI + param_1 key*; CS; scan; FUN_0043df90; return found

bytes:
  SUB ESP,0C; CMP [ESI+2C],0; LEA EDI,[ESI+14]
  … page-map first-equal …
  MOV ECX,ESI; CALL 0043df90; MOV BL,1
  MOV AL,BL; ADD ESP,0C; RET 4

caller 00971030:
  ADD ESI,1C; PUSH key; CALL 0043e630   ; pending ring

caller 0075ddb2:
  LEA ESI,[EBP+1C]; PUSH key; CALL 0043e630
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF; **bytes win** on ESI + RET 4 + nested thiscall.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector first-equal erase (thiscall-range twin):
//   ESI = container
//   stack const int* key; RET 4; AL found
//   optional CS when +0x2c
//   on hit: EraseRange_Thiscall ECX=container [idx, idx+1)
// Do NOT call as ECX-this outer without ESI setup.
// Do NOT use W28-C 0043c550 / EAX EraseRange (0043c8c0) interchangeably
//   without matching nested ABI (both outer ESI but nested differs).
// Do NOT treat as ContainsFirstEqual (0043e5b0) — this mutates.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF and rejects ECX-outer / contains-only / scaffold-name claims. Product residual remains → **accept-with-gaps**.
