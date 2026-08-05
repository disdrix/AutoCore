# Review B (skeptical / adversarial): `Env_ApplyFogShaderAndReflect_Inferred` / `FUN_005b36f0` @ `0x005b36f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b36f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-I) |
| **Counterpart** | `reviews/A_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/vtbl/fog pipeline; reject “dead code / no callers” and over-named RTTI class claims |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Zero xrefs ⇒ unreachable / dead | **Falsified** — **vtbl[1]** of `PTR_FUN_009d95a0` (`0x009d95a4`) |
| 2 | cdecl / plain ret | **Falsified** — thiscall + **`ret 4`** |
| 3 | Always applies fog | **Falsified** — gate on `+0x15c`/`e4f8`; work flag `+0x80` |
| 4 | Return void | **Falsified** — **0** / **-1** |
| 5 | Class **is** `CVOGEnvironmentReflect` because decompiler string label | **Overstated** — RTTI string at `00af3eb8`; flags at `+0x1d/+0x1e` are adjacent **static bytes**, not sealed class proof for *this* host |
| 6 | Packs color itself | **Falsified** — calls `FUN_00973820` (scale) → `FUN_00973590` (clamp) |
| 7 | Product field English for reflect block | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 + 0/-1 returns | **Confirmed** | stack/return contract breaks |
| vtbl[1] ownership | **Confirmed** | “unused” mis-prioritization |
| Fog string → shader bind CF | **Confirmed** | wrong subsystem port |
| `this+0x164` fog block layout | **High** | wrong constant offsets |
| Product class name | **Open** | docs only |
| Reflect math product meaning | **Medium** | wrong light/env semantics |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + bytes

```
if (!ctx || !ctx->e4f8) return -1;
if (flag80) {
  bind gFogEnable/Start/End/Color from this+0x164;
  Color_PackFloat4_Scale255(color@+0x60);
  refresh *(this+0x158)+8 vectors (+ dirty);
}
return 0;
```

Epilogue both paths: `C2 04 00`. Vtbl dword at `009d95a4` = `005b36f0`. Live decompile ≡ scaffold raw CF (2026-07-23).

---

## 4. Surviving contract for AutoCore

```
// thiscall, ret 4
int Env_ApplyFogShaderAndReflect(Host* self, uint32_t arg0):
  if missing ctx/e4f8: return -1
  if self->work_flag_80:
    push fog shader consts from self->shader_block_164
    pack fog color (via sealed Color_PackFloat4_Scale255)
    update env/reflect vectors under self->ptr_158
  return 0
```

Do **not** treat as dead. Do **not** invent `CVOGEnvironmentReflect::…` as sealed product plate. Do **not** reimplement color clamp here — reuse pack cluster. Do **not** drop the -1 gate.

---

## 5. Falsification notes

### 5.1 “No callers”

Ghidra function xrefs empty because dispatch is **data** via vtbl. Byte search + ctor/dtor install seal ownership.

### 5.2 “CVOGEnvironmentReflect method”

Decompiler indexes type-descriptor string for two bools. Image shows `.?AVCVOGEnvironmentReflect@@` then `01 01` — flags, not a demangled method plate on this body. Host class name remains open.

### 5.3 “Fog-only utility”

Body also dirties/writes reflect vectors and may call a vfunc — name must cover **both** fog bind and reflect update, not fog alone.

---

## 6. Open questions

1. Product host class / method name.
2. Nested duals of shader-bind helpers and `FUN_004cd220` / `FUN_005b39d0`.
3. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed virtual fog+reflect apply method. Reject dead-code and over-specific RTTI class claims.
