# Dual A/B report — WQ9R-C OWN `aa_005130e0` + `aa_00943340`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ9R-C  
**Scope:** VAs `0x005130e0`, `0x00943340` only. Trio + dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_residual_partition_map.md` row WQ9R-C.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005130e0` Object_IsWorldPickupType_Inferred | **accept-with-gaps** — ABI/CF/type table sealed; product name + two flag English open |
| `aa_00943340` Client_CycleHostileTarget_Inferred | **accept-with-gaps** — EAX/RET8 + hostile gather + step polarity sealed; nested sort/key English open |

---

## VA `0x005130e0` — sealed facts

1. **Body:** `0x005130e0`–`0x0051314d` inclusive (**0x6E** B code); pad `8B FF`; switch dword table `@0x00513150`, byte index `@0x00513160`.
2. **ABI:** **thiscall** ECX=`this` (cloned object); stack `char requireLoose`; **`RET 4`** (`C2 04 00`); **AL** bool.
3. **Semantics:** Soft type / world-pickup eligibility:
   - Enter type switch iff `requireLoose==0` **OR** `*(this+0xac)==0`.
   - Type from `*(uint*)(*(this+0xa8)+0x38)`:
     - **1** Object → `(blob[+0x3f2] >> 7) & 1`
     - **4,6,8,10,0xc,0x10,0x1a,0x1c,0x32,0x34,0x42** → 1 (QuestObject/Item/Gadget/PowerPlant/Weapon/WheelSet/Commodity/Armor/TinkeringKit/Accessory/Money)
     - **0xe** Vehicle → `__RTDynamicCast`→`CVOGVehicle` and `veh+0x2ac != 0`
     - else (incl. Creature **0x12**, Character **0x14**) → 0
4. **Classification:** worker.
5. **Callers (8):** gather pair filter `FUN_0058a810` (requireLoose=1 when filterA==-1); `Skill_FilterTargetForResolveList_Inferred` (can pass 0); interact prompt `FUN_008a81a0` (“to pick up”); graphics `FUN_00585e00`; plus list/register/radius helpers.
6. **Callees:** `__RTDynamicCast` only.
7. **Name:** `Object_IsWorldPickupType_Inferred` (Ghidra `FUN_005130e0`). Reject VOG_DEBUG_STOP scaffold alias as product plate.
8. **Decompile ≡ bytes / raw** (live 2026-08-04 ≡ 2026-07-23 scaffold).

### Gaps

- Product C++ / PDB name.  
- English for `this+0xac` (loose/attach gate) and vehicle `+0x2ac` (special/abandoned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005130e0_Object_IsWorldPickupType_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005130e0_Object_IsWorldPickupType_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005130e0_FUN_005130e0.md` |
| Annotated | `docs/reconstruction/raw/aa_005130e0_FUN_005130e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_IsWorldPickupType_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005130e0.cpp` |
| Function | `docs/reconstruction/functions/aa_005130e0_FUN_005130e0.md` |
| Function named | `docs/reconstruction/functions/aa_005130e0_Object_IsWorldPickupType_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005130e0.md` |

---

## VA `0x00943340` — sealed facts

1. **Body:** `0x00943340`–`0x009434fc` inclusive (**0x1BD** B / 445 B); epilogue `5F 5E 5B 8B E5 5D C2 08 00`.
2. **ABI:** **EAX**=client shell (call sites load client into EAX; entry `MOV ESI,EAX`); stack `float range`, `char stepDir`; **stdcall `RET 8`**; void.
3. **Semantics:** Hostile target cycle within range:
   - Early-out if local player (`client+0xe98`) flag `+0x4f1`.
   - Origin float4 from player interior vtbl `+0x1a0`.
   - `Skill_GatherTargetsInArea`: mode **2** (hostile), max **0x32** (50), filterA/B/C 0, allowSelf 1, sortDist 0, score **0xbf800000** (−1.0f), range from arg.
   - `FUN_00930360` view-angle reorders TFID list / may shrink count.
   - If count==0 return.
   - Match current selection `client+0x3048` TFID (`+0x160/+0x164/+0x168`); step: `stepDir==0` → **+1** (next), else **−1** (prev); wrap via ±count.
   - If TFID valid: `Object_ResolveFromTFID` → `FUN_0093e120` (apply selection / `client+0x3048`).
4. **Classification:** worker.
5. **Sole caller:** `Client_Input_PollBoundActions` @ `0x00927c5e` (`range=110.0f`, `stepDir=0`) and `0x00927cc7` (`110.0f`, `1`) when `DAT_00d1d888 != 0`; else sibling `FUN_00943520(110.0f)`.
6. **Callees:** `Skill_GatherTargetsInArea`, `FUN_00930360`, `Object_ResolveFromTFID`, `FUN_0093e120`.
7. **Name:** `Client_CycleHostileTarget_Inferred` (Ghidra `FUN_00943340`).
8. **Decompile ≡ bytes / raw** (live 2026-08-04 ≡ 2026-07-23 scaffold).  
   Range immediate at call sites: `0x42dc0000` = **110.0f**.

### Gaps

- Product keybinding / action English for next/prev hostile cycle.  
- Nested `FUN_00930360` product plate (view-sort Probable from body).  
- player `+0x4f1` product English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00943340_Client_CycleHostileTarget_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00943340_Client_CycleHostileTarget_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00943340_FUN_00943340.md` |
| Annotated | `docs/reconstruction/raw/aa_00943340_FUN_00943340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CycleHostileTarget_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00943340.cpp` |
| Function | `docs/reconstruction/functions/aa_00943340_FUN_00943340.md` |
| Function named | `docs/reconstruction/functions/aa_00943340_Client_CycleHostileTarget_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00943340.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005130e0` | Port as pure **type/loose eligibility** helper used by skill soft-filter (`filterA==-1`), interact pickup prompt, and related gates. Keep type table exact; vehicle only when special `+0x2ac`. Do not fold gather-mode logic into this unit. |
| `00943340` | Port as **hostile target cycle**: gather mode 2 in range → view-sort → step selection ±1 → apply selection. Preserve EAX client convention or expose explicit `ClientShell*`. Default retail range at call sites is **110.0f**. Pair with first-pick sibling `0x00943520` (owned by WQ9R-D). |
| Pair with | `Skill_GatherTargetsInArea` `0x0058d330` (mode table); `FUN_0058a810` pair filter; `FUN_0093e120` selection apply; `Client_Input_PollBoundActions` `0x00925d60`; sibling cycle/first-pick `0x00943520`. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs/callers + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Type IDs cross-checked with `src/AutoCore.Game/Constants/ClonebaseObjectType.cs`.  
- Rejected VOG_DEBUG_STOP scaffold alias for `005130e0` as product name.
