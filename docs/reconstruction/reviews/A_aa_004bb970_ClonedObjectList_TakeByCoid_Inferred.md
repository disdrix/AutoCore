# Review A (reconstruction fidelity): `aa_004bb970` ClonedObjectList_TakeByCoid (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb970` |
| **VA** | `0x004bb970` |
| **Canonical name** | `ClonedObjectList_TakeByCoid` (**INFERRED**) |
| **Ghidra symbol** | `FUN_004bb970` |
| **Review date** | `2026-07-29` |
| **Counterpart** | `reviews/B_aa_004bb970_ClonedObjectList_TakeByCoid_Inferred.md` |
| **System** | `inventory-transfer` / object list |
| **Parent batch** | AddItem nested via `Inv_lootpickup` `0x00945540` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Locate a cloned object by COID inside a list host, detach auxiliary links, return object pointer** (or 0).

Strings (body):
- `"Null return value in clonedobjectlist %I64d, %d"`
- `"Null typelist in clonedobjectlist %I64d, %d"`

```c
// __thiscall ret 0x0C
int ClonedObjectList_TakeByCoid(ListHost* this, uint modeFlag, uint coidLo, uint coidHi);
```

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | `batch_decompile` `0x004bb970` ≡ raw (long body) |
| Live bytes | prologue `push ecx; push esi; mov esi,ecx; cmp byte [esi+0xe],0` … `ret 0x0C` |
| Xrefs | 7 sites including lootpickup `0x009456a2` |
| Raw | `raw/aa_004bb970_FUN_004bb970.md` |

**Not performed:** `disassemble_bytes`, Launcher.

---

## 3. Control flow (sealed high-level)

| Stage | Behavior | Confidence |
|---|---|---|
| Early out if `this+0xe != 0` | return 0 | **High** |
| Mode byte selects gate `this+0xd` vs `this+0xc` | zero gate → return 0 | **High** |
| `FUN_004bcda0(coidLo, coidHi, &obj)` | resolve; fail/`obj==0` → log + 0 | **High** |
| `CNDHash_LookupByKey(this+0x18, clonebase+0x38)` | type list; null → log + 0 | **High** |
| Clear/detach fields on object `+0xdc`, `+0xd4`, `+0xd0`, `+0xd8` via `FUN_004bca50` | unlink helpers | **High** CF |
| Optional erase from vector `this+0x2c` / `+0x3c` / type-`0x14` vector `+0x4c` | membership remove | **High** |
| Return object ptr | success | **High** |

### ABI

| Slot | Role |
|------|------|
| ECX | list host (`clonedobjectlist`) |
| stack0 | mode / path flag (selects `+0xc` vs `+0xd` gate) |
| stack1/2 | COID lo/hi |
| ret | object* or 0; `ret 12` |

---

## 4. Confidence

| Claim | Confidence |
|---|---|
| Role = take/detach from clonedobjectlist by COID | **High** (strings + CF) |
| Loot place path consumer | **High** (xref) |
| Full semantics of each `+0xd0..+0xdc` link | **Probable** |
| Mode flag English | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — loot/object-list take leaf sealed at CF + string level.
