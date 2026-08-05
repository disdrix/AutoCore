# Review B (skeptical / adversarial): `aa_0080ff00` Client_RecvCompleteDynamicObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080ff00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080ff00_Client_RecvCompleteDynamicObjective.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on opcode + register contract |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Body proves opcode 0x2070 | **Falsified as body claim — no opcode immediate; dispatch/plate external** |
| 2 | Complete only if objective in active hash | **Falsified — CompleteObjective always runs even if lookup null** |
| 3 | Always sends UseObject | **Falsified — only when captured target id != -1 and world match** |
| 4 | Force flag is optional | **Falsified — hard-coded force=1** |
| 5 | Portable signature (client, packet) | **Weak — packet formal + EDI client residual** |
| 6 | Finished exact port | **Overstated — UI vcall identities + CS path opaque** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Force-complete always | High | Miss server force-complete |
| Objective id @+0x10 | High | Wrong mission slot |
| UseObject optional polarity | High | Spurious interact spam |
| Opcode binding | Tentative | Dead handler |
| EDI client framing | Tentative | Wrong UI refresh target |

---

## 3. Cross-check against raw

```
FUN_0052d8b0(0,-1);
pActive = hash(char+0x548, pkt+0x10);
scan reqs type==3 → capture [6] or -1;
CompleteObjective(id,-1,-1,1);
UI +0x107c / dialog +0x10b0 refresh;
if target!=-1: match world id → Client_SendUseObject (+ CS release path);
Client_RefreshOpenMissionUiWindows; optional +0x1034.
Clean preserves CF.
```

---

## 4. Surviving contract for AutoCore

```
On S2C CompleteDynamicObjective (dispatch-bound):
  clear mission helper; lookup active objective by id@+0x10
  always CompleteObjective(id, -1, -1, force=1)
  refresh mission UI; optional UseObject if type-3 world target matched
  bulk mission window refresh
Do not send 0x2070 on dialog deliver turn-in (client already completed locally).
Do not treat missing active-hash entry as skip-complete.
```

---

## 5. Open questions

1. Exact PacketDispatch case for VA 0x0080ff00.
2. Full requirement-type enum beyond type 3.
3. Whether CompleteObjective this is local char from EDI+0xe98.
4. Runtime force-complete capture.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on opcode + register contract
