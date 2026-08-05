# Review A (reconstruction fidelity): `aa_008e4430` UI_FormatObjectDifficultyTier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e4430` |
| **VA** | `0x008e4430`–`0x008e4726` (758 B / `0x2F6`) |
| **Canonical name** | `UI_FormatObjectDifficultyTier_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_008e4430` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W29-J) |
| **Counterpart** | `reviews/B_aa_008e4430_UI_FormatObjectDifficultyTier_Inferred.md` |
| **System** | client mission / target UI difficulty |
| **Verdict** | **accept-with-gaps** — CF + register ABI + tier strings/thresholds + out-color store sealed; palette runtime + product English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

UI helper: for a target object, pick a **difficulty tier label** + **palette**, pack color, optionally format `"LocalizedTier: requiredLevel"` into a caller buffer, and return packed color via out-pointer.

Uses global character `DAT_00d1b6d8`, resource lookup `FUN_0052ada0`, score `FUN_0052b080`, locale `FUN_007a69d0`/`FUN_007a6de0`, and color packers `FUN_00973590` / `FUN_00973820`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x008e4430` (2026-07-29 ≡ raw 2026-07-23 CF shape) |
| Bounds | `008e4430`–`008e4726` |
| Entry bytes | `sub esp,18; push ebx; mov ebx,eax; init local color 0xFF×4` |
| Exit bytes | success: `mov [eax],edx; …; ret`; early: `mov [eax],ecx` with 0xFFFFFFFF |
| Thresholds | `read_memory`: 90/70/50/30.0f; scale 255.0f |
| Strings | `Impossible`…`Very Hard`; `"%s: %d"` |
| Callers | `FUN_008b3670`, `FUN_008e47d0`, `FUN_008e5e00` (5 sites) |
| Call-site ABI | push `&out`; ESI=buf or 0; EAX=object; `add esp,4` after call |

**Not performed:** Launcher, runtime palette values, dual of score helper.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 758 B; plain `ret` | **Confirmed** | bounds + epilogue `C3` |
| EAX = object; ESI = optional text; stack = `uint32* out` | **Confirmed** | entry `mov ebx,eax`; call sites; `test esi,esi` |
| Null object or null `DAT_00d1b6d8` → `*out=0xFFFFFFFF` | **Confirmed** | |
| Impossible when player resource &lt; required `+0x4b0` | **Confirmed** | `cmp ebp,edi` / jge |
| Tier ladder on score with sealed float thresholds | **Confirmed** | consts 90/70/50/30 |
| Labels exact rdata strings | **Confirmed** | |
| `*out` = packed color on success (not always -1) | **Confirmed** | epilogue `mov [eax],edx`; **rejects** raw decompile tail |
| sprintf only if ESI ≠ 0 | **Confirmed** | |
| Product UI name | **Open** | |
| Runtime palette RGB | **Open** | BSS zeros in image |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Frame + init color 0xFF | Yes |
| Guard object / global character | Yes |
| Load clone `*(obj+0xa8)+0x3c`; required `@+0x4b0`; key `@+0x4ac` | Yes |
| `FUN_0052ada0` → player value; `FUN_0052b080` → score | Yes |
| `FUN_007a69d0` locale root | Yes |
| Impossible branch: scale palette ×255, `FUN_00973590`, label | Yes |
| Else nested score compares → palette + `FUN_00973820` + label | Yes |
| Optional localize + `sprintf("%s: %d", …, required)` | Yes |
| `*out = packedColor` | Yes |

---

## 5. Gaps

1. Product/PDB symbol.
2. Exact resource type at `+0x4ac` (level vs other) — depends on sealed map helper.
3. Runtime values of `DAT_00d1b424`… color tables.
4. Full dual of `FUN_0052b080` (score); context only here.
5. Runtime / differential UI capture.

**Verdict:** **accept-with-gaps** — difficulty tier UI CF, ABI, strings, and thresholds sealed.
