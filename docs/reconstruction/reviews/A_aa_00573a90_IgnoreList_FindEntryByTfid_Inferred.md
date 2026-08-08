# Review A (reconstruction fidelity): `aa_00573a90` IgnoreList_FindEntryByTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573a90` |
| **VA** | `0x00573a90`–`0x00573ae7` exclusive |
| **Body size** | **87 B** (`0x57`) |
| **Canonical name** | `IgnoreList_FindEntryByTfid_Inferred` |
| **Ghidra name** | `FUN_00573a90` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00573a90_IgnoreList_FindEntryByTfid_Inferred.md` |
| **System** | social / ignore list (partition nest skills-abilities residual) |
| **Agent** | R12-025 OWN-ONLY dual (dual start 2646) |
| **Live tools** | `decompile_function`, `analyze_function_complete`, `disassemble_function`, `get_function_callers`, `get_function_xrefs`, `read_memory` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/vector/TFID-key/callers sealed; product host class open |

---

## 1. Purpose

**Exact TFID-pair linear ignore-list lookup.** Walk pointer vector at **`this+0x38` / `this+0x3c`**, compare each entry's int pair at **`entry+0x08` / `entry+0x0c`**, return first matching entry pointer or **null**.

```c
// __thiscall; RET 0x8; EAX = entry* | 0
void* IgnoreList_FindEntryByTfid_Inferred(void* listHost, int tfid_lo, int tfid_hi);
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` / `analyze_function_complete` @ `0x00573a90` |
| Full listing | `disassemble_function` @ `0x00573a90` (both RET paths) |
| Body bytes | `read_memory` 96 B @ `0x00573a90` — ends dual `C2 08 00`, pad `CC` |
| Callers | `get_function_callers` → `Client_RecvBroadcast`, `FUN_0080a170`, `FUN_0080eeb0`, `FUN_0080fa50`, `FUN_005740f0` |
| Xrefs | 5 UNCONDITIONAL_CALL: `00574101`, `0080a2ac`, `0080eee1`, `0080fabb`, `00810ceb` |
| Parent dual | `FriendsList_FindEntryByNameI_Inferred` (`aa_00573a30`) — friends name find on same multi-list host |
| Sibling dual | `NameTable_FindEntryByNameI_Inferred` (`aa_00573af0`) — **same** +0x38 vector, name key |
| Raw / annotated / clean | trio under `docs/reconstruction/` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 87 B / pad `CC` | **Confirmed** | disasm end + memory |
| `__thiscall` ECX=host, stack TFID lo/hi | **Confirmed** | ESI from `[ECX+0x38]`; EDI/EBX stack args |
| `RET 0x8` | **Confirmed** | both epilogues `C2 08 00` |
| Vector begin/end @ +0x38 / +0x3c | **Confirmed** | disasm + decomp |
| Count `(end-begin)>>2` / begin==0 → 0 | **Confirmed** | |
| TFID key @ `entry+0x08` / `+0x0c` | **Confirmed** | dual CMP |
| Return entry* / 0 | **Confirmed** | match load `[begin+i]`; miss `XOR EAX,EAX` |
| Ignore-list role | **High** | remove-ignore English + trade/convoy/broadcast filters |
| Product host/entry class name | **Open** | no RTTI on VA; `_Inferred` |
| Entry full layout | **Partial** | +8/+0xc TFID; +0x10 name from caller |

---

## 4. Control flow

```
i = 0
loop:
  count = (begin==0) ? 0 : (end - begin) >> 2   // begin=this+0x38, end=this+0x3c
  if i >= count: return 0
  entry = begin[i]
  if entry+8 == tfid_lo AND entry+0xc == tfid_hi: return entry
  i++
  goto loop
```

---

## 5. Decompile ≡ raw

Live R12-025 decompile matches frozen 2026-07-23 raw body (same CF, offsets, keys). ABI sealed beyond decompiler via `disassemble_function` + `read_memory` (`RET 0x8`).

---

## 6. Gaps (acceptable)

1. Product class / MSVC name for list host (`DAT_00d1da2c`) and entry type.
2. Full entry layout beyond TFID@+8/+0xc and name@+0x10.
3. Runtime / bit-exact (Terminal false).

**Verdict:** **accept-with-gaps** — structural contract sealed; product English open for class → `_Inferred`.
