# Review B (skeptical / adversarial): `aa_00580ed0` TtPhantom_castRay

| Field | Value |
|---|---|
| **Stable ID** | `aa_00580ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-101) |
| **Counterpart** | `reviews/A_aa_00580ed0_TtPhantom_castRay.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `CVOGMap_CastRay` / map heightfield cast | **Falsified** — plate `TtPhantom::castRay`; creature null-phantom path uses `CVOGMap_CastTerrainHeight` instead; overlap list + shape vtbl is phantom geometry |
| 2 | Skill system helper (`Skill_TtPhantom_castRay`) | **Falsified** — only 2 callers (wheel packer + creature terrain); no skill plate/RTTI; `Skill_` was scaffold noise |
| 3 | `Named_CalleeOf_CVOGCreature_FindTerrainHeight` only | **Falsified** — equal primary consumer is wheel packer `0x0064bbd0` |
| 4 | `__cdecl` / `RET 4` / one stack arg | **Falsified** — epilogue **`RET 8`**; packer pushes ray+result; analyze Stack[0x4]/Stack[0x8] |
| 5 | ECX unused / static method | **Falsified** — `this+0x80/0x84/0x08` loaded from ECX; packer sets ECX before CALL |
| 6 | Identical to `MapCollisionCtx_CastRay` `0x0055e530` | **Falsified** — different VA; prior duals already contrast vehicle wheel phantom vs map collision ctx |
| 7 | Filter is required for correct hits | **Unproven** — prep exists; decompile never passes `local_1c` into shape call; wheel still works with flag=1 |
| 8 | `*(fw+0x1f8)` is always this | **Falsified / refined** — packer stores `*(fw+0x1f8)` at ray+0x24; **ECX = `*(fw+0x38)`** at CALL |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 10 | Invented product English beyond plate | **Avoided** — name is plate demangle only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Plate `TtPhantom::castRay` names this VA | **Confirmed** | Wrong geometry backend identity |
| thiscall + RET 8 | **Confirmed** | Stack imbalance in ports |
| Overlap walk + world→local + shape cast | **Confirmed** | Wrong wheel compression |
| Distinct from map terrain Y API | **Confirmed** | Bake terrain-only into suspension |
| Post-hit normal world rotate via `005d6ae0` | **Confirmed** | Bad contact normal |
| Filter object semantics | **Low** | Over-filter or under-filter ports |
| Exact phantom field on framework (`+0x38` vs `+0x1f8`) | **Med** | Wrong this when rehosting packer |
| Shape closest-hit internals | **Med** | Need seed fraction=1.0 from caller |
| Runtime | **Open** | — |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean TtPhantom_castRay.cpp CF

Entry:  55 8B EC 83 E4 F0 83 EC 44 53 56 …
Plate:  C7 06 74 45 9D 00     ; MOV [ESI], 0x009d4574 "TtPhantom::castRay"
Exit:   C2 08 00              ; RET 8
Pad:    CC CC

Callers:
  004c629f  CVOGCreature_FindTerrainHeight
  0064bc61  FUN_0064bbd0  (PUSH result; PUSH ray; ECX=*(fw+0x38); CALL)

Callee:
  005d6ae0  FUN_005d6ae0  (normal R·v)
```

Reject ports that:

- Name this as map/terrain-only cast or skill ability.
- Use cdecl without popping 8 bytes.
- Replace fraction-along-ray with vertical ΔY without re-deriving suspension math.
- Merge with `0x0055e530` / `0x004cfe60`.

---

## 4. Surviving contract for AutoCore

```csharp
// Geometry-later injectable query (retail backend = TtPhantom_castRay semantics)
struct WheelRayQuery { Vec3 start, end; };
struct WheelRayHit {
    bool  hit;           // result+0x20 != null
    float fraction;      // result+0x14; seed 1.0 before cast
    Vec3  normalWorld;   // result+0x00 after FUN_005d6ae0
    object bodyOrNull;   // optional
};

// Retail: walk phantom overlap, shape castRay, rotate normal
// v1:     heightfield / world ray with same I/O
WheelRayHit QueryWheelRay(in WheelRayQuery q);
```

Creature ground snap: if `creature.physicsBody/phantom (+0x254)` present → this cast; else map heightfield sibling.

---

## 5. Verdict

Adversarial pass confirms A on plate/ABI/CF/callers and falsifies map/skill merges. Residual filter/this-field/runtime gaps remain → **accept-with-gaps**.
