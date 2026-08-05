# Review A (reconstruction fidelity): `aa_00973820` Color_PackFloat4_Scale255_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973820` |
| **VA** | `0x00973820`–`0x00973872` (83 B / `0x53`) |
| **Canonical name** | `Color_PackFloat4_Scale255_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00973820` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W28-E) |
| **Counterpart** | `reviews/B_aa_00973820_Color_PackFloat4_Scale255_Inferred.md` |
| **System** | client color pack utility |
| **Verdict** | **accept-with-gaps** — CF + scale-255 + ret4 + ECX dest sealed; nested packer product English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **float4 → packed byte color** wrapper:

1. Multiply `src[0..3]` by **`DAT_00aaa6f8` = 255.0f**.
2. Call `FUN_00973590` to clamp+ROUND each channel into the destination buffer.

Destination is **ECX** (byte-sealed via `mov eax,ecx` before the call). Stack holds the float* source; epilogue **`ret 4`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x00973820` |
| Bounds | `get_function_by_address` → `00973820`–`00973872` |
| Entry/exit bytes | `read_memory` 84 B; epilogue `E8 … C2 04 00` |
| Constant | `DAT_00aaa6f8` = `00 00 7F 43` = **255.0f** |
| Callers | `FUN_004b18f0`, `FUN_005b36f0`, `FUN_005e1fc0`, `FUN_008e4430` (9 xrefs) |
| Call-site ECX | `004b1900`: `mov ecx,[esi+8]; push &DAT_00aef980; add ecx,0x34; call` |
| Nested peek | `FUN_00973590` decompile (channel map) — not OWN dual |
| Raw / annotated / clean | W28-E updated |

**Not performed:** Launcher, runtime golden, bit-exact, full dual of `FUN_00973590`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `00973820`–`00973872` (83 B) | **Confirmed** | bounds + pad `CC` after ret |
| **`ret 4`** (`C2 04 00`) | **Confirmed** | epilogue `read_memory` |
| Scale each float by 255.0f | **Confirmed** | `mulss` × `DAT_00aaa6f8` |
| ECX = dest; stack = float* src | **Confirmed** | call sites + `8B C1` |
| Single callee `FUN_00973590` | **Confirmed** | analyze callees |
| Decompiler surface incomplete (no ECX) | **Confirmed** | raw shows stack-only |
| Nested channel map BGRA-style | **High** (via callee decompile) | not OWN dual |
| Product / PDB name | **Open** | |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load float* from stack | Yes |
| Load 255.0f constant | Yes |
| Scale src[3],src[2],src[1],src[0] onto call stack | Yes |
| `mov eax, ecx` before call | Yes |
| `call FUN_00973590` | Yes |
| `ret 4` | Yes |

---

## 5. Callers

| Caller | Notes |
|---|---|
| `FUN_004b18f0` | pack black `{0,0,0,1}` → `child+0x34` (W27-F dualed parent) |
| `FUN_005b36f0` | fog color path |
| `FUN_005e1fc0` | color field write helper |
| `FUN_008e4430` | difficulty tier colors (×5 sites in one fn) |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Full dual of nested `FUN_00973590` (clamp + channel indices).
3. Runtime golden for out-of-range floats.

**Verdict:** **accept-with-gaps** — sealed scale-255 pack wrapper CF, ret4, and ECX dest ABI; nested packer English open.
