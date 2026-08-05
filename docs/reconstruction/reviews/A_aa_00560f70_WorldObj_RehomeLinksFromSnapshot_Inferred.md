# Review A (reconstruction fidelity): `aa_00560f70` WorldObj_RehomeLinksFromSnapshot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560f70` |
| **VA** | `0x00560f70`–`0x00561312` |
| **Body** | **930 bytes** (`0x3A2`) |
| **Canonical name** | `WorldObj_RehomeLinksFromSnapshot_Inferred` |
| **Prior scaffold** | `FUN_00560f70` |
| **Review date** | `2026-07-29` (W27-O dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00560f70_WorldObj_RehomeLinksFromSnapshot_Inferred.md` |
| **System** | world-object / phys rehome after mode exit |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Manager **thiscall** rehome after leaving a special object mode (caller: old mode == **7**):

| Phase | Action |
|---|---|
| **0** | Guarded reattach (identical to `00560f30`): flag `+0x12c`, `0055e760`, `0055fa40` |
| **1** | Snapshot children (`param_3` `{ptr*, count}`) → host `obj+0x44` list `+0x58` (grow `005b3370` elem 4); child virtuals; `child+0x14 = host` |
| **2** | Link array `obj+0x88` / count `+0x8c`: skip `vtbl+0x20()==0xb`; else open-code **PhysSim_PushBodyPair** onto `manager+0x20` |
| **3** | Action array `obj+0x94` / count `+0x98`: match host reverse list `*(manager+0x2c)+0x4c`; on hit `006292a0` + `00628f10`; `action+0x10 = host`; neighbor collect via action `vtbl+0x18` + arena `DAT_00b05060`; more body pairs |

Snapshot produced earlier by `FUN_005617c0` in the same SwitchHBAI path.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00560f70` ≡ raw 2026-07-23 |
| Bytes | entry `read_memory` 128 B; epilogue `read_memory` @ `0x00561300` → `add esp,30h; ret 8` |
| Bounds | body `00560f70`–`00561312` |
| Call site | `get_assembly_context` @ `0x005d46d3`: `LEA EDX,[ESP+2Ch]; PUSH EDX; PUSH ESI; MOV ECX,EDI; CALL` |
| Callees | `0055e760`, `0055fa40`, `005b3370`, `005b3300`, `006292a0`, `00628f10` |
| Caller | `FUN_005d4440` only (1 xref) |
| Related duals | `PhysSim_PushBodyPair` (`0055efd0`), `Phys_HostActionList_Push`, `ActionHost_RemoveReverseListEntry`, `WorldObj_BindLinks` |
| Raw / clean | `aa_00560f70_*`, `FUN_00560f70.cpp`, named twin |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of `005617c0` / `0055e760` / arena allocator.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = manager; stack obj + snapshot; **`ret 8`** | **Confirmed** | call site 2 pushes; epilogue `C2 08 00` |
| Phase 0 ≡ `00560f30` guarded reattach | **Confirmed** | same flag + callees |
| Snapshot `{data,count}` at `param_3[0]/[1]` | **Confirmed** | body + LEA of stack buffer at call site |
| Host from `obj+0x44`; child list `host+0x58/+0x5c/+0x60` | **Confirmed** | body |
| Link array `obj+0x88/+0x8c`; skip type **0xb** | **Confirmed** | body |
| Open-coded pair push ≡ `0055efd0` policy | **High** | same `+0x20` grow/store; prior dual notes inlined use |
| Action rehome: `006292a0` + `00628f10` + `action+0x10=host` | **Confirmed** | sealed callees |
| Arena via `DAT_00b05060` | **Confirmed** | alloc/free pattern |
| `unaff_EBX` second virtual after `vtbl+0x28` | **Residual** | decompiler; surrounding CF still sealed |
| Product English / mode-7 name | **Open** | `_Inferred` |
| clean ≡ raw ≡ live | **Confirmed** | 2026-07-29 |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Phase 0 flag + e760 + fa40 | Yes |
| Phase 1 snapshot → host list + child virtuals + `+0x14` | Yes (EBX residual on 2nd virtual) |
| Phase 2 links → body pairs | Yes |
| Phase 3 actions → rehome + neighbors | Yes |
| Arena free + ret 8 | Yes |

### ABI seal (call site)

```
; 005d4440 when old mode == 7:
LEA  EDX, [ESP+2Ch]   ; snapshot buffer (from FUN_005617c0)
PUSH EDX              ; param_3
PUSH ESI              ; obj
MOV  ECX, EDI         ; manager
CALL 00560f70         ; ret 8
```

### Pair-push open-code (matches `PhysSim_PushBodyPair_Inferred`)

```
need = *(manager+0x24) + 1
cap  = *(manager+0x28) & 0x7fffffff
if (cap < need) FUN_005b3300(manager+0x20, max(cap*2, need), 8)
*(manager+0x24) = need
store pair at data + need*8 - 8 / -4
```

---

## 5. Gaps / open

1. Product name for mode **7** and snapshot from `005617c0`.
2. Exact target of second virtual after child `vtbl+0x28` (`unaff_EBX`).
3. Product English for link type code **0xb**.
4. Full arena `DAT_00b05060` contract (not OWN).
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — CF stages + ABI + pair/action rehome sealed; virtual residual + product names open.
