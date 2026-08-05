# Review B (skeptical / adversarial): `aa_0080cc50` Client_RecvSpecialEvent

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080cc50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0080cc50_Client_RecvSpecialEvent.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on opcode seal |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Vehicle TFID works on fast path | **Often false in live — plate says 0xe98 is character; mismatch → resolve or silent return** |
| 2 | Unknown type still processes | **Falsified — type not 0/1/2 returns** |
| 3 | Respawn ignores flag@+0x40 | **Falsified — ctor takes non-zero flag** |
| 4 | Always animates | **Falsified — null +0x250 returns** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type switch | High | Wrong anim class |
| TFID gate | High | Silent no-op (live vehicle mistake) |
| Alloc sizes 0x70/0x34/0x50 | Probable | Heap corruption if wrong |
| Opcode | Tentative | Dead handler |

---

## 3. Cross-check against raw

```
copy pose from pkt; if no local char or TFID mismatch: resolve object TFID type==0x14 else return
require +0x250; switch type: Respawn/TeleportOut/TeleportIn ctors; enqueue.
Clean matches plate notes.
```

---

## 4. Surviving contract for AutoCore

```
On S2C SpecialEvent 0x20A9:
  target TFID must match local character (not vehicle) for fast path
  type 0 Respawn / 1 TeleportOut / 2 TeleportIn
  require mounted/vehicle context +0x250 for processing
AutoCore Respawn after RespawnInSector must use character coid.
```

---

## 5. Open questions

1. Exact enqueue list semantics FUN_00403150.
2. Full TFID layout beyond +0x28/+0x2c.
3. Runtime capture.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on opcode seal
