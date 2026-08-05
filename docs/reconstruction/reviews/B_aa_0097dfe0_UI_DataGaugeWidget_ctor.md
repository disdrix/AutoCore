# Review B (skeptical / adversarial): `aa_0097dfe0` UI_DataGaugeWidget_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0097dfe0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0097dfe0_UI_DataGaugeWidget_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Implements cooldown fraction / remaining-time math | Body only base ctor + 5 field stores | **Falsified** |
| 2 | Name must be Cooldown not Data | Ghidra plate = Cooldown; user dual name = Data; both map same VA | **Alias OK** — do not fork addresses |
| 3 | Single-purpose quickbar-only | Many non-QuickBar UI callers | **Multi-use widget** |
| 4 | `DAT_00d1e504` is a function pointer | 4-byte global copied into `+0x4a8`; movss in prologue | **Data payload** |
| 5 | Vtable installed before base ctor | Order is **base first** (`FUN_00863f10`), then override `*this` | **Order sealed** |
| 6 | Object is only `+0x4b8` large | Factories / plate use **`0x4bc`** | **0x4bc** |
| 7 | No other dual needed for behavior | Update paths live in QuickBar cooldown updaters | **Ctor ≠ update** |
| 8 | Live ≠ raw | Match | **Match** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thin UI gauge ctor | **High** | Over-engineered port |
| Field offsets +0x4a8..+0x4b8 | **High** | Wrong defaults |
| Multi-caller UI reuse | **High** | Assume only quickbar |
| Constant product meanings (15, 4) | **Low** | Wrong visual defaults |
| `DAT_00d1e504` semantics | **Low** | Wrong default fill |
| Runtime | **Open** | — |

---

## 3. Cross-check

| Check | Result |
|---|---|
| Live ≡ `raw/aa_0097dfe0_*.md` | **Match** |
| Xrefs include QuickBar builders | **Yes** |
| Plate XML `i_d_qb_2d_btn_quickbar_cooldown.xml` | **Consistent** with cooldown role |
| Related duals (UpdateSkillSlotCooldownGauge etc.) | Separate VAs — not this unit |

---

## 4. Surviving contract for AutoCore

```
// UI widget construction only — no cooldown math.

GaugeWidget* UI_DataGaugeWidget_ctor(GaugeWidget* w /* size 0x4bc */)
{
  BaseUIWidget_ctor_00863f10(w);
  w->vt = &Vtable_Gauge_00a62454;
  w->field_4a8 = g_DAT_00d1e504;  // default (float-sized global)
  w->field_4ac = 0;
  w->field_4b0 = 1;
  w->field_4b4 = 15;
  w->field_4b8 = 4;
  return w;
}
```

**Do not:**

- Port cooldown remaining / charge formulas into this VA.
- Assume exclusive QuickBar ownership.
- Rename VA into two different functions (Data vs Cooldown) — one VA, two aliases.
- Skip base ctor ordering.

---

## 5. Open questions

1. Product meaning of `+0x4b4=15` and `+0x4b8=4` (segments? z-layers? enum?).
2. Typed identity of `DAT_00d1e504` (default color? width? fill?).
3. Full `FUN_00863f10` base layout (separate dual if needed).

**Verdict:** **accept-with-gaps** — adversarial checks confirm a minimal ctor; only constant semantics remain soft.
