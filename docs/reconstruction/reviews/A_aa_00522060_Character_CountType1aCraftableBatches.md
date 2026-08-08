# Review A (reconstruction fidelity): `aa_00522060` Character_CountType1aCraftableBatches

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522060` |
| **VA** | `0x00522060`–`0x00522203` inclusive (**420 B** / `0x1A4`) |
| **Canonical name** | `Character_CountType1aCraftableBatches` |
| **Ghidra name** | `FUN_00522060` |
| **Prior scaffold** | `FUN_00522060` / `Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060` |
| **Rejected misname** | `Named_CalleeOf_Inv_Client_ValidateCraftAffordability_00522060` (parent-seed only) |
| **Review date** | `2026-08-05` (MEGA-002 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00522060_Character_CountType1aCraftableBatches.md` |
| **System** | `inventory-transfer` (type-0x1a craft batch count) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `analyze_control_flow` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Character **thiscall** that counts how many type-**0x1a** craft batches the player can afford from **cargo + locker** inventories. Writes the total into `*outBatches` and returns whether that total is positive.

```text
Character_CountType1aCraftableBatches(self, obj, out, mode, simpleFlag) -> bool
  *out = 0
  require cargo holder, cargo grid, locker grid, type==0x1a, blob
  if simpleFlag:
      *out = count(cargo, blob+0x4c0) + count(locker, blob+0x4c0)
      return *out != 0
  if mode != 1 and cost@+0x4d4 > 0:
      *out += floor( (count cargo+locker of +0x4d0) / cost )
  if mode != 2:
      *out += min secondary slot counts (ADD, not min-with-primary)
  return *out > 0
```

Parent dualed craft consumer: `CVOGCharacter_TryType1aCraft_Inferred` (`0x005316c0`) calls this before free-slot probe and material removal.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | ≡ scaffold CF (guards → simple / primary / secondary) |
| Full body | `disassemble_function` + `read_memory` (`C2 10 00` epilogues) |
| Dual-grid this | assembly ECX loads at cargo `+0x2b0` / locker `+0xcbc` |
| Callee count | `InventoryGrid_CountItemsByCbid` `0x005711c0` (dualed) |
| Callee slots | `ItemDef_CountConfiguredModSlots_Inferred` `0x00599dd0` |
| Sample caller | craft `0x005316c0` @ `0x00531750` (mode from arg; flag `0`) |
| UI callers | `0089bc30`, `0089bf50`, `0089c330`, xref `0089cc96` |

---

## 3. Signature (sealed)

```c
// ECX=character; stack item*, outBatches*, mode, simpleFlag; AL bool; RET 0x10
bool __thiscall Character_CountType1aCraftableBatches(
    void *self,
    void *type1aObject,
    int *outBatches,
    char mode,
    char simpleFlag);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX → EBP | **Confirmed** |
| type1aObject | stack `[ESP+4]` | **Confirmed** (call sites + `CMP [EAX+0x38],0x1a`) |
| outBatches | stack `[ESP+8]` → EBX; `MOV [EBX],0` | **Confirmed** |
| mode | stack `[ESP+0xC]` | **Confirmed** (mode 1/2 gates) |
| simpleFlag | stack `[ESP+0x10]` | **Confirmed** |
| return | AL bool | **Confirmed** (`SETNZ`/`SETG`) |
| cleanup | `RET 0x10` (`C2 10 00`) | **Confirmed** ×4 exits |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| `*out = 0` | `MOV dword ptr [EBX],0` | **Confirmed** |
| Guard cargoHolder / cargo / locker | `+0x250`, `+0x2b0`, `+0xcbc` | **Confirmed** |
| Type gate `== 0x1a` | `CMP [EAX+0x38],0x1a` | **Confirmed** |
| Blob null check | `MOV EDI,[EAX+0x3c]` / `TEST` | **Confirmed** |
| `modeNot2 = (mode != 2)` | `CMP AL,2` / `SETNZ` | **Confirmed** |
| Simple path dual-count `+0x4c0` | two `CALL 005711c0` + `ADD [EBX],EAX` | **Confirmed** |
| Primary floor-div `+0x4d0/+0x4d4` | `IDIV` after dual count | **Confirmed** |
| Secondary min loop `+0x498` | `FUN_00599dd0` + min track + early break | **Confirmed** |
| Return `*out > 0` | `CMP [EBX],0` / `SETG AL` | **Confirmed** |
| Decompile ≡ raw CF | live re-verify | **Confirmed** |
| Dual-grid this restoration | assembly vs collapsed decompile | **Confirmed** (asm wins) |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (craft affordability counter) |
| External callers | **4** named funcs / **5** UNCONDITIONAL_CALL xrefs |
| Site role | type-1a craft batch ceiling before consume / UI list |
| Callees | `InventoryGrid_CountItemsByCbid` (`0x005711c0`); `ItemDef_CountConfiguredModSlots_Inferred` (`0x00599dd0`) |
| Mode matrix | 0 both / 1 skip primary / 2 skip secondary — matches parent craft |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Hard type `0x1a` gate | **Yes** (bytes) |
| Batch floor-div + secondary min | **Yes** (CF) |
| Parent craft consume uses result as available qty | **Yes** (`005316c0`) |
| Product string naming this symbol | **No** |
| Scaffold Named_CalleeOf ValidateCraftAffordability | **Reject** — parent-seed plate, not this unit's role |

**Decision:** promote **`Character_CountType1aCraftableBatches`** (partition hint). Type-1a + batch math sealed; field English remains High/Inferred.

---

## 7. Gaps

- Product English for blob fields (`+0x4c0` vs `+0x4d0` vs secondary list).
- Whether UI always uses exclusive mode 1/2 (making primary+secondary ADD moot in practice).
- Runtime Confirmed / bit-exact / differential (no Launcher).
- Secondary loop index bound = count-of-non-(-1), not dense pack — preserve; product intent open.

---

## 8. Verdict

Fidelity path seals CF/ABI/mode matrix/dual-grid counts with residual product-field English and runtime → **accept-with-gaps**.
