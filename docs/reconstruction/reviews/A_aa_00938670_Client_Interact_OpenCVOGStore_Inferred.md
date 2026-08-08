# Review A (reconstruction fidelity): `aa_00938670` Client_Interact_OpenCVOGStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00938670` |
| **VA** | `0x00938670`–`0x009387dc` inclusive (**365 B** / `0x16D`) |
| **Canonical name** | `Client_Interact_OpenCVOGStore_Inferred` |
| **Ghidra name** | `FUN_00938670` |
| **Prior scaffold** | `Named_CalleeOf_Client_InteractClickPickTarget_00938670` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-027 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00938670_Client_Interact_OpenCVOGStore_Inferred.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Client-side **store interact open** helper:

1. Optionally **park** the local vehicle (flag 109, handbrake, longitudinal 0).
2. Resolve stack **TFID_16** → object and **dynamic_cast** to **`CVOGStore`**.
3. No-op if the matching store dialog is already open on this store.
4. Send C2S packet **opcode 0x2024** (size 0x18) with the TFID.
5. Stamp TFID into dialog host storage and open dialog index **0x0B** or **0x0C**.

Triggered from world click type-switch **case 0x16** and from sector-event dispatcher case **3**.

```text
Client_Interact_OpenCVOGStore_Inferred(client=ESI, tfid)
  if vehicle entity:
    SetFlag_109(1); SetHandbrake(1); SetLongitudinalInput(0)
  store = dyn_cast<CVOGStore>(Resolve(tfid))
  if !store: return
  if already-open same store on dialog 0xB/0xC: return
  SendPacket(0x2024, tfid, 0x18)
  stamp tfid; OpenDialog(0xB|0xC, 1, 0)
```

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (park → cast → gates → 0x2024 → open) |
| Full body | `disassemble_function` + `read_memory` (entry + epilogue `C2 10 00`) |
| RTTI | `.?AVCVOGStore@@` @ `0x00afe0c8`; `.?AVCVOGClonedObjectBase@@` @ `0x00af8e10` |
| Callers | `Client_InteractClickPickTarget` @ `0x00924f8c`; `FUN_00946c00` @ `0x00947057` |
| Call-site ABI | `get_assembly_context` — ESI load + `SUB ESP,0x10` TFID push |
| Dialog hub | `FUN_007fef20` — `client+0x1030+idx*4` → hosts `0x105c`/`0x1060` |
| Vehicle park | `VehicleEntity_SetFlag_109` / `SetHandbrake` / `SetLongitudinalInput` |

---

## 3. Signature (sealed)

```c
// ESI = ClientController* (live-in; not ECX thiscall)
// stack = TFID_16 (4 dwords); void; RET 0x10
void Client_Interact_OpenCVOGStore_Inferred(
    /*ESI*/ ClientController* client,
    uint32_t tfid0, uint32_t tfid1, uint32_t tfid2, uint32_t tfid3);
```

| Formal | Source | Conf |
|---|---|---|
| client | ESI live-in (`MOV ESI,0xd1a840` / `MOV ESI,EBX`) | **Confirmed** |
| TFID | stack 16 B; LEA into `Object_ResolveFromTFID` | **Confirmed** |
| return | void | **Confirmed** |
| cleanup | `RET 0x10` (`C2 10 00`) | **Confirmed** |
| body size | `0x16D` to inclusive RET | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Vehicle entity null-check `+0xe98→+0x250` | `TEST ECX / JZ` | **Confirmed** |
| Park triple (flag109 / HB / long=0) | three CALLs | **Confirmed** |
| Resolve + RTDynamicCast to CVOGStore | TD pushes + CALL pair | **Confirmed** |
| Null store early RET | `TEST EBX / JZ epilog` | **Confirmed** |
| Dialog 0xB already-open gate | vtbl`+0x3d8` + cmp `+0x588` | **Confirmed** |
| Dialog 0xC already-open gate | vtbl`+0x3d8` + cmp `+0x5a0` | **Confirmed** |
| Packet opcode 0x2024 size 0x18 | `MOV [ESP+…],0x2024` + send | **Confirmed** |
| Dialog index 0xB vs 0xC by `store+0x4e5` | JZ branch + PUSH 0xB/0xC | **Confirmed** |
| `FUN_007fef20(ECX=ESI, idx, 1, 0)` | final CALL | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (interaction / store UI) |
| External callers | **2** UNCONDITIONAL_CALL |
| Site roles | type **0x16** click interact; sector event case **3** |
| Callees | SetFlag_109, SetHandbrake, SetLongitudinalInput, Object_ResolveFromTFID, __RTDynamicCast, FUN_007fef20, virtuals |
| System | `interaction-activation` (partition MEGA-027) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| RTTI `.?AVCVOGStore@@` | **Yes** |
| Parent `Client_InteractClickPickTarget` type 0x16 | **Yes** |
| Vehicle park + open dialog path | **Yes** |
| Product English for dialog 0xB/0xC titles | **No** |
| Product English for `store+0x4e5` | **No** |

**Decision:** promote **`Client_Interact_OpenCVOGStore_Inferred`**. Retire `Named_CalleeOf_*` scaffold. `_Inferred` retained for product UI English gaps.

---

## 7. Gaps

- Product names for dialog slots **0x0B** / **0x0C**.
- Semantic label of `CVOGStore+0x4e5` subtype byte.
- Product name for `FUN_007fef20` dialog open hub.
- Full 0x2024 field map beyond opcode + TFID (0x18 layout middle dword).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity path accepts CF/ABI/RTTI/callers with product-UI English residual → **accept-with-gaps**.
