# Review A (reconstruction fidelity): `aa_00522020` Character_SelectInventoryGridByMode (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00522020` |
| **VA** | `0x00522020` |
| **Canonical name** | `Character_SelectInventoryGridByMode` (**INFERRED**) |
| **Ghidra symbol** | `FUN_00522020` |
| **Review date** | `2026-08-05` |
| **Agent** | MEGA-045 OWN-ONLY |
| **Counterpart** | `reviews/B_aa_00522020_Character_SelectInventoryGridByMode_Inferred.md` |
| **System** | `inventory-transfer` |
| **Parent batch** | MEGA residual dual seal — parent `0x00941b20` equip/customize confirm |
| **Partition hint** | `Character_SelectInventoryGridByMode` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Select Character inventory grid by mode** — pure pointer table / switch leaf:

```c
// __thiscall: ECX = Character*
// stack: int mode
// RET 4; EAX = InventoryGrid* or 0
InventoryGrid* Character_SelectInventoryGridByMode_Inferred(Character* ch, int mode) {
  if (mode == 1) {
    void* mid = *(void**)((char*)ch + 0x250);
    if (mid) return *(InventoryGrid**)((char*)mid + 0x2B0); // cargo
  } else if (mode == 3) {
    return *(InventoryGrid**)((char*)ch + 0xCBC); // locker
  } else if (mode == 5) {
    return *(InventoryGrid**)((char*)ch + 0xCE0); // trade
  }
  return nullptr;
}
```

No place/stamp/mutation. Read-only selector used by equip space-check path.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | `decompile_function` + `analyze_function_complete` ≡ raw scaffold (2026-07-23) |
| Live bytes | `read_memory` 61 B body + `RET 4` ×4; pad `CC` before `0x00522060` |
| Live asm | `disassemble_function` — subtract-chain mode decode; ECX loads |
| Callers/xrefs | 1× UNCONDITIONAL_CALL `0x00941bc7` in `FUN_00941b20` |
| Callees | none (leaf) |
| Cross-dual | DropResponse / GrabApply invType 1/3/5 grid map |
| Clean | `reconstructed-exact/Character_SelectInventoryGridByMode_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Control flow: bytes ≡ decompile

| Stage | Match |
|---|---|
| Load mode from `[ESP+4]` | **Yes** (`MOV EAX,[ESP+4]`) |
| `SUB 1` / `JZ` → mode 1 | **Yes** → `0x0052204a` |
| `SUB 2` / `JZ` → mode 3 | **Yes** → `0x00522041` |
| `SUB 2` / `JZ` → mode 5 | **Yes** → `0x00522038` |
| Default `XOR EAX,EAX; RET 4` | **Yes** |
| Mode 5: `[ECX+0xCE0]` | **Yes** |
| Mode 3: `[ECX+0xCBC]` | **Yes** |
| Mode 1: `[ECX+0x250]`; `TEST`; null → default 0 | **Yes** (`JZ 0x00522033`) |
| Mode 1 hit: `[EAX+0x2B0]` | **Yes** |
| All exits `RET 4` | **Yes** (`C2 04 00`) |
| No callees | **Yes** |

### Body

| Field | Value |
|---|---|
| Start | `0x00522020` |
| End inclusive | `0x0052205c` |
| Size | **61 B** (`0x3D`) |
| Pad | `CC` → sibling `FUN_00522060` @ `0x00522060` |

### Offsets

| Off | Role | Confidence |
|----:|------|------------|
| `ch+0x250` | mid object* (cargo host) | **High** CF |
| mid`+0x2B0` | cargo InventoryGrid* | **High** (invType1 / commodity duals) |
| `ch+0xCBC` | locker InventoryGrid* | **High** load; English via DropResponse duals |
| `ch+0xCE0` | trade InventoryGrid* | **High** load; English via DropResponse duals |

---

## 4. Callers (context, not owned)

| Caller | Site | Role |
|---|---|---|
| `FUN_00941b20` | `0x00941bc7` | After item-type≠4 gate: `grid = Select(mode)`; if unequip-target present and grid==0 → UI path `FUN_007fc270(2)`; else footprint/place (`005715d0`/`005714e0`) with inventory-full string |

Caller strings (parent evidence only): `"There is not enough space in your inventory for this equipment."`, customize-bind warning, town-only change.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| CF + mode cascade 1/3/5 | **High** |
| ABI thiscall + RET 4 + EAX grid* | **High** |
| Leaf (no callees) | **High** |
| Cargo path `+0x250/+0x2B0` | **High** |
| Mode 3/5 field loads | **High** |
| Product English (locker/trade labels, method name) | **Inferred / Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed inventory-grid selector leaf; name `_Inferred` (no demangle).
