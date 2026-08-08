# Review A (reconstruction fidelity): `aa_005739d0` FriendsList_FindEntryByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005739d0` |
| **VA** | `0x005739d0`–`0x00573a28` exclusive |
| **Body size** | **88 B** (`0x58`) |
| **Canonical name** | `FriendsList_FindEntryByTfid_Inferred` |
| **Ghidra name** | `FUN_005739d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_005739d0_FriendsList_FindEntryByTfid_Inferred.md` |
| **System** | social / friends list (partition nest skills-abilities residual) |
| **Agent** | R13-039 OWN-ONLY dual (dual start 2686) |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_callers`, `get_function_xrefs`, `read_memory`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/vector/TFID-key/callers sealed; product host class open |

---

## 1. Purpose

**Exact TFID-pair linear friends-list lookup.** Walk pointer vector at **`this+0x8` / `this+0xc`**, compare each entry's int pair at **`entry+0x08` / `entry+0x0c`**, return first matching entry pointer or **null**.

```c
// __thiscall; RET 0x8; EAX = entry* | 0
void* FriendsList_FindEntryByTfid_Inferred(void* listHost, int tfid_lo, int tfid_hi);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x005739d0` |
| Complete analysis | `analyze_function_complete?name=FUN_005739d0` — leaf; 3 xrefs; 0 callees |
| Full listing | `disassemble_function` @ `0x005739d0` (both RET paths) |
| Body bytes | `read_memory` 96 B @ `0x005739d0` — ends dual `C2 08 00`, pad `CC` |
| Callers | `get_function_callers` → `FUN_0080f3b0`, `FUN_00574020`, `FUN_00574270` |
| Xrefs | 3 UNCONDITIONAL_CALL: `00574031`, `00574281`, `0080f3f5` |
| Partition parent dual | `IgnoreList_FindEntryByTfid_Inferred` (`aa_00573a90`) — same TFID algorithm, **+0x38** vector |
| Sibling dual | `FriendsList_FindEntryByNameI_Inferred` (`aa_00573a30`) — **same +0x8** vector, name key |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 88 B / pad `CC` | **Confirmed** | disasm end + memory |
| `__thiscall` ECX=host, stack TFID lo/hi | **Confirmed** | ESI from `[ECX+0x8]`; EDI/EBX stack args |
| `RET 0x8` | **Confirmed** | both epilogues `C2 08 00` |
| Vector begin/end @ +0x8 / +0xc | **Confirmed** | disasm + decomp |
| Count `(end-begin)>>2` / begin==0 → 0 | **Confirmed** | |
| TFID key @ `entry+0x08` / `+0x0c` | **Confirmed** | dual CMP |
| Return entry* / 0 | **Confirmed** | match load `[begin+i]`; miss `XOR EAX,EAX` |
| Leaf (no callees) | **Confirmed** | analyze_function_complete |
| Friends-list role | **High** | "Your friend" English + same vector as dualed friends name find |
| Product host/entry class name | **Open** | no RTTI on VA; `_Inferred` |
| Entry full layout | **Partial** | +8/+0xc TFID; +0x1a name from caller |

---

## 4. Control flow

```
i = 0
loop:
  count = (begin==0) ? 0 : (end - begin) >> 2   // begin=this+0x8, end=this+0xc
  if i >= count: return 0
  entry = begin[i]
  if entry+8 == tfid_lo AND entry+0xc == tfid_hi: return entry
  i++
  goto loop
```

---

## 5. Decompile ≡ raw

Live R13-039 decompile matches frozen 2026-07-23 raw body (same CF, offsets, keys). ABI sealed beyond decompiler via `disassemble_function` + `read_memory` (`RET 0x8`).

---

## 6. Gaps (acceptable)

1. Product class / MSVC name for list host (`DAT_00d1da2c`) and entry type.
2. Full entry layout beyond TFID@+8/+0xc and name@+0x1a.
3. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** — structural contract sealed; product English open for class → `_Inferred`.
