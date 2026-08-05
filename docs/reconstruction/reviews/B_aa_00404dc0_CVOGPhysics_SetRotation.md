# Review B (skeptical / adversarial): `aa_00404dc0` CVOGPhysics_SetRotation

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404dc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00404dc0_CVOGPhysics_SetRotation.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sets **position** (confuse with `0x40d2a0`) | Slot mix-up | **Falsified** — imm **`0x44`**, not `0x40` |
| 2 | Sets **angular velocity** (confuse with `0x40d040`) | Family bundle | **Falsified** — slot `0x44` ≠ `0x54`; also has fully-ready skip that angVel lacks |
| 3 | Sets **linear** vel / impulse (`0x40d260`) | Soft-teleport table skim | **Falsified** — slot `0x44` ≠ `0x50` |
| 4 | **Always** pushes rot to body (like angVel helpers) | Miss second gate | **Falsified** — if `phys+0x40≠0` **and** `phys+0x08≠0`, body call is skipped |
| 5 | Second gate is “and” for call (must be ready) | Polarity flip | **Falsified** — call when **not** fully ready: `+0x40==0` **OR** `+0x08==0` |
| 6 | Decompiler `FUN_005070b0((int)&uStack_4+3)` invents wrong `this` | Stack artifact | **Falsified as behavior change** — asm keeps ECX=`this`; out-byte is stack temp |
| 7 | Null body is safe no-op | Defensive port | **Falsified** — no test of `phys+0x3c` on dispatch path |
| 8 | Always prepares (`5070d0`) | Skip first gate | **Falsified** — only when probe out==0 **and** `+0x44≠0` |
| 9 | Sole caller is camera ApplyLookOffset | Camera-centric naming | **Falsified** — 11 xrefs; network soft, airStab, respawn, AI, … |
| 10 | Scaffold clean “recursive FUN_00404dc0 / FUN_005070*” misread | Auto plate | **Falsified** — body is leaf phys forwarder; callees are ready helpers + body vtbl |
| 11 | Name `SetRotation` is string-proven | Symbol inflation | **Not sealed** — **Probable** from usage + networkApply table; Ghidra still `FUN_00404dc0` |
| 12 | networkApply table “no ready gate” for angVel applies here | Table row conflation | **N/A for this VA** — this body **has** fully-ready skip; angVel row was about a different helper |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| body `+0x3c` / vtbl **+0x44** | **High** | Wrong pose axis (rot vs pos) |
| Fully-ready skip (`+0x40` / `+0x08`) | **High** | Fighting live sim while “ready” / dropped soft snaps |
| Ready probe + optional prepare | **High** | Dropped / double-init |
| Sibling +0x40 position | **High** | Port swaps pos/rot |
| Contrast: angVel always-dispatch | **High** | Wrong port of soft teleport family |
| Caller list completeness (11) | **High** | Miss respawn / camera / net |
| Havok English method name | **Medium** | Doc only |
| `+0x44` / `+0x29` type names | **Low–Med** | Naming only |
| Quat vs matrix consumer | **Medium** | Layout; callers suggest quat f4 |

---

## 3. Cross-check against raw

```text
// raw aa_00404dc0 ≡ live decompile 2026-07-29
probe = FUN_005070b0(this, &out);   // decompiler form messy; asm thiscall
if (*out == 0 && *(this+0x44) != 0)
    FUN_005070d0(this);
if (*(this+0x40) == 0 || *(this+0x08) == 0) {
    body = *(this+0x3c);
    (*body->vtbl)[+0x44](rot);      // FF 52 44
}
// else fully ready: return without body call
```

Sibling raw `aa_0040d2a0`: identical except `+0x40` (position).  
Contrast `aa_0040d040`: ready prepare only; **no** fully-ready skip; slot `+0x54`.

---

## 4. Surviving contract for AutoCore

```
CVOGPhysics_SetRotation(phys, rotPtr):
  // readiness (same first stage as SetPosition / ApplyImpulse / SetAngVel)
  out = ready_flag(phys)          // via FUN_005070b0: 0 if +0x44 null else *(*(phys+0x44)+0x29)
  if out==0 && phys.field_44 != null:
      FUN_005070d0(phys)          // prepare / attach path

  // fully-ready skip (shared with SetPosition; NOT with SetAngVel / ApplyImpulse)
  if phys.byte_40 != 0 && phys.field_08 != 0:
      return                      // do not touch body

  body = phys.rigidBody (+0x3c)   // NO null check
  body->setRotation(rotPtr)       // vtbl +0x44

// Sibling:
//   FUN_0040d2a0 setPosition → vtbl +0x40, same dual gates
// Contrast:
//   CVOGPhysics_SetAngularVelocity → vtbl +0x54, no fully-ready skip
//   CVOGPhysics_ApplyImpulseVector → vtbl +0x50, no fully-ready skip

// Known consumers of rotPtr:
//   network soft FUN_0053eec0: net rot on large pos error (soft path only when not fully ready at caller too)
//   airStab cleanup / orientation
//   Client_Camera_ApplyLookOffset
//   ClientSpecialEvent_Respawn_Update
//   AI / creature pose paths
```

**Port tests that matter:**

* Must **not** call vtbl+0x40 / +0x50 / +0x54 (those are pos / lin / ang siblings).
* Must skip body call when `phys+0x40≠0` **and** `phys+0x08≠0`.
* Must run ready prepare only on (out==0 && +0x44≠0).
* Must not write pos/vel/ω fields itself.
* Null `phys+0x3c` on dispatch path may fault — silent-return ports diverge from retail CF.

---

## 5. Open questions

1. Confirm Havok method identity for vtbl+0x44 (RTTI / vtable dump).
2. `phys+0x44` object type and `+0x29` flag producers.
3. Whether any caller packs matrix or non-unit quat without pre-normalize.
4. Runtime CE force of fully-ready skip under network soft teleport vs hard visual-only path.
5. Orphan site `0x009587d8` function boundary rename if product symbol appears.

**Verdict:** **accept-with-gaps** — adversarial attacks on pos/lin/ang confusion and “always dispatch” **fail**; remaining gaps are naming/types/runtime only.
