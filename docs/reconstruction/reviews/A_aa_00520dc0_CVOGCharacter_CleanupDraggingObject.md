# Review A (reconstruction fidelity): `aa_00520dc0` CVOGCharacter_CleanupDraggingObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_00520dc0` |
| **VA** | `0x00520dc0`–`0x00520f39` (**378 B** / `0x17A`) |
| **Canonical name** | `CVOGCharacter_CleanupDraggingObject` |
| **Ghidra name** | `FUN_00520dc0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-001) |
| **Counterpart** | `reviews/B_aa_00520dc0_CVOGCharacter_CleanupDraggingObject.md` |
| **System** | inventory-transfer |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `analyze_control_flow` + callers/xrefs + `get_bulk_xrefs` + `search_strings` + callee batch decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Cleanup the character’s dragging object** at `this+0xCD0`:

1. If null → profiler leave, return **false**.
2. Else try **place** into cargo grid `*( *(this+0x250)+0x2B0 )` via FindFree+Place.
3. Else try **place** into locker grid `*(this+0xCBC)`.
4. Else **TryEquip** on host `*(this+0x250)`; if `out==0` and status ∈ `{0,1,0xA,0xD,0xF}`, call `FUN_00502e90` equip switch.
5. Always **null** `this+0xCD0`, profiler leave, return **true**.

Product plate string seals Class::Method English.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-001 append) | `docs/reconstruction/raw/aa_00520dc0_FUN_00520dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00520dc0_FUN_00520dc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_CleanupDraggingObject.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00520dc0.cpp` |
| FindFree dual | `InventoryGrid_FindFreeForItem` `0x005714e0` |
| Place dual | `InventoryGrid_PlaceItemFootprint` `0x00571620` |
| TryEquip dual | `Character_TryEquipItem` `0x004fabc0` |
| Profiler duals | `Profiler_EnterNamedZone` / `Profiler_Leave` |

---

## 3. Signature (sealed)

```c
// ECX = this; stack 4 B unread; RET 4; AL bool
bool __thiscall CVOGCharacter_CleanupDraggingObject(void* self /*, uint32_t unused */);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`MOV EDI,ECX`) | **High** |
| stack dword | `RET 4` both exits; no body load | **High** (presence); **Low** (meaning) |
| return | AL 0/1 (`XOR AL,AL` / `MOV AL,1`) | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Profiler enter + plate string | `PUSH 0x9cf0b0` / `CALL 0x00786a00` | **High** |
| Load drag `+0xCD0` | `MOV ESI,[EDI+0xCD0]` | **High** |
| Null → leave + `AL=0` + `RET 4` | early block `@0x00520dfd` | **High** |
| Clear outX/outY low bytes | `MOV [ESP+…],BL` ×2 | **High** |
| Path A FindFree cargo grid | ECX=`*(*(this+0x250)+0x2B0)`; push item, outs, `1`, `-1` | **High** |
| Path A vcall qty `+0x25C` + Place | ECX=cargo; success → `JNZ CLEAR` | **High** |
| Path B FindFree locker | ECX=`[EDI+0xCBC]` | **High** |
| Path B Place | same pattern; success → CLEAR | **High** |
| TryEquip host+item+out | ECX=`[EDI+0x250]`; `CALL 0x004fabc0` | **High** |
| Gate out==0 && code set | `CMP [out],0` + `CMP EAX,{0,1,A,D,F}` | **High** CF |
| Equip switch | `CALL 0x00502e90` | **High** |
| Clear `+0xCD0` + leave + `AL=1` | `@LAB_00520f0a` | **High** |
| No loops | CF metrics loops=0 | **High** |

Cyclomatic complexity ~11–20 (tool variance); 14 basic blocks; 2 returns.

---

## 5. Machine bytes

Full body hex in raw MEGA-001 append (`read_memory` 400 B covering function + pad).  
Entry: `6A FF 68 F7 37 9A 00 64 A1 … 8B F9`.  
Epilogues: `C2 04 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker product method (inventory-transfer) |
| Code callers (live Ghidra) | **0** (gap) |
| DATA xrefs to entry | **0** found |
| String xrefs | plate only from this body |
| Prior residual | listed among FindFree place-prep consumers |

---

## 7. Gaps

1. Direct callers / unread stack-arg producers.  
2. Product English for TryEquip status set → `FUN_00502e90`.  
3. Cross-unit `+0xCD0` naming (vehicle vs drag) on other hosts.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/offsets/plate name/place-then-equip contract sealed against live assembly. Residual callers + equip-code English + runtime → **accept-with-gaps**.
