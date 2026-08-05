# Review B (skeptical / adversarial): `aa_0043cb00` GuardedVector_InsertN

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cb00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-A) |
| **Counterpart** | `reviews/A_aa_0043cb00_GuardedVector_InsertN.md` |
| **Scratch** | `tmp/a_0043cb00.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `__thiscall` with ECX=this | **Falsified** — ECX is **N** (count); container is stack[+4] |
| 2 | Flat vector insert / memmove | **Falsified** — ring page map + push_front/back + RingFill |
| 3 | All four arms exercised by Resize | **Falsified** — sole caller always `insert_at=begin+size` → suffix=0 back arm only |
| 4 | No exception paths | **Falsified** — bytes contain pop_front/pop_back + `_CxxThrowException` SEH cleanup |
| 5 | Product name retail string | **Overstated** — inferred `GuardedVector_InsertN` |
| 6 | Nested ce10/c830 bit-exact | **Survives** — out of scope residual (W29-B) |
| 7 | Body length / RET 0x10 | **Survives** — 769 B, `C2 10 00` @ end |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX=N + RET 0x10 | **High** | Wrong count / stack smash |
| Shorter-side tree | **High** | Wrong shift direction |
| End-insert Resize path | **High** | Grow fills wrong window |
| Nested construct free | **Medium** | Port invents plain memcpy insert |
| Front arms golden | **Low** | Untested by sole caller |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | SEH / capacity races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  prefix = insert_at - begin; suffix = size - prefix
  4-arm tree with ce10 front / c830 back / d390|d300 / cef0 fill

bytes:
  MOV EDI, ECX          ; N
  MOV ESI, [ebp+8]      ; container
  MOV EBX, [ebp+10]     ; insert_at
  … RET 0x10
  E8 → 0043ce10 / 0043c830 / 0043cef0 / 0043d390 / 0043d300
  SEH cleanup E8 → 0040d980 / 0043df70 / 006a3d60
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 for success CF tree.  
Caller `GuardedVector_Resize` grow: stack `(cont, cont, begin+size, &fill0)`, ECX=delta.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector insert-N (unlocked body; parent may hold CS):
//   ECX = N
//   stack: container, seed, insert_at, fill*
//   RET 0x10
//   End-insert (Resize grow): suffix=0 → push_back N *fill then RingFillRange
// Do not invent linear vector::insert; must use page map + push_front/back helpers.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/sole-caller path; nested construct free + unexercised front arms residual → **accept-with-gaps**.
