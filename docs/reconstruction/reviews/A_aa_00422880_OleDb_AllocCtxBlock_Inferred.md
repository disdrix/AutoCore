# Review A (reconstruction fidelity): `aa_00422880` OleDb_AllocCtxBlock_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422880` |
| **VA** | `0x00422880`–`0x004228c7` (logical `ret 8` via `FUN_004228d1`) |
| **Body** | Ghidra **72 B** + SEH status tail |
| **Canonical name** | `OleDb_AllocCtxBlock_Inferred` |
| **Prior scaffold** | `FUN_00422880` |
| **Review date** | `2026-07-29` (W24-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` |
| **System** | COM / OLE DB ctx gate alloc |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

SEH-framed **stdcall** helper that fills a two-field block:

| Off | Role |
|---:|---|
| `+0` | `void*` = `operator_new[](count * 8)` |
| `+4` | `int32` count |

Returns **HRESULT**: `S_OK` (0) if alloc non-null, else `E_OUTOFMEMORY` (`0x8007000E`).

Sole caller: `OleDb_BuildBindingsAllocRow_Inferred` when `*ctx==0` with **`count=1`**.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00422880` + tail `0x004228d1` |
| Bytes | `read_memory` 80 B entry + 40 B @ `004228d1` |
| Bounds | `get_function_by_address` body `00422880`–`004228c7` |
| Callees | `operator_new[]` @ `00489834`; tail `FUN_004228d1` |
| Callers | sole xref `FUN_0042139b` @ `0x00421604` (`push 1; push ebx`) |
| Raw / clean | `aa_00422880_*`, `OleDb_AllocCtxBlock_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `param_1[1]=count`; `*param_1=0` then alloc | **Confirmed** | bytes + decomp |
| Alloc size `count*8` | **Confirmed** | three `add eax,eax` |
| `operator_new[]` rel32 → `00489834` | **Confirmed** | callees + arithmetic |
| HRESULT via `neg/sbb` + `0x7FF8FFF2` + `0x8007000E` | **Confirmed** | tail bytes |
| `ret 8` | **Confirmed** | `C2 08 00` |
| Decompiler `void` understates | **Confirmed residual** | |
| Product English name | **Inferred** | role from OleDb sole caller |
| Buffer element product typedef | **Open** | 8-byte stride only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH install | Yes (raw/decomp; clean abstracts) |
| Store count / zero ptr | Yes |
| `new[](count*8)` / store | Yes |
| HRESULT return | Yes (clean returns `int32_t`) |
| `ret 8` | Yes (documented; clean plate) |

---

## 5. Gaps / open

1. Product C++ type of the 8-byte slot(s) in the allocated buffer.
2. Whether non-OleDb callers ever existed in other images.
3. Runtime / bit-exact / differential.
4. Full SEH filter body at `LAB_009bc010` — compiler glue, not product logic.

**Verdict:** **accept**
