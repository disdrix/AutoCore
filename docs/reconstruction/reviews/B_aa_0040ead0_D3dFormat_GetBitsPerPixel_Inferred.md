# Review B (skeptical / adversarial): `aa_0040ead0` D3dFormat_GetBitsPerPixel_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ead0` |
| **VA** | `0x0040ead0` |
| **Canonical name** | `D3dFormat_GetBitsPerPixel_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0040ead0_D3dFormat_GetBitsPerPixel_Inferred.md` |
| **System** | Graphics / D3D format utility |
| **Live tools** | Independent decompile + `read_memory` + multi-caller assembly |
| **Verdict** | **accept** — accept bpp leaf; reject bytes-return / thiscall / non-leaf / scaffold name claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns **bytes** per pixel | **Falsified** — callers `shr eax,3` after call before pitch multiply |
| 2 | `__thiscall` / ECX format | **Falsified** — format from stack `[esp+4]`; free function |
| 3 | `ret 4` stdcall | **Falsified** — plain `c3`; callers `add esp,4` |
| 4 | Incomplete switch vs tables | **Falsified** — decompile cases match index/jump tables end-to-end for listed formats |
| 5 | Non-zero default | **Falsified** — default and out-of-range → **0** |
| 6 | Scaffold `Named_CalleeOf_…gfxDevice…` is product | **Rejected** — parent-seed noise |
| 7 | Covers all D3D9 formats | **Open** — many classic enums missing (e.g. `0x18` X1R5G5B5 → 0); intentional sparse map |
| 8 | FourCC DXT handled here | **Falsified** — only small enum range `0x14`..`0x74` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Jump-table CF | **High** | Wrong bpp |
| Return = bits | **High** | 8× memory error if treated as bytes |
| `__cdecl` | **High** | Stack imbalance |
| Core D3DFMT identities | **High** | Misnamed formats |
| Extended `0x6f`–`0x74` English | **None** | Overclaim |
| Exhaustive D3D coverage | **N/A** | Sparse by design |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** return bytes — port must keep **bits**; callers shift.
2. Default **0** is load-bearing (skip/fail paths).
3. Scaffold gfxDevice name — **ignore**.
4. Do not invent DXT/FourCC cases absent from tables.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Sparse format→bpp leaf | “Complete D3D9 bpp table” |
| `__cdecl` free function | Member of GfxDevice |
| bits return + caller `>>3` | bytes return |
| `_Inferred` structural name | Official SDK helper symbol |

---

## 5. CF challenge of Review A

- Jump tables + listed case map: **agree Confirmed**  
- bpp + `shr 3` callers: **agree Confirmed**  
- Extended format product English open: **agree**  
- accept (not accept-with-gaps): **agree** — residual is naming only, not CF  

**Verdict:** **accept**
