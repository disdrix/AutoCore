# Review B (skeptical / adversarial): `aa_00862d90` Client_SendInventoryGrab_Hardpoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862d90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00862d90_Client_SendInventoryGrab_Hardpoint.md` |
| **Verdict** | **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Same wire as FromGrid except type=2 | **Probable but unsealed** — send helper differs (SectorPacket vs connection vcall) |
| 2 | Type 2 always “hardpoint” retail enum | **Label Probable** — only constant 2 in body |
| 3 | Post-send vcalls complete unequip-from-slot client state | **Unproven** — unknown vfunc semantics |
| 4 | Return 0/1 is send success | **Holds better than FromGrid** — fails return 0; still no server ack |
| 5 | Clean exact finished | **Scaffold** |

---

## 2. Surviving contract

```
FUN_007fbbb0();
if local host + item resolve:
  if blocked: toast path; return 0
  build 0x2034 size 0x20 with type=2 + item TFID
  Client_SendSectorPacket(...); post item vcalls; return 1
else return 0
```

---

## 3. Open questions

Field-for-field parity with FromGrid; who clears busy; live hardpoint unequip/grab capture.

**Verdict:** Use for hardpoint grab emit shape only.
