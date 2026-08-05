# Dual A/B report — W29-C OWN `aa_00436860` + `aa_00423e00`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-C  
**Scope:** VAs `0x00436860`, `0x00423e00` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave29

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00436860` StdDeque_ThrowTooLong_00436860 | **accept** — compact noreturn `"deque<T> too long"` throw (75 B); multi-caller map-grow overflow helper sealed |
| `aa_00423e00` AssManager_RemoveResolver_Inferred | **accept** — ECX/EAX remove-resolver: find @ this+0x58 → log miss or EraseFirstEqual sealed (68 B) |

---

## VA `0x00436860` — sealed facts

1. **Body:** `0x00436860`–`0x004368aa` (**75 B** / `0x4B`; pad `CC` @ `0x004368ab`).
2. **ABI:** **no formals**; SEH frame (`LAB_009bc919`); **noreturn** (ends in `_CxxThrowException`).
3. **Semantics:** `basic_string("deque<T> too long")` @ `0x00a31520` → `FUN_00401a40` (exception + vftable `PTR_FUN_009c7634`) → `_CxxThrowException(&ex, &DAT_00acc388)`.
4. **Classification:** worker noreturn — callees string IAT + `FUN_00401a40` + `_CxxThrowException`.
5. **Callers (4):** `FUN_00436650` (CircularPtrBuf_Grow), `FUN_0043c9b0` (GuardedVector_GrowBlockMap), `FUN_0043d990`, `FUN_0043ea60`.
6. **Name:** `StdDeque_ThrowTooLong_00436860` (Ghidra `FUN_00436860`; **Inferred** structural; VA-qualified vs sibling plate clones `0040ff30` / `0051b5f0` / `005b2a80` — **not** byte-merged; this clone is compact via `FUN_00401a40`).
7. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product / PDB `_Xlen` English.  
- Exception C++ type / ThrowInfo RTTI.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00436860_StdDeque_ThrowTooLong_00436860.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00436860_StdDeque_ThrowTooLong_00436860.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00436860_FUN_00436860.md` |
| Annotated | `docs/reconstruction/raw/aa_00436860_FUN_00436860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdDeque_ThrowTooLong_00436860.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00436860.cpp` |
| Function | `docs/reconstruction/functions/aa_00436860_FUN_00436860.md` |
| Function named | `docs/reconstruction/functions/aa_00436860_StdDeque_ThrowTooLong_00436860.md` |

---

## VA `0x00423e00` — sealed facts

1. **Body:** `0x00423e00`–`0x00423e43` (**68 B** / `0x44`; pad `CC` after plain `RET`).
2. **ABI:** **ECX** = assManager `this`; **EAX** = resolver key (dword); frame saves ECX/ESI; plain **`RET`**. Decompiler `void(void)` is incomplete.
3. **Semantics:** `container = this+0x58`; if `!FUN_0043e5b0(&key)` (find with **EAX**=container) → `vog_LogMessage(assManager.cpp, 0x27b, 3, "Removing resolver not found")` and return; else `FUN_0043c550(&key)` / `GuardedVector_EraseFirstEqual` (**ESI**=container).
4. **Strings:** path `0x00a9e930`, msg `0x00a9e888` (`read_memory`).
5. **Classification:** worker — callees find + log + erase (erase dual sealed W28-C).
6. **Callers (1):** only `FUN_007b65d0` @ `0x007b65df` — `EAX=[EBX+8]`, `ECX=[DAT_00d1f058]`.
7. **Name:** `AssManager_RemoveResolver_Inferred` (Ghidra `FUN_00423e00`; **Inferred** from plate path + message + CF).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23; register ABI sealed via caller + body bytes).

### Gaps

- Product/PDB method English.  
- Resolver key type beyond dword equality.  
- Nested find helper dual (not OWN).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00423e00_AssManager_RemoveResolver_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00423e00_AssManager_RemoveResolver_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00423e00_FUN_00423e00.md` |
| Annotated | `docs/reconstruction/raw/aa_00423e00_FUN_00423e00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssManager_RemoveResolver_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00423e00.cpp` |
| Legacy clean | `docs/reconstruction/reconstructed-exact/Named_assManager_00423e00.cpp` |
| Function | `docs/reconstruction/functions/aa_00423e00_FUN_00423e00.md` |
| Function named | `docs/reconstruction/functions/aa_00423e00_AssManager_RemoveResolver_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00436860` | Map/block grow overflow arms must **throw** (or equivalent hard length-error) with message `"deque<T> too long"` — not soft-fail. Shared by CircularPtrBuf + GuardedVector grow paths. Do not merge with other plate clones without byte proof. |
| `00423e00` | Resolver remove: look up key in assManager list at **+0x58**; log miss; else first-equal erase. Call with **manager + key** (not void). Do not invent erase-all or hard-fail on miss. Closes residual caller path left open by W28-C EraseFirstEqual dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Avoided bare `undefined4` in clean (used `uint8_t` / `uint32_t` / explicit types).  
- Pattern: `docs/agents/task-dual-ab-0043d300-0043c550-w28c-report.md` / W21-E throw helper.
