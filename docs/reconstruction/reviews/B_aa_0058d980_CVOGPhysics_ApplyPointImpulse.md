# Review B (skeptical / adversarial): `aa_0058d980` CVOGPhysics_ApplyPointImpulse

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d980` |
| **VA** | `0x0058d980` |
| **Canonical name** | `CVOGPhysics_ApplyPointImpulse` (inferred) |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0058d980_CVOGPhysics_ApplyPointImpulse.md` |
| **System** | `physics` / `CVOGPhysics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `ApplyImpulseVector` (COM linear only) | Confuse with `0x0040d260` | **Falsified** — slot imm **`0x60`**, **two** args, `ret 8` |
| 2 | Set angular / linear velocity | Bundle with +0x50/+0x54 helpers | **Falsified** — different imm; two-arg shape |
| 3 | Set position / rotation | Soft-teleport family | **Falsified** — no +0x40/+0x44; always dispatches |
| 4 | No readiness gate | “thin vtbl forward only” | **Falsified** — same `5070b0`/`5070d0` gate as siblings |
| 5 | Always calls `PrepareReady` | Skip gate | **Falsified** — only when out==0 **and** `+0x44≠0` |
| 6 | Decompiler `FUN_005070b0((int)&uStack_4+3)` invents wrong `this` | Stack artifact | **Falsified as behavior change** — asm keeps ECX=`phys`; out-byte is stack temp |
| 7 | Null body is safe no-op | Defensive port | **Falsified** — no test of `phys+0x3c` |
| 8 | One stack argument (`ret 4`) | Sibling habit | **Falsified** — `C2 08 00` |
| 9 | Name `ApplyPointImpulse` is string-proven in this VA | Symbol inflation | **Not sealed** — **High** prior-art English only; Ghidra still `FUN_0058d980` |
| 10 | Math / scale / clamp impulse | Overfit susp force path | **Falsified** — pure forward; scaling is caller-owned |
| 11 | Exclusive postTick wrapper | Assume sole entry to +0x60 | **Falsified as exclusive** — prior art shows **inline** `+0x60` from chassis paths too |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| body `+0x3c` / vtbl **+0x60** | **Confirmed** | Wrong force model (COM vs point) |
| Two formals / `ret 8` | **Confirmed** | Stack imbalance on ported callers |
| Ready probe + optional prepare | **Confirmed** | Dropped attach / double-init |
| Sibling gate parity | **Confirmed** | Inconsistent write path |
| applyPointImpulse English | **High** (docs) / product **Open** | Doc-only mismatch |
| Impulse / point layouts | **Open** | Wrong pack size / contact slot |
| Caller completeness | **Open** | Miss debug / AI / mission paths |
| `+0x44` / `+0x29` type names | **Low–Med** | Naming only |

---

## 3. Cross-check against raw / live / bytes

```text
raw aa_0058d980 ≡ live decompile 2026-07-29 (W16-B)
read_memory @ 0x0058d980:
  call FUN_005070b0 / conditional FUN_005070d0
  mov ecx, [esi+0x3c]
  call dword ptr [edx+0x60]    ; FF 52 60
  ret 8                        ; C2 08 00
callees: ProbeReadyFlag, PrepareReady, indirect +0x60
```

### Arity trap

Do **not** model this as a one-arg COM impulse twin of `0x0040d260`. Bytes end in **`ret 8`** and push **two** pointers.

### Slot trap

Do **not** confuse method slot **`+0x60`** with rigid-body **field** offsets near `+0x50..5c` (angVel storage). Method table ≠ field map.

### Inline vs wrapper trap

Suspension/postTick may call body `+0x60` **inline** without this helper. Porting only this VA does not capture all point-impulse sites.

### Decompiler trap

`FUN_005070b0((int)&uStack_4+3)` is **not** a third logical argument to the point-impulse API — it is the ready out-byte address.

---

## 4. Surviving contract for AutoCore

```
CVOGPhysics_ApplyPointImpulse(phys, impulseVec, pointObj):
  // readiness (same as ApplyImpulseVector / SetAngularVelocity)
  out = ready_flag(phys)          // via FUN_005070b0
  if out==0 && phys.field_44 != null:
      FUN_005070d0(phys)          // prepare / attach path
  body = phys.rigidBody (+0x3c)   // NO null check
  body->applyPointImpulse(impulseVec, pointObj)   // vtbl +0x60

// Sibling one-arg body writes (ret 4):
//   ApplyImpulseVector     → vtbl +0x50
//   SetAngularVelocity     → vtbl +0x54
//   ApplyVector_Vtbl5c     → vtbl +0x5c

AutoCore must NOT:
  - model ret 4 / single vector formal for this VA
  - swap with +0x50 COM impulse without a point
  - invent clamp/scale math inside this VA
  - assume null body is a no-op
  - claim product Havok symbol without string/RTTI
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| CF clean ≡ raw ≡ live | **Agree Confirmed** |
| vtbl imm +0x60 | **Agree Confirmed** |
| ret 8 / two stack args | **Agree Confirmed** |
| Ready gate identical to siblings | **Agree Confirmed** |
| applyPointImpulse English | **Agree High** prior art; product string **Open** |
| accept-with-gaps | **Agree** |
| Caller inventory complete | **Disagree as sealed** — leave **Open** under OWN-ONLY |

Naming: registry name `CVOGPhysics_ApplyPointImpulse` is fine as **inferred** structural English matching suspension prior art. Do not promote a demangled product symbol without evidence.

---

## 6. Open questions

1. Runtime capture of a known applyPointImpulse call (impulse + contact).
2. Point-arg type recovery via a parent dual (wheel struct vs world point).
3. Bit-exact vs retail image.
4. Whether all chassis `+0x60` sites should share one helper API in the port.

**Verdict:** **accept-with-gaps** — agree with A; block one-arg/`ret 4` conflation, COM-only impulse merge, and invented product symbols.
