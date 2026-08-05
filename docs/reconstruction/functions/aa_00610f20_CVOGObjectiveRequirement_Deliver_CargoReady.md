# Function record: Deliver CargoReady (INFERRED)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00610f20` |
| **Canonical name** | `CVOGObjectiveRequirement_Deliver_CargoReady_Inferred` |
| **Address** | `0x00610f20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Status** | Human-refined partial; **dual residual sealed 2026-07-29** (`+0x23` polarity + authorship + ABI) |
| **Name confidence** | Probable (role); suffix `_Inferred` — no PDB |
| **Body range** | `0x00610f20`–`0x00610f61` |

## Purpose

Pure cargo-count readiness predicate for **Deliver** objective requirements (type **3**). Returns whether the character’s cargo grid holds enough of the required item CBID for the matched key — or whether quantity is waived.

No progress writes, toasts, or inventory mutations.

## Signature (asm-sealed)

```c
// RET 8 — cleans two stack dwords
uint8_t /* AL */ __thiscall
CVOGObjectiveRequirement_Deliver_CargoReady_Inferred(
    void* req,          // ECX  Deliver requirement
    int   matchKey,     // stack0  vs req+0x18
    void* character);   // stack1  cargo host
```

## Predicate

```
return
  (*(int*)(req + 0x18) == matchKey)
  && (*(InventoryGrid**)(*(char*)(character + 0x250) + 0x2b0) != 0)
  && (
        CountItemsByCbid(cargo, *(int*)(req + 0x10), /*includeBroken*/ 0)
          >= *(int*)(req + 0x14)
        || *(char*)(req + 0x23) == 0
     );
```

### `+0x23` polarity (**sealed**)

| Value | Meaning |
|------:|---------|
| **0** | **Bypass** quantity — ready if match + cargo grid present |
| **≠0** (default **1**) | **Enforce** `count >= NumToDeliver` |

**Authorship:** not a standalone GLM tag. Ctor sets **1**. XML `CBIDItem` parse: if value **== −1**, store **`+0x23 = 0`**; otherwise leave **1**. GetFlags does not dump this byte.

## Deliver field map (shared object)

| Offset | Role | Default |
|-------:|------|---------|
| `+0x0c` | type code | **3** |
| `+0x10` | `CBIDItem` | −1 |
| `+0x14` | `NumToDeliver` | 0 |
| `+0x18` | match key (`TargetNPCCBID` / event id) | −1 |
| `+0x1c` | Continent | −1 |
| `+0x20` | `GiveItemAtStart` | 1 |
| `+0x21` | `TakeItemAtEnd` | 1 |
| `+0x22` | `NPCTargetCompletes` | 1 |
| `+0x23` | require-count / enforce-qty | 1 (0 if CBIDItem −1) |

Cargo: `character+0x250` → host; host `+0x2b0` → `InventoryGrid*` (same as Collect / Drop type-1).

## Callers / callees

| Direction | Target | Notes |
|-----------|--------|-------|
| Caller | virtual only | DATA xref `0x009e0f5c` = vtbl `PTR_FUN_009e0f24 + 0x38` |
| Callee | `InventoryGrid_CountItemsByCbid` `0x005711c0` | includeBroken **0** |

Sibling: `aa_00611290` Deliver OnInventoryEvent (vtbl `+0x04`) — same qty OR on `+0x23`.

## Artifacts

| Kind | Path |
|------|------|
| Residual seal | `docs/reconstruction/reviews/a_00610f20.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_00610f20_CVOGObjectiveRequirement_Deliver_CargoReady.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00610f20_CVOGObjectiveRequirement_Deliver_CargoReady.md` |
| Raw | `docs/reconstruction/raw/aa_00610f20_CVOGObjectiveRequirement_Deliver_CargoReady.md` |
| Annotated | `docs/reconstruction/raw/aa_00610f20_CVOGObjectiveRequirement_Deliver_CargoReady.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_Deliver_CargoReady.cpp` |

Scaffold twin `aa_00610f20_FUN_00610f20.md` remains low-level capture; this record is authoritative for the Deliver name.

## Confidence

| Claim | Level |
|---|---|
| Control flow / predicate | **High** |
| `+0x23` polarity + CBIDItem-derived authorship | **High** |
| ABI / vtable slot | **High** |
| Parameter English names | **Probable** |
| Original method symbol | **Tentative** (`_Inferred`) |
| Runtime / bit-exact | **Open** |

## Open gaps

- PDB method name
- Virtual dispatch call-site inventory
- matchKey domain labeling beyond equality
- Server `RequireItemToComplete` polarity inverted vs client (parity)
- Clean cpp vehicle-null check not in raw image
