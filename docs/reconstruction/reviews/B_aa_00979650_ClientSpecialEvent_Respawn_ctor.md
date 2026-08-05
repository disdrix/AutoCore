# Review B (skeptical / adversarial): `aa_00979650` ClientSpecialEvent_Respawn_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00979650_ClientSpecialEvent_Respawn_ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Ctor runs the INC airlift / phase machine | No anims, no ship, no phases — only field copy + `FUN_00979310` | **Falsified** |
| 2 | Clean caller shows full ABI | Shows `(event, flag, quat)` only; body needs dest+entity registers | **Caller decompile incomplete** |
| 3 | Flag at `+0x38` is raw `packet+0x40` dword | Caller passes `!= 0` boolean | **Booleanized** |
| 4 | TFID is optional | Always copied from entity `+0x164` path | **Always written** |
| 5 | Same size as TeleportIn | **0x70** vs In **0x50** / Out **0x34** | **Distinct** |
| 6 | Vtable is shared with TeleportOut | Distinct `PTR_…_00a76720` with Update `0x00979730` | **Falsified** |
| 7 | Plate “EDX = entity+0x250 child” | Body uses EDX as entity for TFID; `+0x250` checked only in caller | **Plate overstates** |
| 8 | Multiple callers | Sole xref `0x0080cde2` | **Single** |
| 9 | Layout disagrees with Update dual | Update uses same `+0x28` TFID, `+0x38` flag, dest `+0x40/+0x50`, timers `+0x60/+0x64`, phase `+0x6d` | **Consistent** |
| 10 | Bit-exact proven | Static only | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Respawn ctor / type 0 / size 0x70 | **High** | Wrong heap object |
| Field offsets vs Update | **High** | Broken phase machine inputs |
| ABI registers dest+entity | **High** | Dest/TFID garbage |
| `FUN_00979310` side effects | **Medium** | Missed zero of gfx slots |
| Packet offset map (caller) | **High** structure from `Client_RecvSpecialEvent` plate | Wrong wire layout if plate wrong |
| Runtime | **Open** | — |

---

## 3. Cross-check

| Check | Result |
|---|---|
| Live ≡ raw `aa_00979650` | **Match** |
| Update dual field table | **Consistent** |
| Caller requires `entity+0x250 != 0` before new | **Precondition** not in ctor |
| Type 0 only | **Yes** |

---

## 4. Surviving contract for AutoCore

```
// Client presentation — SpecialEvent type==0 (Respawn).
// ABI: ECX=destPos*, EDX=entity*, stack=(Event* e /*0x70*/, uint8 flag, float4* quat)

Event* ClientSpecialEvent_Respawn_ctor(Vec4* dest, Entity* ent, Event* e, uint8 flag, Vec4* quat)
{
  e->vt = &Vtable_Respawn;          // Update @ 0x00979730
  e->cancel = 0;                    // +0x08
  e->gfx = e->ship = null;          // +0x10/+0x14
  e->tfid = LoadTfid16(ent);        // +0x28 from ent+0x164 (MI)
  e->fullSequence = flag;           // +0x38
  e->destPos = *dest;               // +0x40
  e->destQuat = *quat;              // +0x50
  e->elapsed = e->phaseTime = 0;    // +0x60/+0x64
  e->liftFollow = 0; e->phase = 0;  // +0x6c/+0x6d
  FUN_00979310(e);
  return e;
}
```

**Do not:**

- Put phase / airlift logic in the ctor.
- Trust one-arg or three-arg caller listings without registers.
- Store raw `packet+0x40` dword if product only needs boolean (caller already booleanizes).
- Confuse with TeleportIn/Out sizes or vtables.

---

## 5. Open questions

1. Full body of `FUN_00979310` (shared with Update cancel) — sibling VA.
2. Whether `+0x0c` camera cookie is ever set by ctor path (Update uses it; ctor body does not write it).
3. Runtime when `flag==0` (Update early-complete at phase 2).

**Verdict:** **accept-with-gaps** — thin initializer dual is solid; residual risk is incomplete caller decompile and helper `FUN_00979310`, not the field map.
