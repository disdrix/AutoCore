# Review A (reconstruction fidelity): `aa_00617fc0` CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00617fc0` |
| **VA** | `0x00617fc0`–`0x006180fb` inclusive |
| **Body** | **316 bytes** (`0x13C`) |
| **Canonical name (Ghidra)** | `FUN_00617fc0` |
| **Proposed name** | `CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred` |
| **Review date** | `2026-08-05` (R12-039 OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_00617fc0_CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (first dual seal)** |
| **Dual start** | 2646 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs + COL/type_info. **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

Virtual **multi-target Reflect HB spawn** method (vtbl **+0x2c** on `CVOGHBSkill_Reflect`):

1. Walk `param_4` target list (stride **0x10**) until terminator `{-1,-1,type0}`.
2. Resolve each entry via `CVOGReaction_ResolveObjectTarget` (`this = *(world+0xe4e8)`).
3. If resolved object clone type `*(*(t+0xa8)+0x38) == 0xe` (vehicle): `__RTDynamicCast` to `CVOGVehicle`, then remap target to vehicle host `*(*(*(veh+4)+4)+veh+0xb0)`.
4. `operator_new(0x6d0)` + `CVOGHBSkill_OnHit_ctor` (`0x00617ad0`) + install `PTR_FUN_009d0f7c` (Reflect).
5. If `pOwner(+0x18) != 0`: `CVOGHBList_Enqueue(*(world+0xe4ec))` + `CVOGHBBase_Start`; else scalar-deleting dtor.

**Not** OnHit base spawn (`FUN_00617df0` / vtbl `009d0f1c`); **not** the OnHit ctor itself (`FUN_00617ad0` — parent dual, called here).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00617fc0` |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/disasm/vars) |
| Assembly | `disassemble_function` full body through `RET 0x18` |
| Bytes | `read_memory` entry 256 B; terminal `C2 18 00 CC` @ `0x006180f9` |
| Meta | `get_function_by_address` body `00617fc0`–`006180fb` |
| RTTI | COL `0x00aadc14` → type_info `0x00af28f4` → **`.?AVCVOGHBSkill_Reflect@@`** |
| Vtbl | `read_memory` `0x009d0f7c`; slot +0x2c = `0x00617fc0`; +0 = `0x00651190` |
| Xrefs | sole DATA `0x009d0fa8`; no CODE callers |
| Parent dual | `CVOGHBSkill_OnHit_ctor` / `aa_00617ad0` (R11-012) |
| Sibling contrast | `FUN_00617df0` OnHit spawn (no vehicle branch; different vtbl) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_00617fc0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature

```c
// virtual slot +0x2c; ECX this unused; ret 0x18; EAX = 1
uint32_t CVOGHBSkill_Reflect_SpawnActionsForTargetList_Inferred(
    void *pSourceObj,
    void *pSkillBlob,     // period via OnHit_ctor float +0x4c
    void *pWorld,         // +0xe4e8 / +0xe4ec
    TargetEntry16 *pList, // stride 0x10
    void *pTfid16,
    uint32_t arg7);
```

| Item | Evidence |
|---|---|
| Terminal | `C2 18 00` @ `0x006180f9` |
| Vtbl imm | `C7 06 7C 0F 9D 00` after OnHit ctor |
| new size | `PUSH 0x6d0` → `operator_new` |
| OnHit ctor | `CALL 0x00617ad0` with ECX=new |
| Enqueue list | `MOV ECX,[EBP+0xe4ec]` EBP=param_3 |
| Resolve this | `MOV ECX,[EBP+0xe4e8]` before `CALL 0x004bae70` |
| Vehicle type | `CMP [ECX+0x38],0x0E` after load from target+0xa8 |
| Host remap | `MOV EDI,[ECX+EAX*1+0xB0]` after RTDynamicCast |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog / index=0 | Yes |
| Terminator triple check → return 1 | Yes |
| ResolveObjectTarget thiscall | Yes (assembly; decompile omits ECX) |
| Vehicle type 0xe + RTDynamicCast + +0xb0 host | Yes |
| new + OnHit_ctor + Reflect vtbl | Yes |
| Owner gate → Enqueue/Start vs dtor(1) | Yes |
| index++ both arms; infinite loop | Yes |
| RET 0x18 | Yes |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Class = `CVOGHBSkill_Reflect` | **Confirmed** | RTTI string |
| Role = multi-target spawn Reflect HBs | **High** | CF + vtbl self-install |
| Object size `0x6d0` | **Confirmed** | `PUSH 0x6d0` |
| Vehicle type `0xe` remap to host `+0xb0` | **Confirmed** | bytes + RTTI casts |
| HB list @ world `+0xe4ec` | **Confirmed** | matches family |
| Method product English | **Open** | `_Inferred` |
| Virtual this unused intentionally | **High** (static) | no ECX consumer |
| Param English source/skill/world | **High** via OnHit/base ctor map | arg7 Tentative |
| Host product English at vehicle+0xb0 | **High** family / Tentative product word | character host gate |

---

## 6. Gaps / open

1. Product method name for slot +0x2c.  
2. Virtual call sites / list producers (not CODE xrefs).  
3. Null-`operator_new` and null-RTDynamicCast crash paths (static UB).  
4. Product English for vehicle host `+0xb0`.  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — class Confirmed; CF/ABI/vtbl/vehicle branch High; method English open.
