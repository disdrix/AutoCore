# Review B (skeptical / adversarial): `aa_0040d2a0` CVOGPhysics_SetPosition

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d2a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0040d2a0_CVOGPhysics_SetPosition.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Sets **rotation** (confuse with `0x404dc0`) | Slot mix-up | **Falsified** — imm **`0x40`**, not `0x44` |
| 2 | Sets **angular velocity** (confuse with `0x40d040`) | Family bundle | **Falsified** — slot `0x40` ≠ `0x54`; also has fully-ready skip that angVel lacks |
| 3 | Sets **linear** vel / impulse (`0x40d260`) | Soft-teleport table skim | **Falsified** — slot `0x40` ≠ `0x50` |
| 4 | **Always** pushes pos to body (like angVel helpers) | Miss second gate | **Falsified** — if `phys+0x40≠0` **and** `phys+0x08≠0`, body call is skipped |
| 5 | Second gate is “and” for call (must be ready) | Polarity flip | **Falsified** — call when **not** fully ready: `+0x40==0` **OR** `+0x08==0` |
| 6 | Decompiler `FUN_005070b0((int)&uStack_4+3)` invents wrong `this` | Stack artifact | **Falsified as behavior change** — asm keeps ECX=`this`; out-byte is stack temp |
| 7 | Null body is safe no-op | Defensive port | **Falsified** — no test of `phys+0x3c` on dispatch path |
| 8 | Always prepares (`5070d0`) | Skip first gate | **Falsified** — only when probe out==0 **and** `+0x44≠0` |
| 9 | Sole caller is network soft apply | Net-centric naming | **Falsified** — 9 caller funcs; activate, AI, vehicle helpers too |
| 10 | Scaffold “recursive FUN_0040d2a0” plate misread | Auto plate | **Falsified** — body is leaf phys forwarder; callees are ready helpers + body vtbl |
| 11 | Name `SetPosition` is string-proven | Symbol inflation | **Not sealed** — **Probable** from usage + networkApply table; Ghidra still `FUN_0040d2a0` |
| 12 | networkApply note that angVel “has no ready gate” applies here | Table row conflation | **N/A for this VA** — this body **has** fully-ready skip; angVel row was about a different helper |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| body `+0x3c` / vtbl **+0x40** | **High** | Wrong pose axis (pos vs rot) |
| Fully-ready skip (`+0x40` / `+0x08`) | **High** | Fighting live sim while “ready” / dropped soft snaps |
| Ready probe + optional prepare | **High** | Dropped / double-init |
| Sibling +0x44 rotation | **High** | Port swaps pos/rot |
| Contrast: angVel always-dispatch | **High** | Wrong port of soft teleport family |
| Caller list completeness (9) | **High** | Miss activate / AI / net |
| Havok English method name | **Medium** | Doc only |
| `+0x44` / `+0x29` type names | **Low–Med** | Naming only |
| f3 vs f4 consumer | **Medium** | Layout; callers suggest f4 |

---

## 3. Cross-check against raw

```text
// raw aa_0040d2a0 ≡ live decompile 2026-07-29
probe = FUN_005070b0(this, &out);   // decompiler form messy; asm thiscall
if (*out == 0 && *(this+0x44) != 0)
    FUN_005070d0(this);
if (*(this+0x40) == 0 || *(this+0x08) == 0) {
    body = *(this+0x3c);
    (*body->vtbl)[+0x40](pos);      // FF 52 40
}
// else fully ready: return without body call
```

Sibling raw `aa_00404dc0`: identical except `+0x44` (rotation).  
Contrast `aa_0040d040`: ready prepare only; **no** fully-ready skip; slot `+0x54`.

---

## 4. Surviving contract for AutoCore

```
CVOGPhysics_SetPosition(phys, posPtr):
  // readiness (same first stage as SetRotation / ApplyImpulse / SetAngVel)
  out = ready_flag(phys)          // via FUN_005070b0: 0 if +0x44 null else *(*(phys+0x44)+0x29)
  if out==0 && phys.field_44 != null:
      FUN_005070d0(phys)          // prepare / attach path

  // fully-ready skip (shared with SetRotation; NOT with SetAngVel / ApplyImpulse)
  if phys.byte_40 != 0 && phys.field_08 != 0:
      return                      // do not touch body

  body = phys.rigidBody (+0x3c)   // NO null check
  body->setPosition(posPtr)       // vtbl +0x40

// Sibling:
//   CVOGPhysics_SetRotation → vtbl +0x44 (same dual gates)
// Contrast:
//   SetAngularVelocity → vtbl +0x54 (ready prepare only; always dispatch)
//   ApplyImpulseVector → vtbl +0x50 (ready prepare only; always dispatch)
```

**Port tests that matter:**

* Must **not** call vtbl+0x44/0x50/0x54 (those are siblings).
* Must skip body write when fully ready (`+0x40≠0 && +0x08≠0`).
* Must run ready prepare only on (out==0 && +0x44≠0).
* Null `phys+0x3c` may fault — ports that silent-return diverge from retail CF.

---

## 5. Open questions

1. Confirm Havok method identity for vtbl+0x40 (RTTI / vtable dump).
2. `phys+0x44` object type and `+0x29` flag producers.
3. Whether any caller packs only xyz (w undefined) vs full f4.
4. Runtime CE force of ready flag under network soft path (policy-open).

**Verdict:** **accept-with-gaps** — adversarial attacks on pos/rot/lin/ang confusion and “always dispatch” **fail**; remaining gaps are naming/types/runtime only.
