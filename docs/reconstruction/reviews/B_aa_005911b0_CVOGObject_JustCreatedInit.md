# Review B (skeptical / adversarial): `CVOGObject_JustCreatedInit` / `FUN_005911b0` @ `0x005911b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005911b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005911b0_CVOGObject_JustCreatedInit.md` |
| **Verdict** | **accept-with-gaps** on phase/ABI/gates; **reject** overclaims of skybox-only role or full bit-exact physics seal |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function is only skybox particle helper | **Falsified** — root `"Just created"`; ragdoll/rigidbody/addEntity phases dominate size |
| 2 | Always creates rigidbody | **Falsified** — early latches + flag gates can skip to ret 1/0 |
| 3 | `__cdecl` / no stack cleanup | **Falsified** — epilogue **`ret 4`** (`C2 04 00`) |
| 4 | Returns void | **Falsified** — `mov al,1` / early `return 0` |
| 5 | Mode ignored | **Falsified** — mode0 enables soft-skip abort; batch uses 1 |
| 6 | Done-latch at wrong offset | **Falsified** — `param_1[0x244]` as int* = byte `@+0x910`; batch ORs same |
| 7 | Scaffold name `Named_SkyBoxParticles` is canonical | **Overstated** — string is phase-local log only |
| 8 | Full multi-RB math dual-sealed | **Open** — decomp present; not byte-audited line-by-line this dual |
| 9 | Server-authoritative spawn | **Falsified** — client object finalize (gfx/RB); not sector packet handler |
| 10 | Product class name sealed | **Open** — structural `CVOGObject_*` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + ret 4 | **Confirmed** | Stack smash in ports |
| Return 1/0 contract | **Confirmed** | Tick hangs or double-init |
| Latch `@+0x910 bit0` | **Confirmed** | Re-entry re-builds RB |
| Phase string map | **Confirmed** | Mis-attribution |
| Soft-skip condition exact bits | **High** (decomp) / not byte-proved | Rare tick defer bugs |
| Nested physics constants | **Medium** | Gameplay drift if ported without further duals |
| Product English | **Open** | Docs |

---

## 3. Surviving contract for AutoCore

```
// __thiscall; ret 4
u32 CVOGObject_JustCreatedInit(Object* self, char mode):
  profile "Just created"
  if (self->flags910 & 1): return 1
  if (mode == 0 && soft_skip(self)): helper_abort(self); return 0
  copy pending position → active
  if gfx: apply pose/rot (optional random); skybox; optional FX once
  optional scale
  if ragdoll once: load or error log
  if rigidbody path: build RB(s); addEntity
  return 1

// Call sites:
//   batch FUN_00594290(mode=1) then flags910 |= 1
//   tick  FUN_00595230(mode=0); if 0: abort frame work
//
// NOT: skybox-only. NOT: server spawn packet. NOT: pure ctor.
```

---

## 4. Falsification notes

### 4.1 Skybox-only naming

Scaffold pulled `"SkyBoxParticles"` string. That string is a **conditional log** inside one nested phase. Root profiler and majority of callees are pose/RB.

### 4.2 “Always success”

Tick path can return **0** after `FUN_004a7a20`. Ports that ignore return break deferred create.

### 4.3 Claiming bit-exact RB math sealed

This dual seals **phase structure and ABI**. Nested builders (`FUN_00590cb0`, `FUN_0058fd30`, …) remain OWN residual unless separately dualed.

### 4.4 Server port temptation

Do not port wholesale into sector simulation without a server-side equivalent dual — this path talks client gfx vtables and local RB hosts.

---

## 5. Open questions

1. Exact product class / vtable id of `this`.
2. Full soft flag bit dictionary.
3. Whether batch pass is the only mode=1 caller forever (xrefs: 2 today).
4. Runtime multi-RB golden.

**Verdict:** **accept-with-gaps** — sealed Just-created phase contract, ABI, latch, mode, returns. Reject skybox-only / always-RB / full nested bit-exact overclaims.
