# Review B (skeptical / adversarial): `aa_0091d460` Client_Input_ApplyRandomUpPhysicsKick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091d460` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A narrative polish) |
| **Counterpart** | `reviews/A_aa_0091d460_Client_Input_ApplyRandomUpPhysicsKick_Inferred.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on gates + RNG map + mass×12 + physics thiscall; **reject** overclaims that this writes drive axes, is pure unit-scalar helper, is ApplyImpulseVector, or is a finished product-named hop/boost |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Writes thr/steer/HB (`entity+0x614/618/61c`) | **Falsified** — zero axis stores; only builds stack float4 → `FUN_00404cb0` |
| 2 | Is `CVOGPhysics_ApplyImpulseVector` | **Falsified** — sibling shell; body vfunc **`+0x5c`** not **`+0x50`** (`0x0040d260`) |
| 3 | `CVOGReaction_RandomUnitScalar` alone returns [0,1] float | **Falsified role** — `CALL 0x007a4330` returns RNG **host**; this site maps u16→float |
| 4 | Random range is full [−1,1] or [0,1] | **Falsified** — `(u16 * ~0.6/65535) − 0.3` → **≈ [−0.3, +0.3]** |
| 5 | `g_flOverheatCoolFrac` proves overheat coupling | **Falsified as semantics** — shared **0.3f** at `0x00a0f714`; no overheat field touch here |
| 6 | Direction is isotropic 3D random | **Falsified** — base **+Y=1**, only X/Z randomized → **mostly upward** cone |
| 7 | Length includes W | **Falsified** — asm length = x²+y²+z²; W scaled but starts 0 |
| 8 | `FUN_00404cb0(&vec)` is free function with only one real arg | **Falsified** — asm leaves **ECX = *(entity+8)** from mass load; thiscall |
| 9 | Ring wrap at `0xfffff` exclusive misread | **Clarified** — asm `CMP idx, 0x100000` / `JL`; decompiler `0xfffff < idx` ≡ wrap when **≥ 0x100000** |
| 10 | Multiple callers / AI path | **Falsified** — sole caller DriveControlTick |
| 11 | Product name “hop/jump thruster” sealed | **Fail** — no body strings; ActionMap bind residual |
| 12 | Scaffold dual A/B already complete | **Falsified** — prior state was three-rep scaffold only; this dual supersedes |
| 13 | Ready for bit-exact / runtime seal | **Fail** — deferred |

---

## 2. Decisive dataflow (raw ≡ live decompile ≡ asm)

```
entity = *(DAT_00d1b6d8 + 0x250)
if !entity || !*(entity+8) || *(u8*)(entity+0x101): return

if vfunc(+0x198, component_chain(entity)) != 0: return

// float4 @ ESP+0x10
(x,y,z,w) = (0, 1, 0, 0)     // DAT_00afda50

rng = CALL 0x007a4330
if rng.index >= 0x100000: rng.index = 0
u = rng.table[rng.index++]; x = (float)u * DAT_00aaaaf0 - 0.3f

rng = CALL 0x007a4330
if rng.index >= 0x100000: rng.index = 0
u = rng.table[rng.index++]; rz = (float)u * DAT_00aaaaf0 - 0.3f

len2 = x*x + y*y + rz*rz
inv  = (len2 == 0) ? 0 : 1/sqrt(len2)     // g_flOne @ 0x00a0f2a0

// normalize first (asm), then:
ECX = *(entity+8)                         // physics host — lives to CALL
mass = *(*(ECX)+0x3c + 0x2c)
s = (mass == 0) ? 0 : (1/mass) * 12.0f    // DAT_00aaaad0

vec = (x,y,rz,w) * inv * s
PUSH &vec
CALL FUN_00404cb0                         // thiscall ECX=physics; body vtbl+0x5c(vec)
```

Live `force_decompile` 2026-07-29 matches 2026-07-23 raw. Constants re-verified `read_memory`.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gates + sole caller | **High** | Phantom kicks / wrong entity |
| Mostly-up random cone | **High** | Wrong force model (isotropic vs hop) |
| ±0.3 map + 12/mass | **High** | Wrong kick strength / mass independence |
| Physics thiscall ECX | **High** | Null/wrong body apply crash |
| Not drive-axis writer | **High** | Double-count thr in port |
| Not ApplyImpulseVector | **High** | Wrong Havok op |
| Product action name | **Open** | UX label only |
| vfunc +0x198 / +0x5c English | **Open** | Block condition / impulse vs vel |
| Runtime golden | **Open** | Residual parity |

---

## 4. Offset / formula attack checklist

| Item | Attack | Result |
|------|--------|--------|
| `entity+0x101` gate | Invented? | **No** — same drive-suppress flag as PushDriveAxes |
| `entity+0x8` physics | Invented? | **No** — mass path + ECX this |
| `body+0x2c` mass | Wrong field? | **CF High** as loaded scale; English “mass” Probable |
| `DAT_00aaaaf0` | Guess? | **No** — LE `349a1937` ≈ 0.6/65535 |
| Subtract 0.3 | Overheat path? | **Value yes, name no** — `0x00a0f714` |
| `DAT_00aaaad0` = 12 | Guess? | **No** — `00004041` |
| Base (0,1,0,0) | Guess? | **No** — `afda50` block |
| Symmetric ± random on Y | Compatible? | **No** — Y fixed 1 |
| Axis writes | Hidden? | **None** |

---

## 5. Surviving contract for AutoCore

```
Client_Input_ApplyRandomUpPhysicsKick_Inferred():
  entity = localVehicleFrom(DAT_00d1b6d8+0x250)
  require entity, physics=*(entity+8), driveEnabled(entity+0x101==0)
  require !vfunc_0x198(component_chain(entity))
  dir = normalize( (rand±0.3, 1.0, rand±0.3) )   // w=0
  scale = (mass(physics)==0) ? 0 : 12.0 / mass
  FUN_00404cb0(physics, dir * scale)              // vtbl+0x5c; not axes
```

**Port note:** do **not** treat as keyboard thr/steer producer. Co-located in DriveControlTick only as secondary edge action with parent rate limit (5s / counter) — rate limit lives in **caller**, not this body.

---

## 6. What would change the verdict

| Evidence | Effect |
|----------|--------|
| ActionMap string for `DAT_00d1be2e` | Promote name beyond `_Inferred` |
| Body string / RTTI for kick | Confirm hop vs boost vs unstick |
| Dual of `FUN_00404cb0` sealing vfunc+0x5c | Close apply semantics gap |
| Runtime capture of vec under known mass | Bit-exact strength |

---

## 7. Dual process note

OWN-ONLY dual B on `0x0091d460`. Independent adversarial pass over live decompile + full-function disasm + constant `read_memory`. No ledger edits. No other VA duals.
