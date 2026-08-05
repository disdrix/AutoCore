# Review A (reconstruction fidelity): `aa_00979290` ClientSpecialEvent_Respawn_TeardownAirlift

| Field | Value |
|---|---|
| **Stable ID** | `aa_00979290` |
| **VA** | `0x00979290`–`0x009792ff` (112 B) |
| **Canonical name** | `ClientSpecialEvent_Respawn_TeardownAirlift` (inferred; Ghidra `FUN_00979290`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W23-I) |
| **Counterpart** | `reviews/B_aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md` |
| **System** | client special-event / respawn |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Shared **Respawn airlift teardown** (EDI = `ClientSpecialEvent_Respawn* this`):

1. Gate on `this+0x38` (full-sequence / airlift-active).
2. Resolve controlled entity TFID at `this+0x28` via sealed `Object_ResolveTfIdVtbl1d4_Inferred` (ECX = `DAT_00b04830`).
3. If resolved: virtual `vtbl+0x1bc(0)`; restore mode dword `*(phys+0x28) = this+0x68`; `FUN_00560e90(phys)`; if `this+4==0` call `Vehicle_ActivateEnterWorld` with **ECX = resolved**.
4. Clear `this+0x38 = 0` (even if resolve failed).

Called from **Update** phase 4→5 (after lift-follow clear) and from **dtor**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function records | `aa_00979290_FUN_00979290.md`, `aa_00979290_ClientSpecialEvent_Respawn_TeardownAirlift.md` |
| Raw | `docs/reconstruction/raw/aa_00979290_FUN_00979290.md` (+ W23-I live seal) |
| Annotated | `docs/reconstruction/raw/aa_00979290_FUN_00979290.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ClientSpecialEvent_Respawn_TeardownAirlift.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00979290.cpp` |
| Live decompile | Ghidra `decompile_function` `0x00979290` |
| Live body | `read_memory` full 112 B |
| Callers | Update `0x00979730`, dtor `0x00979c70` |
| Parent duals | `A_aa_00979730_*`, `A_aa_00979c70_*`, `A_aa_00979310_SetupAirlift` |
| Callee dual | `A_aa_004bb010_Object_ResolveTfIdVtbl1d4_Inferred` |

**Not performed:** Launcher, runtime, bit-exact, deep dual of `FUN_00560e90` / vtbl `+0x1bc` product.

---

## 3. Signature

```c
// EDI = ClientSpecialEvent_Respawn* this
void ClientSpecialEvent_Respawn_TeardownAirlift(void /*EDI this*/);
```

| Formal | Source | Conf |
|---|---|---|
| Event `this` | **EDI** | **High** (offsets + callers match Respawn layout dual) |
| Stack | none | **High** (`ret` plain `C3`) |

---

## 4. Control flow checklist

| Stage | Match | Conf |
|---|---|---|
| Gate `this+0x38` | **Yes** | **Confirmed** |
| ECX = `[DAT_00b04830]` before resolve | **Yes** | **Confirmed** (bytes) |
| `FUN_004bb010(this+0x28)` | **Yes** | **Confirmed** |
| `vtbl+0x1bc(0)` | **Yes** | **Confirmed** (`ff 90 bc 01 00 00`) |
| Restore `phys+0x28` from `this+0x68` | **Yes** | **Confirmed** |
| `FUN_00560e90` | **Yes** | **High** |
| `Vehicle_ActivateEnterWorld` if `this+4==0` (ECX=obj) | **Yes** | **Confirmed** (bytes `mov ecx,esi`) |
| Clear `this+0x38` | **Yes** | **Confirmed** |
| Skip body if gate closed | **Yes** | **Confirmed** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **112 B** / end `009792ff` | **Confirmed** | `get_function_by_address` |
| EDI-this ABI plain ret | **Confirmed** | epilogue `5e c3` |
| Role: airlift teardown not setup | **High** | callers + sibling Setup dual |
| Latch `+0x38` shared with Update phase 2 | **High** | parent dual |
| Resolve ctx global | **High** | matches Object_Resolve dual pattern |
| vtbl `+0x1bc` product English | **Open** | slot sealed, name residual |
| `this+4` / `this+0x68` product names | **Tentative** | offsets sealed |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Product name for virtual `+0x1bc`.  
2. Product meaning of event `+0x04` suppress-activate flag and `+0x68` mode snapshot.  
3. Whether `FUN_00560e90` staged stack byte is a true formal.  
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
