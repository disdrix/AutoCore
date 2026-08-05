# Review A (reconstruction fidelity): `aa_00458510` StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00458510` |
| **VA** | `0x00458510` |
| **Body** | `0x00458510`–`0x004585C5` exclusive (**181** B) |
| **Canonical name** | `StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00458510` |
| **Prior / alias** | `Named_CalleeOf_…_Palantir_00458510` (reject product) |
| **Review date** | `2026-08-04` (W37-K OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md` |
| **System** | std map insert-or-find |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert-or-find a unique map entry by **unsigned** 32-bit key under isnil@+0x15 (Val8) tree layout, using register ABI (EAX map, EBX value*). Write `{iterator, inserted}`; on equal key do not rewrite mapped dword.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00458510_FUN_00458510.md` (+ W37-K append) |
| Annotated | `docs/reconstruction/raw/aa_00458510_FUN_00458510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_00458510.cpp` |
| Function record | `docs/reconstruction/functions/aa_00458510_StdMap_InsertOrFind_UintKey_Isnil15_EaxEbx_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | full 181 B hex in raw append |
| Wrapper context | W35-H `FUN_00444850` FourCC ensure |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | `51 55 8B 6C 24 0C 56 57 8B F8` — out in EBP; `MOV EDI,EAX` map |
| Key walk | `3B 50 0C` / `0F 92 C1` — cmp key; **SETB** (unsigned) |
| Equal gate | `3B 0B 73 23` — cmp / **JAE** (unsigned) |
| isnil | `80 78 15 00` — byte `@+0x15` |
| Epilogue | `5D 59 C2 04 00` — pop ebp; pop ecx; **RET 4** ×3 |
| Body end | exclusive `0x004585C5` (pad `cc` after) |

Full hex: see raw W37-K append.

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size exclusive end | **pass** (`004585C5` / 181 B) |
| `ret 4` / single stack out | **pass** |
| EAX=map, EBX=value* | **pass** (bytes + decompiler unaff) |
| Unsigned key compare | **pass** (`SETB`/`JAE`) |
| isnil@+0x15 / key@+0x0C | **pass** |
| Equal → inserted=0 no rewrite | **pass** |
| Clean has no bare `undefined4` | **pass** (`uint32_t` / structs) |
| Insert helper internals | **gap** (unOWN `FUN_00438140`) |
| Product English | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 4 sealed |
| Unsigned uint key | **High** | opcodes |
| Multi-caller shared helper | **High** | 6 xrefs |
| Name structural `_Inferred` | **Inferred** | no product plate |
| Runtime / differential | Open | |

---

## 6. Gaps (acceptable)

1. Full dual of insert helper `FUN_00438140` / buynode `FUN_00439110`.  
2. Product/demangle names for the six caller maps.  
3. Runtime / bit-exact / differential.
