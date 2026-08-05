# Review A (reconstruction fidelity): `aa_00973590` Color_ClampRoundPackBGRA_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00973590` |
| **VA** | `0x00973590`–`0x00973680` (240 B / `0xF0`) |
| **Canonical name** | `Color_ClampRoundPackBGRA_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_00973590` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W29-I) |
| **Counterpart** | `reviews/B_aa_00973590_Color_ClampRoundPackBGRA_Inferred.md` |
| **System** | client color pack utility |
| **Verdict** | **accept** — leaf clamp+ROUND pack, EAX dest, ret 0x10, BGRA map sealed |
| **Dual status** | **Present (first full dual)** — closes W28-E/F nested-packer gap |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Shared **float×4 → packed U8×4** leaf:

1. `ROUND` each float via FPU `fistp`.
2. Clamp to **[0, 255]**.
3. Store as **BGRA bytes** when stack order is RGBA: `[2]=f0, [1]=f1, [0]=f2, [3]=f3`.

Destination is **EAX** (callers typically `mov eax, ecx`). Epilogue **`ret 0x10`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x00973590` |
| Bounds | `get_function_by_address` → `00973590`–`00973680` |
| Entry/exit bytes | `read_memory` 240 B; epilogue `83 C4 0C C2 10 00` |
| Channel stores | `88 48 02` / `88 48 01` / `88 08` / `88 50 03` (and alpha early-ret twins) |
| Callers | 20 UNCONDITIONAL_CALL xrefs (scale pack, lerp, difficulty, serializers, …) |
| Sibling duals | W28-E `00973820`, W28-F `00973690` (call this) |
| Raw / annotated / clean | W29-I updated |

**Not performed:** Launcher, runtime golden, bit-exact.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `00973590`–`00973680` (240 B) | **Confirmed** | bounds + pad `CC` |
| **`ret 0x10`** | **Confirmed** | epilogue `read_memory` |
| EAX = dest | **Confirmed** | `in_EAX` + caller `mov eax,ecx` pattern |
| Leaf (no callees) | **Confirmed** | analyze_function_complete |
| Channel map BGRA-style | **Confirmed** | dest indices in decompile ≡ bytes |
| Clamp 0..255 via ROUND | **Confirmed** | fistp + 0/0xFF lea select |
| Mid-channel decomp pointer labels | **High gap** | labels wrong; **semantics sealed** |
| Product / PDB name | **Open** | |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| `sub esp,0xC; push esi` frame | Yes |
| Load f0; ROUND; clamp; `dest[2]=` | Yes |
| Load f1; ROUND; clamp; `dest[1]=` | Yes |
| Load f2; ROUND; clamp; `dest[0]=` | Yes |
| Load f3; ROUND; clamp; `dest[3]=` (3 exit paths) | Yes |
| `add esp,0xC; ret 0x10` | Yes |

---

## 5. Callers (summary)

| Caller | Role |
|---|---|
| `FUN_00973820` | Scale float4 ×255 then pack (W28-E) |
| `FUN_00973690` | Packed ARGB lerp → pack (W28-F) |
| `FUN_00973770` / `FUN_00973880` | Sibling color helpers |
| `FUN_008e4430` | Difficulty tier colors |
| `FUN_0073d200` | Multi-site color serialize/pack |
| Others | 20 total xrefs |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Runtime golden for out-of-range / NaN.

**Verdict:** **accept** — sealed leaf packer ABI, channel map, and clamp; product English open only.
