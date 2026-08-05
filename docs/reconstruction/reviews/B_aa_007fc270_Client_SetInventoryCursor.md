# Review B (skeptical / adversarial): `aa_007fc270` Client_SetInventoryCursor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc270` |
| **VA** | `0x007fc270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fc270_Client_SetInventoryCursor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Same as clear `007fc150` | **Falsified** | Sets `+0x494`, show/position; clear zeros |
| 2 | Equips vehicle hardpoint | **Falsified** | UI only |
| 3 | Always runs | **Falsified** | EDI==0 early out |
| 4 | Payload is always item* | **Open** | Only know dword → `+0x494` |
| 5 | No position logic | **Falsified** | size vfunc + client screen offsets |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Set vs clear symmetry | **High** | Cursor stuck empty/full |
| `+0x494` store | **High** | Wrong held icon |
| EDI / payload English | **Tentative** | Port type errors |
| Screen position math | **Medium** | Cosmetic only |

---

## 3. Cross-check spine

```
SetInventoryCursor(client@ESI, payload, gate@EDI):
  if !EDI: return
  prep; attach cursor root; cursor[+0x494]=payload
  show + center using client screen size fields
  unhide optional UI child (+4(0) vs clear's +4(1))
```

---

## 4. Surviving contract for AutoCore

```
Client.SetInventoryCursor(payload):
  client-only; pair equip put-in-hand / grab
  inverse of ClearInventoryCursor
```

---

## 5. Open questions

1. Payload semantic (item instance vs CBID vs flags).
2. EDI provenance at each call site.

**Verdict:** **accept-with-gaps**
