# Review A (reconstruction fidelity): `aa_0045dd60` Anm_KestChunk_ReadF32Array_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045dd60` |
| **VA** | `0x0045dd60` |
| **Body** | `0x0045dd60`–`0x0045de07` inclusive (**168 B** / `0xA8`) |
| **Canonical name** | `Anm_KestChunk_ReadF32Array_Inferred` |
| **Ghidra symbol** | `FUN_0045dd60` |
| **Review date** | `2026-08-04` (W37-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0045dd60_Anm_KestChunk_ReadF32Array_Inferred.md` |
| **System** | `sto-chunk` / animation |
| **Live tools** | `batch_decompile`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Nested chunk reader for fourCC **KEST**: after EnterChunkScope, require tag match, bulk-read **`elem_count * 7`** f32 into dest (Pod28 packing), leave, return status. Tag miss → `-1`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0045dd60_FUN_0045dd60.md` (+ W37-P append + full hex) |
| Annotated | `docs/reconstruction/raw/aa_0045dd60_FUN_0045dd60.annotated.md` |
| Clean | `reconstructed-exact/Anm_KestChunk_ReadF32Array_Inferred.cpp` |
| Twin | `reconstructed-exact/FUN_0045dd60.cpp` |
| Live decompile | ≡ 2026-07-23 raw CF |
| Live body bytes | full 168 B via `read_memory` |
| Parent dual | `A/B_aa_00459750_AnmTrackMaster_Unserialize_Inferred` (W36-M) |
| Nested duals | EnterChunkScope, readF32Array (sealed) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body span | inclusive end `0045de07`; 168 B; pad `CC` |
| ECX → ESI | `8B F1` after SEH |
| EDI reader | `57` push into Enter; re-push before readF32Array |
| Tag imm | `81 7C 24 10 54 53 45 4B` → `0x4B455354` KEST |
| count*7 | `8D 04 F5 00..; 2B C6; 03 C0; 03 C0; C1 E8 02` |
| dest | `8B 4C 24 28` after frame (= stack formal) |
| Callees | rel32 → `004370b0`, `00436090`, `00769e40` |
| Epilog | dual `ADD ESP,20; C3` (bare RET) |
| Call site | parent `PUSH [this+0x20]; MOV ECX,count; MOV EDI,reader; CALL; ADD ESP,4` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive of pad | **pass** (168 B) |
| Formals ECX/EDI/stack sealed | **pass** (bytes + caller) |
| Tag KEST + *7 count | **pass** |
| Clean documents register ABI | **pass** |
| Product KEST English | **gap** |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | full hex + call site |
| Pod28 / track element role | **High** | parent resize + *7 |
| Name `_Inferred` structural | **Inferred** | fourCC + domain |
| Runtime | Open | |

---

## 6. Gaps

1. Product/PDB English for **KEST**.  
2. Full SEH / exception path not reconstructed line-by-line (scope leave on unwind via `LAB_009bef98`).  
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
