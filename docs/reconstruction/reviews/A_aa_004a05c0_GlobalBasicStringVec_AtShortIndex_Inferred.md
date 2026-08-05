# Review A (reconstruction fidelity): `aa_004a05c0` GlobalBasicStringVec_AtShortIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a05c0` |
| **VA** | `0x004a05c0` |
| **Body** | `0x004a05c0`–`0x004a0629` inclusive (**106 B** / `0x6A`); pad `CC` then `FUN_004a0630` |
| **Canonical name** | `GlobalBasicStringVec_AtShortIndex_Inferred` (**Inferred**); Ghidra `FUN_004a05c0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004a05c0_GlobalBasicStringVec_AtShortIndex_Inferred.md` |
| **System** | Global string table / MSVC `basic_string` vector lookup |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context` (no `disassemble_bytes`) |
| **Verdict** | **accept** — CF/ABI/bounds/stride sealed; product table owner open (non-blocking) |
| **Dual status** | **Present (W38-AF)** |

---

## 1. Purpose

Copy-out a `std::basic_string` from a **global vector** by **signed short index**:

```
begin = DAT_00b0360c;
end   = DAT_00b03610;
count = (begin == 0) ? 0 : (end - begin) / 0x1c;

if (count <= (uint32_t)(int32_t)index)   // MOVSX short; negative → OOB
  return basic_string(out, "");
else
  return basic_string(out, &begin[index]);  // element @ begin + index*0x1c
```

**ABI:** `__cdecl`; stack `(out_string*, int16 index)`; returns `out*`; caller `ADD ESP,8`.

Element size **`0x1c`** matches classic MSVC `basic_string` layout used elsewhere in this binary.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x004a05c0` (2026-08-04) — **≡ raw** |
| Complete analysis | 6 xrefs; callers `FUN_004b88e0`, `FUN_00491480`, `FUN_00491a00` |
| Machine | `read_memory` `0x004a05c0` length 128 → body **106 B** then `CC` |
| Call sites | `get_assembly_context` — all `ADD ESP,8`; index from `word` fields |
| Mission consumer | W32-H `MissionHost_CollectMediaPreloads_Inferred` |
| Scaffold | `raw/aa_004a05c0_*`, `reconstructed-exact/FUN_004a05c0.cpp` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| Load begin `DAT_00b0360c` | `8b 35 0c 36 b0 00` | **Confirmed** |
| Load end `DAT_00b03610` | `8b 0d 10 36 b0 00` | **Confirmed** |
| Div by `0x1c` (magic) | `b8 93 24 49 92 f7 e9` … | **Confirmed** |
| Index `MOVSX` short | `0f bf 4c 24 10` | **Confirmed** |
| OOB → empty ctor `""` @ `0x00a1419b` | `68 9b 41 a1 00` + `ff 15 … ctor` | **Confirmed** |
| In-range: `index*0x1c` + copy-ctor | `8d 04 cd 00 00 00 00; 2b c1; 8d 04 86` + copy-ctor IAT | **Confirmed** |
| Return out in EAX | `8b c6` both exits | **Confirmed** |
| Epilogue / plain `ret` | `5e 59 c3` (pop esi; pop ecx; ret) | **Confirmed** |
| Body 106 B | last `c3` @ `0x004a0629`; next `CC` | **Confirmed** |

Full hex (106 B):

```
51568b350c36b00033c03bf089442404741b8b0d1036b0002bceb893244992f7e903d1c1fa048bc2c1e81f03c20fbf4c24103bc872168b74240c689b41a1008bceff15f8629c008bc65e59c38d04cd000000002bc18d04868b74240c508bceff15ec629c008bc65e59c3
```

---

## 4. Callers / callees

| Direction | Detail |
|---|---|
| Callees | `basic_string` ctor(`const char*`); `basic_string` copy-ctor |
| Callers | Mission media preload (word resource ids); two host helpers writing short field ids into string temps |

---

## 5. Confidence table

| Claim | Level |
|---|---|
| Control flow ≡ live | **Confirmed** |
| Stride `0x1c` string elements | **Confirmed** |
| Short index + OOB empty | **Confirmed** |
| cdecl `ADD ESP,8` | **Confirmed** |
| Product table owner name | **None** (gap, non-blocking for structure) |

---

## 6. Verdict

**accept** — structure fully sealed from decompile ≡ machine; only product English for the global table remains open.
