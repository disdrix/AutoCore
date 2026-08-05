# Review B (skeptical / adversarial): `aa_007fc100` Client_SendQuickBarUpdateWithSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007fc100_Client_SendQuickBarUpdateWithSlot.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on CL slot packing |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Slot comes from UI page/col | **Falsified — absolute CL (vs FromUi)** |
| 2 | Identical register contract as FromUi | **Falsified — EAX/CL vs ECX/ESI** |
| 3 | Clean formals complete | **Overstated — CL slot missing as named local** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Wire opcode/size | High | Wrong wire |
| isItem polarity | High | Skill/item swap |
| CL slot placement on wire | Tentative until stack map sealed | Wrong slot index |

---

## 3. Cross-check against raw

```
if EAX payload: isItem=(*EAX!=1); value=EAX[2..3]; opcode 0x2062; send 0x10
Plate: CL=slot written into packet — verify in raw stack map.
Clean send path matches FromUi transport.
```

---

## 4. Surviving contract for AutoCore

```
On programmatic QuickBar update:
  same 0x2062 layout as FromUi with absolute slot 0..99
  do not derive slot from UI page when calling this entry
Seal CL→packet+4 before production port.
```

---

## 5. Open questions

1. Disasm confirmation of CL store into packet.
2. All call sites.

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on CL slot packing
