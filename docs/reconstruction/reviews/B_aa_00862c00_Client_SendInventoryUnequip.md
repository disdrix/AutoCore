# Review B (skeptical / adversarial): `aa_00862c00` Client_SendInventoryUnequip

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862c00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00862c00_Client_SendInventoryUnequip.md` |
| **Verdict** | **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Clean is finished exact port | **Overstated** — still decompiler scaffold with stub preamble |
| 2 | Bidirectional 0x203E with S2C notify is same struct | **Unproven** — size 0x30 plate shared; field roles may differ C2S vs S2C |
| 3 | Vehicle TFID “not filled” is intentional forever | **Narrative** — may be incomplete decompile of fill |
| 4 | Free-slot always cargo | **Weak** — dest type not sealed in unit pack |
| 5 | Signature sealed | **Fail** — `in_EAX` residual |

---

## 2. Surviving contract

```
if local host+vehicle:
  resolve item inventory root
  if blocked: FUN_00931db0 path; return 0
  find free slot → dest X/Y
  if no space: toast; return 0
  send InventoryUnequip 0x203E size 0x30 (item TFID + dest)
```

---

## 3. Open questions

Exact send API; full 0x30 layout vs RecvNotify; town fallback `FUN_004ce5c0`; runtime.

**Verdict:** Plate-level C2S unequip map only; do not seal wire parity with S2C.
