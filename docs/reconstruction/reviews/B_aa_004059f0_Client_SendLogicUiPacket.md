# Review B (skeptical / adversarial): `Client_SendLogicUiPacket` @ `0x004059f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004059f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_004059f0_Client_SendLogicUiPacket.md` |
| **Verdict** | **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always succeeds / never grows | **Falsified — overflow branch** |
| 2 | Stride is not 0x138 | **Falsified** |
| 3 | param_2 is full UI struct | **Overstated — opaque dword** |
| — | Param names / types are production-ready | **Overstated** — decompiler widths and FUN_* remain |
| — | Runtime verified | **Falsified** — open / deferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Element stride is 0x138 | High | Wrong → protocol/UI mismatch risk |
| In-bounds construct at this+8 | High | Wrong → protocol/UI mismatch risk |
| Overflow uses FUN_004068f0 | High | Wrong → protocol/UI mismatch risk |
| param_2 is UI event payload | Medium | Wrong → protocol/UI mismatch risk |
| this is LogicUi queue | Medium | Wrong → protocol/UI mismatch risk |
| Clean is CF-preserving scaffold | High | Low for using as map; high if treating as bit-exact |
| Semantic field names beyond strings | Medium | Auth wire layout mistakes |

---

## 3. Surviving contract for AutoCore

```
Client_SendLogicUiPacket(queue, event):
  if free 0x138-stride slots: construct at write; write+=0x138
  else grow-helper(event)
```

---

## 4. Open questions

1. FUN_00409cc0 / FUN_004068f0 not fully typed
2. param_2 payload layout unknown
3. Callers not mapped in this unit

**Verdict:** **accept-with-gaps** on CF; **needs-more-evidence** on unrecovered FUN_/layouts — safe as behavioral map for AutoCore auth/network ports; do not treat FUN_* or incomplete decomp signatures as sealed wire codecs without sibling units.
