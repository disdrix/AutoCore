# Review A (reconstruction fidelity): `aa_00513fc0` Item_RequiresBindOrTradeLock

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513fc0` |
| **VA** | `0x00513fc0` |
| **Canonical name** | `Item_RequiresBindOrTradeLock` (proposed; was `FUN_00513fc0`) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_00513fc0_Item_RequiresBindOrTradeLock.md` |
| **System** | `inventory-transfer` |
| **Work item** | MEGA-050 OWN-ONLY dual seal |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold + Named_CalleeOf mis-seed) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Per-item bind / permanent-customize / trade-lock requirement probe.** Returns whether equipping or applying the item should trigger bind-on-customize handling (modal warn, tooltip, auto-set `ItemFlag_Customized`). Does **not** set bit20 itself and does **not** emit packets.

**Calling convention:** `__thiscall` — **ECX = Item\***; stack `coid_lo` (`item+0x160`), `coid_hi` (`item+0x164`); **AL** bool; **`RET 8`**.

| Slot | Role | Evidence |
|------|------|----------|
| `this` / ECX | `Item*` | Entry `MOV EAX,[ECX+0xa4]`; all call sites `mov ecx, item` |
| stack arg1 | COID lo | Callers push `[item+0x160]` |
| stack arg2 | COID hi | Callers push `[item+0x164]` |
| AL | bool | `MOV AL,1` / `MOV AL,BL` / zero path |

**Side effects:** none on success path beyond resolve lookup (read-only predicate).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513fc0_FUN_00513fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513fc0_FUN_00513fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_RequiresBindOrTradeLock.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513fc0.cpp` |
| Function records | `docs/reconstruction/functions/aa_00513fc0_FUN_00513fc0.md` + named |
| Live re-decompile | Ghidra `decompile_function` @ `0x00513fc0` — **≡ raw body** |
| Complete analyze | `analyze_function_complete` (callers/xrefs/callees/disasm) |
| Bytes | `read_memory` 144 B @ `0x00513fc0` — ends three `c2 08 00` |
| Disassembly | `disassemble_function` full body (no `disassemble_bytes`) |
| Parent dual | `Client_ConfirmEquipOrCustomizeItem` `0x00941b20` |
| Sibling | `Item_SetCustomized` `0x00513e30` |

**Not performed:** `disassemble_bytes` primary, Launcher, live CE, bit-exact image diff.

---

## 3. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| Resolve via `CVOGReaction_ResolveObjectTarget(1, coid…)` | **Yes** |
| Null → false | **Yes** |
| Type ∈ `{0xc,0x1c,0xa,0x10,0xe}` | **Yes** (asm CMP chain) |
| Type 6 + subtype `{10,11}` @ `blob+0x3f4` | **Yes** |
| `need = (blob+0x4b8 >= 2)` | **Yes** (`1 < short` ≡ `>= 2`) |
| `vtbl+0x60 != 0` → true | **Yes** (`TEST/JBE`) |
| Else return `need` | **Yes** |
| Outside type gate → false | **Yes** |

### Closed form (sealed)

```text
obj = Resolve(item, coid)
if !obj: return false
if !TypeEligible(obj): return false
if vtbl60(obj) != 0: return true
return (int16)(blob+0x4b8) >= 2
```

---

## 4. Role vs siblings

| Related unit | VA | Role vs this function |
|---|---|---|
| `Item_SetCustomized` | `0x00513e30` | **Writes** bit20; this unit only **reads** bind need |
| `Client_ConfirmEquipOrCustomizeItem` | `0x00941b20` | Caller: modal when this∧!bit20∧confirmFlag |
| `Item_IsStackEligible` | `0x00513e70` | Stack flag predicate; different offsets |
| Capacity | `0x0040abf0` | Qty room; not bind |

Modal string evidence (caller, not body):  
`"Warning: This will permanently customize this item to you! If you do this, you will no longer be able to trade it."`  
Tooltip caller: `"\nCustomizes On Equip"`.

---

## 5. Confidence

| Dimension | Level |
|---|---|
| Function boundary / size (`00513fc0`–`0051404f`, 0x90) | **High / Sealed** |
| ECX=item, 2 stack COID, RET 8 | **High / Sealed** |
| Type-class + subtype gate | **High / Sealed** |
| `blob+0x4b8 >= 2` + vtbl+0x60 force | **High / Sealed** |
| Role = bind/customize/trade-lock need | **High / Sealed** (caller strings + CF) |
| Product type-class English | Tentative / Open |
| `blob+0x4b8` / vtbl+0x60 product names | Tentative / Open |
| Original PDB symbol | Open |
| Overall | **Probable / accept-with-gaps** |

---

## 6. Verdict

### **accept-with-gaps**

**Accept:** Live body matches raw; asm seals ABI decompiler missed; type gate and dual return paths sealed; four callers + modal/tooltip strings lock role; Named_CalleeOf scaffold retired.

**Gaps:** type taxonomy English, field/vfunc product names, PDB symbol, runtime/diff.
