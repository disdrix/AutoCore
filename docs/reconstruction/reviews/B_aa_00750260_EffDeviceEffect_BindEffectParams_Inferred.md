# Review B (skeptical / adversarial): `aa_00750260` EffDeviceEffect_BindEffectParams_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00750260` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-C) |
| **Counterpart** | `reviews/A_aa_00750260_EffDeviceEffect_BindEffectParams_Inferred.md` |
| **Scratch** | `tmp/a_00750260.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** `D3DXCreateEffect` itself | **Falsified** — caller `FUN_00751890` calls `D3DXCreateEffect` then this |
| 2 | ECX-thiscall | **Falsified** — prologue loads object from `[EBP+8]`, not ECX |
| 3 | Always returns −1 only | **Falsified** — epilogue path `XOR EAX,EAX` (success 0); caller checks `iVar5 >= 0` |
| 4 | Name is exact product method | **Careful** — inferred from `effDeviceEffect.cpp` path + role; no PDB demangle |
| 5 | Decompiler types (************) are real | **Falsified** — type-prop WARNING; treat as pointer noise |
| 6 | Thin string helper only | **Falsified** — 5616 B; COM walk + alloc + matrix table |
| 7 | Many callers | **Falsified** — sole xref from `FUN_00751890` |
| 8 | Clean cpp is bit-exact port | **Falsified** — structural contract only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product file / graphics effect domain | **High** | Wrong subsystem |
| Post-create bind role | **High** | Wrong call order |
| String semantic table | **High** | Wrong matrix/light mapping |
| Body size / SEH / stack object | **High** | ABI crash |
| Full typed layout | **Low** | Field offsets wrong |
| 2nd formal semantics | **Med** | Path unused vs used |
| Nested callees | **Open** | Incomplete port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against caller + strings + bounds

```
// Caller FUN_00751890:
//   D3DXCreateEffect(... fallback HLSL ...);
//   if ok: FUN_00989e00(&local_24, "effFallbackEffect.h");
//          iVar5 = FUN_00750260(obj, &local_24);
//          if (iVar5 >= 0) { effect vtable tweaks }
//   else: vog_LogMessage(...effDeviceEffect.cpp..., "Failed to compile the fallback effect:")
//
// This unit's own log plate: same effDeviceEffect.cpp
// Nested string concat: FUN_00416410 (W33-F sealed free operator+(string,string))
// Bounds: 0x750260 + 0x15F0 = 0x751850
```

Live 2026-07-29 decompile ≡ 2026-07-23 scaffold CF + string set.

---

## 4. Surviving contract for AutoCore

```
// Port as large product-specific effect bind, not a thin wrapper.
// ABI: stack device_effect*; int return (0 / -1); EBP+SEH frame.
// Use sealed string table for matrix/light semantics.
// Reuse StdString_OperatorPlus_String (00416410) for LightCount_/LightSupport_ builds.
// Do not invent ECX-thiscall or claim D3DXCreateEffect ownership.
// Do not treat decompiler ************ types as real layouts — re-type from
// runtime or smaller nested duals first.
```

---

## 5. Verdict

Adversarial pass confirms A on product domain, bounds, caller, string table, return shape. Residual type/2nd-arg/nested/runtime + structural-only clean → **accept-with-gaps**.
