# Review A (reconstruction fidelity): `aa_0040d020` Math_Vec3Length_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d020` |
| **VA** | `0x0040d020` |
| **Canonical name** | `Math_Vec3Length_Inferred` (inferred; product symbol unknown) |
| **Ghidra symbol** | `FUN_0040d020` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0040d020_Math_Vec3Length_Inferred.md` |
| **System** | interaction-activation (partition) / shared pure math |
| **Work item** | MEGA-137 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pure Euclidean **3-float length** leaf:

```text
length = sqrt(x*x + y*y + z*z)
```

No globals, no callees, no scale. Callers (pick-target distance, residual path distance) compute deltas and optionally scale the result **outside** this body. Partition demoted product “pick ray/dist scale” to **pure math** — sealed.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040d020_FUN_0040d020.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_0040d020_FUN_0040d020.annotated.md` | Refreshed |
| Clean (scaffold twin) | `docs/reconstruction/reconstructed-exact/FUN_0040d020.cpp` | Refreshed |
| Clean (named) | `docs/reconstruction/reconstructed-exact/Math_Vec3Length_Inferred.cpp` | Written |
| Retired scaffold | `Named_CalleeOf_Client_InteractClickPickTarget_0040d020.cpp` | Retired → named |
| Function records | `functions/aa_0040d020_FUN_*` + named | Written |
| Live decompile | Ghidra `decompile_function` `0x0040d020` | **≡ raw** |
| Live body bytes | Ghidra `read_memory` `0x0040d020` length 64 | CF sealed |
| Disasm | `disassemble_function` | 10 insns, 1 block |
| Complete analysis | `analyze_function_complete` | leaf, 3 xrefs, 0 callees |
| Callers / xrefs | `get_function_callers` / `get_xrefs_to` / `get_function_xrefs` | 3 sites / 2 funcs |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__cdecl`, three `float` stack args `@[esp+4/8/c]` | **High** | `FLD`/`FMUL` each slot; plain `ret` |
| Return in **ST0** as `float10` / x87 | **High** | `FSQRT` leaves ST0; no store |
| Formula `sqrt(x²+y²+z²)` | **High** | Three mul-self + two `FADDP` + `FSQRT` |
| Leaf (no callees / no CALL) | **High** | `analyze_function_complete` callees `[]` |
| Body `0x0040d020`–`0x0040d03e` (31 B) | **High** | disasm + next fn `0040d040` after `CC` |
| Callers: pick ×2 + `FUN_005ba440` ×1 | **High** | 3 UNCONDITIONAL_CALL xrefs |
| Pick uses result as distance then `*0.015f` | **High** (caller) | scale `@0x00aaacbc` outside OWN |
| Name product-official | **Tentative** | `_Inferred`; Ghidra still `FUN_0040d020` |
| NaN / −0 / denormal edges | **Tentative** | static only |
| Bit-for-bit / runtime harness | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| Load `x`, square | Yes (`FLD [esp+4]` / `FMUL [esp+4]`) |
| Load `y`, square, add | Yes (`FLD`/`FMUL`/`FADDP`) |
| Load `z`, square, add | Yes (`FLD`/`FMUL`/`FADDP`) |
| `FSQRT` → `RET` | Yes |
| No invent normalize / 2D / squared-length / scale | Yes — scale is caller-side |

### Instruction seal (`read_memory` + `disassemble_function` 2026-08-05)

```text
0040d020  D9 44 24 04          FLD   dword [esp+0x4]     ; x
0040d024  D8 4C 24 04          FMUL  dword [esp+0x4]     ; x*x
0040d028  D9 44 24 08          FLD   dword [esp+0x8]     ; y
0040d02c  D8 4C 24 08          FMUL  dword [esp+0x8]     ; y*y
0040d030  DE C1                FADDP                     ; x*x + y*y
0040d032  D9 44 24 0C          FLD   dword [esp+0xc]     ; z
0040d036  D8 4C 24 0C          FMUL  dword [esp+0xc]     ; z*z
0040d03a  DE C1                FADDP                     ; sum
0040d03c  D9 FA                FSQRT
0040d03e  C3                   RET
; pad
0040d03f  CC                   INT3
```

Body size **0x1F** bytes (`0x0040d020`–`0x0040d03e` inclusive).

Hex: `d9442404d84c2404d9442408d84c2408dec1d944240cd84c240cdec1d9fac3`

### Recovered CF

```c
// __cdecl — stack: x, y, z; return length in ST0
float Math_Vec3Length_Inferred(float x, float y, float z)
{
    return sqrtf(x * x + y * y + z * z);  // x87 FSQRT path in retail
}
```

---

## 5. Callers (inventory only; not dualled)

| Site | Function | Evidence |
|---|---|---|
| `0x009249c0` | `Client_InteractClickPickTarget` | decompile: `FUN_0040d020(hit−cam)` then `* _DAT_00aaacbc` |
| `0x00924c76` | `Client_InteractClickPickTarget` | same second path |
| `0x005bad63` | `FUN_005ba440` | decompile: `FUN_0040d020(piVar9[2..4]−param_1[0x41..0x43])` |

---

## 6. Gaps

| Gap | Status |
|---|---|
| Product / PDB name | Open (`_Inferred`) |
| IEEE edge cases | Open (static) |
| Full English of `FUN_005ba440` | Out of OWN VA |
| Runtime / differential | Deferred |

---

## 7. Verdict rationale

**accept-with-gaps:** CF, ABI, body range, leaf nature, and xref inventory are sealed against live Ghidra. Product name and runtime remain open; scaffold name retired. No CF invent or scale-merge into the leaf.
