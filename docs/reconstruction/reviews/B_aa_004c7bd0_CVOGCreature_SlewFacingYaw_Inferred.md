# Review B (skeptical / adversarial): `aa_004c7bd0` CVOGCreature_SlewFacingYaw_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c7bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004c7bd0_CVOGCreature_SlewFacingYaw_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This sets world position / teleports | Sole store is float `+0x11c` | **Falsified** teleport |
| 2 | Full 3D look-at (pitch) | Y component forced `* 0`; XZ only | **Falsified** pitch |
| 3 | Instant snap to target angle | Rate `(1-align)*ms*0.001*9.6` + align gate | **Falsified** snap |
| 4 | Degrees, not radians | `2π` wrap constant `≈6.283185` | **Falsified** degrees |
| 5 | `__cdecl` / no stack cleanup | Epilogue **`RET 4`** | **Falsified** cdecl |
| 6 | `param_2` is float already | `FILD`/float cast of int; `<0` → `+2^32` | **Survives as int ms** |
| 7 | Only SetupGraphics uses it | HB ctor `005d6b80` + tick `005d6c10` also call | **Falsified** setup-only |
| 8 | Align threshold is 1.0f float | Double `0.999` @ `0x009cbab8` | **Falsified** exact-1.0 |
| 9 | Name wrong (not facing yaw) | Write `+0x11c` + acos/sin/cos + HB period | **Survives** structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Write site `+0x11c` only | **High** | Corrupt wrong field |
| Rate / wrap constants | **High** | Wrong turn speed / angle domain |
| Horizontal-only | **High** | Fake pitch in port |
| `RET 4` thiscall | **High** | Stack smash |
| Acos argument component | **Medium** | Wrong absolute heading base |
| Aim path English | **Open** | Wrong target when free-aim |

---

## 3. Cross-check against raw / bytes

```
raw: host? finite? aim-path; delta XZ; dist>eps; unit; acos; basis; 2π wrap;
     sin/cos; align<0.999; step=(1-a)*ms*0.001*9.6; signed; store +0x11c
bytes: 8B F1; RET C2 04 00; FLD/FMUL constants 9.6 / 0.001 / 2π / 0.999
```

Clean ≡ raw ≡ live decompile. Constants sealed by `read_memory`.

---

## 4. Surviving contract for AutoCore

```csharp
// deltaMs from HB period or setup push (e.g. 0x1E).
void SlewFacingYaw(Creature c, int deltaMs)
{
    if (c.Host == null) return;
    // … pose finite, aim resolve, XZ delta …
    if (horizLen <= 1.1920929e-7f) return;
    var dir = NormalizeXZ(delta); // y = 0
    float ang = AcosClamped(/* unit component */);
    // basis flip → ang = 2π - ang when needed
    float combined = Wrap2Pi(ang + c.Yaw); // Yaw @ +0x11c
    float align = Dot(Heading(combined), dir);
    if (align >= 0.999) return;
    float ms = deltaMs < 0 ? deltaMs + 4294967296f : deltaMs;
    float step = (1f - align) * ms * 0.001f * 9.6f;
    // signed by 2D cross; residual = wrap(combined ± step - ang)
    c.Yaw = residual;
}
```

**Port traps to reject:**

- Snapping yaw without rate.
- Using degrees or π-wrap only.
- Applying pitch from 3D look-at.
- Forgetting `RET 4` / stack `deltaMs`.
- Treating `0.999` threshold as hard `1.0` equality only (gate is `< 0.999`).

---

## 5. Residual gaps (do not block seal)

1. Exact stack float into `Math_AcosClamped` (decompiler omits formal; not owned to re-dual here).
2. Product English for free-aim / camera slot path.
3. Runtime yaw slew differential vs retail.
4. PDB name for HB pair `005d6b80` / `005d6c10`.

---

## Verdict

**accept-with-gaps** — adversarial review cannot break XZ slew, rate formula, 2π wrap, or `+0x11c` write. Main falsifications are teleport/pitch/snap/degrees myths. Gaps are acos-arg detail + aim English + runtime.
