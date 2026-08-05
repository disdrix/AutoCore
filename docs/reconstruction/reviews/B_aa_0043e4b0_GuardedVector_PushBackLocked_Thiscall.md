# Review B (skeptical / adversarial): `aa_0043e4b0` GuardedVector_PushBackLocked_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e4b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-G) |
| **Counterpart** | `reviews/A_aa_0043e4b0_GuardedVector_PushBackLocked_Thiscall.md` |
| **Scratch** | `tmp/a_0043e4b0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Entry `thiscall` ECX=this | **Falsified** — container is **EDI**; ECX set only for nested call |
| 2 | Same unit as `0043c4f0` PushBackLocked | **Falsified** — identical CS shell, **different nest** (`0043d670` thiscall vs `0043c830` EAX) |
| 3 | Unlocked push body | **Falsified** — this is CS wrapper only |
| 4 | Multi-caller shared helper | **Overstated risk** — **1** xref only (`009716cd`); still general ABI |
| 5 | Product name retail | **Overstated** — inferred `GuardedVector_PushBackLocked_Thiscall` |
| 6 | Decompiler signature complete | **Falsified** — omits EDI formal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI container + RET 0x4 | **High** | Wrong object / stack tear |
| CS +0x14 / flag +0x2c | **High** | Deadlock / data race |
| Nested = PushBack_Thiscall | **High** | Wrong polarity / ABI at nest |
| Distinct from EAX Locked twin | **High** | Wrong list contract |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | CS races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if [EDI+0x2c]: EnterCS(EDI+0x14)
  FUN_0043d670(param) with ECX=EDI
  if [EDI+0x2c]: LeaveCS

bytes (94 B full seal):
  SEH prolog → CMP [EDI+0x2C] → LEA ESI,[EDI+0x14]
  MOV EAX,[ESP+18]; PUSH EAX; MOV ECX,EDI; CALL 0043d670
  CMP [ESI+0x18] (=EDI+0x2C); Leave; ADD ESP,10; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Call target `E8 81 F1 FF FF` from `0x0043e4ea` → `0x0043d670` confirmed.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector locked push_back (thiscall nest):
//   EDI = container; stack = const dword* value; RET 0x4
//   if lockEnable(+0x2c): EnterCS(+0x14)
//   PushBack_Thiscall(ECX=container, value)   // W31-I contract
//   if lockEnable: LeaveCS
// Do NOT substitute EAX PushBackLocked (0043c4f0) or unlocked EAX PushBack (0043c830).
// Do not invent entry thiscall ECX=this.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/nest target; product name residual only → **accept**.
