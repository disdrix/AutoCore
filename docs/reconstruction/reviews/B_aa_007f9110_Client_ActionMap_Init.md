# Review B (skeptical / adversarial): `Client_ActionMap_Init` @ `0x007f9110`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007f9110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_007f9110_Client_ActionMap_Init.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes DIK defaults inline | Falsified — delegates InitDefaultKeybinds |
| 2 | Single contiguous zero memset | Falsified — four region loops |
| 3 | Server input map | Falsified — client ActionMap |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Init order names then DIK | High | Empty labels / binds |
| Zero regions | High | Stale binds |
| +0x5 flag | Medium | Re-init bugs |

---

## 3. Cross-check against raw

```
*this=vtbl; zero regions; InitActionDisplayNames();
InitDefaultKeybinds(); *(+5)=0.
```

---

## 4. Surviving contract for AutoCore

```
ActionMap_Init:
  vtbl + zero slot mass
  display names then default DIK (helpers)
  pairs OnKeyDown / PollBoundActions / DriveControlTick
```

---

## 5. Open questions

1. Publish ActionMap layout with 0x34 slot stride.

**Verdict:** **accept**
