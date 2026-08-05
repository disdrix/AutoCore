# Review B (skeptical / adversarial): `aa_0040d040` CVOGPhysics_SetAngularVelocity

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d040` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040d040_CVOGPhysics_SetAngularVelocity.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Applies **linear** velocity / impulse | Confuse with `0x40d260` | **Falsified** — slot imm **`0x54`**, not `0x50` |
| 2 | No readiness gate (“networkApply table says none”) | Prior-art table row | **Falsified for body** — same `5070b0`/`5070d0` gate as ApplyImpulseVector; table meant caller soft path, not body |
| 3 | Writes position / rotation | Bundle with soft-teleport helpers | **Falsified** — only vtbl call; pos=`0x40d2a0`, rot=`0x404dc0` |
| 4 | Math / clamp / scale ω | Overfit damping | **Falsified** — pure forward; AVD damping is separate `0x64d810` |
| 5 | Decompiler `FUN_005070b0((int)&uStack_4+3)` invents wrong `this` | Stack artifact | **Falsified as behavior change** — asm keeps ECX=`this`; out-byte is stack temp |
| 6 | Null body is safe no-op | Defensive port | **Falsified** — no test of `phys+0x3c` |
| 7 | Always prepares (`5070d0`) | Skip gate | **Falsified** — only when probe out==0 **and** `+0x44≠0` |
| 8 | DriveControlTick is sole caller | DCT-centric naming | **Falsified** — 8 sites; network/airStab/AI also call |
| 9 | Slot +0x54 is setLinearVel | Offset confusion with rb fields `+0x50..5c` | **Falsified** — method slot ≠ field offset; fields are read in AVD, write uses method +0x54 |
| 10 | Name `SetAngularVelocity` is string-proven | Symbol inflation | **Not sealed** — **Probable** from usage; Ghidra still `FUN_0040d040` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| body `+0x3c` / vtbl **+0x54** | **High** | Wrong axis (spin vs slide) |
| Ready probe + optional prepare | **High** | Dropped / double-init ω |
| Sibling +0x50 linear | **High** | Port swaps lin/ang |
| Caller list completeness (8) | **High** | Miss soft net / airStab zero |
| Havok English method name | **Medium** | Doc only |
| `+0x44` / `+0x29` type names | **Low–Med** | Naming only |
| f3 vs f4 consumer | **Medium** | Padding / w component |

---

## 3. Cross-check against raw

```text
// raw aa_0040d040 ≡ live decompile 2026-07-29
probe = FUN_005070b0(this, &out);   // decompiler form messy; asm thiscall
if (*out == 0 && *(this+0x44) != 0)
    FUN_005070d0(this);
body = *(this+0x3c);
(*body->vtbl)[+0x54](vec);          // FF 52 54
```

Sibling raw `aa_0040d260`: identical except `+0x50`.

---

## 4. Surviving contract for AutoCore

```
CVOGPhysics_SetAngularVelocity(phys, angVelVec):
  // readiness (same as ApplyImpulseVector)
  out = ready_flag(phys)          // via FUN_005070b0: 0 if +0x44 null else *(*(phys+0x44)+0x29)
  if out==0 && phys.field_44 != null:
      FUN_005070d0(phys)          // prepare / attach path
  body = phys.rigidBody (+0x3c)   // NO null check
  body->setAngularVelocity(angVelVec)   // vtbl +0x54

// Sibling:
//   CVOGPhysics_ApplyImpulseVector → vtbl +0x50 (linear / set lin vel)

// Known producers of angVelVec:
//   DriveControlTick: zero vec (clear ω under mode gate)
//   network soft FUN_0053eec0: net angVel on large pos error
//   airStab: DAT_00b04eb0 zero pack cleanup
//   AI DecideHeading / related
```

**Port tests that matter:**

* Must **not** call vtbl+0x50 (that is linear sibling).
* Must run ready prepare only on (out==0 && +0x44≠0).
* Must not write pos/rot fields itself.
* Null `phys+0x3c` may fault — ports that silent-return diverge from retail CF.

---

## 5. Open questions

1. Confirm Havok method identity for vtbl+0x54 (RTTI / vtable dump).
2. `phys+0x44` object type and `+0x29` flag producers.
3. Whether any caller packs only xyz (w undefined) vs full quat-style f4.
4. Runtime CE force of ready flag under DriveControlTick zero path (policy-open).

**Verdict:** **accept-with-gaps** — adversarial attacks on lin/ang confusion and “no gate” prior-art row **fail**; remaining gaps are naming/types/runtime only.
