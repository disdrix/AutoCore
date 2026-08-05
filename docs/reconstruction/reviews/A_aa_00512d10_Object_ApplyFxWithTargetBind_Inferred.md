# Review A (reconstruction fidelity): `aa_00512d10` Object_ApplyFxWithTargetBind_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512d10` |
| **VA** | `0x00512d10` |
| **Body span** | `00512d10`–`00512ead` (**~413 B**) |
| **Canonical name** | `Object_ApplyFxWithTargetBind_Inferred` (structural **INFERRED**) |
| **Ghidra name** | `FUN_00512d10` |
| **Review date** | `2026-07-29` (W21-A dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md` |
| **System** | `client-fx` / skills-abilities |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs/callees (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Vtbl method** on many object classes that resolves/applies a special-FX instance, stamps flag bit **2**, optionally binds a target entity TFID + offset onto the FX, attaches via host **vtbl+0xf8**, then posts through `FUN_004b7e50`.

Two resolve paths:

1. **Full nfx apply** — `skipFullNfx==0` **and** resource subsystem live (`*(DAT_00d1f050+0x6c)!=0`) **and** no in-FX → `FxCache_ApplyWithNfxEnsure` (return its result).
2. **Light ensure** — otherwise, if no in-FX → `FxCache_EnsureMasterAndResolve(..., 1)`; null → return **0**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00512d10_FUN_00512d10.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_00512d10_FUN_00512d10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ApplyFxWithTargetBind_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_00512d10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md` |
| Related duals | `A_aa_00542790_*`, `A_aa_005408f0_*`, `A_aa_004b68c0_*` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Assembly-sealed claims (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Body through `ret 0x20` | epilogues `C2 20 00` × success/fail/full-apply | **Confirmed** |
| `__thiscall` this in ECX | `mov ebx, ecx` prologue | **Confirmed** |
| Gate `param_8` @ `[ebp+0x20]` | `cmp byte [ebp+0x20],0` | **Confirmed** |
| Gate `DAT_00d1f050+0x6c` | `mov eax,[d1f050]; cmp [eax+0x6c],0` | **Confirmed** |
| `*fx \|= 2` | `or dword [esi], 2` | **Confirmed** |
| `DAT_00aaa5dc` = `2^32` float | bytes `00 00 80 4F` | **Confirmed** |
| Full-apply host `DAT_00b041fc` | tail `mov ecx,[b041fc]; call 00542790` | **Confirmed** |
| Live decompile ≡ raw CF | side-by-side | **Confirmed** |
| DATA xrefs only (vtbl slots) | `get_xrefs_to` 20+ DATA, no CALL callers | **Confirmed** |

### Entity TFID / offset (decompile High, pattern Confirmed)

| Item | Value |
|---|---|
| Direct TFID | `param_6[0x58..0x5b]` → bytes **`+0x160..+0x16c`** |
| Nested TFID | adj object `+0x164` |
| Offset float4 | `{0, 0, (float)u32(param_7), 0}` |
| Bind callee | `FUN_004b68c0` / `NDSpecialFX_SetTargetTfidAndOffset_Inferred` with **ECX=fx** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Dual resolve path + returns | **High** | decompile + epilogues |
| Role = apply FX + optional target bind | **High** | sealed callees |
| Flag bit 2 semantic name | **Open** | only OR observed |
| Product method English | **Open** | structural `_Inferred` |
| Nested vtbl+0xf8 full args | **Probable** | decompiler thin on else branch |
| `FUN_004b7e50` full semantics | **Open** | large sibling; zero-arg call sealed |
| Runtime | **Open** | |

---

## 5. Call graph (this unit)

**Callees:** `FxCache_ApplyWithNfxEnsure`, `FxCache_EnsureMasterAndResolve`, `NDSpecialFX_SetTargetTfidAndOffset_Inferred`, `FUN_004b7e50`, plus object vtbls `+0x19c` / `+0xf8`.

**Callers:** vtbl DATA installs only (no direct CALL).

---

## 6. Naming gate

| Candidate | Gate |
|---|---|
| `Object_ApplyFxWithTargetBind_Inferred` | Role **High**; product string **absent** → keep `_Inferred` |
| `FxCache_*` | **Wrong** — this is consumer, not cache |
| Retain `FUN_00512d10` only | Scaffold; role sealed enough to promote structural name |

---

## 7. Gaps

1. Product/PDB method name.
2. Exact meaning of cache key args (`param_2`/`param_3` order vs helpers).
3. Nested attach argument list residual.
4. Flag bit **2** product enum.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI/CF/paths/flag/TFID/offset sealed; naming + nested-arg residual.
