# Review A (reconstruction fidelity): `aa_0048ed00` PalantirEnv_InitEffectTextures_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048ed00` |
| **VA** | `0x0048ed00`–`0x0048ed81` exclusive (**129 B** / `0x81`) |
| **Canonical name** | `PalantirEnv_InitEffectTextures_Inferred` |
| **Ghidra name** | `FUN_0048ed00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-R) |
| **Counterpart** | `reviews/B_aa_0048ed00_PalantirEnv_InitEffectTextures_Inferred.md` |
| **System** | client / Palantir env effect textures |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full body). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Env host method that creates/binds **two** effect-texture instances via `FUN_0096f0e0` (`effTexture.cpp`):

1. Full display dims (`device+0x80` / `+0x84`) → slot `env+0xDC`, related `env+0xD4`.
2. Half width/height on stack → slot `env+0xE0`, related null.

Format `0x15` (D3DFMT_A8R8G8B8), shared args `1`, `0x4011`, `0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-R) | `docs/reconstruction/raw/aa_0048ed00_FUN_0048ed00.md` |
| Annotated | `docs/reconstruction/raw/aa_0048ed00_FUN_0048ed00.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalantirEnv_InitEffectTextures_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048ed00.cpp` |
| Function records | `functions/aa_0048ed00_FUN_0048ed00.md`, `functions/aa_0048ed00_PalantirEnv_InitEffectTextures_Inferred.md` |
| Callee | `FUN_0096f0e0` → `effTexture.cpp` L0x57 fail string |
| Live | full body bytes; `LEA ECX,[ESI+0xDC]` / `+0xE0`; sole xref InitPhases |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=env*; bare RET; void
void __thiscall PalantirEnv_InitEffectTextures_Inferred(void *env);
```

| Formal | Source | Conf |
|---|---|---|
| env | ECX (`8B F1`); InitPhases `MOV ECX,ESI` | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
device = *(DAT_00d1f058 + 0x2c)
FUN_0096f0e0(this=env+0xDC, 0x15, device+0x80, 1, 0x4011, 0, env+0xD4)
halfW = *(device+0x80)/2; halfH = *(device+0x84)/2
FUN_0096f0e0(this=env+0xE0, 0x15, &halfDims, 1, 0x4011, 0, 0)
RET
```

| Stage | Match | Conf |
|---|---|---|
| Body 0x81 / bare RET / thiscall | **Yes** | **High** |
| Dual this-adjusts +0xDC / +0xE0 | **Yes** (bytes) | **High** |
| format 0x15; half dims | **Yes** | **High** |
| Sole caller InitPhases | **Yes** | **High** |
| Callee = texture create | **Yes** (`effTexture.cpp`) | **High** |

---

## 5. Gaps

- Product English for slots `+0xDC` / `+0xE0` / related `+0xD4` (ctor nested object at `+0xD4` from W31-P).
- Exact product enum for constant `0x4011`.
- Whether `FUN_0096f0e0` replaces prior instance (refcount path in callee suggests yes).
- Runtime / bit-exact / differential.

---

## 6. Verdict

CF/ABI/slots/format/half-dims/sole-caller sealed against full-body `read_memory` + decompile. Residual product slot English + `0x4011` → **accept-with-gaps**.
