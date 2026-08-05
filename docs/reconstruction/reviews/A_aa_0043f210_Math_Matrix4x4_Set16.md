# Review A (reconstruction fidelity): `aa_0043f210` Math_Matrix4x4_Set16

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043f210` |
| **VA** | `0x0043f210` |
| **Body span** | `0043f210` – `0043f2df` |
| **Canonical name** | `Math_Matrix4x4_Set16` (**Inferred**) |
| **Ghidra name** | `FUN_0043f210` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W18-E) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0043f210_Math_Matrix4x4_Set16.md` |
| **System** | math / matrix |
| **Dual status** | **Present** |
| **Verdict** | **accept** |

---

## 1. Purpose

Materialize a **4×4 float matrix** into `float out[16]` (**ECX**) from **16 scalar stack floats**. Pure store — **no** FOV, aspect, near/far, or ortho span math.

| Input | Source |
|---|---|
| `out` | **ECX** |
| `m00..m33` | stack `[ebp+8]` … `[ebp+0x44]` (16 floats) |

Retail body: align frame → 16× `movss` spill → `rep movsd` (count 16) → `ret 0x40`.

Sibling at `0x0043f2e0` (`Math_MatrixOrthoOffCenterLH`) **computes** ortho projection. gfxView perspective mode **computes** scales then calls **this** unit to write the matrix.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_0043f210_*` |
| Fresh decompile | Ghidra @ `0x0043f210` |
| Bytes | `read_memory` 220 B — `mov edi,ecx`; `ret 0x40` |
| Callers | 4 xrefs via `get_function_xrefs` + `get_assembly_context` |
| Bounds | `get_function_by_address` → `0043f210`–`0043f2df` |

**Not performed:** Launcher, runtime golden, bit-exact image diff.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 16-float matrix store leaf | **Confirmed** | decompile + bytes |
| ECX = dest | **Confirmed** | `8B F9` |
| `ret 0x40` = 16 stack floats | **Confirmed** | epilogue |
| SSE `movss` + `rep movsd` path | **Confirmed** | `F3 0F 10/11`, `F3 A5` |
| Not perspective formula builder | **Confirmed** | no math; callers precompute |
| Used by gfxView perspective write | **High** | caller `FUN_0075b7f0` @ `0075bb45` |
| Product/PDB export name | **Open** | structural `Math_Matrix4x4_Set16` |
| Runtime / differential | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Spill 16 stack floats | Yes |
| Copy 16 dwords to ECX dest | Yes |
| `ret 0x40` | Yes |

### Recovered CF

```c
// void __thiscall Math_Matrix4x4_Set16(float* out /*ECX*/, float m00..m33 /*stack*/)
for (i = 0; i < 16; i++) out[i] = arg[i];
```

---

## 5. Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_0075b7f0` | `0x0075bb45` | gfxView projection matrix @ `view+0x50` |
| `FUN_004d10d0` | `0x004d126c` | matrix materialize |
| `FUN_004e9570` | `0x004e96d0` | matrix materialize |
| `FUN_004f9030` | `0x004f94fa` | local matrix materialize |

**4 xrefs.**

---

## 6. Gaps

1. Product/PDB English symbol.
2. Runtime / bit-exact / differential — open.
3. Full per-caller element order documentation (row-major assumed from D3D-style sites).

**Verdict:** **accept**
