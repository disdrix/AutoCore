# Review B (skeptical / adversarial): `aa_0057a190` CVOGReaction_ShowDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057a190` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0057a190_CVOGReaction_ShowDialog.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Fully displays dialog UI | **Overstated** |
| 2 | Runs with null src | **Falsified** |
| 3 | Writes arbitrary memory | **Falsified** |
| 4 | Ignores map variables | **Falsified** |
| 5 | Server dialog builder | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Field copy CF | High | Wrong dialog text |
| Variable resolve | High | Empty placeholders |
| UI open responsibility | Probable | Missing dialog |

---

## 3. Cross-check against raw

```
if !src: return
copy src[+0x160..+0x16c] -> dst[+0x30..+0x3c]
for each slot in [dst+0xc, dst+0x10):
  if *slot == 0: CVOGMap_LookupVariable(...)
```

Clean preserves this control-flow spine from the authoritative decompile.

---

## 4. Surviving contract for AutoCore

```
ShowDialog(dialogSink, sourceObj)
  hydrate dialog fields and resolve empty variable slots
  caller may still need to present UI
```

---

## 5. Open questions

1. Dispatch reaction case number for ShowDialog.
2. Relation to RecvNpcMissionDialog widgets.
3. Live variable substitution capture.

**Verdict:** accept-with-gaps. Treat unresolved FUN_* / vtable slots as open.
