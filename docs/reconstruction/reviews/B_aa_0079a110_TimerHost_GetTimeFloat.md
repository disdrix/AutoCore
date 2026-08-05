# Review B (skeptical / adversarial): `aa_0079a110` TimerHost_GetTimeFloat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0079a110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0079a110_TimerHost_GetTimeFloat.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Turret-specific helper (`Named_CalleeOf_CVOGPlayerVehicle_UpdateTurretAiming`) | 34 xrefs across anim/drive/update | **Falsified** turret-only claim |
| 2 | Writes or updates the clock | Body is FLD only — no store | **Falsified** writer claim |
| 3 | Offset is `+0x23c` or vtbl slot | Bytes: displacement `0x238` | **Falsified** wrong offset |
| 4 | Returns int milliseconds | FLD dword float → ST0 | **Falsified** int claim |
| 5 | Stack formal `this` | `[ECX+0x238]` only | **Falsified** stack this |
| 6 | Name `TimerHost_GetTimeFloat` overclaims “time” | Callers use as duration/sample clock on `DAT_00b04c74` | **Survives** structural; product English open |
| 7 | Non-trivial math / scale | 7-byte FLD+RET | **Falsified** math claim |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x238` float load | **High** | Wrong field in ports |
| ECX host | **High** | ABI mismatch |
| No side effects | **High** | Spurious state changes |
| Time semantic | **Medium** | Could be generic float field; still correct load |
| Units | **Open** | Scale errors if assumed wrong unit |

---

## 3. Cross-check against raw / bytes

```
raw: return *(float *)(param_1 + 0x238);
bytes: FLD dword [ECX+0x238]; RET
```

Clean ≡ raw ≡ bytes. Nothing to modernize.

---

## 4. Surviving contract for AutoCore

```csharp
static float GetTimeFloat(TimerHost host) // ECX
{
    return host.TimeAt0x238; // float field only
}
// Do not invent setters, scales, or turret-only wrappers here.
```

**Port traps to reject:**

- Treating as turret-only API.
- Assuming integer tick counter.
- Adding writes or conversion in this unit.

---

## 5. Residual gaps (do not block seal)

1. Product English for host type / field.
2. Layout dual of `DAT_00b04c74`.
3. Units (seconds vs other).

---

## Verdict

**accept** — adversarial review cannot break the 7-byte field-load kernel. Scaffold “turret callee” name is rejected; structural timer-host getter stands.
