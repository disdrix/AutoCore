# Review B (skeptical / adversarial): `UiTargetPanel_MatchSlotAndRefresh_Inferred` / `FUN_008e9690` @ `0x008e9690`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e9690` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008e9690_UiTargetPanel_MatchSlotAndRefresh_Inferred.md` |
| **Verdict** | **accept-with-gaps** — reject “find only / no paint”, “min-distance”, and “EDI is panel” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Only searches; no side effects | **Falsified** — always calls `FUN_008e9290` paint/update |
| 2 | Stack arg is selected object | **Falsified** — stack = **panel**; **EDI** = object |
| 3 | Scans unlimited / world list | **Falsified** — fixed **4** slots at `+0x5d8` |
| 4 | Distance / radius selection | **Falsified** — TFID equality only |
| 5 | Match requires both self and +0xac | **Falsified** — **OR** of self TFID **or** secondary |
| 6 | Skips helper when no match | **Falsified** — helper always; miss sets EBX=−1 |
| 7 | Same body as `00893580` / `008b2470` | **Falsified** — different CF (slot match vs single widget) |
| 8 | Product panel name sealed | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 4-slot + TFID compare | **Confirmed** | Wrong party/target UI |
| Always `008e9290` | **Confirmed** | Stale chrome if omitted |
| EDI vs stack roles | **Confirmed** | ABI break |
| Secondary `+0xac` | **Confirmed** | Miss vehicle-in-seat style links |
| EDI-null EBX | **Open** | Possible stale slot highlight |
| Slot English | **Open** | Docs |

---

## 3. Surviving contract for AutoCore

```
// panel on stack; selected object in EDI (parent)
void MatchSlotAndRefresh(Panel* panel):
  idx = -1
  if selected_obj:
    for i in 0..3:
      s = panel->slots[i]  // base +0x5D8
      if s && s->flag_500:
        if tfid_eq(obj, s) or (obj->sec_ac && tfid_eq(sec, s)):
          idx = i; break
  PaintSlots(panel, idx)  // FUN_008e9290 — always

// Ports MUST preserve:
//  - 4-cap, not dynamic size
//  - OR secondary +0xac path
//  - always paint (including miss → -1)
```

---

## 4. Falsification notes

### 4.1 Not the highlight chrome at `client+0x3048`

Parent does separate selection chrome after this. This unit is **panel slot** matching only.

### 4.2 `void` signature understates registers

Decompiler `unaff_EDI` is load-bearing. Stack-only ports will match nothing useful.

---

## 5. Open questions

1. Product UI (party bar? target bookmarks?).
2. Dual `008e9290`.
3. EDI-null EBX discipline from all parent sites.

**Verdict:** **accept-with-gaps**. Sealed 4-slot TFID match + mandatory paint; reject search-only and distance myths.
