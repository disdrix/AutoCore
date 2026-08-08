# Review A (reconstruction fidelity): `aa_0090c810` MedalUI_CountDisplayableEntries_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c810` |
| **VA** | `0x0090c810`–`0x0090c8c9` (**186 B** / `0xBA`) |
| **Canonical name** | `MedalUI_CountDisplayableEntries_Inferred` |
| **Ghidra name** | `FUN_0090c810` |
| **Prior names** | `Named_VOG_DEBUG_STOP_0090c810` (retired) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-103) |
| **Counterpart** | `reviews/B_aa_0090c810_MedalUI_CountDisplayableEntries_Inferred.md` |
| **System** | `missions-progression` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `inspect_memory_content` + `get_function_callers` / `callees` / `xrefs` + `get_assembly_context` @ call sites. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Medal UI **entry-count query** on the character/medal-state object (`EBX` ← `DAT_00d1b6d8`):

1. Null object → 0.
2. Seed from owned medal-id **vector size** at `+0x574/+0x578`.
3. Hash-traverse `+0x540` with lock `@+0x1d`; for each payload, `MedalDef_LookupById(id@+0x100)` → count++ on hit.
4. Unlock; return total in EAX.

Parent `FUN_0090cbc0` uses the count for page math after prep clear (`FUN_0090c700`) and before bind (`FUN_0090c9a0`). Gate peers `FUN_0090c920` / gap-`0x0090c8d0` compare count to `0x18`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-103 append) | `docs/reconstruction/raw/aa_0090c810_FUN_0090c810.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c810_FUN_0090c810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_CountDisplayableEntries_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090c810.cpp` |
| Function records | `functions/aa_0090c810_FUN_0090c810.md` + named |
| Live decompile | Ghidra `decompile_function` `0x0090c810` |
| Live listing | `disassemble_function` `0x0090c810` |
| Live bytes | `read_memory` 186 B @ entry |
| Strings | `inspect_memory_content` @ `0x00a27cd0` / `0x00a27c9c` / `0x00a15844` |
| Call sites | `get_assembly_context` @ `0x0090cbfa` / `0x0090c938` / `0x0090c8ed` |
| Parent (evidence only) | `FUN_0090cbc0` disasm head; `FUN_0090c920` decompile |

**Not performed:** `disassemble_bytes`, Launcher, runtime Confirmed, dual of parent/siblings.

---

## 3. Body (listing seals)

```text
0090c810  TEST EBX,EBX / JNZ cont / XOR EAX,EAX / RET   ; null → 0
0090c817  MOV  EAX,[EBX+0x574] / TEST EAX
0090c81f  PUSH EBP / PUSH ESI / PUSH EDI
0090c822  JNZ  sized
0090c824  XOR  EBP,EBP / JMP after_vec                  ; begin null → 0
0090c828  MOV  EBP,[EBX+0x578] / SUB EBP,EAX / SAR EBP,2
0090c833  MOV  EDI,[EBX+0x540] / XOR ESI,ESI
0090c83b  CMP  [EDI+0x1d],0 / JZ setlock
          PUSH "TraversalLock..." / CALL log / PUSH "VOG_DEBUG_STOP" / CALL log
0090c85a  MOV  [EDI+0x1d],1
; loop
0090c860  MOV  EDI,[EBX+0x540]
0090c866  CMP  [EDI+0x1d],0 / JNZ step
          PUSH "TraverseToNext..." / CALL log / PUSH "VOG_DEBUG_STOP" / CALL log
0090c887  TEST ESI / JZ first / MOV ESI,[ESI+0x14] / JMP have
0090c890  MOV  ESI,[EDI+0x14]
0090c893  TEST ESI / JZ null_pay / MOV EAX,[ESI+8] / JMP got_pay
0090c89c  XOR  EAX,EAX
0090c89e  TEST EAX / JZ unlock
0090c8a2  MOV  EAX,[EAX+0x100] / PUSH EAX / CALL MedalDef_LookupById / ADD ESP,4
0090c8b1  TEST EAX / JZ loop / ADD EBP,1 / JMP loop
0090c8ba  MOV  EAX,[EBX+0x540] / POP EDI / MOV [EAX+0x1d],0
0090c8c5  POP  ESI / MOV EAX,EBP / POP EBP / RET
```

Live decompile CF ≡ frozen raw 2026-07-23 ≡ live 2026-08-05.  
Body hex 186 B sealed; pad `CC×6` then gap twin @ `0x0090c8d0`.

---

## 4. ABI / signature (High)

```c
// Retail: EBX = character*; no stack args; EAX = count; bare RET (C3)
int MedalUI_CountDisplayableEntries_Inferred(void);
```

| Formal | Source | Conf |
|---|---|---|
| character | **EBX** (`TEST EBX`; callers `MOV EBX,[DAT_00d1b6d8]`) | **High** |
| stack | none | **High** |
| return | **EAX** = EBP count | **High** |
| cleanup | bare `C3` | **High** |
| ECX-thiscall | **No** | **High** |

---

## 5. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Null EBX early return | `85 DB` / `75 03` / `33 C0` / `C3` | **High** |
| Vector size `(end-begin)>>2` | `8B AB 78 05 00 00` / `2B E8` / `C1 FD 02` | **High** |
| Hash base `+0x540` | `8B BB 40 05 00 00` | **High** |
| Lock set/clear `@+0x1d` | `C6 47 1D 01` / `C6 40 1D 00` | **High** |
| Chain walk `+0x14` / payload `+0x08` | `8B 77 14` / `8B 46 08` | **High** |
| Id at payload `+0x100` | `8B 80 00 01 00 00` | **High** |
| `MedalDef_LookupById` cdecl | `PUSH EAX` / `CALL 0051a0e0` / `ADD ESP,4` | **High** |
| Count++ on hit | `83 C5 01` | **High** |
| Return count | `8B C5` / `5D` / `C3` | **High** |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Named code callers | **2** — `FUN_0090cbc0` @ `0x0090cbfa`; `FUN_0090c920` @ `0x0090c938` |
| Extra site | `0x0090c8ed` (body @ `0x0090c8d0`, twin of `0090c920`) |
| Xrefs | 3× UNCONDITIONAL_CALL |
| Static callees | `FUN_0051a0e0`, `FUN_007a4480` |
| Parent sequence | visible-gate → prep clear `0090c700` → **this count** → page math → bind `0090c9a0` |

---

## 7. Gaps

1. Product English for character class at `DAT_00d1b6d8`.  
2. Product English for hash container (lock strings only).  
3. Whether owned vector entries are always valid defs (raw size, no filter).  
4. Runtime / bit-exact / differential — open.  
5. Parent `FUN_0090cbc0` and bind sibling `FUN_0090c9a0` residual (other MEGA units).  
6. Partition "query/**alloc**" — this unit is **query only** (alloc is `0090c9a0`).

---

## 8. Verdict

CF/ABI/EBX-this/vector+hash count/MedalDef lookup/3 call sites sealed. Product character/hash English residual → **accept-with-gaps**. Terminal **false**.
