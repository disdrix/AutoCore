# Review A (reconstruction fidelity): `aa_00933310` Client_UI_RefreshInventoryWindows_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00933310` |
| **VA** | `0x00933310`–`0x0093336f` inclusive (**96 B** / `0x60`) |
| **Canonical name** | `Client_UI_RefreshInventoryWindows_Inferred` |
| **Ghidra name** | `FUN_00933310` |
| **Prior scaffold** | `FUN_00933310` / `Named_CalleeOf_Client_RecvInventoryUseItemResponse_00933310` |
| **Rejected misname** | product demangle; pure ECX-thiscall; decompiler `void(void)` |
| **Review date** | `2026-08-05` (MEGA-099 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00933310_Client_UI_RefreshInventoryWindows_Inferred.md` |
| **System** | inventory-transfer (UI map side-effect) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `get_function_signature` + `get_function_hash` + `batch_decompile` (callers + `00402b30`). **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **pack-and-insert** helper after inventory remove/use/tinker/gadget mutations:

```text
Client_UI_RefreshInventoryWindows_Inferred(item*, flag, client, a1, a2, a3, a4)
  value.key = (uint32)item*
  fold a1/CL/a2/a3/a4 into value payload fields
  map = client + 0xF14
  StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx(map, &out, &value)  // 00402b30
  // discard out; RET 0x14
```

Not a window walk. Shared **client+0xF14** map with dualed `Client_NotifyActiveMissionChanged` (direct `00402b30` sites).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | understates ABI; CF = single insert call |
| Full body | `disassemble_function` + `read_memory` 96 B |
| Hash | `a04b98d42bef5dfd0234a2fbaae83339f2d6cccd70eb691f4bd712d07fe98c30` |
| Callee | dualed MEGA-040 `StdMap_InsertOrFind_UintKey_Isnil31_EaxEbx_Inferred` |
| Call sites | 5 UNCONDITIONAL_CALL; assembly context on all |
| Sample parent | `Client_RecvInventoryUseItemResponse` @ `0x008102de` |

---

## 3. Signature (sealed)

```c
// EAX=item*; CL=flag; stack client,a1,a2,a3,a4; void; RET 0x14
void Client_UI_RefreshInventoryWindows_Inferred(
    void *itemOrObject,   // EAX
    uint8_t flag,         // CL
    void *client,         // stack0
    int a1, int a2, int a3, int a4);
```

| Formal | Source | Conf |
|---|---|---|
| itemOrObject | **EAX** → value.key dword0 | **High** (call sites + stores) |
| flag | **CL** → pack byte | **High** (`XOR CL,CL` sites) |
| client | stack0 → `ADD …,0xF14` map base | **High** |
| a1..a4 | stack1..4; sites const **1,0,-1,-1** | **High** |
| cleanup | **`RET 0x14`** (`C2 14 00`) | **High** |
| callee | `CALL 00402b30` only | **High** |
| map offset | **`0xF14`** | **High** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| `SUB ESP,0x38` frame | bytes | **High** |
| Pack value from EAX/CL/stack | stores | **High** |
| `ADD EAX,0xF14` map | imm `05 14 0f 00 00` | **High** |
| `LEA EBX,value` + `PUSH out` + `CALL 00402b30` | disasm | **High** |
| Discard pair; `ADD ESP,0x38`; `RET 0x14` | epilog | **High** |
| No other calls / branches | single BB | **High** |
| Decompiler ≡ raw CF (insert only) | yes | **High** |
| Decompiler ≡ ABI | **no** — assembly wins | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| External callers | **4** functions / **5** call sites |
| Site roles | post-inventory mutation UI map insert; often followed by `Client_RefreshOpenMissionUiWindows` |
| Callees | `00402b30` only |
| Family | shared map with NotifyActiveMissionChanged; inventory-only wrapper |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Inventory-only callers after item remove/use | **Yes** |
| Map insert at client+0xF14 | **Yes** |
| Mega hint `Client_UI_RefreshInventoryWindows` | **Yes** (role) |
| PDB / demangle product English | **No** → **`_Inferred`** |
| Direct window walk / vtbl refresh | **No** (mechanism = map insert) |
| Scaffold `Named_CalleeOf_*RecvInventoryUseItem*` as sole role | **Rejected** (multi-caller) |

---

## 7. Gaps

- Product map T / payload field English.
- Uninit local fold (`MOV EAX,[ESP+0xc]`).
- Whether insert buynode or later consumers perform visible UI refresh.
- Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — CF/ABI/RET0x14/EAX-key/client+0xF14/callee/5 call sites sealed; product English and UI refresh mechanism depth open.
