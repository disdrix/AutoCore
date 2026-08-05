# Review A (reconstruction fidelity): `aa_005e1030` LootCatalog_RollCandidateId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1030` |
| **VA** | `0x005e1030` |
| **Canonical name (Ghidra)** | `FUN_005e1030` |
| **Proposed name** | `LootCatalog_RollCandidateId_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_005e1030` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_005e1030_LootCatalog_RollCandidateId_Inferred.md` |
| **System** | `inventory` / loot generation |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Build a candidate dword vector from a loot-catalog band table, then randomly select one ID** (or fail with `0xffffffff`).

`this` = loot catalog (`&DAT_00bc56d8` from `FUN_005e0580`). Extra stack formal `in_stack_00000024` selects which table root:

| Mode | Table base used for fill |
|---|---|
| `0` | `this + 0x8700c` |
| `1` | `this + 0xc` |
| other | immediate `return 0xffffffff` |

### Control flow

1. SEH frame `LAB_009a7478`; zero local `std::vector`-like `{begin,end,cap}` at `local_18/14/10`.
2. Select table base by mode (above).
3. Copy **8 dwords** from the caller's stack frame into `auStackY_54` (roll context / level / quality params — same 8-dword pack callers prepare before `005e0580`/`005e1030`).
4. `FUN_005e07d0(...)` — band/quality walk that **pushes candidate item IDs** into the out-vector (`local_1c` as out-arg).
5. If `local_18 == NULL` → restore ExceptionList, `return 0xffffffff`.
6. If `(end - begin) >> 2 != 0` (non-empty):
   - `CVOGReaction_RandomUnitScalar()` + `FUN_007a41f0()` — **pick one entry** from the vector (index / weighted pick residual).
   - free vector via `operator_delete` (decompiler marks noreturn — **SEH artifact**; real path returns selected ID).
7. Empty vector after fill → free + fail path.

**Not** the filtered/exclusion-list roll (`005e1150`), not the low-level band filler (`005e07d0`), not the global getter (`005e0580`).

Callers: `Inv_GenerateLootItem_type` `0x004d0cf0`, kill loot materialize `0x0050ac80` (retry with adjusted pack when first roll returns `-1`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005e1030` |
| Filler callee | live `FUN_005e07d0` (band/level table walk + vector push) |
| Sibling | live `FUN_005e1150` (filtered roll via `005e0cd0`) |
| Callers | `get_function_callers` → `004d0cf0`, `0050ac80` |
| Getter | `A_aa_005e0580_*` / live `005e0580` → `&DAT_00bc56d8` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005e1030` |
| Function record | `docs/reconstruction/functions/aa_005e1030_FUN_005e1030.md` |

**This pass:** live decompile; callers; filler body skim. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = loot catalog (global DAT_00bc56d8)
// Additional formals arrive on stack as an 8-dword roll context + mode.
// Decompiler collapses many formals into stack copies into FUN_005e07d0.
uint32_t __thiscall LootCatalog_RollCandidateId_Inferred(
    void *catalog,           // this
    /* stack: 8×dword roll context (level/quality/…), mode at [ESP+0x24] relative */);
// returns: selected item/cbid id, or 0xffffffff on miss/empty
```

Exact formal map for the 8-dword pack is **Probable** from `0050ac80`/`004d0cf0` prep (level, quality band, type flags) — not fully named here.

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_005e07d0` | Fill candidate ID vector from catalog bands |
| `CVOGReaction_RandomUnitScalar` | RNG stream |
| `FUN_007a41f0` | Select element from filled vector (**Probable** index pick) |
| `operator_delete` | Free vector buffer |

| Caller | Role |
|---|---|
| `0x004d0cf0` GenerateLootItem (type) | Primary type-keyed roll |
| `0x0050ac80` | Kill loot; retries with alternate pack if `-1` |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Mode 0 → `this+0x8700c`, mode 1 → `this+0xc`, else `-1` | Yes |
| 8-dword stack copy into fill helper | Yes |
| `FUN_005e07d0` then null / empty checks | Yes |
| Non-empty → random + `007a41f0` + delete | Yes |
| `operator_delete` "noreturn" | Artifact only (SEH) — ignore for product CF |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Loot catalog thiscall roll of one ID | **High** | callers + filler |
| Mode selects `+0x8700c` vs `+0xc` table | **High** | explicit |
| Fail = `0xffffffff` | **High** | |
| `005e07d0` fills dword ID vector | **High** | live body push pattern |
| `007a41f0` is the actual pick return | **Probable** | SEH/delete noise hides clean return |
| Full 8-dword context schema | **Tentative** | residual |
| Product function name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Exact product name and formal names of the 8-dword roll pack.
2. Bit-exact return path through `FUN_007a41f0` (decompiler SEH pollution).
3. Full semantics of table roots `+0xc` vs `+0x8700c`.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF High for roll/fail; pack schema + clean return path residual.
