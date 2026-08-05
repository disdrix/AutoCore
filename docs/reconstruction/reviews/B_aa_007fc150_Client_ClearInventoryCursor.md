# Review B (skeptical / adversarial): `aa_007fc150` Client_ClearInventoryCursor

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc150` |
| **VA** | `0x007fc150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fc150_Client_ClearInventoryCursor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Hardpoint unequip | **Falsified** | UI cursor only |
| 2 | Runs with null cursor | **Falsified** | Dual null gate |
| 3 | Sets cursor item id | **Falsified** | Forces `+0x494 = 0`; set is sibling `007fc270` |
| 4 | stdcall with client arg0 | **Falsified** (image) | ESI-relative; no stack client load at entry |
| 5 | Always calls all pane helpers | **Falsified** | Each pane null-checked |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear CF + ESI client | **High** | Stuck “item on cursor” |
| Sibling set @ `007fc270` | **High** | Asymmetric cursor state |
| Pane side effects | **Medium** | Stale sheet highlights |

---

## 3. Cross-check spine

```
ClearInventoryCursor(client@ESI):
  if !client[+0xf40] || !client[+0x9b8]: return
  close optional UI; probe panes; hide cursor root
  cursor[+0x494] = 0; cursor.vfunc_3b0(0)
  maybe clear related +0xe98 helper
```

---

## 4. Surviving contract for AutoCore

```
Client.ClearInventoryCursor():
  client-only UI; pair equip/grab/drop recv
  does not mutate vehicle hardpoints
```

---

## 5. Open questions

1. Widget identities at `+0x1040/+0x1034/+0x105c/+0x1060`.
2. Relation of `+0x494` to held item TFID vs flags.

**Verdict:** **accept-with-gaps**
