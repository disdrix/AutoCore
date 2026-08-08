# Review A (reconstruction fidelity): `aa_0092bf60` MissionTracker_RefreshTrackedTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092bf60` |
| **VA** | `0x0092bf60`–`0x0092c075` (**278 B** / `0x116`) |
| **Canonical name** | `MissionTracker_RefreshTrackedTargets_Inferred` |
| **Ghidra name** | `FUN_0092bf60` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R11-040) |
| **Counterpart** | `reviews/B_aa_0092bf60_MissionTracker_RefreshTrackedTargets_Inferred.md` |
| **System** | inventory-transfer partition (parent `0x0092adf0`); role MissionTracker target refresh |
| **Evidence pass** | Live Ghidra `decompile_function` + `force_decompile` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` (4 call sites) + `read_memory` (278 B body + `DAT_00aaa690` + `DAT_00aaaaf8`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Refresh the MissionTracker-family host's tracked-target state on the dirty/timer path: clear vector `+0x11c`, reload poll timer to **4.0f**, resolve world target(s) from character origin, bind primary hit (node + TFID_16) or secondary multi-target fill.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R11-040 append) | `docs/reconstruction/raw/aa_0092bf60_FUN_0092bf60.md` |
| Annotated | `docs/reconstruction/raw/aa_0092bf60_FUN_0092bf60.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/MissionTracker_RefreshTrackedTargets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092bf60.cpp` |
| Dualed clear helper | `Tracker_ClearOwnedPtrVectorAt11c_Inferred` (`0x0092a3d0`) |
| Parent filter arm | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` (`0x0092adf0`) via dispatcher `0x0092af80` |
| Sole caller | `FUN_0092c640` timer/dirty tick |

---

## 3. Signature (sealed)

```c
// EAX = MissionTracker* host; no stack args; AL = bool; ADD ESP,8; RET
uint8_t MissionTracker_RefreshTrackedTargets_Inferred(void* host /*EAX*/);
```

| Formal | Source | Conf |
|---|---|---|
| host | **EAX** (`MOV EDI,EAX`; caller `MOV EAX,ESI`) | **High** |
| return | `MOV AL,1` / `XOR AL,AL` | **High** |
| cleanup | `ADD ESP,8; RET` (frame only; not `RET n`) | **High** |
| ECX-this | **Not** thiscall for this unit | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Guards client / `+0xE98` / `+0xE04` | `CMP/JZ → 0x0092c06e` fail | **High** |
| Clear vector | `CALL 0x0092a3d0` with EDI=host | **High** |
| Timer `+0x14 = 4.0f` | `MOVSS [EDI+0x14], [DAT_00aaa690]` | **High** |
| Busy `char+0x4F1` / `client+0xD34` | `CMP/JNZ|JZ → fail` | **High** |
| Origin vtbl `+0x1A0` | this-adjust + `CALL [EDX+0x1A0]` | **High** |
| Init bestObj/bestDist | zero local; `MOVSS` 1e9f from `DAT_00aaaaf8` | **High** |
| Primary filter | `CALL 0x0092af80`; `TEST AL` / null bestObj → secondary | **High** |
| Type gate `+0xB` | clone `+0x38` ∈ {`0x12`,`0x0E`} else clear flag | **High** |
| Primary bind | `CALL 0x0092a440`; null→`AL=1`; else clear `+0x8`, copy TFID `obj+0x160`×16 | **High** |
| Secondary | `PUSH origin; PUSH host; CALL 0x0092b2a0` | **High** |
| Fail | clear `+0x8`; `AL=0` | **High** |

**Decompiler caveat:** live decompile removes primary bind blocks as "unreachable" and invents `af80 && b2a0` success. **Bytes supersede.**

---

## 5. Machine bytes

Full 278 B hex in raw R11-040 append. Entry: `83 EC 08 53 57 8B F8 …`. Success epilogue: `B0 01 5B 83 C4 08 C3`. Fail: `32 C0 5B 83 C4 08 C3`. Next function `FUN_0092c080` @ `0x0092c080`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker — MissionTracker target refresh |
| Code callers | `FUN_0092c640` ×1 @ `0x0092c67c` |
| Xrefs | 1 UNCONDITIONAL_CALL |
| Callees | `0x0092a3d0`, vtbl+`0x1A0`, `0x0092af80`, `0x0092a440`, `0x0092b2a0` |

---

## 7. Gaps

1. Product/PDB English for host class and vector element type.  
2. Official names: vtbl `+0x1A0`, flags `+0x08`/`+0x0B`, clone types `0x12`/`+0x0E`.  
3. Full dual of residuals `0092af80` / `0092a440` / `0092b2a0` / `0092c640` / `0092c080`.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/timer/filter/bind/secondary path sealed from bytes + sole call site. Product residual → **accept-with-gaps**.
