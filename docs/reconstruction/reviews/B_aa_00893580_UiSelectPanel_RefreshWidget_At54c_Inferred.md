# Review B (skeptical / adversarial): `UiSelectPanel_RefreshWidget_At54c_Inferred` / `FUN_00893580` @ `0x00893580`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00893580` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00893580_UiSelectPanel_RefreshWidget_At54c_Inferred.md` |
| **Verdict** | **accept-with-gaps** — reject “select API”, “only zero arm uses 0.5f”, and conflation with `+0x520` twin |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is `Object_SetSelectedTarget` / core select | **Falsified** — UI child refresh only; select is parent |
| 2 | Widget lives at `+0x520` | **Falsified** — this VA uses **`+0x54c`**; twin is `008b2470` |
| 3 | Always calls vfunc even if widget null | **Falsified** — early `test esi` |
| 4 | 0.5f only on disabled arm (decompiler absolute) | **Challenged** — `push 0x3f000000` **before** branch; both arms have it on stack |
| 5 | Sends C2S / mutates world target | **Falsified** — local UI vfuncs + helper only |
| 6 | Product name sealed | **Open** |
| 7 | Clean cdecl `(void)` fully describes ABI | **Overstated** — **EDI/EBX** register contract from parent |
| 8 | Same VA as input poll body | **Falsified** — Named plate is callee-of-poll chain; body is select UI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x54c` slot | **Confirmed** | Wrong widget refreshed |
| Twin offset discipline (`54c` vs `520`) | **Confirmed** | Cross-wire panels |
| 0.5f immediate | **Confirmed** | Wrong alpha/scale in port |
| vtbl `+0xfc` | **Confirmed** | Wrong UI method |
| Register ABI EDI/EBX | **High** | Ports that only take stack args break |
| vfunc English | **Open** | Docs |
| `00837d50` internals | **Not owned** | Residual |

---

## 3. Surviving contract for AutoCore

```
// Parent-visible panel refresh (select path)
// EDI = panel (client+0x10b4), EBX = mode flag
void RefreshWidget_At54c():
  w = *(panel + 0x54C)
  if !w: return
  ConfigureWidgetShared(w, EBX)   // FUN_00837d50
  // then vtbl+0xFC with enable-like flag and 0.5f stack word(s)
  // nonzero EBX → flag 1; zero → flag 0

// MUST NOT:
//  - treat as world select
//  - use +0x520 (sibling panel)
//  - drop null check
```

---

## 4. Falsification notes

### 4.1 Decompiler arity trap

Trust **bytes** for the unconditional `push 0x3f000000`. A port that only passes 0.5f on the zero arm may still “work” if the nonzero arm ignores the extra stack word — but documenting “0.5f zero-only” as absolute is overstated.

### 4.2 Sibling confusion

`008b2470` is the **`+0x520`** clone for `client+0x10a4`. Shared CF ≠ shared offset.

---

## 5. Open questions

1. Widget class + `+0xfc` product method (set enabled/alpha?).
2. Dual `00837d50`.
3. Runtime capture of EBX at call sites.

**Verdict:** **accept-with-gaps**. Sealed `+0x54c` refresh twin; reject select-identity and offset mixups.
