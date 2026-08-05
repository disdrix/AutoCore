# Dual A/B report — W37-Z OWN `aa_0044a380` + `aa_0076bc00`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-Z  
**Scope:** VAs `0x0044a380`, `0x0076bc00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site context + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-Z).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0044a380` StdVector_DwordResize_EaxCount_Inferred | **accept** — ECX=vec / EAX=n / stack fill / RET 4 / dword grow+shrink sealed |
| `aa_0076bc00` Fs_CreateDirectoryForce_Inferred | **accept** — cdecl path+force / bool AL / dir-wipe vs file-unlink / CreateDirectoryA sealed |

---

## VA `0x0044a380` — sealed facts

1. **Body:** `0x0044a380`–`0x0044a3e9` exclusive (**105 B** / `0x69`; pad `CC` then next).
2. **ABI:** **ECX=`vec*`**, **EAX=`newCount`**, stack **`fill`** (dword); **`RET 4`**. Decompiler `__fastcall(int)` + phantom `in_EAX` incomplete — **bytes win**.
3. **Semantics:** MSVC-style **`vector<uint32_t>::resize(n, value)`**:
   - `size = begin(+4) ? (end(+8)−begin)>>2 : 0`.
   - Grow: `FUN_00463e30(this, end, n−size, &fill)` InsertN.
   - Shrink: `FUN_00469f10(begin+n*4, end)` with **EBX=this**.
   - Equal / empty: no-op.
4. **Classification:** worker.
5. **Callers (12 fn + 1 raw):** `FUN_00436b00`, `FUN_0043ba40`, `FUN_0043fb50`, `FUN_00443530`, `FUN_0044a140`, `FUN_0044e650`, `FUN_004638c0`, `FUN_00464340`, `FUN_00469910`, **`FUN_0046bf90`** (NestedHash0x10 insert rehash @ `0x0046bfe3`), `FUN_0046c8f0`, `FUN_00746d40`; raw `0x0096015d`.
6. **Callees:** `FUN_00463e30` (InsertN/grow), `FUN_00469f10` (erase/shrink).
7. **Name:** `StdVector_DwordResize_EaxCount_Inferred` (Ghidra `FUN_0044a380`; **Inferred**). **Reject** `Named_CalleeOf_Named_effVertexDecl_0044a380`.
8. **Twin:** `FUN_004367f0` same CF but **stack n + fill**, **`RET 8`** — do not merge.
9. **Decompile vs bytes:** CF ≡ raw; **bytes win** on EAX count, fill formal, RET 4.  
   Full hex: raw W37-Z append (105 B).

### Gaps

- Product/PDB STL mangled English.  
- Unowned grow/shrink callee duals.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044a380_StdVector_DwordResize_EaxCount_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0044a380_StdVector_DwordResize_EaxCount_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0044a380_FUN_0044a380.md` |
| Annotated | `docs/reconstruction/raw/aa_0044a380_FUN_0044a380.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DwordResize_EaxCount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044a380.cpp` |
| Function | `docs/reconstruction/functions/aa_0044a380_FUN_0044a380.md` |
| Function named | `docs/reconstruction/functions/aa_0044a380_StdVector_DwordResize_EaxCount_Inferred.md` |

---

## VA `0x0076bc00` — sealed facts

1. **Body:** `0x0076bc00`–`0x0076bc79` exclusive (**121 B** / `0x79`; pad `CC` then `FUN_0076bc80`).
2. **ABI:** **cdecl** `const char* path`, `char force_clear`; **bool AL**; frame `SUB ESP,0x24` / `ADD ESP,0x24; RET`. Callers `ADD ESP,8`.
3. **Semantics:** **CreateDirectoryA** with optional force clear:
   - force + **directory** (`FUN_0076adc0`): `FUN_0076ba10(path,1)` wipe tree → CreateDirectoryA → return.
   - force + **regular file** (`stat` + `_S_IFREG` bit 15): `FUN_0076b080(1)` with **ESI=path**.
   - else / fall-through: CreateDirectoryA; return success.
4. **Classification:** worker.
5. **Callers (4):** `FUN_004b52e0` @ `0x004b5572`; `FUN_0076bc80` @ `0x0076bd5a`; `FUN_007a13e0` @ `0x007a1474`; **`FUN_00985010`** CompactPackFile @ `0x009850b5` (force=1).
6. **Callees:** `FUN_0076adc0`, `FUN_0076ba10`, `FUN_0076b080`, `stat`, `CreateDirectoryA`.
7. **Name:** `Fs_CreateDirectoryForce_Inferred` (Ghidra `FUN_0076bc00`; **Inferred**). **Reject** `Named_CalleeOf_Named_NDRenderEngine_0076bc00`.
8. **Decompile vs bytes:** CF ≡ raw; **bytes win** on force gate, `_S_IFREG` (`SHR 0xF`), SETNZ returns.  
   Full hex: raw W37-Z append (121 B).

### Gaps

- Product/PDB English.  
- Full `FUN_0076b080` plate (ESI=path sealed by peer DeleteDirTree).  
- Non-force + already-exists-as-dir intentionality.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0076bc00_Fs_CreateDirectoryForce_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0076bc00_Fs_CreateDirectoryForce_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0076bc00_FUN_0076bc00.md` |
| Annotated | `docs/reconstruction/raw/aa_0076bc00_FUN_0076bc00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_CreateDirectoryForce_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076bc00.cpp` |
| Function | `docs/reconstruction/functions/aa_0076bc00_FUN_0076bc00.md` |
| Function named | `docs/reconstruction/functions/aa_0076bc00_Fs_CreateDirectoryForce_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0044a380` | Port as **dword vector resize**: **ECX=vec**, **EAX=n**, stack **fill**, **RET 4**. begin@+4 end@+8 stride 4. Do **not** use `FUN_004367f0` stack/`RET 8` twin ABI. Critical under NestedHash0x10 insert rehash (`0046bf90`). |
| `0076bc00` | Port as **force-capable CreateDirectory**: cdecl path+flag, bool return. Force=dir → recursive wipe then create; force=file → unlink then create. CompactPackFile / mkpath consumers. |
| Shared | Unrelated domains (container vs FS); co-owned only as W37-Z partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x004367f0` | StdVector_DwordResize stack-count / RET 8 twin |
| `0x00463e30` | InsertN / grow-realloc for EAX-count resize |
| `0x00469f10` | Erase-range shrink (EBX=vec) |
| `0x0046bf90` | NestedHash0x10_Insert (W36-B) — rehash caller |
| `0x00457ac0` | NestedHash_Ctor_Sentinel0x10 (W34-E) |
| `0x0076adc0` | Fs_PathIsDirectory_Stat (W33-C) |
| `0x0076ba10` | Fs_DeleteDirTreeRecursive (W34-A) |
| `0x0076b080` | Force file unlink (ESI=path) |
| `0x0076bc80` | Sibling mkpath-style caller |
| `0x00985010` | AssPackManager_CompactPackFile |

Closes W37-Z OWN pair: NestedHash bucket-vector **resize** helper + FS **force create-directory** left open as nested callees under hash rehash / pack compact paths.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Distinguished EAX-count resize from stack-count `StdVector_DwordResize` twin.  
- Distinguished `_S_IFREG` (bit 15) from directory (handled by peer is-dir).  
- Terminal coverage: **false** always.
