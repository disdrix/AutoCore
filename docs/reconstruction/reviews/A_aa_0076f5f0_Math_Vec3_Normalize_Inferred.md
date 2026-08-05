# Review A (reconstruction fidelity): `aa_0076f5f0` Math_Vec3_Normalize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076f5f0` |
| **VA** | `0x0076f5f0` |
| **Canonical name (Ghidra)** | `FUN_0076f5f0` |
| **Proposed name** | `Math_Vec3_Normalize_Inferred` (**High** role; product name open) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_0076f5f0_Math_Vec3_Normalize_Inferred.md` |
| **System** | math / graphics vec3 |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Normalize a 3-float vector** into a destination buffer: `out = src / |src|` when length is outside the near-zero epsilon band; otherwise **return `out` unchanged** (no write, avoids div-by-zero).

Used heavily by camera unproject, special-event teleports, physics/gfx direction setup (50+ callers).

### Control flow (summary)

1. `len = sqrt(src.x² + src.y² + src.z²)`.
2. If `len < eps` **and** `-eps < len` where `eps = 1e-6` (`_DAT_00a240ec`) and `-eps = DAT_00aaa640`:
   * **return `out` without stores** (degenerate / near-zero).
3. Else `inv = 1.0 / len` (`g_flOne / len`):
   * `out.x = src.x * inv`
   * `out.y = src.y * inv`
   * `out.z = src.z * inv`
4. Return `out`.

**Not** in-place-only (dest and src are separate formals; may alias at call site). **Not** mat4. **Not** safe-normalize to fixed default axis (leaves dest stale).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0076f5f0` |
| Entry bytes | `read_memory` @ `0x0076f5f0` — `mov ecx,[esp+8]`; x87 `fld` xyz; `fsqrt`; compare `_DAT_00a240ec` / `DAT_00aaa640` |
| Constants | `read_memory` `0x00a240ec` → LE `bd378635` = **+1e-6**; `0x00aaa640` → LE `bd3786b5` = **-1e-6** |
| Callers | `get_function_callers` — unproject `0075c340`, teleport ctors, broad gfx list |
| Prior dual cite | `A_aa_0075c340_*` names this **Normalize** |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0076f5f0` |
| Function record | `docs/reconstruction/functions/aa_0076f5f0_FUN_0076f5f0.md` |

**This pass:** live decompile; constants; callers sample. **Not performed:** Launcher, ledgers, NaN golden.

---

## 3. Signature

```c
// __cdecl (stack): param_1 = out, param_2 = src
float * Math_Vec3_Normalize_Inferred(float out[3], const float src[3]);
// returns out
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `SQRT` / x87 `fsqrt` | Length |
| globals | `g_flOne`, `_DAT_00a240ec`, `DAT_00aaa640` |

| Caller (sample) | Role |
|---|---|
| `GfxView_UnprojectScreenToWorldRay_Inferred` `0x0075c340` | Perspective ray dir |
| `ClientSpecialEvent_TeleportIn/Out_ctor` | Basis floats |
| Many gfx/phys sites | Direction unitize |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Length from xyz sum-of-squares + sqrt | Yes |
| Near-zero band early return (no store) | Yes |
| `inv = 1/len`; scale xyz into out | Yes |
| Return out pointer | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = vec3 normalize copy | **Confirmed** | body |
| eps = ±1e-6 constants | **Confirmed** | `read_memory` |
| Degenerate: leave out untouched | **Confirmed** | early return before stores |
| Two stack formals out/src | **Confirmed** | `mov ecx,[esp+8]` src |
| Product name | **Open** | structural |
| Safe default axis on failure | **Falsified** | no write |

---

## 7. Gaps / open

1. Product/PDB name.
2. Whether any caller relies on stale `out` on near-zero (contract risk).
3. SSE vs x87 path variants elsewhere.
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — math CF sealed High/Confirmed.
