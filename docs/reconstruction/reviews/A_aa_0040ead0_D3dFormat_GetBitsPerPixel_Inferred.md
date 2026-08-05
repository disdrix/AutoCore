# Review A (reconstruction fidelity): `aa_0040ead0` D3dFormat_GetBitsPerPixel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ead0` |
| **VA** | `0x0040ead0` |
| **Body** | jump-table leaf; code + tables through `0x0040eb90` (**193 B** / `0xC1`); pad `CC` |
| **Canonical name** | `D3dFormat_GetBitsPerPixel_Inferred` (**Inferred**); Ghidra `FUN_0040ead0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md` |
| **System** | Graphics / D3D format utility |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context` (no `disassemble_bytes`) |
| **Verdict** | **accept** — pure leaf map; bpp semantics sealed by caller `shr 3` |
| **Dual status** | **Present (W38-T)** |

---

## 1. Purpose

Leaf **D3DFORMAT → bits-per-pixel** lookup for texture/surface memory math.

```
eax = format - 0x14;
if (eax > 0x60) return 0;
jmp return_table[index_table[eax]];  // {24,32,16,8,64,128,0}
```

**ABI:** `__cdecl`; stack `(format)`; returns **bpp** in EAX; plain **`ret`** (callers `add esp,4`).

| fmt | bpp | note |
|---|---|---|
| `0x14` | 24 | D3DFMT_R8G8B8 |
| `0x15`/`0x16`/`0x23`/`0x70`/`0x72` | 32 | A8R8G8B8 family + ext |
| `0x17`/`0x19`/`0x1a`/`0x33`/`0x6f` | 16 | 16-bit family + ext |
| `0x1c`/`0x32` | 8 | A8 / L8 |
| `0x24`/`0x71`/`0x73` | 64 | A16B16G16R16 + ext |
| `0x74` | 128 | ext |
| default | 0 | unknown |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x0040ead0` — **≡ switch map** |
| Complete analysis | 19 xrefs; 0 callees; leaf; 17 callers |
| Machine | `read_memory` code + jump table @ `0x40eb14` + index @ `0x40eb30` (0x61 bytes) |
| Callers | GfxDevice_Reset (`0075eff0`) imul+`shr 3`; veh_paint `shr 3`; others |
| Scaffold | prior raw/annotated/clean |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| `format - 0x14` then `cmp 0x60` | `83 c0 ec 83 f8 60 77 32` | **Confirmed** |
| Index table @ `0x40eb30` | `0f b6 80 30 eb 40 00` | **Confirmed** |
| Jump table @ `0x40eb14` | `ff 24 85 14 eb 40 00` | **Confirmed** |
| Return stubs 128/64/32/24/16/8/0 | consecutive `b8 imm32; c3` / `33 c0 c3` | **Confirmed** |
| `__cdecl` | plain `c3`; callers `add esp,4` | **Confirmed** |
| Return = **bits** not bytes | callers `shr eax,3` then pitch math | **Confirmed** |
| Leaf | no callees | **Confirmed** |

---

## 4. Gaps

- Product names for engine-extended formats `0x6f`–`0x74`.
- Full bytes-on-disk formula is in callers (mips, pitch align) — not this leaf.
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept** — pure data-driven leaf; CF and bpp semantics sealed; residual only extended-format product English.
