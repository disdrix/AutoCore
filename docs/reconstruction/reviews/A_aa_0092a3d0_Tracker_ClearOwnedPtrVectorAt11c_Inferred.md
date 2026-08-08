# Review A (reconstruction fidelity): `aa_0092a3d0` Tracker_ClearOwnedPtrVectorAt11c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a3d0` |
| **VA** | `0x0092a3d0`–`0x0092a43d` (**110 B** / `0x6E`) |
| **Canonical name** | `Tracker_ClearOwnedPtrVectorAt11c_Inferred` |
| **Ghidra name** | `FUN_0092a3d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-088) |
| **Counterpart** | `reviews/B_aa_0092a3d0_Tracker_ClearOwnedPtrVectorAt11c_Inferred.md` |
| **System** | missions-progression / MissionTracker clear helper |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (110 B) + callers/xrefs + `get_assembly_context` on all 5 call sites. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Clear MissionTracker owned pointer vector at `host+0x11c`: scalar-delete every element, then set vector `end := begin` without freeing the buffer. Always returns success (`AL=1`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-088 append) | `docs/reconstruction/raw/aa_0092a3d0_FUN_0092a3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0092a3d0_FUN_0092a3d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tracker_ClearOwnedPtrVectorAt11c_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0092a3d0.cpp` |
| Parent binder | `FUN_0092a590` / `Client_TryBindActiveMissionTracker` chain (`tracker` @ client+0x4d0) |
| Sibling destroy | `FUN_0092a600` (clear → free buffer → zero triple) |

---

## 3. Signature (sealed)

```c
// EDI = MissionTracker*; no stack args; AL = 1; bare RET (C3)
uint8_t __regparm_edi Tracker_ClearOwnedPtrVectorAt11c_Inferred(void* tracker);
```

| Formal | Source | Conf |
|---|---|---|
| tracker | **EDI** (`MOV ESI,[EDI+0x11c]`; callers `MOV EDI,ECX` / stack / EAX) | **High** |
| return | `MOV AL,1` | **High** |
| cleanup | bare `C3` | **High** |
| ECX-this | **Not used** as this (only temps) | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Load begin/end | `MOV ESI,[EDI+0x11c]` / `CMP ESI,[EDI+0x120]` | **High** |
| Empty skip | `JZ 0x0092a3f6` | **High** |
| Delete loop body | `MOV EAX,[ESI]; PUSH; CALL operator_delete; ADD ESI,4; ADD ESP,4; CMP; JNZ` | **High** |
| Null begin skip | `TEST EDX,EDX; JZ done` | **High** |
| Count==0 / begin==end skip | `SAR EAX,2; JZ` / `CMP EDX,ECX; JZ` | **High** |
| memmove clear | `PUSH 0; PUSH end; PUSH begin; CALL [memmove IAT]` | **High** |
| Store end | `MOV [EDI+0x120],EAX` with EAX=begin | **High** |
| Return 1 | `MOV AL,1; POP ESI; POP ECX; RET` | **High** |

**Decompiler caveat:** live decompile shows single `operator_delete(**begin)` + noreturn warning. Bytes restore full loop. Prefer annotated/clean over raw decompiler for port.

---

## 5. Machine bytes

Full 110 B hex in raw MEGA-088 append. Entry: `51 56 8B B7 1C 01 00 00 …`. Epilogue: `B0 01 5E 59 C3`. Next pad `CC` then `FUN_0092a440`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker clear helper |
| Code callers | `FUN_0092a590`×2, `FUN_0092a600`×1, `FUN_0092bf60`×1, `FUN_0092c080`×1 |
| Xrefs | 5 UNCONDITIONAL_CALL |
| Callees | `operator_delete` `0x00489822`, `memmove` IAT `0x009c652c` |

---

## 7. Gaps

1. Product English for element type `T*` in the vector.  
2. Product field name at tracker `+0x11c`.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/offsets/call-site EDI contract sealed from bytes + five call sites. Product residual on element type → **accept-with-gaps**.
