# Function record: Rng_Source_ExtractU32

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a41f0` |
| **Canonical name** | `Rng_Source_ExtractU32` |
| **Ghidra name** | `FUN_007a41f0` |
| **Address** | `0x007a41f0` |
| **Body range** | `0x007a41f0`–`0x007a41f7` (**7 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | RNG / MT19937 |
| **Completion status** | **partial** — dual A/B **accept**; bytes + ABI + tail target sealed; product class name + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_007a41f0_Rng_Source_ExtractU32.md`, `reviews/B_aa_007a41f0_Rng_Source_ExtractU32.md` (2026-07-29 W21-L) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_007a41f0`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_007a41f0` (legacy auto parent-seed — misleading)
- Prior loot notes called this a “vector index pick” — **superseded** by byte seal (MT extract only)

## Purpose

**Next tempered uint32** from an RNG **source** object: read `Mt19937State*` at **`this+0x14`**, tail into sealed **`Rng_Mt19937_Extract`** (`0x00424830`).

## Signature

```c
// __thiscall; no stack formals; returns uint32 in EAX
uint32_t __thiscall Rng_Source_ExtractU32(void *source);
// source+0x14 → Mt19937State* (EAX-this for extract)
```

## Algorithm

1. `EAX = *(source + 0x14)`
2. `jmp Rng_Mt19937_Extract` @ `0x00424830`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_007a41f0_FUN_007a41f0.md`
- Annotated: `docs/reconstruction/raw/aa_007a41f0_FUN_007a41f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Rng_Source_ExtractU32.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_007a41f0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_007a41f0_FUN_007a41f0.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00414c20-007a41f0-w21l-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callee** | `Rng_Mt19937_Extract` `FUN_00424830` (tail jmp) |
| **Callers** | `FUN_005e1030` LootCatalog_RollCandidateId; `FUN_005e1150` LootCatalog_RollFilteredCandidateId |

## Confidence

| Claim | Level |
|---|---|
| 7-byte body + tail to `00424830` | **Confirmed** |
| `[ecx+0x14]` state load | **Confirmed** (`read_memory`) |
| Return = tempered u32 | **High** (extract contract) |
| Source object layout (+0x14 MT*) | **High** (bytes + sibling `007a4200`) |
| Product English class name | **Inferred** |
| Runtime vectors | Open |

## Related

- `aa_00424830` Rng_Mt19937_Extract
- `aa_004248c0` Rng_Mt19937_Twist / `aa_00424890` Seed
- `FUN_007a4200` table fill from same source layout
