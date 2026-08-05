# Review B (skeptical / adversarial): `aa_005bc120` Emitter_SpawnOnIntervalTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-I) |
| **Counterpart** | `reviews/A_aa_005bc120_Emitter_SpawnOnIntervalTick_Inferred.md` |
| **Scratch** | `tmp/a_005bc120.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the full emitter update (`FUN_005bc3c0`) | **Falsified** — sole **callee** of 005bc3c0 at one site; body is interval spawn only |
| 2 | Always spawns every call | **Falsified** — early return while countdown `+0x804 > 0` after −dt |
| 3 | cdecl / no this | **Falsified** — `MOV ESI,ECX`; `RET 8` |
| 4 | Reschedule is fixed period | **Falsified** — ushort RNG × range × ≈1/65535 + base |
| 5 | Cap 0 means zero spawns | **Falsified** — `local_c = 0` rewritten to `0x7FFFFFFF` (unlimited) |
| 6 | Multi-group always on | **Falsified** — only when `+0x98C & 0x80` and vector non-null |
| 7 | Product English sealed | **Open** — `_Inferred` intentional |
| 8 | All nested callee this models sealed | **Open residual** — decompiler-shaped; machine fix out of OWN if needed |
| 9 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Interval CF + early-out | **High** | Spurious continuous spawn |
| RET 8 / two formals | **High** | Stack smash |
| Reschedule formula + scale | **High** | Wrong spawn cadence |
| Emitter domain (caller string) | **High** | Mis-system classification |
| Nested create/list/motion names | **Medium–High** | Wrong callee wiring in ports |
| Product method name | **Open** | Docs only |
| Nested ECX models | **Tentative** | Subtle ABI bugs if ported blindly |

---

## 3. Cross-check against raw + bytes

```
acc += rate * dt
countdown -= dt; if countdown > 0: ret
groups = 1 or vector_len/0xC
clear ring flags; empty name → reschedule
for g in groups:
  for i in maxBurst while active < cap:
    create/insert/motion/[pair]
reschedule: countdown = base + range * (u16 * ~1/65535)
ret 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Call site pushes two formals then `mov ecx,esi; call`.

---

## 4. Surviving contract for AutoCore

```
// Port cadence must match:
//   nextInterval = base + range * (ushort_rng / 65535.0f)   // DAT_00aaa638
// Do not spawn every frame — gate on countdown <= 0 after dt subtract.
// Cap field 0 means unlimited (INT_MAX), not zero.
// Empty asset name still reschedules timer (no spawn body).
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/interval/spawn/reschedule. Nested this models + product name residual only → **accept**.
