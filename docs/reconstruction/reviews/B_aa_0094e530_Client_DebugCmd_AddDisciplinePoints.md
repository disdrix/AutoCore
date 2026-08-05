# Review B (skeptical / adversarial): `aa_0094e530` Client_DebugCmd_AddDisciplinePoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094e530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-T) |
| **Counterpart** | `reviews/A_aa_0094e530_Client_DebugCmd_AddDisciplinePoints.md` |
| **Scratch** | `tmp/a_0094e530.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `AddMissionCounter` (`00530610`) | **Falsified** — calls **Set** `005305b0` (absolute), not Add; no third seed formal |
| 2 | Always sets max/`+0x10` | **Falsified** — `FUN_0052ade0` only when third token `atoi==1` |
| 3 | Free function / cdecl | **Falsified** — ECX saved as client; char load `[ESI+0xe98]`; `ret 8` |
| 4 | Command is addresearchpoints / addcredits | **Falsified** — register imm binds `"adddisciplinepoints"` + help plate |
| 5 | strtok starts a fresh string (first arg non-null) | **Falsified** — `PUSH 0; PUSH delim; CALL strtok` = continue |
| 6 | Returns void | **Falsified** — EAX 1 fail / 0 success paths |
| 7 | Character optional | **Falsified** — null `+0xe98` returns 1 before Set |
| 8 | Product name is retail demangle | **Overstated** — slash-string structural name only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Absolute set role | **High** | Wrong progress math if port uses Add |
| Optional max flag | **High** | Dual-field desync if always/never sync |
| thiscall client + ret 8 | **High** | ABI break |
| Command identity | **High** | Wrong handler wiring |
| Stack[0x4] meaning | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
SUB ESP,8; ESI=delim (Stack[0x8] after frame)
strtok(NULL,delim) → key; null → EAX=1; RET 8
strtok → amount; null → EAX=1; RET 8
flag = false; strtok optional → flag=(atoi==1)
char=*(client+0xe98); null → EAX=1; RET 8
SetMissionCounter(char,key,amount)
if flag: FUN_0052ade0(char,key,amount)
ui refresh client+0x1074 / +0x3d8 / +0x448
EAX=0; RET 8
```

Live 2026-07-29 CF ≡ annotated. Registration: `MOV ECX,0x0094e530` with `"adddisciplinepoints"`.

---

## 4. Surviving contract for AutoCore

```
// Debug slash only (not production S2C path):
Client_DebugCmd_AddDisciplinePoints(client, unused, delim);
// strtok continue: key, amount required; optional "1" sets max (+0x10) too.
// Require local character client+0xe98.
// Use sealed CVOGCharacter_SetMissionCounter (absolute +0x14), not Add.
// Optional FUN_0052ade0 for max sync + dirty 0x40.
// UI: if client+0x1074 active (vtbl+0x3d8) → vtbl+0x448.
// ret 8; return 1 fail / 0 ok.
```

---

## 5. Verdict

Adversarial pass **confirms** A: set-vs-add, flag-gated max, ABI, command plate sealed; product key catalog + unused stack formal open → **accept-with-gaps**.
