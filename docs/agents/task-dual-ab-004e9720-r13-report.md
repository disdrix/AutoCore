# Dual A/B report — R13-027 OWN-ONLY (`aa_004e9720`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-027**  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-027**  
**Dual start:** **2686**  
**Scope:** OWN ONLY VA `0x004e9720`. Dual A/B + trio + function record.  
**System:** interaction-activation  
**Parent dual:** `0x005eb790` `VOGPhysics_QueryCollect_Ctor_Inferred`  
**Terminal:** false  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / VERIFICATION_MATRIX / NAMING_REGISTRY / parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + callers/xrefs + `read_memory` + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004e9720` CVOGPhysicsUtils_FindClearSpawnPosition_Inferred | **accept-with-gaps** — cdecl clear-spawn sphere probe; ABI/bytes/loop/host physics sealed; product English open |

---

## VA `0x004e9720` — sealed facts

1. **Body:** `0x004e9720`–`0x004e9a9b` inclusive (**892 B** / `0x37C`); exclusive end `0x004e9a9c` (`cc` pad).
2. **ABI:** **cdecl**; 8 stack args; **bare `RET`**; return **bool in AL**. Callers all `ADD ESP,0x20`.
3. **Semantics:** **Find collision-clear spawn/placement position** via temporary sphere shape + parent query-collect:
   - Sphere ctor `FUN_006c7fa0(radius=param_4)`.
   - Query-collect ctor **`FUN_005eb790`** (parent dual) on 0xD0 alloc tag `0x2C`.
   - Register/unregister on `*(host+0xE4A4)` via `FUN_0055ff20` / `FUN_00560020`.
   - Loop up to `param_7` attempts: set pose → `vcall(query,+0x30)` collect → empty hits = success; else random XZ scatter by `param_3` and re-height via `FUN_004cd220(host,x,z)`.
   - Optional restore of input float4 when still blocked and `param_8==0`.
4. **Return polarity:** `AL=1` means **found clear** (zero-hit); spawn callers treat `AL==0` as hard fail (`"Couldn't find a spawn position…"`).
5. **Constants:** `DAT_00a0f298=0.5f` Y pad; `_DAT_009cc4a8≈1/32768` random scale; `DAT_00a0f2a0=1.0f`; `DAT_00a0f518=0.0f`; `DAT_00aaa664≈1e-4`; hit vtbl `0x009ccbb4`; cap `0x80000010`.
6. **Decompiler corrections:** `param_1` **live** (host); height sample is **thiscall on host**; random helper asm target `FUN_007a4330`.
7. **Callers (4):** `CVOGSpawnPoint_CreateCreature` @ `00565251`; `CVOGSpawnPoint_CreateTemplateVehicle` @ `00564351`; `FUN_00522f70` @ `005230ed`; `FUN_005cc7f0` @ `005cc917`.
8. **Callees:** `006c7fa0`, `005eb8d0`, **`005eb790`**, `0055ff20`, `005eb130`, `007a4330`, `004cd220`, `00560020`, `004eacc0`, allocator `DAT_00b05060`.
9. **Name:** `CVOGPhysicsUtils_FindClearSpawnPosition_Inferred` (Ghidra `FUN_004e9720`; **Inferred** — never Runtime Confirmed). Scaffold `Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004e9720` **retired**.
10. **Decompile ≡ raw CF** with assembly corrections above; entry/epilogue bytes sealed via `read_memory`.

### Gaps

- Product/PDB method string (family inferred from sibling `CVOGPhysicsUtils::*` only).  
- Exact English of `param_6` query cookie (callers often pass `0x14`).  
- Residual duals for register/set-pose/height/triad-dtor helpers.  
- Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md` | **accept-with-gaps** |

### Files (trio + function + dual)

| Kind | Path |
|------|------|
| Raw (+ R13-027 append) | `docs/reconstruction/raw/aa_004e9720_FUN_004e9720.md` |
| Annotated | `docs/reconstruction/raw/aa_004e9720_FUN_004e9720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.cpp` |
| Clean twin scaffold | `docs/reconstruction/reconstructed-exact/FUN_004e9720.cpp` |
| Function (named) | `docs/reconstruction/functions/aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md` |
| Function (FUN_*) | `docs/reconstruction/functions/aa_004e9720_FUN_004e9720.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e9720_CVOGPhysicsUtils_FindClearSpawnPosition_Inferred.md` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGSpawnPoint_CreateCreature_004e9720.cpp` |
| This report | `docs/agents/task-dual-ab-004e9720-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004e9720` | Clear-spawn **sphere probe** under host physics `+0xE4A4`. Pair with parent query-collect ctor `005eb790` + sphere shape `006c7fa0`. Success = **zero** collect hits within `attempts`. Do **not** merge with `FindDistanceToTarget` (`004e9aa0`) or `GetObjectsInArea`. Scatter radius and sphere radius are **separate** formals. Max attempts is **uchar** countdown. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + callers/xrefs + read_memory (+ disassemble_function / assembly context).  
- Dual A (fidelity) + B (adversarial) both filed.  
- Name suffix **`_Inferred`**; never Runtime Confirmed.  
- Terminal **false**.
