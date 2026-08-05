# Review B (skeptical / adversarial): `aa_007fe720` Client_UiAnnounce_TrySelectOrQueue_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fe720` |
| **VA** | `0x007fe720` |
| **Canonical name** | `Client_UiAnnounce_TrySelectOrQueue_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fe720_Client_UiAnnounce_TrySelectOrQueue_Inferred.md` |
| **System** | client UI / announce window |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is inventory item add itself | Body only UI host/announce; callers are residual UI | **Falsified** inv-add merge |
| 2 | Always selects category | Ring drain + early returns can no-op | **Falsified** always-select |
| 3 | `param_4` false never selects | `0090bd80` may still call `0090b9c0` | **Attack fails** — queue path can select |
| 4 | Works without `+0xf38` host | Immediate return if null | **Falsified** |
| 5 | Nested object is free-floating | Nested is `*(host+0xcb4)` only | **Attack fails** |
| 6 | Same as `FUN_007fef20` open-dialog | Different table (`+0x1030`); this is announce nested | **Falsified** merge |
| 7 | `param_2` is TFID/COID | Downstream `0090b9c0` bounds 0..4 with label dds | **High** slot/category |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Host/nested gates + final +0x94 | **Confirmed** | Broken announce UI |
| param_4 branch | **Confirmed** | Wrong select path |
| Ring early-out semantics | **High** | Spurious reselect |
| English class names | **Open** | Docs only |
| Ring index math | **Tentative** | Port ring wrong |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw scaffold CF.
Callees confirmed: 0040fd60, 0090b9c0, 0090bd80.
0090b9c0 RTTI: CDlgObjective / CDlgGauges / CDlgQuickBar + label dds strings
  → announce / tip window family (not inventory grid).
```

### Merge trap

Do **not** fold into:

- `Client_OpenDialogByIndex` (`0x007fef20`)
- inventory packet handlers
- `FUN_007fca10` close/flush

### Queue trap

`param_4 != 1` is **not** "skip UI"; `0090bd80` may still select when ring empty / flag path.

---

## 4. Surviving contract for AutoCore

```
Client_UiAnnounce_TrySelectOrQueue(client, slotId, doRingCheck, forceSelect):
  require client+0xf38 visible and host+0xcb4 visible
  if doRingCheck and nested ready:
    if nested.current == slotId: return
    drain ring; if slotId matched: return
  if forceSelect: SelectCategory(slotId) else QueueOrSelect(slotId)
  nested.vtbl[+0x94]()

AutoCore must NOT:
  - treat as inventory net handler
  - open dialog table +0x1030 here
  - skip nested +0x94 refresh after select
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Host/nested visibility gates | **Agree Confirmed** |
| param_4 → 0090b9c0 / 0090bd80 | **Agree Confirmed** |
| Ring drain optional early out | **Agree High** |
| English names Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Dual `0090b9c0` / `0090bd80` / ring layout.
2. Caller `00945540` / `00946c00` context (which inventory event).
3. Runtime capture of slot ids.

**Verdict:** **accept-with-gaps** — agree with A; block inv-add/open-dialog merge.
