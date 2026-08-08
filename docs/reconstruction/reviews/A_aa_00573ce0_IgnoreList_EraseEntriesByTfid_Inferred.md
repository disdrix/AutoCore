# Review A (reconstruction fidelity): `aa_00573ce0` IgnoreList_EraseEntriesByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573ce0` |
| **VA** | `0x00573ce0`–`0x00573d4c` exclusive |
| **Body size** | **108 B** (`0x6c`) |
| **Canonical name** | `IgnoreList_EraseEntriesByTfid_Inferred` |
| **Ghidra name** | `FUN_00573ce0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00573ce0_IgnoreList_EraseEntriesByTfid_Inferred.md` |
| **System** | social / ignore list (partition nest skills-abilities residual) |
| **Agent** | R13-040 OWN-ONLY dual (dual start **2686**) |
| **Parent dual** | `IgnoreList_FindEntryByTfid_Inferred` `0x00573a90` (R12-025) |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_callers`, `get_function_xrefs`, `get_assembly_context`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/vector/TFID-key/delete+compact/sole-caller sealed; product host class + unused-arg English open |

---

## 1. Purpose

**Erase all ignore-list entries matching a TFID pair.** Walk pointer vector at **`this+0x38` / `this+0x3c`**, compare each entry's int pair at **`entry+0x08` / `entry+0x0c`**, and on match: free the heap entry, zero the slot, `memmove` compact, shrink end by one pointer, re-scan the current slot. Always returns **0**.

```c
// __thiscall; RET 0x10; EAX = 0
// unused1/unused2 cleaned but unread
int IgnoreList_EraseEntriesByTfid_Inferred(
    void* listHost, int unused1, int unused2, int tfid_lo, int tfid_hi);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x00573ce0` |
| Full listing | `disassemble_function` @ `0x00573ce0` (empty + match + miss paths; `RET 0x10`) |
| Body bytes | `read_memory` 128 B @ `0x00573ce0` — ends `C2 10 00`, pad `CC`, next `FUN_00573d50` |
| Callers | `get_function_callers` → `FUN_0080eeb0` only |
| Xrefs | 1 UNCONDITIONAL_CALL: `0080ef7c` |
| Caller site | `get_assembly_context` + decompile `FUN_0080eeb0` — remove-ignore English + find then erase |
| Parent dual | `IgnoreList_FindEntryByTfid_Inferred` (`aa_00573a90`) — read-only twin same vector |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 108 B / pad `CC` | **Confirmed** | disasm end + memory |
| `__thiscall` ECX=host | **Confirmed** | `MOV EDI,ECX` |
| Stack four dwords; **`RET 0x10`** | **Confirmed** | `C2 10 00` |
| Body uses only stack args 3–4 as TFID | **Confirmed** | `[ESP+0x1c]` / `[ESP+0x20]` after 4 callee pushes |
| Args 1–2 unread by body | **Confirmed** | no loads of those slots |
| Vector begin/end @ +0x38 / +0x3c | **Confirmed** | disasm + decomp |
| TFID key @ `entry+0x08` / `+0x0c` | **Confirmed** | dual CMP |
| Match: delete + zero + memmove + end−4 | **Confirmed** | full match path |
| No cursor advance after erase | **Confirmed** | JMP to end-compare without ESI/EBX +=4 |
| Always return 0 | **Confirmed** | `XOR EAX,EAX` |
| `operator_delete` returns (not noreturn) | **Confirmed** | `ADD ESP,4` then continue |
| Ignore-list role | **High** | sole caller remove-ignore English + parent find |
| Product host/entry class name | **Open** | no RTTI on VA; `_Inferred` |
| Why unused arg1/arg2 exist | **Open** | caller still pushes them |

---

## 4. Control flow

```
cur = begin = this+0x38; end = this+0x3c
if cur == end: return 0
next = cur + 1
loop:
  entry = *cur
  if entry+8 == tfid_lo AND entry+0xc == tfid_hi:
    if entry != 0: operator_delete(entry)
    *cur = 0
    memmove(cur, next, (end - next) bytes)
    end -= 4   // this+0x3c
    // do not advance cur/next
  else:
    cur += 1; next += 1
  if cur != end: goto loop
return 0
```

---

## 5. Decompile ≡ raw

Live R13-040 decompile matches frozen 2026-07-23 raw body (same CF, offsets, keys, delete+memmove). ABI width sealed beyond decompiler via `disassemble_function` + `read_memory` (`RET 0x10`, four stack args). Decompiler false-noreturn on `operator_delete` corrected by memory (`83 C4 04`).

---

## 6. Gaps (acceptable)

1. Product class / MSVC name for list host and entry type.
2. English for unused stack arg1/arg2 (caller plate leftover?).
3. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** — structural mutator contract sealed; product English open for class → `_Inferred`.
