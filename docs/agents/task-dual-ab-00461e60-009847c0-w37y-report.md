# Dual A/B report — W37-Y OWN `aa_00461e60` + `aa_009847c0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-Y  
**Scope:** VAs `0x00461e60`, `0x009847c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `force_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context` + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-Y).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00461e60` RcElem28_AssignRange | **accept-with-gaps** — EAX=dest / stack src_first+src_last / plain RET / returns dest* / 138 B / RC@+0x10 forward assign sealed; product English open |
| `aa_009847c0` AssPackManager_PrepReplaceExistingEntry_Inferred | **accept-with-gaps** — ECX pathBuf / EDX host / stack name / RET 4 / 0|−1 / 204 B / CS+lookup+clear+push sealed; nested node/push product open |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## VA `0x00461e60` — sealed facts

1. **Body:** `0x00461e60`–`0x00461eea` exclusive (**138 B** / `0x8A`; pad `CC`×6 then `FUN_00461ef0` / `RcElem28_AssignBackward`).
2. **ABI:** **EAX=dest\***, stack **src_first\***, **src_last\***, plain **`RET`** (`C3`); returns final dest\* in **EAX**. Parent may push a third unread stack dword and cleans with **`ADD ESP,0xC`**.
3. **Semantics:** MSVC-style **forward assign-range** on live **RcElem28** (stride **0x1c**):
   - Copy dwords +0x00..+0x0C; AddRef source resource `@+0x10` (vtbl+4 if refcount becomes 1); Release dest resource (vtbl+8 if 0); store; copy +0x14..+0x16 and +0x18.
   - Empty range returns dest unchanged. **Not** uninit-copy / destroy / fill / backward.
4. **Classification:** leaf.
5. **Callers (1):** `FUN_00461720` (`StdVector_EraseRange_RcElem28`) @ `0x0046173e` — erase tail `[last,end) → first`.
6. **Name:** `RcElem28_AssignRange` (Ghidra `FUN_00461e60`; **Inferred** structural). Reject scaffold `Named_CalleeOf_*gfxDevice*`.
7. **Decompile ≡ bytes** for CF/RC; **bytes win** on EAX dest + return and dead third stack slot.  
   Full hex: raw W37-Y append (138 B).

### Gaps

- Product/PDB T English (gfx residual only).  
- Exact AddRef-when-becomes-1 semantics residual (shared with W34/W35 RcElem28 family).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00461e60_RcElem28_AssignRange.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00461e60_RcElem28_AssignRange.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00461e60_FUN_00461e60.md` |
| Annotated | `docs/reconstruction/raw/aa_00461e60_FUN_00461e60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_AssignRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00461e60.cpp` |
| Function | `docs/reconstruction/functions/aa_00461e60_FUN_00461e60.md` |
| Function named | `docs/reconstruction/functions/aa_00461e60_RcElem28_AssignRange.md` |

---

## VA `0x009847c0` — sealed facts

1. **Body:** `0x009847c0`–`0x0098488c` exclusive (**204 B** / `0xCC`; pad `CC`×4 then `FUN_00984890`).
2. **ABI:** **ECX=pathBuf\***, **EDX=host\***, stack **nameOrCookie\***, **`RET 4`**; returns **0** hit / **`0xFFFFFFFF`** miss. **Not** ECX-thiscall on host. Decompiler 2-arg `__fastcall` incomplete — **bytes win**.
3. **Semantics:** AssPack **replace-prep** for existing entry:
   - Optional CS: gate **`host+0x50`**, section **`host+0x38`**.
   - `FUN_00719630` path normalize into pathBuf; `FUN_00989e00` lookup with **ECX=`DAT_00d1eac8`**.
   - `FUN_0044e8c0` HashMap find (**EDI=host**, **EBX=key\***); miss if it == **`host+8`**.
   - Hit: **`*(entry+0x1C) = DAT_00d1eac0`** (empty shared); `FUN_00469c80` push/grow on **`*(entry+0x24)+0x30`** (RcElem28-stride vector family).
4. **Classification:** worker.
5. **Callers (1):** `FUN_00984910` (`AssPackManager_AddOrReplaceFileInPack_Inferred`) @ `0x00984a18` (replace branch after skip-same fails).
6. **Callees:** CS APIs, `FUN_00719630`, `FUN_00989e00`, `FUN_0044e8c0`, `FUN_00469c80`.
7. **Name:** `AssPackManager_PrepReplaceExistingEntry_Inferred` (Ghidra `FUN_009847c0`; **Inferred** from parent `assPackManager.cpp` + call site). Reject scaffold `Named_*assPackManager*`.
8. **Decompile ≡ bytes** for CS/miss/hit CF; **bytes win** on third stack formal + `RET 4`.  
   Full hex: raw W37-Y append (204 B).

### Gaps

- Product English for `nameOrCookie` / entry field plates.  
- Nested `FUN_00469c80` push-value construction (not OWN).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009847c0_AssPackManager_PrepReplaceExistingEntry_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009847c0_AssPackManager_PrepReplaceExistingEntry_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009847c0_FUN_009847c0.md` |
| Annotated | `docs/reconstruction/raw/aa_009847c0_FUN_009847c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_PrepReplaceExistingEntry_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009847c0.cpp` |
| Function | `docs/reconstruction/functions/aa_009847c0_FUN_009847c0.md` |
| Function named | `docs/reconstruction/functions/aa_009847c0_AssPackManager_PrepReplaceExistingEntry_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00461e60` | Port as **RC forward assign-range** stride **0x1c**: **EAX=dest**, stack **src_first+src_last**, plain RET, return final dest. Honor AddRef-before-Release on `@+0x10`. Do **not** memmove; do **not** skip Release (not uninit). Required by erase-range tail move. |
| `009847c0` | Port as **AssPack replace-prep**: **ECX pathBuf**, **EDX host**, stack **name**, **`RET 4`**, return 0/−1. Preserve CS gate, cache lookup, map miss, clear `entry+0x1C` to empty shared, deferred push. Do **not** implement full remove or compress/insert here. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x00461720` | `StdVector_EraseRange_RcElem28` (W36-N) — sole parent of assign-range |
| `0x00460d70` | per-elem Release leaf (erase leftover destroy) |
| `0x00461b80` / `0x00461ef0` | AssignFillRange / AssignBackward siblings (W35-P) |
| `0x00984910` | `AssPackManager_AddOrReplaceFileInPack_Inferred` (W33-Q) — sole parent of replace-prep |
| `0x0044e8c0` | HashMap find (W21-N) |
| `0x00989e00` | ResourceCache lookup by name |
| `0x00469c80` | RcElem28-stride vector push/grow |

Together they close the **erase-range move engine** residual called out in W36-N and the **replace-prep** residual called out in W33-Q AddOrReplace.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly_context at call sites. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; `_Inferred` / structural names only (`RcElem28_*` family; `AssPackManager_*_Inferred` tied to parent path string).  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).
