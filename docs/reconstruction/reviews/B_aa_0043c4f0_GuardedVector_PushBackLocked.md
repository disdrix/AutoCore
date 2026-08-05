# Review B (skeptical / adversarial): `aa_0043c4f0` GuardedVector_PushBackLocked

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c4f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-D) |
| **Counterpart** | `reviews/A_aa_0043c4f0_GuardedVector_PushBackLocked.md` |
| **Scratch** | `tmp/a_0043c4f0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `thiscall` ECX=this | **Falsified** — container is **EDI**; ECX unused as this |
| 2 | Unlocked push_back body | **Falsified** — this is CS wrapper; body is `0043c830` |
| 3 | Host-level lock (`DAT+0x6c`) | **Falsified** — uses container `+0x14` / `+0x2c` (contrast second arm of `007b75b0`) |
| 4 | Multi-caller shared helper | **Overstated risk** — **1** xref only (`007b77ba`); still general ABI |
| 5 | Product name retail | **Overstated** — inferred `GuardedVector_PushBackLocked` |
| 6 | Decompiler signature complete | **Falsified** — omits EDI formal |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI container + RET 0x4 | **High** | Wrong object / stack tear |
| CS +0x14 / flag +0x2c | **High** | Deadlock / data race |
| Nested = PushBack | **High** | Wrong polarity |
| Sole-caller manager+0x58 | **High** | Wrong list |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | CS races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if [EDI+0x2c]: EnterCS(EDI+0x14)
  FUN_0043c830(param) with EAX=EDI
  if [EDI+0x2c]: LeaveCS

bytes (94 B full seal):
  SEH prolog → CMP [EDI+0x2C] → LEA ESI,[EDI+0x14]
  MOV EAX,[ESP+18]; PUSH EAX; MOV EAX,EDI; CALL 0043c830
  CMP [ESI+0x18] (=EDI+0x2C); Leave; ADD ESP,10; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Call target `E8 01 03 00 00` from `0x0043c52a` → `0x0043c830` confirmed.

Contrast: `007b75b0` second resolver arm uses **host** lock (`DAT_00d1f058+0x84` / `+0x6c`) + raw `FUN_0043c830` — different pattern; does **not** call this unit.

---

## 4. Surviving contract for AutoCore

```
// GuardedVector locked push_back:
//   EDI = container; stack = const dword* value; RET 0x4
//   if lockEnable(+0x2c): EnterCS(+0x14)
//   PushBack(EAX=container, value)   // W29-B contract
//   if lockEnable: LeaveCS
// Do not substitute host-level CS (DAT+0x6c) for this wrapper.
// Do not invent thiscall ECX=this.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets; product name residual only → **accept**.
