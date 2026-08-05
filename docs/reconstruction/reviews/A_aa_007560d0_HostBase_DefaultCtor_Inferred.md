# Review A (reconstruction fidelity): `aa_007560d0` HostBase_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007560d0` |
| **VA** | `0x007560d0`–`0x0075617f` exclusive (**175 B** / `0xAF`) |
| **Canonical name** | `HostBase_DefaultCtor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_007560d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-O) |
| **Counterpart** | `reviews/B_aa_007560d0_HostBase_DefaultCtor_Inferred.md` |
| **System** | client / shared host base |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full 175 B + globals). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared first-stage default constructor used by Palantir env, UI host (`new(0x80)`), and phase objects:

1. Install vtbl `PTR_FUN_00a9f534`.
2. Zero `+0x04` / `+0x08`.
3. Init subobject at `+0x10` via `FUN_0076c500(1000)` then write `+0x40/+0x44 = 1000` and `FUN_0076c4d0`.
4. Zero mid fields; copy float4 ones from `DAT_00afdf40`; store `g_flHardKillInterpolate` (0.005f); set byte `+0x78 = 1`.
5. Return **this**.

Derived ctors commonly overwrite vtbl after return (e.g. PalantirEnv → `PTR_FUN_009c7928`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-O) | `docs/reconstruction/raw/aa_007560d0_FUN_007560d0.md` |
| Annotated | `docs/reconstruction/raw/aa_007560d0_FUN_007560d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HostBase_DefaultCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_007560d0.cpp` |
| Function records | `functions/aa_007560d0_FUN_007560d0.md`, `functions/aa_007560d0_HostBase_DefaultCtor_Inferred.md` |
| Live | decompile ≡ raw CF; full body hex; globals `1.0f`×4 + `0.005f`; 6 callers / 6 xrefs |
| Related | W31-P PalantirEnv ctor residual closed for this callee’s field map |

---

## 3. Signature (sealed)

```c
// __thiscall/__fastcall; ECX=self*; returns self; plain RET
void *HostBase_DefaultCtor_Inferred(void *self /*ECX*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | EAX = ESI = this | **High** |
| cleanup | `ADD ESP,0x10` + `C3` | **High** |
| stack formals | none | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH LAB_009ada99
vtbl = PTR_FUN_00a9f534
+4=+8=0
FUN_0076c500(1000) on this+0x10
+0x40=+0x44=1000
FUN_0076c4d0 on this+0x10
+0x48=0; +0x50..+0x5C=0
+0x60..+0x6C = DAT_00afdf40 float4 (1.0f)
+0x70=0; +0x74=g_flHardKillInterpolate; +0x78=1
return this
```

| Stage | Match | Conf |
|---|---|---|
| Field order ≡ full hex | **Yes** | **High** |
| Subobject ECX=`this+0x10` | **Yes** (`8D 7E 10`) | **High** |
| Constants 1000 / 1.0f / 0.005f | **Yes** (`read_memory`) | **High** |
| Product class English | shape only | **Inferred** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (175 B) in raw W32-O append. Globals:

| Symbol | VA | Bytes / value |
|--------|-----|----------------|
| `DAT_00afdf40..4c` | `0x00afdf40` | `00 00 80 3F` ×4 → **1.0f** |
| `g_flHardKillInterpolate` | `0x00aaa6a4` | `0A D7 A3 3B` → **0.005f** |

---

## 6. Gaps

1. Product/PDB class name for `PTR_FUN_00a9f534`.
2. Nested `FUN_0076c500` / `FUN_0076c4d0` product roles (not owned here).
3. Exact sizeof per most-derived (0x80 known for UI peer; others open).
4. Runtime / bit-exact / differential.

---

## 7. Verdict

Fidelity pass seals ABI, full body bytes, field map, and constants → **accept-with-gaps** (product/nested residual).
