# Review A (reconstruction fidelity): `aa_008aab00` MissionDialog_ParseMarkupToRichText_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aab00` |
| **VA** | `0x008aab00` |
| **Canonical name** | `MissionDialog_ParseMarkupToRichText_Inferred` (Ghidra `FUN_008aab00`) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_008aab00_MissionDialog_ParseMarkupToRichText_Inferred.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Mission/dialog **markup → richtext paint** helper:

1. Guard null markup / null widget.
2. Locale ensure (`FUN_007a69d0`); copy markup into local 4 KiB work buffer.
3. Scan for `[$` tags; flush plain runs via **vtbl+0x250**.
4. Color open/close pairs, pause, and keybind resolve as sealed matrix.
5. Final flush of trailing plain run.

Does **not** send packets or mutate mission journal state.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra | `batch_decompile` + `analyze_function_complete` @ `0x008aab00` |
| Body bounds | `get_function_by_address` → `008aab00`–`008aaf58` |
| Entry/epilogue | `read_memory` @ `0x008aab00`, `0x008aaf50` |
| Xrefs / callers | `get_function_xrefs` (6) + `get_assembly_context` call sites |
| Key table | `read_memory` @ `DAT_00d1bbf5` (static zeros) |
| Raw | `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.md` (+ WQ7R-C append) |
| Annotated | `docs/reconstruction/raw/aa_008aab00_FUN_008aab00.annotated.md` |
| Clean | `reconstructed-exact/MissionDialog_ParseMarkupToRichText_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_008aab00.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body size 1112 B / `0x458` | **High** | Ghidra bounds + epilogue `add esp,0x204c; ret` |
| ECX = markup string | **High** | `mov esi,ecx`; callers LEA/MOV string into ECX |
| Stack arg = richtext widget* | **High** | vtbl uses; callers PUSH widget; `ADD ESP,4` |
| Null-guard both args | **High** | entry tests |
| Tag string matrix complete | **High** | all tags in decompile immediates |
| Color immediates exact | **High** | decompile constants; ARGB decode sealed |
| `[$pause]` → +0x254(0x14) | **High** | decompile |
| Key path Free Look / table / `<%s>` | **High** CF | table bounds 120×0x34 |
| Vtbl product English | **Tentative** | ordinals only |
| `FUN_007f9160` display side-effect | **Tentative** | non-zero skips sprintf |
| Product function name | **Open** | `_Inferred` only |
| Scaffold `Named_npc` product | **Reject** | single-tag plate |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live | Clean |
|---|---|---|---|
| Null-guard + locale ensure | Yes | Yes | Yes |
| Copy to work buffer | Yes | Yes | Yes |
| Tag scan + flush runs | Yes | Yes | Yes |
| Color / pause / key arms | Yes | Yes | Yes |
| Final flush | Yes | Yes | Yes |
| Invented branches | — | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra.

---

## 5. Assembly seals (no disassemble_bytes)

### 5.1 Entry (`read_memory` @ `0x008aab00`)

`B8 4C 20 00 00` = `mov eax, 0x204c` → `__chkstk`; `8B F1` = `mov esi, ecx` (markup).

### 5.2 Epilogue (`read_memory` @ `0x008aaf50`)

`5F 5E 5D 81 C4 4C 20 00 00 C3` = pop edi/esi/ebp; `add esp,0x204c`; ret.

### 5.3 Call framing (sample)

| Site | Pattern |
|---|---|
| `008aaff3` | PUSH widget; ECX=string buffer/widget path; CALL; ADD ESP,4 |
| `008a3c35` | LEA ECX, stack string; PUSH widget; CALL; ADD ESP,4 |
| `008cc5c0` | PUSH ECX (widget); MOV ECX,EDI (string); CALL |

---

## 6. Gaps

1. Product/PDB symbol.
2. Product names for vtbl +0x230/+0x23c/+0x250/+0x254.
3. Runtime fill of `DAT_00d1bbf5`.
4. Full seal of `FUN_007f5120` / `FUN_007f9160` (WQ7R-G).
5. Runtime / bit-exact / differential.

---

## 7. Verdict

**accept-with-gaps** — markup matrix, ABI, body bounds, and paint ordinals sealed from decompile + memory + call sites; product English and key-display helper internals open.
