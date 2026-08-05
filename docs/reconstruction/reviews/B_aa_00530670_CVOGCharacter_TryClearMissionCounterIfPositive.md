# Review B (skeptical / adversarial): `aa_00530670` CVOGCharacter_TryClearMissionCounterIfPositive

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-S) |
| **Counterpart** | `reviews/A_aa_00530670_CVOGCharacter_TryClearMissionCounterIfPositive.md` |
| **Scratch** | `tmp/a_00530670.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is SetMissionCounter (`005305b0`) | **Falsified** — gates on +0x14>0; returns bool; **ret 4** not **ret 8**; calls Set |
| 2 | This is AddMissionCounter (`00530610`) | **Falsified** — no `+=`; ret 4 not 0xC; no third formal |
| 3 | Always clears even if zero/missing | **Falsified** — miss or `+0x14<=0` → return 0 without Set |
| 4 | Free function / stdcall two args | **Falsified** — thiscall ECX=character; one stack formal |
| 5 | Only touches +0x14 | **Falsified** — also writes **+0x10** before Set |
| 6 | Dirty uses bit 0x10 like FailMission | **Falsified** — machine ORs **0x40** |
| 7 | Decompiler map this is complete | **Falsified as ABI** — machine `LEA EDI,[ESI+0x584]` before both finds |
| 8 | Product name is retail | **Overstated** — structural + packet string context only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Try-clear when positive | **High** | Wrong spend / stuck counters |
| thiscall + ret 4 | **High** | ABI break |
| +0x10 then Set(0) on +0x14 | **High** | Dual-field desync if port omits +0x10 |
| Dirty 0x40 | **High** | Missed UI/sync flag |
| Key domain English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
PUSH ECX/EBX/EBP; key→EBP; this→ESI
LEA EDI,[ESI+0x584]; CALL find
CMP node,[ESI+0x588]; JZ fail
TEST [node+0x14]; JLE fail
re-find; if hit: [node+0x10]=0; OR [ESI+0x634],0x40
PUSH 0; PUSH key; MOV ECX,ESI; CALL SetMissionCounter
OR [ESI+0x634],0x40; MOV AL,1; RET 4
fail: XOR AL,AL; RET 4
```

Live 2026-07-29 ≡ raw 2026-07-23 CF. Sole caller success branch opposite failure toast.

---

## 4. Surviving contract for AutoCore

```
// Try-clear if counter +0x14 > 0:
if (CVOGCharacter_TryClearMissionCounterIfPositive(character, key)) { ... }
// Preserve: map this=char+0x584; head=char+0x588;
// hit+positive → zero +0x10, Set(key,0), dirty |=0x40; ret 4 bool.
// Do not call Set on miss/non-positive. Do not use Add's ret 0xC.
```

---

## 5. Verdict

Adversarial pass **confirms** A: try-clear role, ABI, dual-field write, dirty bit sealed; product key English open → **accept-with-gaps**.
