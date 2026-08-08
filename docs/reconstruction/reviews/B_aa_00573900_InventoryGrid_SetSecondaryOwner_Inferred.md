# Review B (skeptical / adversarial): `aa_00573900` InventoryGrid_SetSecondaryOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573900` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-092 dual) |
| **Counterpart** | `reviews/A_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md` |
| **System** | `inventory-transfer` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** on CF + ABI + vtbl + store; **reject** overclaims of product English / primary-owner merge / runtime Confirmed |
| **Terminal** | **false** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is `SetOwner` (`+0x24` / vtbl+0x18) | **Falsified** — different body `0x005718a0`; this unit never writes `+0x24`, never walks list |
| 2 | This is `SetOwnerFlag` (`+0x4`) | **Falsified** — different unit `0x00570600`; only store is `+0x58` |
| 3 | Method also rebinds items like SetOwner | **Falsified** — 10 B leaf; no CALL |
| 4 | Direct CALL graph callers exist | **Falsified** — Ghidra callers empty; only DATA vtable xref @ `0x009d33a4` |
| 5 | Function was already defined in Ghidra | **Falsified** — entry was undefined code; `create_function` required for decompile |
| 6 | Body is 9 B / ends before `C2` | **Falsified** — inclusive end `0x00573909` = **10 B** including `RET 4` |
| 7 | `stdcall` / stack-this | **Falsified** — store uses **ECX** as base; classic thiscall |
| 8 | Returns the stored pointer in EAX | **Overclaim** — EAX holds arg only as store source; no post-store EAX contract; decompiler void is correct for port |
| 9 | Product name `SetSecondaryOwner` proven from strings | **Fail** — no string refs; remains `_Inferred` |
| 10 | Pointee is proven `CVOGCharacter*` | **Overclaim** — cargo expression Probable character; type not sealed here |
| 11 | Ready for Terminal / runtime Confirmed | **Fail** — no Launcher; Terminal false |
| 12 | Adjacent `0x00573910` is the same method | **Falsified** — pad `CC` then scalar deleting dtor (vtbl[0]) |

---

## 2. Decisive dataflow (SEALED)

```
// bytes: 8B 44 24 04  89 41 58  C2 04 00
EAX = *(ESP+4)          // stack arg
*(ECX + 0x58) = EAX     // secondary owner slot
return                  // RET 4
```

Live 2026-08-05 decompile after function create:

```c
void __thiscall FUN_00573900(int param_1, undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x58) = param_2;
  return;
}
```

Vtbl: `read_memory(0x009d33a4) = 0x00573900` = `PTR_FUN_009d3390 + 0x14`.

Parent dual `Vehicle_CreateCargoInventoryFromPageCount` already sealed the virtual call order:

```
SetOwnerFlag(grid, 1)
(grid.vtbl+0x18)(owner_entity)   // SetOwner → +0x24 + rebind
(grid.vtbl+0x14)(char_expr)      // THIS → +0x58 only
```

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store CF + 10 B body | **High** | Broken cargo secondary bind |
| RET 4 / thiscall | **High** | Stack imbalance |
| vtbl slot +0x14 | **High** | Wrong virtual dispatch |
| Offset `+0x58` | **High** | Wrong field |
| Secondary-owner English | **Tentative** | Port naming only |
| Pointee type | **Probable** | Wrong typed port field |
| Runtime golden | **Open** | Residual parity |

---

## 4. Surviving contract for AutoCore

```
InventoryGrid.SetSecondaryOwner(ptr):
  grid.SecondaryOwner = ptr    // +0x58 only
  // does NOT set OwnerFlag (+0x4)
  // does NOT set OwnerObject (+0x24)
  // does NOT rebind items
```

Ports that fold this into `SetOwner` or skip the cargo vfunc+0x14 call will diverge from client vehicle cargo create.

---

## 5. Residual gaps

- Product symbol / field English for `+0x58`.
- Exact pointee type (character vs abstract).
- Other virtual callers (no static edges).
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
