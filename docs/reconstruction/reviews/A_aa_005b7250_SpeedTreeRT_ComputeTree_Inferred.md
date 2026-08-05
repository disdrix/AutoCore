# Review A (reconstruction fidelity): `aa_005b7250` SpeedTreeRT_ComputeTree_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7250` |
| **VA** | `0x005b7250`–`0x005b76e5` (**1173 B** / `0x495`) |
| **Canonical name** | `SpeedTreeRT_ComputeTree_Inferred` |
| **Ghidra name** | `FUN_005b7250` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-A) |
| **Counterpart** | `reviews/B_aa_005b7250_SpeedTreeRT_ComputeTree_Inferred.md` |
| **System** | graphics / SpeedTreeRT tree compute |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (prologue/epilogue + `DAT_00a2c53c` + `DAT_00aaa688`) + `get_function_by_address` + `get_function_xrefs` + caller `FUN_00582090`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

thiscall SpeedTreeRT tree compute/attach: store asset at `this+0x174`, ensure RT object `this+0x30` (0x9c), first-load resource+compute when `*(asset+0x128) < 1`, else refresh `FUN_005b71a0(1)`. On compute success: bounds, LOD span×5.0f, material block, optional `.dds` textures at `+0x170` / `+0x24`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-A append) | `docs/reconstruction/raw/aa_005b7250_FUN_005b7250.md` |
| Annotated | `docs/reconstruction/raw/aa_005b7250_FUN_005b7250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SpeedTreeRT_ComputeTree_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005b7250.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b7250_FUN_005b7250.md` |
| Named record | `docs/reconstruction/functions/aa_005b7250_SpeedTreeRT_ComputeTree_Inferred.md` |
| Caller | `FUN_00582090` (`"%s.spt"`) |
| Live | decompile CF ≡ scaffold; body 1173 B; `RET 0x14`; SEH `LAB_009a6a98` |

---

## 3. Signature (sealed)

```c
// thiscall; ECX=this; 5 stack formals; RET 0x14; AL success
uint8_t __thiscall SpeedTreeRT_ComputeTree_Inferred(
    void* self,
    void* resource_key,  // param_2
    int*  asset_cfg,     // param_3 → self+0x174
    void* compute_arg,   // param_4 → FUN_00688680
    float size_a,        // param_5
    float size_b);       // param_6
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → ESI; stores | **High** |
| asset_cfg | early `MOV EAX,[esp+0x14]` after SEH pushes = 2nd stack arg; `this+0x174` | **High** |
| stack count | `RET 0x14` = 5×4 | **High** |
| size gates | both ≥ 0 before `FUN_006863a0` | **High** |

---

## 4. Control flow (decompile + bytes authority)

```
this+0x174 = asset_cfg
if asset_cfg == null: return 0
ensure this+0x30 = new(0x9c)+FUN_0068a690
FUN_00685ed0(1)
if *(asset_cfg+0x128) >= 1:
  FUN_005b71a0(1); return 1
// first compute:
open resource(param_2); if null return 0
load FUN_0068b360(blob, st); release resource
if load fail: log "SpeedTreeRT Error"; return 0
configure RT (axis 1,-1,-1; flags; optional sizes)
if !FUN_00688680(0, param_4, 1):
  log "Fatal Error, cannot compute tree"; return 0
bounds/getters/LOD (dx * 5.0f); material 0x1c
optional .dds textures @ +0x170 and +0x24
FUN_005b71a0(0); return 1
```

| Stage | Match | Conf |
|---|---|---|
| Null asset early fail | Yes | **High** |
| ST object ensure 0x9c | Yes | **High** |
| Gate `+0x128` refresh vs compute | Yes | **High** |
| Plates SpeedTreeRT / compute tree | Yes | **High** |
| `.dds` + 5.0f constants | Yes (`read_memory`) | **High** |
| Body 1173 B + RET 0x14 | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00582090` @ `0x00582222`, `0x00582265` |
| Notable callees | `FUN_0068a690`, `FUN_0068b360`, `FUN_00688680`, `FUN_005b71a0`, `FUN_005b7770`×3, `FUN_005b4600`, `FUN_00416490`, `FUN_007a4480` |

---

## 6. Gaps

1. Nested SpeedTree SDK English names for `FUN_00686xxx` / `FUN_00688680` (kept `FUN_*`).  
2. Exact C++ types for `resource_key` / `asset_cfg` / `compute_arg`.  
3. Whether load destination is always `this+0x30` vs decompiler `local_c0` temp aliasing.  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI (thiscall + RET 0x14), dual-path CF (first compute vs refresh), plates, and constants sealed. Residual nested SDK plates → **accept-with-gaps**.
