# Review A (reconstruction fidelity): `aa_004ba740` Object_CopyVec4At108_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ba740` |
| **VA** | `0x004ba740` |
| **Body span** | `004ba740` – `004ba764` (leaf; `ret 4`) |
| **Canonical name** | `Object_CopyVec4At108_Inferred` |
| **Ghidra name** | `FUN_004ba740` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B seal — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_004ba740_Object_CopyVec4At108_Inferred.md` |
| **System** | client special-FX / object transform leaf (weapon–FX host chain) |
| **Dual status** | **Present (first dual A/B)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pure **`__thiscall` leaf**: copy four dwords from **`this+0x108 .. this+0x114`** into caller-provided out buffer.

```c
// this in ECX; out on stack; stdcall-ish thiscall cleanup ret 4
void __thiscall Object_CopyVec4At108_Inferred(void *this, uint32_t out[4]);
// semantic: out[0..3] = *(uint32_t*)(this + 0x108 + 4*i)
```

No branches, no callees, no globals. Role is a **vec4 / float4 field dump** at fixed offset `0x108` (likely local position / orient pack or similar — product field name open).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004ba740_FUN_004ba740.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_004ba740_FUN_004ba740.annotated.md` | Scaffold still valid CF |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004ba740.cpp` | CF ≡ raw |
| Named alias clean | `reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_004ba740.cpp` | Parent-seed rename only |
| Function record | `docs/reconstruction/functions/aa_004ba740_FUN_004ba740.md` | Scaffold |
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x004ba740` | **≡ raw** |
| Live `read_memory` | body @ `0x004ba740` length 48 | Instruction seal |
| Callers | `get_function_callers` / xrefs (6 sites) | `FUN_004b7e50`, `FUN_005cd3b0`, `FUN_005da0a0` |

**Not performed:** Launcher, runtime golden, bit-exact binary diff. **No ledgers.**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`: `this` in **ECX** | **High** | `add ecx, 0x108`; `ret 4` |
| One stack arg: `out*` at `[esp+4]` | **High** | Entry `mov eax,[esp+4]` |
| Source base **`this+0x108`** | **High** | `81 C1 08 01 00 00` |
| Copies **4× dword** contiguous | **High** | stores out[0..3] from [ecx],[ecx+4],[ecx+8],[ecx+0xc] after add |
| Dest offsets **0x108, 0x10c, 0x110, 0x114** | **High** | decompile + bytes |
| Leaf / no callees / no branches | **High** | analyze: callees=[], single straight path |
| Types are float4 vs int4 vs mixed | **Tentative** | dword copy only; float use at callers **Probable** (FX/pos path) |
| Product English name | **Probable** (`_Inferred`) | No string/RTTI |
| Field is “world position” specifically | **Tentative** | Offset sealed; semantic open |

---

## 4. Control flow: clean ≡ raw ≡ live decompile

| Stage | Match |
|---|---|
| Load out* from stack | **Yes** |
| Advance this by `0x108` | **Yes** |
| Copy 4 dwords to out | **Yes** |
| `ret 4` | **Yes** |
| No invent normalize / transform / thiscall-free | **Yes** |

### 4.1 Live decompile (2026-07-29)

```c
void __thiscall FUN_004ba740(int param_1, undefined4 *param_2)
{
  *param_2     = *(undefined4 *)(param_1 + 0x108);
  param_2[1]   = *(undefined4 *)(param_1 + 0x10c);
  param_2[2]   = *(undefined4 *)(param_1 + 0x110);
  param_2[3]   = *(undefined4 *)(param_1 + 0x114);
  return;
}
```

### 4.2 Instruction seal (`read_memory` this pass)

```text
8B 44 24 04          mov  eax, [esp+4]       ; out*
81 C1 08 01 00 00    add  ecx, 0x108         ; this += 0x108
56                   push esi
8B 31                mov  esi, [ecx]
8B D0                mov  edx, eax
89 32                mov  [edx], esi         ; out[0]
8B 71 04             mov  esi, [ecx+4]
89 72 04             mov  [edx+4], esi       ; out[1]
8B 71 08             mov  esi, [ecx+8]
89 72 08             mov  [edx+8], esi       ; out[2]
8B 49 0C             mov  ecx, [ecx+0xC]
89 4A 0C             mov  [edx+0xC], ecx     ; out[3]
5E                   pop  esi
C2 04 00             ret  4
```

Hex prefix: `8b44240481c108010000568b318bd089328b71048972048b71088972088b490c894a0c5ec20400`

---

## 5. Callers (live xrefs, 6 sites / 3 functions)

| Call site | Function | Role |
|---|---|---|
| `0x004b7fa0` | `FUN_004b7e50` | FX host process list — pulls vec4 from object |
| `0x005cdfd8`, `0x005ce287` | `FUN_005cd3b0` | (2 sites) |
| `0x005daa00`, `0x005daa47`, `0x005db65d` | `FUN_005da0a0` | (3 sites) |

Parent dual on `aa_004b7e50` lists this as a callee (position-related path). Named alias seeds from `Named_VOG_DEBUG_STOP` parent only — **not** exclusive role.

---

## 6. Gaps / open

1. Product field name at `+0x108` (pos / quat / color / custom pack).
2. English roles for `FUN_005cd3b0` / `FUN_005da0a0` call sites.
3. Whether W component is used as float vs pad.
4. Runtime / bit-exact not run.
5. Clean plate still `FUN_*` scaffold.

**Verdict:** **accept-with-gaps** — dual **ABI + offset + dword×4 CF** sealed; product field English open.
