# Review B (skeptical / adversarial): `UiSelectPanel_RefreshWidget_At520_Inferred` / `FUN_008b2470` @ `0x008b2470`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008b2470` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008b2470_UiSelectPanel_RefreshWidget_At520_Inferred.md` |
| **Verdict** | **accept-with-gaps** — reject merge with `00893580`, select-core identity, and absolute decompiler arity |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same function as `00893580` | **Falsified** — distinct VA; offset **`+0x520`** not `+0x54c` |
| 2 | Parent panel is `client+0x10b4` | **Falsified** — parent uses this for **`+0x10a4`** |
| 3 | Core target selection | **Falsified** — UI refresh only |
| 4 | Widget at `+0x54c` | **Falsified** for this VA |
| 5 | 0.5f zero-arm exclusive (absolute) | **Challenged** — push before branch (same as twin) |
| 6 | Product name sealed | **Open** |
| 7 | Stack-only ABI | **Overstated** — EDI/EBX register contract |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x520` | **Confirmed** | Wrong chrome |
| Distinct from twin | **Confirmed** | Panel cross-wire |
| Select-parent only | **High** | Wrong call graph |
| vfunc / 0.5f | **Confirmed** | UI glitch |
| English | **Open** | Docs |

---

## 3. Surviving contract for AutoCore

```
// EDI = panel (client+0x10a4), EBX = mode
void RefreshWidget_At520():
  w = *(panel + 0x520)
  if !w: return
  ConfigureWidgetShared(w, EBX)  // FUN_00837d50
  vtbl+0xFC(… flag from EBX, 0.5f present on stack …)

// Keep separate from RefreshWidget_At54c (client+0x10b4)
```

---

## 4. Falsification notes

### 4.1 Offset is the product difference

CF clone is intentional MSVC-style copy; ports must keep **two** slots.

### 4.2 Not input poll

Named scaffold alias under PollBoundActions is **call-chain** naming, not body role.

---

## 5. Open questions

1. Product widget identity at `+0x520` vs `+0x54c`.
2. Shared helper dual.
3. Runtime EBX.

**Verdict:** **accept-with-gaps**. Sealed `+0x520` twin; reject VA merge and select-core overclaim.
