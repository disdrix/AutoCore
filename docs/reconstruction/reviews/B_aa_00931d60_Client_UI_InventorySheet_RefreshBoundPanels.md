# Review B (skeptical / adversarial): `aa_00931d60` Client_UI_InventorySheet_RefreshBoundPanels

| Field | Value |
|---|---|
| **Stable ID** | `aa_00931d60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00931d60_Client_UI_InventorySheet_RefreshBoundPanels.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Rebuilds item widgets itself | Parent conflation | **Falsified** — only two panel refreshes; rebuild is `0x00860700` |
| 2 | Always calls both helpers | Ignore probes | **Falsified** — null panel skip; `vtbl+0x3d8==0` skip |
| 3 | ECX thiscall | ABI | **Falsified** — **EDI** host |
| 4 | Mutates inventory / sends C2S | Side-effect inflation | **Falsified** — UI refresh callees only |
| 5 | Single panel at one offset | Layout skim | **Falsified** — **two** offsets `0x1078` and `0x105c` |
| 6 | Polarity: refresh when probe **false** | Flip | **Falsified** — `if (al != 0) call` |
| 7 | Product name sealed | Inflation | **Not sealed** — inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual offsets + vtbl 0x3d8 | **High** | Missed chrome update |
| Probe polarity | **High** | Spurious / skipped refresh |
| EDI ABI | **High** | Wrong this |
| Callee bodies full semantics | **Med** | Port of 800e0/8ef70 |
| Panel type names | **Low** | Doc |

---

## 3. Cross-check raw ≡ force

```text
if (window[0x1078] && window[0x1078]->vtbl[0x3d8]()) FUN_008800e0();
if (window[0x105c] && window[0x105c]->vtbl[0x3d8]()) FUN_0088ef70();
```

Callers: RebuildItemWidgets (after list teardown / before final window vtbl+0x34c) and GrabApplyToCursor.

---

## 4. Surviving contract

```
Client_UI_InventorySheet_RefreshBoundPanels(window@EDI):
  maybe refresh panel@+0x1078 via 0x008800e0
  maybe refresh panel@+0x105c via 0x0088ef70
// no item hash, no grid, no network
```

**Port tests:** preserve null gates and true-polarity probe; do not fold into Clear/Collect/Add.

**Verdict:** **accept-with-gaps** — rebuild-conflation and polarity attacks **fail**.
