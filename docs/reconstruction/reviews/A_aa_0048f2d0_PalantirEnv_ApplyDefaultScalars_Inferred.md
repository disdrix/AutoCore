# Review A (reconstruction fidelity): `aa_0048f2d0` PalantirEnv_ApplyDefaultScalars_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048f2d0` |
| **VA** | `0x0048f2d0`–`0x0048f361` exclusive (**145 B** / `0x91`) |
| **Canonical name** | `PalantirEnv_ApplyDefaultScalars_Inferred` |
| **Ghidra name** | `FUN_0048f2d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-Q) |
| **Counterpart** | `reviews/B_aa_0048f2d0_PalantirEnv_ApplyDefaultScalars_Inferred.md` |
| **System** | client / Palantir env host |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Env-host method applying sealed default scalars after child@`+0x100` is present:

1. If `env+0x100 != 0` → `FUN_00497c80(child)` (thiscall; ECX preloaded from field).
2. `+0x10c = 100.0f` (`DAT_00aaa7ac`); `+0x110 = 200.0f` (`DAT_00aaa884`).
3. Float bank `+0x60..+0x6c` ← `_DAT_009c774c`, `DAT_009c7748`, `DAT_009c7748`, `g_flOne`.
4. `+0x178 = 0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-Q) | `docs/reconstruction/raw/aa_0048f2d0_FUN_0048f2d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0048f2d0_FUN_0048f2d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalantirEnv_ApplyDefaultScalars_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048f2d0.cpp` |
| Function records | `functions/aa_0048f2d0_FUN_0048f2d0.md`, `functions/aa_0048f2d0_PalantirEnv_ApplyDefaultScalars_Inferred.md` |
| Related | W31-P ctor `PalantirEnv_Ctor_Inferred`; child `FUN_00497920` (W32-P) |
| Live | body 145 B; epilogue `5E 83 C4 10 C3`; globals sealed via `read_memory` |

---

## 3. Signature (sealed)

```c
// __thiscall / Ghidra __fastcall; ECX=env*; no stack formals; bare C3
void __fastcall PalantirEnv_ApplyDefaultScalars_Inferred(void *env);
```

| Formal | Source | Conf |
|---|---|---|
| env | ECX (`8B F1`) | **High** |
| return | void (no EAX contract) | **High** |
| cleanup | bare `RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
sub esp, 0x10; push esi; mov esi, ecx
ecx = [esi+0x100]; if ecx: call FUN_00497c80
movss [esi+0x10c] ← DAT_00aaa7ac   // 100.0f
movss [esi+0x110] ← DAT_00aaa884   // 200.0f
lea eax, [esi+0x60]
[eax+0] ← _DAT_009c774c
[eax+4] ← DAT_009c7748
[eax+8] ← DAT_009c7748
[eax+c] ← g_flOne
[esi+0x178] ← 0
pop esi; add esp, 0x10; ret
```

| Stage | Match | Conf |
|---|---|---|
| Body size 0x91 / bare RET | **Yes** | **High** |
| Child thiscall ECX | **Yes** (bytes; decompiler omits) | **High** |
| Float constants | **Yes** (read_memory) | **High** |
| Ctor tail call site | **Yes** (`0x00493090`) | **High** |

---

## 5. Gaps

- Product English for scalar fields / bank meaning.
- Product name of child@`+0x100` and full role of `FUN_00497c80`.
- Orphan call site enclosing function at `0x004d966b`.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, body, stores, and constants. Residual product English + orphan site → **accept-with-gaps**.
