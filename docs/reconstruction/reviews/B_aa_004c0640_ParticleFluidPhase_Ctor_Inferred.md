# Review B (skeptical / adversarial): `aa_004c0640` ParticleFluidPhase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0640` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-M) |
| **Counterpart** | `reviews/A_aa_004c0640_ParticleFluidPhase_Ctor_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `Drive_NDRiver_fx` / NDRiver-named | **Falsified** — sole body is HostBase+vtbl+parent wiring; NDRiver is InitPhases tail (W33-S same reject) |
| 2 | PalantirEnv method (ECX=env) | **Falsified** — `new(0xC8)` then ECX=allocated phase; stored at env+0xCC |
| 3 | No base ctor / pure POD zero | **Falsified** — first call `FUN_007560d0` HostBase |
| 4 | Keeps HostBase vtbl | **Falsified** — immediate `*this = PTR_FUN_009cb62c` |
| 5 | Writes full 0xC8 including +0xb8 | **Falsified** — bytes skip +0xb8; zeros listed slots only |
| 6 | Product English sealed | **Overstated** — `_Inferred` structural name from Init peer only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + parent stack + RET 4 + return this | **High** | Wrong object / stack |
| HostBase then derived vtbl | **High** | Missing base fields |
| Offset map (+0x78..+0xc4, parent fields) | **High** | Port field desync |
| `DAT_00b03790` publish | **High** | Singleton miss |
| Product class demangle | **Inferred** | Naming only |
| parent+0xe4e8 / +0xe894 semantics | **Open** | Wrong parent field roles |
| Runtime | **Open** | Construction order races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  FUN_007560d0(); *param_1 = PTR_FUN_009cb62c; (+0x80)=1;
  FUN_0096f530 ×2; zeros; parent wiring; DAT_00b03790; (+0x78)=0; return this;

bytes:
  MOV ESI,ECX; CALL 007560d0
  MOV [ESI], 009cb62c; MOV byte [ESI+0x80],1
  LEA ECX,[ESI+0x84]/0x8c; CALL 0096f530 ×2
  parent from [ESP+…]; copies; XOR/zero stores; MOV DAT_00b03790,ESI
  MOV byte [ESI+0x78],0; MOV EAX,ESI; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF; full 199 B hex matches body bounds.

---

## 4. Surviving contract for AutoCore

```
// ParticleFluidPhase ctor (env+0xCC host, sizeof 0xC8):
//   ECX = self; stack parent*; returns self; RET 4
//   HostBase_DefaultCtor first; replace vtbl PTR_FUN_009cb62c
//   +0x80=1; init +0x84/+0x8c; parent @ +0xa0; copy parent fields;
//   DAT_00b03790 = self; +0x78 = 0
// Do NOT treat as PalantirEnv method or NDRiver driver.
// Do NOT skip HostBase or invent writes to +0xb8.
// Pair with ParticleFluidPhase_Init_Inferred after construction.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/layout and rejects NDRiver / env-method / no-base claims; product demangle residual only → **accept**.
