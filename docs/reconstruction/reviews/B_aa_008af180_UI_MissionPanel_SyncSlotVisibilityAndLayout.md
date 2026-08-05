# Review B (skeptical / adversarial): `aa_008af180` UI_MissionPanel_SyncSlotVisibilityAndLayout

| Field | Value |
|---|---|
| **Stable ID** | `aa_008af180` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008af180_UI_MissionPanel_SyncSlotVisibilityAndLayout.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `__thiscall` with ECX host | Callers set **ESI**, not ECX; stack force arg | **Falsified** as pure thiscall |
| 2 | Only medals panel | Three feature-flag slots + medals; general 4-slot layout | **Falsified** as medals-only |
| 3 | Always relayouts | `forceRelayout==0` early return after visibility sync | **Sealed** |
| 4 | Teardown path is live hang (infinite loop) | Decompiler residual on `+0x160`; live path requires `DAT_00af92d4!=0` | **Overstated** as product hang |
| 5 | `ESI` always `dialog+0x684` | Class methods pass `this` (ESI=EDI/ECX); RecvComplete uses `+0x684` | **Sealed** as dual host sources |
| 6 | Scale floats are 0.85/0.66 | `read_memory` shows ~0.000833 / 0.000625 (and negatives) | **Falsified** wrong magnitudes |
| 7 | void return ignored always | void confirmed; no AL contract | **Sealed** |

---

## 2. Confidence table

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI host / force stack | **High** | Wrong port ABI |
| Stage order (sync → maybe layout) | **High** | Spurious geometry |
| Medals string + `.dds` | **High** | Wrong asset path |
| Scale constant magnitudes | **High** | Layout drift |
| Multi-slot pixel math | **Tentative** | Visual parity |
| Feature-flag product names | **Open** | Doc only |
| Runtime | **Open** | |

---

## 3. Surviving contract

```c
// ESI=panel host; stack char forceRelayout
void UI_MissionPanel_SyncSlotVisibilityAndLayout(void* host /*ESI*/, char forceRelayout);
```

- Visibility sync always (when root live + not teardown).
- Layout only if force or visibility changed.
- Medals path is one of four slots, not the whole function.

---

## 4. Verdict

**accept-with-gaps** — adversarial seals ESI/force ABI, non-medals-only role, force short-circuit, and correct scale magnitudes; geometry residual remains.
