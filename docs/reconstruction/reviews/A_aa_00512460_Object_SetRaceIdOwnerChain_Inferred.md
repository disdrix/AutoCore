# Review A (reconstruction fidelity): `aa_00512460` Object_SetRaceIdOwnerChain_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00512460` |
| **VA** | `0x00512460` |
| **Canonical name** | `Object_SetRaceIdOwnerChain_Inferred` |
| **Ghidra name** | `FUN_00512460` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (A) |
| **Counterpart** | `reviews/B_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md` |
| **System** | object / faction |
| **Dual status** | **Written this pass** (W24-G) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf **thiscall** that **writes** race/faction id (`RACE_ID_INFERRED`) at object field **`+0x10`**, then walks the **owner chain** at **`+0xAC`** and writes the **same id** on every owner **including the root**.

Companion **writer** to sealed getter `Object_GetRootRaceId` (`aa_00512440` @ `0x00512440`).

Primary domain use: spawnpoint **`FactionDirty`** apply (`CVOGSpawnPoint_CreateCreature` / `CreateTemplateVehicle`), vehicle/driver faction push, reaction dispatch race rewrites, and prediction reconcile.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `raw/aa_00512460_FUN_00512460.md` |
| Annotated | `raw/aa_00512460_FUN_00512460.annotated.md` |
| Clean scaffold | `reconstructed-exact/FUN_00512460.cpp` |
| Clean named | `reconstructed-exact/Object_SetRaceIdOwnerChain_Inferred.cpp` |
| Function records | `functions/aa_00512460_*` |
| Ghidra | `decompile_function`, `read_memory`, `get_function_by_address`, callers/xrefs |
| Sibling seal | `Object_GetRootRaceId` dual A/B |
| Domain | `docs/NPC.md` §15.3 FactionDirty |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body bounds `00512460`–`00512487`, 39 B | **High** | Function meta + epilogue bytes |
| `__thiscall` ECX + stack DWORD, `ret 4` | **High** | `mov edx,[esp+4]`; `C2 04 00` |
| Write self `+0x10` then owners via `+0xAC` | **High** | Decompile ≡ bytes |
| Root is written (not skipped) | **High** | Loop writes before checking next owner null |
| Leaf (no callees) | **High** | Signature/meta `call_count: 0` |
| Id domain = race/faction | **High** | Sibling getter + spawn/hostility consumers |
| Product C++ field names | **Tentative** | Offsets sealed; names not |
| Full faction enum table | **Partial** | 0/1/2 + −1/−100 known at callers |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load owner / write self `+0x10` | Yes |
| Early exit if no owner | Yes (`jz` after self write) |
| Loop write owner, advance `+0xAC` | Yes |
| `ret 4` | Yes |
| No invented null/cycle checks | Yes |

---

## 5. Gaps / open

1. Product member names for `+0xAC` / `+0x10`.
2. Whether race vs faction are always one DWORD domain (callers treat unified).
3. Owner-chain cycle / corruption policy.
4. Runtime capture / bit-exact image diff.
5. Per-caller MI base adjustment is caller-owned.

**Verdict:** **accept-with-gaps**
