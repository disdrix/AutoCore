# Review B (skeptical / adversarial): `aa_004d9ec0` Continent_SendLogicUiUnlessDuplicate

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d9ec0` |
| **VA** | `0x004d9ec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d9ec0_Continent_SendLogicUiUnlessDuplicate.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always sends LogicUI | **Falsified** — can early-return on duplicate when flag set |
| 2 | Character is `this` | **Falsified** — continent host; Unlock sets ECX from `+0xa8` object |
| 3 | Dedupe list is hash | **Falsified** — linear array stride `0x138` |
| 4 | `RET 4` one arg | **Falsified** — **`RET 8`** |
| 5 | Mutates continent unlock state itself | **Falsified** — send/skip only; unlock work is caller |
| 6 | Bit-exact runtime | **Fail** |

---

## 2. Decisive Unlock framing (`0x00531d37`)

```
; after FUN_004d1d00 continent work
PUSH 1                 ; enable dedupe
LEA  EAX, [ESP+msg]
PUSH EAX
MOV  ECX, continent
CALL 0x004d9ec0
```

---

## 3. Port risks

| Risk | Impact |
|---|---|
| Always send without dedupe | Duplicate LogicUI spam |
| Wrong stride | Miss matches / OOB |
| Wrong ECX base for SendLogicUiPacket | Packet to wrong queue |

**Verdict:** Accept gated send. Keep flag + stride sealed.
