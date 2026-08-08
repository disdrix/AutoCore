# Review A (reconstruction fidelity): `aa_0052eb90` Character_Craft_HasMatchingStationInRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052eb90` |
| **VA** | `0x0052eb90`–`0x0052ed73` exclusive (**483** B / `0x1E3`) |
| **Canonical name** | `Character_Craft_HasMatchingStationInRange_Inferred` |
| **Ghidra symbol** | `FUN_0052eb90` |
| **Prior scaffold** | `FUN_0052eb90` / `Named_CalleeOf_*RefreshOpenMissionUiWindow_0052eb90` |
| **Review date** | `2026-08-05` (R12-021 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md` |
| **System** | inventory-transfer — craft station proximity gate (partition parent craft host `0x008e6b50`) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + call-site context. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Character **thiscall bool** gate used by craft 2d host UI and item tooltips:

```text
Character_Craft_HasMatchingStationInRange_Inferred(character, craftObject) -> bool
  if charObj@MI+0xa8 == 0 or craftObject == 0: return false
  if character+0x6b4 > 0: return true
  if !DisciplineDefMap_TryCopyPayloadById(craftObject.def+0x4ac, buf): return true
  for each TFID in charObj+0xe7f8:
    obj = Resolve(charObj+0xe4e8, tfid)
    if pose-ok and SurfaceDistance3D <= 50.0:
      subtype = obj.def+0x3f4
      if subtype in {0xD,0xE,0xF} and matching buf flag non-zero: return true
  return false
  RET 0x4
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-021 re-verify) | `docs/reconstruction/raw/aa_0052eb90_FUN_0052eb90.md` |
| Annotated | `docs/reconstruction/raw/aa_0052eb90_FUN_0052eb90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_Craft_HasMatchingStationInRange_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_0052eb90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ entry/exit/`DAT_00a0f524` |
| Discipline map | dualed `FUN_0052b040` `DisciplineDefMap_TryCopyPayloadById_Inferred` |
| Distance | dualed `FUN_0053e510` `Object_SurfaceDistance3D_Inferred` |
| Parent craft host | dualed `FUN_008e6b50` tail `MOV [EBP+0x7e2],AL` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 483 B + four `ret 0x4` exits | **Confirmed** | disasm ends `C2 04 00`; pad `CC` |
| thiscall ECX=character, stack object*, AL bool | **Confirmed** | prologue `MOV ESI,ECX`; all 4 sites `MOV ECX,[DAT_00d1b6d8]` + PUSH object |
| Null charObj / null object → false | **Confirmed** | early `XOR AL,AL` path |
| `+0x6b4 > 0` → true bypass | **Confirmed** | `CMP [ESI+0x6b4],1; JGE allow` |
| DisciplineDef try-copy via `0052b040` | **Confirmed** | dualed R12-020; key `def+0x4ac` |
| Map miss → true | **Confirmed** | `TEST AL; JNZ loop; MOV AL,1; RET 4` |
| TFID vector @ object `+0xe7f8` via `004e5810` | **Confirmed** | callee body + dual CALL pattern |
| Resolve via `+0xe4e8` + `CVOGReaction_ResolveObjectTarget` | **Confirmed** | `MOV ECX,[ECX+0xe4e8]` before CALL |
| Distance ≤ 50.0f (`DAT_00a0f524`) | **Confirmed** | `read_memory` `00 00 48 42`; `FCOMIP` gate |
| Subtype `0xD/0xE/0xF` @ def `+0x3f4` | **Confirmed** | `MOVSX` + `SUB EAX,0xD` ladder |
| Flags = DisciplineDef payload tail 3 dwords | **Confirmed** | buffer is 0x1FC; decompiler `iStack_*` sit after 496 B |
| Craft host `+0x7e2` consumer | **Confirmed** | parent `008e80f7` / tick `008e63cc` |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Null gates → AL=0 | **Yes** |
| `+0x6b4` / Discipline miss → AL=1 | **Yes** |
| TFID loop + resolve + distance + subtype flags | **Yes** |
| Exhaust → AL=0; match → AL=1; RET 4 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Craft host gate byte consumer | **Yes** |
| DisciplineDef requirements row | **Yes** (dualed map) |
| Station subtype + range match | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`Character_Craft_HasMatchingStationInRange_Inferred`** (structural High; English unproven). Reject mission-UI Named_CalleeOf scaffold; reject pure inventory-grid place/find merge; reject skill-cast target resolve merge.

---

## 6. Gaps

1. Product English for station subtypes `0xD/0xE/0xF` and DisciplineDef flag fields.
2. Product English for `character+0x6b4` (RE-free / open family Probable from RE required-level twin usage).
3. Exact std::vector member layout of temp buffers (CF sealed; type names open).
4. Full dual of `FUN_004e5810` / craft host refresh `FUN_008e55e0` (not OWN).
5. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
