# Review B (skeptical / adversarial): `aa_005da0a0` Drive_CollisionListener_Contact

| Field | Value |
|---|---|
| **Stable ID** | `aa_005da0a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W22-I) |
| **Counterpart** | `reviews/A_aa_005da0a0_Drive_CollisionListener_Contact.md` |
| **Scratch** | `tmp/a_005da0a0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler signature is complete (4 stack args, no this) | **Falsified** — prologue `mov [esp+0x24],ecx`; `RET 0x10`; rate uses saved this |
| 2 | Always damages both vehicles | **Falsified** — many early returns 0/1; type gates; flag +0x26 required for damage apply |
| 3 | Always sends Logic-UI packet | **Falsified** — only if linked actor path and `ABS(*impact) > 1.0` |
| 4 | Name invented without evidence | **Falsified** — literal `"CollisionListener::contact"` + sibling `DoVehicleCollision` |
| 5 | Energy formula guessed | **Falsified** — floats read: 3.6, ~2.5e-7, clamp 350 |
| 6 | Multiple independent callers | **Falsified** — sole xref `FUN_005dab30` |
| 7 | `local_19e` always returned | **Overstated** — early paths return literal 1; reject returns 0; some return `local_19e` |
| 8 | Type ids product-known | **Overstated** — 0xe/0x12/3 sealed as discriminators only |
| 9 | `FUN_005d9290` is optional noise | **Falsified** — bidirectional main vehicle-collision path when filters pass |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Name / string | **High** | Misfiled system |
| thiscall + RET 0x10 | **High** | Stack smash / wrong rate host |
| Parent-walk + type==1 resolve | **High** | Missed GO → wrong return 1 |
| Energy constants | **High** | Wrong damage scale |
| UI opcode 0x29 gate | **High** | Spam/miss collision UI |
| Bidirectional DoVehicleCollision | **High** | One-sided collision effects |
| Return AL contract vs caller | **High** | Sticky disabled contacts |
| Clonebase type English | **Medium** | Port mis-filter |
| Full event layout | **Medium** | Adapter residual |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
this = ECX; (ctx, impact, bodyA, bodyB) = stack×4
scope("CollisionListener::contact")
hosts = walk(bodyA/B → parent[3] → [8])
goA/goB = scan(host list type==1, flag bit5, vtbl+0x1c8)
// material-1 exclusive path may set local_19e=0 + debounce 500ms
// type 0xe hooks; rate flag via this+0x10 vs 0.5s
prep both (FUN_005d9ea0)
if !goA || !goB: return 1
// gates, energy, damage, FX, UI 0x29
// filters → maybe return local_19e
// else DoVehicleCollision both orders → return local_19e or 0
RET 0x10
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean plate fills this residual + renames from string.

Caller `FUN_005dab30` bytes confirm arg order and `if AL==0: event+0x20=1`.

---

## 4. Surviving contract for AutoCore

```
// CollisionListener contact callback
ok = Drive_CollisionListener_Contact(listener, ctx, &impact, bodyA, bodyB)
// ok==0 → disable/suppress this contact event (event.flag_20 = 1)
// ok!=0 → contact processed (damage/FX/UI may have fired)
//
// Energy: min(350, (speed*3.6)^2 * mass * 2.5e-7)
// UI toast/event: opcode 0x29 when |impact| > 1.0 and actor links present
// Vehicle-specific: Drive_CollisionListener_DoVehicleCollision both orderings
//
// Do not omit type gates 0xe / 0x12 / 3 or debounce 500ms on material-1 path.
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/string/constants sealed; gaps are product type English + nested callee depth → **accept-with-gaps**.
