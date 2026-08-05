# Dual A/B report — W22-O OWN-ONLY (`aa_004313d0`, `aa_00434dd0`)

**Date:** 2026-07-29  
**Agent:** W22-O OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004313d0`, `0x00434dd0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004313d0` StdTree_IteratorDecrement | **accept** — MSVC tree predecessor; nil@`+0x2d`; EDX=`node**`; 80 B sealed |
| `aa_00434dd0` NDAssetImage_DecodeUncompressedTgaRow | **accept** — TGA uncompressed span; bpp 8/15/16/24/32; `ret 0x14`; RGB555 R-mask sealed |

---

## Sealed facts — `0x004313d0`

1. **ABI:** iterator in **EDX** (`node**`); **ECX unused**; plain **`ret`**. Body **`0x004313d0`–`0x00431420`** (**80 bytes**).

2. **Node:** `+0` left, `+4` parent, `+8` right, **`+0x2d` `_Isnil`**.

3. **Algorithm (predecessor):**  
   - nil/header → `*it = right` (rightmost)  
   - else if left non-nil → rightmost of left subtree  
   - else climb parents while still left-child  

4. **Not** successor (contrast `StdTree_IteratorIncrement_Inferred` @ `0x004cb270`, nil@`+0x29`).

5. **Callers (4):** `StdMap_StringKey_InsertOrFind` @ `0x00430a42`, `FUN_0044d9f0`, `FUN_00401c50`, `FUN_004303c0`. Pattern: `lea edx, [local]; call`.

6. **Callees:** none.

7. **Name:** `StdTree_IteratorDecrement` — role-sealed **INFERRED**. Ghidra: `FUN_004313d0`.

---

## Sealed facts — `0x00434dd0`

1. **ABI:** **ECX** = stream*, **EDX** = dest RGB*; **5 stack** formals; epilogue **`ret 0x14`**. Body **`0x00434dd0`–`0x00434f08`** (**312 bytes**). SEH `LAB_009bccb0`.

2. **Stack:** image*, header* (**bpp @ +0x10**), pixel **count**, row **y**, start **x**.

3. **Stream:** `vtbl+8` Read `(buf, size, 1)`.

4. **bpp switch** (jump table `0x00434f10` / index `0x00434f24`, index = bpp−8):  
   - **8:** bulk read `count`  
   - **15/16:** loop; 2 B → RGB555 expand to 3 B; **R = (p&0x1f)<<3** (decomp dropped mask)  
   - **24:** bulk read `count*3`  
   - **32:** loop; 4 B → write 3 RGB; **`FUN_00433280`** stores alpha  

5. **Callers:** `NDAssetImage_LoadTGA` @ `0x00434a55`; RLE `FUN_00434b30` @ `0x00434d45`.

6. **Name:** `NDAssetImage_DecodeUncompressedTgaRow` — role-sealed **INFERRED**. Ghidra: `FUN_00434dd0`.

---

## Gaps

### `004313d0`
1. Product MSVC template English symbol.  
2. Full map-node payload (key at +0x0C etc.) — parent duals.  
3. Runtime / bit-exact / differential — open.  
4. Whether all callers share identical node size (isnil@2d) — assumed yes by algorithm.

### `00434dd0`
1. Product stream class / Read return polarity English.  
2. `FUN_00433280` alpha plane vs packed-A layout — callee residual.  
3. Channel-order product name (byte order sealed).  
4. Runtime vs retail `map.tga` — open.

---

## Files

### `aa_004313d0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004313d0_StdTree_IteratorDecrement.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004313d0_StdTree_IteratorDecrement.md` |
| Function record | `docs/reconstruction/functions/aa_004313d0_StdTree_IteratorDecrement.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004313d0_FUN_004313d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_IteratorDecrement.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004313d0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004313d0_FUN_004313d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004313d0_FUN_004313d0.annotated.md` |
| Scratch | `tmp/a_004313d0.md` |

### `aa_00434dd0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md` |
| Function record | `docs/reconstruction/functions/aa_00434dd0_NDAssetImage_DecodeUncompressedTgaRow.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00434dd0_FUN_00434dd0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDAssetImage_DecodeUncompressedTgaRow.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00434dd0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00434dd0_FUN_00434dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00434dd0_FUN_00434dd0.annotated.md` |
| Scratch | `tmp/a_00434dd0.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004313d0-00434dd0-w22o-report.md` |

---

## AutoCore impact

### `004313d0`
- Client STL tree helper: reverse/insert-side predecessor only.
- Port only if AutoCore needs reverse map iteration or MSVC-compatible insert positioning.
- **Do not** confuse with successor @ `0x004cb270` (different nil offset).
- Server typically **omits** unless sharing client map structures.

### `00434dd0`
- Client TGA asset path (`map.tga` / `NDAssetImage_LoadTGA`).
- Port as bpp switch + stream Read; keep RGB555 expand **including R `&0x1f`**.
- 32bpp alpha is **not** written into the RGB dest stride — separate `FUN_00433280`.
- Server AutoCore typically **omits** unless hosting client-parity asset tooling.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
