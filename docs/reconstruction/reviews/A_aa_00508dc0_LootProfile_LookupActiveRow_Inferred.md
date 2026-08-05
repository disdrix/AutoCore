# Review A (reconstruction fidelity): `aa_00508dc0` LootProfile_LookupActiveRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508dc0` |
| **VA** | `0x00508dc0` |
| **Canonical name** | `LootProfile_LookupActiveRow_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00508dc0`; scaffold `Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00508dc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00508dc0_LootProfile_LookupActiveRow_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Active loot/credit-profile row lookup** on a table object. Given a profile/table root in ECX, if the map at `table+0xb0` is non-empty (`table+0xb8 != 0`), run `Map_LowerBoundFindByIntKey` and return the payload pointer at `node+0x10` when the lower-bound hits a live node; otherwise return **0**.

Shared helper for death-path credit roll (`FUN_00508e70`), primary kill-loot generator (`FUN_0050ac80`), and level-gated sector loot (`FUN_004d4440`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00508dc0_FUN_00508dc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00508dc0_FUN_00508dc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00508dc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00508dc0_FUN_00508dc0.md` |
| Live decompile | Ghidra `batch_decompile` `0x00508dc0` (2026-07-29) — **≡ raw body** |
| Callers | `get_function_callers`: `FUN_004d4440`, `FUN_00508e70`, `FUN_0050ac80` |
| Related duals | `A_aa_00508e70_*`, `A_aa_0050ac80_*`, `A_aa_004d4440_*` |

**Not performed:** `disassemble_bytes`, Launcher, live CE, ledger updates.

---

## 3. Control flow (authoritative raw / live)

```
FUN_00508dc0(table /* ECX */):
  if *(int*)(table + 0xb8) == 0:
    return 0
  // Map root at table+0xb0; end sentinel at table+0xb4
  Map_LowerBoundFindByIntKey(table+0xb0, &node, &key, …)
  if node == *(int*)(table + 0xb4):   // end / miss
    return 0
  Map_LowerBoundFindByIntKey(…)        // re-resolve (decompiler double-call)
  return *(void**)(*node + 0x10)      // payload
```

Decompiler shows a second identical lower-bound call before the payload load (likely iterator re-materialization / Ghidra artifact). Product: null-safe map hit → row pointer.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` ECX = table/object with map `@+0xb0` | **High** | Live + all three callers |
| Empty map (`+0xb8 == 0`) → 0 | **High** | Early return |
| Miss / end sentinel (`node == +0xb4`) → 0 | **High** | |
| Hit → payload at `*node + 0x10` | **High** | Matches credit dual notes |
| Shared by credit + item loot paths | **High** | Callers sealed |
| Exact map **key** identity / provenance | **Open** | `stack0x00000004` / `unaff_ESI` residual in decompile |
| Product name “LootProfile” vs “CreditTable” | **Probable** | Same helper, multiple table kinds |
| Double lower-bound call is intentional | **Tentative** | May be decompiler noise |

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Empty `+0xb8` gate | **Yes** |
| Lower-bound map probe | **Yes** |
| End-sentinel miss → 0 | **Yes** |
| Payload `+0x10` return | **Yes** |

Scaffold clean is mechanical rewrite of raw; no CF drift.

---

## 6. Callers

| Site | Role |
|---|---|
| `CreditLoot_RollAmount_Inferred` `0x00508e70` | Credit row for amount roll |
| `KillLoot_GenerateDrops_Inferred` `0x0050ac80` | Profile for death drops |
| `CVOGSectorMap_GenerateLevelGatedLoot` `0x004d4440` | Loot def / key path |

---

## 7. Gaps / open

1. Seal exact key type (level? zone id? def field) at each call site.
2. Confirm whether second `Map_LowerBoundFindByIntKey` is real asm or decompiler artifact.
3. Table layout registry entry for `+0xb0/+0xb4/+0xb8` + node `+0x10`.

**Verdict:** CF **High**. Key identity residual. **accept-with-gaps.**
