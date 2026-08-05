# Review B (skeptical / adversarial): `aa_00567ce0` Quat_FromAxisAngle_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567ce0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00567ce0_Quat_FromAxisAngle_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Degrees → radians (×π/180) | Half factor is `DAT_00a0f298`; bytes `3f000000` = **0.5**, not π/180 | **Falsified** — radians; half-angle only |
| 2 | Full-angle sin/cos (no half) | Explicit `FMUL 0.5` before FSIN/FCOS | **Falsified** — standard half-angle quat |
| 3 | Pure `__cdecl` (caller cleans) | Epilogue **`RET 8`** | **Falsified** — callee cleans **8** stack bytes |
| 4 | `__stdcall` with 3 stack args | Only two stack loads (`[esp+4]`, `[esp+8]`); out in **ECX** | **Clarify** — ECX+2 stack, not 3-stack stdcall |
| 5 | Real C++ thiscall on quat object | No vtable load; ECX is only store base | **Over-claim if “method on object”** — buffer-out convention only |
| 6 | Axis is float3 only (12 B) | Body **`FMUL [eax+0xC]`** then store | **Must have 16 B readable** at axis (even though w result discarded) |
| 7 | Final `out.w = sin(half)*axis.w` | Immediate **`FCOS` + `FSTP [ecx+0xC]`** overwrites | **Falsified for final state** — intermediate dead write only |
| 8 | Identity when angle=0 without reading axis | θ=0 → sin0=0, cos0=1, but axis **still loaded** ×4 | **Loads still happen** — null axis → fault even at 0 |
| 9 | Normalizes axis or re-normalizes quat | No SQRT / inv-len in body | **Falsified** — unit quat only if unit axis |
| 10 | Decompiler arity at `FUN_004f54f0` (2 args) is full ABI | Call-site bytes: `push angle; push axis; mov ecx,out` | **Caller decomp under-counts**; body ABI is 3-arg (ECX+2) |
| 11 | Name must stay parent-seed `Named_CalleeOf_…WeaponSlot…` | 51 xrefs across camera, skill, AI, graphics | **Reject exclusive parent name** — use math role name |
| 12 | Same as matrix-from-quat / basis extract | Body is only sin/cos scale | **Different** from `0x004e8a40` / `0x004e8ad0` / `0x00567d20` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Half-angle 0.5f | **High** | Wrong orientation everywhere (double angle) |
| ECX=out, stack axis+angle, RET 8 | **High** | Stack smash / wrong fills on port |
| Final w = cos(θ/2) | **High** | Non-unit / flipped rotations |
| axis[3] final unused | **High** | Wrong if port keeps s*w |
| Radians not degrees | **High** | π-scale errors |
| Product English “Quat_FromAxisAngle” | **Medium** | Doc only |
| Axis always unit at callers | **Medium** | Silent non-unit quats |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  s = sin(angle * DAT_00a0f298)
  out[0..2] = s * axis[0..2]
  out[3] = s * axis[3]; out[3] = cos(angle * DAT_00a0f298)

bytes:
  FLD angle; FMUL [0.5]; FSIN; scale axis[0..3] into out;
  FCOS; FSTP out[3]; RET 8

DAT_00a0f298 read_memory: 00 00 00 3f → 0.5f
```

Clean must **not**:

- use degrees,
- skip the dead `axis[3]` load if claiming bit-identical FPU traffic,
- invent normalize,
- claim `out.w = s * axis.w` as final,
- use plain `RET` / three stack args without ECX out.

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact axis-angle → quat (radians, half-angle)
// axis must be readable float[4]; w of axis does not affect final q
static void Quat_FromAxisAngle(Span<float> outQ /*4*/, ReadOnlySpan<float> axis /*≥4*/, float angleRad)
{
    float half = angleRad * 0.5f; // DAT_00a0f298
    float s = MathF.Sin(half);
    float c = MathF.Cos(half);
    outQ[0] = s * axis[0];
    outQ[1] = s * axis[1];
    outQ[2] = s * axis[2];
    // retail briefly writes s*axis[3] then overwrites:
    outQ[3] = c;
}
```

**Port traps to reject:**

- `angle * (π/180)` or `angle * 0.5 * π/180`.
- float3-only axis pointer when matching retail crash surface (retail reads +0xC).
- Treating ECX as an object with lifetime/vtable.
- Assuming output is normalized if axis is not unit.
- Caller-clean ABI (`__cdecl` without `RET 8`).

---

## 5. Residual gaps (do not block seal)

1. Product name / engine math library English.
2. Exhaustive non-unit-axis caller audit.
3. Whether `DAT_00af18b0` is the only shared unit-Y constant (caller-owned).
4. Runtime live verification / image diff.
5. Dual of sibling `FUN_00567d20` (matrix→quat).

---

## Verdict

**accept** — adversarial review cannot break half-angle axis→quat kernel. Main falsifications: degrees, full-angle sin/cos, final `w = s*axis.w`, float3-only axis, and under-arity caller decompiles. ABI sealed as **ECX out + axis + angle, RET 8**.
