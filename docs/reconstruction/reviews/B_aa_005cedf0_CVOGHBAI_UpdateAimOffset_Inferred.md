# Review B (skeptical / adversarial): `aa_005cedf0` CVOGHBAI_UpdateAimOffset_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cedf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-O) |
| **Counterpart** | `reviews/A_aa_005cedf0_CVOGHBAI_UpdateAimOffset_Inferred.md` |
| **Scratch** | `tmp/a_005cedf0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure movement / pathfinding stepper | **Falsified** — random aim local offset + quat transform + `g_abInferredDefaultAimPos` |
| 2 | Always rebuilds offset every tick | **Falsified** — arm ts, 1.5s hold, flag gate, still/drift gates |
| 3 | cdecl with stack this | **Falsified** — ECX this; no stack formals; frame RET |
| 4 | TTL is 1.5 not 6 | **Falsified** — `DAT_00aaa8dc=6.0` clears active; `DAT_00aaa68c=1.5` is arm delay |
| 5 | Compares world positions with relative eps only | **Falsified** — absolute thresholds 0.05 / 0.75 / 1.0 |
| 6 | Name is retail plate string | **Open** — **Inferred**; evidence is default-aim global + role |
| 7 | Unreachable block changes live CF | **Falsified for sealed paths** — warning only; live returns covered |
| 8 | Random scales arbitrary | **Falsified** — ushort × (5/65535)+5 and ×(6/65535)+4 sealed by `read_memory` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| State machine CF | **High** | Wrong NPC aim behavior |
| Constants | **High** | Wrong timing / ranges |
| ECX this void | **High** | ABI break |
| Aim-offset role | **High** | Mis-port consumers |
| Product English | **Medium** | Naming only |
| Nested callee internals | **Open** | Partial port |
| Runtime RNG | **Open** | Bit-exact aim |

---

## 3. Cross-check against raw + bytes

Prologue `55 8B EC 83 E4 F0 83 EC 64` matches 0x64 frame. Dual epilogues at end:
- clear path: `xorps; mov [esi+0x60],bl; movss [esi+0x3c],xmm0; pop*; ret`
- generic: `pop edi/esi/ebx; mov esp,ebp; pop ebp; ret`

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Callers all HB AI DoLogic/HeartBeat.

---

## 4. Surviving contract for AutoCore

```
// Per AI tick (Driver/Creature DoLogic / OnHeartBeat):
CVOGHBAI_UpdateAimOffset_Inferred(aiAimHelper);
// Side effects: may set this+0x40 aim vec4, flag+0x60, ts+0x3c
// Requires matching constants: 6s TTL, 1.5s arm, 0.05 still, 0.75 near, 1.0 drift
// Random: 3× RandomUnitScalar ushorts → local X/Z then quat transform via +0x18
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/constants sealed; product name + nested/RNG residual → **accept**.
