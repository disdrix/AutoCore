# Review A (reconstruction fidelity): `aa_005b36f0` Env_ApplyFogShaderAndReflect_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b36f0` |
| **VA** | `0x005b36f0`–`0x005b3992` (674 B / `0x2A2`) |
| **Canonical name** | `Env_ApplyFogShaderAndReflect_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_005b36f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W29-I) |
| **Counterpart** | `reviews/B_aa_005b36f0_Env_ApplyFogShaderAndReflect_Inferred.md` |
| **System** | client environment / fog shader |
| **Verdict** | **accept-with-gaps** — CF + ret4 + vtbl[1] + fog string pipeline sealed; product class open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + `search_byte_patterns` + `audit_globals_in_function` + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Host virtual method that applies **fog shader constants** and refreshes **environment reflection vectors** when context is live:

1. Gate on `this+0x15c` and nested `+0xe4f8`.
2. If `this+0x80`: bind `gFogEnable` / `gFogStart` / `gFogEnd` / `gFogColor` from `this+0x164`, pack color via `00973820`, update reflect block at `*(this+0x158)+8`.
3. Return `0` if gate passed, else `-1`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x005b36f0` ≡ 2026-07-23 raw CF |
| Bounds | `get_function_by_address` → `005b36f0`–`005b3992` |
| Epilogue | `read_memory` @ `005b3980`: success + fail both **`C2 04 00`**; fail `or eax,0xFFFFFFFF` |
| Vtbl | `search_byte_patterns` `f0 36 5b 00` → **`0x009d95a4`** = `PTR_FUN_009d95a0[1]` |
| Ctor/dtor | `FUN_005b35a0` / `FUN_005b3670` / `FUN_005b3a30` |
| Globals audit | fog strings + `DAT_00d1f048` / `DAT_00d1f05c` + flags `00af3ed5/6` |
| Direct xrefs | **0** code callers |
| Raw / annotated / clean | W29-I updated |

**Not performed:** Launcher, runtime golden, nested duals of bind helpers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range 674 B / `0x2A2` | **Confirmed** | bounds + pad `CC` |
| **`ret 4`** + returns 0 / -1 | **Confirmed** | epilogue bytes |
| thiscall ECX + 1 stack arg | **Confirmed** | decompile + ret 4 |
| Vtbl slot 1 of `009d95a0` | **Confirmed** | byte search + ctor install |
| Fog string pipeline | **Confirmed** | literals + `FUN_0074f1b0` / `FUN_00442d50` |
| Color pack via `00973820` | **Confirmed** | callee list + W28-E dual |
| Reflect dirty / vector writeback | **High** | CF sealed; field English open |
| Product class name | **Open** | do not invent from adjacent RTTI string |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Prologue `push ebp; mov ebp,esp; and esp,-16` | Yes |
| Gate `this+0x15c` / `+0xe4f8` → fail -1 | Yes |
| Gate `this+0x80` → skip work body | Yes |
| Mirror `this+0x78` into `DAT_00d1f048` slots | Yes |
| Bind gFogEnable / Start / End | Yes |
| gFogColor + `FUN_00973820` | Yes |
| Reflect block dirty + optional flags | Yes |
| Optional vfunc `+0x3c`(arg0) | Yes |
| Return 0 / -1 with `ret 4` | Yes |

---

## 5. Related (not OWN)

| VA / symbol | Role |
|---|---|
| `0x009d95a0` | host vtbl |
| `0x005b35a0` | ctor |
| `0x005b3670` | body dtor |
| `0x00973820` | color pack scale-255 (W28-E) |
| `0x00973590` | nested clamp pack (W29-I peer) |
| `0x00af3ed5` / `0x00af3ed6` | static toggles (image `01`) |

---

## 6. Gaps

1. Product class / method English.
2. Nested helper duals (shader bind, `FUN_004cd220`, `FUN_005b39d0`).
3. Reflect field product labels.
4. Runtime golden.

**Verdict:** **accept-with-gaps** — sealed CF, ABI, vtbl ownership, and fog string pipeline; product class and nested English open.
