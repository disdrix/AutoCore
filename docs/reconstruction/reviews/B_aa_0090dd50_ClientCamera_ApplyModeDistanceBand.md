# Review B (skeptical / adversarial): `aa_0090dd50` ClientCamera_ApplyModeDistanceBand

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dd50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0090dd50_ClientCamera_ApplyModeDistanceBand.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is `__thiscall` with ECX | Decompiler `in_EAX`; entry loads `[EAX+0x60c]`; no ECX this | **Falsified** — **EAX object** |
| 2 | Restores full camera pose/position | Only writes floats at +0x524..+0x534; no matrix/pos stores | **Falsified** — **distance band only** |
| 3 | Has callees / logging | `get_function_callees` empty; body is MOVSS/arithmetic | **Falsified** — **leaf** |
| 4 | Mode 0 always rewrites current distances | Secondary init gated on `DAT_00d1b6d8` and `+0x6b9` | **Confirmed** — only optional path writes +0x52c/+0x530 |
| 5 | Clamp is exclusive / broken by decompiler compares | Expanded fcom pairs still map to inclusive [min,max] | **Falsified hazard** — clamp is correct |
| 6 | `DAT_00af9150` is not 16 | `read_memory` `00008041` → 16.0f | **Falsified** — **16.0** |
| 7 | Name is product-string sealed | No strings in unit; name from behavior + callers | **Admit** — name is **Probable / inferred** |
| 8 | Alias "Named_CalleeOf_CreateCharacter" is sole purpose | 12+ call sites incl. Respawn/Teleport | **Falsified exclusive use** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mode 0/1/else float table | **High** | Wrong zoom after respawn/teleport |
| Rate = (max−min)/16 | **High** | Zoom animation speed wrong |
| Clamp both currents | **High** | Stuck out-of-band zoom |
| EAX ABI | **High** | Wrapper crash |
| Mode product semantics | **Low** | Only docs/UI labels |
| Wide/narrow flag meaning | **Low** | Wrong max when flag flipped |

---

## 3. Cross-check against raw + bytes

```
entry:  8B 88 0C 06 00 00     mov ecx, [eax+0x60c]
        83 E9 00              sub ecx, 0
        0F 84 8D 00 00 00     je  mode0
        83 E9 01              sub ecx, 1
        74 55                 je  mode1
        ; else path loads af916c / af9170 via MOVSS
…
float pool @ af9150: 16,2,11,16,6,20,30,12,20  (LE decode)
a0f298: 0.5
epilogue sites: C3 (plain ret)
```

CF ≡ raw decompile ≡ clean plate mode table.

---

## 4. Surviving contract for AutoCore

```csharp
// Client-only camera helper. Server has no equivalent requirement unless
// simulating client camera for tools.
void ApplyModeDistanceBand(Camera cam)
{
    float min, max, rate;
    switch (cam.Mode) // +0x60c
    {
        case 0:
            min = 2f;
            max = WideMaxFlag ? 16f : 11f;
            rate = (max - min) / 16f;
            if (LocalEntity != null && LocalEntity.Flag6b9)
            {
                float secMax = WideMaxFlag ? 30f : 20f;
                float span = secMax - 6f;
                cam.Secondary = span * 0.5f;
                cam.Primary = span / 16f + cam.Secondary;
            }
            break;
        case 1:
            min = 6f;
            max = WideMaxFlag ? 30f : 20f;
            rate = (max - min) / 16f;
            break;
        default:
            min = 12f; max = 20f;
            cam.Primary = cam.Secondary = 20f;
            rate = (max - min) / 16f;
            break;
    }
    cam.Min = min; cam.Max = max; cam.Rate = rate;
    cam.Primary = Math.Clamp(cam.Primary, min, max);
    cam.Secondary = Math.Clamp(cam.Secondary, min, max);
}
```

- Do **not** treat this as full camera restore (position/look); callers that need that do other work.
- Preserve mode cookie write → ApplyModeDistanceBand order used by Respawn/Teleport.

---

## 5. Residual attacks that stand

1. Product mode labels unknown.
2. `DAT_00d1b26c` / `+0x6b9` product meanings unknown.
3. No runtime memory capture in this dual.

None break the sealed numeric CF. **Verdict: accept**
