# Review B (skeptical / adversarial): `Client_UnpackSpecialMessage` @ `0x00637c20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637c20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00637c20_Client_UnpackSpecialMessage.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Gameplay handler for missions | Falsified — unpack layer |
| 2 | Only damage messages | Falsified — multi-opcode |
| 3 | No 0x206c path | Falsified — explicit case |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Correct opcode cascade | High | Mis-unpack packets |
| 0x206c group reaction unpack | High | Broken group reactions |
| TNL buffer helpers | High | Parse faults |

---

## 3. Cross-check against raw

```
UnpackSpecialMessage(buf, opcode, ctx):
  SEH;
  case 0x206c: FUN_006374f0;
  case 0x2005: ...
  damage unpack / generic TNL unpack paths.
```

---

## 4. Surviving contract for AutoCore

```
UnpackSpecialMessage:
  TNL/client special msg unpack by opcode;
  not business logic — feed PacketDispatch handlers.
```

---

## 5. Open questions

1. Complete case list from raw.
2. Map to named handlers (GroupReactionCall, Damage, ...).

**Verdict:** **accept-with-gaps**
