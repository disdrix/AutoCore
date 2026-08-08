# Review A (reconstruction fidelity): `aa_00573a30` FriendsList_FindEntryByNameI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573a30` |
| **VA** | `0x00573a30`–`0x00573a8b` exclusive |
| **Body size** | **91 B** (`0x5B`) |
| **Canonical name** | `FriendsList_FindEntryByNameI_Inferred` |
| **Ghidra name** | `FUN_00573a30` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00573a30_FriendsList_FindEntryByNameI_Inferred.md` |
| **System** | social / friends list (partition nest skills-abilities residual) |
| **Agent** | R11-005 OWN-ONLY dual |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_callers`, `get_function_xrefs`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/vector/name-key/callers sealed; product host class open |

---

## 1. Purpose

**Case-insensitive linear friends-list name lookup.** Walk pointer vector at **`this+0x8` / `this+0xc`**, compare each entry's C-string at **`entry+0x1a`** via **`_stricmp`**, return first matching entry pointer or **null**.

```c
// __thiscall; RET 0x4; EAX = entry* | 0
void* FriendsList_FindEntryByNameI_Inferred(void* listHost, char* name);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x00573a30` |
| Full listing | `disassemble_function` @ `0x00573a30` (both RET paths) |
| Body bytes | `read_memory` 104 B @ `0x00573a30` — ends dual `C2 04 00`, pad `CC` |
| Callers | `get_function_callers` → `FUN_0082f9a0`, `FUN_0094d900` |
| Xrefs | 3 UNCONDITIONAL_CALL: `0082f9de`, `0094d9d5`, `008304fe` (`FUN_00830010`) |
| Parent dual | `UI_InteractionMenu_AddFriendsToggle` (`aa_0082f9a0`) — friends membership |
| Sibling dual | `NameTable_FindEntryByNameI_Inferred` (`aa_00573af0`) — **different** vector/key |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 91 B / pad `CC` | **Confirmed** | disasm end + memory |
| `__thiscall` ECX=host, stack name | **Confirmed** | `MOV ESI,ECX`; `MOV EBX,[ESP+8]` |
| `RET 0x4` | **Confirmed** | both epilogues `C2 04 00` |
| Vector begin/end @ +0x8 / +0xc | **Confirmed** | disasm + decomp |
| Count `(end-begin)>>2` / begin==0 → 0 | **Confirmed** | |
| `_stricmp` case-insensitive | **Confirmed** | IAT call via EBP; decompiler name |
| Name key @ `entry+0x1a` | **Confirmed** | `ADD ECX,0x1a` |
| Return entry* / 0 | **Confirmed** | match load `[begin+i]`; miss `XOR EAX,EAX` |
| Friends-list role | **High** | dualed parent + `/friend` English + btn `0x1117a` |
| Product host/entry class name | **Open** | no RTTI on VA; `_Inferred` |
| Entry full layout | **Partial** | +0x1a name; +8/+0xc TFID from caller |

---

## 4. Control flow

```
i = 0
loop:
  count = (begin==0) ? 0 : (end - begin) >> 2   // begin=this+8, end=this+0xc
  if i >= count: return 0
  entry = begin[i]
  if _stricmp(entry+0x1a, name) == 0: return entry
  i++
  goto loop
```

---

## 5. Decompile ≡ raw

Live R11-005 decompile matches frozen 2026-07-23 raw body (same CF, offsets, callee). ABI sealed beyond decompiler via `disassemble_function` + `read_memory` (`RET 0x4`, IAT `_stricmp`).

---

## 6. Gaps (acceptable)

1. Product class / MSVC name for list host (`DAT_00d1da2c`) and entry type.
2. Full entry layout beyond name@+0x1a and TFID@+8/+0xc.
3. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** — structural contract sealed; product English open → `_Inferred`.
