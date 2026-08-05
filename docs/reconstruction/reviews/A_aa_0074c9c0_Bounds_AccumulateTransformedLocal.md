# Review A (reconstruction fidelity): `aa_0074c9c0` Bounds_AccumulateTransformedLocal

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074c9c0` |
| **VA** | `0x0074c9c0`–`0x0074ce55` |
| **Canonical name** | `Bounds_AccumulateTransformedLocal` |
| **Prior scaffold** | `FUN_0074c9c0` |
| **Review date** | `2026-07-29` (W21-O OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_0074c9c0_Bounds_AccumulateTransformedLocal.md` |
| **System** | graphics / bounds |
| **Verdict** | **accept-with-gaps** — ABI, gate, sphere merge, 8-corner AABB, 0.5f, ret 12 sealed; product English + `FUN_0044b5c0` dual open |

**Tools:** Ghidra `decompile_function` + `read_memory` (entry + epilogue + `DAT_00a0f298`). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Transform a **local** sphere+AABB volume into a reference object's space, **scale** its radius by relative object scales, and **merge** into a **destination** bounds object held in **ECX**:

1. Early-out if `local[+0x2c] != 0`.
2. Build/fetch matrix (`FUN_0044b5c0`).
3. Project local center (`FUN_0076f6e0`).
4. Compute world radius (uniform X ratio or full scale-length ratio).
5. Merge spheres (empty / contain / expand with mid-factor **0.5**).
6. Project 8 local-AABB corners; expand dest AABB (with sphere window clamps).
7. Clear dest gate; write XZ extent at `+0x10`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0074c9c0_FUN_0074c9c0.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0074c9c0_FUN_0074c9c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Bounds_AccumulateTransformedLocal.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0074c9c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074c9c0_Bounds_AccumulateTransformedLocal.md` |
| Live decompile | `decompile_function` `0x0074c9c0` — CF ≡ raw |
| Live bytes | entry `55 8b ec…80 7e 2c 00…89 4c 24 24`; epilogue `c6 47 2c 00…c2 0c 00` |
| Constant | `read_memory` `0x00a0f298` → `00 00 00 3f` = **0.5f** |
| Call site | `read_memory` near `0x004bdb20` — `lea ecx,[edi+0x414]; push DAT; call` |
| Callees | `get_function_callees` → `FUN_0044b5c0`, `FUN_0076f6e0` |
| Xrefs | multi mesh + special-event callers |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Dest in **ECX** | entry `mov [esp+0x24],ecx`; call sites `lea ecx,[…+0x414]`; writeback via restored EDI |
| stack0 xformRef | `[ebp+8]`; often `&DAT_00d1eb60` |
| stack1 local bounds | `[ebp+0xc]` → ESI; gate at `+0x2c` |
| stack2 scaleSrc | `[ebp+0x10]` |
| Epilogue | **`ret 12`** (`c2 0c 00`) |
| Body range | `0074c9c0`–`0074ce55` |

```c
void Bounds_AccumulateTransformedLocal(
    BoundsVolume *dest /*ECX*/,
    void *xformRef, BoundsVolume *local, void *scaleSrc);
// ret 12
```

### 3.2 BoundsVolume map — **SEALED**

| Rel | Role | Conf |
|---:|---|---|
| `+0x00..+0x08` | sphere center | **High** |
| `+0x0c` | radius | **High** |
| `+0x10` | XZ extent metric (dest) | **High** |
| `+0x14..+0x1c` | AABB min | **High** |
| `+0x20..+0x28` | AABB max | **High** |
| `+0x2c` | gate byte | **High** |

### 3.3 Scale path — **SEALED**

| Condition | Formula |
|---|---|
| both `+0xb8 == 0` | `(scaleSrc.sx / xformRef.sx) * local.r` |
| else | `\|scaleSrc\| * (local.r / \|xformRef\|)` using xyz at `+0x9c/+0xa0/+0xa4` |

### 3.4 Sphere merge — **SEALED**

| Case | Action |
|---|---|
| `dest.r == 0` | replace with world sphere |
| else | `rMerge = (dest.r + dist + worldR) * 0.5`; expand / replace / no-op per classic contain tests |

### 3.5 AABB loop — **SEALED**

- 8 iterations; corner axes from local min (`param_2+5`) / max (`param_2+8`) via bit selects.
- Each corner projected with `FUN_0076f6e0`.
- Dest min/max updated with sphere-window partners (`worldC ± worldR`).

### 3.6 Three-rep CF fidelity

| Pass | Match |
|---|---|
| Raw 2026-07-23 | baseline |
| Live re-decompile 2026-07-29 | **≡** CF |
| Bytes | gate, ret 12, 0.5f load site present |

---

## 4. Call graph (inventory)

| Direction | Symbol | VA | Note |
|---|---|---|---|
| Callee | `FUN_0044b5c0` | `0x0044b5c0` | matrix (not owned) |
| Callee | `FUN_0076f6e0` | `0x0076f6e0` | point project (dualed elsewhere) |
| Callee | SQRT/ABS/FPU | — | merge + metric |
| Data | `DAT_00a0f298` | `0x00a0f298` | 0.5f |
| Caller | mesh walks | `0x004bdb10` family | ECX=owner+0x414 |
| Caller | TeleportIn / Respawn | `0x00978d20` / `0x00979730` | attach glue |
| Caller | others | `0x007647c0`, `0x0096dc80`, … | multi-system |

---

## 5. Gaps / open

1. Product/PDB names for BoundsVolume / ObjectLike / this helper.
2. Full dual of `FUN_0044b5c0` (matrix blend; uses both objects).
3. Exact identity of `DAT_00d1eb60` (global xform/scale ref).
4. Bit-exact AABB float-select micro-order vs simplified min/max rewrite.
5. Runtime / differential — open.

---

## 6. Verdict

**accept-with-gaps** — machine ABI + core math CF dual-ready for AutoCore bounds port; residual product English and matrix-helper ownership.
