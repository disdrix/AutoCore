# Review B (skeptical / adversarial): `aa_005cd3b0` CVOGHBAICreatureBase_DoMovement

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cd3b0` |
| **VA** | `0x005cd3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B **create** — W16-I) |
| **Counterpart** | `reviews/A_aa_005cd3b0_CVOGHBAICreatureBase_DoMovement.md` |
| **Evidence** | Adversarial re-read of raw + live decompile + prologue/epilogue/string/`read_memory` constants; callee list; DATA xrefs |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Function **is** `VOG_DEBUG_STOP` / debug-only | **Falsified** | Scope string `::DoMovement`; trap is one failure path |
| 2 | No physics writes (read-only AI) | **Falsified** | Multiple ApplyImpulse / SetPos / SetRot / SetAngVel / `004cb3e0` |
| 3 | Always gated through `FUN_004c3a40` for local pos | **Falsified** | Direct `FUN_004cb3e0` bypass (leaf dual already noted) |
| 4 | Direct-call utility (static helper) | **Falsified** | **0** CALL xrefs; **5** vtable DATA slots |
| 5 | Free function / no this | **Falsified** | `mov esi,ecx`; thiscall fields |
| 6 | Ignores dt | **Falsified** | `param_2` scales impulses / blends |
| 7 | Host entity is `this` itself | **Falsified** | host at `this[0x19]` / `+0x64` |
| 8 | Timer always required | **Falsified** | duration `this+0x34 == 0` skips timer gate |
| 9 | Product name unrecoverable | **Falsified** | ASCII at `0x009da8a8` pushed in prologue |
| 10 | Bit-exact every float temporary sealed | **Not sealed** | large residual stack; dual claims gate spine not every temp |
| 11 | Server-only movement | **Falsified** | client tick globals / client physics leaves |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product name + virtual dispatch | **High** | Mis-wire wrong method / drop vtable |
| Early-out spine | **High** | AI moves when should idle (or never) |
| Host offset `+0x64` | **High** | Mutate wrong object |
| Physics leaf fan-out | **High** | Port missing pose writers |
| Ungated `+0x240` write | **High** | “Always gated” pose myth |
| Flag English (`+0x304` family) | **Tentative** | Wrong state machine narrative |
| Full float math bit-exact | **Open** | Soft numeric drift in climb/impulse |
| All 5 vtable class owners | **Open** | Partial virtual map |

---

## 3. Cross-check spine (must match image + decompile)

```
DoMovement(self /*ECX*/, dt):
  SEH; scope("CVOGHBAICreatureBase::DoMovement")
  if self[+0x18] == 0: cleanup; return
  if duration=self[+0x34] != 0 and elapsed < duration: cleanup; return
  entity = self[+0x64]
  if entity flags/type reject: cleanup; return
  // pose sample, vertical tests, speed scale FUN_004c55e0
  // climb/ground branches:
  //   impulses / set angvel/rot/pos / optional vtbl anim
  //   optional FUN_004cb3e0(entity-or-related, localPos4)  // UNGATED
  //   optional TeleportTarget; terrain cast; lerp window 0x18ff
  // if NaN cascade: FUN_007a4480(0, "VOG_DEBUG_STOP")
  cleanup scope; return
```

Scaffold raw decompile shape ≡ live 2026-07-29 decompile. Prologue bytes seal **thiscall** + **product string**. Clean plate documents constants and offsets; body is decompiler-faithful (not modernized).

---

## 4. Surviving contract for AutoCore

```
CVOGHBAICreatureBase::DoMovement(self, dt)
  virtual HB creature movement tick
  mutates host entity pose/physics through known leaves
  may bypass gated SetLocalPosition4 and call store leaf directly
  NaN -> debug stop helper (not normal control flow)

Port rules:
  * Install on creature AI vtables (multiple derived slots share address)
  * Pass client dt; honor timer fields when duration != 0
  * Do not rename method after VOG_DEBUG_STOP
  * Do not assume local-pos writes always go through 004c3a40
```

**Port tests that matter (static):**

* Prologue pushes `0x009da8a8` string before scope enter.
* Null `self+0x18` → no physics callees.
* Path that reaches `004cb3e0` does so without requiring `004c3a40`.

---

## 5. Open questions

1. Complete flag dictionary for host `+0x304..+0x314` and AI `+0x96`.
2. Class names for each of the 5 vtable DATA sites.
3. Interaction with network soft apply (`FUN_0053eec0`) vs this local integrator.
4. Runtime capture of climb vs land transitions.
5. Whether any non-creature type reuses the same body pointer.

**Verdict:** **accept-with-gaps**. Adversarial attacks on debug-only naming, gated-only local pos, static-call ABI, and free-function shape **closed**. Residual float-stack bit-exact and full flag English remain open — acceptable for dual seal at **accept-with-gaps**, not package-complete.
