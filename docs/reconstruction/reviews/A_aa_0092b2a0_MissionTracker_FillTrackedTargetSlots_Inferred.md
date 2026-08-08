# Review A (reconstruction fidelity): `aa_0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092b2a0` |
| **VA** | `0x0092b2a0`–`0x0092bf5b` (**3260 B** / `0xCBC`) |
| **Canonical name** | `MissionTracker_FillTrackedTargetSlots_Inferred` |
| **Ghidra name** | `FUN_0092b2a0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY R12-008) |
| **Counterpart** | `reviews/B_aa_0092b2a0_MissionTracker_FillTrackedTargetSlots_Inferred.md` |
| **System** | inventory-transfer partition (parent dual `0x0092af80`); MissionTracker secondary multi-target fill |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / `get_function_xrefs` + `get_assembly_context` (entry/branch/fill/epilogue/caller) + `read_memory` (entry, epilogue, DAT floats, TFID template). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill up to four tracked-target nodes on the MissionTracker host vector after the primary multi-list filter misses: rank world matches by distance (and level band), allocate `0x20` nodes (TFID_16 + position), push onto `host+0x11C`, set `host+0x08=1` on success.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R12-008 append) | `docs/reconstruction/raw/aa_0092b2a0_FUN_0092b2a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0092b2a0_FUN_0092b2a0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/MissionTracker_FillTrackedTargetSlots_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092b2a0.cpp` |
| Sole caller | `MissionTracker_RefreshTrackedTargets_Inferred` (`0x0092bf60`) @ `0x0092c058` |
| Parent dual | `TargetFilter_DispatchMatchArms_Inferred` (`0x0092af80`) — not edited |

---

## 3. Signature (sealed)

```c
// stdcall: PUSH origin; PUSH host; CALL; RET 8; AL = bool
uint8_t MissionTracker_FillTrackedTargetSlots_Inferred(void* host, float* origin);
```

| Formal | Source | Conf |
|---|---|---|
| host | stack `[EBP+8]` → `EBX` | **High** |
| origin | stack `[EBP+0xC]` | **High** |
| return | `MOV AL,1` @ `0x0092bf2d` / `XOR AL,AL` @ `0x0092bf4c` | **High** |
| cleanup | `RET 8` @ `0x0092bf43` / `0x0092bf59` | **High** |
| ECX-this | **Not** thiscall | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| SEH frame + 16-byte align | entry `PUSH EBP; AND ESP,F0; …` | **High** |
| Top-4 dist init FLT_MAX | `MOVSS` ×4 from `DAT_00aaa630` | **High** |
| Arm select `+0x54` / `+0x80` | `CMP/JG` then `CMP/JLE → 0x0092b968` | **High** |
| Race gate `+0xAC` | `CMP/JLE → fail` | **High** |
| Optional pre-pass | `host+6` → `CALL 0x0092b1c0` | **High** |
| CBID/world walk | tree `client+0xE04+0xE84C`, vtbl `+0x1EC`, bit9 `@+0x180` | **High** |
| Level band | `host+0x108/+0x10C`, level−100 if >99 | **High** |
| Race arm CS key 0x36 | hash walk + list iterate | **High** |
| Min distSq 10000 | `DAT_00aaa880` race insert gate | **High** |
| Emit nodes | `new(0x20)`, vector base `ADD …,0x118`, TFID `@+0x164`, pos `@+0x84` | **High** |
| Success | `host+0x08=1`, `AL=1`, `RET 8` | **High** |
| Fail | `AL=0`, `RET 8` | **High** |

**Decompiler caveat:** type-propagation unstable; map/tree iterators and SEH `operator_delete` paths are noisy. ABI/epilogue/vector emit sealed from `read_memory` + assembly context.

---

## 5. Machine bytes

- Entry: `55 8B EC 83 E4 F0 6A FF 68 CE 04 9B 00 …`
- Success epilogue: `B0 01 88 42 08 … 8B E5 5D C2 08 00`
- Fail epilogue: `32 C0 … C2 08 00`
- Pad `CC` then next `FUN_0092bf60`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker — MissionTracker secondary multi-target fill |
| Code callers | `FUN_0092bf60` ×1 @ `0x0092c058` |
| Xrefs | 1 UNCONDITIONAL_CALL |
| Callees | see function record |

---

## 7. Gaps

1. Product/PDB English for host class and node type.
2. Full dual of residuals `0092b1c0`, `00929c60`, map helpers interiors.
3. Exact product meaning of CBID list A vs B (`+0x54` vs `+0x80`) and race table English.
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/top-4 emit/sole call site sealed from bytes + constants. Product residual → **accept-with-gaps**.
