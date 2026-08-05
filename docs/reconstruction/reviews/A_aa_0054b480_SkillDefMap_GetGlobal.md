# Review A (reconstruction fidelity): `aa_0054b480` `SkillDefMap_GetGlobal`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054b480` |
| **VA** | `0x0054b480` |
| **Body span** | `0054b480`–`0054b493` (20 B through `ret`) |
| **Canonical name** | `SkillDefMap_GetGlobal` (structural) |
| **Ghidra name** | `FUN_0054b480` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W18-C) |
| **Counterpart** | `reviews/B_aa_0054b480_SkillDefMap_GetGlobal.md` |
| **System** | `skills-abilities` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Lazy-get the process-global skill-definition map header:**

1. If `DAT_00b04724 == 0`, call `FUN_0054b2c0` (init/load tree; sets flag).
2. Return `&DAT_00b04734` (always).

Leaf used before `SkillDefMap_ExactFindByIntKey` (`0x00418890`) and related skill-def walks. **Not** the per-entity category cooldown map.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054b480_FUN_0054b480.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0054b480_FUN_0054b480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillDefMap_GetGlobal.cpp` |
| Scaffold clean | `reconstructed-exact/FUN_0054b480.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054b480_SkillDefMap_GetGlobal.md` |
| Live decompile | Ghidra @ `0x0054b480` |
| Bytes | `read_memory` 32 B @ `0x0054b480` |
| Xrefs | callers: RecvSkillStatusEffect, `FUN_005408f0`, `FUN_00541aa0`, `FUN_00542790`, `0x0052a2ca` |
| Sibling | `SkillDefMap_ExactFindByIntKey` dual (`aa_00418890`) — map this = `DAT_00b04734` |

**Not performed:** `disassemble_bytes`, Launcher, runtime cold/warm golden.

---

## 3. Assembly-sealed body (`read_memory` @ `0x0054b480`)

```text
0054b480  80 3D 24 47 B0 00 00   cmp  byte ptr [DAT_00b04724], 0
0054b487  75 05                  jne  +5                 ; already inited
0054b489  E8 32 FE FF FF         call FUN_0054b2c0
0054b48e  B8 34 47 B0 00         mov  eax, offset DAT_00b04734
0054b493  C3                     ret
```

Hex (body through `ret`):

```
803d2447b000007505e832feffffb83447b000c3
```

| Claim | Evidence | Conf |
|---|---|---|
| Body **20 bytes** through `ret` | `read_memory` + `CC` pad | **Confirmed** |
| No stack args / pure leaf | `C3` only; no `C2` | **Confirmed** |
| Gate on `DAT_00b04724` | `80 3D 24 47 B0 00 00` | **Confirmed** |
| Init callee `FUN_0054b2c0` | relative call target | **Confirmed** |
| Return `&DAT_00b04734` | `B8 34 47 B0 00` | **Confirmed** |
| Live decompile ≡ raw | side-by-side | **Confirmed** |
| Clean ≡ raw CF | three-rep | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = global SkillDefMap getter | **Confirmed** | consumers + ExactFind family |
| Lazy once via `DAT_00b04724` | **Confirmed** | bytes + init sets flag |
| ≠ GetCategoryCooldownMap | **Confirmed** | different address / entity `+0x6c` |
| Product STL/RTTI name | **Open** | structural name sealed |
| Full init side effects | **Open** | callee `FUN_0054b2c0` not OWN |

---

## 5. Call graph (this unit)

**Callees:** `FUN_0054b2c0` (conditional)

**Callers:**

| Symbol | VA |
|---|---|
| `Client_RecvSkillStatusEffect` | `0x00811170` |
| `FUN_005408f0` | `0x005408f0` |
| `FUN_00541aa0` | `0x00541aa0` |
| `FUN_00542790` | `0x00542790` |
| (site) | `0x0052a2ca` |

---

## 6. Gaps

1. Product English / STL type name for map header.
2. Dual of `FUN_0054b2c0` (out of OWN).
3. Runtime golden cold vs warm path.

**Verdict:** **accept** — leaf fully sealed; naming residual only.
