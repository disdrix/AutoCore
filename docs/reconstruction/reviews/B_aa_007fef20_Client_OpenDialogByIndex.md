# Review B (skeptical / adversarial): `aa_007fef20` Client_OpenDialogByIndex

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fef20` |
| **VA** | `0x007fef20` |
| **Canonical name** | `Client_OpenDialogByIndex` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fef20_Client_OpenDialogByIndex.md` |
| **System** | client UI / dialog table |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always opens (never closes) | Visible + `param_3==0` → `007fca10` close path | **Falsified** open-only |
| 2 | Index unlimited | Reject `dialogIndex > 0x3a` | **Falsified** |
| 3 | Same as announce helper `007fe720` | Different host fields; no `+0xcb4` ring | **Falsified** merge |
| 4 | Drive always blocks | Index `0x29` and `param_4!=0` bypass | **Falsified** absolute block |
| 5 | Null dialog silent | Logs `"Attempting to open null dialog %i."` | **Falsified** silent |
| 6 | Mission-only | Input poll opens inventory/map/menus | **Falsified** domain lock |
| 7 | `param_3` is "force open" only | When visible and `param_3==0`, acts as toggle-close | **High** toggle semantics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Table +0x1030 / max 0x3a | **Confirmed** | OOB open |
| Close via 007fca10 on toggle | **Confirmed** | Stuck modals |
| Show vtbl chain | **Confirmed** | Dialog not shown |
| Index lexicon complete | **Open** | Wrong menu wire |
| Drive gate details | **High** | Open while driving incorrectly |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw large body.
String evidence seals null path.
Close dual A_aa_007fca10 agrees this is the open-side host of the same table.
Mission duals call with indices 0x13, force flags — consistent.
```

### Merge trap

Do **not** merge:

- `FUN_007fca10` (close/flush of **current** EAX dialog)
- `FUN_007fe720` (announce nested under `+0xf38+0xcb4`)
- HideMissionDialogIfOpen (`0x0092ce50`) — different path

### Recursive trap

Self-call `FUN_007fef20(0x1d,1,0)` during exclusive conflict is **real** — ports must allow re-entry.

---

## 4. Surviving contract for AutoCore

```
Client_OpenDialogByIndex(client, index, forceCloseIfOpen, allowWhileDriving):
  if index > 0x3A: return
  dlg = client.dialogTable[index]   // +0x1030
  if !dlg: log null; return
  // toggle/close if already visible and !forceCloseIfOpen
  // gate drive / exclusive / specials
  // attach + show vtbls + host restore

AutoCore must NOT:
  - treat every call as pure show
  - open without null check
  - ignore 0x29 drive exception
  - share implementation with announce 007fe720
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Table open primary | **Agree Confirmed** |
| Toggle via 007fca10 | **Agree Confirmed** |
| Drive/special gates | **Agree High** |
| Index map Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Publish index→dialog class map from construction / RTTI.
2. Formal names for param_3/param_4 from source if found.
3. Runtime open/close traces for inventory/map.

**Verdict:** **accept-with-gaps** — agree with A; block open-only and announce merge mistakes.
