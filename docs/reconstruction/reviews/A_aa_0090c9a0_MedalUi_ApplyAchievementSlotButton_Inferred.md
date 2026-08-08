# Review A (reconstruction fidelity): `aa_0090c9a0` MedalUi_ApplyAchievementSlotButton_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c9a0` |
| **VA** | `0x0090c9a0`–`0x0090cbbb` inclusive (**540 B** / `0x21C`) |
| **Canonical name** | `MedalUi_ApplyAchievementSlotButton_Inferred` |
| **Ghidra name** | `FUN_0090c9a0` |
| **Prior scaffolds** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c9a0` (retired); plate alias `UI_a_btn_achievement` |
| **Review date** | `2026-08-05` (MEGA-095 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0090c9a0_MedalUi_ApplyAchievementSlotButton_Inferred.md` |
| **System** | `missions-progression` / Medal UI |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `read_memory` + parent `disassemble_function` `0x0090cbc0`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Create and bind **one** medal/achievement grid-slot button on the medal UI host:

```text
MedalUi_ApplyAchievementSlotButton_Inferred(host=ESI, slot=EBX, medalDef, earnedFlag)
  SEH
  widget = new(0x488) ? FUN_007b5dd0(mem,0) : null
  host[+0x540 + slot*4] = widget
  host.vtbl[+0xa8](widget)                          // attach
  widget.vtbl[+0x28]("i_d_a_2d_btn_achievement.xml")
  place 3-col grid (slot/3, slot%3) via size/origin vfuncs + scales
  host[+0x510 + slot] = medalDef[0]
  name = strcpy(medalDef+0x10) + ".dds"
  widget.vtbl[+0x50](name); [+0x118](pos); [+0x34c](); [+0x74](slot+0x9c43)
  if earnedFlag==0: dim via [+0x164](2) → [+0x154](0, mode)
  RET 8
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0090c9a0_FUN_0090c9a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c9a0_FUN_0090c9a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUi_ApplyAchievementSlotButton_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090c9a0.cpp` |
| Live decompile | ≡ scaffold CF (SEH → new/ctor → XML → grid → dds → dim) |
| Full body listing | `disassemble_function` 141 insns; epilogue `ADD ESP,0x13C; RET 8` |
| Entry/epilogue bytes | `read_memory` `6A FF 68 AB 3A 9B…` / `…C2 08 00` |
| Constants | `.dds`, scale floats, layout string via `read_memory` |
| Parent sites | `FUN_0090cbc0` @ `0x0090ccea` / `0x0090cdb4` |
| Medal lookup | dualed `MedalDef_LookupById` `0x0051a0e0` |

---

## 3. Signature (sealed)

```c
// ESI=host; EBX=slotIndex; stack medalDef*, earnedFlag; void; RET 8
void MedalUi_ApplyAchievementSlotButton_Inferred(
    MedalDef* medalDef,
    uint32_t earnedFlag);
```

| Formal | Source | Conf |
|---|---|---|
| host | **ESI** (parent `MOV ESI,EAX`) | **High** |
| slotIndex | **EBX** (parent `MOV EBX,EBP` / fill count) | **High** |
| medalDef | stack arg0 (`PUSH EAX` lookup) | **High** |
| earnedFlag | stack arg1 (`PUSH 1` / `PUSH 0`) | **High** |
| cleanup | `RET 8` (`C2 08 00`) | **High** |
| return | void | **High** |

Ghidra signature `void FUN_0090c9a0(void)` is **under-specified** — decompiler `unaff_*` corrected via listing + parent.

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| SEH install `LAB_009b3aab` | bytes + decompile | **High** |
| `operator_new(0x488)` + null-safe `FUN_007b5dd0` | CALL sites | **High** |
| Store widget `@+0x540[slot]` | `MOV [ESI+EBX*4+0x540]` | **High** |
| Host attach vfunc `+0xa8` | CALL dword | **High** CF |
| Load XML string | PUSH `0xa31024` | **High** |
| `IDIV 3` row/col grid | listing | **High** |
| Scale mul `DAT_00aaa678/67c` + `DAT_00d1e81c/818` | listing + `read_memory` | **High** |
| Medal byte `@+0x510+slot` | listing | **High** |
| Name copy + `.dds` append | listing + `DAT_00a2c53c` | **High** |
| Set name/pos/refresh/id | vfuncs `+0x50/+0x118/+0x34c/+0x74` | **High** CF |
| earnedFlag==0 dim path | `CMP [ESP+0x14c],0` | **High** CF |
| Live decompile ≡ raw CF | yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (UI slot apply) |
| Caller functions | **1** — `FUN_0090cbc0` |
| Xrefs | **2** UNCONDITIONAL_CALL |
| Site roles | owned medals (flag=1); unowned hash remainder (flag=0) |
| Named callees | `operator_new`, `FUN_007b5dd0` |
| Indirect | host/widget vtable surface |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Layout string `i_d_a_2d_btn_achievement.xml` | **Yes** |
| Parent medal loops via `MedalDef_LookupById` | **Yes** |
| `.dds` texture bind from medal name | **Yes** |
| earned vs unowned flag toggle | **Yes** |
| Product demangle / RTTI host class | **No** → `_Inferred` |
| `Named_VOG_DEBUG_STOP` as purpose | **No** (parent error path only) |

---

## 7. Gaps

1. Product English for host panel class and `FUN_007b5dd0` widget type.
2. Exact vtable method names for listed offsets.
3. Runtime values of `DAT_00d1e818` / `DAT_00d1e81c` (static zeros).
4. Art meaning of dim path (gray vs locked overlay).
5. Runtime / bit-exact / differential.

---

## 8. Verdict

CF/ABI/callers/string/grid/flag-path **sealed**. Product class English open → **accept-with-gaps**.
